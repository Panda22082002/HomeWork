#include "pch.h"
#include <iostream>

using namespace std;

struct rebro { // структура описывает ребро графа
	int numNode; // вершина, в которую приходит ребро
	double lenRebro; // длина ребра
};

void Opisanie_Grafa(int pCntNode,int *pRebraNode, rebro **pGraf) { // заполнение данных графа
	int i;
	// теперь описываем граф, показанный в проекте. Эта часть должна заполняться по реальному графу.
	pRebraNode[0] = 3; // учитываем что индекс массива начинается с 0, а номера вершин с 1.
	pRebraNode[1] = 3;
	pRebraNode[2] = 4;
	pRebraNode[3] = 3;
	pRebraNode[4] = 2;
	pRebraNode[5] = 3;
	for (i = 0; i < pCntNode; i++) { // заполням строки двумерного массива массивами ребер, выходящими из вершины
		pGraf[i] = new rebro[pRebraNode[i]];
	}
	// теперь заполняем ребра, выходящие из вершин. Учитываем что индексы массива начинаяются с 0, а не 1
	pGraf[0][0].numNode = 2; // ребро из вершины 1 в 2. В какую вершину приходим
	pGraf[0][0].lenRebro = 7; // ребро из вершины 1 в 2. Длина ребра. Далее все аналогично
	pGraf[0][1].numNode = 3;
	pGraf[0][1].lenRebro = 9;
	pGraf[0][2].numNode = 6;
	pGraf[0][2].lenRebro = 14;
	pGraf[1][0].numNode = 1;
	pGraf[1][0].lenRebro = 7;
	pGraf[1][1].numNode = 3;
	pGraf[1][1].lenRebro = 10;
	pGraf[1][2].numNode = 4;
	pGraf[1][2].lenRebro = 15;
	pGraf[2][0].numNode = 1;
	pGraf[2][0].lenRebro = 9;
	pGraf[2][1].numNode = 2;
	pGraf[2][1].lenRebro = 10;
	pGraf[2][2].numNode = 4;
	pGraf[2][2].lenRebro = 11;
	pGraf[2][3].numNode = 6;
	pGraf[2][3].lenRebro = 2;
	pGraf[3][0].numNode = 2;
	pGraf[3][0].lenRebro = 15;
	pGraf[3][1].numNode = 3;
	pGraf[3][1].lenRebro = 11;
	pGraf[3][2].numNode = 5;
	pGraf[3][2].lenRebro = 6;
	pGraf[4][0].numNode = 4;
	pGraf[4][0].lenRebro = 6;
	pGraf[4][1].numNode = 6;
	pGraf[4][1].lenRebro = 9;
	pGraf[5][0].numNode = 1;
	pGraf[5][0].lenRebro = 14;
	pGraf[5][1].numNode = 3;
	pGraf[5][1].lenRebro = 2;
	pGraf[5][2].numNode = 5;
	pGraf[5][2].lenRebro = 9;
	// Закончили заполнение исходных данных
}

void WorkWithNode(int pNode, double pMaxLen, int *pRebraNode, rebro **pGraf, bool *pFlagN, double *pLenPath, int *pPrevNode) { // работа с вершиной графа
	int i, numOtherN;
	double lenOtherN;
	for (i = 0; i < pRebraNode[pNode]; i++) { // цикл по всем ребрам из вершины
		numOtherN = pGraf[pNode][i].numNode;
		lenOtherN = pGraf[pNode][i].lenRebro;
		if (pFlagN[numOtherN - 1] == false) { // если узел еще не отработан
			if ((pLenPath[pNode] + lenOtherN) < pLenPath[numOtherN-1]) { // если полученная длина пути меньше существующей тогда меняем на новое значение
				pLenPath[numOtherN - 1] = pLenPath[pNode] + lenOtherN;
				pPrevNode[numOtherN - 1] = pNode+1;
			}
		}
	}
	pFlagN[pNode] = true; // ставим флаг отработки вершины
}

