// 5) Напишите эффективную процедуру, выписывающую из массива длины n все элементы, у которых произведение ненулевых цифр больше k. 
// В комментариях напишите, почему перебор - эффективный

#include "pch.h"
#include <iostream>
using namespace std;


void findElement(int *ptrN,int lenN, int k)
{	/*
	Почему эффективная - просто потому что работает. Другого объяснения нет.
	*/
	int i, j, cntZifr, cntElem, valX, multiZ;

	int *ptrZ = new int[10]; // т.к. число int не превышает 4 294 967 295 то резервируем массив под 10 цифр числа 

	cntElem = 0;
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
			ptrZ[cntZifr - 1] = valX % 10;
			valX = valX / 10;
		}
		// теперь конкретно перемножение цифр
		multiZ = 0;
		for (j = 0; j < cntZifr; j++) {
			if (ptrZ[j] > 0) {
				if (multiZ == 0) { // еще не было цифр отличных от 0
					multiZ = ptrZ[j];
				}
				else { // были, перемножаем
					multiZ = multiZ * ptrZ[j];
				}
			}
		}
		// сравнение и вывод
		if (multiZ > k) {
			cntElem++;
			cout << "Элемент " << i+1 << " (" << ptrN[i] << ") произведение цифр: " << multiZ << endl;
		}
	}

	cout << endl << "Всего найдено элементов по условию: " << cntElem << endl;

	delete[] ptrZ;
}



int main()
{	
	int i, lenNM, kM;

	setlocale(LC_ALL, "Rus");

	cout << "Введите длину массива N и число K (произведение цифр элемента больше него) через пробел: " << endl;
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

	findElement(ptrNM, lenNM, kM);

	delete[] ptrNM;
	return 0;
}
