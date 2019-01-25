#include <iostream>
using namespace std;
int main() {
	int X, Y, Z;
	cin >> X;
	cin >> Y;
	cin >> Z;
	int*a = new int[Y - X + 1];
	int*b = new int[Y - X + 1];
	a[0] = X;
	b[0] = 1;
	for (int n = 1; n < Y - X + 1; n++) {
		a[n] = 1 + a[n - 1];
	}
	for (int n = 1; n < Y - X + 1; n++) {
		if (a[n] == 2) {
			b[n] = 2;
		}
		if (a[n] == 3) {
			b[n] = 3;
		}
		if ((a[n] % (2 * X) != 0) && (a[n] % 10 != 0) && (a[n] % (2 * X + 1) != 0)) {
			b[n] = b[n - 1];
		}
		if ((a[n] % (2 * X) != 0) && (a[n] % (2 * X + 1) == 0) && (a[n] % (10 * X) != 0)) {
			b[n] = b[n - 1] + b[(n - 1) / 2];
		}
		if ((a[n] % (2 * X) == 0) && (a[n] % (10 * X) != 0) && (a[n] % (2 * X + 1) != 0)) {
			b[n] = b[n - 1] + b[n / 2];
		}
		if ((a[n] % (2 * X) == 0) && (a[n] % (10 * X) == 0)) {
			b[n] = b[n - 1] + b[n / 2] + b[n / 10];
		}
		if ((a[n] % (2 * X) == 0) && (a[n] % (2 * X + 1) == 0) && (a[n] % (10 * X) != 0)) {
			b[n] = b[n - 1] + b[n / 2] + b[(n - 1) / 2];
		}
		if ((a[n] % (2 * X + 1) == 0) && (a[n] % (10 * X) == 0) && (a[n] % (2 * X) != 0)) {
			b[n] = b[n - 1] + b[(n - 1) / 2] + b[n / 10];
		}
		if ((a[n] % (2 * X + 1) == 0) && (a[n] % (10 * X) == 0) && (a[n] % (2 * X) == 0)) {
			b[n] = b[n - 1] + b[(n - 1) / 2] + b[n / 10] + b[n / 2];
		}
		if ((a[n] % (2 * X + 1) != 0) && (a[n] % (10 * X) == 0) && (a[n] % (2 * X) != 0)) {
			b[n] = b[n - 1] + b[n / 10];
		}
		if (a[n] == Z) {
			b[n] = 0;
		}
	}
	cout << b[Y - X];
	system("pause");
	return 0;
}
