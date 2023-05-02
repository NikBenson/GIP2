#include <iostream>
#include <vector>
#include <memory>
#include <sstream>
#include "Foo.h"
#include "Bar.h"
#include "Field.h"

int main() {
    /*
    std::vector<std::unique_ptr<Foo>> foos;

    foos.push_back(std::make_unique<Foo>(5));
    foos.push_back(std::make_unique<Bar>(3));
    foos.push_back(std::make_unique<Foo>(7));
    foos.push_back(std::make_unique<Bar>(41));

    for(auto& foo : foos) {
        std::cout << *foo << " ";
    }
     */

    std::vector<std::vector<labyrinth::Field*>> labyrinthIn;
    std::vector<std::vector<labyrinth::Field*>> labyrinthOut;

    std::cin >> labyrinthIn;

    std::stringstream str;
    str << labyrinthIn;
    str >> labyrinthOut;

    std::cout << labyrinthOut;

    return 0;
}
