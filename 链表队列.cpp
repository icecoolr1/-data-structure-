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
2:enhQuene����û�а�ע��д���һ��
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
void outQuene(PQUENE p);//����
void enhQuene(PQUENE p, int t);//���
void travser(PQUENE p);//�������

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

void enhQuene(PQUENE p, int t) {
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

//һ��ʼ���˷�����ȫ���Ϊջ�ĳ�ջ���� �󾭹��о� ջ�ĳ�ջ�Ͷӵĳ�ջ�в�� ��Ϊջ���Ǵ����������ֵ��
//��������ֻ�洢ָ���� ����Ӧ�����׵���һ������ͷ� �����ǵ�����ɾ��ͷָ��

//void outQuene(PQUENE p) {
//	//��front����һ�����ĵ�ַ����front  free ptem
//	PNODE ptem;
//	ptem = p->front;
//	p->front = p->front->pNext;
//	free(ptem);
//	ptem = NULL;
//}

void outQuene(PQUENE p) {
	//��Front���׽��ָ���׽�����һ����� free�׽��
	PNODE ptem = p->front->pNext;
	p->front->pNext = ptem->pNext;
	//���ֻ��һ��Ԫ�� ��ͷ�����
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