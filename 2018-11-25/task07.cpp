
/* 7) Напишите эффективную функцию, выписывающую из массива длины n все элементы, у которых количество двоек в троичной записи меньше k.
Функция должна возвращать общее количество двоек в троичной записи всех чисел массива. В комментариях напишите, почему перебор - эффективный
*/
#include "pch.h"
#include <iostream>
using namespace std;

int findElement3(int *ptrN, int lenN, int k)
{	/*
	Почему эффективная - РАБОТАЕТ !!!.
	*/
	int i, j, cntZifr, valX, countZ, cnt222;

	int *ptrZ = new int[32]; // т.к. число int 32 разрядное, резервируем по максимуму для любой формы записи (2, 3, 8 и т.п.) 

	cnt222 = 0;
	for (i = 0; i < lenN; i++) { // цикл по элементам массива
		valX = ptrN[i];
		if (valX < 0) { valX = -valX; }
		cntZifr = 0;
		if (valX == 0) { // единственное исключение - когда изначально число равно 0
			cntZifr++;
			ptrZ[cntZifr - 1] = 0;
		}

		while (valX >= 1) { // разбиваем число на цифры
			cntZifr++;
			ptrZ[cntZifr - 1] = valX % 3;
			valX = valX / 3;
		}
		// теперь конкретно число двоек в записи числа
		countZ = 0;
		for (j = 0; j < cntZifr; j++) {
			if (ptrZ[j] == 2) {
				countZ++;
				cnt222++;
			}
		}
		// сравнение и вывод
		if (countZ < k) {
			cout << "Элемент " << i + 1 << " (" << ptrN[i] << " форма записи "; 
			for (j = 1; j <= cntZifr; j++) {
				cout << ptrZ[cntZifr - j]; // вывод в обратном порядке
			}
			cout << ") число двоек: " << countZ << endl;
		}
	}

	delete[] ptrZ;
	return cnt222;
}



int main()
{
	int i, lenNM, kM, all2;

	setlocale(LC_ALL, "Rus");

	cout << "Введите длину массива N и число K (количество двоек в троичной записи меньше его): " << endl;
	cin >> lenNM >> kM;
	if (lenNM < 1) { // прерываем если маленькая длина
		cout << "Некорректная длина массива. Стоп программа..." << endl;
		return 0;
	}

	int *ptrNM = new int[lenNM]; // массив чисел
	// интерактивный ввод элементов массива для проверки работоспособности
	for (i = 0; i < lenNM; i++) {
		cout << "Введите " << i + 1 << " число массива: ";
		cin >> ptrNM[i];
	}

	cout << endl;

	all2 = findElement3(ptrNM, lenNM, kM);

	cout << endl << "Всего 2 в троичной записи: " << all2 << endl;

	delete[] ptrNM;
	return 0;
}
