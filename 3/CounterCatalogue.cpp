//
// Created by NikBe on 19.04.2023.
//

#include <iostream>
#include <list>
#include "CounterCatalogue.h"

Counter &CounterCatalogue::Add(const std::string &name) {
    auto counter = new Counter(name);
    counters_.insert({name, counter});

    return *counter;
}

void CounterCatalogue::Touch(const std::string &name, unsigned int increment) {
    counters_.at(name)->Touch(increment);
}

void CounterCatalogue::Print() const {
    std::cout << *this;
}

std::ostream &CounterCatalogue::WriteToStream(std::ostream &stream) const {
    std::list<Counter> counters;
    for (const auto &nameToCounter: counters_) {
        Counter* counter = nameToCounter.second;
        counters.push_back(*counter);
    }

    counters.sort();

    for(const auto& counter : counters)
        stream << counter << std::endl;

    return stream;
}

std::istream &CounterCatalogue::ReadFromStream(std::istream &stream) {
    std::string name;
    while (stream.good()) {
        stream >> name >> Add(name);
    }

    return stream;
}
