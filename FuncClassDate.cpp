//Реализация методов класса
#pragma once //одноразовое подключение файла
#include "ClassDate.h" // подключение класса

			//Конструктор по умолчанию
Data::Data() : seconds(0), minutes(0), hours(0) {
	set_Data();
}
//Деструктор по умолчанию
Data::~Data() {}

//Приветствие
void Data::set_Data() {
	for (;;) {
		cin >> setw(2) >> hours; // ввод с ограничением в 2 цыфры
		cin.ignore(); // игнорирование 1 символа
		if (cin.fail()) {
			cout << "Неверный ввод! Повторите Ввод..." << endl;
			cin.clear(); //Восстановили поток
			cin.ignore(cin.rdbuf() -> in_avail()); //Почистили поток
		}
		else if (hours >= 24) {
			cout << "Неверный ввод! Повторите Ввод..." << endl;
			cin.clear(); //Восстановили поток
			cin.ignore(cin.rdbuf() -> in_avail()); //Почистили поток
		}
		else break;
	}
	for (;;) {
		cin >> setw(2) >> minutes; // ввод с ограничением в 2 цыфры
		cin.ignore(); // игнорирование 1 символа
		if (cin.fail()) {
			cout << "Неверный ввод! Повторите Ввод..." << endl;
			cin.clear(); //Восстановили поток
			cin.ignore(cin.rdbuf() -> in_avail()); //Почистили поток
		}
		else if (minutes >= 60) {
			cout << "Неверный ввод! Повторите Ввод..." << endl;
			cin.clear(); //Восстановили поток
			cin.ignore(cin.rdbuf() -> in_avail()); //Почистили поток
		}
		else break;
	}
	for (;;) {
		cin >> setw(2) >> seconds; // ввод с ограничением в 2 цыфры
		cin.ignore(); // игнорирование 1 символа
		if (cin.fail()) {
			cout << "Неверный ввод! Повторите Ввод..." << endl;
			cin.clear(); //Восстановили поток
			cin.ignore(cin.rdbuf() -> in_avail()); //Почистили поток
		}
		else if (seconds >= 60) {
			cout << "Неверный ввод! Повторите Ввод..." << endl;
			cin.clear(); //Восстановили поток
			cin.ignore(cin.rdbuf() -> in_avail()); //Почистили поток
		}
		else break;
	}
}
//метод для определения операции с временем
void Data::what_Do_You_Want(Data arg_obj1, Data arg_obj2, int & arg_secCountAfterOper) {
	cout << "\nВведите операндум действия '+' или '-'!: ";
	cin >> simbol; // ввод символа для определения операции с датами 
	switch (simbol) {
	case '+': // если плюс то запуск операции плюсования с последующим запуском конвертёра даты в день
		plus_Sec(konver_Time_to_Sec(arg_obj1), konver_Time_to_Sec(arg_obj2), arg_secCountAfterOper);
		break;
	case '-': // если минус то запуск операции отнимания с последующим запуском конвертёра даты в день
		minus_Sec(konver_Time_to_Sec(arg_obj1), konver_Time_to_Sec(arg_obj2), arg_secCountAfterOper);
		break;
	default:
		cout << "Введен не корректный Операндум! " << endl; // предупреждение, перезапуск ввода
		cout << "Пожалуйста повторите! " << endl;
		what_Do_You_Want(arg_obj1, arg_obj2, arg_secCountAfterOper);
		break;
	}
}
//метод Конвертации дату в дни с учётом высокосных годов
int Data::konver_Time_to_Sec(Data arg_obj) {
	arg_obj.sumSecObj = (arg_obj.hours * 3600) + (arg_obj.minutes * 60) + arg_obj.seconds; // перевод времени в сумму секунд
	return arg_obj.sumSecObj; //возвращаем значение где метод вызывается
}
//метод прибавления даты
void Data::plus_Sec(int arg_sumSecObj1, int arg_sumSecObj2, int & arg_secCountAfterOper) {
	arg_secCountAfterOper = arg_sumSecObj2 + arg_sumSecObj1; // прибавление сумм секунд
}

//метод отнимания времени
void Data::minus_Sec(int arg_sumSecObj1, int arg_sumSecObj2, int & arg_secCountAfterOper) {
	if (arg_sumSecObj1 > arg_sumSecObj2)
		arg_secCountAfterOper = arg_sumSecObj1 - arg_sumSecObj2;
	else
		arg_secCountAfterOper = arg_sumSecObj2 - arg_sumSecObj1; // отбавление количества секунд
}
// Выщитываем дату из данных обьектов для вывода результата в часах,минутах,секундах
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
//метод Вывода результата Времени
void Data::get_Result(int arg_secCountAfterOper, int arg_res_seconds, int arg_res_minutes, int arg_res_hour, int arg_res_day) {
	switch (simbol) {
	case '+':
		cout << "\nСумма времени:  Day::Hour:Min:Sec = " << arg_res_day << "::" << arg_res_hour << ":" << arg_res_minutes << ":" << arg_res_seconds;
		cout << " В сумме = " << arg_secCountAfterOper << " Sec" << endl;
		break;
	case '-':
		cout << "\nРазница времени Hour:Min:Sec = " << arg_res_hour << ":" << arg_res_minutes << ":" << arg_res_seconds;
		cout << " В сумме = " << arg_secCountAfterOper << " Sec" << endl;
		break;
	}
}