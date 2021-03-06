/*
18) Дед Мороз и Снегурочка приходят на детские утренники с мешком конфет. Дед Мороз делит конфеты поровну между всеми присутствующими детьми
(детей на утреннике никогда не бывает больше 100), а оставшиеся конфеты отдает Снегурочке. Снегурочка каждый раз записывает в блокнот 
количество полученных конфет. Если конфеты разделились между всеми детьми без остатка, Снегурочка ничего не получает и ничего не записывает.
Когда утренники закончились, Деду Морозу стало интересно, какое число чаще всего записывала Снегурочка. Дед Мороз и Снегурочка — волшебные,
поэтому число утренников N, на которых они побывали, может быть очень большим. Напишите программу, которая будет решать эту задачу.
Описание входных данных
В первой строке вводится одно целое положительное число — количество утренников N. 
Каждая из следующих N строк содержит два целых числа: сначала D — количество пришедших на очередной утренник детей, а затем K – количество конфет в мешке Деда Мороза на этом утреннике.
Гарантируется выполнение следующих соотношений:
1 ≤ N ≤ 10000
1 ≤ D ≤ 100 (для каждого D) D ≤ K ≤ 1000 (для каждой пары D, K)
Описание выходных данных 
Программа должна вывести одно число — то, которое Снегурочка записывала чаще всего. 
Если несколько чисел записывались одинаково часто, надо вывести большее из них. Если Снегурочка ни разу ничего не записывала, надо вывести ноль.
*/

#include <iostream>
using namespace std;

void MyQuickSort(int *vMas, int maxN) { // алгоритм быстрой сортировки
	int cntL = 0, cntC = 0, cntR = 0; // число элементов массива слева, в центре, справа при делении базового массива
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
{
	int N; //число утренников
	int i,prevVal,prevCnt,curVal,curCnt; 

	setlocale(LC_ALL, "Rus");

	cout << "Введите число утренников: "; cin >> N;
	int *childN = new int[N]; // число детей 
	int *chocoN = new int[N]; // число конфет
	int *snegN = new int[N]; // ну и что Снегурке осталось
	for (i = 0; i < N; i++) {
		cout << "Введите число детей и конфет для утренника " << i+1 <<": "; cin >> childN[i] >> chocoN[i];
		snegN[i] = chocoN[i] % childN[i];
	}
	
	MyQuickSort(snegN, N); // сортируем Снегуркин доход
	// по отсортированному массиву определяем сколько и каких прибылей у Снегурки
	prevVal = 0;
	prevCnt = 0;
	curVal = 0;
	curCnt = 0;
	for (i = 0; i < N; i++) {
		if (curVal == snegN[i]) { curCnt++; } // если повторилось текущее значение - наращиваем счетчик этого значения
		else { // произошла смена значения - сравниваем накопленное количество с предыдущим. Если больше - сохраняем. Устанавливаем счетчик в 1 для нового значения.
			if ((curCnt >= prevCnt) and (curVal>0)) {
				prevCnt = curCnt;
				prevVal = curVal;
			}
			curVal = snegN[i];
			curCnt = 1;
		}
	}
	// на выходе из цикла снова делаем проверку чтоб не потерять последнее значение
	if ((curCnt >= prevCnt) and (curVal > 0)) {
		prevCnt = curCnt;
		prevVal = curVal;
	}

	// Собственно ответ
	cout << endl << "Наиболее частое число равно: " << prevVal << endl;

	return 0;
}

