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
	unsigned Test_case, *r1, *r2;
	int *x1, *x2, *y1, *y2, Loop1;

	//Test case만큼 변수 할당.
	cin >> Test_case;
	r1 = new unsigned[Test_case];
	r2 = new unsigned[Test_case];
	x1 = new int[Test_case];
	x2 = new int[Test_case];
	y1 = new int[Test_case];
	y2 = new int[Test_case];

	//입력.
	for (Loop1 = 0; Loop1 < (int)Test_case; Loop1++) {
		cin >> x1[Loop1] >> y1[Loop1] >> r1[Loop1] >> x2[Loop1] >> y2[Loop1] >> r2[Loop1];
	}
	cout << endl;

	//결과 출력.
	for (Loop1 = 0; Loop1 < (int)Test_case; Loop1++) {
		cout << Target_num(x1[Loop1], y1[Loop1], r1[Loop1], x2[Loop1], y2[Loop1], r2[Loop1]) << endl;
	}

	//메모리정리.
	delete [] r1;
	delete [] r2;
	delete [] x1;
	delete [] x2;
	delete [] y1;
	delete [] y2;
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
		if (Add < Distance) { return 0; }
		else if (Add == Distance) { return 1; }
		else if (Sub < Distance) { return 2; }
		else if (Sub == Distance) { return 1; }
		else { return 0; }
	}
}
//verge
