#include "Controller.h"
#include "Model/Game.h"
#include "Util/GameException.h"
#include "View/ConsoleRead.h"

#include <fstream>
#include <algorithm>
#include <iostream>

#include "Libraries/rapidjson/include/rapidjson/document.h"
#include "Libraries/rapidjson/include/rapidjson/istreamwrapper.h"
#include "Libraries/rapidjson/include/rapidjson/ostreamwrapper.h"
#include "Libraries/rapidjson/include/rapidjson/writer.h"
#include "Libraries/rapidjson/include/rapidjson/error/en.h"

using namespace rapidjson;
using namespace std;

/**
 * @brief Controller::Controller
 * Init a game with default board
 */
Controller::Controller(Game & game, ConsoleView & view):
    game_{game},
    view_{view}
{}


void Controller::run(){
    view_.displayStart();
    Command cmd;
    do {
        cmd = readCommand();
        switch(cmd){
            case START:
                start();
                break;
            case CUSTOM:
                custom();
                break;
            case SCORES:
                scores();
                view_.displayChrono();
                view_.displayBoard();
                break;
            case MARK:
                if(game_.getGameState() == init || game_.getGameState() == inProgress){
                    mark();
                }else{
                    view_.displayError();
                }
                break;
            case REVEAL:
                if(game_.getGameState() == init || game_.getGameState() == inProgress){
                    reveal();
                }else{
                    view_.displayError();
                }
                //TODO Display end game si getGameState != inProgress.
                break;
            case EXIT:
                view_.displayExit();
                break;
            case HELP:
                view_.displayCommands();
                break;
            default:
                view_.displayError();
                view_.displayCommands();
                break;
        }
    } while(cmd != EXIT);
}

void Controller::start(){
    string confirmMsg = "Are you sure you want to start a new game(Y or N)";
    bool confirmed = readBoolean(confirmMsg);
    if(confirmed){
        game_ = Game();
        view_.setModel(game_);
    }
}

void Controller::custom(){
    TypeOfCustom customType ;
    customType = readCustom();

    string linesMsg = "The number of lines you want :";
    string colsMsg = "The number of columns you want :";
    int nbLines = readInt(linesMsg);
    int nbCols = readInt(colsMsg);

    switch(customType){

        case LINESANDCOLUMNS:
            {
                game_ = Game(nbLines, nbCols);
                break;
            }

        case NBBOMBS:
            {
                string bombsMsg = "The number of bombs you want :";
                unsigned nbBombs = readInt(bombsMsg);
                game_ = Game(nbLines, nbCols, nbBombs);
                break;
            }

        case DENSITYBOMBS:
            {
            string densityMsg = "The density of bombs you want :";
            double densityBombs = readDouble(densityMsg);
            game_ = Game(nbLines, nbCols, densityBombs);
            break;
            }

        default:
            view_.displayError();
        break;
    }

    view_.setModel(game_);

}

void Controller::scores(){
    //TODO read category and not by default
    int nbLines = 10, nbCols = 10;
    unsigned nbBombs = 10;
    view_.displayScores(nbLines, nbCols, nbBombs, getScores(nbLines, nbCols, nbBombs));
}


/**
 * @brief Controller::reveal
 * Reads and reveals a case in the game
 */
void Controller::reveal(){
    string lineMsg = "Type the line of the case you want to reveal";
    string colMsg = "Type the column of the case you want to reveal";
    int line = readIntBetween(0, game_.getBoard().getNbLines()-1, lineMsg);
    int col = readIntBetween(0, game_.getBoard().getNbColumns()-1, colMsg);
    try{
        game_.reveal(Coordinates(line, col));
    } catch(GameException e){
        //TODO add view.displayError(GameException)
        view_.displayError();
    }
}
/**
 * @brief Controller::mark
 * Reads and marks a case in the game
 */
