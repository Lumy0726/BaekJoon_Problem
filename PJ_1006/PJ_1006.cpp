#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//PAEKJOON online judge Problem1006.
//문제.

//mecro
//#define MAX_ENTITY_NUM 10000
#define MAX_ENTITY_NUM 8
#define HIGH_ROW 0
#define MID_ROW 1
#define LOW_ROW 2

//type, class

//variable
unsigned Area_num;
unsigned Member_num;
//Entity_num[가로(2)][세로(Area_num)] = 적의 수.
unsigned Entity_num[2][MAX_ENTITY_NUM];
bool Area_connect[3][MAX_ENTITY_NUM];

//function
void Input();
void Ouput();
unsigned Connect_delete(unsigned Loop1, unsigned Loop2, bool Force_delete = false);
inline unsigned Right(unsigned Input);
inline unsigned Left(unsigned Input);

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
	int Loop1, Loop2, Temp1;
	int Answer = Area_num * 2;
	bool Con_able_ent[2][MAX_ENTITY_NUM] = {false, };

	//convert data to Area_connect
	for (Loop1 = 0, Temp1 = 0; Loop1 < 2; Loop1++, Temp1 += 2) {//HIGH_ROW, LOW_ROW.
		for (Loop2 = 0; Loop2 < Area_num - 1; Loop2++) {
			if (Entity_num[Loop1][Loop2] + Entity_num[Loop1][Loop2 + 1] <= Member_num) //대원들 같이 투입가능.
				Area_connect[Temp1][Loop2] = true;
			else Area_connect[Temp1][Loop2] = false;
		}
		if (Entity_num[Loop1][Loop2] + Entity_num[Loop1][0] <= Member_num) //대원들 같이 투입가능.
			Area_connect[Temp1][Loop2] = true;
		else Area_connect[Temp1][Loop2] = false;
	}
	for (Loop2 = 0; Loop2 < Area_num; Loop2++) {//MID_ROW.
		if (Entity_num[0][Loop2] + Entity_num[1][Loop2] <= Member_num) //대원들 같이 투입가능.
			Area_connect[MID_ROW][Loop2] = true;
		else Area_connect[MID_ROW][Loop2] = false;
	}
	//convert data end.
	//delete connect.
	while (true) {
		for (Loop2 = 0; Loop2 < Area_num; Loop2++) {
			if (Connect_delete(HIGH_ROW, (unsigned)Loop2) == 1) {
				Answer--;
			}
			if (Connect_delete(LOW_ROW, (unsigned)Loop2) == 1) {
				Answer--;
			}
			if (Connect_delete(MID_ROW, Right((unsigned)Loop2)) == 1) {
				Answer--;
			}
		}
		for (Loop2 = Area_num - 1; Loop2 >= 0; Loop2--) {
			if (Connect_delete(HIGH_ROW, (unsigned)Loop2) == 1) {
				Answer--;
			}
			if (Connect_delete(LOW_ROW, (unsigned)Loop2) == 1) {
				Answer--;
			}
			if (Connect_delete(MID_ROW, (unsigned)Loop2) == 1) {
				Answer--;
			}
		}
		//모든 연결이 사라졌는지 점검.
		Temp1 = 1;
		for (Loop1 = 0; Loop1 < 3; Loop1++) {
			for (Loop2 = 0; Loop2 < Area_num; Loop2++) {
				if (Area_connect[Loop1][Loop2]) {
					Connect_delete(Loop1, Loop2, true);
					Answer--; Temp1 = 0; Loop1 = 3, Loop2 = Area_num;
				}
			}
		}
		if (Temp1) { break; }
	}
	cout << Answer << endl;
}
unsigned Connect_delete(unsigned Loop1, unsigned Loop2, bool Force_delete) {
	unsigned UL, UR, DL, DR;
	if (Area_connect[Loop1][Loop2] == false) {
		return 0;//에초에 연결이 없어 지우지 못함.
	}
	else {
		switch (Loop1) {
		case HIGH_ROW:
			UL = (Area_connect[HIGH_ROW][Left(Loop2)]) ? 1 : 0;//왼쪽.
			UR = (Area_connect[HIGH_ROW][Right(Loop2)]) ? 1 : 0;//오른쪽.
			DL = (Area_connect[MID_ROW][Loop2]) ? 1 : 0;//왼쪽아래.
			DR = (Area_connect[MID_ROW][Right(Loop2)]) ? 1 : 0;//오른쪽아래.
			switch (UL + UR + DL + DR) {
			case 0:
			case 1://연결 손실이 0,1개이므로 지움.
				Area_connect[HIGH_ROW][Loop2] = false;
				Area_connect[HIGH_ROW][Left(Loop2)] = false;
				Area_connect[HIGH_ROW][Right(Loop2)] = false;
				Area_connect[MID_ROW][Loop2] = false;
				Area_connect[MID_ROW][Right(Loop2)] = false;
				return 1;
			case 2:
				if (UL + DL == 2) {
					Area_connect[HIGH_ROW][Loop2] = false;
					Area_connect[HIGH_ROW][Left(Loop2)] = false;
					Area_connect[MID_ROW][Loop2] = false;
					return 1;//지움
				}
				else if (UR + DR == 2) {
					Area_connect[HIGH_ROW][Loop2] = false;
					Area_connect[HIGH_ROW][Right(Loop2)] = false;
					Area_connect[MID_ROW][Right(Loop2)] = false;
					return 1;//지움.
				}
			default: return 2;//연결 손실이 너무 많아 지울수 없음.
			}
		case MID_ROW:
			UL = (Area_connect[HIGH_ROW][Left(Loop2)]) ? 1 : 0;//왼쪽위.
			UR = (Area_connect[HIGH_ROW][Loop2]) ? 1 : 0;//오른쪽위.
			DL = (Area_connect[LOW_ROW][Left(Loop2)]) ? 1 : 0;//왼쪽아래.
			DR = (Area_connect[LOW_ROW][Loop2]) ? 1 : 0;//오른쪽아래.
			switch (UL + UR + DL + DR) {
			case 0:
			case 1://연결 손실이 0,1개이므로 지움.
				Area_connect[MID_ROW][Loop2] = false;
				Area_connect[HIGH_ROW][Left(Loop2)] = false;
				Area_connect[HIGH_ROW][Loop2] = false;
				Area_connect[LOW_ROW][Left(Loop2)] = false;
				Area_connect[LOW_ROW][Loop2] = false;
				return 1;
			case 2:
				if (UL + UR == 2) {
					Area_connect[MID_ROW][Loop2] = false;
					Area_connect[HIGH_ROW][Left(Loop2)] = false;
					Area_connect[HIGH_ROW][Loop2] = false;
					return 1;
				}
				if (DL + DR == 2) {
					Area_connect[MID_ROW][Loop2] = false;
					Area_connect[LOW_ROW][Left(Loop2)] = false;
					Area_connect[LOW_ROW][Loop2] = false;
					return 1;
				}
			default: return 2;//연결 손실이 너무 많아 지울수 없음.
			}
		case LOW_ROW:
			UL = (Area_connect[LOW_ROW][Left(Loop2)]) ? 1 : 0;//왼쪽.
			UR = (Area_connect[LOW_ROW][Right(Loop2)]) ? 1 : 0;//오른쪽.
			DL = (Area_connect[MID_ROW][Loop2]) ? 1 : 0;//왼쪽아래.
			DR = (Area_connect[MID_ROW][Right(Loop2)]) ? 1 : 0;//오른쪽아래.
			switch (UL + UR + DL + DR) {
			case 0:
			case 1://연결 손실이 0,1개이므로 지움.
				Area_connect[LOW_ROW][Loop2] = false;
				Area_connect[LOW_ROW][Left(Loop2)] = false;
				Area_connect[LOW_ROW][Right(Loop2)] = false;
				Area_connect[MID_ROW][Loop2] = false;
				Area_connect[MID_ROW][Right(Loop2)] = false;
				return 1;
			case 2:
				if (UL + DL == 2) {
					Area_connect[LOW_ROW][Loop2] = false;
					Area_connect[LOW_ROW][Left(Loop2)] = false;
					Area_connect[MID_ROW][Loop2] = false;
					return 1;//지움
				}
				else if (UR + DR == 2) {
					Area_connect[LOW_ROW][Loop2] = false;
					Area_connect[LOW_ROW][Right(Loop2)] = false;
					Area_connect[MID_ROW][Right(Loop2)] = false;
					return 1;//지움.
				}
			default: return 2;//연결 손실이 너무 많아 지울수 없음.
			}
		}
	}
}
unsigned Right(unsigned Input) {
	return (Input != Area_num - 1) ? (Input + 1) : (0);
}
unsigned Left(unsigned Input) {
	return (Input) ? (Input - 1) : (Area_num - 1);
}
//verge
