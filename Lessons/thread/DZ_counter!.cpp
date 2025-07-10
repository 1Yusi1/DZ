#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

std::mutex mtx;

int value = 0;

void count(){
    while (value < 1000000000){
        value++;
    }
}


int main(){
    auto start1 = std::chrono::high_resolution_clock::now(); 
    count();
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration1 = end1 - start1;
    std::cout << "Without thread: " << duration1.count() << "\n";


    value = 0;
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