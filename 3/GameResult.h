//
// Created by NikBe on 04.04.2023.
//

#ifndef INC_2_GAMERESULT_H
#define INC_2_GAMERESULT_H

#include <string>

enum GameState {
    WIN, DRAW, LOSS
};

struct GameResult {
    unsigned int goalsScored = 0;
    unsigned int goalsTaken = 0;

    int GetGoalDifference() const;

    GameState GetCurrentState() const;

    std::string GetFormattedGoals() const;
    std::string GetFormattedGoalDifference() const;

    std::string to_string() const;
    void Print() const;

    std::ostream &WriteToStream(std::ostream &stream) const;

    void operator+=(GameResult other);
};

inline std::ostream &operator<<(std::ostream &stream, const GameResult& teams) {
    return teams.WriteToStream(stream);
}

#endif //INC_2_GAMERESULT_H
