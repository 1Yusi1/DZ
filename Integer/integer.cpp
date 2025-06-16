//integer.cpp
#include "integer.h"
#include <iostream>

Integer::Integer(){
    std::cout << "create empty Integer" << std::endl;
}

Integer::Integer(int value){
    number = value;
    std::cout << "create Integer" << std::endl;
}

Integer::Integer(const Integer &value){
    this->number = value.number;
}

int Integer::getValue() const{
    return number;
}

void Integer::setValue(int value){
    number = value;
}

void Integer::printValue() const{
    std::cout << number << std::endl;
}