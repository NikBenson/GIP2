//
// Created by NikBe on 03.05.2023.
//

#include "Graph.h"

Graph::Node::Node(std::string &name, Graph::Node::Position position) {
    name_ = name;
    position_ = position;
}

std::string &Graph::Node::get_name() {
    return name_;
}

Graph::Node::Position Graph::Node::get_position() {
    return position_;
}

void Graph::update_adjacent_size() {
    unsigned int target_size = nodes_.size();
    unsigned int current_size = adjacent_size_;
    unsigned int delta = abs(target_size - current_size);

    if(current_size >= target_size)
        return;

    std::vector<float> empty_row;
    empty_row.assign(target_size, Graph::NOT_CONNECTED);

    for(int i = 0; i < delta; ++i) {
        for(int j = 0; j < current_size; ++j)
            adjacent_[j].push_back(Graph::NOT_CONNECTED);
        adjacent_.push_back(empty_row);
    }

    for(int i = 0; i < target_size; ++i)
        adjacent_[i][i] = 0;

    adjacent_size_ = target_size;
}

std::ostream &operator<<(std::ostream &os, const Graph::Node &node) {
    return os << node.name_ << " [pos=\"" << node.position_ << "!\"]";
}

std::ostream &operator<<(std::ostream &os, const Graph::Node::Position &position) {
    return os << position.x << "," << position.y;
}

bool Graph::Node::operator==(const Graph::Node &other) const {
    return position_ == other.position_;
}

bool Graph::Node::Position::operator==(const Graph::Node::Position &other) const {
    return x == other.x && y == other.y;
}

std::ostream &operator<<(std::ostream &os, Graph &graph) {
    os << "graph {" << std::endl << "\tnode [shape=box]" << std::endl << std::endl;

    for (auto &node: graph.nodes_)
        os << '\t' << node << std::endl;

    os << std::endl;

    graph.update_adjacent_size();
    for (unsigned int from_id = 0; from_id < graph.adjacent_size_; ++from_id)
        for (unsigned int to_id = 0; to_id < graph.adjacent_size_; ++to_id)
            if (from_id != to_id && graph.weight_between(from_id, to_id) != Graph::NOT_CONNECTED)
                os << "\t[" << graph.node_of(from_id).get_name() << "] - [" << graph.node_of(to_id).get_name() << "]"
                   << std::endl;

    return os << "}";
}

unsigned int Graph::id_of(const Graph::Node &node) {
    return std::find(nodes_.begin(), nodes_.end(), node) - nodes_.begin();
}

Graph::Node &Graph::node_of(unsigned int id) {
    return nodes_[id];
}

float Graph::weight_between(unsigned int id_from, unsigned int id_to) {
    update_adjacent_size();
    return adjacent_[id_from][id_to];
}

float Graph::weight_between(const Graph::Node &from, const Graph::Node &to) {
    return weight_between(id_of(from), id_of(to));
}

unsigned int Graph::add(const Graph::Node &node) {
    nodes_.push_back(node);
    return id_of(node);
}

float Graph::update_weight(unsigned int from_id, unsigned int to_id, float weight) {
    return update_weight(from_id, to_id, weight, false);
}

float Graph::update_weight(const Graph::Node &from, const Graph::Node &to, float weight) {
    return update_weight(from, to, weight, false);
}

float Graph::update_weight(const Graph::Node &from, const Graph::Node &to, float weight, bool bidirectional) {
    return update_weight(id_of(from), id_of(to), weight, bidirectional);
}

float Graph::update_weight(unsigned int from_id, unsigned int to_id, float weight,
                           bool bidirectional) { // NOLINT(misc-no-recursion)
    float prev = weight_between(from_id, to_id);

    adjacent_[from_id][to_id] = weight;

    if (bidirectional)
        update_weight(to_id, from_id, weight, false);

    return prev;
}

bool Graph::are_connected(unsigned int id_from, unsigned int id_to) {
    return weight_between(id_from, id_to) == Graph::NOT_CONNECTED;
}

bool Graph::are_connected(const Graph::Node &from, const Graph::Node &to) {
    return weight_between(from, to) == Graph::NOT_CONNECTED;
}
