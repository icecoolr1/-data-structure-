#include <iostream>
using namespace std;

typedef struct BTNode
{
	char data;//������
	struct BTNode* pLchild;//����
	struct BTNode* pRchild;//�Һ���
}*PTNODE, BTNODE;

PTNODE createBtnode();//���ظ��ڵ��ַ
void preTraverse(PTNODE p);//����
void inTraverse(PTNODE p);//����
void postTraverse(PTNODE p);//����

int main() {
	PTNODE ptnode = createBtnode();
	preTraverse(ptnode);
	return 0;
}

//��̬������ʽ�������ڵ� �ȴ���n���ڵ���������β���� ���ظ��ڵ��ַ
PTNODE createBtnode() {
	PTNODE pA = (PTNODE)malloc(sizeof(BTNODE));
	PTNODE pB = (PTNODE)malloc(sizeof(BTNODE));
	PTNODE pC = (PTNODE)malloc(sizeof(BTNODE));
	PTNODE pD = (PTNODE)malloc(sizeof(BTNODE));
	PTNODE pE = (PTNODE)malloc(sizeof(BTNODE));

	pA->data = 'a';
	pB->data = 'b';
	pC->data = 'c';
	pD->data = 'd';
	pE->data = 'e';

	pA->pLchild = pB;
	pA->pRchild = pC;
	pB->pLchild = pB->pRchild = NULL;
	pC->pLchild = pD;
	pC->pRchild = NULL;
	pD->pLchild = NULL;
	pD->pRchild = pE;
	pE->pLchild = pE->pRchild = NULL;

	return pA;
}

void preTraverse(PTNODE p)
{
	if (p != NULL) {
		//�ȷ��ʸ��ڵ� ��������������� ���������������
		cout << p->data << endl;
		if (p->pLchild != NULL) {
			//p->pLchild�ɴ�������������
			preTraverse(p->pLchild);
		}
		if (p->pRchild != NULL) {
			//p->pRchild�ɴ�������������
			preTraverse(p->pRchild);
		}
	}
}

void inTraverse(PTNODE p)
{
	if (p != NULL) {
		if (p->pLchild != NULL) {
			//p->pLchild�ɴ�������������
			inTraverse(p->pLchild);
		}
		cout << p->data << endl;
		if (p->pRchild != NULL) {
			//p->pRchild�ɴ�������������
			inTraverse(p->pRchild);
		}
	}
}

void postTraverse(PTNODE p)
{
	if (p != NULL) {
		if (p->pLchild != NULL) {
			//p->pLchild�ɴ�������������
			postTraverse(p->pLchild);
		}
		if (p->pRchild != NULL) {
			//p->pRchild�ɴ�������������
			postTraverse(p->pRchild);
		}
		cout << p->data << endl;
	}
}