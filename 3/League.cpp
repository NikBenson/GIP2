//
// Created by NikBe on 20.04.2023.
//

#include <iostream>
#include <list>
#include "League.h"

TeamStatistics &League::Add(const std::string &name) {
    return Add(new TeamStatistics(&name));
}

TeamStatistics &League::Add(TeamStatistics *team) {
    teams_.insert({team->GetAbbreviation(), team});
}

void League::Print() const {
    std::cout << *this;
}

std::ostream &League::WriteToStream(std::ostream &stream) const {
    std::list<TeamStatistics> teams;
    for (const auto &nameToCounter: teams_) {
        TeamStatistics* counter = nameToCounter.second;
        teams.push_back(*counter);
    }

    teams.sort(std::greater());

    for(const auto& team : teams)
        stream << team << std::endl;

    return stream;
}

std::istream &League::ReadFromStream(std::istream &stream) {
    std::string homeName;
    unsigned int homeScore;
    unsigned int guestScore;
    std::string guestName;

    stream >> homeName >> homeScore >> guestScore >> guestName;

    teams_.at(homeName)->Add(GameResult {homeScore, guestScore});
    teams_.at(guestName)->Add(GameResult {guestScore, homeScore});

    return stream;
}
