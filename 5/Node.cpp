//
// Created by NikBe on 06.05.2023.
//

#include "Node.h"
#include <utility>


namespace graph::node {
    int Position::distance(const struct Position &other) const {
        return abs(x - other.x) + abs(y - other.y);
    }

    bool Position::operator==(const struct Position &other) const {
        return x == other.x && y == other.y;
    }

    std::ostream &operator<<(std::ostream &os, const struct Position &position) {
        return os << position.x << "," << -position.y;
    }

    template<typename Value>
    Node<Value>::Node(std::string name, const Value &value, const Position &position) :
            name_(std::move(name)),
            value_(value),
            position_(position) {}

    template<typename Value>
    std::string Node<Value>::GetName() const {
        return name_;
    }

    template<typename Value>
    Value &Node<Value>::GetValue() const {
        return value_;
    }

    template<typename Value>
    Position Node<Value>::GetPosition() const {
        return position_;
    }

    template<typename Value>
    bool Node<Value>::operator==(const Node<Value> &other) const {
        return position_ == other.position_;
    }

    template<typename T>
    std::ostream &operator<<(std::ostream &os, const Node<T> &node) {
        return os << node.name_ << " [pos=\"" << node.position_ << "!\"]";
    }
}
