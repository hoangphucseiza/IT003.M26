#include<iostream>
using namespace std;
struct NODE
{
	int data;
	NODE* pNext;
};
struct STACK
{
	NODE* pHead;
	NODE* pTail;
};
void KhoiTaoStack(STACK& s)
{
	s.pHead = NULL;
	s.pTail = NULL;
}
NODE* KhoiTaoNODE(int x)
{
	NODE* p = new NODE;
	if (p == NULL) return NULL;
	p->data = x;
	p->pNext = NULL;
	return p;
}
bool IsEmpty(STACK s)
{
	if (s.pHead == NULL) return true;
	else return false;
}
void Push(STACK& s, NODE* p)
{
	if (s.pHead == NULL)
	{
		s.pHead = s.pTail = p;
	}
	else
	{
		p->pNext = s.pHead;
		s.pHead = p;
	}
}
void Pop(STACK& s, int& x)
{
	if (!IsEmpty(s))
	{
		NODE* p = s.pHead;
		x = p->data;
		s.pHead = s.pHead->pNext;
		delete p;
	}
}
int DemSoPhanTuTrongStack(STACK s)
{
	int dem = 0;
	for (NODE* k = s.pHead; k != NULL; k = k->pNext)
	{
		dem++;
	}
	return dem;
}
void XoaTatCaCacPhanTuTrongStack(STACK& s)
{
	while (!IsEmpty(s))
	{
		NODE* p = s.pHead;
		s.pHead = s.pHead->pNext;
		delete p;
	}
}
void MENU(STACK& s)
{

	while (true)
	{
		system("cls");
		cout << "================MENU===============" << endl;
		cout << "1.Push" << endl;
		cout << "2.Pop" << endl;
		cout << "3. Kiem tra stack rong hay khong" << endl;
		cout << "4.Dem So luong phan tu trong stack" << endl;
		cout << "5.Xoa tat ca phan tu trong stack" << endl;
		cout << "0.Thoat" << endl;
		cout << "======================END===============" << endl;
		int luachon;
		cout << "Nhap lua chon" << endl;
		cin >> luachon;
		if (luachon == 1)
		{
			int i;
			cout << "Nhap gia tri can cho vao stack" << endl;
			cin >> i;
			NODE* p = KhoiTaoNODE(i);
			Push(s, p);
		}
		if (luachon == 2)
		{
			
				int x;
				Pop(s, x);
				cout << x << " ";
			system("pause");
		}
		if (luachon == 3)
		{
			if (IsEmpty(s)) cout << "Rong"; else cout << "Co Phan Tu" << endl;
			system("pause");
		}
		if (luachon == 4)
		{
			cout << "So phan tu trong Stack la " << DemSoPhanTuTrongStack(s) << endl;
			system("pause");
		}
		if (luachon == 5)
		{
			XoaTatCaCacPhanTuTrongStack(s);
		}
		if (luachon == 0)
		{
			break;
		}
	}
}
int main()
{
	STACK s;
	KhoiTaoStack(s);
	MENU(s);
	return 0;
}