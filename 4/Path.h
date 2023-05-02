//
// Created by NikBe on 02.05.2023.
//

#ifndef INC_4_PATH_H
#define INC_4_PATH_H

#include "Field.h"

namespace labyrinth {

    class Path : public Field {
    public:
        bool IsClear() const override;

        ~Path() override;

        void ToStream(std::ostream &os) const override;
    };

} // labyrinth

#endif //INC_4_PATH_H
