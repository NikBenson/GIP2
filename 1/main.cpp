#include <iostream>
#include <vector>
#include "hello.h"
#include "goodbye.h"

namespace pointer {
    template<class T>
    void swap(T* a, T* b) {
        T temp = *a;
        *a = *b;
        *b = temp;
    }

    void order(int* a, int* b) {
        if(*a > *b)
            swap(a, b);
    }
}

namespace reference {
    template<class T>
    void swap(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }

    void order(int& a, int& b) {
        if(a > b)
            swap(a, b);
    }
}

int main() {
    hello::tell();
    goodbye::tell();

    int a = 1;
    int b = 2;
    std::cout << "a=" << a << ", b=" << b << std::endl;

    pointer::swap(&a, &b);
    std::cout << "a=" << a << ", b=" << b << std::endl;

    pointer::order(&a, &b);
    std::cout << "a=" << a << ", b=" << b << std::endl;

    reference::order(a, b);
    std::cout << "a=" << a << ", b=" << b << std::endl;

    reference::swap(a, b);
    std::cout << "a=" << a << ", b=" << b << std::endl;

    do {
        std::string input;
        float operand1;
        char binaryOperator;
        float operand2;

        std::getline(std::cin, input);

        for(int i = 0; i < input.length(); i++) {
            char c = input[i];

            if(c == '+' || c =='-' || c == '*' || c == '/') {
                operand1 = atof(input.substr(0, i).c_str());
                binaryOperator = c;
                operand2 = atof(input.substr(i + 1).c_str());
            }
        }

        switch (binaryOperator) {
            case '+':
                std::cout << operand1 + operand2 << std::endl;
                break;
            case '-':
                std::cout << operand1 - operand2 << std::endl;
                break;
            case '*':
                std::cout << operand1 * operand2 << std::endl;
                break;
            case '/':
                std::cout << operand1 / operand2 << std::endl;
                break;
            default:
                std::cout << "Error" <<std::endl;
        }

    } while(std::cin.good());

    return 0;
}
