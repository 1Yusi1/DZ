#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>
#include <vector>

// std::mutex mtx;
using namespace std;


class SafeCounter{
public:
    int increment(){
        unique_lock<shared_timed_mutex> lock(mtx);
        return ++value;
    }
    int getValue() const {
        shared_lock<shared_timed_mutex> lock(mtx);
        return value;
    }
private:
    mutable shared_timed_mutex mtx;
    int value = 0;
    
};

void reader(SafeCounter &counter){
    int value;
    for (size_t i = 0; i < 5; i++){
        this_thread::sleep_for(chrono::milliseconds(100));
        value = counter.getValue();
        cout << "Reader: value =  " << value << "\n"; 
    }

}

void writer(SafeCounter &counter){
    int value;
    for (size_t i = 0; i < 5; i++){
        this_thread::sleep_for(chrono::milliseconds(100));
        value = counter.increment();
        cout << "Writer value =  " << value << "\n";
    }

}

int main(){

    SafeCounter counter;

    vector<thread> readerThread;
    for(size_t i = 0; i < 5; i++){
        readerThread.emplace_back(reader, ref(counter));
    }

    thread writerThread(writer, ref(counter));

    for(auto &t: readerThread){
        t.join();
    }

    writerThread.join();

    
}