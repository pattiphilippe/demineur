#include "Controller.h"
#include "Scores/Category.h"
#include <fstream>
#include "Libraries/rapidjson/include/rapidjson/document.h"
#include "Libraries/rapidjson/include/rapidjson/istreamwrapper.h"


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
    ifstream ifs("Scores.json");
    IStreamWrapper isw(ifs);
    Document document;
    document.ParseStream(isw);

    //searching category
    const BoardPublic & board {game_.getBoard()};
    int boardSize = board.getNbColumns()*board.getNbLines();
    const char* catId = (to_string(boardSize) + to_string(board.getNbBombs())).c_str();

    if(document.HasMember(catId)){
        //READ SCORES IN JSON
        double scoreCur;
        string playerCur;
        vector<Score> scores{};
        for(Value & scoreJson : document[catId].GetArray()){
            scoreCur = scoreJson["score"].GetDouble();
            playerCur = scoreJson["player"].GetString();
            scores.push_back({scoreCur, playerCur});
        }

        //CLEAR SCORES IN JSON
        document[catId].Clear();

        //REFILL SCORES IN JSON
        Score newScore {game_.getScore().count(), player};
        bool addedNewScore {false};
        Document::AllocatorType& alc = document.GetAllocator();
        for(int nbScoresAdded = 0; nbScoresAdded < 5; nbScoresAdded++){
            if(!addedNewScore && scores.at(nbScoresAdded) < newScore){
                Value o (kObjectType); //VALUE IS NEW SCORE
                o.AddMember("score", newScore.getTime(), alc);
                o.AddMember("player", newScore.getPlayer(), alc);
                document[catId].PushBack(o, alc);
                addedNewScore = true;
            } else {
                Value o (kObjectType); //VALUE IS IN PREVIOUS SCORES
                Score & scPtr = scores.at(addedNewScore? nbScoresAdded-1 : nbScoresAdded);
                o.AddMember("score", scPtr.getTime(), alc);
                o.AddMember("player", scPtr.getPlayer(), alc);
                document[catId].PushBack(o, alc);
            }
        }
    } else {
        //add category to doc
    }
}


