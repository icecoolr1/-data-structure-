#include <iostream>
using namespace std;

typedef struct Node
{
	int data;//数据域
	struct Node* pNext;//指针域 指向和本身数据类型一样另外一个节点
}*PNODE, NODE;

PNODE create_list();//初始化
void traverse_list(PNODE pHead);//遍历输出
bool is_pEmpty(PNODE pHead);//判空
bool insert_list(PNODE pHead,int index,int val);//插入
bool delete_list(PNODE pHead,int index, int * t );//
void sort_list(PNODE pHead);
int get_length(PNODE pHead);



int main()
{
    int index;
    int val;
    NODE node;
    int  t;
    PNODE pHead = &node;
   //创建一个非循环单链表，并将该链表的头结点地址赋给pHead
    pHead = create_list();
    traverse_list(pHead);
    //is_pEmpty(pHead);
    cout << "链表长度为:"<<get_length(pHead) << endl;

 
  /*  cout << "请输入在第几个节点之前插入值"<<endl;
    cin >> index;
    cout << "请输入插入的值" << endl;
    cin >> val;
    if (insert_list(pHead, index, val) == true) {
        traverse_list(pHead);
    }
    else {
        cout << "插入失败!" << endl;
    }
  */
    //cout << "排序结果是" << endl;
    //sort_list(pHead);
    //traverse_list(pHead);
    /*cout << "----" << endl;
    delete_list(pHead,1,&t);
    traverse_list(pHead);*/
    cout << "----" << endl;
    sort_list( pHead);
    traverse_list(pHead);
    return 0;
}


PNODE create_list() {
    int len;
    int val;
    cout << "请输入您要生成链表结点的个数" << endl;
    cin >> len;
    //分配了一个不存放有效数据的头结点 尾插法                   
    PNODE pHead = (PNODE)malloc((sizeof(NODE)));
    if (NULL == pHead) {
        cout << "创建头结点失败" << endl;
        exit (-1);
    }
    PNODE pTail = pHead;
    pTail->pNext = NULL;
    for (int i = 0; i < len;i++) {
        cout << "请输入第" << i+1 << "个结点的值"<<endl;
        cin >> val;
        PNODE pNew = (PNODE)malloc((sizeof(NODE)));
        if (NULL == pNew) {
            cout << "创建后继结点失败" << endl;
            exit(-1);
        }
        pNew->data = val;
        pTail->pNext = pNew;
        pNew->pNext = NULL;
        //注意是把pNew的地址给pTail 而不是两个地址交换
        pTail = pNew;
    }
    return pHead;

}

void traverse_list(PNODE pHead) {
    //设首指针为p 
    PNODE p = pHead->pNext;
    //在while循环中 只要p检测到不为空 则将p的下一个节点赋给p
    while (NULL != p)
    {
        cout << p->data<<" ";
        p = p->pNext;

    }
    return;
}

bool is_pEmpty(PNODE pHead) {
    if (pHead->pNext == NULL) {
        return true;
    }
    else {
        return false;
    }
}

bool insert_list(PNODE pHead, int index, int val) {
    PNODE p = pHead;
    PNODE pNew = (PNODE)malloc((sizeof(NODE)));
    if (pNew == NULL) {
        exit(-1);
    }
    if (index > get_length(pHead) || index < 1) {
        return false;
    }
    for (int i = 1; i < index;i++) {
        p = p->pNext;
    }
   
    pNew->data = val;
    pNew->pNext = p->pNext;
    p->pNext = pNew;
    return true;
    /*
        while(NULL!=p&&i<pos-1){
        p = p->pnext;
        i++
        }
        if(i>pos-1||NULL==p)
        return false;


        pNode q = p->pNext;
        p->pNext = pNew;
        pNew->pNext = q;
    
    */
}

int get_length(PNODE pHead) {
    int i = 0;
    PNODE p = pHead->pNext;
    if (is_pEmpty(pHead) == true) {
        i = 0;
        return i;
    }
    else {
        while (p != NULL) {
            p = p->pNext;
            i++;
        }
        return i;
    }

}
void sort_list(PNODE pHead) {
    int i, j;
    PNODE p, q;

    /*
    for (i = 0, p = pHead->pNext; i < get_length(pHead) - 1;i++, p = p->pNext) {
        for (j = i + 1, q = p->pNext;j < get_length(pHead);j++, q = q->pNext) {
            if (p->data > q->data) {
                int t;
                t = p->data;
                p->data = q->data;
                q->data = t;
            }
        }
    }
    */

    for (i = 0, p = pHead->pNext;i < get_length(pHead) - 1;i++, p = p->pNext) {
        for (j = 0, q = pHead->pNext;j < get_length(pHead) - 1 - i;j++, q = q->pNext) {
            if (q->data > q->pNext->data) {
                int t;
                t = p->data;
                p->data = q->pNext->data;
                q->pNext->data = t;
            }
        }
    }
}


bool delete_list(PNODE pHead, int index, int* t) {
    PNODE p = pHead;
    for (int i = 1; i < index;i++) {
        p = p->pNext;
    }
   PNODE q = p->pNext;
   *t = q->data;
   //删除p节点后面的节点
   p->pNext = p->pNext->pNext;
    free(q);
   q = NULL;
    return true;
}

