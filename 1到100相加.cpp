#include<iostream>
using namespace std;

long add(long n) {
	if (n == 1) {
		return 1;
	}
	else {
		return add(n - 1) + n;
	}
}

int main() {
	cout << add(100);
	return 0;
}