//
// Created by NikBe on 02.05.2023.
//

#ifndef INC_4_EXIT_H
#define INC_4_EXIT_H

#include "Path.h"

namespace labyrinth {

    class Exit : public Path {
        void ToStream(std::ostream &os) const override;
    };

} // labyrinth

#endif //INC_4_EXIT_H
