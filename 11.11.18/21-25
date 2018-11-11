#include "pch.h"
#include <iostream>
using namespace std;

struct Date { int year; int month; int day; };

int absDate(Date x) { // абсолютное количество дней от РХ до заданной даты
	int i, valX, prevYear;
	int dayOfMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	if ((x.year % 4 == 0) and ((x.year % 100 != 0) or (x.year % 400 == 0))) { dayOfMonth[2]=29;} // если для заданной даты это високосный год
	prevYear = x.year - 1;
	valX = 365 * prevYear + (prevYear / 4) - (prevYear / 100) + (prevYear / 400); // количество дней до начала года
	for (i = 0; i < x.month; i++) { valX = valX + dayOfMonth[i]; } // наращиваем число дней до начала месяца
	valX = valX + x.day;
	return valX;
}

Date absDateToDate(int x) { // функция обратная absDate - возвращает дату по числу дней от РХ
	int n, raznDay, upDayYear, valX, tekYear, dayInTekYear;
	Date varDate, resu;
	int dayOfMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	tekYear = 1;
	while (true) { // считаем нарастающим по годам число прошедших дней
		varDate.year = tekYear;
		varDate.month = 1;
		varDate.day = 1;
		valX = absDate(varDate);
		if ((tekYear % 4 == 0) and ((tekYear % 100 != 0) or (tekYear % 400 == 0))) { 
			dayInTekYear = 366; // это високосный год
			dayOfMonth[2] = 29;
		} 
		else { 
			dayInTekYear = 365; 
			dayOfMonth[2] = 28;
		}
		raznDay = x - valX;
		if (raznDay >= dayInTekYear) { // дата не в текущем году (учитываем что отсчет не от 0 а от 1 числа года)
			tekYear = tekYear + 1; 
		}
		else if (raznDay == 0) { // начало текущего года
			resu = varDate;
			break;
		}
		else { // дата в текущем году, пробегаем по массиву дней в году чтоб найти месяц и день
			raznDay = raznDay + 1; // добавляем 1 число года чтоб отсчет шел от 0
			upDayYear = 0;
			for (n = 1; n <= 12; n++) {
				upDayYear = upDayYear + dayOfMonth[n - 1];
				if ((raznDay - upDayYear) <= dayOfMonth[n]) {
					varDate.month = n;
					varDate.day = raznDay - upDayYear;
					resu = varDate;
					break;
				}
			}
			break; // прерываем while
		}
	}

	return resu;
}

int dayOfWeekChrist(Date x) { // день недели (мы то знаем что Христос родился в воскресенье!!! - не зря у ангосаксов неделя начинается в воскресенье)
	return absDate(x)%7;
}

int dayToNewYear(Date x)
{	
	Date newYear;
	int aDat1, aDat2, valX;
	
	aDat1 = absDate(x);
	newYear.day = 1;
	newYear.month = 1;
	newYear.year = x.year + 1;
	aDat2 = absDate(newYear);

	valX =aDat2 - aDat1;

	return valX;
}

int operator- (Date dateTo,Date dateFrom) {  // перегрузка оператора - для структуры Date
	return absDate(dateTo) - absDate(dateFrom);
}

Date operator+ (Date dateFrom, int plusDay) {  // перегрузка оператора + для структуры Date
	int valX;
	valX = absDate(dateFrom) + plusDay;
	return absDateToDate(valX);
}

Date nextPalindromDate(Date x) { // дата-палиндром
	int zifra[8];
	int i, n;
	Date valX;

	n = absDate(x);
	while (true) {
		n = n+1;
		for (i = 0; i < 8; i++) { zifra[i] = 0; }
		valX = absDateToDate(n);
		zifra[0] = valX.day / 10;
		zifra[1] = valX.day % 10;
		zifra[2] = valX.month / 10;
		zifra[3] = valX.month % 10;
		zifra[4] = valX.year / 1000;
		zifra[5] = (valX.year / 100) - 10*zifra[4];
		zifra[6] = valX.year % 100;
		zifra[6] = zifra[6] / 10;
		zifra[7] = valX.year % 10;
		if ((zifra[0] == zifra[7]) and (zifra[1] == zifra[6]) and (zifra[2] == zifra[5]) and (zifra[3] == zifra[4])) { // это палиндром
			break;
		}
	}

	return valX;
}



void mainNoAnswer()
{
	cout << endl;
	cout << "Увы... Нет такой задачи.";
}

