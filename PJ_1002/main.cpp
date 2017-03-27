#include <iostream>
#include <assert.h>
using std::cout;
using std::cin;
using std::endl;

//PAEKJOON online judge Problem1002
//����.

//mecro

//type, class

//variable

//function
int Target_num(int x1, int y1, unsigned r1, int x2, int y2, unsigned r2);
//main
int main(int arg_num, char * argv[], char * env[]) {
	unsigned Test_case, *r1, *r2;
	int *x1, *x2, *y1, *y2, Loop1;

	//Test case��ŭ ���� �Ҵ�.
	cin >> Test_case;
	r1 = new unsigned[Test_case];
	r2 = new unsigned[Test_case];
	x1 = new int[Test_case];
	x2 = new int[Test_case];
	y1 = new int[Test_case];
	y2 = new int[Test_case];

	//�Է�.
	for (Loop1 = 0; Loop1 < (int)Test_case; Loop1++) {
		cin >> x1[Loop1] >> y1[Loop1] >> r1[Loop1] >> x2[Loop1] >> y2[Loop1] >> r2[Loop1];
	}
	cout << endl;

	//��� ���.
	for (Loop1 = 0; Loop1 < (int)Test_case; Loop1++) {
		cout << Target_num(x1[Loop1], y1[Loop1], r1[Loop1], x2[Loop1], y2[Loop1], r2[Loop1]) << endl;
	}

	//�޸�����.
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
	if (x1 == x2 && y1 == y2) {//�� ��ǥ�� ���� ���.
		if (r1 == r2) { return -1; }
		else { return 0; }
	}
	else {//�� ��ǥ�� �ٸ� ���.
		Distance = unsigned((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));//�� ��ǥ�� �Ÿ��� ����.
		Add = unsigned((r1 + r2)*(r1 + r2));//�� ������ ���� ����.
		Sub = unsigned((r1 - r2)*(r1 - r2));//�� ������ ���� ����.
		if (Add < Distance) { return 0; }
		else if (Add == Distance) { return 1; }
		else if (Sub < Distance) { return 2; }
		else if (Sub == Distance) { return 1; }
		else { return 0; }
	}
}
//verge
