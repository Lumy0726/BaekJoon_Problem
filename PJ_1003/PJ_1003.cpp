#include <iostream>
#include <assert.h>
using std::cout;
using std::cin;
using std::endl;

//PAEKJOON online judge Problem1003.
//a(0)=0, a(1)=1;
//a(n)=a(n - 1) + a(n - 2);단, n>=2인 정수.
//a(n)은 몇개의 a(0)과 a(1)으로 이루어져 있는가?--->B(n)이라 두자. (이 값은 정수 2개이다, Coord타입).
//이때 B(n) = B(n - 1) + B(n - 2)가 성립하므로, 이를 이용하여 문제를 해결한다.

//mecro

//type, class
class Coord {
public:
	int a0, a1;
	Coord(int _a0, int _a1) : a0(_a0), a1(_a1) { ; }
	Coord operator+(const Coord &Input) const{
		return Coord(a0 + Input.a0, a1 + Input.a1);
	}
	Coord operator-(const Coord &Input) const{
		return Coord(a0 - Input.a0, a1 - Input.a1);
	}
};
//variable

//function
void Sol(unsigned Input);
//main
int main(int arg_num, char * argv[], char * env[]) {
	unsigned Test_case;
	int Loop1;
	unsigned *Num;
	cin >> Test_case;
	Num = new unsigned[Test_case];
	for (Loop1 = 0; Loop1 < (int)Test_case; Loop1++) {
		cin >> Num[Loop1];
	}
	for (Loop1 = 0; Loop1 < (int)Test_case; Loop1++){
		Sol(Num[Loop1]);
	}

	delete[] Num;
	return 0;
}

//function define
void Sol(unsigned Input) {
	int Loop1;
	Coord Value1(1,0), Value2(0,1);//B(0)과 B(1)의 초기값.
	//B(0) = (1,0)
	//B(1) = (0,1)
	//B(2) = (1,1)
	//B(3) = (1,2)......
	for (Loop1 = 0; Loop1 < (int)Input; Loop1++) {
		//B(n),B(n+1)을 B(n+1),B(n+2)로 변환하는 코드.
		Value2 = Value2 + Value1;
		Value1 = Value2 - Value1;
	}
	cout << Value1.a0 << ' ' << Value1.a1 << endl;
}
//verge
