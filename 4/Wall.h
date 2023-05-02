//
// Created by NikBe on 02.05.2023.
//

#ifndef INC_4_WALL_H
#define INC_4_WALL_H

#include "Field.h"

namespace labyrinth {

    class Wall: public Field {
    public:
        bool IsClear() const override;

        ~Wall() override;

        void ToStream(std::ostream &os) const override;
    };

} // labyrinth

#endif //INC_4_WALL_H
