#include <iostream>
using namespace std;
class double_vector {
private:
	double*data;
	unsigned int size;
	unsigned int capacity;
public:
	double_vector() {
		data = new double[1];
		capacity = 1;
		size = 0;
		data[0] = 0;
	}
	double_vector(unsigned int N) {
		data = new double[N];
		capacity = N;
		size = 0;
		for (int i = 0; i < N; i++) {
			data[i] = 0;
		}
	}
	double_vector(double*a, unsigned int b) {
		delete[] data;
		capacity = b;
		size = b;
		data = a;
	}
	double_vector(const double_vector& A) {
		double*Vec = new double[A.capacity];
		for (int i = 0; i < A.capacity; i++) {
			Vec[i] = 0;
		}
		for (int i = 0; i < A.size; i++) {
			Vec[i] = A.data[i];
		}
		capacity = A.capacity;
		size = A.size;
		data = Vec;
	}
	const double_vector& operator=(const double_vector& A) {
		double*Vec = new double[A.capacity];
		for (int i = 0; i < A.capacity; i++) {
			Vec[i] = 0;
		}
		for (int i = 0; i < A.size; i++) {
			Vec[i] = A.data[i];
		}
		capacity = A.capacity;
		size = A.size;
		delete[] data;
		data = Vec;
		return *this;
	}
	double operator[](unsigned int n) {
		return data[n - 1];
	}
	void push_back(int x) {
		if (size >= capacity) {
			capacity *= 2;
			double* temp = new double[capacity];
			for (int i = 0; i < capacity; i++) {
				temp[i] = 0;
			}
			for (int i = 0; i < size; i++) {
				temp[i] = data[i];
			}
			delete[] data;
			data = temp;
		}
		data[size] = x;
		size++;
	}
	double pop_back() {
		double m;
		m = data[size];
		data[size] = 0;
		size--;
		return m;
	}
	unsigned int get_size() {
		unsigned int a = size;
		return a;
	}
	unsigned int get_capacity() {
		unsigned int a = capacity;
		return a;
	}
	void resize(unsigned int N) {
		if (N > 0) {
			capacity = capacity + N;
			double* temp = new double[capacity];
			for (int i = 0; i < capacity; i++) {
				temp[i] = 0;
			}
			for (int i = 0; i < size; i++) {
				temp[i] = data[i];
			}
			delete[] data;
			data = temp;
		}
		if (N < 0) {
			if (capacity - size >= N) {
				capacity = capacity + N;
			}
			else {
				int a = N - capacity + size;
				capacity = size;
			}
			double*temp = new double[capacity];
			for (int i = 0; i < size; i++) {
				temp[i] = data[i];
			}
			delete[] data;
			data = temp;
		}
	}
	void push_front(double a) {
		if (size >= capacity) {
			capacity *= 2;
			double*temp = new double[capacity];
			for (int i = 0; i < capacity; i++) {
				temp[i] = 0;
			}
			temp[0] = a;
			for (int i = 1; i <= size; i++) {
				temp[i] = data[i - 1];
			}
			delete[] data;
			data = temp;
		}
		for (int i = size; i > 0; i--) {
			data[i] = data[i - 1];
		}
		data[0] = a;
		size++;
	}
	double pop_front() {
		double a;
		a = data[0];
		for (int i = 0; i < size - 1; i++) {
			data[i] = data[i + 1];
		}
		size--;
		return a;
	}
	void insert(double a, unsigned int n) {
		int x = 0;
		if (n <= size && x != 1) {
			if (size >= capacity) {
				capacity *= 2;
				double*temp = new double[capacity];
				for (int i = 0; i < capacity; i++) {
					temp[i] = 0;
				}
				temp[n - 1] = a;
				for (int i = 0; i < n - 1; i++) {
					temp[i] = data[i];
				}
				for (int i = n; i <= size; i++) {
					temp[i] = data[i - 1];
				}
				delete[] data;
				data = temp;
			}
			for (int i = n; i <= size; i++) {
				data[i] = data[i - 1];
			}
			data[n - 1] = a;
			x = 1;
			size+= 1;
		}
		if (n > capacity && x != 1) {
			capacity = n * 2;
			double*temp = new double[capacity];
			for (int i = 0; i < capacity; i++) {
				temp[i] = 0;
			}
			temp[n - 1] = a;
			for (int i = 0; i < size; i++) {
				temp[i] = data[i];
			}
			delete[] data;
			data = temp;
			size = n;
			x = 1;
		}
		if (n <= capacity && n > size && x != 1) {
			size = n;
			data[n - 1] = a;
			x = 1;
		}
	}
	double erase(unsigned int n) {
		double a;
		if (n <= size) {
			a = data[n - 1];
			for (int i = n - 1; i < size - 1; i++) {
				data[i] = data[i + 1];
			}
			size--;
		}
		return a;
	}
	void erase_ab(unsigned int a, unsigned int b) {
		int x = 0;
		if (a > b) {
			int temp = a;
			a = b;
			b = temp;
		}
		if (b <= size && x != 1) {
			int m = 0;
			for (int i = 0; i < size - b + 1; i++) {
				cout << data[a - 1 + i] << endl;
				data[a - 1 + i] = data[b - 1 + i];
				m++;
			}
			for (int i = size - 1 - m; i < size; i++) {
				data[i] = 0;
			}
			size = size - m - 1;
			x = 1;
		}
		if (a <= size && b > size && x != 1) {
			int p = 0;
			for (int i = a - 1; i < size; i++) {
				cout << " " << data[i];
				data[i] = 0;
				p++;
			}
			size = size - p;
			x = 1;
		}
	}
	double_vector operator+(double_vector A) {
		double*Vec = new double[capacity + A.capacity];
		for (int i = 0; i < capacity + A.capacity; i++) {
			Vec[i] = 0;
		}
		for (int i = 0; i < size; i++) {
			Vec[i] = A.data[i];
		}
		for (int i = size; i < size + A.size; i++) {
			Vec[i] = A.data[i - size];
		}
		capacity = capacity + A.capacity;
		size = size + A.size;
		delete[] data;
		data = Vec;
		return *this;
	}
	void find(double x) {
		int x = 0;
		for (int i = 0; i < size; i++) {
			if (data[i] == x) {
				x = 1;
				cout << "I finded it";
			}
		}
		if (x == 0) {
			cout << "I didn't find it";
		}
	}
	void print(unsigned int n) {
		cout << data[n - 1];
	}
	~double_vector() {
		delete[] data;
	}
	bool is_sort(bool b) {
		for (int i = 0; i < size; i++) {
			if (data[i] > data[i + 1]) {
				b = false;
				break;
			}
		}
		else b = true;
	}
	void qsort(int*A, int m, int n) {
		int m = 0;
		int n = size - 1;
		int x = A[(n + m) / 2];
		while (m <= n) {
			while (A[m] < x) m++;
			while (A[n] > x) n--;
			if (m <= n) swap(A[m]; A[n]);
		}
	}
	int Bin_Search(int*a, int key) {
		for (int i = 0; i < size; i++) {
			if (data[i] > data[i + 1]) {
				b = false;
				break;
			}
		}
		else {
		b = true;
		int left = 0; right = size - 1; mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (key < a[mid]) right = mid - 1;
			else if (key > a[mid]) left = mid + 1;
			else return mid;
		}
		return -1;
		}
	}
};
