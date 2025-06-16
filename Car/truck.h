#pragma once
#include "car.h"
#include <string>

class Truck : public Car {
public:
    Truck(Driver driver, Engine engine) : Car(driver, engine), load_capacity(845.5) {
        
    }

    std::string toString() const override {
        return Car::toString() + "\nload_capacity - " + std::to_string(load_capacity);
    }

private:
    double load_capacity;
};