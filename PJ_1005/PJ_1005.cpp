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
	C_problem Problem;
	cin >> Test_case;
	for (Loop1 = 0; Loop1 < Test_case; Loop1++) {//각각의 테스트 케이스에 대해.
		Problem.Input();//입력 구문.
		Problem.Ouput();//출력 구문.
	}
	return 0;
}

//function define
void C_problem::Input() {

}
void C_problem::Ouput() const {

}
//verge
