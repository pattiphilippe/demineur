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
    view_.displayCommands();
    Command cmd;
    do {
        //TODO gestion de commandes au mauvais moment : reveal et mark si pas de jeu ou jeu fini
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
                break;
            case MARK:
                mark();
                break;
            case REVEAL:
                reveal();
                break;
            case EXIT:
                view_.displayExit();
                break;
            case HELP:
                view_.displayCommands();
                break;
            default:
            //TODO CHANGE DISPLAY ERROR TO DISPLAY_EXCEPTION(EXCEPTION)
                view_.displayError();
                view_.displayCommands();
                break;
        }
    } while(cmd != EXIT);
}

void Controller::start(){
    view_.displayStart();
    //TODO ajouter vérif s'il y a déja un jeu en cours : faire readBoolean(msg)
    game_ = Game(); //TODO ATTENTION, N'EST PLUS OBSERVE PAR VUE, FAIRE GAME::NEW_GAME()
}

void Controller::custom(){
    view_.displayCustom();
    string linesMsg = "The number of lines you want :";
    string colsMsg = "The number of columns you want :";
    int nbLines = readInt(linesMsg);
    int nbCols = readInt(colsMsg);
    //TODO  read type of custom
    game_ = Game(nbLines, nbCols);

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
        //TODO add view.displayError(GameException)
        view_.displayError();
    }
}

/**
 * @brief Controller::newGame
 * Replace current game with a new game
 */
/*
void Controller::newGame (int nbLines, int nbColumns, int nbBombs, double densityBombs)
{
    //TODO read param for game start
    unsigned u_nbBombs = static_cast<unsigned>(nbBombs);
    if(nbLines<0 || nbColumns<0){
        game_ = Game();
    }else if(nbBombs<0){
        game_ = Game(nbLines, nbColumns);
    }else if(densityBombs<0){
        game_ = Game(nbLines, nbColumns, u_nbBombs);
    }else{
        game_ = Game(nbLines, nbColumns, densityBombs);
    }
}
*/



/**
 * @brief Controller::reveal
 * Reveal case in the game
 * @param line Line of the case you want to reveal
 * @param column Column of the case you want to reveal
 */
/*
void Controller::mark(unsigned line, unsigned column)
{
    try{
        game_.mark(Coordinates(line,column));
    } catch (GameException e){
        cout << "error marking : " << e.what() << endl;
    }
}
*/


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


