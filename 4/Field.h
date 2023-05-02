//
// Created by NikBe on 02.05.2023.
//

#ifndef INC_4_FIELD_H
#define INC_4_FIELD_H

#include <ostream>
#include <vector>

namespace labyrinth {

    class Field {
    public:
        const static unsigned int maxLength = 20;

        static Field *FromName(char &name);

        friend std::ostream &operator<<(std::ostream &os, const Field &field);

        friend std::istream &operator>>(std::istream &is, Field **field);

        virtual bool IsClear() const = 0;

        virtual void ToStream(std::ostream &) const = 0;

        virtual ~Field() = default;
    };

    std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<Field *>> &labyrinth);

    std::istream &operator>>(std::istream &is, std::vector<std::vector<Field *>> &labyrinth);
} // labyrinth

#endif //INC_4_FIELD_H
