#include <iostream>
#include <regex>
#include "Greeting.h"
#include "TeamStatistics.h"

void ReadUppercaseLetters(std::string message, std::string* out) {
    std::string input;
    std::regex uppercase_regex("^[A-Z]+$");

    do {
        std::cout << message;
        std::getline(std::cin, input);
    } while (!std::regex_match(input, uppercase_regex));

    *out = input;
}

void ExercisesFourThroughSeven() {
    std::string teamName;
    ReadUppercaseLetters("Enter the name of the team (only capital letters): ", &teamName);

    auto* team = new TeamStatistics(&teamName);

    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        GameResult gameResult;
        if (iss >> gameResult.goalsScored >> gameResult.goalsTaken)
            team->Add(gameResult);
        else
            std::cerr << "Error parsing line: " << line << std::endl;
    }

    std::cout << team->to_string() << std::endl;
}

void ExercisesOneThroughThree() {
    auto* greeting = new Greeting("Wazzup!! ", "Goodbye");

    for(int i = 0; i < 20; i++)
        greeting->Tick();

    greeting->Print();
}

int main() {
    //ExercisesOneThroughThree();
    ExercisesFourThroughSeven();

    return 0;
}
