#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//PAEKJOON online judge Problem1011.
//����.

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
unsigned distance;//���� �Ÿ�.


//function
void input();
void output();

//main
int main(int arg_num, char * argv[], char * env[]) {
	unsigned test_case, loop1;
	cin >> test_case;
	for (loop1 = 0; loop1 < test_case; loop1++) {//������ �׽�Ʈ ���̽��� ����.
		input();//�Է� ����.
		output();//��� ����.
	}

	return 0;
}

//function define
void input() {
	unsigned input1, input2;
	cin >> input1 >> input2;
	distance = input2 - input1;
}
void output() {
	unsigned answer = 0;
	for (unsigned loop1 = 2; 1; loop1 += 2) {
		if (loop1 > distance ) {//���� ���� �Ұ���.
			if (distance <= loop1 / 2) {
				answer += 1; break;
			}
			else {
				answer += 2; break;
			}
		}
		else {//���� ����.
			distance -= loop1;
			answer += 2;
			if (!distance) { break; }
		}
	}
	cout << answer << endl;
}
//verge