#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

// Проверка на простое число
bool isSimple(int X) {
	bool Res = true;
	if (X < 0) { X = -X; }
	if (X = 0) { return true; }
	if (X = 1) { return false; }
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

int workMassive04(int *ptrM,int maxN)
{
	int n;
	int sumRes = 0;
	for (n = 0; n < maxN; n++) {
		if (isSimple(ptrM[n])) {sumRes=sumRes+ ptrM[n];}
	}
	return sumRes;
}

int* workMassive10(int *ptrM, int *maxN)
{
	int n,tekNum;
	int cntNoEven = 0;
	// число нечетных элементов массива
	for (n = 0; n < *maxN; n++) {
		if (isEven(ptrM[n])==false) { cntNoEven = cntNoEven + 1; }
	}
	if (cntNoEven == 0) { cntNoEven = 1; }
	// определяем новый массив
	int *ptrNA = new int[cntNoEven];
	// переписываем нечетные в новый массив
	tekNum = 0;
	for (n = 0; n < *maxN; n++) {
		if (isEven(ptrM[n]) == false) { 
			tekNum = tekNum + 1;
			ptrNA[tekNum - 1] = ptrM[n];
		}
	}
//	cout << cntNoEven << endl;
//	cout << ptrM << " " << ptrNA << " " << *maxN << " " << maxN << endl;
	*maxN = cntNoEven; // меняем число элементов в массиве, чтоб видела вызывающая процедура

	return ptrNA;
}

int* workMassive11(int *ptrM, int *maxN)
{
	int n, tekNum;
	int minV = ptrM[0];
	int maxV = ptrM[0];
	// минимальное и максимальное значение массива
	for (n = 0; n < *maxN; n++) {
		if (ptrM[n] < minV) { minV = ptrM[n]; }
		if (ptrM[n] > maxV) { maxV = ptrM[n]; }
	}
	// количество элементов в новом массиве
	tekNum = 0;
	for (n = 0; n < *maxN; n++) {
		if ((ptrM[n] != minV) and (ptrM[n] != maxV)) {
			tekNum = tekNum + 1;
		}
	}
	if (tekNum == 0) { tekNum = 1; }
	// определяем новый массив
	int *ptrNA = new int[tekNum];
	ptrNA[0] = 0;
	// переписываем не макс и мин в новый массив
	tekNum = 0;
	for (n = 0; n < *maxN; n++) {
		if ((ptrM[n] != minV) and (ptrM[n] != maxV)) {
			tekNum = tekNum + 1;
			ptrNA[tekNum - 1] = ptrM[n];
		}
	}
	*maxN = tekNum; // меняем число элементов в массиве, чтоб видела вызывающая процедура

	return ptrNA;
}

int* workMassive12(int *ptrM, int *maxN)
{
	int n, newN;
	newN = 2*(*maxN);
	// определяем новый массив
	int *ptrNA = new int[newN];
	// переписываем значение и его квадрат в новый массив
	for (n = 0; n < *maxN; n++) {
			ptrNA[2 * n] = ptrM[n];
			ptrNA[2 * n +1] = ptrM[n] * ptrM[n];
	}
	*maxN = newN; // меняем число элементов в массиве, чтоб видела вызывающая процедура

	return ptrNA;
}

char* workMassive13(char *ptrC, int *maxN)
{
	int n, newN=0, cntSym=1;
	char numToChar, tekSymbol=ptrC[0];
	string newS="";
	// стартуем со 2 символа строки
	for (n = 1; n < *maxN; n++) {
		if (ptrC[n] != tekSymbol) {
			// пишем предыдущий символ
			numToChar = cntSym + '0';
			newS = newS + numToChar + tekSymbol;
			newN = newN + 2;
			// задаем новый начальный символ
			cntSym = 1;
			tekSymbol = ptrC[n];
		} // конец условия ели предыдущий и текущий символы не равны
		else { cntSym = cntSym + 1; } // наращиваем счетчик найденных символов - если повторяются
	}
	// пишем последний символ по выходу из цикла, т.к. в цикле он не пишется
	numToChar = cntSym + '0';
	newS = newS + numToChar + tekSymbol;
	newN = newN + 2;

	*maxN = newN; // меняем число элементов в массиве, чтоб видела вызывающая процедура
	// создаем новый дин.массив и пишем в него из строки
	char *ptrNA = new char[newN];

	for (n = 0; n < newN; n++) { ptrNA[n] = newS[n]; }

	return ptrNA;
}

char* workMassive14(char *ptrC, int *maxN)
{
	int i, n, newN=0, cntSym;
	char tekSymbol;
	string newS = "";

	for (n = 0; n < *maxN; n=n+2) {
		tekSymbol = ptrC[n + 1];
		cntSym = ptrC[n] - '0';
		for (i = 0; i < cntSym; i++) { // цикл по числу повторений символов
			newS = newS + tekSymbol;
			newN = newN + 1; // наращиваем счетчик числа символов в строке
		}
	}

	*maxN = newN; // меняем число элементов в массиве, чтоб видела вызывающая процедура
	// создаем новый дин.массив и пишем в него из строки
	char *ptrNA = new char[newN];

	for (n = 0; n < newN; n++) { ptrNA[n] = newS[n]; }

	return ptrNA;
}

char* workMassive20(char *ptrC, int *maxN)
{
	int n, newN;
	bool probel; // флаг что начались пробелы
	// определяем количество символов вновом массиве подавляя лишние пробелы
	newN = 0;
	probel = true; // хитрость чтоб убрать пробелы в начале строки
	for (n = 0; n < *maxN; n++) {
		if (ptrC[n] != ' ') {
			probel = false;
			newN = newN + 1;
		}
		else {
			if (probel == false) {
				probel = true;
				newN = newN + 1;
			}
		}
	}
	
	// создаем новый дин.массив и пишем в него из строки
	char *ptrNA = new char[newN];

	// пишем в новый массив без лишних пробелов
	newN = 0;
	probel = true; // хитрость чтоб убрать пробелы в начале строки
	for (n = 0; n < *maxN; n++) {
		if (ptrC[n] != ' ') {
			probel = false;
			newN = newN + 1;
			ptrNA[newN - 1] = ptrC[n];
		}
		else {
			if (probel == false) {
				probel = true;
				newN = newN + 1;
				ptrNA[newN - 1] = ptrC[n];
			}
		}
	}

	*maxN = newN; // меняем число элементов в новом массиве, чтоб видела вызывающая процедура

	return ptrNA;
}

bool isPalindrom(char *ptrC, int maxN)
{
	int half_n, n;
	bool resP = true;

	half_n = maxN / 2;

	for (n = 0; n < half_n; n++) {
		if (ptrC[n] != ptrC[maxN-1-n]) {
		resP=false;
		break;
		}
	}

	return resP;
}

bool isAnogram(char *ptrC1, int maxN1, char *ptrC2, int maxN2)
{
	// создадим 2 статических массива длиной 256 и в них будем писать количество кодов ASCII для каждой строки.  
	int kodASCII, n;
	int asci_1[256], asci_2[256];
	bool resP = true;
	// обнулим массивы
	for (n = 0; n < 256; n++) {
		asci_1[n] = 0;
		asci_2[n] = 0;
	}
	// заполняем массив по 1 строке
	for (n = 0; n < maxN1; n++) {
		kodASCII = ptrC1[n] - '\0';
		asci_1[kodASCII] = asci_1[kodASCII] + 1;
	}
	// заполняем массив по 2 строке
	for (n = 0; n < maxN2; n++) {
		kodASCII = ptrC2[n] - '\0';
		asci_2[kodASCII] = asci_2[kodASCII] + 1;
	}
	// теперь сравним 2 массива на равность. Если равны - то возможна анограмма (количество различных букв совпадает)
	for (n = 0; n < 256; n++) {
		if (asci_1[n] != asci_2[n]) { // что-то не совпало, прерываем, анограммы не будет
			resP = false;
			break;
		}
	}

	return resP;
}

int trianglePas(int valN, int valK)
{
	int i, j, half_n,noEven_n,resKoef;
	int **mas;
	int *tekStroka,*predStroka;

	half_n = valN / 2;
	noEven_n = valN % 2;
	// коэффициенты симметричны относительно середины, поэтому для К больших середины правим К
	if ((noEven_n > 0) and (valK > (half_n+1))) { // нечетное N
		valK = 2 * (half_n + 1) - valK;
	}
	else if ((noEven_n = 0) and (valK > half_n)) { // четное N
		valK = 2 * half_n + 1 - valK;
	}

	// создаем двумерный динамический массив
	mas = new int*[valN];
	for (i = 0; i < valN; i++) {
		mas[i] = new int[valK]; // указатель на строку
	}
	// заполняем 1 строку массива и его левую сторону 1 - от них будем плясать дальше
	tekStroka = mas[0];
	for (j = 0; j < valK; j++) {
		tekStroka[j] = 1;
	}
	for (i = 0; i < valN; i++) {
		tekStroka = mas[i];
		tekStroka[0] = 1;
	}
	// заполняем остальные элементы массива если К и N больше 1 
	if ((valN > 1) and (valK >1)) {
		for (i = 1; i < valN; i++) {
			predStroka = mas[i-1];
			tekStroka = mas[i];
			for (j = 1; j < valK; j++) {
				tekStroka[j] = predStroka[j]+tekStroka[j-1];
			}
		}
	}
	// получаем результат
	tekStroka = mas[valN-1];
	resKoef = tekStroka[valK-1];
	// освобождаем память от массива
	for (i = 0; i < valN; i++) {
		delete[] mas[i];
	}
	delete[] mas;

	return resKoef;
}

double methodHalfDivide(double valX, int koren)
{	// Метод половинного деления
	int i, blockDiv=100, cntBlock=0, valDiv,tekIter;
	int maxIterNum = 1000; // максимальное число итераций
	double tochnRes = 0.0001; // точность результата
	double minV=1, maxV=1, halfV,tekResMin,tekResMax,tekResHalf;
	double raznMin, raznMax, raznHalf, raznMinA, raznMaxA, raznHalfA;
	// Для начала находим опорные точки для начала метода: количество блоковN: (100)^n - для квадратного корня, (1000)^n для кубического,где n -натуральное число
	valDiv = valX;
	if (valDiv < 0) { valDiv = -valDiv; } // берем модуль числа
	if (koren == 3) { blockDiv = 1000; }
	while ((valDiv / blockDiv) > 0) {
		cntBlock = cntBlock + 1;
		valDiv = valDiv / blockDiv;
	}
	if (cntBlock > 0) {
		for (i = 0; i < cntBlock; i++) {
			minV = minV * 10; // почему 10? - да это корень заданной степени из блока
		}
	}
	maxV = minV * 10; // Все... стартовые опорные точки для метода определены. Искомое число находится между ними

	// собственно сам метод половинного деления
	tekIter = 0;
	while (true)
	{
		tekIter = tekIter + 1;
		if (tekIter > maxIterNum) { break; } // прерывание по превышению числа итераций
		// значения функции на краях отрезка и посередине
		tekResMin = minV * minV;
		if (koren == 3) {
			tekResMin = tekResMin * minV;
		}
		tekResMax = maxV * maxV;
		if (koren == 3) {
			tekResMax = tekResMax * maxV;
		}
		halfV = (minV + maxV) / 2;
		tekResHalf = halfV * halfV;
		if (koren == 3) {
			tekResHalf = tekResHalf * halfV;
		}
		raznMin = tekResMin - valX;
		raznMax = tekResMax - valX;
		raznHalf = tekResHalf - valX;
		raznMinA = raznMin;
		raznMaxA = raznMax;
		raznHalfA = raznHalf;
		if (raznMinA < 0) { raznMinA = -raznMinA; }
		if (raznMaxA < 0) { raznMaxA = -raznMaxA; }
		if (raznHalfA < 0) { raznHalfA = -raznHalfA; }
		
		// теперь смотрим какие начальные значения присвоить следующей итерации или значения в опорных точках близки к искомым в пределах точности

		if ((maxV-halfV) <= tochnRes) { // прерывание по точности искомого результата
			break;
		}
		else if (raznMinA <= tochnRes) { // прерывание по точности обратной функции (квадрата/куба)
			halfV = minV;
			break;
		}
		else if (raznMaxA <= tochnRes) { // прерывание по точности обратной функции (квадрата/куба)
			halfV = maxV;
			break;
		}
		else if (raznHalfA <= tochnRes) { // прерывание по точности обратной функции (квадрата/куба)
			break;
		}
		else if ((raznMin < 0) and (raznHalf > 0)) { // новые отрезок как минимум-средний
			maxV = halfV;
		}
		else if ((raznHalf < 0) and (raznMax > 0)) { // новые отрезок как средний-максимум
			minV = halfV;
		}
		else { // не было перехода функции через 0, это ошибка - прерываем
			cout << endl << "Что-то пошло не так... Не было перехода функции через 0 на отрезке, это ошибка - прерываем..." << endl;
			break;
		}
	}

	cout << endl << "Число итераций: " << tekIter << endl;

	if ((koren == 3) and (valX < 0)) { halfV = -halfV; }
	
	return halfV;
}

double funcBlackBox(double valX)
{ /* монотонная функция черного ящика y=x^3+3x^2+8x+17+0.97*exp(x) */
	double resu;
	resu = valX * valX*valX + 3 * valX*valX + 8 * valX + 17 + 0.97*exp(valX);
//	resu = 0.0005*valX * valX*valX + 17;
//	resu = -23 + exp(valX);
	return resu;
}

double methodHalfDivMonoBB()
{	// Метод половинного деления для неизвестной монотонной функции
	int tekIter;
	int maxIterNum = 1000; // максимальное число итераций
	double tochnRes = 0.0001; // точность результата
	double minV = 1, maxV = 1, halfV, tekResMin, tekResMax, tekResHalf;
	double raznMin, raznMax, raznHalf, raznMinA, raznMaxA, raznHalfA;
	bool directUp = true;  
	// Для начала находим опорные точки для начала метода: поскольку вид функции неизвестен, попытаемся найти значения функции в точках 1,10,100,1000 и т.д.
	// поскольку макс.значение для результата (тип double) конечно, то за конечное разумное число итераций найдем нужный начальный отрезок.
	minV = -1;
	halfV = 0;
	maxV = 1;
	tekResMin = funcBlackBox(minV);
	tekResHalf = funcBlackBox(halfV);
	tekResMax = funcBlackBox(maxV);
	if (tekResMin > tekResMax) { directUp = false; } // функция убывающая
	// смотрим, в какую сторону будем двигаться и ищем начальный отрезок
	if (((tekResMin > 0) and (tekResMax > 0)) or ((tekResMin < 0) and (tekResMax < 0))) { // значения функции в точках -1 и 1 в одной полуплоскости (нет перехода через 0)
		if (((tekResMax > 0) and (directUp == false)) or ((tekResMax < 0) and (directUp == true))) { // если в точке 1 функция отрицательная и возрастает или положительная и убывает
			minV = 1;
			while (true) {
				maxV = minV * 10;
				tekResMin = funcBlackBox(minV);
				tekResMax = funcBlackBox(maxV);
				if (((tekResMin >= 0) and (tekResMax <= 0)) or ((tekResMin <= 0) and (tekResMax >= 0))) { // есть переход через 0
					break;
				}
				minV = maxV;
			}
		}
		else {
			maxV = -1;
			while (true) {
				minV = maxV * 10;
				tekResMin = funcBlackBox(minV);
				tekResMax = funcBlackBox(maxV);
				if (((tekResMin >= 0) and (tekResMax <= 0)) or ((tekResMin <= 0) and (tekResMax >= 0))) { // есть переход через 0
					break;
				}
				maxV = minV;
			}
		}
	}
	// конец определения начального отрезка

	// собственно сам метод половинного деления
	tekIter = 0;
	while (true)
	{
		tekIter = tekIter + 1;
		if (tekIter > maxIterNum) { break; } // прерывание по превышению числа итераций
		// значения функции на краях отрезка и посередине
		halfV = (minV + maxV) / 2;
		tekResMin = funcBlackBox(minV);
		tekResHalf = funcBlackBox(halfV);
		tekResMax = funcBlackBox(maxV);
		raznMin = tekResMin;
		raznMax = tekResMax;
		raznHalf = tekResHalf;
		raznMinA = raznMin;
		raznMaxA = raznMax;
		raznHalfA = raznHalf;
		if (raznMinA < 0) { raznMinA = -raznMinA; }
		if (raznMaxA < 0) { raznMaxA = -raznMaxA; }
		if (raznHalfA < 0) { raznHalfA = -raznHalfA; }

		// теперь смотрим какие начальные значения присвоить следующей итерации или значения в опорных точках близки к искомым в пределах точности

		if ((maxV - halfV) <= tochnRes) { // прерывание по точности искомого результата
			break;
		}
		else if (raznMinA <= tochnRes) { // прерывание по точности функции
			halfV = minV;
			break;
		}
		else if (raznMaxA <= tochnRes) { // прерывание по точности функции
			halfV = maxV;
			break;
		}
		else if (raznHalfA <= tochnRes) { // прерывание по точности функции
			break;
		}
		else if ((raznMin < 0) and (raznHalf > 0)) { // новые отрезок как минимум-средний
			maxV = halfV;
		}
		else if ((raznHalf < 0) and (raznMax > 0)) { // новые отрезок как средний-максимум
			minV = halfV;
		}
		else { // не было перехода функции через 0, это ошибка - прерываем
			cout << endl << "Что-то пошло не так... Не было перехода функции через 0 на отрезке, это ошибка - прерываем..." << endl;
			break;
		}
	}

	cout << endl << "Число итераций: " << tekIter << endl;

	return halfV;
}

void mainNoAnswer() 
{
	cout << endl;
	cout << "Увы... Задача не решена.";
}

void main01()
/* 1) Напишите программу, вычисляющую сумму нечетных цифр целого числа.*/
{
	int valX;
	cout << "Введите число:" << endl;
	cin >> valX;
	cout << "Сумма нечетных цифр числа:" << sumNoEven(valX) << endl;
}

void main02()
/* 2) Напишите программу, вычисляющую произведение цифр целого числа, чётность которых совпадает с чётностью последней цифры.*/
{
	int valX;
	cout << "Введите число:" << endl;
	cin >> valX;
	cout << "Произведение цифр числа по четности последней цифры:" << multiDigit(valX) << endl;
}

void main03()
/* 3) Напишите программу, вычисляющую биномиальный коэффициент из n по к. В программе нельзя использовать числа, превышающие итоговое значение.*/
{
	int n, k;
	cout << "Введите числа N и K:" << endl;
	cin >> n >> k;
	if ((n < 0) or (k < 0) or (k > n)) { // плохие числа
		cout << "Биномиальный коэффициент из n по к: 0"  << endl;
	}
	else if (k == 0) {
		cout << "Биномиальный коэффициент из n по к: 1" << endl;
	}
	else {
		cout << "Биномиальный коэффициент из n по к: " <<trianglePas(n,k) << endl; // используем треугольник Паскаля
	}
}

void main04() // задача 4
/* 4) Напишите программу, находящую сумму простых элементов массива.*/
{
	int i,iMax;
	cout << "Введите количество элементов массива:" << endl;
	cin >> iMax;
	int *ptrArr = new int[iMax];
	for (i = 0; i < iMax; i++) { ptrArr[i] = 0; }
	cout << "Введите элементы массива (по 1 в строке):" << endl;
	for (i = 0; i < iMax; i++) { cin >> ptrArr[i]; }
	cout << "Конец ввода массива. Что занесли:";
	for (i = 0; i < iMax; i++) { cout << " " << ptrArr[i]; }
	cout << endl << endl;

	cout << "Сумма простых чисел массива: " << workMassive04(ptrArr,iMax) <<endl;

	delete [] ptrArr;
}

void main05() // задача 5
/* 5) Напишите программу, заменяющую составные числа на их самые большие простые делители.*/
{
	int valX;
	cout << "Введите число:" << endl;
	cin >> valX;
	cout << "Максимальный простой делитель:" << maxSimple(valX) << endl;
}

void main06() // задача 6
/* 6) Напишите программу, выписывающую все элементы последовательности, имеющие не менее пяти делителей*/
{
	int i, iMax, cntDvd;
	cout << "Введите количество элементов последовательности:" << endl;
	cin >> iMax;
	int *ptrArr = new int[iMax];
	for (i = 0; i < iMax; i++) { ptrArr[i] = 0; }
	cout << "Введите элементы последовательности (по 1 в строке):" << endl;
	for (i = 0; i < iMax; i++) { cin >> ptrArr[i]; }
	cout << "Конец ввода последовательности. Что занесли:";
	for (i = 0; i < iMax; i++) { cout << " " << ptrArr[i]; }
	cout << endl << endl;
	cout << "Имеют не менее 5 делителей (не равных самому числу):" << endl;
	for (i = 0; i < iMax; i++) {
		cntDvd = countDivider(ptrArr[i]);
		if (cntDvd >= 5) {
			cout << ptrArr[i] <<" (" << cntDvd << ")" << endl;
		}
	}
	cout << endl;

	delete[] ptrArr;
}

void main07()  // задача 7
/* 7) Напишите программу, выписывающую все элементы последовательности, имеющие ровно семь делителей*/
{
	int i, iMax, cntDvd;
	cout << "Введите количество элементов последовательности:" << endl;
	cin >> iMax;
	int *ptrArr = new int[iMax];
	for (i = 0; i < iMax; i++) { ptrArr[i] = 0; }
	cout << "Введите элементы последовательности (по 1 в строке):" << endl;
	for (i = 0; i < iMax; i++) { cin >> ptrArr[i]; }
	cout << "Конец ввода последовательности. Что занесли:";
	for (i = 0; i < iMax; i++) { cout << " " << ptrArr[i]; }
	cout << endl << endl;
	cout << "Имеют ровно 7 делителей (не равных самому числу):" << endl;
	for (i = 0; i < iMax; i++) {
		cntDvd = countDivider(ptrArr[i]);
		if (cntDvd == 7) {
			cout << ptrArr[i] << " (" << cntDvd << ")" << endl;
		}
	}
	cout << endl;

	delete[] ptrArr;
}

void main08()  // задача 8
/* 8) Напишите две функции, находящие приближенное значение квадратного и кубического корня. В программе не должны использоваться математические библиотеки.*/
{
	int stepen;
	double X;
	cout << "Введите число (тип - вещественное) и степень корня (2 или 3):" << endl;
	cin >> X >> stepen;
	if ((stepen == 2) or (stepen == 3)) { // правильно ввели корень
		if ((stepen == 2) and (X < 0)) { // квадратный корень и отрицательное число - ошибка
			cout << endl << "Нельзя квадратный корень из отриц.числа: " << X << "  Выполнение прервано..." << endl;
			system("pause");
			return;
		}
		else {
			cout << endl << "Результат: " << methodHalfDivide(X, stepen) << endl;
		}
	}
	else {
		cout << endl << "Неправильная степень корня: " << stepen << "  Выполнение прервано..." << endl;
		system("pause");
		return;
	}
}

void main09()  // задача 9
/* Напишите программу, находящую корень функции f, если известно, что f – монотонна. Функцию f считаем не известной (т.е. она просто возвращает значение по аргументу).
Для отладки разумно использовать кубическую функцию.*/
{

	cout << endl << "Результат (корень функции): " << methodHalfDivMonoBB() << endl;

}

void main10() // задача 10
/* 10) Напишите процедуру, удаляющую из динамически выделенного массива все четные значения (функция принимает в качестве аргументов – указатель на массив и его размер).
По окончании работы процедуры количество выделенной памяти должно уменьшиться.*/
{
	int i, iMax;
	int *ptrNewArr;
	cout << "Введите количество элементов массива:" << endl;
	cin >> iMax;
	int *ptrArr = new int[iMax];
	for (i = 0; i < iMax; i++) { ptrArr[i] = 0; }
	cout << "Введите элементы массива (по 1 в строке):" << endl;
	for (i = 0; i < iMax; i++) { cin >> ptrArr[i]; }
	cout << "Конец ввода массива. Что занесли:";
	for (i = 0; i < iMax; i++) { cout << " " << ptrArr[i]; }
	cout << endl << endl;
	// передаем в функцию не значение числа элементов в исходном массиве, а ссылку чтоб в функии можно было изменить на новое число элементов
	ptrNewArr=workMassive10(ptrArr, &iMax); // указатель на новый массив
	delete[] ptrArr; // удаляем исходный массив

	cout << "Что получилось:" << endl;
	for (i = 0; i < iMax; i++) { cout << " " << ptrNewArr[i]; }
	cout << endl << endl;

	delete[] ptrNewArr;
}

void main11() // задача 11
/* 11) Напишите процедуру, удаляющую из динамически выделенного массива максимальный и минимальный элементы (если таковых несколько – удалить нужно все).
По окончании работы процедуры количество выделенной памяти должно уменьшиться.*/
{
	int i, iMax;
	int *ptrNewArr;
	cout << "Введите количество элементов массива:" << endl;
	cin >> iMax;
	int *ptrArr = new int[iMax];
	for (i = 0; i < iMax; i++) { ptrArr[i] = 0; }
	cout << "Введите элементы массива (по 1 в строке):" << endl;
	for (i = 0; i < iMax; i++) { cin >> ptrArr[i]; }
	cout << "Конец ввода массива. Что занесли:";
	for (i = 0; i < iMax; i++) { cout << " " << ptrArr[i]; }
	cout << endl << endl;
	// передаем в функцию не значение числа элементов в исходном массиве, а ссылку чтоб в функии можно было изменить на новое число элементов
	ptrNewArr = workMassive11(ptrArr, &iMax); // указатель на новый массив
	delete[] ptrArr; // удаляем исходный массив

	cout << "Что получилось:" << endl;
	for (i = 0; i < iMax; i++) { cout << " " << ptrNewArr[i]; }
	cout << endl << endl;
}

void main12() // задача 12
/* 12) Напишите процедуру, дописывающую к каждому элементу динамически выделенного массива справа его квадрат.({1,2,3,4}->{1,1,2,4,3,9,4,16}).
По окончании работы процедуры количество выделенной памяти должно увеличиться.*/
{
	int i, iMax;
	int *ptrNewArr;
	cout << "Введите количество элементов массива:" << endl;
	cin >> iMax;
	int *ptrArr = new int[iMax];
	for (i = 0; i < iMax; i++) { ptrArr[i] = 0; }
	cout << "Введите элементы массива (по 1 в строке):" << endl;
	for (i = 0; i < iMax; i++) { cin >> ptrArr[i]; }
	cout << "Конец ввода массива. Что занесли:";
	for (i = 0; i < iMax; i++) { cout << " " << ptrArr[i]; }
	cout << endl << endl;
	// передаем в функцию не значение числа элементов в исходном массиве, а ссылку чтоб в функии можно было изменить на новое число элементов
	ptrNewArr = workMassive12(ptrArr, &iMax); // указатель на новый массив
	delete[] ptrArr; // удаляем исходный массив

	cout << "Что получилось:" << endl;
	for (i = 0; i < iMax; i++) { cout << " " << ptrNewArr[i]; }
	cout << endl << endl;

	delete[] ptrNewArr;
}

void main13() // задача 13
/* 13) Напишите процедуру, проводящую сжатие символьного динамически выделенного массива. Несколько подряд идущих одинаковых букв должны заменяться на их количество и саму букву.
Например, строка “aaabcccccdd” должна перейти в “3a1b5c2d”. Можно считать, что не бывает более девяти одинаковых букв, идущих подряд.*/
{
	int i, iMax=0;
	char *ptrNewArr;
	string sss;
	cout << "Введите строку (на латинице!!! на русском получим крякозябры):" <<endl;
	cin.ignore(); // очищаем буфер ввода с консоли перед считыванием строки, иначе что-то пойдет не так 
	getline(cin,sss, '\n');
	while (sss[iMax] != '\0') { iMax = iMax + 1; }
	char *ptrArr = new char[iMax];
	iMax = 0;
	while (sss[iMax] != '\0') { 
		ptrArr[iMax] = sss[iMax];
		iMax = iMax + 1; }

	cout << "Конец ввода в динамический массив. Что занесли: ";
	for (i = 0; i < iMax; i++) { cout << ptrArr[i]; }
	ptrNewArr = workMassive13(ptrArr, &iMax); // указатель на новый массив
	delete[] ptrArr; // удаляем исходный массив

	cout << endl << endl << "Что получилось:" << endl ;
	for (i = 0; i < iMax; i++) { cout << ptrNewArr[i]; }
	cout << endl << endl;

	delete[] ptrNewArr;
}

void main14() // задача 14
/* 14) Напишите процедуру, проводящую “разжатие” символьного динамически выделенного массива, сделанное в прошлой задаче. Например строка “3a1b5c2d“
должна перейти в “aaabcccccdd”. Можно считать, что не бывает более девяти одинаковых букв, идущих подряд.*/
{
	int i, nSym, iMax = 0;
	char *ptrNewArr;
	bool rezProv = true;
	string sss;
	cout << "Введите строку (на латинице!!! на русском получим крякозябры):" << endl;
	cin.ignore(); // очищаем буфер ввода с консоли перед считыванием строки, иначе что-то пойдет не так 
	getline(cin, sss, '\n');
	while (sss[iMax] != '\0') { iMax = iMax + 1; }
	char *ptrArr = new char[iMax];
	iMax = 0;
	while (sss[iMax] != '\0') {
		ptrArr[iMax] = sss[iMax];
		iMax = iMax + 1;
	}

	cout << "Конец ввода в динамический массив. Что занесли: ";
	for (i = 0; i < iMax; i++) { cout << ptrArr[i]; }
	// Проверим - а то ли там ввели, иначе результат непредсказуем
	// проверим на четность число введенных символов
	if (iMax % 2 != 0) {
		cout << endl << endl << "Нечетное число символов!!! Попытка не засчитана. Попробуйте позже..." <<endl << endl;
		system("pause");
		return;
	}
	// проверим на цифры нечетные символы, должны быть 1-9
	for (i = 0; i < iMax; i=i+2) {
		nSym= ptrArr[i]-'0';
		if ((nSym <= 0) or (nSym > 9)) { // не в диапазоне 1-9
			cout << endl << endl << "Неправильно указано число символов!!! Попытка не засчитана. Попробуйте позже..." << endl << endl;
			system("pause");
			return;
		}
	}

	// Ну если все правильно - разжимаем строку

	ptrNewArr = workMassive14(ptrArr, &iMax); // указатель на новый массив
	delete[] ptrArr; // удаляем исходный массив

	cout << endl << endl << "Что получилось:" << endl;
	for (i = 0; i < iMax; i++) { cout << ptrNewArr[i]; }
	cout << endl;

	delete[] ptrNewArr;
}

void main15()
/* 15) Напишите процедуру, заполняющую квадратный двумерный массив по диагоналям.
На побочной диагонали должны стоять наибольшие значения, на соседних с ней - на единицу меньшие, и так далее - до угла, в котором должны стоять единицы.*/
{
	int i, j, iMax, tekVal;
	int **mas;
	int *tekStroka;
	cout << "Введите размер квадратного двумерного массива:" << endl;
	cin >> iMax;
	// создаем двумерный динамический массив
	mas = new int* [iMax];
	for (i = 0; i < iMax; i++) {
		mas[i] = new int[iMax];
	}
	// заполняем массив
	for (i = 0; i < iMax; i++) {
		tekStroka = mas[i];
		for (j = 0; j < iMax; j++) {
			tekVal = (i + 1) + j;
			if (tekVal > iMax) { tekVal = iMax + (iMax - tekVal); }
			tekStroka[j] = tekVal;
		}
	}
	// выводим массив
	cout << endl;
	for (i = 0; i < iMax; i++) {
		tekStroka = mas[i];
		for (j = 0; j < iMax; j++) {
			cout << " " << tekStroka[j];
		}
		cout << endl;
	}
	// освобождаем память
	for (i = 0; i < iMax; i++) {
		delete [] mas[i];
	}
	delete[] mas;
}

void main16()
/* 16) Напишите процедуру, заполняющую квадратный двумерный массив пирамидой.*/
{
	int i, j, k, half_i,iMax;
	int **mas;
	int *tekStroka;
	cout << "Введите размер основания пирамиды (нечетное):" << endl;
	cin >> iMax;

	if (iMax % 2 == 0) {
		cout << endl << endl << "Размер должен быть нечетным!!! Попытка не засчитана. Попробуйте позже..." << endl << endl;
		system("pause");
		return;
	}
	// создаем двумерный динамический массив
	mas = new int*[iMax];
	for (i = 0; i < iMax; i++) {
		mas[i] = new int[iMax];
	}
	
	half_i = iMax / 2;
	// заполняем массив
	for (k = 0; k <= half_i; k++) {
		for (i = k; i < (iMax-k); i++) {
			tekStroka = mas[i];
			for (j = k; j < (iMax-k); j++) {
				tekStroka[j] = k+1;
			}
		}
	}
	// выводим массив
	cout << endl;
	for (i = 0; i < iMax; i++) {
		tekStroka = mas[i];
		for (j = 0; j < iMax; j++) {
			cout << " " << tekStroka[j];
		}
		cout << endl;
	}
	// освобождаем память
	for (i = 0; i < iMax; i++) {
		delete[] mas[i];
	}
	delete[] mas;
}

void main17()
/* 17) Напишите процедуру, заполняющую квадратный двумерный массив последовательными числами змейкой против часовой стрелки, начиная с верхнего правого угла.*/
{
	int i, j, k, half_i, iMax, tekVal;
	int **mas;
	int *tekStroka;
	cout << endl << "Введите размер квадратного двумерного массива (нечетное):" << endl;
	cin >> iMax;

	if (iMax % 2 == 0) {
		cout << endl << endl << "Размер должен быть нечетным!!! Попытка не засчитана. Попробуйте позже..." << endl << endl;
		system("pause");
		return;
	}
	// создаем двумерный динамический массив
	mas = new int*[iMax];
	for (i = 0; i < iMax; i++) {
		mas[i] = new int[iMax];
	}

	for (i = 0; i < iMax; i++) {
		tekStroka = mas[i];
		for (j = 0; j < iMax; j++) {
			tekStroka[j] = 0;
		}
	}


	/* представим квадрат как пирамиду и будем делать сечения по высоте с шагом 1
	в сечении будет квадрат с уменьшающимся размером, стороны которого и будем заполнять от верхнего правого угла от начального значения
	так и получим змейку от угла к центру*/

	half_i = iMax / 2;

	tekVal = 0; 
	// заполняем массив. Но!!! без вершинки пирамиды
	for (k = 0; k < half_i; k++) {
		// верхняя сторона квадрата
		tekStroka = mas[k]; 
		for (j = (iMax - k - 1); j >= k; j--) {
			tekVal = tekVal + 1;
			tekStroka[j] = tekVal;
		}
		// левая сторона квадрата
		for (j = (k + 1); j <= (iMax - k - 2); j++) {
			tekStroka = mas[j];
			tekVal = tekVal + 1;
			tekStroka[k] = tekVal;
		}
		// нижняя сторона квадрата
		tekStroka = mas[iMax-k-1];
		for (j = k; j <= (iMax - k - 1); j++) {
			tekVal = tekVal + 1;
			tekStroka[j] = tekVal;
		}
		// правая сторона квадрата
		for (j = (iMax - k - 2); j >= (k + 1); j--) {
			tekStroka = mas[j];
			tekVal = tekVal + 1;
			tekStroka[iMax - k - 1] = tekVal;
		}
	}
	// а теперь вершинка пирамиды
	tekStroka = mas[half_i];
	tekVal = tekVal + 1;
	tekStroka[half_i] = tekVal;

	// выводим массив
	cout << endl;
	for (i = 0; i < iMax; i++) {
		tekStroka = mas[i];
		for (j = 0; j < iMax; j++) {
			if (tekStroka[j] <= 9) { cout << "  " << tekStroka[j]; } // лишний пробел для чисел меньше 9
			else { cout << " " << tekStroka[j]; }
		}
		cout << endl;
	}
	// освобождаем память
	for (i = 0; i < iMax; i++) {
		delete[] mas[i];
	}
	delete[] mas;
}

void main18() // задача 18
/* 18) Напишите логическую функцию, проверяющую, является строка палиндромом. Можно считать, что строка состоит только из букв латиницы.*/

// ЗАМЕЧАНИЕ: Подавляются ТОЛЬКО пробелы. Точки, тире и т.п. - нет, поэтому они влияют на результат
{
	int i, iMax;
	string sss;
	cout << endl << "Введите строку (на латинице!!! на русском получим крякозябры):" << endl;
	cin.ignore(); // очищаем буфер ввода с консоли перед считыванием строки, иначе что-то пойдет не так 
	getline(cin, sss, '\n');
	// определяем длину дин.массива
	iMax = 0;
	i = 0;
	while (sss[i] != '\0') {
		if (sss[i] != ' ') { // убираем пробелы
			iMax = iMax + 1;
		}
		i = i + 1;
	}
	
	char *ptrArr = new char[iMax];
	// заносим символы в массив
	iMax = 0;
	i = 0;
	while (sss[i] != '\0') {
		if (sss[i] != ' ') { // убираем пробелы
			ptrArr[iMax] = tolower(sss[i]); // приводим все в нижний регистр чтоб корректно сравнивать
			iMax = iMax + 1;
		}
		i = i + 1;
	}

	cout << "Конец ввода в динамический массив. Что занесли: ";
	for (i = 0; i < iMax; i++) { cout << ptrArr[i]; }
	
	if (isPalindrom(ptrArr, iMax)) { cout << endl << endl << "Что получилось: - это палиндром" << endl; }
	else { cout << endl << endl << "Что получилось: - это НЕ палиндром" << endl; }

	delete[] ptrArr; // удаляем исходный массив
}

void main19() // задача 19
/* 19) Напишите логическую функцию, проверяющую, является ли одна строка анаграммой другой строки (т.е. может быть получена перестановкой букв).
Можно считать, что строка состоит только из букв латиницы.*/

// ЗАМЕЧАНИЕ: Подавляются ТОЛЬКО пробелы. Точки, тире и т.п. - нет, поэтому они влияют на результат
{
	int i, iMax1=0, iMax2=0;
	string ss1,ss2;
	cin.ignore(); // очищаем буфер ввода с консоли перед считыванием строки, иначе что-то пойдет не так 

	cout << endl << "Введите строку 1 (на латинице!!! на русском получим крякозябры):" << endl;
	getline(cin, ss1, '\n');
	// определяем длину дин.массива
	iMax1 = 0;
	i = 0;
	while (ss1[i] != '\0') {
		if (ss1[i] != ' ') { // убираем пробелы
			iMax1 = iMax1 + 1;
		}
		i = i + 1;
	}

	char *ptrArr1 = new char[iMax1];

	iMax1 = 0;
	i = 0;
	while (ss1[i] != '\0') {
		if (ss1[i] != ' ') { // убираем пробелы
			ptrArr1[iMax1] = tolower(ss1[i]); // приводим все в нижний регистр чтоб корректно сравнивать
			iMax1 = iMax1 + 1;
		}
		i = i + 1;
	}
	
	cout <<endl << endl << "Введите строку 2 (на латинице!!! на русском получим крякозябры):" << endl;
	getline(cin, ss2, '\n');
	// определяем длину дин.массива
	iMax2 = 0;
	i = 0;
	while (ss2[i] != '\0') {
		if (ss2[i] != ' ') { // убираем пробелы
			iMax2 = iMax2 + 1;
		}
		i = i + 1;
	}
	
	char *ptrArr2 = new char[iMax2];
	i = 0;
	iMax2 = 0;
	while (ss2[i] != '\0') {
		if (ss2[i] != ' ') { // убираем пробелы
			ptrArr2[iMax2] = tolower(ss2[i]); // приводим все в нижний регистр чтоб корректно сравнивать
			iMax2 = iMax2 + 1;
		}
		i = i + 1;
	}

	cout << "Конец ввода в динамический массив. Что занесли: " <<endl;
	for (i = 0; i < iMax1; i++) { cout << ptrArr1[i]; }
	cout << endl;
	for (i = 0; i < iMax2; i++) { cout << ptrArr2[i]; }
	cout << endl;

	if (isAnogram(ptrArr1, iMax1, ptrArr2, iMax2)) { cout << endl << "Что получилось: - это анограмма" << endl; }
	else { cout << endl << "Что получилось: - это НЕ анограмма" << endl; }

	delete [] ptrArr1; // удаляем исходный массив
	delete [] ptrArr2; // удаляем исходный массив
}

void main20() // задача 20
/* Напишите процедуру, удаляющую из динамически выделенной строки лишние пробелы. Не лишними считаются одиночные пробелы, разделяющие пару слов.
По окончании работы процедуры количество выделенной памяти должно увеличиться.*/
{
	int i, iMax = 0;
	char *ptrNewArr;
	string sss;
	cout << endl << "Введите строку (на латинице!!! на русском получим крякозябры):" << endl;
	cin.ignore(); // очищаем буфер ввода с консоли перед считыванием строки, иначе что-то пойдет не так 
	getline(cin, sss, '\n');
	while (sss[iMax] != '\0') { iMax = iMax + 1; }
	char *ptrArr = new char[iMax];
	iMax = 0;
	while (sss[iMax] != '\0') {
		ptrArr[iMax] = sss[iMax];
		iMax = iMax + 1;
	}

	cout << "Конец ввода в динамический массив. Что занесли: ";
	for (i = 0; i < iMax; i++) { cout << ptrArr[i]; }
	ptrNewArr = workMassive20(ptrArr, &iMax); // указатель на новый массив
	delete[] ptrArr; // удаляем исходный массив

	cout << endl << endl << "Что получилось:" << endl;
	for (i = 0; i < iMax; i++) { cout << ptrNewArr[i]; }
	cout << endl << endl;

	delete[] ptrNewArr;
}

int main()
{
	int zadanie;
	bool ziklZadach = true;
	setlocale(LC_ALL, "Rus"); // русифицируем вывод
	while (ziklZadach) {
		cout << endl << "ИНФО: сделаны задачи 1-20 (20 штук)" << endl;
		cout << endl << "Введите номер задачи (911 - для выхода из цикла выбора задач):" << endl;
		cin >> zadanie;

		switch (zadanie)
		{
		case 1:
		{
			cout << "Напишите программу, вычисляющую сумму нечетных цифр целого числа." << endl << endl;
			main01(); break; }
		case 2:
		{
			cout << "Напишите программу, вычисляющую произведение цифр целого числа, чётность которых совпадает с чётностью последней цифры." << endl << endl;
			main02(); break; }
		case 3:
		{
			cout << "Напишите программу, вычисляющую биномиальный коэффициент из n по к." << endl;
			cout << "В программе нельзя использовать числа, превышающие итоговое значение." << endl;
			main03(); break; }
		case 4:
		{
			cout << "Напишите программу, находящую сумму простых элементов массива." << endl << endl;
			main04(); break; }
		case 5:
		{
			cout << "Напишите программу, заменяющую составные числа на их самые большие простые делители." << endl << endl;
			main05(); break; }
		case 6:
		{
			cout << "Напишите программу, выписывающую все элементы последовательности, имеющие не менее пяти делителей." << endl << endl;
			main06(); break; }
		case 7:
		{
			cout << "Напишите программу, выписывающую все элементы последовательности, имеющие ровно семь делителей." << endl << endl;
			main07(); break; }
		case 8:
		{
			cout << "Напишите две функции, находящие приближенное значение квадратного и кубического корня." << endl;
			cout << "В программе не должны использоваться математические библиотеки." << endl << endl;
			main08(); break; }
		case 9:
		{
			cout << "Напишите программу, находящую корень функции f, если известно, что f – монотонна." << endl;
			cout << "Функцию f считаем не известной (т.е. она просто возвращает значение по аргументу)." << endl;
			cout << "Для отладки взято: y = x ^ 3 + 3x ^ 2 + 8x + 17 + 0.97*exp(x)" << endl << endl;
			main09(); break; }
		case 10:
		{
			cout << "Напишите процедуру, удаляющую из динамически выделенного массива все четные значения (функция принимает в качестве аргументов – указатель на массив и его размер)." << endl;
			cout << "По окончании работы процедуры количество выделенной памяти должно уменьшиться." << endl << endl;
			main10(); break; }
		case 11:
		{
			cout << "Напишите процедуру, удаляющую из динамически выделенного массива максимальный и минимальный элементы (если таковых несколько – удалить нужно все)." << endl;
			cout << "По окончании работы процедуры количество выделенной памяти должно уменьшиться." << endl << endl;
			main11(); break; }
		case 12:
		{
			cout << "Напишите процедуру, дописывающую к каждому элементу динамически выделенного массива справа его квадрат.({1,2,3,4}->{1,1,2,4,3,9,4,16})." << endl;
			cout << "По окончании работы процедуры количество выделенной памяти должно увеличиться." << endl << endl;
			main12(); break; }
		case 13:
		{
			cout << "Напишите процедуру, проводящую сжатие символьного динамически выделенного массива." << endl;
			cout << "Несколько подряд идущих одинаковых букв должны заменяться на их количество и саму букву. Например, строка 'aaabcccccdd' должна перейти в '3a1b5c2d'." << endl;
			cout << "Можно считать, что не бывает более девяти одинаковых букв, идущих подряд." << endl << endl;
			main13(); break; }
		case 14:
		{
			cout << "Напишите процедуру, проводящую “разжатие” символьного динамически выделенного массива, сделанное в прошлой задаче." << endl;
			cout << "Например строка '3a1b5c2d'	должна перейти в 'aaabcccccdd'." << endl;
			cout << "Можно считать, что не бывает более девяти одинаковых букв, идущих подряд." << endl << endl;
			main14(); break; }
		case 15:
		{
			cout << "Напишите процедуру, заполняющую квадратный двумерный массив по диагоналям." << endl;
			cout << "На побочной диагонали должны стоять наибольшие значения, на соседних с ней - на единицу меньшие, и так далее - до угла, в котором должны стоять единицы." << endl;
			main15(); break; }
		case 16:
		{
			cout << "Напишите процедуру, заполняющую квадратный двумерный массив пирамидой." << endl;
			main16(); break; }
		case 17:
		{
			cout << "Напишите процедуру, заполняющую квадратный двумерный массив последовательными числами змейкой" << endl;
			cout <<	"против часовой стрелки, начиная с верхнего правого угла." << endl;
			main17(); break; }
		case 18:
		{
			cout << "Напишите логическую функцию, проверяющую, является строка палиндромом." << endl;
			cout << "Можно считать, что строка состоит только из букв латиницы." << endl;
			main18(); break; }
		case 19:
		{
			cout << "Напишите логическую функцию, проверяющую, является ли одна строка анаграммой другой строки (т.е. может быть получена перестановкой букв)." << endl;
			cout << "Можно считать, что строка состоит только из букв латиницы." << endl;
			main19(); break; }
		case 20:
		{
			cout << "Напишите процедуру, удаляющую из динамически выделенной строки лишние пробелы." << endl;
			cout << "Не лишними считаются одиночные пробелы, разделяющие пару слов." << endl;
			cout << "По окончании работы процедуры количество выделенной памяти должно увеличиться." << endl;
			main20(); break; }
		case 911:
		{
			ziklZadach = false;
			break; }
		default:
			mainNoAnswer();
		}
		cout << endl << "///" << endl;
	}

//	system("pause");

	return 0;
}
