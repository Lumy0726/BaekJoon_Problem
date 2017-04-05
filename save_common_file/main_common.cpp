#include <iostream>
#include <assert.h>
using std::cout;
using std::cin;
using std::endl;

//Project_Euler Problem
//PAEKJOON online judge Problem
//문제.

//system("mode con cols=80 lines=25");
//system("color f0");
//mecro
#define NUM_100 100
#define NUM_1000 1000
#define NUM_10000 10000
#define NUM_100000 100000
#define NUM_1000000 1000000

//type, class

//variable

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

}
void output(){

}
//verge
/*
#include <iostream>
#include <assert.h>
using std::cout;
using std::cin;
using std::endl;

//Project_Euler Problem.
//문제.

//system("mode con cols=80 lines=25");
//system("color f0");
//mecro
#define NUM_100 100
#define NUM_1000 1000
#define NUM_10000 10000
#define NUM_100000 100000
#define NUM_1000000 1000000

//type, class

//variable

//function

//main
int main(int arg_num, char * argv[], char * env[]) {

	return 0;
}

//function define

//verge
*/
/*

#include <iostream>
#include <iomanip>
#include <math.h>
using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::setprecision;

//Project_Euler Problem
//PAEKJOON online judge Problem
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
#define _10PECT 3628800
#define _19C9 92378

//type, class

//variable

//xPos[좌표번호] = x좌표
int xPos[MAX_POS_NUM];
//yPos[좌표번호] = y좌표
int yPos[MAX_POS_NUM];
int vectorNum;//좌표들의 수 / 2 = 백터갯수.
//firstPos[백터번호] = 백터시작점의 좌표번호.
int firstPos[MAX_POS_NUM / 2];
//lastPos[백터번호] = 백터끝점의 좌표번호.
int lastPos[MAX_POS_NUM / 2];
int P[_10PECT + 1][MAX_POS_NUM / 2];

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
vectorNum >>= 1;
}
void output() {
int temp1, temp2, loop1, loop2, loopNum = 0;
long long int maxLoopNum = 1;
int dotNum = vectorNum * 2;//for optimization.
int lastVectorNum = vectorNum - 1;//for optimization.
int xSum, ySum;
int xMinSum, yMinSum, minLength = 0x0fffffff;
//firstPosLoop[백터 번호] = (for nCr)그 전백터의 시작좌표번호와 현재 백터의 시작좌표번호 사이에 몇칸떨어져 있는가?
int firstPosLoop[MAX_POS_NUM / 2] = { 0, };
//lastPosLoop[백터 번호] = (for nPn)시작점 제외, 이미선택한 백터끝점 제외하고 남은 좌표 중 몇번째의 좌표를 백터 끝점으로 삼는가?
int lastPosTemp[MAX_POS_NUM / 2];
int pectorialNum;

//팩토리얼 경우의 수 저장.
for (loop1 = 0; loop1 < lastVectorNum; loop1++) {
P[0][loop1] = 0;
}
loop1 = 0;
while (!P[loop1][lastVectorNum]) {
for (loop2 = 0; loop2 < lastVectorNum; loop2++) {//다음 경우로 현재경우 복사.
P[loop1 + 1][loop2] = P[loop1][loop2];
}
loop1++;
P[loop1][0]++;
for (loop2 = 0; loop2 < lastVectorNum; loop2++) {
if (P[loop1][loop2] >= vectorNum - loop2) {
P[loop1][loop2] = 0, P[loop1][loop2 + 1]++;
}
else { break; }
}
}
pectorialNum = loop1 - 1;

if (vectorNum==1){//예외.
cout << fixed << setprecision(6) << sqrt(double(xPos[0] - xPos[1])*(xPos[0] - xPos[1]) + double(yPos[0] - yPos[1])*(yPos[0] - yPos[1]));
return;
}
//maxLoopNum = C(dotNum - 1, vectorNum - 1); //백터 시작점 선택하는 최대 횟수.
for (temp1 = dotNum - 1, loop1 = 0; loop1 < lastVectorNum; loop1++) {
maxLoopNum *= temp1--;
}
for (loop1 = 1; loop1 < vectorNum; loop1++) {
maxLoopNum /= loop1;
}

firstPos[0] = 0;
while (true/*firstPosLoop[lastVectorNum] <= vectorNum*/) {//백터 시작점 선택 루프.
//백터 시작점 구하기.
for (temp1 = 1, loop1 = 1; loop1 < vectorNum; loop1++) {
	temp1 += firstPosLoop[loop1];
	firstPos[loop1] = temp1++;
}
if (firstPos[lastVectorNum] < dotNum) {//시작점 백터 선택성공.
																			 //
	loopNum++;
	for (temp1 = 0, temp2 = 0, loop1 = 0; loop1 < dotNum; loop1++) {//시작점 제외한 백터 점들을 구함.
																																	//temp1은 firstPos의 백터번호, temp2는 lastPos의 백터번호
		if (firstPos[temp1] != loop1) lastPosTemp[temp2++] = loop1;
		else temp1++;
	}
	for (loop1 = 0; loop1 < pectorialNum; loop1++) {//백터 끝점 선택 루프.
																									//백터 끝점 남은점 복사.
		for (loop2 = 0; loop2 < vectorNum; loop2++) {
			lastPos[loop2] = lastPosTemp[loop2];
		}
		//남은 점들을 순열 형식으로 나열함.
		for (loop2 = 0; loop2 < lastVectorNum; loop2++) {
			temp1 = lastPos[P[loop1][loop2] + loop2];
			lastPos[P[loop1][loop2] + loop2] = lastPos[loop2];
			lastPos[loop2] = temp1;
		}

		//백터 선택 완료, 길이 계산.
		xSum = ySum = 0;
		for (loop2 = 0; loop2 < vectorNum; loop2++) {
			xSum += xPos[lastPos[loop2]] - xPos[firstPos[loop2]];
			ySum += yPos[lastPos[loop2]] - yPos[firstPos[loop2]];
		}
		if (xSum*xSum + ySum*ySum < minLength) {
			xMinSum = xSum; yMinSum = ySum; minLength = xMinSum*xMinSum + yMinSum*yMinSum;
			if (!minLength) { cout << "0.000000\n"; return; }
		}
	}//백터 끝점 선택 루프 끝.
	if (loopNum >= maxLoopNum) {//모든 백터 선택 경우 완료.
		cout << fixed << setprecision(6) << sqrt(double(minLength));
		return;
	}
}
else {//불필요한 백터시작점 검색경우 제외(for optimization).
	firstPosLoop[1] = vectorNum;
}
//백터 시작점 다음 경우의 수.
firstPosLoop[1]++;
for (loop1 = 1; loop1 < lastVectorNum; loop1++) {
	if (firstPosLoop[loop1] > vectorNum) {
		firstPosLoop[loop1] = 0, firstPosLoop[loop1 + 1]++;
	}
	else { break; }
}
	}
}
//verge


*/
