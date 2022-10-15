#include<iostream>
using namespace std;
//=====================LAM VIEC VOI DSLK========================
struct NODE
{
	int data;
	NODE* pNext;
};
struct QUEUE
{
	NODE* pHead;
	NODE* pTail;
};
void KhoiTaoQueue(QUEUE& q)
{
	q.pHead = NULL;
	q.pTail = NULL;
}
NODE* KhoiTaoNODE(int x)
{
	NODE* p = new NODE;
	if (p == NULL) return NULL;
	p->data = x;
	p->pNext = NULL;
	return p;
}
bool IsEmpty(QUEUE q)
{
	if (q.pHead == NULL) return true;
	else
	return false;
}
void EnQueue(QUEUE& q, NODE* p)
{
	if (q.pHead == NULL)
	{
		q.pHead = q.pTail = p;
	}
	else
	{
		q.pTail->pNext = p;
		q.pTail = p;
	}
}
bool DeQueue(QUEUE& q, int& x)
{
	if (IsEmpty(q) == true)
	{
		return false;
	}
	else
	{
		NODE* p = q.pHead;
		x = p->data;
		q.pHead = q.pHead->pNext;
		delete p;
	}
}
int DemSoPhanTuTrongQueue(QUEUE q)
{
	int dem = 0;
	for (NODE* k = q.pHead; k != NULL; k = k->pNext)
	{
		++dem;
	}
	return dem;
}
void XoaTatCaCacPhanTuTrongQueue(QUEUE& q)
{
	while (!IsEmpty(q))
	{
		NODE* p = q.pHead;
		q.pHead = q.pHead->pNext;
		delete p;
	}
}
void MENU(QUEUE& q)
{
	while (true)
	{
		system("cls");
		cout << "================MENU===============" << endl;
		cout << "1.Enqueue" << endl;
		cout << "2.Dequeue" << endl;
		cout << "3. Kiem tra queue rong hay khong" << endl;
		cout << "4.Dem So luong phan tu trong queue" << endl;
		cout << "5.Xoa tat ca phan tu trong queue" << endl;
		cout << "0.Thoat" << endl;
		cout << "======================END===============" << endl;
		int luachon;
		cout << "Nhap lua chon" << endl;
		cin >> luachon;
		if (luachon == 1)
		{ 
			int i;
			cout << "Nhap gia tri can cho vao queue" << endl;
			cin >> i;
			NODE* p = KhoiTaoNODE(i);
			EnQueue(q, p);
		}
		if (luachon == 2)
		{
			while (IsEmpty(q) != true)
			{
				int x;
				DeQueue(q, x);
				cout << x << " ";
			}
			system("pause");
		}
		if (luachon == 3)
		{
			if (IsEmpty(q)) cout << "Rong"; else cout << "Co Phan Tu" << endl;
			system("pause");
		}
		if (luachon == 4)
		{
			cout << "So phan tu trong Queue la " << DemSoPhanTuTrongQueue(q) << endl;
			system("pause");
		}
		if (luachon == 5)
		{
			XoaTatCaCacPhanTuTrongQueue(q);
		}
		if (luachon == 0)
		{
			break;
		}
	}
}
int main()
{
	QUEUE q;
	KhoiTaoQueue(q);
	MENU(q);
	return 0;
}