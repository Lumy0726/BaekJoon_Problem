#include <iostream>
#include <vector>
#include <assert.h>
using std::cout;
using std::cin;
using std::endl;
using std::vector;

//PAEKJOON online judge Problem1005.
//����.

//mecro
#define INPUTOUTPUT_SETTING 0//0�̸� ���� �Է¹ް� ���, 1�̸� �Ѳ����� �Է¹ް� ���

//type, class
struct C_pair_unsigned {
	unsigned Value1, Value2;
	C_pair_unsigned() :Value1(0), Value2(0){; }
	C_pair_unsigned(unsigned V1, unsigned V2) :Value1(V1), Value2(V2) { ; }
};
struct C_problem {
	unsigned Win_tower_num;//�¸��Ҽ� �ִ� �ǹ���ȣ.
	vector<unsigned> Tower_time;//�ǹ��� ���µ� �ɸ��� �ð�.
	vector<C_pair_unsigned> Tower_rule;//�ǹ� �Ǽ� ��Ģ.
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
	for (Loop1 = 0; Loop1 < Test_case; Loop1++) {//������ �׽�Ʈ ���̽��� ����.
		Problem.Input();//�Է� ����.
		Problem.Ouput();//��� ����.
	}
#else
	C_problem *Problem;
	cin >> Test_case;
	Problem = new C_problem[Test_case];
	for (Loop1 = 0; Loop1 < Test_case; Loop1++) {//������ �׽�Ʈ ���̽��� ����.
		Problem[Loop1].Input();//�Է� ����.
	}
	for (Loop1 = 0; Loop1 < Test_case; Loop1++) {//������ �׽�Ʈ ���̽��� ����.
		Problem[Loop1].Ouput();//��� ����.
	}
	delete[] Problem;
#endif

	return 0;
}

//function define
void C_problem::Input() {
	unsigned Input1, Input2, Loop1;
	unsigned Tower_num, Rule_num;

	//���� ���� ����.
	Tower_time.clear(), Tower_rule.clear();
	cin >> Tower_num >> Rule_num;
	//�ǹ��Ǽ��ð� �Է�.
	for (Loop1 = 0; Loop1 < Tower_num; Loop1++) {
		cin >> Input1;
		Tower_time.push_back(Input1);
	}
	//�ǹ��Ǽ���Ģ �Է�.
	for (Loop1 = 0; Loop1 < Rule_num; Loop1++) {
		cin >> Input1 >> Input2;
		Tower_rule.push_back(C_pair_unsigned(Input1 - 1, Input2 - 1));//0���� �����ϴ� �ǹ���ȣ�� ����.
	}
	cin >> Win_tower_num;//�¸��� ���� �ǹ���ȣ �Է�.
	Win_tower_num--;//0���� �����ϴ� �ǹ���ȣ�� ����.
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

	//�ǹ���Ģ �ڷ� ��ȯ(Tower_rule --> Tower_connetor).
	for (Loop1 = 0; Loop1 < Tower_rule.size(); Loop1++) {
		Tower_connetor[Tower_rule[Loop1].Value2].push_back(Tower_rule[Loop1].Value1);
	}

	//�ǹ� �Ǽ� ��θ� Ž��(���������� ����� �ϴ� �ǹ����� ����ȸ).
	Tower_route.push_back(C_tower_route(Win_tower_num, 0));
	Time = Tower_time[Win_tower_num];
	while (true) {//��� ��Ʈ�� ��ȸ�� ������.
		if (Tower_route.back().Tower_connetor_num < Tower_connetor[Tower_route.back().Tower_num].size()) {
			//�����ؼ� ����� �ϴ� �ǹ� Ž��.
			Tower_route.push_back(
				C_tower_route(Tower_connetor[Tower_route.back().Tower_num][Tower_route.back().Tower_connetor_num], 0)
			);
			Time += Tower_time[Tower_route.back().Tower_num];
		}
		else {
			//�����ؼ� ����� �ϴ� �ǹ� Ž�� ���� ���.
			(Time > Time_max) ? (Time_max = Time) : 0;//�ְ�ð� ���.
			Time -= Tower_time[Tower_route.back().Tower_num];//Time�ǵ�����.
			Tower_route.pop_back();//Tower_route�ǵ�����.
			if (Tower_route.empty()) {//Ÿ�� ��ȸ �Ϸ�.
				break;
			}
			Tower_route.back().Tower_connetor_num++;//�ٸ� Ÿ���� ��ȸ�ϵ��� ��.
		}
	}
	cout << Time_max << endl;
}
//verge
