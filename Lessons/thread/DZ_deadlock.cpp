#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

std::mutex mtx1, mtx2;

void threadFunction1(){
    std::unique_lock<std::mutex> lock1(mtx1);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::unique_lock<std::mutex> lock2(mtx2);
}

void threadFunction2(){
    std::unique_lock<std::mutex> lock2(mtx2);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::unique_lock<std::mutex> lock1(mtx1);
}



int main(){

    std::vector<std::thread> threads;

    threads.emplace_back(threadFunction1);
    threads.emplace_back(threadFunction2);

    for (auto &t: threads){
        t.join();
    }

    std::cout << "end\n";

    

}