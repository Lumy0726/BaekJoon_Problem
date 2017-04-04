#include <iostream>
#include <assert.h>
using std::cout;
using std::cin;
using std::endl;

//Project_Euler Problem3.
//문제.

//system("mode con cols=80 lines=25");
//system("color f0");
//mecro
#define NUM_100 100
#define NUM_1000 1000
#define NUM_10000 10000
#define NUM_100000 100000
#define NUM_1000000 1000000
#define PROBLEM_NUM 600851475143L

//type, class

//variable

//function

//main
int main(int arg_num, char * argv[], char * env[]) {
	long long unsigned problemNum = PROBLEM_NUM;
	long long unsigned divNum;
	long long unsigned answer = 1;
	while (problemNum != 1) {
		for (divNum = 2; problemNum%divNum; divNum++) { ; }//나누어 지는수 찾음.
		problemNum /= divNum;
		(divNum > answer) ? answer = divNum : 0;
	}
	cout << answer;
	return 0;
}

//function define

//verge
