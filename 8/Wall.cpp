//
// Created by NikBe on 02.05.2023.
//

#include "Wall.h"

namespace labyrinth {
    void Wall::ToStream(std::ostream &os) const {
        os << '#';
    }

    bool Wall::IsClear() const {
        return false;
    }

    Wall::~Wall() = default;
} // labyrinth