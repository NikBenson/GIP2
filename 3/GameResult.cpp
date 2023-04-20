//
// Created by NikBe on 04.04.2023.
//

#include <sstream>
#include <iostream>
#include "GameResult.h"

int GameResult::GetGoalDifference() const {
    return (goalsScored - goalsTaken);
}

GameState GameResult::GetCurrentState() const {
    int goalDifference = GetGoalDifference();

    if (goalDifference > 0)
        return WIN;
    else if (goalDifference < 0)
        return LOSS;
    else
        return DRAW;
}

std::string GameResult::GetFormattedGoals() const {
    std::ostringstream stream;
    stream << goalsScored << ":" << goalsTaken;
    return stream.str();
}

std::string GameResult::GetFormattedGoalDifference() const {
    std::ostringstream stream;
    stream << std::showpos << GetGoalDifference() << std::noshowpos;
    return stream.str();
}

std::string GameResult::to_string() const {
    std::ostringstream stream;
    WriteToStream(stream);
    return stream.str();
}

void GameResult::operator+=(GameResult other) {
    this->goalsScored += other.goalsScored;
    this->goalsTaken += other.goalsTaken;
}

std::ostream &GameResult::WriteToStream(std::ostream &stream) const {
    return stream << GetFormattedGoals() << " " << GetFormattedGoalDifference();
}

void GameResult::Print() const {
    std::cout << *this;
}
