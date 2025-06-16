#pragma once
#include <string>

class Engine{
public:
    Engine() : power(164), efficiency(0.6){

    }

    std::string toString() const {
        return "Engine:\npower - " + std::to_string(power) + "\nefficiency - " + std::to_string(efficiency);
    }

private:
    int power;
    float efficiency;
};