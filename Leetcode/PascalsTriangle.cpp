#include <iostream>
#include <vector>


std::vector<std::vector<int>> generate(int num_rows){
    std::vector<std::vector<int>> result(num_rows);
    for(int i = 0; i < num_rows; ++i){
        for(int j = 0; j < i+1; ++j){
            result[i].push_back( j == 0 || j == i ? 1 : result[i-1][j-1] + result[i-1][j]);
        }
    }
    return result;
}

std::vector<int> getRow(int rowIndex){
    std::vector<std::vector<int>> result(rowIndex+1);
    for(int i = 0; i < rowIndex+1; ++i){
        for(int j = 0; j < i+1; ++j){
            result[i].push_back( j == 0 || j == i ? 1 : result[i-1][j-1] + result[i-1][j]);
        }
    }
    return result[rowIndex];
}


int main(){
    std::vector<std::vector<int>> triangle1;
    std::vector<int> triangle2;
    triangle1 = generate(5);
    
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < i+1; ++j){
            std::cout << triangle1[i][j];
        }
        std::cout << std::endl;
    }
    
    triangle2 = getRow(3);
    for(int i = 0; i < 5; ++i){
        std::cout << triangle2[i];
    }



}

