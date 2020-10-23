#include <iostream>
using namespace std;

typedef struct ARR
{
	int* pBase;//储存数组第一个元素地址
	int len;//数组所能容纳最大元素个数
	int cnt;//当前数组有效元素个位

}* PARR , ARR;


bool append_arr(struct ARR *parry,int val);//追加
bool insert_arr(struct ARR* parry,int index,int vel);//插入 pos从1开始
bool delete_arr(struct ARR *parry,int index,int *pal);//删除
bool get_arr();//获得
bool is_aempty(struct ARR *parry);//判空 注： isempty()可能为C++内部函数使用该名称命名会报错
bool is_full(struct ARR *parry);//判满
void sort_arr(struct ARR* parry);//排序
void show_arr(struct ARR *parry);//打印
void inversion_arr(struct ARR* parry);//倒置
void init_arr(struct ARR *parray,int length);//初始化

int main() {
	ARR arr;
	PARR parr = &arr;
	init_arr(parr,6);
	int pak;
	
	
	append_arr(parr, 4);
	append_arr(parr, 3);
	append_arr(parr, 2);
	append_arr(parr, 1);
	
	show_arr(parr);
	
	cout << "--------" << endl;
	
	sort_arr(parr);
	show_arr(parr);
	cout << "--------" << endl;
	inversion_arr(parr);
	show_arr(parr);
	is_full(parr);


	return 0;
}

/*
* 如果按照这种方法，函数结束后系统即回收array的内存，所以还是垃圾地址。
void init_arr(struct ARR array) {
	array.len = 99;

}
*/


void init_arr(struct ARR *parray,int length) {
	//动态内存分配首地址 array指向数组结构的pBase成员
	parray->pBase = (int*)malloc(sizeof(int) * length);
	if (NULL == parray->pBase) {
		cout << "动态内存分配失败" << endl;
		//程序结束
		exit(-1);
	}
	else {
		parray->len = length;
		parray->cnt = 0;
	}
	//函数终止
	return ;
}


bool is_aempty(struct ARR *parry) {
	//如果有效数字为0则空
	if (0 == parry->cnt)
		return true;
	else
		return false;

}
void show_arr(struct ARR *parry)	{
	// struct Arr *parry = &arr 则parry作为指针指向arr 那么parry里面存放的是arr的地址，所用不用加取地址符，如加则表示单独的parry的地址
	if (is_aempty(parry) == true) {
		cout << "数组为空" << endl;
	}
	else {
		//因为动态内存分配后pBase作为首地址，可以将pBase当做数组名来使用 pBase=&pBase[0] *(pBase+1)=pBase[1] 也可
		for (int i = 0; i < parry->cnt;++i) {
			cout << parry->pBase[i]<<" ";
			//cout << *(parry->pBase + i) << endl;
		}
	}

	

}

bool is_full(struct ARR *parry) {
	//如果最大有效等于数组存储数字则为满
	if (parry->cnt == parry->len) {
		return true;
	}
	else {
		return false;
	}

}

/*
	pBase[0] = 1 cnt=1
	pBase[1] = 2 cnt=2
	pBase[2] = 3 cnt=3


*/

bool append_arr(struct ARR *parry, int val) {
	//满返回false
	if (is_full(parry) == true) {
		return false;
	}
	//不满时追加
	else {
		parry->pBase[parry->cnt] = val;
		(parry->cnt)++;
		return true;
	}


}


bool insert_arr(struct ARR* parry, int index, int val) {

	if (is_full(parry) == true) {
		return false;
	}
	
	if (index<1 || index>parry->len) {
		return false;
	}
	
	for (int i = parry->cnt - 1;i >= index - 1;--i) {
		parry->pBase[i + 1] = parry->pBase[i];

	}
	parry->pBase[index - 1] = val;
	
	//有效长度+1
	(parry->cnt)++;
	return true;


}

bool delete_arr(struct ARR* parry, int index,int *pal) {
	if (is_aempty(parry)) {
		return false;
	}if (index <1 || index > parry->cnt)
		return false;
	pal = parry->pBase+index-1;
	for(int i = index;i < parry->cnt;i++) {
		parry->pBase[i - 1] = parry->pBase[i];


	}
	parry->cnt--;
	return true;
}


void inversion_arr(struct ARR* parry) {
	int i = 0;
	int j = parry->cnt-1;
	int t;
	//互换
	while (i<j)
	{
		t = parry->pBase[i];
		parry->pBase[i] = parry->pBase[j];
		parry->pBase[j] = t;
		i++;
		j--;
	}
	return;

}

void sort_arr(struct ARR* parry) {
	/*
	for (int i = 0;i < parry->cnt - 1;i++) {
		for (int j = 0; j < parry->cnt- 1 - i;j++) {
		if(parry->pBase[j] > parry->pBase[j+1])
			{
				int t;
				t = parry->pBase[j];
				parry->pBase[j] = parry->pBase[j+1];
				parry->pBase[j+1] = t;
			}
		}
	}
	*/

	//选择
	for (int i = 0;i < parry->cnt - 1;i++) {
		for (int j = i + 1;j < parry->cnt;j++) {
			if (parry->pBase[i] > parry->pBase[j ]) {
				int t;
				t = parry->pBase[i];
				parry->pBase[i] = parry->pBase[j];
				parry->pBase[j] = t;

			}
		}
	}

}