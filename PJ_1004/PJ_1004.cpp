#include <iostream>
#include <vector>
#include <assert.h>
using std::cout;
using std::cin;
using std::endl;
using std::vector;

//PAEKJOON online judge Problem1004.
//문제.

//mecro

//type, class
struct C_coord {
	int X, Y;
	C_coord() :X(0), Y(0) { ; }
	C_coord(int x, int y) :X(x), Y(y){ ; }
	C_coord operator+(const C_coord &Input)const;
	C_coord operator-(const C_coord &Input)const;
};
struct C_circle :public C_coord{
	unsigned Radius;
	C_circle() :Radius(0) { ; }
	C_circle(int x, int y, unsigned r) :C_coord(x,y), Radius(r) { ; }
	bool Dot_is_in(C_coord Dot) const;
};
struct C_prince_move {
	C_coord Start_dot, End_dot;
	vector<C_circle> Planet;
	C_prince_move();
	C_prince_move(C_coord Start, C_coord End, vector<C_circle> _Planet) :
		Start_dot(Start), End_dot(End), Planet(_Planet) { ; }
	unsigned Check_movenum()const;
};


//variable

//function
int Power(int Num, unsigned exp);

//main
int main(int arg_num, char * argv[], char * env[]) {
	unsigned Test_case, Loop1;
	vector<C_prince_move> Prince_move;
	cin >> Test_case;
	for (Loop1 = 0; Loop1 < Test_case; Loop1++) {//각각의 테스트 케이스에 대해 입력.
		Prince_move.push_back(C_prince_move());//입력 구문.
	}
	for (Loop1 = 0; Loop1 < Test_case; Loop1++) {//각각의 테스트 케이스에 대해 출력.
		cout << Prince_move.at(Loop1).Check_movenum() << endl;
	}
	return 0;
}

//function define
int Power(int Num, unsigned exp) {
	if (exp) {
		for (unsigned Loop1 = 1; Loop1 < exp; Loop1++) {
			Num *= Num;
		}
		return Num;
	}
	return 1;
}
C_coord C_coord::operator+(const C_coord &Input)const {
	return C_coord(X + Input.X, Y + Input.Y);
}
C_coord C_coord::operator-(const C_coord &Input)const {
	return C_coord(X - Input.X, Y - Input.Y);
}
bool C_circle::Dot_is_in(C_coord Dot) const {
	C_coord Temp = (*this - Dot);
	int Distance = Power(Temp.X, 2) + Power(Temp.Y, 2);//원의 중심과 들어온 좌표의 거리의 제곱.
	return Distance < Power(Radius, 2);//좌표가 원 안에 있는 경우 true리턴(경계선 제외).
}
C_prince_move::C_prince_move() {
	unsigned Planet_num, R_temp, Loop1;
	int X_temp, Y_temp;
	cin >> X_temp >> Y_temp;
	Start_dot = C_coord(X_temp, Y_temp);
	cin >> X_temp >> Y_temp;
	End_dot = C_coord(X_temp, Y_temp);
	cin >> Planet_num;
	for (Loop1 = 0; Loop1 < Planet_num; Loop1++) {//각각의 행성계를 입력받음.
		cin >> X_temp >> Y_temp >> R_temp;
		Planet.push_back(C_circle(X_temp, Y_temp, R_temp));
	}
}
unsigned C_prince_move::Check_movenum()const {
	vector<C_circle>::const_iterator One_planet;
	unsigned Movenum = 0;
	for (One_planet = Planet.begin(); One_planet != Planet.end(); One_planet++) {//각각의 행셩계에 대해 반복.
		if (One_planet->Dot_is_in(Start_dot) != One_planet->Dot_is_in(End_dot)) {
			Movenum++;
		}
	}
	return Movenum;
}

//verge
