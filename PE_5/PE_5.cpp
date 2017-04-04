#include <iostream>
#include <assert.h>
using std::cout;
using std::cin;
using std::endl;

//Project_Euler Problem5.
//¹®Á¦.

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
long long unsigned gcd(long long unsigned a, long long unsigned b);
long long unsigned lcm(long long unsigned a, long long unsigned b);
//main
int main(int arg_num, char * argv[], char * env[]) {
	long long unsigned answer = 1;
	for (int loop1 = 1; loop1 <= 20; loop1++) {
		answer = lcm(answer, loop1);
	}
	cout << answer;
	return 0;
}

//function define
long long unsigned gcd(long long unsigned a, long long unsigned b) {
	if (b == 0) {
		return 1;
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
long long unsigned lcm(long long unsigned a, long long unsigned b) {
	return a * b / gcd(a, b);
}

//verge
