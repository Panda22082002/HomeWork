/*�������� ��������� ��������� ����������� ����� ���� ��������� ������� ��������� ���� �� ����� �� ����� ��� �� 4 ��������
(������ � ����� ������� ����� ���������, � ������ � ������ - ���).
������������� � ������ ��������� �� �����������.*/
#include <iostream> 
using namespace std;
int main()
{
	int b, n, i, N, min;
	cin�n;
	int *A = new int[n];
	for (i = 0; i < n; i++)
	{
		cin �A[i];
		min = A[0] + A[4];
		for (b = 0; b < n - 5; b++)
		{
			for (N = b + 4; N < n; N++)
			{
				if (A[b] + A[N] < min)
					min = A[b] + A[N];
			}
		}
	}
	cout �min;
	delete[]A;
	return 0;
}