void main21()
{	/* 21) Для структуры Date напишите метод, выписывающий наименование дня недели по дате.*/
	Date tekDate;
	int tekDay;
	cout << "Введите день месяц год для даты:" <<endl;
	cin >> tekDate.day >> tekDate.month >> tekDate.year;

	tekDay = dayOfWeekChrist(tekDate);
	cout << "День недели: ";

	switch (tekDay) {
		case 0: {cout << "Воскресенье"; }
		case 1: {cout << "Понедельник"; }
		case 2: {cout << "Вторник"; }
		case 3: {cout << "Среда"; }
		case 4: {cout << "Четверг"; }
		case 5: {cout << "Пятница"; }
		case 6: {cout << "Суббота"; }
	}
	cout << endl;
}

void main22()
{	/* 22) Для структуры Date напишите метод, определяющий, сколько дней осталось до Нового Года.*/
	Date tekDate;

	cout << "Введите день месяц год для даты:" << endl;
	cin >> tekDate.day >> tekDate.month >> tekDate.year;

	cout << endl << "До Нового года осталось (дней): " << dayToNewYear(tekDate) << endl;
}

void main23()
{	/* 23) Для структуры Date напишите оператор минус возвращающий, количество дней прошедших между датами.*/
	Date date2,date1;

	cout << "Введите день месяц год для Даты_1:" << endl;
	cin >> date1.day >> date1.month >> date1.year;

	cout << endl << "Введите день месяц год для Даты_2:" << endl;
	cin >> date2.day >> date2.month >> date2.year;

	cout << endl << "Разность между Дата_2 и Дата_1 (дней): " << (date2-date1) << endl;
}

void main24()
{	/* 24) Для структуры Date напишите оператор плюс, принимающий целое число дней и возвращающий дату, отстоящую на это количество дней.*/
	Date date1,date2;
	int plusD;

	cout << "Введите день месяц год для Даты:" << endl;
	cin >> date1.day >> date1.month >> date1.year;

	cout << endl << "Введите число дней плюсом:" << endl;
	cin >> plusD;

	date2 = date1 + plusD;
	cout << endl << "Новая дата: " << date2.day << "." << date2.month << "." << date2.year << endl;
}

void main25()
{	/* 25) Для структуры Date напишите метод, находящий следующую дату-палиндром.*/
	Date date1, date2;
	char vv[8];
	int i;
	int zf[8];

	cout << "Введите день месяц год для Даты:" << endl;
	cin >> date1.day >> date1.month >> date1.year;

	date2 = nextPalindromDate(date1);

	zf[0] = date2.day / 10;
	zf[1] = date2.day % 10;
	zf[2] = date2.month / 10;
	zf[3] = date2.month % 10;
	zf[4] = date2.year / 1000;
	zf[5] = (date2.year / 100) - 10 * zf[4];
	zf[6] = date2.year % 100;
	zf[6] = zf[6] / 10;
	zf[7] = date2.year % 10;

	for (i = 0; i < 8; i++) { vv[i] = '0' + zf[i]; }

	cout << endl << "Следующая дата-палиндром: " << vv[0] << vv[1] << "." << vv[2] << vv[3] << "." << vv[4] << vv[5] << vv[6] << vv[7] << endl;
}

int main()
{
	int zadanie;
	bool ziklZadach = true;
	setlocale(LC_ALL, "Rus"); // русифицируем вывод
	while (ziklZadach) {
		cout << endl << "ИНФО: сделаны задачи 21-25 (5 штук)" << endl;
		cout << endl << "Введите номер задачи (911 - для выхода из цикла выбора задач):" << endl;
		cin >> zadanie;

		switch (zadanie)
		{
		case 21:
		{
			cout << "Для структуры Date напишите метод, выписывающий наименование дня недели по дате." << endl << endl;
			main21(); break; }
		case 22:
		{
			cout << "Для структуры Date напишите метод, определяющий, сколько дней осталось до Нового Года." << endl << endl;
			main22(); break; }
		case 23:
		{
			cout << "Для структуры Date напишите оператор минус возвращающий, количество дней прошедших между датами." << endl << endl;
			main23(); break; }
		case 24:
		{
			cout << "Для структуры Date напишите оператор плюс, принимающий целое число дней и возвращающий дату, отстоящую на это количество дней." << endl << endl;
			main24(); break; }
		case 25:
		{
			cout << "Для структуры Date напишите метод, находящий следующую дату-палиндром." << endl << endl;
			main25(); break; }
		case 911:
		{
			ziklZadach = false;
			break; }
		default:
			mainNoAnswer();
		}
		cout << endl << "///" << endl;
	}

	//	system("pause");

	return 0;
}
