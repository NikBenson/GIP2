//
// Created by NikBe on 06.05.2023.
//

#ifndef INC_5_NODE_H
#define INC_5_NODE_H

#include <ostream>
#include <string>
#include <utility>

namespace graph::node {
    struct Position {
        int x;
        int y;

        [[maybe_unused]] int distance(const struct Position &other) const;

        bool operator==(const struct Position &other) const;

        friend std::ostream &operator<<(std::ostream &os, const struct Position &position);
    };

    typedef struct Position position;

    template<typename Value>
    class Node {
    private:
        const std::string name_;
        const Value &value_;
        const Position position_;
    public:
        Node(std::string name, const Value &value, const Position &position);

        std::string GetName() const;

        Value &GetValue() const;

        Position GetPosition() const;

        bool operator==(const Node<Value> &other) const;

        template<typename T>
        friend std::ostream &operator<<(std::ostream &os, const Node<T> &node);
    };
}

#endif //INC_5_NODE_H
