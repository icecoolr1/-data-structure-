#include<iostream>
using namespace std;

/*
队列先进先出
front负责出
rear负责进

*/

/*
遇到的问题:
1:Node 和 Quene在编写过程中有混淆 新建结点应该是pNode
2:enhQuene方法没有按注释写最后一步
3:front储存没有实际的数据域 所以遍历时要从front->pnext开始

*/

typedef struct Node
{
	int date;//数据域
	struct Node* pNext;//指针域
}NODE, * PNODE;

typedef struct LQueue
{
	PNODE front;//队首结点指针
	PNODE rear;//队尾结点指针
}QUENE, * PQUENE;

void init(PQUENE p);//初始化
bool isEmpty(PQUENE p);//判空
void outQuene(PQUENE p);//出队
void enhQuene(PQUENE p, int t);//入队
void travser(PQUENE p);//遍历输出

int main() {
	QUENE qnode;
	PQUENE p = &qnode;
	init(p);
	enhQuene(p, 1);
	enhQuene(p, 2);
	enhQuene(p, 3);
	enhQuene(p, 4);
	travser(p);
	cout << "-----" << endl;
	outQuene(p);
	travser(p);
	return 0;
}

void init(PQUENE p) {
	//初始化头结点和尾结点在同一个新结点，并将头结点或尾结点指针域设为空
	p->front = (PNODE)malloc(sizeof(Node));
	if (p->front == NULL) {
		cout << "创建节点失败!" << endl;
		exit(-1);
	}
	p->rear = p->front;
	p->front->pNext = NULL;
}

bool isEmpty(PQUENE p) {
	//判断头节点和尾节点地址是否相同
	if (p->front == p->rear) {
		return true;
	}
	else {
		return false;
	}
}

void enhQuene(PQUENE p, int t) {
	//初始化一个新的节点pNew 将值T赋给pnew的数据域 将 rear的指针域指向pNew pnew的指针域指向NULL 将pNew赋给rear
	PNODE pNew = (PNODE)malloc(sizeof(Node));
	if (pNew == NULL) {
		cout << "创建节点失败!" << endl;
		exit(-1);
	}
	pNew->date = t;
	p->rear->pNext = pNew;
	pNew->pNext = NULL;
	p->rear = pNew;
}

//一开始将此方法完全类比为栈的出栈方法 后经过研究 栈的出栈和队的出栈有差别 因为栈顶是储存有意义的值的
//而队首则只存储指针域 所以应将队首的下一个结点释放 而不是单纯地删除头指针

//void outQuene(PQUENE p) {
//	//将front的下一个结点的地址赋给front  free ptem
//	PNODE ptem;
//	ptem = p->front;
//	p->front = p->front->pNext;
//	free(ptem);
//	ptem = NULL;
//}

void outQuene(PQUENE p) {
	//将Front的首结点指向首结点的下一个结点 free首结点
	PNODE ptem = p->front->pNext;
	p->front->pNext = ptem->pNext;
	//如果只有一个元素 除头结点外
	if (ptem == p->rear) {
		p->rear = p->front;
	}
	free(ptem);
	ptem = NULL;
}
void travser(PQUENE p) {
	PNODE ptem = p->front->pNext;
	while (ptem) {
		cout << ptem->date << " ";
		ptem = ptem->pNext;
	}
}