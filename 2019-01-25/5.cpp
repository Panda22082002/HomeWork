#include <iostream>
using namespace std;
int main() {
	int X;
	cin >> X;
	int Y;
	cin >> Y;
	int k, m;
	int*a = new int[X - Y + 1];
	int*b = new int[X - Y + 1];
	for (int i = 0; i < X - Y + 1; i++) {
		a[i] = 0;
	}
	for (int i = 0; i <= X - Y; i++) {
		b[i] = 0;
	}
	for (int i = 0; i < X - Y + 1; i++) {
		m = 0;
		k = 0;
		if (i - 1 >= 0) {
			k = a[i - 1] + 1;
			m = 1;
		}
		if (i - 4 >= 0) {
			if (k > a[i - 4] + 1) {
				k = a[i - 4] + 1;
				m = 2;
			}
		}
		if (i - 5 >= 0) {
			if (k > a[i - 5] + 1) {
				k = a[i - 5] + 1;
				m = 3;
			}
		}
		if (((i + Y) % 2 == 0) && ((i + Y) / 2 >= Y)) {
			if (k > a[(i + Y) / 2 - Y] + 1) {
				k = a[(i + Y) / 2 - Y] + 1;
				m = 4;
			}
		}
		a[i] = k;
		b[i] = m;
	}
	for (int i = X - Y; i > 0; i -= 1) {
		cout << b[i] << " ";
		if (b[i] == 4) {
			i = ((i + Y) / 2) - Y + 1;
			continue;
		}
		if (b[i] == 3) {
			i = i - 4;
			continue;
		}
		if (b[i] == 2) {
			i = i - 3;
			continue;
		}
		if (b[i] == 1) {
			i = i;
			continue;
		}
	}
	cout << a[X - Y];
	return 0;
}
