#include <iostream>
#include <mutex>
#include <thread>
#include <vector>


int shared_data;
std::mutex mtx;

void functionThread(){
    for(size_t i = 0; i < 1000000; i++){
        mtx.lock();
        shared_data++;
        mtx.unlock();
    }
}

int main(){
    std::vector<std::thread> threads;

    for (size_t i = 0; i < 8; i++){
        threads.emplace_back(functionThread);
    }

    for(auto &t : threads){
        t.join();
    }

    std::cout << shared_data;

}