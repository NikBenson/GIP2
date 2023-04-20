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

    std::string GetAbbreviation() const;
    unsigned int GetGamesPlayed() const;
    unsigned int GetPoints() const;
    unsigned int GetGoalsScored() const;
    unsigned int GetGoalsTaken() const;

    void Add(const GameResult& result);

    std::string to_string() const;
    void Print() const;

    std::ostream &WriteToStream(std::ostream &stream) const;

    bool operator<(const TeamStatistics& other) const;
    bool operator>(const TeamStatistics& other) const;
    bool operator==(const TeamStatistics& other) const;
private:
    int GoalDifference() const;
};

inline std::ostream &operator<<(std::ostream &stream, const TeamStatistics& teams) {
    return teams.WriteToStream(stream);
}


#endif //INC_2_TEAMSTATISTICS_H
