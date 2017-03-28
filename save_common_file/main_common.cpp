#include <iostream>
#include <vector>
#include <assert.h>
using std::cout;
using std::cin;
using std::endl;
using std::vector;

//Project_Euler Problem
//PAEKJOON online judge Problem
//문제.

//mecro
#define INPUTOUTPUT_SETTING 1//0이면 각각 입력받고 출력, 1이면 한꺼번에 입력받고 출력

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
	for (Loop1 = 0; Loop1 < Test_case; Loop1++) {//각각의 테스트 케이스에 대해.
		Problem.Input();//입력 구문.
		Problem.Ouput();//출력 구문.
	}
#else
	C_problem *Problem;
	cin >> Test_case;
	Problem = new C_problem[Test_case];
	for (Loop1 = 0; Loop1 < Test_case; Loop1++) {//각각의 테스트 케이스에 대해.
		Problem[Loop1].Input();//입력 구문.
	}
	for (Loop1 = 0; Loop1 < Test_case; Loop1++) {//각각의 테스트 케이스에 대해.
		Problem[Loop1].Ouput();//출력 구문.
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
