//
// Created by NikBe on 04.04.2023.
//

#ifndef INC_2_TEAMSTATISTICS_H
#define INC_2_TEAMSTATISTICS_H


#include <string>
#include "GameResult.h"

class TeamStatistics {
private:
    std::string abbreviation;
    unsigned int gamesPlayed = 0;
    unsigned int points = 0;
    GameResult goals;

public:
    explicit TeamStatistics(const std::string* abbreviation);

    std::string GetAbbreviation();
    unsigned int GetGamesPlayed();
    unsigned int GetPoints();
    unsigned int GetGoalsScored();
    unsigned int GetGoalsTaken();

    void Add(const GameResult result);

    std::string to_string();

private:
    int GoalDifference();

};


#endif //INC_2_TEAMSTATISTICS_H
