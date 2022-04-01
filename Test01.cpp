#include <iostream>
using namespace std;

const int MaxSize = 50;

struct SqList
{
	int data[MaxSize];
	int length;
};

void InitList(SqList*& L)							//初始化顺序表
{
	L = (SqList*)malloc(sizeof(SqList));
	if(L != NULL)
		L->length = 0;
}

void CreateList(SqList*& L, int n)							//创建约瑟夫环
{
	for (int i = 0; i < n; i++)
	{
		L->data[i] = i + 1;
	}
	L->length = n;
}

void DispList(SqList* L)									//遍历环
{
	for (int i = 0; i < L->length; i++)
	{
		cout << L->data[i] << " ";
	}
	cout << endl;
}

void DestroyList(SqList*& L)								//销毁环
{
	free(L);
}

//约瑟夫环问题
int main()
{
	//定义顺序表
	SqList *L;

	//初始化顺序表,并赋予50长度
	InitList(L);

	int m, n, i, j, k = 0;
	cout << "请输入总人数：" << endl;
	cin >> n;

	//创建约瑟夫环
	CreateList(L, n);

	//遍历环
	cout << "队列序号是：" << endl;
	DispList(L);

	cout << "请输入所报的数：" << endl;
	cin >> m;

	cout << "出列次序是：" << endl;
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

	//销毁链表
	DestroyList(L);
}