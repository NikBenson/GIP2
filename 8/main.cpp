#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <list>
#include <iomanip>
#include <unordered_map>
#include <fstream>
#include <cstring>
#include "Field.h"
#include "Graph.h"


typedef struct RoutingTableEntry {
    const graph::node::Node<labyrinth::Field> *prev = nullptr;
    float weight = -1;

    friend std::ostream &operator<<(std::ostream &os, const RoutingTableEntry &entry);
} RoutingTableEntry;

namespace std {
    template<typename T>
    struct hash<graph::node::Node<T>> {
        size_t operator()(const graph::node::Node<T> &node) const {
            // Define the logic to generate a hash value for the Node<T> object
            // For example, you can use std::hash on the name of the node
            return std::hash<std::string>{}(node.GetName());
        }
    };

    template<typename T>
    struct equal_to<graph::node::Node<T>> {
        bool operator()(const graph::node::Node<T> &lhs, const graph::node::Node<T> &rhs) const {
            return lhs == rhs;
        }
    };
}

typedef std::unordered_map<graph::node::Node<labyrinth::Field>, RoutingTableEntry, std::hash<graph::node::Node<labyrinth::Field>>, std::equal_to<>> RoutingTable;

std::ostream &operator<<(std::ostream &os, const RoutingTableEntry &entry) {
    os << entry.weight << " " << std::setw(20);

    if (entry.prev == nullptr)
        os << "-";
    else
        os << entry.prev->GetName();

    return os;
}

std::ostream &
operator<<(std::ostream &os, const std::pair<graph::node::Node<labyrinth::Field>, RoutingTableEntry> &entry) {
    return os << entry.first.GetName() << " " << std::setw(15) << entry.second;
}

std::ostream &
operator<<(std::ostream &os, const RoutingTable &table) {
    for (auto &entry: table) {
        os << entry << std::endl;
    }

    return os;
}

const graph::node::Node<labyrinth::Field> &
next_to_visit(RoutingTable &routingTable, std::list<graph::node::Node<labyrinth::Field>> &unvisitedNodes) {
    const graph::node::Node<labyrinth::Field> *min = nullptr;
    float min_weight = graph::Graph<labyrinth::Field>::NOT_CONNECTED;
    for (auto &current: unvisitedNodes) {
        if (!routingTable.contains(current))
            continue;

        auto &entry = routingTable[current];
        if (entry.weight < min_weight) {
            min = &current;
            min_weight = entry.weight;
        }
    }

    if (min == nullptr) {
        throw std::invalid_argument("Empty routing table has no nearest node");
    }

    return *min;
}

int main(const int argc, const char *argv[]) {
    std::istream* input = &std::cin;

    std::ifstream* file;
    try {
        if (argc == 4) {
            if (strcmp("-s", argv[2]) != 0)
                throw std::invalid_argument("Invalid argv!");

            file = new std::ifstream(argv[3]);
            if (!*file)
                throw std::runtime_error("Failed to open file!");

            input = file;
        }
    } catch (std::runtime_error& e) {
        std::cout << "Failed to open file: " << argv[3];
        return -1;
    }

    std::vector<std::vector<labyrinth::Field *>> labyrinthIn;

    *input >> labyrinthIn;

    auto *labyrinth = new graph::Graph<labyrinth::Field>();

    for (unsigned int height = labyrinthIn.size(), y = 0; y < height; ++y) {
        for (unsigned int width = labyrinthIn[y].size(), x = 0; x < width; ++x) {
            labyrinth::Field *field = labyrinthIn[y][x];
            if (field->IsClear()) {
                std::stringstream name_stream;
                name_stream << "n_" << x << "_" << y;
                std::string name = name_stream.str();
                const auto *n = new graph::node::Node<labyrinth::Field>(name, *field, {(int) x, (int) y});

                labyrinth->Add(*n);

                for (const auto &other: labyrinth->GetNodes())
                    if (n->GetPosition().distance(other.GetPosition()) == 1)
                        labyrinth->UpdateWeight(*n, other, 1.0, true);
            }
        }
    }

    std::cout << *labyrinth << std::endl << std::endl;

    RoutingTable routingTable;
    auto nodes = labyrinth->GetNodes();
    auto nodeBegin = nodes.begin();
    auto nodeEnd = nodes.end();
    auto unvisitedNodes = std::list<graph::node::Node<labyrinth::Field>>(nodeBegin, nodeEnd);

    if (!(argc == 2 || argc == 4))
        throw std::invalid_argument("Please provide exactly one argument!");
    std::string subject_name = argv[1];
    auto subject_iterator = std::find_if(unvisitedNodes.begin(), unvisitedNodes.end(),
                                         [&subject_name](graph::node::Node<labyrinth::Field> &node) {
                                             return node.GetName() == subject_name;
                                         });
    if (subject_iterator == unvisitedNodes.end())
        throw std::invalid_argument("Not a valid name!");
    graph::node::Node<labyrinth::Field> &subject = *subject_iterator;


    routingTable.insert(std::make_pair(subject, RoutingTableEntry{nullptr, 0}));

    while (!unvisitedNodes.empty()) {
        auto current = next_to_visit(routingTable, unvisitedNodes);
        unvisitedNodes.remove(current);

        float current_distance = routingTable[current].weight;

        for (auto &neighbor: labyrinth->GetNeighbors(current)) {
            float neighbor_distance = current_distance + labyrinth->WeightBetween(current, neighbor);
            if ((!routingTable.contains(neighbor)) || neighbor_distance < routingTable[neighbor].weight) {
                routingTable[neighbor] = RoutingTableEntry{
                        new graph::node::Node<labyrinth::Field>(current.GetName(), current.GetValue(),
                                                                current.GetPosition()), neighbor_distance};
            }
        }
    }

    std::cout << "Routing table for " << subject_name << ":" << std::endl << routingTable;

    return 0;
}
