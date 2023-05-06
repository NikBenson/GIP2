//
// Created by NikBe on 03.05.2023.
//

#ifndef INC_4_GRAPH_H
#define INC_4_GRAPH_H


#include <vector>
#include <limits>
#include <string>
#include <ostream>
#include "Node.h"


namespace graph {
    template<typename Value>
    class Graph {
    public:
        constexpr static float NOT_CONNECTED = std::numeric_limits<float>::infinity();

        using Node = node::Node<Value>;

    private:
        std::vector<Node> nodes_;
        std::vector<std::vector<float>> adjacent_;
        unsigned int adjacent_size_ = 0;

    public:
        std::vector<Node> GetNodes();

        void UpdateAdjacentSize();

        unsigned int IdOf(const Node &node);

        Node &NodeAt(unsigned int id);

        float WeightBetween(unsigned int id_from, unsigned int id_to);

        float WeightBetween(const Node &from, const Node &to);

        bool AreConnected(unsigned int id_from, unsigned int id_to);

        bool AreConnected(const Node &from, const Node &to);

        unsigned int Add(const Node &node);

        float UpdateWeight(unsigned int from_id, unsigned int to_id, float weight);

        float UpdateWeight(const Node &from, const Node &to, float weight);

        float UpdateWeight(unsigned int from_id, unsigned int to_id, float weight, bool bidirectional);

        float UpdateWeight(const Node &from, const Node &to, float weight, bool bidirectional);

        template<typename T>
        friend std::ostream &operator<<(std::ostream &os, Graph<T> &graph);
    };
}
#endif //INC_4_GRAPH_H
