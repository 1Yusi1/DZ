#include <vector>
#include <iostream>
#define n 4

void fill(int **p){
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            p[i][j] = j + 1;
        }
    }
}

void print(int **p){
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            std:: cout << p[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void change(int **p){
    int required_number = 9;
    for(int i = 0; i < n; i++){
        p[i][i] = required_number;
    }
}


int main(){
    //init
    int **p = new int *[n];
    for (int i = 0; i < n; i++){
        p[i] = new int[n];
    }
    fill(p);
    print(p);
    std::cout << "\n";
    change(p);
    print(p);

}