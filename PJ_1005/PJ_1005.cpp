#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//PAEKJOON online judge Problem1005.
//문제.

//mecro
#define NUM_100 100
#define NUM_1000 1000
#define NUM_10000 10000
#define NUM_100000 100000
#define NUM_1000000 1000000
#define MAX_TOWER_NUM 1000
#define MAX_TOWER_RULE 100000

//type, class
struct C_pair_unsigned {
	unsigned Value1, Value2;
};
struct C_tower_route {
	unsigned Tower_num, Tower_connector_num;
};

//variable
unsigned Win_tower_num;//승리할수 있는 건물번호.
//Tower_time[건물번호] = 건물을 짓는데 걸리는 시간.
unsigned Tower_time[MAX_TOWER_NUM];
unsigned Tower_time_snum;
//Tower_rule[건물번호] = 건물규칙
//건물규칙.Value1--->건물규칙.Value2.
C_pair_unsigned Tower_rule[MAX_TOWER_RULE];
unsigned Tower_rule_snum;
//Tower_route[선행건물을 찾아간 번호] = 건물루트구조체
//건물루트구조체.Tower_num = 현재 건물번호
//건물루트구조체.Tower_connect_num = 현재 찾아가야 될 Tower_connector의 번호.
C_tower_route Tower_route[MAX_TOWER_RULE + 1];
unsigned Tower_route_snum;
//Tower_connector[건물번호][Tower_connector번호]= 선행건물번호.
unsigned Tower_connector[MAX_TOWER_NUM][(MAX_TOWER_RULE * 5) / MAX_TOWER_NUM];
//Tower_connector_snum2[건물번호] = 그 건물 connector번호들의 갯수.
unsigned Tower_connector_snum2[MAX_TOWER_NUM];

//function
void Input();
void Ouput();
C_tower_route& Last_tower_route() {
	return Tower_route[Tower_route_snum - 1];
}

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
	unsigned Input1, Input2, Loop1;
	unsigned Tower_num, Rule_num;

	//기존 내용 정리.
	Tower_time_snum = 0, Tower_rule_snum = 0;
	cin >> Tower_num >> Rule_num;
	//건물건설시간 입력.
	for (Loop1 = 0; Loop1 < Tower_num; Loop1++) {
		cin >> Input1;
		Tower_time[Tower_time_snum++]=Input1;
	}
	//건물건설규칙 입력.
	for (Loop1 = 0; Loop1 < Rule_num; Loop1++) {
		cin >> Input1 >> Input2;
		Tower_rule[Tower_rule_snum].Value1 = Input1 - 1;
		Tower_rule[Tower_rule_snum].Value2 = Input2 - 1;
		Tower_rule_snum++;
	}
	cin >> Win_tower_num;//승리를 위한 건물번호 입력.
	Win_tower_num--;//0부터 시작하는 건물번호로 변경.
}
void Ouput() {
	unsigned Time_max;
	unsigned Loop1, Temp1;
	C_tower_route Temp_last_route;
	
	Tower_route_snum = 0;
	for (Loop1 = 0; Loop1 < Tower_time_snum; Loop1++) {
		Tower_connector_snum2[Loop1] = 0;
	}
	//건물규칙 자료 변환(Tower_rule --> Tower_connector).
	for (Loop1 = 0; Loop1 < Tower_rule_snum; Loop1++) {
		Tower_connector[Tower_rule[Loop1].Value2][Tower_connector_snum2[Tower_rule[Loop1].Value2]++] = Tower_rule[Loop1].Value1;
	}

	//Tower_time[건물번호] =  시간.
	//Tower_rule[건물번호] = 건물규칙//건물규칙.Value1--->건물규칙.Value2.
	//Tower_route[선행건물을 찾아간 번호] = 건물루트구조체
	//건물루트구조체.Tower_num = 현재 건물번호
	//건물루트구조체.Tower_connect_num = 현재 찾아가야 될 Tower_connector의 번호.
	//Tower_connector[건물번호][Tower_connector번호]= 선행건물번호.
	//Tower_connector_snum[건물번호] = 그 건물의 선행건물의 수.

	//건물 건설 경로를 탐색(최종적으로 지어야 하는 건물부터 역순회).
	Tower_route[Tower_route_snum].Tower_num = Win_tower_num;
	Tower_route[Tower_route_snum].Tower_connector_num = 0;
	Tower_route_snum++;
	while (true) {//모든 루트를 순회할 때까지.
		Temp_last_route = Last_tower_route();
		if (Temp_last_route.Tower_connector_num < Tower_connector_snum2[Temp_last_route.Tower_num]) {
			//탐색하지 않은 선행해서 지어야 하는 건물 존재.
			//그쪽으로 Tower_route이동.
			Tower_route[Tower_route_snum].Tower_num = Tower_connector[Temp_last_route.Tower_num][Temp_last_route.Tower_connector_num];
			Tower_route[Tower_route_snum].Tower_connector_num = 0;
			Tower_route_snum++;
		}
		else {
			//선행해서 지어야 하는 건물 탐색 끝난 경우.
			Time_max = 0; Temp1 = Tower_connector_snum2[Temp_last_route.Tower_num];
			for (Loop1 = 0; Loop1 < Temp1; Loop1++) {//현재 건물들의 선행건물들 중  건설최고시간 구함.
				if (Time_max < Tower_time[Tower_connector[Temp_last_route.Tower_num][Loop1]]) {
					Time_max = Tower_time[Tower_connector[Temp_last_route.Tower_num][Loop1]];
				}
			}
			Tower_time[Temp_last_route.Tower_num] += Time_max;
			Tower_connector_snum2[Temp_last_route.Tower_num] = 0;//선행 건물들을 전부 점검하고 시간을 더했으므로 더이상 선행건물 필요없음.
			Tower_route_snum--;//Tower_route되돌리기.
			if (Tower_route_snum==0) {//타워 순회 완료.
				break;
			}
			Last_tower_route().Tower_connector_num++;//다른 타워를 순회하도록 함.
		}
	}
	cout << Tower_time[Win_tower_num] << endl;
}
//verge
