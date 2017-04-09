// 2017104008.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <cmath>
#include <windows.h>
#include <assert.h>
using namespace std;

unsigned gcd(unsigned a, unsigned b) {
	if (b == 0) {
		assert(("Division with 0.", false)); return 1;
	}
	if (a == 0) {
		return b;
	}
	else if (((a>b) ? a : b) % ((a>b) ? b : a) == 0) {
		return ((a>b) ? b : a);
	}
	else {
		return gcd(((a>b) ? b : a), ((a>b) ? a : b) % ((a>b) ? b : a));
	}
}
unsigned lcm(unsigned a, unsigned b) {
	return a * b / gcd(a, b);
}

int main() {
	//Program start.
	unsigned input1;
	cout << "숫자 입력: "; cin >> input1;
	for (int loop1 = 0; loop1 < input1; loop1++) {
		for (int loop2 = 0; loop2 < input1; loop2++) {
			if (loop2 < input1 - loop1 - 1) { cout << ' '; }
			else { cout << '*'; }
		}
		cout << endl;
	}
	return 0;
}