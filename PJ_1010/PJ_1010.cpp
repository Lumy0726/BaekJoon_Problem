#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//PAEKJOON online judge Problem1010.
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
unsigned n;
unsigned r;
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
	cin >> r >> n;
}
void output() {//nCr구함.
	long long unsigned answer = 1;
	int loop1;
	(n - r < r) ? r = n - r : 0;
	for (loop1 = n; loop1 > n - r; loop1--) {
		answer *= loop1;
	}
	for (loop1 = 2; loop1 <= r; loop1++) {
		answer /= loop1;
	}
	cout << answer << endl;
}
//verge
