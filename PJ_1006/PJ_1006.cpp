#include <iostream>
#include <assert.h>
using std::cout;
using std::cin;
using std::endl;

//PAEKJOON online judge Problem1006.
//문제.

//mecro
#define NUM_100 100
#define NUM_1000 1000
#define MAX_ENTITY_NUM 10000
#define NUM_100000 100000
#define NUM_1000000 1000000

//type, class

//variable
unsigned Area_num;
unsigned Member_num;
//Entity_num[가로(2)][세로(Area_num)] = 적의 수.
unsigned Entity_num[2][MAX_ENTITY_NUM];

//function
void Input();
void Ouput();

//main
int main(int arg_num, char * argv[], char * env[]) {
	unsigned Test_case, Loop1;
	cin >> Test_case;
	for (Loop1 = 0; Loop1 < Test_case; Loop1++) {//각각의 테스트 케이스에 대해.
		Input();//입력 구문.
		Ouput();//출력 구문.
	}

	return 0;
}

//function define
void Input() {
	unsigned Loop1;
	cin >> Area_num >> Member_num;
	for (Loop1 = 0; Loop1 < Area_num; Loop1++) {
		cin >> Entity_num[0][Loop1];
	}
	for (Loop1 = 0; Loop1 < Area_num; Loop1++) {
		cin >> Entity_num[1][Loop1];
	}
}
void Ouput() {

}
//verge
