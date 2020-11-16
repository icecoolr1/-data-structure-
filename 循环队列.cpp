#include <iostream>
using namespace std;

typedef struct Queue
{
	int* pBase;
	int front;
	int rear;
}QUEUE, * PQUEUE;

void init(PQUEUE q);//��ʼ��
bool en_queue(PQUEUE q, int val);//���
void traverse(PQUEUE q);//����
bool full_queue(PQUEUE q);//����
bool out_queue(PQUEUE q);//����
bool isEmpty(PQUEUE q, int*);//�п�;

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
	//pBase����һ������
	q->pBase = (int*)malloc(sizeof(int) * 6);
	q->front = 0;
	q->rear = 0;
}

//��̬���ж�β��� ��ͷ����
bool en_queue(PQUEUE q, int val) {
	//�����������
	if (full_queue(q) == true) {
		return false;
	}
	else {
		q->pBase[q->rear] = val;
		//ѭ��������β���� ��rear=5ʱ (rear+1)%6=0
		q->rear = (q->rear + 1) % 6;
		return true;
	}
}

bool full_queue(PQUEUE q) {
	//���Կ��ɵ�rear��front����ʱ ������
	if (((q->rear) + 1) % 6 == q->front) {
		return true;
	}
	else {
		return false;
	}
}

void traverse(PQUEUE q) {
	//��Ϊrear���洢�� ���Ը÷������5����
	int i = q->front;
	//rear���洢ֵ ���Ա�����rear֮ǰ
	while (i != q->rear) {
		cout << q->pBase[i] << endl;
		i = (i + 1) % 6;
	}
}

bool out_queue(PQUEUE q, int* pal) {
	//��̬���в���Ҫ�ͷſռ�
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