#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//Project_Euler Proble7.
//¹®Á¦.

//system("mode con cols=80 lines=25");
//system("color f0");
//mecro
#define NUM_100 100
#define NUM_1000 1000
#define NUM_10000 10000
#define NUM_100000 100000
#define NUM_1000000 1000000
#define PROBLEM_NUM 10001
#define LONGINT long long int
//type, class

//variable

//function

//main
int main(int arg_num, char * argv[], char * env[]) {
	LONGINT primeNum[PROBLEM_NUM];
	primeNum[0] = 2L;
	int primeNum_snum = 1;
	for (LONGINT loop1 = 3; primeNum_snum < PROBLEM_NUM; loop1 += 2) {
		int loop2;
		for (loop2 = 0; loop2 < primeNum_snum; loop2++) {
			if (loop1 % primeNum[loop2] == 0) { loop2 = -1; break; }
		}
		if (loop2 == -1) { continue; }
		primeNum[primeNum_snum++] = loop1;
	}
	cout << primeNum[primeNum_snum - 1];
	return 0;
}

//function define

//verge