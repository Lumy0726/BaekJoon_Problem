#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//Project_Euler Problem6.
//¹®Á¦.

//system("mode con cols=80 lines=25");
//system("color f0");
//mecro
#define NUM_100 100
#define NUM_1000 1000
#define NUM_10000 10000
#define NUM_100000 100000
#define NUM_1000000 1000000
#define PROBLEM_NUM 100
#define LONGINT long long int
//type, class

//variable

//function
LONGINT pow2Sum(LONGINT input);
LONGINT sumPow2(LONGINT input);
//main
int main(int arg_num, char * argv[], char * env[]) {
	cout << sumPow2(PROBLEM_NUM) - pow2Sum(PROBLEM_NUM);
	return 0;
}

//function define
LONGINT pow2Sum(LONGINT input) {
	return input * (input + 1) / 2 * (2 * input + 1) / 3;
}
LONGINT sumPow2(LONGINT input) {
	LONGINT temp = input * (input + 1) / 2;
	return temp * temp;
}
//verge