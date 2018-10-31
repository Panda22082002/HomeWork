// Сорри... Код один для всех задач, чтоб дважды не вставать. :-)

#include "pch.h"
#include <iostream>
using namespace std;

// Проверка на простое число
bool isSimple(int X) {
	bool Res = true;
	for (int i = 2; i < X; i++) {
		if (X%i == 0) {
			Res = false;
			break;
		}
	}
	return Res;
}

// Максимальный простой делитель
int maxSimple(int X) {
	int Res = 1;
	int valX = X;
	while (valX > 1) {
		for (int i = 2; i <= valX; i++) {
			if (valX % i == 0) {
				Res = i;
				valX = valX / i;
				break;
			}
		}
	}
	return Res;
}

// Число простых делителей (без делителя - само число)
int countDivider(int X) {
	int Res = 1;
	int valX = X;
	int cntDiv = 0;
	while (valX > 1) {
		for (int i = 2; i <= valX; i++) {
			if (valX % i == 0) {
				cntDiv = cntDiv + 1;
				Res = i;
				valX = valX / i;
				break;
			}
		}
	}
	if (Res == X) { cntDiv = cntDiv - 1; }
	return cntDiv;
}

// Проверка на четность
bool isEven(int X) {
	bool Res = false;
		if (X%2 == 0) {
			Res = true;
		}
	return Res;
}

// Сумма нечетных цифр числа
int sumNoEven(int X) {
	int vX = X;
	int zifra = 0;
	int resSum = 0;
	int noEvenZifra = 0;
	
	while (vX > 0) {
		zifra = vX % 10;
		noEvenZifra = zifra % 2;
		if (noEvenZifra > 0) {
			resSum = resSum + zifra;
		}
		vX = vX / 10;
	}
	return resSum;
}

// Произведение цифр числа по четности последней цифры
int multiDigit(int X) {
	int vX = X;
	int zifra = 0;
	int noEvenZifra = 0;
	int lastEven = (vX % 10) % 2;
	int multiEven = 1;
	int multiNoEven = 1;
	if (vX == 0) {
		multiEven = 0;
		multiNoEven = 0;
	}

	while (vX > 0) {
		zifra = vX % 10;
		noEvenZifra = zifra % 2;
		if (noEvenZifra > 0) {
			multiNoEven = multiNoEven * zifra;
		}
		else {
			multiEven = multiEven * zifra;
		}
		vX = vX / 10;
	}

	if (lastEven == 0) { return multiEven;}
	else { return multiNoEven;}
}

int workMassive04(int *ptrM,int maxN)
{
	int n;
	int sumRes = 0;
	for (n = 0; n < maxN; n++) {
		if (isSimple(ptrM[n])) {sumRes=sumRes+ ptrM[n];}
	}
	return sumRes;
}

int mainTest()
{
	int valX;
	setlocale(LC_ALL, "Rus"); // русифицируем вывод
	cout << "Введите число:" << endl;
	cin >> valX;
/*	if (isSimple(valX)==true) {
		cout << "Число - простое" << endl;
	}
	else {
		cout << "Число - составное" << endl;
	} 
*/
//	system("pause");
//	cout << "Сумма нечетных:" << sumNoEven(valX) << endl;
	cout << "Произведение цифр числа по четности последней цифры:" << multiDigit(valX) << endl;

	return 0;
}

void mainNoAnswer() 
{
	cout << endl;
	cout << "Увы... Задача не решена.";
}

void main04() // задача 4
/* 4) Напишите программу, находящую сумму простых элементов массива.*/
{
	int i,iMax;
	cout << "Введите количество элементов массива:" << endl;
	cin >> iMax;
	int *ptrArr = new int[iMax];
	for (i = 0; i < iMax; i++) { ptrArr[i] = 0; }
	cout << "Введите элементы массива (по 1 в строке):" << endl;
	for (i = 0; i < iMax; i++) { cin >> ptrArr[i]; }
	cout << "Конец ввода массива. Что занесли:";
	for (i = 0; i < iMax; i++) { cout << " " << ptrArr[i]; }
	cout << endl;
	cout << endl;

	cout << "Сумма простых чисел массива: " << workMassive04(ptrArr,iMax) <<endl;

	delete [] ptrArr;
}

void main05() // задача 5
/* 5) Напишите программу, заменяющую составные числа на их самые большие простые делители.*/
{
	int valX;
	cout << "Введите число:" << endl;
	cin >> valX;
	cout << "Максимальный простой делитель:" << maxSimple(valX) << endl;
}

void main06() // задача 6
/* 6) Напишите программу, выписывающую все элементы последовательности, имеющие не менее пяти делителей*/
{
	int i, iMax, cntDvd;
	cout << "Введите количество элементов последовательности:" << endl;
	cin >> iMax;
	int *ptrArr = new int[iMax];
	for (i = 0; i < iMax; i++) { ptrArr[i] = 0; }
	cout << "Введите элементы последовательности (по 1 в строке):" << endl;
	for (i = 0; i < iMax; i++) { cin >> ptrArr[i]; }
	cout << "Конец ввода последовательности. Что занесли:";
	for (i = 0; i < iMax; i++) { cout << " " << ptrArr[i]; }
	cout << endl;
	cout << endl;
	cout << "Имеют не менее 5 делителей (не равных самому числу):" << endl;
	for (i = 0; i < iMax; i++) {
		cntDvd = countDivider(ptrArr[i]);
		if (cntDvd >= 5) {
			cout << ptrArr[i] <<" (" << cntDvd << ")" << endl;
		}
	}
	cout << endl;

	delete[] ptrArr;
}

void main07()  // задача 7
/* 7) Напишите программу, выписывающую все элементы последовательности, имеющие ровно семь делителей*/
{
	int i, iMax, cntDvd;
	cout << "Введите количество элементов последовательности:" << endl;
	cin >> iMax;
	int *ptrArr = new int[iMax];
	for (i = 0; i < iMax; i++) { ptrArr[i] = 0; }
	cout << "Введите элементы последовательности (по 1 в строке):" << endl;
	for (i = 0; i < iMax; i++) { cin >> ptrArr[i]; }
	cout << "Конец ввода последовательности. Что занесли:";
	for (i = 0; i < iMax; i++) { cout << " " << ptrArr[i]; }
	cout << endl;
	cout << endl;
	cout << "Имеют ровно 7 делителей (не равных самому числу):" << endl;
	for (i = 0; i < iMax; i++) {
		cntDvd = countDivider(ptrArr[i]);
		if (cntDvd == 7) {
			cout << ptrArr[i] << " (" << cntDvd << ")" << endl;
		}
	}
	cout << endl;

	delete[] ptrArr;
}

int main()
{
	int zadanie;
	setlocale(LC_ALL, "Rus"); // русифицируем вывод
	cout << "Введите номер задачи:" << endl;
	cin >> zadanie;

	switch(zadanie)
	{
	case 4:
		{ 
		cout << "Напишите программу, находящую сумму простых элементов массива." << endl << endl;
		main04(); break; }
	case 5:
	{
		cout << "Напишите программу, заменяющую составные числа на их самые большие простые делители." << endl << endl;
		main05(); break; }
	case 6:
	{
		cout << "Напишите программу, выписывающую все элементы последовательности, имеющие не менее пяти делителей." << endl << endl;
		main06(); break; }
	case 7:
	{
		cout << "Напишите программу, выписывающую все элементы последовательности, имеющие ровно семь делителей." << endl << endl;
		main07(); break; }
	default:
		mainNoAnswer();
	}
	cout << endl;
	
	system("pause");

	return 0;
}
