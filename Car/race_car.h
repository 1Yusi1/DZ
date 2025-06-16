#pragma once
#include "car.h"
#include <string>


class Race_car : public Car {
public:
    Race_car(Driver driver, Engine engine, int new_speed) : Car(driver, engine) {
        add_max_speed = max_speed + new_speed;
    }

    std::string toString() const override {
        return Car::toString() + "\nadd_max_speed - " + std::to_string(add_max_speed) + "km/h";
    }

private:
    int add_max_speed;
};