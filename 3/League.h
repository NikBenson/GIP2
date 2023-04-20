//
// Created by NikBe on 20.04.2023.
//

#ifndef INC_3_LEAGUE_H
#define INC_3_LEAGUE_H


#include <map>
#include <string>
#include "TeamStatistics.h"

class League {
private:
    std::map<const std::string, TeamStatistics*> teams_;

    TeamStatistics &Add(TeamStatistics *stats);
public:
    TeamStatistics &Add(const std::string &name);

    void Print() const;

    std::ostream &WriteToStream(std::ostream &stream) const;

    std::istream &ReadFromStream(std::istream &stream);
};

inline std::ostream &operator<<(std::ostream &stream, const League& league) {
    return league.WriteToStream(stream);
}

inline std::istream &operator>>(std::istream &stream, League& league) {
    return league.ReadFromStream(stream);
}


#endif //INC_3_LEAGUE_H
