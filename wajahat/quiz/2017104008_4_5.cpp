// 2017104008.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int reverse(int number);
int quotient(int divider, int dividend);
int remainder(int divider, int dividend);
int multi(int number, int multi);

int main() {
	//Program start.
	int Input;
	cout << "Enter four digit number:\n";
	cin >> Input;
	cout <<"The reverse order of the four digit number "<<Input<<": "<< reverse(Input) << endl;
	return 0;
}

int reverse(int number) {
	int return_value = 0;
	return_value += quotient(number, 1000);
	return_value += multi(quotient(remainder(number, 1000), 100), 10);
	return_value += multi(quotient(remainder(number, 100), 10), 100);
	return_value += multi(remainder(number, 10), 1000);
	return return_value;
}
int quotient(int divider, int dividend) {
	return divider / dividend;
}
int remainder(int divider, int dividend) {
	return divider%dividend;
}
int multi(int number, int multi) {
	return number*multi;
}