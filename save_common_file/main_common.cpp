#include <iostream>
#include <vector>
#include <assert.h>
using std::cout;
using std::cin;
using std::endl;
using std::vector;

//Project_Euler Problem
//PAEKJOON online judge Problem
//����.

//mecro
#define INPUTOUTPUT_SETTING 1//0�̸� ���� �Է¹ް� ���, 1�̸� �Ѳ����� �Է¹ް� ���

//type, class
struct C_problem {
	C_problem() { ; }
	void Input();
	void Ouput()const;
};

//variable

//function

//main
int main(int arg_num, char * argv[], char * env[]) {
	unsigned Test_case, Loop1;
#if (INPUTOUTPUT_SETTING==0)
	C_problem Problem;
	cin >> Test_case;
	for (Loop1 = 0; Loop1 < Test_case; Loop1++) {//������ �׽�Ʈ ���̽��� ����.
		Problem.Input();//�Է� ����.
		Problem.Ouput();//��� ����.
	}
#else
	C_problem *Problem;
	cin >> Test_case;
	Problem = new C_problem[Test_case];
	for (Loop1 = 0; Loop1 < Test_case; Loop1++) {//������ �׽�Ʈ ���̽��� ����.
		Problem[Loop1].Input();//�Է� ����.
	}
	for (Loop1 = 0; Loop1 < Test_case; Loop1++) {//������ �׽�Ʈ ���̽��� ����.
		Problem[Loop1].Ouput();//��� ����.
	}
	delete[] Problem;
#endif
	return 0;
}

//function define
void C_problem::Input() {

}
void C_problem::Ouput() const{

}
//verge
