#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <atomic>

std::atomic<bool> stop {false};

//relax right

void thread(){
    while(!stop.load(std::memory_order_relaxed));
    std::cout << "Stop\n";

}

void stopthread(){
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    stop.store(true, std::memory_order_relaxed);
}

int main(){

    std::thread t1(thread);
    std::thread t2(stopthread);

    t1.join();
    t2.join();


}

