// #include "car.h"
#include "engine.h"
#include "driver.h"
#include "truck.h"
#include "race_car.h"

#include <iostream>

int main(){
    Driver driver;
    Engine engine;

    Truck truck(driver, engine);
    std::cout << truck.toString() << std::endl;

    Race_car car(driver, engine, 150);
    std::cout << car.toString() << std::endl;


}