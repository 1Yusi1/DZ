#pragma once
#include <string>

class Driver{
public:
    Driver() : name("John"), experience(5), gender("male"){
        
    }

    std::string toString() const {
        return "Driver: \n" + name + "\n" + std::to_string(experience) + " years\n" + gender;
    }

private:
    std::string name;
    int experience;
    std::string gender;
};