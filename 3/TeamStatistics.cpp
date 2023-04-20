//
// Created by NikBe on 04.04.2023.
//

#include <sstream>
#include <iostream>
#include "TeamStatistics.h"
#include "GameResult.h"

TeamStatistics::TeamStatistics(const std::string *abbreviation) {
    this->abbreviation = *abbreviation;
}

std::string TeamStatistics::GetAbbreviation() const {
    return abbreviation;
}

unsigned int TeamStatistics::GetGamesPlayed() const {
    return gamesPlayed;
}

unsigned int TeamStatistics::GetPoints() const {
    return points;
}

unsigned int TeamStatistics::GetGoalsScored() const {
    return goals.goalsScored;
}

unsigned int TeamStatistics::GetGoalsTaken() const {
    return goals.goalsTaken;
}


void TeamStatistics::Add(const GameResult &result) {
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

int TeamStatistics::GoalDifference() const {
    return goals.GetGoalDifference();
}

std::string TeamStatistics::to_string() const {
    std::ostringstream stream;
    WriteToStream(stream);
    return stream.str();
}

std::ostream &TeamStatistics::WriteToStream(std::ostream &stream) const {
    return stream << abbreviation << " "
                  << gamesPlayed << " "
                  << points << " "
                  << goals.to_string();
}

bool TeamStatistics::operator<(const TeamStatistics &other) const {
    return points < other.points ||
           GoalDifference() < other.GoalDifference() ||
           goals.goalsScored < other.goals.goalsScored ||
           GetAbbreviation() < other.GetAbbreviation();
}

bool TeamStatistics::operator>(const TeamStatistics &other) const {
    return points > other.points ||
           GoalDifference() > other.GoalDifference() ||
           goals.goalsScored > other.goals.goalsScored ||
           GetAbbreviation() > other.GetAbbreviation();
}

bool TeamStatistics::operator==(const TeamStatistics &other) const {
    return points == other.points ||
           GoalDifference() == other.GoalDifference() ||
           goals.goalsScored == other.goals.goalsScored ||
           GetAbbreviation() == other.GetAbbreviation();
}

void TeamStatistics::Print() const {
    std::cout << *this;
}
