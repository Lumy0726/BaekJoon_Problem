#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//PAEKJOON online judge Problem1005.
//����.

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
unsigned Win_tower_num;//�¸��Ҽ� �ִ� �ǹ���ȣ.
//Tower_time[�ǹ���ȣ] = �ǹ��� ���µ� �ɸ��� �ð�.
unsigned Tower_time[MAX_TOWER_NUM];
unsigned Tower_time_snum;
//Tower_rule[�ǹ���ȣ] = �ǹ���Ģ
//�ǹ���Ģ.Value1--->�ǹ���Ģ.Value2.
C_pair_unsigned Tower_rule[MAX_TOWER_RULE];
unsigned Tower_rule_snum;
//Tower_route[����ǹ��� ã�ư� ��ȣ] = �ǹ���Ʈ����ü
//�ǹ���Ʈ����ü.Tower_num = ���� �ǹ���ȣ
//�ǹ���Ʈ����ü.Tower_connect_num = ���� ã�ư��� �� Tower_connector�� ��ȣ.
C_tower_route Tower_route[MAX_TOWER_RULE + 1];
unsigned Tower_route_snum;
//Tower_connector[�ǹ���ȣ][Tower_connector��ȣ]= ����ǹ���ȣ.
unsigned Tower_connector[MAX_TOWER_NUM][(MAX_TOWER_RULE * 5) / MAX_TOWER_NUM];
//Tower_connector_snum2[�ǹ���ȣ] = �� �ǹ� connector��ȣ���� ����.
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
	for (Loop1 = 0; Loop1 < Test_case; Loop1++) {//������ �׽�Ʈ ���̽��� ����.
		Input();//�Է� ����.
		Ouput();//��� ����.
	}
	return 0;
}

//function define
void Input() {
	unsigned Input1, Input2, Loop1;
	unsigned Tower_num, Rule_num;

	//���� ���� ����.
	Tower_time_snum = 0, Tower_rule_snum = 0;
	cin >> Tower_num >> Rule_num;
	//�ǹ��Ǽ��ð� �Է�.
	for (Loop1 = 0; Loop1 < Tower_num; Loop1++) {
		cin >> Input1;
		Tower_time[Tower_time_snum++]=Input1;
	}
	//�ǹ��Ǽ���Ģ �Է�.
	for (Loop1 = 0; Loop1 < Rule_num; Loop1++) {
		cin >> Input1 >> Input2;
		Tower_rule[Tower_rule_snum].Value1 = Input1 - 1;
		Tower_rule[Tower_rule_snum].Value2 = Input2 - 1;
		Tower_rule_snum++;
	}
	cin >> Win_tower_num;//�¸��� ���� �ǹ���ȣ �Է�.
	Win_tower_num--;//0���� �����ϴ� �ǹ���ȣ�� ����.
}
void Ouput() {
	unsigned Time_max;
	unsigned Loop1, Temp1;
	C_tower_route Temp_last_route;
	
	Tower_route_snum = 0;
	for (Loop1 = 0; Loop1 < Tower_time_snum; Loop1++) {
		Tower_connector_snum2[Loop1] = 0;
	}
	//�ǹ���Ģ �ڷ� ��ȯ(Tower_rule --> Tower_connector).
	for (Loop1 = 0; Loop1 < Tower_rule_snum; Loop1++) {
		Tower_connector[Tower_rule[Loop1].Value2][Tower_connector_snum2[Tower_rule[Loop1].Value2]++] = Tower_rule[Loop1].Value1;
	}

	//Tower_time[�ǹ���ȣ] =  �ð�.
	//Tower_rule[�ǹ���ȣ] = �ǹ���Ģ//�ǹ���Ģ.Value1--->�ǹ���Ģ.Value2.
	//Tower_route[����ǹ��� ã�ư� ��ȣ] = �ǹ���Ʈ����ü
	//�ǹ���Ʈ����ü.Tower_num = ���� �ǹ���ȣ
	//�ǹ���Ʈ����ü.Tower_connect_num = ���� ã�ư��� �� Tower_connector�� ��ȣ.
	//Tower_connector[�ǹ���ȣ][Tower_connector��ȣ]= ����ǹ���ȣ.
	//Tower_connector_snum[�ǹ���ȣ] = �� �ǹ��� ����ǹ��� ��.

	//�ǹ� �Ǽ� ��θ� Ž��(���������� ����� �ϴ� �ǹ����� ����ȸ).
	Tower_route[Tower_route_snum].Tower_num = Win_tower_num;
	Tower_route[Tower_route_snum].Tower_connector_num = 0;
	Tower_route_snum++;
	while (true) {//��� ��Ʈ�� ��ȸ�� ������.
		Temp_last_route = Last_tower_route();
		if (Temp_last_route.Tower_connector_num < Tower_connector_snum2[Temp_last_route.Tower_num]) {
			//Ž������ ���� �����ؼ� ����� �ϴ� �ǹ� ����.
			//�������� Tower_route�̵�.
			Tower_route[Tower_route_snum].Tower_num = Tower_connector[Temp_last_route.Tower_num][Temp_last_route.Tower_connector_num];
			Tower_route[Tower_route_snum].Tower_connector_num = 0;
			Tower_route_snum++;
		}
		else {
			//�����ؼ� ����� �ϴ� �ǹ� Ž�� ���� ���.
			Time_max = 0; Temp1 = Tower_connector_snum2[Temp_last_route.Tower_num];
			for (Loop1 = 0; Loop1 < Temp1; Loop1++) {//���� �ǹ����� ����ǹ��� ��  �Ǽ��ְ�ð� ����.
				if (Time_max < Tower_time[Tower_connector[Temp_last_route.Tower_num][Loop1]]) {
					Time_max = Tower_time[Tower_connector[Temp_last_route.Tower_num][Loop1]];
				}
			}
			Tower_time[Temp_last_route.Tower_num] += Time_max;
			Tower_connector_snum2[Temp_last_route.Tower_num] = 0;//���� �ǹ����� ���� �����ϰ� �ð��� �������Ƿ� ���̻� ����ǹ� �ʿ����.
			Tower_route_snum--;//Tower_route�ǵ�����.
			if (Tower_route_snum==0) {//Ÿ�� ��ȸ �Ϸ�.
				break;
			}
			Last_tower_route().Tower_connector_num++;//�ٸ� Ÿ���� ��ȸ�ϵ��� ��.
		}
	}
	cout << Tower_time[Win_tower_num] << endl;
}
//verge
