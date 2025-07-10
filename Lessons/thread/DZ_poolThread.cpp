#include <iostream>
#include <functional>
#include <mutex>
#include <thread>
#include <vector>
#include <atomic>
#include <condition_variable>
#include <queue>

using namespace std; 

class ThreadPool{
public:
    ThreadPool(size_t num_threads = thread::hardware_concurrency()){
        for (size_t i = 0; i < num_threads; i++){
            _threads.emplace_back([this](){
                while(true){
                    function<void()> task;
                    
                    unique_lock<mutex> lock(_queue_mtx);
                    _cv.wait(lock, [this](){
                        return !_tasks.empty() || _stop;
                    });

                    if(_stop && _tasks.empty()){
                        return; 
                    }

                    task = move(_tasks.front());
                    _tasks.pop();
                    
                    task();
                }
            });
        }
    }
    ~ThreadPool(){
        {
            unique_lock<mutex> lock(_queue_mtx);
            _stop = true;
        }

        _cv.notify_all();

        for(auto &t: _threads){
            t.join();
        }
    }

    void enqueue(function<void()> task){
        unique_lock<mutex> lock(_queue_mtx);
        _tasks.emplace(move(task));
        _cv.notify_one();
    }
private:
    vector<thread> _threads;
    queue<function<void()>> _tasks;
    mutex _queue_mtx;
    condition_variable _cv;

    bool _stop = false;

};
int main(){

    ThreadPool pool(4);

    for(int i = 0; i < 5; i++){
        pool.enqueue([i](){
            cout << "Task " << i << "is running on thread " << this_thread::get_id() << "\n";
            this_thread::sleep_for(chrono::milliseconds(100)); 
        });
    }

    return 0;

}