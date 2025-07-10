#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

std::mutex mtx;

int value = 0;
int stupid_value = 0;

double stupid_count(){
    auto start = std::chrono::high_resolution_clock::now(); 
    while(stupid_value < 1000000000){
        stupid_value++;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();

}

void count(){
    while (value < 1000000000){
        std::unique_lock<std::mutex> lock(mtx);
        value++;
        lock.unlock();
    }
}


int main(){

    std::cout << "Without thread: " << stupid_count() << "\n";

    std::thread thread;   
    std::vector<std::thread> threads;   

    auto start = std::chrono::high_resolution_clock::now(); 

    for (int i = 0; i < thread.hardware_concurrency() ; i++){
        threads.emplace_back(count);
    }

    for (auto& t: threads){
        t.join();
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "With threads: " << duration.count() << "\n";
}