#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

//Project_Euler Problem2
//피보나치 수열이면서 짝수이면서 4백만 이하인 항들의 합은?

//mecro
#define PROBLEM_NUM 4000000
#define LARGE_NUM 10000000
//type, class

//variable

//function
unsigned Sol1();//단순 반복문 해결.
unsigned Sol2();//수학적 귀납법 정의에서 간단한 식을 만들어 해결.

//main
int main(int arg_num, char * argv[], char * env[]) {
	int Time1, Time2, Loop1;
	cout << "Sol1: " << Sol1() << endl;
	cout << "Sol2: " << Sol2() << endl;

	//시간의 비를 측정해 봅시다.
	Time1 = GetTickCount();
	for (Loop1 = 0; Loop1 < LARGE_NUM; Loop1++) { Sol1(); }
	cout << "Sol1Time : " << (Time1 = GetTickCount() - Time1) << endl;//현재 테스트 약 1300.
	Time2 = GetTickCount();
	for (Loop1 = 0; Loop1 < LARGE_NUM; Loop1++) { Sol2(); }
	cout << "Sol2Time : " << (Time2 = GetTickCount() - Time2) << endl;//현재 테스트 약 540.
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
	//피보나치 수열은 a(n) = a(n - 1) + a(n -2);
	//피보나치수열의 짝수의 주기는 3이다.
	//a(n - 1) = 2 * a(n - 3) + a(n - 4);
	//a(n) = 2 * a(n - 1) - 2 * a(n - 3);
	//이 성질을 이용하여 답을 구한다.
	//ex) 피보나치수열이 1, 2, 3, 5, 8일때,
	//5는 2를 2번더하고 1을 1번더한며,
	//8은 5을 2번더하고 2을 한번뺀다.
	unsigned Num1 = 1, Num2 = 2, Sum = 0;
	while (Num2 <= PROBLEM_NUM) {
		Sum += Num2;
		Num1 += 2 * Num2;
		Num2 = 2 * Num1 - Num2;
	}
	return Sum;
}
//verge
