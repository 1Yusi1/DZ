#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>    


int partition(std::vector<int> &arr, int low, int high){
    int index = low + rand() % (high - low + 1);
    std::swap(arr[high], arr[index]);
    int pivot = arr[high];

    int i = low - 1;
    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i+1], arr[high]);
    return i + 1;
}


void quickSort(std::vector<int> &arr, int low, int high){
    if (low < high){
        int border = partition(arr, low, high);
        quickSort(arr, low, border - 1);
        quickSort(arr, border + 1, high);
    }
}

int main() {
    std::srand(std::time(nullptr));

    std::vector<int> arr = {5, 2, 9, 1, 7};
    quickSort(arr, 0,  arr.size() - 1);

    for(int x : arr)
        std::cout << x << " ";
    std::cout << std::endl;

}






