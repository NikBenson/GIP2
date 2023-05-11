#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <list>
#include "Field.h"
#include "Graph.h"


int main() {
    std::vector<std::vector<labyrinth::Field *>> labyrinthIn;

    std::cin >> labyrinthIn;

    auto *labyrinth = new graph::Graph<labyrinth::Field>();

    for (unsigned int height = labyrinthIn.size(), y = 0; y < height; ++y) {
        for (unsigned int width = labyrinthIn[y].size(), x = 0; x < width; ++x) {
            labyrinth::Field *field = labyrinthIn[y][x];
            if (field->IsClear()) {
                std::stringstream name_stream;
                name_stream << "n_" << x << "_" << y;
                std::string name = name_stream.str();
                auto *n = new graph::node::Node<labyrinth::Field>(name, *field, {(int) x, (int) y});

                labyrinth->Add(*n);

                for (const auto &other: labyrinth->GetNodes())
                    if (n->GetPosition().distance(other.GetPosition()) == 1)
                        labyrinth->UpdateWeight(*n, other, 1.0, true);
            }
        }
    }

    std::cout << *labyrinth;

    graph::node::Node<labyrinth::Field> current = labyrinth->NodeAt(0);

    typedef struct RoutingTableEntry {
        graph::node::Node<labyrinth::Field>* next = nullptr;
        float weight = -1;
    } RoutingTableEntry;

    std::list<graph::node::Node<labyrinth::Field>> unvisitedNodes = new std::list(labyrinth->GetNodes());
    unvisitedNodes.remove(current);

    std::map<graph::node::Node<labyrinth::Field>, RoutingTableEntry> routingTable;
    routingTable[current] = {&current, 0};

    while(!unvisitedNodes.empty()) {

    }

    std::cout << "Routing table for " << current.GetName() << ":";
    for(auto& entry : routingTable) {
        std::cout << entry.first.GetName() << " <- " << entry.second.next << " (" << entry.second.weight << ")";
    }

    return 0;
}
