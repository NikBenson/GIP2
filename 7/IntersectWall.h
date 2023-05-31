//
// Created by NikBe on 02.05.2023.
//

#ifndef INC_4_INTERSECTWALL_H
#define INC_4_INTERSECTWALL_H

#include "Wall.h"

namespace labyrinth {

    class IntersectWall : public Wall {
    public:
        void ToStream(std::ostream &os) const override;
    };

} // labyrinth

#endif //INC_4_INTERSECTWALL_H
