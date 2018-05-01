#include "Score.h"

#include <fstream>
#include <algorithm>

#include "Libraries/rapidjson/include/rapidjson/document.h"
#include "Libraries/rapidjson/include/rapidjson/istreamwrapper.h"
#include "Libraries/rapidjson/include/rapidjson/ostreamwrapper.h"
#include "Libraries/rapidjson/include/rapidjson/writer.h"
#include "Libraries/rapidjson/include/rapidjson/error/en.h"

using namespace std;
using namespace rapidjson;

/**
 * @brief Score::Score
 * Creates an empty score
 */
Score::Score(): Score(0, ""){}




/**
 * @brief Score::Score
 * Score of a player with a time and name of player
 * @param time, time of the score
 * @param player, the name of the player
 */
Score::Score(double time, string player):
    s_time {time},
    s_player {player}
{}



vector<Score> saveScore(Score newScore, int lines, int cols, unsigned nbBombs) {
    //Opening json file
    ifstream ifs("Scores.json");
    IStreamWrapper isw(ifs);
    Document document;
    ParseResult parseR = document.ParseStream(isw);
    if(parseR.IsError()){
        //cout << GetParseError_En(parseR.Code())<<endl;
        document.SetObject();
    }
    Document::AllocatorType& allocator = document.GetAllocator();

    //SEARCH CATEGORY FOR SCORE
    int boardSize = cols*lines;
    const char* catId = (to_string(boardSize) + to_string(nbBombs)).c_str();

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
    //CHANGED FROM
    /*
    string player = readString("Enter your username");
    scores.push_back({game_.getScore().count(), player});
    */ //TO
    scores.push_back(newScore);
    for(unsigned i = scores.size(); i < 5; i++){
        scores.push_back({});
    }

    //SORT
    vector<Score *> vpsc {};
    transform(scores.begin(), scores.end(), back_inserter(vpsc), [](Score & s){return &s;});
    sort(begin(vpsc), end(vpsc), [](const Score * s1, const Score * s2){
        return *s1 < *s2;
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

    vector<Score> newScores {};
    for(int i = 0; i < 5; i++){
        newScores.push_back(*(vpsc.at(i)));
    }/*
    for(Score * psc : vpsc){
        newScores.push_back(*psc);
    }*/

    return newScores;
}


vector<Score> getScores(int nbLines, int nbCols, unsigned nbBombs) {

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
