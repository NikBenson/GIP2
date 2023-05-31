//
// Created by NikBe on 02.05.2023.
//

#include "Path.h"

namespace labyrinth {
    void Path::ToStream(std::ostream &os) const {
        os << ' ';
    }

    bool Path::IsClear() const {
        return true;
    }

    Path::~Path() = default;
} // labyrinth