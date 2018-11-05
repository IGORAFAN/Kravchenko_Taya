//���������� ������� ������
#pragma once //����������� ����������� �����
#include "ClassDate.h" // ����������� ������

			//����������� �� ���������
Data::Data() : seconds(0), minutes(0), hours(0) {
	set_Data();
}
//���������� �� ���������
Data::~Data() {}

//�����������
void Data::set_Data() {
	for (;;) {
		cin >> setw(2) >> hours; // ���� � ������������ � 2 �����
		cin.ignore(); // ������������� 1 �������
		if (cin.fail()) {
			cout << "�������� ����! ��������� ����..." << endl;
			cin.clear(); //������������ �����
			cin.ignore(cin.rdbuf() -> in_avail()); //��������� �����
		}
		else if (hours >= 24) {
			cout << "�������� ����! ��������� ����..." << endl;
			cin.clear(); //������������ �����
			cin.ignore(cin.rdbuf() -> in_avail()); //��������� �����
		}
		else break;
	}
	for (;;) {
		cin >> setw(2) >> minutes; // ���� � ������������ � 2 �����
		cin.ignore(); // ������������� 1 �������
		if (cin.fail()) {
			cout << "�������� ����! ��������� ����..." << endl;
			cin.clear(); //������������ �����
			cin.ignore(cin.rdbuf() -> in_avail()); //��������� �����
		}
		else if (minutes >= 60) {
			cout << "�������� ����! ��������� ����..." << endl;
			cin.clear(); //������������ �����
			cin.ignore(cin.rdbuf() -> in_avail()); //��������� �����
		}
		else break;
	}
	for (;;) {
		cin >> setw(2) >> seconds; // ���� � ������������ � 2 �����
		cin.ignore(); // ������������� 1 �������
		if (cin.fail()) {
			cout << "�������� ����! ��������� ����..." << endl;
			cin.clear(); //������������ �����
			cin.ignore(cin.rdbuf() -> in_avail()); //��������� �����
		}
		else if (seconds >= 60) {
			cout << "�������� ����! ��������� ����..." << endl;
			cin.clear(); //������������ �����
			cin.ignore(cin.rdbuf() -> in_avail()); //��������� �����
		}
		else break;
	}
}
//����� ��� ����������� �������� � ��������
void Data::what_Do_You_Want(Data arg_obj1, Data arg_obj2, int & arg_secCountAfterOper) {
	cout << "\n������� ��������� �������� '+' ��� '-'!: ";
	cin >> simbol; // ���� ������� ��� ����������� �������� � ������ 
	switch (simbol) {
	case '+': // ���� ���� �� ������ �������� ���������� � ����������� �������� ��������� ���� � ����
		plus_Sec(konver_Time_to_Sec(arg_obj1), konver_Time_to_Sec(arg_obj2), arg_secCountAfterOper);
		break;
	case '-': // ���� ����� �� ������ �������� ��������� � ����������� �������� ��������� ���� � ����
		minus_Sec(konver_Time_to_Sec(arg_obj1), konver_Time_to_Sec(arg_obj2), arg_secCountAfterOper);
		break;
	default:
		cout << "������ �� ���������� ���������! " << endl; // ��������������, ���������� �����
		cout << "���������� ���������! " << endl;
		what_Do_You_Want(arg_obj1, arg_obj2, arg_secCountAfterOper);
		break;
	}
}
//����� ����������� ���� � ��� � ������ ���������� �����
int Data::konver_Time_to_Sec(Data arg_obj) {
	arg_obj.sumSecObj = (arg_obj.hours * 3600) + (arg_obj.minutes * 60) + arg_obj.seconds; // ������� ������� � ����� ������
	return arg_obj.sumSecObj; //���������� �������� ��� ����� ����������
}
//����� ����������� ����
void Data::plus_Sec(int arg_sumSecObj1, int arg_sumSecObj2, int & arg_secCountAfterOper) {
	arg_secCountAfterOper = arg_sumSecObj2 + arg_sumSecObj1; // ����������� ���� ������
}

//����� ��������� �������
void Data::minus_Sec(int arg_sumSecObj1, int arg_sumSecObj2, int & arg_secCountAfterOper) {
	if (arg_sumSecObj1 > arg_sumSecObj2)
		arg_secCountAfterOper = arg_sumSecObj1 - arg_sumSecObj2;
	else
		arg_secCountAfterOper = arg_sumSecObj2 - arg_sumSecObj1; // ���������� ���������� ������
}
// ���������� ���� �� ������ �������� ��� ������ ���������� � �����,�������,��������
void Data::Data_To_Result(Data arg_obj1, Data arg_obj2, int & arg_res_seconds, int & arg_res_minutes, int & arg_res_hour, int & arg_res_day) {
	switch (simbol) {
	case '+':
		arg_res_seconds += (arg_obj1.seconds + arg_obj2.seconds);
		if (arg_res_seconds >= 60) {
			arg_res_minutes++;
			arg_res_seconds -= 60;
		}
		arg_res_minutes += (arg_obj1.minutes + arg_obj2.minutes);
		if (arg_res_minutes >= 60) {
			arg_res_hour++;
			arg_res_minutes -= 60;
		}
		arg_res_hour += (arg_obj1.hours + arg_obj2.hours);
		if (arg_res_hour >= 24) {
			arg_res_day++;
			arg_res_hour -= 24;
		};
		break;

	case '-':
			arg_res_seconds = abs(arg_obj1.seconds - arg_obj2.seconds);
			arg_res_minutes = abs(arg_obj1.minutes - arg_obj2.minutes);
			arg_res_hour	= abs(arg_obj1.hours - arg_obj2.hours);
		break;
	}
}
//����� ������ ���������� �������
void Data::get_Result(int arg_secCountAfterOper, int arg_res_seconds, int arg_res_minutes, int arg_res_hour, int arg_res_day) {
	switch (simbol) {
	case '+':
		cout << "\n����� �������:  Day::Hour:Min:Sec = " << arg_res_day << "::" << arg_res_hour << ":" << arg_res_minutes << ":" << arg_res_seconds;
		cout << " � ����� = " << arg_secCountAfterOper << " Sec" << endl;
		break;
	case '-':
		cout << "\n������� ������� Hour:Min:Sec = " << arg_res_hour << ":" << arg_res_minutes << ":" << arg_res_seconds;
		cout << " � ����� = " << arg_secCountAfterOper << " Sec" << endl;
		break;
	}
}