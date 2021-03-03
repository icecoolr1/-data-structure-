#include <iostream>
using namespace std;

/*
	链栈
*/

typedef struct NODE {
	int data;
	struct NODE* pNext;
}*PNODE, NODE;

typedef struct  Stack
{
	PNODE pTop;
	//pBottom可以看成链表的首指针
	PNODE pBottom;
}STACK, * PSTACK;

void initStack(PSTACK p);//初始化方法
void push(PSTACK p, int val);//压栈
void traverse(PSTACK p);//遍历
bool pop(PSTACK p);//出栈
bool empty(PSTACK p);//判空
void clear(PSTACK p);//清空

int main() {
	Stack s;
	PSTACK ps = &s;
	initStack(ps);
	push(ps, 1);
	push(ps, 2);
	push(ps, 3);
	traverse(ps);
	cout << "-----" << endl;
	pop(ps);
	traverse(ps);
	cout << "-----" << endl;
	clear(ps);
	traverse(ps);
}

void initStack(PSTACK p) {
	//让ptop与pBOttom同时指向没有意义的头结点
	p->pTop = (PNODE)malloc(sizeof(NODE));
	if (NULL == p->pTop) {
		exit(-1);
	}
	else {
		p->pBottom = p->pTop;
		//把ptop的指针域清空 因为头结点 初始化应将指针域清空
		p->pTop->pNext = NULL;
	}
}

void push(PSTACK p, int val) {
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pNew) {
		exit(-1);
	}
	//数据域赋值
	pNew->data = val;
	pNew->pNext = p->pTop;
	p->pTop = pNew;
}

void traverse(PSTACK p)
{
	//p指向栈顶元素
	PNODE ps = p->pTop;
	while (ps != p->pBottom)
	{
		cout << ps->data << "";
		cout << endl;
		ps = ps->pNext;
	}
	return;
}

bool pop(PSTACK p) {
	if (empty(p)) {
		return false;
	}
	else {
		PNODE pnew = p->pTop;
		p->pTop = p->pTop->pNext;
		free(pnew);
		pnew = NULL;
		return true;
	}
}

bool empty(PSTACK p) {
	if (p->pBottom == p->pTop) {
		return true;
	}
	else {
		return false;
	}
}

void clear(PSTACK ps) {
	PNODE p = ps->pTop;
	PNODE q = NULL;
	while (p != ps->pBottom) {
		/*q = p->pNext;
		free(p);
		p = q;*/

		q = p;
		p = p->pNext;
		free(q);
	}
}
