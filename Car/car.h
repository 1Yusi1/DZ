#pragma once

#include <iostream>
#include <string>
#include "driver.h"
#include "engine.h"

enum Status {
    ON,
    OFF
};

class Car {
public:
    Car(Driver driver, Engine engine) : mark("BMW"), car_class("E"), weight(700), max_speed(200),
                                        driver(driver), engine(engine), stat(Status::OFF) {

    }

    void start(){
        if (stat == Status::OFF){
            stat = Status::ON;
            std::cout << "start engine" << std::endl;
        }
        else
            std::cout << "engine is already start\n";
    }

    void stop() const{
        if (stat == Status::ON){
            for (int i = max_speed; i < 0; i--)
                std::cout << i << " ";
            std::cout << std::endl;
        }
        else
            std::cout << "the engine is not start\n";
    }

    void move() const {
        if (stat == Status::ON){
            for (int i = 1; i < max_speed; i++)
                std::cout << i << " ";
            std::cout << std::endl;
        }
        else
            std::cout << "the engine is not start\n";
    }

    void off(){
        if (stat == Status::ON){
            stat = Status::OFF;
            std::cout << "stop engine" << std::endl;
        }
        else
            std::cout << "the engine is not start\n";
    }

    virtual std::string toString() const {
        return "Info:\n" + mark + "\n" + car_class + "\n" +
            std::to_string(weight) + "kg\n" + std::to_string(max_speed) + "km/h\n" +
             driver.toString() + "\n" + engine.toString();
    } 

protected:
    std::string mark;
    std::string car_class;
    double weight;
    int max_speed;
    Driver driver;
    Engine engine;
    Status stat;

};