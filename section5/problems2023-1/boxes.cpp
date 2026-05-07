#include "boxes.h"
#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;



bool rec(int target, int index, int curr, vector<int>& weights, int n, vector<bool>& used){
  if(n == 1) return true;
  if(curr == target){
    return rec(target, 0, 0, weights, n - 1, used);
  }

  for(int i = index; i < weights.size(); i++){
    if(used[i] || curr + weights[i] > target) continue;
    used[i] = true;
    if(rec(target, i, curr + weights[i], weights, n, used)) return true;
    used[i] = false;
  }

  return false;
}

bool canDivideBoxes(int n, vector<int>& weights) {
  int sum = 0;
  for(int n : weights) sum += n;

  vector<bool> used(weights.size(), false);

  if(sum % n != 0) return false;
  return rec(sum / n, 0, 0, weights, n, used);
}
