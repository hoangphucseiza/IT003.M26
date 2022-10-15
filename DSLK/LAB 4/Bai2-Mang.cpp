#include<iostream>
using namespace std;
#define max 100
struct STACK
{
	int a[max];
	int t;
};
void KhoiTaoStack(STACK& s)
{
	s.t = -1;
}
bool IsEmpty(STACK s)
{
	if (s.t == -1 ) return true;
	else return false;
}
bool IsFull(STACK s)
{
	if (s.t >= max)
		return true;
	else return false;
}

void Push(STACK& s, int x)
{
	if (IsFull(s))
	{
		return;
	}
	else
	{
		s.t++;
		s.a[s.t] = x;
	}
}
void Pop(STACK& s, int& x)
{
	if (!IsEmpty(s))
	{
		x = s.a[s.t];
		s.t--;
	}
}
int DemSoPhanTuTrongStack(STACK s)
{
	int dem = 0;
	for (int i=0;i<=s.t;i++)
	{
		dem++;
	}
	return dem;
}
void XoaTatCaCacPhanTuTrongStack(STACK& s)
{
	s.t = -1;
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
			Push(s, i);
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