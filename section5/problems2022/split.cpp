#include "split.h"
#include <string>
#include <iostream>

using namespace std;

long stringToLong(string s) {
    char *remaining;
    long answer;

    answer = strtol(s.c_str(), &remaining, 10);
    return answer;
}


bool rec(long prevNum, string s){
  if(s.empty()) return true;
  for(int i = 1; i <= s.size(); i++){
    long currNum = stringToLong(s.substr(0, i));
    if(prevNum - 1 == currNum && rec(currNum, s.substr(i))) return true;
  }
  return false;
}

bool splitString(string s) {
  for(int i = 1; i < s.size(); i++){
    long firstNum = stringToLong(s.substr(0, i));
    if(rec(firstNum, s.substr(i))) return true;
  }

  return false;
}
