
// 2)	Напишите эффективную программу, находящую все числа длины n являющиеся палиндромами. В комментариях напишите, почему перебор - эффективный
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{	/* поскольку максимальное число для беззнакового целого 4 294 967 295, то ограничимся максимальной длиной числа в 9 знаков. Если задали больше - ограничимся длиной 9.
	Принцип решения прост: находим половину длины N и последовательно проходимся от значения 1[0..0] до 9[9..9], где в квадратных скобках повторяющиеся цифры длиной
	N/2 -1. Почему начинаем с 1? - число не может начинаться с 0.
	Для каждого числа находим симметричное, например для 1234 - будет 4321. В результате получим 12344321.
	Если N - нечетное, принцип такой сто для четного, только между симметричными половинками числа вставляем цифры от 0 до 9. Т.е. для нечетного вариантов
	будет в 10 раз больше.
	Почему эффективно? - мы не сделали ни одного лишнего шага, сразу находим палиндром, никаких переборов.
	*/
	int lenN, halfLen, noEven, i, dopoln, dopCentr, leftHalf, rightHalf;
	int lowInd, highInd, cntPalindrom, Palindrom, valX, j, xx;

	setlocale(LC_ALL, "Rus");

	cout << "Введите длину числа (больше 1,но не больше 9): " << endl;
	cin >> lenN;
	if (lenN <= 1) { // прерываем если маленькая длина
		cout << "Некорректная длина. Стоп программа..." << endl;
		return 0;
	}
	
	if (lenN > 9) { lenN = 9; }
	halfLen = lenN / 2;
	noEven = lenN % 2; // чет-нечет
	int *ptrZ = new int[halfLen]; // массив для цифр числа

	dopoln = 1; // число, на котрое мы будем умножать левую половину перед сложением с правой чтобы получить палиндром
	dopCentr = 0; // число, на которое умножим цифру серединки, если N - нечетное 
	for (i = 1; i <= halfLen; i++) { dopoln = dopoln * 10; }

	lowInd = dopoln / 10; // от какого числа цикл
	highInd = lowInd * 10 - 1; // до какого числа цикл

	if (noEven > 0) { // если N нечетное
		dopCentr = dopoln;
		dopoln = dopoln * 10;
	}

	cout << endl;
	cntPalindrom = 0;
	for (i = lowInd; i <= highInd; i++) { // строим палиндромы на основе левой половинки
		leftHalf = i;
		valX = i;
		for (j = 1; j <= halfLen; j++) { // разбиваем число на цифры
			ptrZ[halfLen - j] = valX % 10;
			valX = valX / 10;
		}
		
		rightHalf = 0;
		for (j = 1; j <= halfLen; j++) { // строим правую половинку по цифрам левой
			rightHalf = rightHalf * 10 + ptrZ[halfLen - j];
		}

		if (noEven == 0) { // длина N - четная
			cntPalindrom++;
			Palindrom = leftHalf * dopoln + rightHalf;
//			cout << "Палиндром " << cntPalindrom << ": " << Palindrom << endl;  // вывод для отладки
		}
		else { // длина N - нечетная
			for (j = 0; j <= 9; j++) { // перебираем цифры от 0 до 9
				cntPalindrom++;
				Palindrom = leftHalf * dopoln + dopCentr*j + rightHalf;
//				cout << "Палиндром " << cntPalindrom << ": " << Palindrom << endl; // вывод для отладки
			}
		}
	}

	cout << endl << "Всего палиндромов: " << cntPalindrom << endl;

	delete[] ptrZ;
    return 0; 
}
