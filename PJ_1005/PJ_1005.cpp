#include <iostream>
#include <vector>
#include <assert.h>
using std::cout;
using std::cin;
using std::endl;
using std::vector;

//PAEKJOON online judge Problem1005.
//문제.

//mecro
#define INPUTOUTPUT_SETTING 0//0이면 각각 입력받고 출력, 1이면 한꺼번에 입력받고 출력

//type, class
struct C_pair_unsigned {
	unsigned Value1, Value2;
	C_pair_unsigned() :Value1(0), Value2(0){; }
	C_pair_unsigned(unsigned V1, unsigned V2) :Value1(V1), Value2(V2) { ; }
};
struct C_problem {
	unsigned Win_tower_num;//승리할수 있는 건물번호.
	vector<unsigned> Tower_time;//건물을 짓는데 걸리는 시간.
	vector<C_pair_unsigned> Tower_rule;//건물 건설 규칙.
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
	unsigned Input1, Input2, Loop1;
	unsigned Tower_num, Rule_num;

	//기존 내용 정리.
	Tower_time.clear(), Tower_rule.clear();
	cin >> Tower_num >> Rule_num;
	//건물건설시간 입력.
	for (Loop1 = 0; Loop1 < Tower_num; Loop1++) {
		cin >> Input1;
		Tower_time.push_back(Input1);
	}
	//건물건설규칙 입력.
	for (Loop1 = 0; Loop1 < Rule_num; Loop1++) {
		cin >> Input1 >> Input2;
		Tower_rule.push_back(C_pair_unsigned(Input1 - 1, Input2 - 1));//0부터 시작하는 건물번호로 변경.
	}
	cin >> Win_tower_num;//승리를 위한 건물번호 입력.
	Win_tower_num--;//0부터 시작하는 건물번호로 변경.
}
void C_problem::Ouput() const {
	struct C_tower_route{
		unsigned Tower_num, Tower_connetor_num;
		C_tower_route() { ; }
		C_tower_route(unsigned _Tower_num, unsigned Connetor_num) :
			Tower_num(_Tower_num), Tower_connetor_num(Connetor_num) { ; }
	};
	unsigned Time_max = 0, Time;
	unsigned Loop1;
	vector<C_tower_route> Tower_route;
	vector<vector<int>> Tower_connetor(Tower_time.size());

	//건물규칙 자료 변환(Tower_rule --> Tower_connetor).
	for (Loop1 = 0; Loop1 < Tower_rule.size(); Loop1++) {
		Tower_connetor[Tower_rule[Loop1].Value2].push_back(Tower_rule[Loop1].Value1);
	}

	//건물 건설 경로를 탐색(최종적으로 지어야 하는 건물부터 역순회).
	Tower_route.push_back(C_tower_route(Win_tower_num, 0));
	Time = Tower_time[Win_tower_num];
	while (true) {//모든 루트를 순회할 떄까지.
		if (Tower_route.back().Tower_connetor_num < Tower_connetor[Tower_route.back().Tower_num].size()) {
			//선행해서 지어야 하는 건물 탐색.
			Tower_route.push_back(
				C_tower_route(Tower_connetor[Tower_route.back().Tower_num][Tower_route.back().Tower_connetor_num], 0)
			);
			Time += Tower_time[Tower_route.back().Tower_num];
		}
		else {
			//선행해서 지어야 하는 건물 탐색 끈난 경우.
			(Time > Time_max) ? (Time_max = Time) : 0;//최고시간 기록.
			Time -= Tower_time[Tower_route.back().Tower_num];//Time되돌리기.
			Tower_route.pop_back();//Tower_route되돌리기.
			if (Tower_route.empty()) {//타워 순회 완료.
				break;
			}
			Tower_route.back().Tower_connetor_num++;//다를 타워를 순회하도록 함.
		}
	}
	cout << Time_max << endl;
}
//verge
