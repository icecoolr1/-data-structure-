#include<iostream>
using namespace std;

/*
�����Ƚ��ȳ�
front�����
rear�����

*/

/*
����������:
1:Node �� Quene�ڱ�д�������л��� �½����Ӧ����pNode
2:push����û�а�ע��д���һ��
3:front����û��ʵ�ʵ������� ���Ա���ʱҪ��front->pnext��ʼ

*/

typedef struct Node
{
	int date;//������
	struct Node* pNext;//ָ����
}NODE, * PNODE;

typedef struct LQueue
{
	PNODE front;//���׽��ָ��
	PNODE rear;//��β���ָ��
}QUENE, * PQUENE;

void init(PQUENE p);//��ʼ��
bool isEmpty(PQUENE p);//�п�
void pop(PQUENE p);//����
void push(PQUENE p, int t);//���
void travser(PQUENE p);//�������

int main() {
	QUENE qnode;
	PQUENE p = &qnode;
	init(p);
	push(p, 1);
	push(p, 2);
	push(p, 3);
	push(p, 4);
	travser(p);
	cout << "-----" << endl;
	pop(p);
	travser(p);
	return 0;
}

void init(PQUENE p) {
	//��ʼ��ͷ����β�����ͬһ���½�㣬����ͷ����β���ָ������Ϊ��
	p->front = (PNODE)malloc(sizeof(Node));
	if (p->front == NULL) {
		cout << "�����ڵ�ʧ��!" << endl;
		exit(-1);
	}
	p->rear = p->front;
	p->front->pNext = NULL;
}

bool isEmpty(PQUENE p) {
	//�ж�ͷ�ڵ��β�ڵ��ַ�Ƿ���ͬ
	if (p->front == p->rear) {
		return true;
	}
	else {
		return false;
	}
}

void push(PQUENE p, int t) {
	//��ʼ��һ���µĽڵ�pNew ��ֵT����pnew�������� �� rear��ָ����ָ��pNew pnew��ָ����ָ��NULL ��pNew����rear
	PNODE pNew = (PNODE)malloc(sizeof(Node));
	if (pNew == NULL) {
		cout << "�����ڵ�ʧ��!" << endl;
		exit(-1);
	}
	pNew->date = t;
	p->rear->pNext = pNew;
	pNew->pNext = NULL;
	p->rear = pNew;
}

void pop(PQUENE p) {
	//��front����һ�����ĵ�ַ����front  free ptem
	PNODE ptem;
	ptem = p->front;
	p->front = p->front->pNext;
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