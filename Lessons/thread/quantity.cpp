#include <iostream>
#include <thread>


int main(){
    std::thread thread1;
    std::cout << thread1.hardware_concurrency() << "\n";
    
}
