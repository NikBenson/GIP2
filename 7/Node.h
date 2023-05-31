//
// Created by NikBe on 06.05.2023.
//

#ifndef INC_5_NODE_H
#define INC_5_NODE_H

#include <ostream>
#include <string>
#include <utility>

namespace graph::node {
    typedef struct Position2D {
        int x;
        int y;

        int distance(const struct Position2D &other) const;

        bool operator==(const struct Position2D &other) const;

        friend std::ostream &operator<<(std::ostream &os, const struct Position2D &position);
    } Position2D;

    template<typename Value, typename Position=Position2D>
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

        bool operator==(const Node<Value, Position> &other) const;

        Node &operator=(const Node &other);

        template<typename Value1, typename Position1>
        friend std::ostream &operator<<(std::ostream &os, const Node<Value1, Position1> &node);
    };

    template<typename Value, typename Position>
    Node<Value, Position> &Node<Value, Position>::operator=(const Node<Value, Position> &other) {
        if (this != &other) {
            //name_ = other.name_;
            //value_ = other.value_;
            //position_ = other.position_;
        }

        return *this;
    }

    inline int Position2D::distance(const struct Position2D &other) const {
        return abs(x - other.x) + abs(y - other.y);
    }

    inline bool Position2D::operator==(const struct Position2D &other) const {
        return x == other.x && y == other.y;
    }

    inline std::ostream &operator<<(std::ostream &os, const struct Position2D &position) {
        return os << position.x << "," << -position.y;
    }

    template<typename Value, typename Position>
    Node<Value, Position>::Node(std::string name, const Value &value, const Position &position) :
            name_(std::move(name)),
            value_(value),
            position_(position) {}

    template<typename Value, typename Position>
    std::string Node<Value, Position>::GetName() const {
        return name_;
    }

    template<typename Value, typename Position>
    const Value &Node<Value, Position>::GetValue() const {
        return value_;
    }

    template<typename Value, typename Position>
    Position Node<Value, Position>::GetPosition() const {
        return position_;
    }

    template<typename Value, typename Position>
    bool Node<Value, Position>::operator==(const Node<Value, Position> &other) const {
        return position_ == other.position_;
    }

    template<typename Value, typename Position>
    std::ostream &operator<<(std::ostream &os, const Node<Value, Position> &node) {
        return os << node.name_ << " [pos=\"" << node.position_ << "!\"]";
    }
}

#endif //INC_5_NODE_H
