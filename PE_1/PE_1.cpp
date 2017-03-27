#include <iostream>
#include <assert.h>
using std::cout;
using std::cin;
using std::endl;

//Project_Euler Problem1
//1000보다 작은 수 중에서 3의 배수이거나 5의 배수인 수들의 합은?

//mecro
#define PROBLEM_NUM 1000

//type, class

//variable

//function
unsigned Sol1();
unsigned Sol2();
unsigned Sol_generalization(unsigned Problem_num, unsigned Input1, unsigned Input2);
int Arithmetic_sum(int First, unsigned Num, int Dif);
unsigned gcd(unsigned a, unsigned b);
unsigned lcm(unsigned a, unsigned b);

//main
int main(int arg_num, char * argv[], char * env[]) {
	cout << "Sol1: " << Sol1() << endl;
	cout << "Sol2: " << Sol2() << endl;
	cout << "Sol_generalization: " << Sol_generalization(PROBLEM_NUM, 3, 5) << endl;
	return 0;
}

//function define
unsigned Sol1() {
	unsigned Sum = 0;
	for (int Num = 1; Num < PROBLEM_NUM; Num++) {
		if (Num % 3 == 0) { Sum += Num; }
		else if (Num % 5 == 0) { Sum += Num; }
	}
	return Sum;
}
unsigned Sol2() {
	return Arithmetic_sum(3,(PROBLEM_NUM - 1) / 3, 3) + 
		Arithmetic_sum(5, (PROBLEM_NUM - 1) / 5, 5) - 
		Arithmetic_sum(15, (PROBLEM_NUM - 1) / 15, 15);
}
unsigned Sol_generalization(unsigned Problem_num, unsigned Input1, unsigned Input2) {
	return Arithmetic_sum(Input1, (Problem_num - 1) / Input1, Input1) +
		Arithmetic_sum(Input2, (Problem_num - 1) / Input2, Input2) -
		Arithmetic_sum(lcm(Input1, Input2), (Problem_num - 1) / lcm(Input1, Input2), lcm(Input1, Input2));
}
int Arithmetic_sum(int First, unsigned Num, int Dif) {
	return Num * (2 * First + Dif * (Num - 1)) / 2;
}
unsigned gcd(unsigned a, unsigned b) {
	if (b == 0) {
		assert(("Division with 0.", false)); return 1;
	}
	if (a == 0) {
		return b;
	}
	else if (((a>b) ? a : b) % ((a>b) ? b : a) == 0) {
		return ((a>b) ? b : a);
	}
	else {
		return gcd(((a>b) ? b : a), ((a>b) ? a : b) % ((a>b) ? b : a));
	}
}
unsigned lcm(unsigned a, unsigned b) {
	return a * b / gcd(a, b);
}
//verge
