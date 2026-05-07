#include "numbers.h"
#include <algorithm>
#include <iostream>


using namespace std;



void rec(int curr, int n, int k, int size, vector<int>& answ){
  if(size == n){
    answ.push_back(curr);
    return;
  }
  int last_digit = curr % 10;
  if(last_digit + k < 10){
    rec(curr * 10 + last_digit + k, n, k, size + 1, answ);
  }

  if(k != 0 && last_digit - k >= 0){
    rec(curr * 10 + last_digit - k, n, k, size + 1, answ);
  }

}

vector<int> numsSameConsecDiff(int n, int k) {
  vector<int> answ;
  for(int i = 1; i <= 9; i++){
    rec(i, n, k, 1, answ);
  }
  sort(answ.begin(), answ.end());
  return answ;
}
