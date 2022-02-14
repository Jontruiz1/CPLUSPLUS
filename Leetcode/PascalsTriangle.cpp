#include <iostream>
#include <vector>


std::vector<std::vector<int>>& generate(int num_rows){
    std::vector<std::vector<int>>* result = new std::vector<std::vector<int>>(num_rows);
    for(int i = 0; i < num_rows; i++){
        for(int j = 0; j < i+1; j++){
            if(j == i || j == 0){
                (result[i])->push_back(1);
            }
            else{
                (result[i])->push_back(0);
            }
        }

    }
    return (result);
}

int main(){
    std::vector<std::vector<int>> triangle;
    triangle = generate(5);

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < i+1; j++){
            std::cout << triangle[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << triangle[0][0];
}