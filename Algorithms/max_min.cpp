#include <vector>
#include <iostream>

void findMinMax(std::vector<int> &arr){
    int mn = arr[0], mx = arr[0];
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] < mn)
            mn = arr[i];
        if(arr[i] > mx)
            mx = arr[i];
    }

    std::cout << "min = " << mn << "\nmax = " << mx <<std::endl;
}




int main() {
    std::vector<int> arr = {5, 2, 9, 1, 7};
    findMinMax(arr);
}