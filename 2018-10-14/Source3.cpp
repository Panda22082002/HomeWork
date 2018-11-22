#include <iostream> 
using namespace std;
int main() {
	int n;
	cin>> n;
	cout << n << ": ";
	bool isPrime = true;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			isPrime = false;
			break;
		}
	}
	if (n == 1) {
		cout << "Unit";
	}
	else if (isPrime) {
		cout << "Prime";
	}
	else {
		cout << "Composite";
	}
	cout << endl;
	return 0;
}
