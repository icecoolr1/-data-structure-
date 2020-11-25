#include<iostream>
using namespace std;
/*
递归的两个要素
终止条件和递推公式。
*/
long f(long n) {
	if (1 == n) {
		return 1;
	}
	else {
		return f(n - 1) * n;
	}
}

int main() {
	cout << f(10) << endl;
	return 0;
}