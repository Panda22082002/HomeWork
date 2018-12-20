// 4)	Реализуйте вычисление значения полинома в точке посредством схемы Горнера
//

#include "pch.h"
#include <iostream>
using namespace std;

float horner(float varX, int maxN, float *varMA) {
	float s;
	int i;

	s = varMA[maxN];
	for (i = maxN; i > 0; i--) {
		s = s * varX + varMA[i - 1];
	}
	return s;
}


int main()
{
	int N; //степень полинома
	float X;

	setlocale(LC_ALL, "Rus");

	cout << "Введите степень полинома " << endl;
	cin >> N;
	cout << "Введите число Х " << endl;
	cin >> X;

	float *mA = new float[N + 1]; // массив коэффицинтов полинома
	// руками заполнять коэффициенты не будем, назначим им рандомные значения - не в этом суть задачи
	for (int i = 0; i <= N; i++) {
		mA[i] = rand();
	}
	// выводим сам результат - функция horner (какую собственно и требовалось реализовать)
	cout << endl << "Значения полинома в точке посредством схемы Горнера: " << horner(X, N, mA) << endl;

	return 0;
}

