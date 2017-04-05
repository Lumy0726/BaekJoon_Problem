#include <iostream>
#include <assert.h>
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

//type, class

//variable

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
//����.

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
#define _10PECT 3628800
#define _19C9 92378

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
int P[_10PECT + 1][MAX_POS_NUM / 2];

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
int temp1, temp2, loop1, loop2, loopNum = 0;
long long int maxLoopNum = 1;
int dotNum = vectorNum * 2;//for optimization.
int lastVectorNum = vectorNum - 1;//for optimization.
int xSum, ySum;
int xMinSum, yMinSum, minLength = 0x0fffffff;
//firstPosLoop[���� ��ȣ] = (for nCr)�� �������� ������ǥ��ȣ�� ���� ������ ������ǥ��ȣ ���̿� ��ĭ������ �ִ°�?
int firstPosLoop[MAX_POS_NUM / 2] = { 0, };
//lastPosLoop[���� ��ȣ] = (for nPn)������ ����, �̹̼����� ���ͳ��� �����ϰ� ���� ��ǥ �� ���°�� ��ǥ�� ���� �������� ��°�?
int lastPosTemp[MAX_POS_NUM / 2];
int pectorialNum;

//���丮�� ����� �� ����.
for (loop1 = 0; loop1 < lastVectorNum; loop1++) {
P[0][loop1] = 0;
}
loop1 = 0;
while (!P[loop1][lastVectorNum]) {
for (loop2 = 0; loop2 < lastVectorNum; loop2++) {//���� ���� ������ ����.
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

if (vectorNum==1){//����.
cout << fixed << setprecision(6) << sqrt(double(xPos[0] - xPos[1])*(xPos[0] - xPos[1]) + double(yPos[0] - yPos[1])*(yPos[0] - yPos[1]));
return;
}
//maxLoopNum = C(dotNum - 1, vectorNum - 1); //���� ������ �����ϴ� �ִ� Ƚ��.
for (temp1 = dotNum - 1, loop1 = 0; loop1 < lastVectorNum; loop1++) {
maxLoopNum *= temp1--;
}
for (loop1 = 1; loop1 < vectorNum; loop1++) {
maxLoopNum /= loop1;
}

firstPos[0] = 0;
while (true/*firstPosLoop[lastVectorNum] <= vectorNum*/) {//���� ������ ���� ����.
//���� ������ ���ϱ�.
for (temp1 = 1, loop1 = 1; loop1 < vectorNum; loop1++) {
	temp1 += firstPosLoop[loop1];
	firstPos[loop1] = temp1++;
}
if (firstPos[lastVectorNum] < dotNum) {//������ ���� ���ü���.
																			 //
	loopNum++;
	for (temp1 = 0, temp2 = 0, loop1 = 0; loop1 < dotNum; loop1++) {//������ ������ ���� ������ ����.
																																	//temp1�� firstPos�� ���͹�ȣ, temp2�� lastPos�� ���͹�ȣ
		if (firstPos[temp1] != loop1) lastPosTemp[temp2++] = loop1;
		else temp1++;
	}
	for (loop1 = 0; loop1 < pectorialNum; loop1++) {//���� ���� ���� ����.
																									//���� ���� ������ ����.
		for (loop2 = 0; loop2 < vectorNum; loop2++) {
			lastPos[loop2] = lastPosTemp[loop2];
		}
		//���� ������ ���� �������� ������.
		for (loop2 = 0; loop2 < lastVectorNum; loop2++) {
			temp1 = lastPos[P[loop1][loop2] + loop2];
			lastPos[P[loop1][loop2] + loop2] = lastPos[loop2];
			lastPos[loop2] = temp1;
		}

		//���� ���� �Ϸ�, ���� ���.
		xSum = ySum = 0;
		for (loop2 = 0; loop2 < vectorNum; loop2++) {
			xSum += xPos[lastPos[loop2]] - xPos[firstPos[loop2]];
			ySum += yPos[lastPos[loop2]] - yPos[firstPos[loop2]];
		}
		if (xSum*xSum + ySum*ySum < minLength) {
			xMinSum = xSum; yMinSum = ySum; minLength = xMinSum*xMinSum + yMinSum*yMinSum;
			if (!minLength) { cout << "0.000000\n"; return; }
		}
	}//���� ���� ���� ���� ��.
	if (loopNum >= maxLoopNum) {//��� ���� ���� ��� �Ϸ�.
		cout << fixed << setprecision(6) << sqrt(double(minLength));
		return;
	}
}
else {//���ʿ��� ���ͽ����� �˻���� ����(for optimization).
	firstPosLoop[1] = vectorNum;
}
//���� ������ ���� ����� ��.
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
