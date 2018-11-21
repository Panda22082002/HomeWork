
// 6)	Напишите программу, находящую все простые числа Ченя не превосходящие n. Программа должна работать не более чем за O(n*log log n) шагов. 

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int X, valX, i, j, cntSimple, cntChen;
	bool isSimpl;

	setlocale(LC_ALL, "Rus");
	cout << "Введите число N: " << endl;
	cin >> X;
	if (X <= 2) { // тут считать нечего, сразу возвращаем 0, да и потом перебор пойдет по нечетным
		cout << "Чисел Ченя: 0" << endl;
		return 0;
	}
	// резервирем память под простые числа меньшие N. Так как четные кроме 2 не простые, то их число не превысит N/2 + 1
	// прилично расходуем память (для больших N), но потом вариантов перебора меньше - скорость решения выше
	int *ptrSm = new int[(X / 2)+2]; // почему на 1 больше? нам дополнительно понадобиться первое простое число большее N
	ptrSm[0] = 2;
	cntSimple = 1;
	// цикл для нахождения простых чисел меньше N, проходим только по нечетным 
	for (i = 3; i < X; i += 2) {
		isSimpl = true;
		for (int j = 2; j < i; j++) { // конкретно проверка на простое 
			if (i%j == 0) {
				isSimpl = false;
				break;
			}
		}
		if (isSimpl) {
			cntSimple++;
			ptrSm[cntSimple - 1] = i;
		}
	}
	// цикл для нахождения первого простого числа больше или равного N
	i = X;
	while (true) {
		isSimpl = true;
		for (int j = 2; j < i; j++) { // конкретно проверка на простое 
			if (i%j == 0) {
				isSimpl = false;
				break;
			}
		}
		if (isSimpl) {
			ptrSm[cntSimple] = i;
			break;
		}
		i++;
	}
	// теперь из этого массива простых чисел определяем, какие из них Ченя
	cout << endl;
	cntChen = 0;
	for (i = 0; i < cntSimple; i++) {
		if ((ptrSm[i] + 2) == ptrSm[i + 1]) { // текущее простое + 2 тоже простое - выполнено одно из условий Ченя
			cntChen = cntChen + 1;
			cout << "Число Ченя " << cntChen << ": " << ptrSm[i] << endl; // выводим число Ченя
		} 
		else { // проверяем на второе условие Ченя - как произведение двух простых
			valX = ptrSm[i] + 2;
			for (j = 0; j <= i; j++) { // 1 деление на простое
				if ((valX % ptrSm[j]) == 0) {
					valX = valX / ptrSm[j];
					break;
				}
			}
			for (j = 0; j <= i; j++) { // 2 деление на простое
				if ((valX % ptrSm[j]) == 0) {
					valX = valX / ptrSm[j];
					break;
				}
			}
			if (valX == 1) { // выполнилось 2 условие
				cntChen = cntChen + 1;
				cout << "Число Ченя " << cntChen << ": " << ptrSm[i] << endl; // выводим число Ченя
			}

		}
	}

	delete[] ptrSm;
	return 0;
}

