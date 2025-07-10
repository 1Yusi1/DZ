#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

int shared_data = 0;
std::mutex mtx;

void threadFunction(){

    for (size_t i = 0; i < 1000000000; i++){
        shared_data++;
    }


}

int main(int argc, char* argv[]){

    std::vector<std::thread> threads;   

    for (int i = 0; i < 8; i++){
        threads.emplace_back(threadFunction);
    }

    for (auto& t: threads){
        t.join();
    }

    std::cout << shared_data; 
    

}
