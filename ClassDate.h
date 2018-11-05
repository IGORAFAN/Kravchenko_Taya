#pragma once

#include <iostream> 
#include <iomanip>
#include <conio.h>
#include <cmath>

using namespace std;

class Data {
private:
	//переменные для обьектов
	int seconds;
	int minutes;
	int hours;
	int sumSecObj; //сумма секунд из каждого введеного времени
	char simbol; // переменная для получаемого символа
public:
	//Конструктор по умолчанию
	Data();
	//Деструктор по умолчанию
	~Data();
	//метод считывания данных с проверкой

	void set_Data();
	//метод для опредиления операции с датами 
	void what_Do_You_Want(Data arg_obj1, Data arg_obj2, int & arg_secCountAfterOper);
	//метод Конвертации дату в дни с учётом высокосных годов
	int konver_Time_to_Sec(Data arg_obj);
	//метод прибавления даты
	void plus_Sec(int arg_sumSecObj1, int arg_sumSecObj2, int & arg_secCountAfterOper);
	//метод отнимания даты
	void minus_Sec(int arg_sumSecObj1, int arg_sumSecObj2, int & arg_secCountAfterOper);
	//выщитывает дату из дней 
	void Data_To_Result(Data arg_obj1, Data arg_obj2, int & arg_res_sec, int & arg_res_minutes, int & arg_res_hours, int & arg_res_day);
	//метод Вывода результата Дней
	void get_Result(int arg_secCountAfterOper, int arg_res_sec, int arg_res_minutes, int arg_res_hours, int arg_res_day);
};