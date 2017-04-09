#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//PAEKJOON online judge Problem1012.
//문제.

//system("mode con cols=80 lines=25");
//system("color f0");
//mecro
#define NUM_100 100
#define NUM_1000 1000
#define NUM_10000 10000
#define NUM_100000 100000
#define NUM_1000000 1000000
#define SIZE 50

//type, class
struct Coord {
	unsigned x, y;
};
enum T_direction {
	U, R, D, L
};

//variable
//cabbage[y좌표][x좌표] = 배추가 존재하는가?(T/F).
bool cabbage[SIZE][SIZE];
unsigned xSize, ySize;
//find[find_snum - 1] = 현재 찾은 배추의 번호.
Coord find[SIZE * SIZE];
unsigned find_snum;
//function
void input();
void output();
Coord& lastFind() { return find[find_snum - 1]; }
void moveCoord(Coord & input, T_direction way);

//main
int main(int arg_num, char * argv[], char * env[]) {
	unsigned test_case, loop1;
	cin >> test_case;
	for (loop1 = 0; loop1 < test_case; loop1++) {//각각의 테스트 케이스에 대해.
		input();//입력 구문.
		output();//출력 구문.
	}

	return 0;
}

//function define
void input() {
	unsigned vnum, x, y;
	cin >> xSize >> ySize >> vnum;
	for (unsigned loop1 = 0; loop1 < ySize; loop1++) {
		for (unsigned loop2 = 0; loop2 < ySize; loop2++) {
			cabbage[loop1][loop2] = false;
		}
	}
	for (unsigned loop1 = 0; loop1 < vnum; loop1++) {
		cin >> x >> y;
		cabbage[y][x] = true;
	}
}
void output() {
	//cabbage[y좌표][x좌표] = 배추가 존재하는가?(T/F).
	//xSize, ySize.
	//find[find_snum - 1] = 현재 찾은 배추의 번호.
	//find_snum
	unsigned loop1, loop2, answer = 0;
	Coord lastcabbage;
	Coord nextcabbage;
	for (loop1 = 0; loop1 < ySize; loop1++) {
		for (loop2 = 0; loop2 < xSize; loop2++) {
			if (cabbage[loop1][loop2]) {//배추가 존재하는 경우. 인접 지점 탐사를 시작함.
				//인접 배추 탐사 시작.
				find_snum = 1;
				find[0].y = loop1, find[0].x = loop2;
				while (find_snum) {//모든 배추를 다 찾을 때까지.
					nextcabbage = lastcabbage = lastFind();
					cabbage[lastcabbage.y][lastcabbage.x] = false;//현재배추 찾음처리.
					//인접 배추 탐사.
					moveCoord(nextcabbage, D);
					if (cabbage[nextcabbage.y][nextcabbage.x]) {
						find[find_snum++] = nextcabbage; continue;
					}
					nextcabbage = lastcabbage;
					moveCoord(nextcabbage, U);
					if (cabbage[nextcabbage.y][nextcabbage.x]) {
						find[find_snum++] = nextcabbage; continue;
					}
					nextcabbage = lastcabbage;
					moveCoord(nextcabbage, R);
					if (cabbage[nextcabbage.y][nextcabbage.x]) {
						find[find_snum++] = nextcabbage; continue;
					}
					nextcabbage = lastcabbage;
					moveCoord(nextcabbage, L);
					if (cabbage[nextcabbage.y][nextcabbage.x]) {
						find[find_snum++] = nextcabbage; continue;
					}
					find_snum--;//인접 배추가 아무것도 없는 경우.
				}
				//인접 배추 탐사 끝.
				answer++;
			}
		}
	}
	cout << answer << endl;
}
void moveCoord(Coord & input, T_direction way) {
	switch(way) {
	case D:
		(input.y < ySize - 1) ? input.y++ : 0;
		break;
	case U:
		(input.y > 0U) ? input.y-- : 0;
		break;
	case R:
		(input.x < xSize - 1) ? input.x++ : 0;
		break;
	case L:
		(input.x > 0U) ? input.x-- : 0;
		break;
	}
}