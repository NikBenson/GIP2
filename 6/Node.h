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

        int distance(const struct Position &other) const;

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

        const Value &GetValue() const;

        Position GetPosition() const;

        bool operator==(const Node<Value> &other) const;

        Node &operator=(const Node &other);

        template<typename T>
        friend std::ostream &operator<<(std::ostream &os, const Node<T> &node);
    };

    template<typename Value>
    Node<Value> &Node<Value>::operator=(const Node &other) {
        if (this != &other) {
            //name_ = other.name_;
            //value_ = other.value_;
            //position_ = other.position_;
        }

        return *this;
    }

    inline int Position::distance(const struct Position &other) const {
        return abs(x - other.x) + abs(y - other.y);
    }

    inline bool Position::operator==(const struct Position &other) const {
        return x == other.x && y == other.y;
    }

    inline std::ostream &operator<<(std::ostream &os, const struct Position &position) {
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
    const Value &Node<Value>::GetValue() const {
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

#endif //INC_5_NODE_H
