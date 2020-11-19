#include <iostream>
using namespace std;

void han(int n, char A, char B, char C) {
	//如果是一个盘子 直接将a柱子上的盘子从x移到c
	//否则 将a柱子上的n-1个盘子借助c移到b 直接将a柱子上的盘子从a移到c 最后将b柱子上的n-1个盘子借助a移到c

	if (1 == n) {
		cout << "将编号为" << n << "的柱子" << "直接从" << A << "柱子" << "移到" << C << "柱子" << endl;
	}
	else
	{
		han(n - 1, A, C, B);
		cout << "将编号为" << n << "的柱子" << "直接从" << A << "柱子" << "移到" << C << "柱子" << endl;
		han(n - 1, B, A, C);
	}
}

int main() {
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	int n;

	cout << "请输入盘子个数" << endl;
	cin >> n;
	han(n, ch1, ch2, ch3);
	return 0;
}