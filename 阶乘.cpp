#include<iostream>
using namespace std;
/*
�ݹ������Ҫ��
��ֹ�����͵��ƹ�ʽ��
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