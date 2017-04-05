#include <iostream>
#include <math.h>
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
#define MAX_POS_NUM 20

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
	int temp1, temp2, loop1, loop2;
	int xSum, ySum;
	int xMinSum, yMinSum;
	bool isMinInit = true;
	//firstPosLoop[백터 번호] = (for nCr)그 전백터의 시작좌표번호와 현재 백터의 시작좌표번호 사이에 몇칸떨어져 있는가? 
	int firstPosLoop[MAX_POS_NUM / 2] = { 0, };
	//lastPosLoop[백터 번호] = (for nPn)시작점 제외, 이미선택한 백터끝점 제외하고 남은 좌표 중 몇번째의 좌표를 백터 끝점으로 삼는가?
	int lastPosLoop[MAX_POS_NUM / 2];

	while (firstPosLoop[vectorNum - 1] <= vectorNum) {//백터 시작점 선택 루프.
		//백터 시작점 구하기.
		for (temp1 = 0, loop1 = 0; loop1 < vectorNum; loop1++) {
			temp1 += firstPosLoop[loop1];
			firstPos[loop1] = temp1++;
		}
		if (firstPos[vectorNum - 1] < vectorNum * 2) {//시작점 백터 선택성공.
			//
			for (loop1 = 0; loop1 < vectorNum; loop1++) { lastPosLoop[loop1] = 0; }//백터 끝점 선택위한 정보 초기화.
			while (!lastPosLoop[vectorNum - 1]) {//백터 끝점 선택 루프.
				//백터 끝점 구하기.
				for (temp1 = 0, temp2 = 0, loop1 = 0; loop1 < vectorNum * 2; loop1++) {
					//temp1은 firstPos의 백터번호, temp2는 lastPos의 백터번호
					if (firstPos[temp1] != loop1) lastPos[temp2++] = loop1;
					else temp1++;
				}//시작점 제외한 백터 점들을 구함.
				//남은 점들을 순열 형식으로 나열함.
				for (loop1 = 0; loop1 < vectorNum - 1; loop1++) {
					temp1 = lastPos[lastPosLoop[loop1] + loop1];
					lastPos[lastPosLoop[loop1] + loop1] = lastPos[loop1];
					lastPos[loop1] = temp1;
				}

				//백터 선택 완료, 길이 계산.
				xSum = ySum = 0;
				for (loop2 = 0; loop2 < vectorNum; loop2++) {
					xSum += xPos[lastPos[loop2]] - xPos[firstPos[loop2]];
					ySum += yPos[lastPos[loop2]] - yPos[firstPos[loop2]];
				}
				if (isMinInit) {
					xMinSum = xSum; yMinSum = ySum; isMinInit = false;
				}
				else if (xSum*xSum + ySum*ySum < xMinSum*xMinSum + yMinSum*yMinSum) {
					xMinSum = xSum; yMinSum = ySum;
				}

				//백터 끝점 다음 경우의 수.
				lastPosLoop[0]++;
				for (loop1 = 0; loop1 < vectorNum - 1; loop1++) {
					if (lastPosLoop[loop1] >= vectorNum - loop1) {
						lastPosLoop[loop1] = 0, lastPosLoop[loop1 + 1]++;
					}
					else { break; }
				}
			}
			//
		}
		else { firstPosLoop[0] = vectorNum; }//불필요한 백터시작점 검색경우 제외.
		//백터 시작점 다음 경우의 수.
		firstPosLoop[0]++;
		for (loop1 = 0; loop1 < vectorNum - 1; loop1++) {
			if (firstPosLoop[loop1] > vectorNum) {
				firstPosLoop[loop1] = 0, firstPosLoop[loop1 + 1]++;
			}
			else { break; }
		}
	}
	printf_s("%.6f\n", sqrt(double(xMinSum)*xMinSum + double(yMinSum)*yMinSum));
}
//verge
