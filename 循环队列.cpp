#include <iostream>
using namespace std;

typedef struct Queue
{
	int* pBase;
	int front;
	int rear;
}QUEUE, * PQUEUE;

void init(PQUEUE q);//初始化
bool en_queue(PQUEUE q, int val);//入队
void traverse(PQUEUE q);//遍历
bool full_queue(PQUEUE q);//判满
bool out_queue(PQUEUE q);//出队
bool isEmpty(PQUEUE q, int*);//判空;

int main() {
	QUEUE q;
	PQUEUE qe = &q;
	init(qe);
	en_queue(qe, 1);
	en_queue(qe, 2);
	en_queue(qe, 3);
	en_queue(qe, 4);
	en_queue(qe, 5);
	traverse(qe);
	out_queue(qe);
	traverse(qe);
	return 0;
}

void init(PQUEUE q) {
	//pBase代表一个数组
	q->pBase = (int*)malloc(sizeof(int) * 6);
	q->front = 0;
	q->rear = 0;
}

//静态队列队尾入队 队头出队
bool en_queue(PQUEUE q, int val) {
	//判满则不能入队
	if (full_queue(q) == true) {
		return false;
	}
	else {
		q->pBase[q->rear] = val;
		//循环队列收尾相连 当rear=5时 (rear+1)%6=0
		q->rear = (q->rear + 1) % 6;
		return true;
	}
}

bool full_queue(PQUEUE q) {
	//可以看成当rear和front靠近时 队列满
	if (((q->rear) + 1) % 6 == q->front) {
		return true;
	}
	else {
		return false;
	}
}

void traverse(PQUEUE q) {
	//因为rear不存储数 所以该方法输出5个数
	int i = q->front;
	//rear不存储值 所以遍历到rear之前
	while (i != q->rear) {
		cout << q->pBase[i] << endl;
		i = (i + 1) % 6;
	}
}

bool out_queue(PQUEUE q, int* pal) {
	//静态队列不需要释放空间
	if (isEmpty(q)) {
		return false;
	}
	else
	{
		*pal = q->pBase[q->front];
		q->front = (q->front + 1) % 6;
		return true;
	}
}

bool isEmpty(PQUEUE q) {
	if (q->front == q->rear) {
		return true;
	}
	else
	{
		return false;
	}
}