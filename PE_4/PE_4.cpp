#include <iostream>
#include <assert.h>
using std::cout;
using std::cin;
using std::endl;

//Project_Euler Problem3.
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
unsigned power(unsigned value, unsigned num);
unsigned valuePosition(unsigned value, unsigned pos);
//main
int main(int arg_num, char * argv[], char * env[]) {
	unsigned value;
	unsigned answer = 0;
	for (int loop1 = 100; loop1 < 1000; loop1++) {
		for (int loop2 = 100; loop2 < 1000; loop2++) {
			value = loop1 * loop2;
			if (valuePosition(value, 1) == valuePosition(value, 6) &&
				valuePosition(value, 2) == valuePosition(value, 5) &&
				valuePosition(value, 3) == valuePosition(value, 4)) {
				(value > answer) ? answer = value : 0;
			}
		}
	}
	cout << answer;
	return 0;
}

//function define
unsigned power(unsigned value, unsigned num) {
	unsigned returnValue = 1;
	for (int loop1 = 0; loop1 < num; loop1++) {
		returnValue *= value;
	}
	return returnValue;
}
unsigned valuePosition(unsigned value, unsigned pos) {
	return (value % power(10, pos)) / power(10, pos - 1);
}
//verge
