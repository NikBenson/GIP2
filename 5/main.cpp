#include <iostream>
#include <vector>
#include <sstream>
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
                const auto *n = new graph::node::Node<labyrinth::Field>(name, *field, {(int) x, (int) y});

                labyrinth->Add(*n);

                for (const auto &other: labyrinth->GetNodes())
                    if (n->GetPosition().distance(other.GetPosition()) == 1)
                        labyrinth->UpdateWeight(*n, other, 1.0, true);
            }
        }
    }

    std::cout << *labyrinth;

    return 0;
}
