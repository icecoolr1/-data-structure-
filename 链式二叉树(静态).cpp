#include <iostream>
using namespace std;

typedef struct BTNode
{
	char data;//数据域
	struct BTNode* pLchild;//左孩子
	struct BTNode* pRchild;//右孩子
}*PTNODE, BTNODE;

PTNODE createBtnode();//返回根节点地址
void preTraverse(PTNODE p);//先序
void inTraverse(PTNODE p);//中序
void postTraverse(PTNODE p);//后序

int main() {
	PTNODE ptnode = createBtnode();
	preTraverse(ptnode);
	return 0;
}

//静态创建链式二叉树节点 先创建n个节点让它们收尾相连 返回根节点地址
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
		//先访问根节点 再先序访问左子树 再先序访问右子树
		cout << p->data << endl;
		if (p->pLchild != NULL) {
			//p->pLchild可代表整个左子树
			preTraverse(p->pLchild);
		}
		if (p->pRchild != NULL) {
			//p->pRchild可代表整个右子树
			preTraverse(p->pRchild);
		}
	}
}

void inTraverse(PTNODE p)
{
	if (p != NULL) {
		if (p->pLchild != NULL) {
			//p->pLchild可代表整个左子树
			inTraverse(p->pLchild);
		}
		cout << p->data << endl;
		if (p->pRchild != NULL) {
			//p->pRchild可代表整个右子树
			inTraverse(p->pRchild);
		}
	}
}

void postTraverse(PTNODE p)
{
	if (p != NULL) {
		if (p->pLchild != NULL) {
			//p->pLchild可代表整个左子树
			postTraverse(p->pLchild);
		}
		if (p->pRchild != NULL) {
			//p->pRchild可代表整个右子树
			postTraverse(p->pRchild);
		}
		cout << p->data << endl;
	}
}