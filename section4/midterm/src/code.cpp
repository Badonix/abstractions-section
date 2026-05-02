#include "code.h"
#include <bits/stdc++.h>

void solve(int n, string curr, string& symbols, vector<string>& answ){
  if(n <= curr.size()){
    answ.push_back(curr);
    return;
  }

  for(char c : symbols){
    solve(n, curr + c, symbols, answ);
  }
}

vector<string> generateCodes(int n, string symbols) {
  vector<string> answ;
  solve(n, "", symbols, answ);
  return answ;
}


