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
