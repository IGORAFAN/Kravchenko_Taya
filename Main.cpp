#include "ClassDate.h"

void prewiew() {
	cout << "����� ���������� � ���������\n";
	cout << "��� ����� ����������� ��������������� ����� ':' ��� '.' ��� ','\n";
}
int main() {
	setlocale(LC_ALL, "Russian");
	system("color 2");

	int secCountAfterOper(0);
	int res_sec(0), res_minutes(0), res_hours(0), res_day(0);

	prewiew(); //����� ������� ����������� ��������� ������������

	cout << "������� ������ ����� � ������� Hour:Min:Sec> ";
	Data obj1;

	cout << "������� ������ ����� � ������� Hour:Min:Sec> ";
	Data obj2;

	obj1.what_Do_You_Want(obj1, obj2, secCountAfterOper);
	obj1.Data_To_Result(obj1, obj2, res_sec, res_minutes, res_hours, res_day);
	obj1.get_Result(secCountAfterOper, res_sec, res_minutes, res_hours, res_day);

	_getch();
	return 0;
}