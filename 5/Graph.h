//
// Created by NikBe on 03.05.2023.
//

#ifndef INC_4_GRAPH_H
#define INC_4_GRAPH_H


#include <vector>
#include <limits>
#include <string>
#include <ostream>

class Graph {
public:
    class Node {
    public:
        struct Position {
            int x;
            int y;

            bool operator==(const Position &other) const;

            friend std::ostream &operator<<(std::ostream &os, const Position &position);
        };

    private:
        std::string name_;
        struct Position position_;
    public:
        Node(std::string &name, struct Position position);

        std::string &get_name();

        struct Position get_position();

        bool operator==(const Node &other) const;

        friend std::ostream &operator<<(std::ostream &os, const Node &node);
    };

    constexpr static float NOT_CONNECTED = std::numeric_limits<float>::infinity();

private:
    std::vector<Node> nodes_;
    std::vector<std::vector<float>> adjacent_;
    unsigned int adjacent_size_ = 0;

public:
    void update_adjacent_size();

    unsigned int id_of(const Node &node);

    Node &node_of(unsigned int id);

    float weight_between(unsigned int id_from, unsigned int id_to);

    float weight_between(const Node &from, const Node &to);

    bool are_connected(unsigned int id_from, unsigned int id_to);

    bool are_connected(const Graph::Node &from, const Graph::Node &to);

    unsigned int add(const Node &node);

    float update_weight(unsigned int from_id, unsigned int to_id, float weight);

    float update_weight(const Node &from, const Node &to, float weight);

    float update_weight(unsigned int from_id, unsigned int to_id, float weight, bool bidirectional);

    float update_weight(const Node &from, const Node &to, float weight, bool bidirectional);

    friend std::ostream &operator<<(std::ostream &os, Graph &graph);
};


#endif //INC_4_GRAPH_H
