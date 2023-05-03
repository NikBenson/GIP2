#include <iostream>
#include <vector>
#include <sstream>
#include "Field.h"
#include "Graph.h"


int main() {
    /*std::vector<std::vector<labyrinth::Field*>> labyrinthIn;
    std::vector<std::vector<labyrinth::Field*>> labyrinthOut;

    std::cin >> labyrinthIn;

    std::stringstream str;
    str << labyrinthIn;
    str >> labyrinthOut;

    std::cout << labyrinthOut;*/

    auto* graph = new Graph();

    std::string test123_name = "Test123";
    auto* test123_node = new Graph::Node(test123_name, {0, 0});
    unsigned int test123_id = graph->add(*test123_node);
    std::string test456_name = "Test456";
    auto* test456_node = new Graph::Node(test456_name, {1, 0});
    unsigned int test456_id = graph->add(*test456_node);
    std::string test789_name = "Test789";
    auto* test789_node = new Graph::Node(test789_name, {0, 1});
    unsigned int test789_id = graph->add(*test789_node);

    graph->update_weight(test123_id, test456_id, 1.0, true);
    graph->update_weight(test123_id, test789_id, 2.0, true);

    std::cout << *graph;

    return 0;
}
