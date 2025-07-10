#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <condition_variable>

using namespace std;

condition_variable cv;
bool ready = false;
mutex mtx;


void waitingFunction(){
    unique_lock<mutex> lock(mtx);
    while (!ready){
        cout << "Wait signal\n";
        cv.wait(lock);
    }
    cout << "The signal has been received\n";
}

void signalingFunction(){
    this_thread::sleep_for(chrono::milliseconds(100));
    unique_lock<mutex> lock(mtx);
    ready = true;
    cv.notify_all();

}

int main(){

    std::vector<std::thread> threads;   

    threads.emplace_back(waitingFunction);
    threads.emplace_back(signalingFunction);

    for(auto &t: threads){
        t.join();
    }
}