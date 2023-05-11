//
// Created by NikBe on 02.05.2023.
//

#ifndef INC_4_HORIZONTALWALL_H
#define INC_4_HORIZONTALWALL_H

#include "Wall.h"

namespace labyrinth {

    class HorizontalWall: public Wall {
    public:
        void ToStream(std::ostream &os) const override;
    };

} // labyrinth

#endif //INC_4_HORIZONTALWALL_H
