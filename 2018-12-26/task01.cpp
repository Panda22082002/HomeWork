// 1)	Напишите программу, находящую k-ую порядковую статистику. Программа должна работать за время O(n) в среднем.
//

#include "pch.h"
#include <iostream>
using namespace std;

void MyQuickSort(int *vMas, int maxN) { // алгоритм быстрой сортировки
	int cntL=0, cntC=0, cntR=0; // число элементов массива слева, в центре, справа при делении базового массива
	int halfR = maxN / 2;
	int basis = vMas[halfR]; // опорная точка
	int *masL = new int[maxN]; // резервируем массивы для заполнения слева, справа, центр
	int *masC = new int[maxN];
	int *masR = new int[maxN];
	if (maxN > 1) {
		for (int i = 0; i < maxN; i++) {
			if (vMas[i] < basis) {
				cntL++; // число элементов слева
				masL[cntL - 1] = vMas[i];
			}
			else if (vMas[i] > basis) {
				cntR++; // число элементов справа
				masR[cntR - 1] = vMas[i];
			}
			else {
				cntC++;	 // число элементов центр
			}
		}
		MyQuickSort(masL, cntL); // рекурсивно вызываем сами себя для левой половинки массива
		MyQuickSort(masR, cntR); // рекурсивно вызываем сами себя для правой половинки массива
	}

	int iPos = -1;
	for (int i = 0; i < cntL; i++) { // заполняем исходный массив из левой половинки
		iPos++;
		vMas[iPos] = masL[i];
	}
	for (int i = 0; i < cntC; i++) { // заполняем исходный массив из центра
		iPos++;
		vMas[iPos] = basis;
	}
	for (int i = 0; i < cntR; i++) { // заполняем исходный массив из правой половинки
		iPos++;
		vMas[iPos] = masR[i];
	}

}


int main()
{ // задача сводится к сортировке массива. по отсортированному массиву находящую k-ую порядковую статистику.
	int N; //размер массива
	int K; // статистика

	setlocale(LC_ALL, "Rus");

	cout << "Введите размер массива: " << endl;
	cin >> N;
	cout << "Введите статистику k: " << endl;
	cin >> K;

	if ((K < 1) or (K > N)) {
		cout << endl << "Неправильно задан номер статистики! Обработка прервана..." << endl;
		return 0;
	}

	int *mZ = new int[N]; // массив чисел
	// назначим им рандомные значения - для тестирования
	for (int i = 0; i < N; i++) {
		mZ[i] = rand();
	}

	// Для отладки - выводим что было
	cout << endl << "Было:" << endl;
	for (int i = 0; i < N; i++) { cout << mZ[i] << endl; }

	MyQuickSort(mZ, N); // проводим сортировку массива

	// Для отладки - выводим что стало
	cout << endl << "Стало:" << endl;
	for (int i = 0; i < N; i++) { cout << mZ[i] << endl; }

	// Собственно ответ
	cout << endl << "Ответ: k-я статистика равна " << mZ[K-1] << endl;

	return 0;
}

