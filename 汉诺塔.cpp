#include <iostream>
using namespace std;

void han(int n, char A, char B, char C) {
	//�����һ������ ֱ�ӽ�a�����ϵ����Ӵ�x�Ƶ�c
	//���� ��a�����ϵ�n-1�����ӽ���c�Ƶ�b ֱ�ӽ�a�����ϵ����Ӵ�a�Ƶ�c ���b�����ϵ�n-1�����ӽ���a�Ƶ�c

	if (1 == n) {
		cout << "�����Ϊ" << n << "������" << "ֱ�Ӵ�" << A << "����" << "�Ƶ�" << C << "����" << endl;
	}
	else
	{
		han(n - 1, A, C, B);
		cout << "�����Ϊ" << n << "������" << "ֱ�Ӵ�" << A << "����" << "�Ƶ�" << C << "����" << endl;
		han(n - 1, B, A, C);
	}
}

int main() {
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	int n;

	cout << "���������Ӹ���" << endl;
	cin >> n;
	han(n, ch1, ch2, ch3);
	return 0;
}