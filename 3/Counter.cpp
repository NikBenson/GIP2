//
// Created by NikBe on 19.04.2023.
//

#include <iostream>
#include "Counter.h"

Counter::Counter(const std::string &name) {
    name_ = name;
}

void Counter::Touch(unsigned int increment) {
    count_ += increment;
}

void Counter::Print() const {
    std::cout << *this;
}

std::ostream &Counter::WriteToStream(std::ostream &stream) const {
    return stream << name_ << ":" << count_;
}

std::istream &Counter::ReadFromStream(std::istream &stream) {
    stream >> count_;
    return stream;
}

bool Counter::operator<(const Counter &other) const {
    if(count_ == other.count_)
        return name_ < other.name_;

    return count_ < other.count_;
}

bool Counter::operator>(const Counter &other) const {
    if(count_ == other.count_)
        return name_ > other.name_;

    return count_ > other.count_;
}

bool Counter::operator==(const Counter &other) const {
    return count_ == other.count_ && name_ == other.name_;
}
