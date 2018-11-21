
/*
3)	Напишите переборную программу программу, вычисляющую значение функции Эйлера для числа n. Программа должна работать не более чем за O(n* log n) шагов.
*/

#include "pch.h"
#include <iostream>
using namespace std;


int arrSimpleDiv(int X, int *mArr) {
	// функция возвращает количество уникальных делителей и заполняет массив делителей
	int kDiv=0; // число делителей
	int i, tDiv, valX;
	if (X < 0) { X = -X; }
	valX = X;
	tDiv = 1;
	i = 2;
	while (valX > 1) {
		if (valX%i == 0) { // разделилось нацело - проверим это новый делитель или повторение предыдущего
			if (i > tDiv) {
				kDiv++; // наращиваем счетчик делителей
				tDiv = i; // новый уникальный делитель
				mArr[kDiv - 1] = tDiv;
			}
			valX = valX / i;
		}
		else { // проверяем следующее число на делитель
			i++;
		}
	}

	return kDiv;
}



int main()
{
	int varX, i, i1, i2, cntDivI, cntDivT, eler;
	// резервируем массив по делители числа - их число для типа int не превышает 32, т.к. максимальное число разложений на множители - 32 (2 -минимальный делитель, 32 разрядное число) 
	int *ptrIsx = new int[32]; // указатель на массив делителей исходного числа
	int *ptrTek = new int[32]; // массив делителей переменной
	bool naiden;

	setlocale(LC_ALL, "Rus"); // русифицируем вывод

	eler = 1;
	cout << endl << "Введите число для которого нужно найти функцию Эйлера:"<< endl;
	cin >> varX;

	cntDivI = arrSimpleDiv(varX, ptrIsx); // количество и делители исходного числа

	for (i = 2; i < varX; i++) { // цикл по всем числам, меньше заданного
		cntDivT = arrSimpleDiv(i, ptrTek); // количество и делители текущего числа
		// теперь сравним массивы делителей текущего и исходного числа
		naiden = false; 
		for (i1 = 0; i1 < cntDivT; i1++) { // цикл по делителям текущего числа
			for (i2 = 0; i2 < cntDivI; i2++) { // цикл по делителям исходного числа
				if (ptrTek[i1] == ptrIsx[i2]) { // совпали делители
					naiden = true;
					break;
				}
				if (naiden == true) { break; } // прерываем коли найден делитель
			}
		}
		if (naiden == false) { eler = eler + 1; }
	}

	cout << endl << "Функция Эйлера: " << eler << endl;

	delete[] ptrIsx; // удаляем из памяти массивы
	delete[] ptrTek;

    return 0; 
}

