#include <iostream>
using namespace std;
/*
���õݹ�����쳲���˹����

*/

int fei(int n) {
	//�ݹ���ֹ����
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
	cout << "������ڼ�����" << endl;
	int n;
	cin >> n;
	cout << fei(n) << endl;
	for (int i = 1; i < 6; i++) {
		cout << fei(i) << endl;
	}
	return 0;
}