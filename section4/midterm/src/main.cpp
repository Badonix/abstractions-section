#include "change.h"
#include "code.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printTestResults(bool passed, int testNum, int &passedCounter) {
  if (passed) {
    cout << "test " << testNum << " passed" << endl;
    passedCounter++;
  } else {
    cout << "test " << testNum << " failed" << endl;
  }
}

const int codeTestsNum = 15;

bool runCodeSingleTest(int testNum) {
  string fileName = string("../exam/code/test") + to_string(testNum) + ".txt";
  ifstream inp(fileName);
  if (!inp.is_open()) {
    cout << "  [could not open " << fileName << "]" << endl;
    return false;
  }
  int n;
  string symbols;
  vector<string> answ;
  inp >> n >> symbols;
  string code;
  while (inp >> code) {
    answ.push_back(code);
  }
  vector<string> res = generateCodes(n, symbols);
  if (res.size() != answ.size())
    return false;
  for (int i = 0; i < (int)res.size(); i++) {
    if (res[i] != answ[i])
      return false;
  }
  return true;
}

const int changeTestsNum = 15;

bool runChangeSingleTest(int testNum) {
  bool passed = false;
  vector<int> cshBills;
  vector<int> cstBills;
  switch (testNum) {
  case 1:
    cstBills = {15, 30, 120, 5, 3};
    passed = giveChange(cshBills, cstBills, 23);
    break;
  case 2:
    cstBills = {35, 30, 1, 3, 7};
    cshBills = {102, 2, 8};
    passed = giveChange(cshBills, cstBills, 55);
    break;
  case 3:
    cstBills = {2, 3, 7, 100};
    cshBills = {3, 10, 1};
    passed = giveChange(cshBills, cstBills, 4);
    break;
  case 4:
    cstBills = {1, 13, 17, 22, 10};
    cshBills = {3, 7, 15};
    passed = giveChange(cshBills, cstBills, 26);
    break;
  case 5:
    cstBills = {1, 13, 18, 22, 10};
    cshBills = {3, 7, 15, 27};
    passed = giveChange(cshBills, cstBills, 39);
    break;
  case 6:
    cstBills = {100, 140, 160, 180, 200, 240, 340};
    cshBills = {3, 7, 15, 27, 30, 48};
    passed = giveChange(cshBills, cstBills, 339);
    break;
  case 7:
    cstBills = {100, 140, 160, 180, 200, 240, 340};
    cshBills = {3, 7, 15, 27, 30, 48};
    passed = giveChange(cshBills, cstBills, 339);
    break;
  case 8:
    cstBills = {107, 140, 160, 180, 200, 240, 340};
    cshBills = {3, 7, 15, 27, 30, 50};
    passed = giveChange(cshBills, cstBills, 339);
    break;
  case 9:
    cstBills = {10, 140, 160, 180, 200, 240, 340, 400, 430, 32};
    cshBills = {7, 15, 27, 30, 50, 3};
    passed = giveChange(cshBills, cstBills, 29);
    break;
  case 10:
    cstBills = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2056};
    cshBills = {12, 14, 26, 48, 52, 1052};
    passed = !giveChange(cshBills, cstBills, 17);
    break;
  case 11:
    cstBills = {1001, 1000, 120, 160, 180, 1, 1, 1, 1, 1, 1};
    cshBills = {102, 200, 300, 800, 2500, 2300, 1200, 1400, 1004};
    passed = giveChange(cshBills, cstBills, 7);
    break;
  case 12:
    cstBills = {5, 5, 5, 5, 5, 5, 24};
    cshBills = {1, 1, 1, 1};
    passed = giveChange(cshBills, cstBills, 50);
    break;
  case 13:
    cstBills = {13, 227, 38, 101, 180, 204, 288, 128, 208, 13};
    cshBills = {10000, 10011, 1, 1, 5, 5};
    passed = giveChange(cshBills, cstBills, 20);
    break;
  case 14:
    cstBills = {1, 10, 17, 28, 58, 60, 35, 70, 75};
    cshBills = {1, 1, 3, 100, 20, 6, 102, 84, 56, 10, 5, 5, 5, 5, 5};
    passed = giveChange(cshBills, cstBills, 310);
    break;
  case 15:
    cstBills = {1, 10, 17, 28, 40, 58, 60, 35, 70, 75};
    cshBills = {1, 1, 3, 100, 20, 6, 84, 56, 10, 5, 5};
    passed = !giveChange(cshBills, cstBills, 710);
    break;
  }
  return passed;
}

void runCodeAllTests() {
  cout << "### Run Code tests ###" << endl;
  int passedNum = 0;
  for (int testNum = 1; testNum <= codeTestsNum; testNum++) {
    bool passed = runCodeSingleTest(testNum);
    printTestResults(passed, testNum, passedNum);
  }
  cout << "###### passed " << passedNum << " tests ######" << endl;
}

void runChangeAllTests() {
  cout << "### Run Change tests ###" << endl;
  int passedNum = 0;
  for (int testNum = 1; testNum <= changeTestsNum; testNum++) {
    bool passed = runChangeSingleTest(testNum) && runChangeSingleTest(15) &&
                  runChangeSingleTest(3);
    printTestResults(passed, testNum, passedNum);
  }
  cout << "###### passed " << passedNum << " tests ######" << endl;
}

int main() {
  runCodeAllTests();
  runChangeAllTests();
  cout << "end" << endl;
  return 0;
}
