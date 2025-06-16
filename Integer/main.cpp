#include "integer.h"
#include <iostream>

int main(){
    //Ex 1
    Integer int1(5);
    int1.printValue();
    int1.setValue(6);
    
    std::cout << "int1 = " << int1.getValue() << std::endl;
    Integer int2(int1);
    std::cout << "int2 = " << int2.getValue() << std::endl;

    //Ex 2
    Integer int3(0);
    const Integer int4(1);

    int3.printValue();
    int4.printValue();

}