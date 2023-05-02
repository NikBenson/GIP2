//
// Created by NikBe on 02.05.2023.
//

#include <sstream>
#include "Field.h"
#include "Wall.h"
#include "Path.h"
#include "Exit.h"
#include "VerticalWall.h"
#include "HorizontalWall.h"
#include "IntersectWall.h"

namespace labyrinth {
    std::ostream &operator<<(std::ostream &os, const Field &field) {
        field.ToStream(os);
        return os;
    }

    std::istream &operator>>(std::istream &is, Field** field) {
        char name;
        is >> name;

        *field = Field::FromName(name);

        return is;
    }

    Field *Field::FromName(char &name) {
        switch (name) {
            case '#':
            case '|':
            case '+':
            case '-':
                return new Wall();
            case ' ':
                return new Path();
            case '!':
                return new Exit();
            default:
                std::stringstream message;
                message << name << " is not a valid labyrinth field";
                throw std::invalid_argument(message.str());
        }
    }

    std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<Field*>> &labyrinth) {
        for (auto& row : labyrinth) {
            for(auto& field : row) {
                os << *field;
            }
            os << std::endl;
        }

        return os;
    }

    std::istream &operator>>(std::istream &is, std::vector<std::vector<Field*>> &labyrinth) {
        while(is.good()) {
            std::vector<Field*> row;

            char row_name[Field::maxLength] = "";
            is.getline(row_name, Field::maxLength);
            if(row_name[0] == '\0')
                break;

            for(auto& field_name : row_name) {
                if(field_name == '\0')
                    break;
                row.push_back(Field::FromName(field_name));
            }

            labyrinth.push_back(row);
        }

        for (unsigned int height = labyrinth.size(), y = 0; y < height; ++y) {
            for (unsigned int width = labyrinth[y].size(), x = 0; x < width; ++x) {
                Field* field = labyrinth[y][x];

                bool isClear = field->IsClear();

                bool isAtLeft = x <= 0;
                bool isAtTop = y <= 0;
                bool isAtRight = x >= (width-1);
                bool isAtBottom = y >= (height-1);

                bool isLeftClear = isAtLeft || labyrinth[y][x-1]->IsClear();
                bool isAboveClear = isAtTop || labyrinth[y-1][x]->IsClear();
                bool isRightClear = isAtRight || labyrinth[y][x+1]->IsClear();
                bool isBelowClear = isAtBottom || labyrinth[y+1][x]->IsClear();

                if(isClear) {
                    if(isAtLeft || isAtTop || isAtRight || isAtBottom) {
                        labyrinth[y][x] = new Exit();
                    }
                } else {
                    bool isHorizontalClear = isLeftClear && isRightClear;
                    bool isVerticalClear = isAboveClear && isBelowClear;

                    if(isHorizontalClear && !isVerticalClear) {
                        labyrinth[y][x] = new VerticalWall();
                    } else if(!isHorizontalClear && isVerticalClear) {
                        labyrinth[y][x] = new HorizontalWall();
                    } else if(!isHorizontalClear && !isVerticalClear) {
                        labyrinth[y][x] = new IntersectWall();
                    }
                }
            }
        }

        return is;
    }
} // labyrinth