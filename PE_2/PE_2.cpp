#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

//Project_Euler Problem2
//�Ǻ���ġ �����̸鼭 ¦���̸鼭 4�鸸 ������ �׵��� ����?

//mecro
#define PROBLEM_NUM 4000000
#define LARGE_NUM 10000000
//type, class

//variable

//function
unsigned Sol1();//�ܼ� �ݺ��� �ذ�.
unsigned Sol2();//������ �ͳ��� ���ǿ��� ������ ���� ����� �ذ�.

//main
int main(int arg_num, char * argv[], char * env[]) {
	int Time1, Time2, Loop1;
	cout << "Sol1: " << Sol1() << endl;
	cout << "Sol2: " << Sol2() << endl;

	//�ð��� �� ������ ���ô�.
	Time1 = GetTickCount();
	for (Loop1 = 0; Loop1 < LARGE_NUM; Loop1++) { Sol1(); }
	cout << "Sol1Time : " << (Time1 = GetTickCount() - Time1) << endl;//���� �׽�Ʈ �� 1300.
	Time2 = GetTickCount();
	for (Loop1 = 0; Loop1 < LARGE_NUM; Loop1++) { Sol2(); }
	cout << "Sol2Time : " << (Time2 = GetTickCount() - Time2) << endl;//���� �׽�Ʈ �� 540.
	cout << "Sol1 time ratio Sol2: " << fixed << setprecision(7) << (Time1 / (double)Time2) << endl;
	return 0;
}

//function define
unsigned Sol1() {
	unsigned Num1 = 1, Num2 = 2, Sum = 0;
	while (Num2 <= PROBLEM_NUM) {
		if (Num2 % 2 == 0) {
			Sum += Num2;
		}
		Num2 += Num1;
		Num1 = Num2 - Num1;
	}
	return Sum;
}
unsigned Sol2() {
	//�Ǻ���ġ ������ a(n) = a(n - 1) + a(n -2);
	//�Ǻ���ġ������ ¦���� �ֱ�� 3�̴�.
	//a(n - 1) = 2 * a(n - 3) + a(n - 4);
	//a(n) = 2 * a(n - 1) - 2 * a(n - 3);
	//�� ������ �̿��Ͽ� ���� ���Ѵ�.
	//ex) �Ǻ���ġ������ 1, 2, 3, 5, 8�϶�,
	//5�� 2�� 2�����ϰ� 1�� 1�����Ѹ�,
	//8�� 5�� 2�����ϰ� 2�� �ѹ�����.
	unsigned Num1 = 1, Num2 = 2, Sum = 0;
	while (Num2 <= PROBLEM_NUM) {
		Sum += Num2;
		Num1 += 2 * Num2;
		Num2 = 2 * Num1 - Num2;
	}
	return Sum;
}
//verge
