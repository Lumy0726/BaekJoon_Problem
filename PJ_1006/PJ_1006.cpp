#include <iostream>
#include <assert.h>
using std::cout;
using std::cin;
using std::endl;

//PAEKJOON online judge Problem1006.
//문제.

//mecro
#define MAX_ENTITY_NUM 10000
#define HIGH_ROW 0
#define MID_ROW 1
#define LOW_ROW 2

//type, class
struct C_area_connect {
	bool Is_connect;
	unsigned Lose_num;
};

//variable
unsigned Area_num;
unsigned Member_num;
//Entity_num[가로(2)][세로(Area_num)] = 적의 수.
unsigned Entity_num[2][MAX_ENTITY_NUM];
C_area_connect Area_connect[3][MAX_ENTITY_NUM];

//function
void Input();
void Ouput();
bool Lose_check();//현재 연결이 이어짐으로 인하여 얼마나 많은 연결기회가 사라지는지 계산함, 연결 끝 점검.
void Connect_delete(unsigned Loop1, unsigned Loop2);

//main
int main(int arg_num, char * argv[], char * env[]) {
	unsigned Test_case, Loop1;
	cin >> Test_case;
	for (Loop1 = 0; Loop1 < Test_case; Loop1++) {//각각의 테스트 케이스에 대해.
		Input();//입력 구문.1
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
	unsigned Loop1, Loop2, Temp1;
	unsigned Least_lose_num;
	int Answer = Area_num * 2;

	//convert data to Area_connect
	for (Loop1 = 0, Temp1=0; Loop1 < 2; Loop1++, Temp1+=2) {//HIGH_ROW, LOW_ROW.
		for (Loop2 = 0; Loop2 < Area_num - 1; Loop2++) {
			if (Entity_num[Loop1][Loop2] + Entity_num[Loop1][Loop2 + 1] <= Member_num) //대원들 같이 투입가능.
				Area_connect[Temp1][Loop2].Is_connect = true;
			else Area_connect[Temp1][Loop2].Is_connect = false;
		}
		if (Entity_num[Loop1][Loop2] + Entity_num[Loop1][0] <= Member_num) //대원들 같이 투입가능.
			Area_connect[Temp1][Loop2].Is_connect = true;
		else Area_connect[Temp1][Loop2].Is_connect = false;
	}
	for (Loop2 = 0; Loop2 < Area_num; Loop2++) {//MID_ROW.
		if (Entity_num[0][Loop2] + Entity_num[1][Loop2] <= Member_num) //대원들 같이 투입가능.
			Area_connect[MID_ROW][Loop2].Is_connect = true;
		else Area_connect[MID_ROW][Loop2].Is_connect = false;
	}
	//convert data end.

	while (true) {//연결가능한 것이 없어질 때까지.
		if (Lose_check()) {//현재 연결이 이어짐으로 인하여 얼마나 많은 연결기회가 사라지는지 계산함, 연결 끝 점검.
			break;
		}
		Least_lose_num = 100;
		for (Loop1 = 0; Loop1 < 3; Loop1++) {
			for (Loop2 = 0; Loop2 < Area_num; Loop2++) {
				if (Area_connect[Loop1][Loop2].Is_connect) {
					(Least_lose_num > Area_connect[Loop1][Loop2].Lose_num) ? Least_lose_num = Area_connect[Loop1][Loop2].Lose_num : 0;
				}
			}
		}
		for (Loop1 = 0; Loop1 < 3; Loop1++) {
			for (Loop2 = 0; Loop2 < Area_num; Loop2++) {
				if (Area_connect[Loop1][Loop2].Is_connect) {
					if (Least_lose_num == Area_connect[Loop1][Loop2].Lose_num) {//제일 최소의 손실으로 연결할수 있는것을 찾음.
						Connect_delete(Loop1, Loop2);
						Area_connect[Loop1][Loop2].Is_connect = false;
						Answer--;
						Loop1 = 3; Loop2 = Area_num;//루프 탈출.
					}
				}
			}
		}
	}
	cout << Answer << endl;
}
bool Lose_check(){
	unsigned Loop1, Loop2;
	bool Is_end = true;
	//초기화.
	for (Loop1 = 0; Loop1 < 3; Loop1++) {
		for (Loop2 = 0; Loop2 < Area_num; Loop2++) {
			Area_connect[Loop1][Loop2].Lose_num = 0;
		}
	}
	//현재 연결이 이어짐으로 인하여 얼마나 많은 연결기회가 사라지는지 계산함.
	for (Loop1 = 0; Loop1 < 3; Loop1++) {
		for (Loop2 = 0; Loop2 < Area_num; Loop2++) {
			if (Area_connect[Loop1][Loop2].Is_connect) {
				if (Is_end) { Is_end = false; }
				switch (Loop1) {
				case 0:
					Area_connect[HIGH_ROW][(Loop2) ? (Loop2 - 1) : (Area_num - 1)].Lose_num++;//왼쪽.
					Area_connect[HIGH_ROW][(Loop2!=Area_num - 1) ? (Loop2 + 1) : (0)].Lose_num++;//오른쪽.
					Area_connect[MID_ROW][Loop2].Lose_num++;//왼쪽아래.
					Area_connect[MID_ROW][(Loop2 != Area_num - 1) ? (Loop2 + 1) : (0)].Lose_num++;//오른쪽아래.
					break;
				case 1:
					Area_connect[HIGH_ROW][(Loop2) ? (Loop2 - 1) : (Area_num - 1)].Lose_num++;//왼쪽위.
					Area_connect[HIGH_ROW][Loop2].Lose_num++;//오른쪽위.
					Area_connect[LOW_ROW][(Loop2) ? (Loop2 - 1) : (Area_num - 1)].Lose_num++;//왼쪽아래.
					Area_connect[LOW_ROW][Loop2].Lose_num++;//오른쪽아래.
					break;
				case 2:
					Area_connect[LOW_ROW][(Loop2) ? (Loop2 - 1) : (Area_num - 1)].Lose_num++;//왼쪽.
					Area_connect[LOW_ROW][(Loop2 != Area_num - 1) ? (Loop2 + 1) : (0)].Lose_num++;//오른쪽.
					Area_connect[MID_ROW][Loop2].Lose_num++;//왼쪽위.
					Area_connect[MID_ROW][(Loop2 != Area_num - 1) ? (Loop2 + 1) : (0)].Lose_num++;//오른쪽위.
					break;
				}
			}
		}
	}
	return Is_end;
}
void Connect_delete(unsigned Loop1, unsigned Loop2) {
	switch (Loop1) {
	case 0:
		Area_connect[HIGH_ROW][(Loop2) ? (Loop2 - 1) : (Area_num - 1)].Is_connect = false;//왼쪽.
		Area_connect[HIGH_ROW][(Loop2 != Area_num - 1) ? (Loop2 + 1) : (0)].Is_connect = false;//오른쪽.
		Area_connect[MID_ROW][Loop2].Is_connect = false;//왼쪽아래.
		Area_connect[MID_ROW][(Loop2 != Area_num - 1) ? (Loop2 + 1) : (0)].Is_connect = false;//오른쪽아래.
		break;
	case 1:
		Area_connect[HIGH_ROW][(Loop2) ? (Loop2 - 1) : (Area_num - 1)].Is_connect = false;//왼쪽위.
		Area_connect[HIGH_ROW][Loop2].Is_connect = false;//오른쪽위.
		Area_connect[LOW_ROW][(Loop2) ? (Loop2 - 1) : (Area_num - 1)].Is_connect = false;//왼쪽아래.
		Area_connect[LOW_ROW][Loop2].Is_connect = false;//오른쪽아래.
		break;
	case 2:
		Area_connect[LOW_ROW][(Loop2) ? (Loop2 - 1) : (Area_num - 1)].Is_connect = false;//왼쪽.
		Area_connect[LOW_ROW][(Loop2 != Area_num - 1) ? (Loop2 + 1) : (0)].Is_connect = false;//오른쪽.
		Area_connect[MID_ROW][Loop2].Is_connect = false;//왼쪽위.
		Area_connect[MID_ROW][(Loop2 != Area_num - 1) ? (Loop2 + 1) : (0)].Is_connect = false;//오른쪽위.
		break;
	}
}
//verge
