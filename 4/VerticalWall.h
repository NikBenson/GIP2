//
// Created by NikBe on 02.05.2023.
//

#ifndef INC_4_VERTICALWALL_H
#define INC_4_VERTICALWALL_H

#include "Wall.h"

namespace labyrinth {

    class VerticalWall : public Wall {
    public:
        void ToStream(std::ostream &os) const override;
    };

} // labyrinth

#endif //INC_4_VERTICALWALL_H
