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

    template<typename Value>
    void Graph<Value>::UpdateAdjacentSize() {
        unsigned int target_size = nodes_.size();
        unsigned int current_size = adjacent_size_;
        unsigned int delta = abs(target_size - current_size);

        if (current_size >= target_size)
            return;

        std::vector<float> empty_row;
        empty_row.assign(target_size, Graph::NOT_CONNECTED);

        for (int i = 0; i < delta; ++i) {
            for (int j = 0; j < current_size; ++j)
                adjacent_[j].push_back(Graph::NOT_CONNECTED);
            adjacent_.push_back(empty_row);
        }

        for (int i = 0; i < target_size; ++i)
            adjacent_[i][i] = 0;

        adjacent_size_ = target_size;
    }

    template<typename Value>
    unsigned int Graph<Value>::IdOf(const node::Node<Value> &node) {
        return std::find(nodes_.begin(), nodes_.end(), node) - nodes_.begin();
    }

    template<typename Value>
    node::Node<Value> &Graph<Value>::NodeAt(unsigned int id) {
        return nodes_[id];
    }

    template<typename Value>
    float Graph<Value>::WeightBetween(unsigned int id_from, unsigned int id_to) {
        UpdateAdjacentSize();
        return adjacent_[id_from][id_to];
    }

    template<typename Value>
    float Graph<Value>::WeightBetween(const node::Node<Value> &from, const node::Node<Value> &to) {
        return WeightBetween(IdOf(from), IdOf(to));
    }

    template<typename Value>
    unsigned int Graph<Value>::Add(const node::Node<Value> &node) {
        nodes_.push_back(node);
        return IdOf(node);
    }

    template<typename Value>
    float Graph<Value>::UpdateWeight(unsigned int from_id, unsigned int to_id, float weight) {
        return UpdateWeight(from_id, to_id, weight, false);
    }

    template<typename Value>
    float Graph<Value>::UpdateWeight(const node::Node<Value> &from, const node::Node<Value> &to, float weight) {
        return UpdateWeight(from, to, weight, false);
    }

    template<typename Value>
    float Graph<Value>::UpdateWeight(const node::Node<Value> &from, const node::Node<Value> &to, float weight,
                                     bool bidirectional) {
        return UpdateWeight(IdOf(from), IdOf(to), weight, bidirectional);
    }

    template<typename Value>
    float Graph<Value>::UpdateWeight(unsigned int from_id, unsigned int to_id, float weight,
                                     bool bidirectional) { // NOLINT(misc-no-recursion)
        float prev = WeightBetween(from_id, to_id);

        adjacent_[from_id][to_id] = weight;

        if (bidirectional)
            UpdateWeight(to_id, from_id, weight, false);

        return prev;
    }

    template<typename Value>
    bool Graph<Value>::AreConnected(unsigned int id_from, unsigned int id_to) {
        return WeightBetween(id_from, id_to) == Graph::NOT_CONNECTED;
    }

    template<typename Value>
    bool Graph<Value>::AreConnected(const node::Node<Value> &from, const node::Node<Value> &to) {
        return WeightBetween(from, to) == Graph::NOT_CONNECTED;
    }

    template<typename Value>
    std::vector<node::Node<Value>> Graph<Value>::GetNodes() {
        std::vector<node::Node<Value>> result;
        std::copy(nodes_.begin(), nodes_.end(), std::back_inserter(result));
        return result;
    }

    template<typename Value>
    std::ostream &operator<<(std::ostream &os, Graph<Value> &graph) {
        os << "graph {" << std::endl << "\tnode [shape=box]" << std::endl << std::endl;

        for (auto &node: graph.nodes_)
            os << '\t' << node << std::endl;

        os << std::endl;

        graph.UpdateAdjacentSize();
        for (unsigned int from_id = 0; from_id < graph.adjacent_size_; ++from_id)
            for (unsigned int to_id = 0; to_id < graph.adjacent_size_; ++to_id)
                if (from_id < to_id && graph.WeightBetween(from_id, to_id) != Graph<Value>::NOT_CONNECTED)
                    os << "\t" << graph.NodeAt(from_id).GetName() << " -- " << graph.NodeAt(to_id).GetName()
                       << std::endl;

        return os << "}";
    }
}
#endif //INC_4_GRAPH_H
