#include <iostream>
using namespace std;
int main() {
	int X, Y;
	cin >> X;
	cin >> Y;
	int*a = new int[Y - X + 2];
	int*b = new int[Y - X + 2];
	a[0] = X - 1;
	b[0] = 0;
	b[1] = 1;
	for (int n = 1; n < Y - X + 2; n++) {
		a[n] = a[n - 1] + 1;
	}
	for (int n = 1; a[n] < Y; n++) {
		for (int n = 2; n < Y - X + 2; n++) {
			if (((a[n] - X) % 9 != 0) && (a[n] % (7 * X) != 0) && (a[n] % (X * X) != 0)) {
				b[n] = 0;
			}
			if (((a[n] - X) % 9 == 0) && (a[n] % (7 * X) != 0) && (a[n] % (X * X) != 0)) {
				b[n] = b[n - 9];
			}
			if (((a[n] - X) % 9 == 0) && (a[n] % (7 * X) == 0) && (a[n] % (X * X) != 0)) {
				b[n] = b[n - 9] + b[n / 7];
			}
			if (((a[n] - X) % 9 != 0) && (a[n] % (7 * X) == 0) && (a[n] % (X * X) == 0)) {
				b[n] = b[n / 7] + b[n / X];
			}
			if (((a[n] - X) % 9 == 0) && (a[n] % (7 * X) != 0) && (a[n] % (X * X) == 0)) {
				b[n] = b[n - 9] + b[n / X];
			}
			if (((a[n] - X) % 9 != 0) && (a[n] % (7 * X) != 0) && (a[n] % (X * X) == 0)) {
				b[n] = b[n / X];
			}
			if (((a[n] - X) % 9 != 0) && (a[n] % (7 * X) == 0) && (a[n] % (X * X) != 0)) {
				b[n] = b[n / 7];
			}
			if (((a[n] - X) % 9 == 0) && (a[n] % (7 * X) == 0) && (a[n] % (X * X) == 0)) {
				b[n] = b[n - 9] + b[n / 7] + b[n / X];
			}
		}
		if (b[Y - X + 1] >= 1) {
			break;
		}
		a[n] = a[n] * 10 + 1;
	}
	if (b[Y - X + 1] >= 1) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	system("pause");
	return 0;
}
