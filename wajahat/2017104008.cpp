// 2017104008.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <cmath>
using namespace std;

int main() {
	//Program start.
	srand((unsigned)time(NULL));
	int randomNum1 = rand() % 100 + 1;
	int randomNum2 = rand() % 100 + 1;
	int randomNum3 = rand() % 100 + 1;
	double mean1, mean2, var1, var2, sDev1, sDev2;
	
	cout << "mean: " << (mean1 = (randomNum1 + randomNum2 + randomNum3) / 3.0) << endl;
	cout << "variance: " << (var1 = (pow(randomNum1 - mean1, 2) + pow(randomNum2 - mean1, 2) + pow(randomNum3 - mean1, 2)) / 3.0) << endl;
	cout << "standard deviation: " << (sDev1 = sqrt(var1)) << "\n\n";

	randomNum1 = rand() % 100 + 1;
	randomNum2 = rand() % 100 + 1;
	randomNum3 = rand() % 100 + 1;
	cout << "mean: " << (mean2 = (randomNum1 + randomNum2 + randomNum3) / 3.0) << endl;
	cout << "variance: " << (var2 = (pow(randomNum1 - mean2, 2) + pow(randomNum2 - mean2, 2) + pow(randomNum3 - mean2, 2)) / 3.0) << endl;
	cout << "standard deviation: " << (sDev2 = sqrt(var2)) << "\n\n";

	cout << "mean diff: " << (mean1 - mean2) << endl;
	cout << "variance diff: " << (var1 - var2) << endl;
	cout << "standard deviation diff: " << (sDev1 - sDev2) << endl;
	return 0;
}