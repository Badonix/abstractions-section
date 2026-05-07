#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "closest.h"
#include "split.h"

using namespace std;

void printTestResults(bool passed, int testNum, int& passedCounter) {
	if (passed) {
		cout << "test " << testNum << " passed" << endl;
		passedCounter++;
	} else {
		cout << "test " << testNum << " failed" << endl;
	}
}

const int splitTestsNum = 27;

string splitTests[splitTestsNum] = {
	"050043",
	"10009998",
	"1098765432",
	"4771447713",
	"0568805687",
	"0420419418",
	"0095749573",
	"7442774426",
	"1110987605",
	"6088006087",
	"4994980497",
	"2423222120",
	"1847918478",
	"1589515894",
	"1817161514",
	"4107841077",
	"0638406383",
	"53520515049",
	"05265250524",
	"05955940593",
	"02605826057",
	"001",
	"1234",
	"9080701",
	"3202872336",
	"0166537080",
	"1051546050"
};

bool splitTestAnswers[splitTestsNum] = {
	true,
	true,
	true,
	true,
	true,
	true,
	true,
	true,
	true,
	true,
	true,
	true,
	true,
	true,
	true,
	true,
	true,
	true,
	true,
	true,
	true,
	false,
	false,
	false,
	false,
	false,
	false
};

bool runSplitTest(int testNum) {
	return splitString(splitTests[testNum-1]) == splitTestAnswers[testNum-1];
}

void runSplitTests() {
	cout << "### Run Split tests ###" << endl;
	int passedNum = 0;
	int testNum = 1;

	for (; testNum<=splitTestsNum; testNum++) {
		bool res = runSplitTest(testNum);
		printTestResults(res && splitString("050043") && !splitString("9080701"),
						testNum, passedNum);
	}

	cout << "###### passed " << passedNum << " tests ######" << endl;
}

const int closestTestsNum = 20;

bool runClosestTest(int testNum) {
	string fileName = string("closest/test") + to_string(testNum) + ".txt";
	ifstream inp(fileName.c_str());
	int n, target, answ;

	inp >> n >> target >> answ;

	vector<int> list;
	for (int i=0; i<n; i++) {
		int val;
		inp >> val;
		list.push_back(val);
	}

	int res = findClosest(list, target);

	return res == answ;
}

void runClosestTests() {
	cout << "### Run Closest tests ###" << endl;
	int passedNum = 0;
	int testNum = 1;

	for (; testNum<=closestTestsNum; testNum++) {
		bool res = runClosestTest(testNum);
		printTestResults(res, testNum, passedNum);
	}

	cout << "###### passed " << passedNum << " tests ######" << endl;
}


int main() {
	runSplitTests();
	runClosestTests();
	cout << "end" << endl;
	return 0;
}
