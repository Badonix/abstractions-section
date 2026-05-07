#include <iostream>
#include <string>
#include <vector>
#include "boxes.h"

using namespace std;

void printTestResults(bool passed, int testNum, int & passedCounter) {
	if (passed) {
		cout << "test " << testNum << " passed" << endl;
		passedCounter++;
	} else {
		cout << "test " << testNum << " failed" << endl;
	}
}

const int boxesTestsNum = 20;

bool runBoxesSingleTest(int testNum) {
	vector<int> weights;
	bool passed = false;
	switch (testNum) {
		case 1:
			weights = {1,1,1,1};
			passed = canDivideBoxes(2, weights) == true;
			break;
		case 2:
			weights = {1,1,1,1};
			passed = canDivideBoxes(4, weights) == true;
			break;
		case 3:
			weights = {2,3,4,1,5,8,5};
			passed = canDivideBoxes(4, weights) == false;
			break;
		case 4:
			weights = {1,1,1,3,3,3};
			passed = canDivideBoxes(3, weights) == true;
			break;
		case 5:
			weights = {4,1,2,3,3,2,5,1,5,1};
			passed = canDivideBoxes(3, weights) == true;
			break;
		case 6:
			weights = {7,1,2,3,1,5,6,3,4};
			passed = canDivideBoxes(4, weights) == true;
			break;
		case 7:
			weights = {1,3,3,3,3,3};
			passed = canDivideBoxes(4, weights) == false;
			break;
		case 8:
			weights = {7};
			passed = canDivideBoxes(1, weights) == true;
			break;
		case 9:
			weights = {2,3,2,4,5,1,3,10};
			passed = canDivideBoxes(2, weights) == true;
			break;
		case 10:
			weights = {2,3,2,4,5,1,3,20};
			passed = canDivideBoxes(4, weights) == false;
			break;
		case 11:
			weights = {2,3,2,4,5,1,3,30};
			passed = canDivideBoxes(4, weights) == false;
			break;
		case 12:
			weights = {1,1,1,1};
			passed = canDivideBoxes(4, weights) == true;
			break;
		case 13:
			weights = {1,2,3,4,2};
			passed = canDivideBoxes(3, weights) == true;
			break;
		case 14:
			weights = {3,4,3,2,1,2,3,5,6,1};
			passed = canDivideBoxes(3, weights) == true;
			break;
		case 15:
			weights = {3,2,4,5,6,1,3,5,2,1};
			passed = canDivideBoxes(4, weights) == true;
			break;
		case 16:
			weights = {1,1,1,5,6,11,16,4};
			passed = canDivideBoxes(3, weights) == false;
			break;
		case 17:
			weights = {1,1,1,5,6,11,13,4};
			passed = canDivideBoxes(3, weights) == false;
			break;
		case 18:
			weights = {1,2,1,5,6,11,13,3};
			passed = canDivideBoxes(3, weights) == true;
			break;
		case 19:
			weights = {1,9,2,4,3,1,6,8,2};
			passed = canDivideBoxes(4, weights) == true;
			break;
		case 20:
			weights = {1,10,2,4,3,1,6,8,2,3};
			passed = canDivideBoxes(4, weights) == true;
			break;
	}

	return passed;
}

void runBoxesAllTests() {
	cout << "### Run Boxes tests ###" << endl;
	int passedNum = 0;
	int testNum = 1;

	for (; testNum<=boxesTestsNum; testNum++) {
		bool res = runBoxesSingleTest(testNum) &&
					runBoxesSingleTest(3) &&
					runBoxesSingleTest(4);

		printTestResults(res, testNum, passedNum);
	}

	cout << "###### passed " << passedNum << " tests ######" << endl;
}

int main() {
	runBoxesAllTests();
	cout << "end" << endl;
	return 0;
}
