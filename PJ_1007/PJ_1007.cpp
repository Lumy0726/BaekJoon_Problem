#include <iostream>
#include <iomanip>
#include <math.h>
using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::setprecision;

//PAEKJOON online judge Problem1007.
//문제.

//system("mode con cols=80 lines=25");
//system("color f0");
//mecro
#define NUM_100 100
#define NUM_1000 1000
#define NUM_10000 10000
#define NUM_100000 100000
#define NUM_1000000 1000000
#define MAX_POS_NUM 20

//type, class

//variable

//xPos[좌표번호] = x좌표
int xPos[MAX_POS_NUM];
//yPos[좌표번호] = y좌표
int yPos[MAX_POS_NUM];
int vectorNum;//좌표들의 수 / 2 = 백터갯수.
//firstPos[백터번호] = 백터시작점의 좌표번호.
int firstPos[MAX_POS_NUM / 2 + 1];

//function
void input();
void output();

//main
int main(int arg_num, char * argv[], char * env[]) {
	unsigned test_case, loop1;
	cin >> test_case;
	for (loop1 = 0; loop1 < test_case; loop1++) {//각각의 테스트 케이스에 대해.
		input();//입력 구문.
		output();//출력 구문.
	}

	return 0;
}

//function define
void input() {
	cin >> vectorNum;
	for (int loop1 = 0; loop1 < vectorNum; loop1++) {
		cin >> xPos[loop1] >> yPos[loop1];
	}
	vectorNum /= 2;
}
void output() {
	int temp1, loop1;
	int dotNum = vectorNum * 2;//for optimization.
	int lastVectorNum = vectorNum - 1;//for optimization.
	long long int xSum, ySum;
	long long int xMinSum, yMinSum, length, minLength = (long long unsigned int)(-1) / 2;

	for (loop1 = 0; loop1 < vectorNum; loop1++) {
		firstPos[loop1] = loop1;
	}
	firstPos[loop1] = -1;
	while (!firstPos[0]) {//백터 시작점 선택 루프.
		//백터 선택 완료, 길이 계산.
		xSum = ySum = 0;
		for (temp1 = 0, loop1 = 0; loop1 < dotNum; loop1++) {
			if (firstPos[temp1] == loop1) {
				xSum -= xPos[loop1]; ySum -= yPos[loop1]; temp1++;
			}
			else {
				xSum += xPos[loop1]; ySum += yPos[loop1];
			}
		}
		length = xSum*xSum + ySum*ySum;
		if (length < minLength) {
			if (!length) { cout << "0.000000\n"; return; }
			minLength = length;
		}
		//백터 시작점 다음 경우의 수.
		firstPos[loop1 = lastVectorNum]++;
		while (true) {
			if (firstPos[loop1] < dotNum) {
				if (loop1 == lastVectorNum) { break; }
				else { firstPos[loop1 + 1] = firstPos[loop1] + 1, loop1++; }
			}
			else { firstPos[--loop1]++; }
		}
	}
	cout << fixed << setprecision(6) << sqrt(double(minLength)) << endl;
}
//verge
