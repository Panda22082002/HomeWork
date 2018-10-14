#include <iostream> 
using namespace std;
int main() {
	int x, n;
	cin >> x >> n;
	int res = x % n;
	for (int count = 1; count < n; ++count) {
		if (res * count % n == 1) {
			cout << count;
			return 0;
		}
	}
	cout << "None";
	return 0;
