#include "numbers.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

static string testFilePath(int testNum) {
  string srcDir = string(__FILE__);
  size_t pos = srcDir.find_last_of("/\\");
  if (pos != string::npos)
    srcDir = srcDir.substr(0, pos + 1);
  else
    srcDir = "./";
  return srcDir + "numbers/test" + to_string(testNum) + ".txt";
}

void printTestResults(bool passed, int testNum, int &passedCounter) {
  if (passed) {
    cout << "test " << testNum << " passed" << endl;
    passedCounter++;
  } else {
    cout << "test " << testNum << " failed" << endl;
  }
}

bool runNumbersTest(int testNum) {
  string fileName = testFilePath(testNum);
  ifstream inp(fileName);
  if (!inp)
    return false;

  int n, k;
  inp >> n >> k;

  vector<int> answ;
  int numb;
  while (inp >> numb) {
    answ.push_back(numb);
  }

  vector<int> res = numsSameConsecDiff(n, k);
  if (res.size() != answ.size())
    return false;
  for (size_t i = 0; i < res.size(); i++) {
    if (res[i] != answ[i])
      return false;
  }
  return true;
}

const int numbersTestsNum = 15;

void runNumbersTests() {
  cout << "### Run Numbers tests ###" << endl;
  int passedNum = 0;

  for (int testNum = 1; testNum <= numbersTestsNum; testNum++) {
    bool res = runNumbersTest(testNum);
    printTestResults(res, testNum, passedNum);
  }

  cout << "###### passed " << passedNum << " tests ######" << endl;
}

int main() {
  runNumbersTests();
  cout << "end" << endl;
  return 0;
}
