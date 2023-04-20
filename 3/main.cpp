#include <iostream>
#include "CounterCatalogue.h"
#include "League.h"

inline void Print(const TeamStatistics& stats) {
    stats.Print();
}

inline void Print(const League& league) {
    league.Print();
}

inline void Print(const GameResult& result) {
    result.Print();
}

int main() {
    League league;

    unsigned int teams;
    std::cin >> teams;

    std::string name;
    for (int i = 0; i <teams; ++i) {
        std::cin >> name;
        league.Add(name);
    }


    while (std::cin.good())
        std::cin >> league;


    Print(league);

    return 0;
}
