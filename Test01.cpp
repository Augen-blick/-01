#include <iostream>
using namespace std;

const int MaxSize = 50;

struct SqList
{
	int data[MaxSize];
	int length;
};

void InitList(SqList*& L)							//��ʼ��˳���
{
	L = (SqList*)malloc(sizeof(SqList));
	if(L != NULL)
		L->length = 0;
}

void CreateList(SqList*& L, int n)							//����Լɪ��
{
	for (int i = 0; i < n; i++)
	{
		L->data[i] = i + 1;
	}
	L->length = n;
}

void DispList(SqList* L)									//������
{
	for (int i = 0; i < L->length; i++)
	{
		cout << L->data[i] << " ";
	}
	cout << endl;
}

void DestroyList(SqList*& L)								//���ٻ�
{
	free(L);
}

//Լɪ������
int main()
{
	//����˳���
	SqList *L;

	//��ʼ��˳���,������50����
	InitList(L);

	int m, n, i, j, k = 0;
	cout << "��������������" << endl;
	cin >> n;

	//����Լɪ��
	CreateList(L, n);

	//������
	cout << "��������ǣ�" << endl;
	DispList(L);

	cout << "����������������" << endl;
	cin >> m;

	cout << "���д����ǣ�" << endl;
	for (i = L->length; i > 0; i--)
	{
		k = (k + m - 1) % i;
		cout << L->data[k] << " ";
		for (j = k; j < i - 1; j++)
		{
			L->data[j] = L->data[j + 1];
		}
		L->length--;
	}
	cout << endl;

	//��������
	DestroyList(L);
}