#include <iostream> 
using namespace std;
int gcd(int a, int b) {
	int m, k = 0;
	if (a > b)m = b;
	else m = a;
	for (int i = m; i > 0; i--) {
		if ((a%i == 0) && (b%i == 0)) {
			k = i;
			break;
		}
	}
	return k;
}
struct rational {
	int n;
	int m;
};
rational operator~(rational x) {
	for (int i = 2; i < (x.m); i++) {
		if ((x.n%i == 0) && (x.m%i == 0)) {
			x.n = (x.n) / i;
			x.m = (x.m) / i;
		}
	}
	return x;
}
rational operator*(rational x, rational y) {
	x.n = x.n*y.n;
	x.m = x.m*y.m;
	return x;
}
rational operator/(rational x, rational y) {
	x.n = x.n*y.m;
	x.m = x.m*y.n;
	return x;
}
rational operator+(rational x, rational y) {
	if (x.m == y.m) {
		x.n = x.n + y.n;
		x.m = x.m;
	}
	else {
		x.n = (x.n*y.m) + (y.n*x.m);
		x.m = x.m*y.m;
	}
	return x;
}
rational operator-(rational x, rational y) {
	if (x.m == y.m) {
		x.n = x.n - y.n;
		x.m = x.m;
	}
	else {
		x.n = (x.n*y.m) - (y.n*x.m);
		x.m = x.m*y.m;
	}
	return x;
}
bool operator==(rational x, rational y) {
	if (x.m == y.m)return(x.n == y.n);
	else {
		x.n = x.n*y.m;
		x.m = x.m*y.m;
		y.n = y.n*x.m;
		y.m = y.m*x.m;
		return (x.n == y.n);
	}
}
bool operator>(rational x, rational y) {
	if (x.m == y.m)return(x.n > y.n);
	else {
		x.n = x.n*y.m;
		x.m = x.m*y.m;
		y.n = y.n*x.m;
		y.m = y.m*x.m;
		return (x.n > y.n);
	}
}
bool operator>=(rational x, rational y) {
	if (x.m == y.m)return(x.n >= y.n);
	else {
		x.n = x.n*int(y.m);
		x.m = x.m*y.m;
		y.n = y.n*int(x.m);
		y.m = y.m*x.m;
		return (x.n >= y.n);
	}
}
bool operator<=(rational x, rational y) {
	if (x.m == y.m)return(x.n <= y.n);
	else {
		x.n = x.n*int(y.m);
		x.m = x.m*y.m;
		y.n = y.n*int(x.m);
		y.m = y.m*x.m;
		return (x.n <= y.n);
	}
}
bool operator<(rational x, rational y) {
	if (x.m == y.m)return(x.n < y.n);
	else {
		x.n = x.n*int(y.m);
		x.m = x.m*y.m;
		y.n = y.n*int(x.m);
		y.m = y.m*x.m;
		return (x.n < y.n);
	}
}
void print(rational z) {
	rational x = ~(z);
	cout << x.n << "/" << x.m;
}
void enter(rational x) {
	cin >> x.n >> x.m;
}
int main()
{
	rational l;
	enter(l);
	cout << gcd(l.n, l.m) << endl;
	print(l);
	return 0;
}
