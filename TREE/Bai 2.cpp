#include<iostream>
using namespace std;

struct NODE
{
	int data;
	NODE* pLeft;
	NODE* pRight;
};
typedef NODE* TREE;
void KhoiTaoCay(TREE& t)
{
	t = NULL;
}
void ThemNodeVaoCay(TREE& t, int x)
{
	if (t == NULL)
	{
		NODE* p = new NODE;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else
	{
		if (t->data > x)
		{
			ThemNodeVaoCay(t->pLeft, x);
		}
		else if (t->data < x)
		{
			ThemNodeVaoCay(t->pRight, x);
		}
	}
}
void Duyet_LRN(TREE t)
{
	if (t != NULL)
	{
		Duyet_LRN(t->pLeft);
		Duyet_LRN(t->pRight);
		cout << t->data << " ";
	}
}
bool CheckSCP(int n)
{
	int sqr = sqrt(n);
	if (sqr * sqr == n) {
		return true;
	}
	else {
		return false;
	}
}
void InSoChinhPhuong(TREE t)
{
	if (t != NULL)
	{
		if (CheckSCP(t->data) == true)
		{
			cout << t->data << " ";
		}
		InSoChinhPhuong(t->pLeft);
		InSoChinhPhuong(t->pRight);
	}
}

void InCungMuc(TREE t, int muc, int goc) {
		if (t != NULL) {
			if (goc == muc) cout << t->data << " ";
			else {
				InCungMuc(t->pLeft, muc, goc + 1);
				InCungMuc(t->pRight, muc, goc + 1);
			}
		}
		cout << endl;
}

void MENU(TREE& t)
{
	while (true)
	{
		cout << "============MENU===========" << endl;
		cout << "1.Nhap Cay" << endl;
		cout << "2.Xuat LRN" << endl;
		cout << "3.In ra so chinh phuong" << endl;
		cout << "4.In Node Cung Muc" << endl;
		cout << "0.Thoat" << endl;
		int luachon;
		cout << "Nhap lua chon" << endl;
		cin >> luachon;
		if (luachon == 1)
		{
			int x;
			cout << "Nhap gia tri x" << endl;
			cin >> x;
			ThemNodeVaoCay(t, x);
		}
		if (luachon == 2)
		{
			Duyet_LRN(t);
			system("pause");
		}
		if (luachon == 3)
		{
			InSoChinhPhuong(t);
			system("pause");
		}
		if (luachon == 4)
		{
			int muc;
			cout << "Nhap muc" << endl;
			cin >> muc;
			int goc = 0;
			InCungMuc(t, muc, goc);
			system("pause");
		}
		if (luachon == 0)
		{
			break;
		}
	}

}
int main()
{
	TREE t;
	KhoiTaoCay(t);
	MENU(t);
	return 0;
}