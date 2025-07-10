#include <iostream>
#include <thread>
#include <future>
#include <pthread.h>

void threadFunction(){
    std::cout << "function\n";
}

int main(){
    
    std::thread myThread(threadFunction);

    int policy = SCHED_FIFO;
    struct sched_param param;
    param.sched_priority = sched_get_priority_max(policy);

    pthread_t threadID = myThread.native_handle();
    pthread_setschedparam(threadID, policy, &param);

    myThread.join();

}

