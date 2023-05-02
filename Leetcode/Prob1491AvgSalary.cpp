/*
You are given an array of unique integers salary where salary[i] is the salary of the ith employee.

Return the average salary of employees excluding the minimum and maximum salary. Answers within 10-5 of the actual answer will be accepted.

 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double average(vector<int>& salary) {
    double result = 0;
    sort(salary.begin(), salary.end());

    for(int i = 1; i < salary.size()-1; ++i){
        result += salary[i];
    }
    return result/(salary.size()-2);
}

int main(){
    vector<int> salaries{4000, 3000, 1000, 2000};
    cout << average(salaries);

}