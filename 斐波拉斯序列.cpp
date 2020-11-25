#include <iostream>
using namespace std;
/*
运用递归生成斐波拉斯序列

*/

int fei(int n) {
	//递归终止条件
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 1;
	}
	else {
		return fei(n - 2) + fei(n - 1);
	}
}

int main() {
	cout << "请输入第几个数" << endl;
	int n;
	cin >> n;
	cout << fei(n) << endl;
	for (int i = 1; i < 6; i++) {
		cout << fei(i) << endl;
	}
	return 0;
}