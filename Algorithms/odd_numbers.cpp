#include <vector>
#include <iostream>

std::vector<int> findOddNumbers(std::vector<int> &arr){
    std::vector<int> odd_numbers;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] % 2 != 0)
            odd_numbers.push_back(arr[i]);
    }
    return odd_numbers;
}

int main(){
    std::vector<int> arr = {5, 2, 9, 1, 7};

    for(int x : findOddNumbers(arr)){
        std::cout << x <<  " ";
    }
}