#include "Controller.h"
#include "Scores/Category.h"
#include <fstream>
#include <algorithm>
#include "Libraries/rapidjson/include/rapidjson/document.h"
#include "Libraries/rapidjson/include/rapidjson/istreamwrapper.h"
#include "Libraries/rapidjson/include/rapidjson/ostreamwrapper.h"
#include "Libraries/rapidjson/include/rapidjson/writer.h"
#include "Libraries/rapidjson/include/rapidjson/error/en.h"
#include <iostream>


/**
 * @brief Controller::Controller
 * Init a game with default board
 */
Controller::Controller():
    game_{}

{}


/**
 * @brief Controller::newGame
 * Replace current game with a new game
 */
void Controller::newGame(int nbLines, int nbColumns, int nbBombs, double densityBombs)
{
    unsigned u_nbLines = static_cast<unsigned>(nbLines);
    unsigned u_nbColumns = static_cast<unsigned>(nbColumns);
    unsigned u_nbBombs = static_cast<unsigned>(nbBombs);

    //TODO Correct "use of deleted function" errors

    if(nbLines<0 && nbColumns<0){
        game_ = Game();
    }else if(nbBombs<0){
        game_ = Game(u_nbLines, u_nbColumns);
    }else if(densityBombs<0){
        game_ = Game(u_nbLines, u_nbColumns, u_nbBombs);
    }else{
        game_ = Game(u_nbLines, u_nbColumns, densityBombs);
    }


    //game_ = Game(); FAIT DES EXCEPTIONS DS TOUT LE PROJET (pas comme en java)
}

/**
 * @brief Controller::reveal
 * Reveal case in the game
 * @param line Line of the case you want to reveal
 * @param column Column of the case you want to reveal
 */
void Controller::reveal(unsigned line, unsigned column)
{
    game_.reveal(Coordinates(line,column));
}

/**
 * @brief Controller::reveal
 * Reveal case in the game
 * @param line Line of the case you want to reveal
 * @param column Column of the case you want to reveal
 */
void Controller::mark(unsigned line, unsigned column)
{
    game_.mark(Coordinates(line,column));
}


void Controller::saveScore(string player) const{
    //Opening json file
    using namespace rapidjson;
    using namespace std;
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
    //TODO change to game_.getScore().count()
    scores.push_back({20.1, player});
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


