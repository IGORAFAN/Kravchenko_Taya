#pragma once

#include <iostream> 
#include <iomanip>
#include <conio.h>
#include <cmath>

using namespace std;

class Data {
private:
	//���������� ��� ��������
	int seconds;
	int minutes;
	int hours;
	int sumSecObj; //����� ������ �� ������� ��������� �������
	char simbol; // ���������� ��� ����������� �������
public:
	//����������� �� ���������
	Data();
	//���������� �� ���������
	~Data();
	//����� ���������� ������ � ���������

	void set_Data();
	//����� ��� ����������� �������� � ������ 
	void what_Do_You_Want(Data arg_obj1, Data arg_obj2, int & arg_secCountAfterOper);
	//����� ����������� ���� � ��� � ������ ���������� �����
	int konver_Time_to_Sec(Data arg_obj);
	//����� ����������� ����
	void plus_Sec(int arg_sumSecObj1, int arg_sumSecObj2, int & arg_secCountAfterOper);
	//����� ��������� ����
	void minus_Sec(int arg_sumSecObj1, int arg_sumSecObj2, int & arg_secCountAfterOper);
	//���������� ���� �� ���� 
	void Data_To_Result(Data arg_obj1, Data arg_obj2, int & arg_res_sec, int & arg_res_minutes, int & arg_res_hours, int & arg_res_day);
	//����� ������ ���������� ����
	void get_Result(int arg_secCountAfterOper, int arg_res_sec, int arg_res_minutes, int arg_res_hours, int arg_res_day);
};