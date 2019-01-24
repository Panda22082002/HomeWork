/*
21) Дан набор из N целых положительных чисел. Необходимо определить, какая цифра чаще всего встречается в десятичной записи чисел этого набора.
Если таких цифр несколько, необходимо вывести их все в порядке убывания — от большей к меньшей.
Напишите эффективную по времени и по памяти программу для решения этой задачи.
*/

#include <iostream>
using namespace std;

struct rowMas { int valSort; int curVal; }; // структура для цифр: valSort - число цифр, curVal - цифра

void MyQuickSort_2(rowMas *vMas, int maxN) { // алгоритм быстрой сортировки одномерного массива структур по элементу curVal
	int cntL = 0, cntC = 0, cntR = 0; // число элементов массива слева, в центре, справа при делении базового массива
	int halfR = maxN / 2;
	int basis = vMas[halfR].curVal; // опорная точка
	rowMas *masL = new rowMas[maxN]; // резервируем массивы для заполнения слева, справа, центр
	rowMas *masC = new rowMas[maxN];
	rowMas *masR = new rowMas[maxN];
	if (maxN > 1) {
		for (int i = 0; i < maxN; i++) {
			if (vMas[i].curVal < basis) {
				cntL++; // число элементов слева
				masL[cntL - 1] = vMas[i];
			}
			else if (vMas[i].curVal > basis) {
				cntR++; // число элементов справа
				masR[cntR - 1] = vMas[i];
			}
			else {
				cntC++;	 // число элементов центр
				masC[cntC - 1] = vMas[i];
			}
		}
		MyQuickSort_2(masL, cntL); // рекурсивно вызываем сами себя для левой половинки массива
		MyQuickSort_2(masR, cntR); // рекурсивно вызываем сами себя для правой половинки массива
	}

	int iPos = -1;
	for (int i = 0; i < cntL; i++) { // заполняем исходный массив из левой половинки
		iPos++;
		vMas[iPos] = masL[i];
	}
	for (int i = 0; i < cntC; i++) { // заполняем исходный массив из центра
		iPos++;
		vMas[iPos] = masC[i];
	}
	for (int i = 0; i < cntR; i++) { // заполняем исходный массив из правой половинки
		iPos++;
		vMas[iPos] = masR[i];
	}
}

void MyQuickSort_1(rowMas *vMas, int maxN) { // алгоритм быстрой сортировки одномерного массива структур по элементу valSort
	int cntL = 0, cntC = 0, cntR = 0; // число элементов массива слева, в центре, справа при делении базового массива
	int halfR = maxN / 2;
	int basis = vMas[halfR].valSort; // опорная точка
	rowMas *masL = new rowMas[maxN]; // резервируем массивы для заполнения слева, справа, центр
	rowMas *masC = new rowMas[maxN];
	rowMas *masR = new rowMas[maxN];
	if (maxN > 1) {
		for (int i = 0; i < maxN; i++) {
			if (vMas[i].valSort < basis) {
				cntL++; // число элементов слева
				masL[cntL - 1] = vMas[i];
			}
			else if (vMas[i].valSort > basis) {
				cntR++; // число элементов справа
				masR[cntR - 1] = vMas[i];
			}
			else {
				cntC++;	 // число элементов центр
				masC[cntC - 1] = vMas[i];
			}
		}
		// сразу сортируем для элементов с одинаковым значением valSort по элементу curVal
		if (cntC > 0) {
			MyQuickSort_2(masC, cntC);
		}
		//
		MyQuickSort_1(masL, cntL); // рекурсивно вызываем сами себя для левой половинки массива
		MyQuickSort_1(masR, cntR); // рекурсивно вызываем сами себя для правой половинки массива
	}

	int iPos = -1;
	for (int i = 0; i < cntL; i++) { // заполняем исходный массив из левой половинки
		iPos++;
		vMas[iPos] = masL[i];
	}
	for (int i = 0; i < cntC; i++) { // заполняем исходный массив из центра
		iPos++;
		vMas[iPos] = masC[i];
	}
	for (int i = 0; i < cntR; i++) { // заполняем исходный массив из правой половинки
		iPos++;
		vMas[iPos] = masR[i];
	}
}

int main()
{
	int i, N, curVal,ostDiv,maxCnt;

	setlocale(LC_ALL, "Rus"); // русифицируем вывод

	cout << "Введите количество чисел: ";	cin >> N;

	int *valN = new int[N]; // массив чисел
	rowMas *mNum = new rowMas[10]; // массив количества цифр (их то всего 10)
	for (i = 0; i < 10; i++) { // начальное заполнение для цифр
		mNum[i].valSort = 0;
		mNum[i].curVal = i;
	}

	// для тестирования заполняем последовательность произвольными значениями
	for (i = 0; i < N; i++) {
		valN[i] = rand();
	}

	for (i = 0; i < N; i++) { // разбираем числа на цифры
		if (valN[i] == 0) { mNum[0].valSort = mNum[0].valSort + 1; } // это ноль, наращиваем счетчик, разбор числа не делаем
		else { // это значимое число
			curVal = valN[i];
			while (curVal > 0) {
				ostDiv = curVal % 10;
				mNum[ostDiv].valSort = mNum[ostDiv].valSort + 1;
				curVal = curVal / 10;
			}
		}
	}

	MyQuickSort_1(mNum, 10); // сортируем массив количества цифр по возрастанию

	maxCnt = mNum[9].valSort; // это максимальное число повторений

	cout << endl << "Максимальное число повторений цифры: " << maxCnt << endl;
	cout << "конкретно цифры: " << endl;
	for (i = 9; i >= 0; i--) {
		if (mNum[i].valSort == maxCnt) {
			cout << mNum[i].curVal << endl;
		}
	}

	return 0;
}

