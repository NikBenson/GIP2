//
// Created by NikBe on 04.04.2023.
//

#ifndef INC_2_GREETING_H
#define INC_2_GREETING_H


class Greeting {
private:
    std::string greeting;
    std::string farewell;

    int tick = 0;
public:
    explicit Greeting(std::string greeting, std::string farewell);
    ~Greeting();

    void Print();

    void Tick();
};


#endif //INC_2_GREETING_H
