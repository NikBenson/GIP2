//
// Created by NikBe on 04.04.2023.
//

#include <iostream>
#include "Greeting.h"

Greeting::Greeting(const std::string greeting, const std::string farewell) {
    this->greeting = greeting;
    this->farewell = farewell;
}

Greeting::~Greeting() {
    std::cout << farewell << std::endl;
}

void Greeting::Print() {
    std::cout << greeting << tick << std::endl;
}

void Greeting::Tick() {
    tick++;
}
