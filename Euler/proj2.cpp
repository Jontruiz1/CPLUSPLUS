/*
Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
*/

#include <iostream>

using namespace std;

int main() {
  unsigned long f = 1;
  unsigned long s = 2;
  unsigned long t = 0;
  unsigned long sum = 0;

  while(f < 4000000){

    if(f % 2 == 0){
      sum += f;
    }
    t = f + s;
    f = s;
    s = t;

  }
  cout << "Sum is: " << sum;
}