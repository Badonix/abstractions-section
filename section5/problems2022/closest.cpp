#include "closest.h"
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;


void rec(int index, int curr, int target, vector<int>& list, int& answ){
  int d1 = abs(target - curr);
  int d2 = abs(target - answ);
  if(d1 < d2) {
    answ = curr;
  }
  if(d1 == d2){
    answ = min(answ, curr);
  }

  if(index >= list.size()){
    return;
  }

  rec(index + 1, curr, target, list, answ);
  rec(index + 1, curr + list[index], target, list, answ);
  rec(index + 1, curr - list[index], target, list, answ);
}

int findClosest(vector<int> &list, int target) {
  int answ = 0;
  rec(0, 0, target, list, answ);
  return answ;
}
