#include <iostream>
#include <math.h>
using std::cout;
using std::cin;
using std::endl;

//Project_Euler Problem
//PAEKJOON online judge Problem
//����.

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

//xPos[��ǥ��ȣ] = x��ǥ
int xPos[MAX_POS_NUM];
//yPos[��ǥ��ȣ] = y��ǥ
int yPos[MAX_POS_NUM];
int vectorNum;//��ǥ���� �� / 2 = ���Ͱ���.
//firstPos[���͹�ȣ] = ���ͽ������� ��ǥ��ȣ.
int firstPos[MAX_POS_NUM / 2];
//lastPos[���͹�ȣ] = ���ͳ����� ��ǥ��ȣ.
int lastPos[MAX_POS_NUM / 2];

//function
void input();
void output();

//main
int main(int arg_num, char * argv[], char * env[]) {
	unsigned test_case, loop1;
	cin >> test_case;
	for (loop1 = 0; loop1 < test_case; loop1++) {//������ �׽�Ʈ ���̽��� ����.
		input();//�Է� ����.
		output();//��� ����.
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
	//firstPosLoop[���� ��ȣ] = (for nCr)�� �������� ������ǥ��ȣ�� ���� ������ ������ǥ��ȣ ���̿� ��ĭ������ �ִ°�? 
	int firstPosLoop[MAX_POS_NUM / 2] = { 0, };
	//lastPosLoop[���� ��ȣ] = (for nPn)������ ����, �̹̼����� ���ͳ��� �����ϰ� ���� ��ǥ �� ���°�� ��ǥ�� ���� �������� ��°�?
	int lastPosLoop[MAX_POS_NUM / 2];

	while (firstPosLoop[vectorNum - 1] <= vectorNum) {//���� ������ ���� ����.
		//���� ������ ���ϱ�.
		for (temp1 = 0, loop1 = 0; loop1 < vectorNum; loop1++) {
			temp1 += firstPosLoop[loop1];
			firstPos[loop1] = temp1++;
		}
		if (firstPos[vectorNum - 1] < vectorNum * 2) {//������ ���� ���ü���.
			//
			for (loop1 = 0; loop1 < vectorNum; loop1++) { lastPosLoop[loop1] = 0; }//���� ���� �������� ���� �ʱ�ȭ.
			while (!lastPosLoop[vectorNum - 1]) {//���� ���� ���� ����.
				//���� ���� ���ϱ�.
				for (temp1 = 0, temp2 = 0, loop1 = 0; loop1 < vectorNum * 2; loop1++) {
					//temp1�� firstPos�� ���͹�ȣ, temp2�� lastPos�� ���͹�ȣ
					if (firstPos[temp1] != loop1) lastPos[temp2++] = loop1;
					else temp1++;
				}//������ ������ ���� ������ ����.
				//���� ������ ���� �������� ������.
				for (loop1 = 0; loop1 < vectorNum - 1; loop1++) {
					temp1 = lastPos[lastPosLoop[loop1] + loop1];
					lastPos[lastPosLoop[loop1] + loop1] = lastPos[loop1];
					lastPos[loop1] = temp1;
				}

				//���� ���� �Ϸ�, ���� ���.
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

				//���� ���� ���� ����� ��.
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
		else { firstPosLoop[0] = vectorNum; }//���ʿ��� ���ͽ����� �˻���� ����.
		//���� ������ ���� ����� ��.
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
