#include <iostream>
using namespace std;

typedef struct ARR
{
	int* pBase;//���������һ��Ԫ�ص�ַ
	int len;//���������������Ԫ�ظ���
	int cnt;//��ǰ������ЧԪ�ظ�λ

}* PARR , ARR;


bool append_arr(struct ARR *parry,int val);//׷��
bool insert_arr(struct ARR* parry,int index,int vel);//���� pos��1��ʼ
bool delete_arr(struct ARR *parry,int index,int *pal);//ɾ��
bool get_arr();//���
bool is_aempty(struct ARR *parry);//�п� ע�� isempty()����ΪC++�ڲ�����ʹ�ø����������ᱨ��
bool is_full(struct ARR *parry);//����
void sort_arr(struct ARR* parry);//����
void show_arr(struct ARR *parry);//��ӡ
void inversion_arr(struct ARR* parry);//����
void init_arr(struct ARR *parray,int length);//��ʼ��

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
* ����������ַ���������������ϵͳ������array���ڴ棬���Ի���������ַ��
void init_arr(struct ARR array) {
	array.len = 99;

}
*/


void init_arr(struct ARR *parray,int length) {
	//��̬�ڴ�����׵�ַ arrayָ������ṹ��pBase��Ա
	parray->pBase = (int*)malloc(sizeof(int) * length);
	if (NULL == parray->pBase) {
		cout << "��̬�ڴ����ʧ��" << endl;
		//�������
		exit(-1);
	}
	else {
		parray->len = length;
		parray->cnt = 0;
	}
	//������ֹ
	return ;
}


bool is_aempty(struct ARR *parry) {
	//�����Ч����Ϊ0���
	if (0 == parry->cnt)
		return true;
	else
		return false;

}
void show_arr(struct ARR *parry)	{
	// struct Arr *parry = &arr ��parry��Ϊָ��ָ��arr ��ôparry�����ŵ���arr�ĵ�ַ�����ò��ü�ȡ��ַ����������ʾ������parry�ĵ�ַ
	if (is_aempty(parry) == true) {
		cout << "����Ϊ��" << endl;
	}
	else {
		//��Ϊ��̬�ڴ�����pBase��Ϊ�׵�ַ�����Խ�pBase������������ʹ�� pBase=&pBase[0] *(pBase+1)=pBase[1] Ҳ��
		for (int i = 0; i < parry->cnt;++i) {
			cout << parry->pBase[i]<<" ";
			//cout << *(parry->pBase + i) << endl;
		}
	}

	

}

bool is_full(struct ARR *parry) {
	//��������Ч��������洢������Ϊ��
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
	//������false
	if (is_full(parry) == true) {
		return false;
	}
	//����ʱ׷��
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
	
	//��Ч����+1
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
	//����
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

	//ѡ��
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