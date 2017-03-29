#include <iostream>
#include <assert.h>
using std::cout;
using std::cin;
using std::endl;

//PAEKJOON online judge Problem1002
//문제.

//mecro

//type, class

//variable

//function
int Target_num(int x1, int y1, unsigned r1, int x2, int y2, unsigned r2);
//main
int main(int arg_num, char * argv[], char * env[]) {
	unsigned Test_case, r1, r2;
	int x1, x2, y1, y2, Loop1;

	cin >> Test_case;
	for (Loop1 = 0; Loop1 < (int)Test_case; Loop1++) {//각각의 케이스에 대해.
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		cout << Target_num(x1, y1, r1, x2, y2, r2) << endl;
	}

	return 0;
}

//function define
int Target_num(int x1, int y1, unsigned r1, int x2, int y2, unsigned r2) {
	unsigned Distance, Add, Sub;
	if (x1 == x2 && y1 == y2) {//두 좌표가 같은 경우.
		if (r1 == r2) { return -1; }
		else { return 0; }
	}
	else {//두 좌표가 다른 경우.
		Distance = unsigned((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));//두 좌표의 거리의 제곱.
		Add = unsigned((r1 + r2)*(r1 + r2));//두 반지름 합의 제곱.
		Sub = unsigned((r1 - r2)*(r1 - r2));//두 반지름 차의 제곱.
		if (Add < Distance) {
			return 0;
		}
		else if (Add == Distance) {
			return 1;
		}
		else if (Sub < Distance) { return 2; }
		else if (Sub == Distance) { return 1; }
		else { return 0; }
	}
}
//verge