void Controller::mark(){
    string lineMsg = "Type the line of the case you want to mark";
    string colMsg = "Type the column of the case you want to mark";
    int line = readIntBetween(0, game_.getBoard().getNbLines()-1, lineMsg);
    int col = readIntBetween(0, game_.getBoard().getNbColumns()-1, colMsg);
    try{
        game_.mark(Coordinates(line, col));
    } catch(GameException e){
        view_.displayError();
    }
}


void Controller::saveScore() const{
    string nameMsg = "Enter your username";
    string player = readString(nameMsg);

    //Opening json file
    ifstream ifs("Scores.json");
    IStreamWrapper isw(ifs);
    Document document;
    ParseResult parseR = document.ParseStream(isw);
    if(parseR.IsError()){
        cout << GetParseError_En(parseR.Code())<<endl;
        document.SetObject();
    }
    Document::AllocatorType& allocator = document.GetAllocator();

    //SEARCH CATEGORY FOR SCORE
    const BoardPublic & board {game_.getBoard()};
    int boardSize = board.getNbColumns()*board.getNbLines();
    const char* catId = (to_string(boardSize) + to_string(board.getNbBombs())).c_str();

    assert(document.IsObject());
    //CREATE CAT IF NOT THERE YET
    if(!document.HasMember(catId)){
        char buffer[10];
        Value id;
        int len = sprintf(buffer, "%s", catId);
        id.SetString(buffer, len, allocator);
        memset(buffer, 0, sizeof(buffer));
        Value scoresArray(kArrayType);
        document.AddMember(id, scoresArray, allocator);
    }

    //READ SCORES IN JSON
    double scoreCur;
    string playerCur;
    vector<Score> scores{};
    for(Value & scoreJson : document[catId].GetArray()){
        scoreCur = scoreJson["score"].GetDouble();
        playerCur = scoreJson["player"].GetString();
        scores.push_back({scoreCur, playerCur});
    }

    //AT LEAST 5 SCORES
    scores.push_back({game_.getScore().count(), player});
    for(unsigned i = scores.size(); i < 5; i++){
        scores.push_back({});
    }

    //SORT
    vector<Score *> vpsc {};
    transform(scores.begin(), scores.end(), back_inserter(vpsc), [](Score & s){return &s;});
    sort(begin(vpsc), end(vpsc), [](const Score * s1, const Score * s2){
        return *s2 < *s1;
    });


    //WRITE SCORES IN JSON
    document[catId].GetArray().Clear();
    for(unsigned i = 0; i < 5; i++){
        Value score(kObjectType);
        score.AddMember("score", vpsc.at(i)->getTime(), allocator);
        char buffer[10];
        Value playerName;
        int len = sprintf(buffer, "%s", vpsc.at(i)->getPlayer().c_str());
        playerName.SetString(buffer, len, allocator);
        memset(buffer, 0, sizeof(buffer));
        score.AddMember("player", playerName, allocator);
        document[catId].GetArray().PushBack(score, allocator);
    }

    //WRITE TO FILE
    ofstream ofs("Scores.json");
    OStreamWrapper osw(ofs);

    Writer<OStreamWrapper> writer(osw);
    document.Accept(writer);
}


vector<Score> Controller::getScores(int nbLines, int nbCols, unsigned nbBombs) const{
    //Opening json file
    ifstream ifs("Scores.json");
    IStreamWrapper isw(ifs);
    Document document;
    ParseResult parseR = document.ParseStream(isw);
    if(parseR.IsError()){
        document.SetObject();
    }

    //SEARCH CATEGORY FOR SCORE
    vector<Score> scores{};
    int boardSize =nbLines*nbCols;
    const char* catId = (to_string(boardSize) + to_string(nbBombs)).c_str();

    //READ SCORES IN JSON
    double scoreCur;
    string playerCur;
    if(document.HasMember(catId)){
        for(Value & scoreJson : document[catId].GetArray()){
            scoreCur = scoreJson["score"].GetDouble();
            playerCur = scoreJson["player"].GetString();
            scores.push_back({scoreCur, playerCur});
        }
    }

    //AT LEAST 5 SCORES
    for(unsigned i = scores.size(); i < 5; i++){
        scores.push_back({});
    }
    return scores;
}


