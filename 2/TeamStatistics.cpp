//
// Created by NikBe on 04.04.2023.
//

#include <sstream>
#include "TeamStatistics.h"
#include "GameResult.h"

TeamStatistics::TeamStatistics(const std::string* abbreviation) {
    this->abbreviation = *abbreviation;
}

std::string TeamStatistics::GetAbbreviation() {
    return abbreviation;
}

unsigned int TeamStatistics::GetGamesPlayed() {
    return gamesPlayed;
}

unsigned int TeamStatistics::GetPoints() {
    return points;
}

unsigned int TeamStatistics::GetGoalsScored() {
    return goals.goalsScored;
}

unsigned int TeamStatistics::GetGoalsTaken() {
    return goals.goalsTaken;
}


void TeamStatistics::Add(const GameResult result) {
    gamesPlayed++;
    goals += result;

    switch (result.GetCurrentState()) {
        case WIN:
            points += 3;
            break;
        case DRAW:
            points += 1;
            break;
        case LOSS:
            break;
    }
}

std::string TeamStatistics::to_string() {
    std::ostringstream stream;

    stream << abbreviation << " "
           << gamesPlayed << " "
           << points << " "
           << goals.to_string();

    return stream.str();
}