void Dijkstra(int pBegNode, int pCntNode, int *pRebraNode, rebro **pGraf, double *pLenPath, int *pPrevNode) { // алгоритм Дейкстры
	int i, j, nextNode, numOtherN;
	double tekMin, lenRebro;
	bool *mFlagN = new bool[pCntNode]; // массив флагов использованных вершин графа для алгоритма Дейкстры

	for (i = 0; i < pCntNode; i++) { // первоначально заполняем массив длин и флагов
		pLenPath[i] = DBL_MAX; // максимально возможное число данного типа (double)
		mFlagN[i] = false;
		pPrevNode[i] = -1;
		if (pRebraNode[i]==0) { mFlagN[i] = true; } // отсекаем несвязанные вершины
	}
	pLenPath[pBegNode - 1] = 0; // Для начальной точки длина пути равна 0
	pPrevNode[pBegNode - 1] = 0;
	nextNode = pBegNode - 1;

	while (nextNode>=0) { // цикл пока существуют необработанные точки 
		// цикл по ребрам, выходящим из данной вершины
		for (j = 0; j < pRebraNode[nextNode]; j++) {
			numOtherN = pGraf[nextNode][j].numNode;
			lenRebro = pGraf[nextNode][j].lenRebro;
			if (mFlagN[numOtherN - 1] == false) { // если узел еще не отработан
				if ((pLenPath[nextNode] + lenRebro) < pLenPath[numOtherN - 1]) { // если полученная длина пути меньше существующей тогда меняем на новое значение
					pLenPath[numOtherN - 1] = pLenPath[nextNode] + lenRebro;
					pPrevNode[numOtherN - 1] = nextNode + 1;
				}
			}
		}
		mFlagN[nextNode] = true; // отметка об отработке этой опорной точки
		// ищем новую опорную точку по минимуму пути
		tekMin = DBL_MAX; // текущее минимальное значение пути (для выбора новой опорной точки)
		nextNode = -1; // следующая опорная точка по минимуму пути
		for (i = 0; i < pCntNode; i++) {
			if ((mFlagN[i] == false) and (pLenPath[i] < DBL_MAX)) { // если узел еще не отработан и длина пути уже установлена (не равна максимально возможной)
				if (pLenPath[i] < tekMin) {
					tekMin = pLenPath[i];
					nextNode = i;
				}
			}
		}
	}
}

int main()
{
	int cntNode, begNode, endNode; // число вершин графа, № начальной вершины, № конечной вершины
	int i, fullPath, halfPath, n1, n2;
	double resMinPath; // найденный минимальный путь

	using namespace std;
	setlocale(LC_ALL, "Rus"); // русифицируем вывод
	
	// РАЗДЕЛ 1.
	cout << "Введите номера начальной и конечной вершин (не больше 6)" << endl;
	cin >> begNode >> endNode;
	cout << endl;
	
	// РАЗДЕЛ 2.
	// массивы описывающие граф
	cntNode = 6;
	int *mRebraNode = new int[cntNode]; // массив, описывающий сколько ребер выходит из вершины графа
	rebro **mGraf = new rebro*[cntNode]; // двумерный массив, описывающий ребра, выходящие из вершины. № строки массива - № вершины, значение - массив значений типа rebro (в какую точку приходит ребро и его длина)
	// Описываем граф
	Opisanie_Grafa(cntNode, mRebraNode, mGraf);

	// РАЗДЕЛ 3.
	// Проверим начальную точку 
	if (mRebraNode[begNode - 1] == 0) { // нет выходящих из начальной точки ребер
		cout << endl << "Начальная точка - несвязанная! Обработка прервана..." << endl;
		return 0;
	}
	// Проверим конечную точку 
	if (mRebraNode[endNode - 1] == 0) { // нет выходящих из конечной точки ребер
		cout << endl << "Конечная точка - несвязанная! Обработка прервана..." << endl;
		return 0;
	}

	// Описание выходных данных после обработки по алгоритму Дейкстры
	double *mLenPath = new double[cntNode]; // массив длин пути из начальной точки до конкретной точки для алгоритма Дейкстры
	int *mPrevNode = new int[cntNode]; // массив предыдущих вершин для которых получился мин.путь для заданной вершины (будет использован для построения пути)
	int *mPath = new int[cntNode]; // массив описания полученного кратчайшего пути 

	// Обрабатывем граф по алгоритму Дейкстры
	Dijkstra(begNode,cntNode,mRebraNode,mGraf,mLenPath,mPrevNode);

	// РАЗДЕЛ 4. Обработка и вывод полученных результатов
	// Обрабатываем полученные данные
	if (mLenPath[endNode - 1] == DBL_MAX) { // если в конечной точке длина пути так и осталась максимальной - значить путь построить не удалось
		cout << endl << "Не удалось построить путь!" << endl;
	}
	else {
		resMinPath = mLenPath[endNode - 1];
		// строим кратчайший путь от конечной точки к начальной, т.к. у нас для каждой вершины заполнена предыдущая
		fullPath = 1; // число вершин в пути
		mPath[0] = endNode;
		i = endNode;
		while (true) {
			if (mPrevNode[i - 1] != begNode) {
				mPath[fullPath] = mPrevNode[i - 1];
				i = mPrevNode[i - 1];
				fullPath = fullPath + 1;
			}
			else { 
				fullPath = fullPath + 1;
				mPath[fullPath-1] = begNode;
				break; }
		}
		// теперь зеркально разворачиваем полученный массив, чтобы получить путь из начальной точки в конечную   
		halfPath = fullPath / 2; // половина длина пути
		for (i = 0; i < halfPath; i++) {
			n1 = mPath[i];
			n2 = mPath[fullPath - 1 - i];
			mPath[i] = n2;
			mPath[fullPath - 1 - i] = n1;
		}
		// Теперь выводим результат
		cout << endl << "Длина минимального пути: " << resMinPath << endl;
		cout << "Путь: ";
		for (i = 0; i < fullPath; i++) {
			cout << mPath[i] << " ";
		}
		cout << endl;
	}

	return 0;
}

