#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//Project_Euler Proble8.
//¹®Á¦.

//system("mode con cols=80 lines=25");
//system("color f0");
//mecro
#define NUM_100 100
#define NUM_1000 1000
#define NUM_10000 10000
#define NUM_100000 100000
#define NUM_1000000 1000000
#define WIDTH 50
#define LINE 20
#define LONGINT long long int
//type, class

//variable

//function
void clearCin() {
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
}
//main
int main(int arg_num, char * argv[], char * env[]) {
	int num[WIDTH];
	int answer = 0, temp;
	int loop1, loop2, loop3;
	for (loop1 = 0; loop1 < LINE; loop1++) {
		for (loop2 = 0; loop2 < WIDTH; loop2++) {
			num[loop2] = int(cin.get() - '0');
		}
		for (loop2 = 0; loop2 < WIDTH - 4; loop2++) {
			temp = 1;
			for (loop3 = 0; loop3 < 5; loop3++) {
				temp *= num[loop2 + loop3];
			}
			(temp > answer) ? answer = temp : 0;
		}
		clearCin();
	}
	cout << "answer is: " << answer;
	return 0;
}

//function define

//verge