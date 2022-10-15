#include<iostream>
using namespace std;
#define max 100
//=====================LAM VIEC VOI MANG========================
struct QUEUE
{
	int a[max];
	int Front;
	int Rear;
};
void KhoiTaoQueue(QUEUE& q)
{
	q.Front = -1;
	q.Rear = -1;
}
bool IsEmpty(QUEUE q)
{
	if (q.Front== -1) return true;
	else
		return false;
}
void EnQueue(QUEUE& q, int x)
{
	if (q.Front == -1)
	{
		q.Front = q.Rear = 0;
		q.a[q.Front] = x;
	}
	else
	{
		if (q.Rear - q.Front + 1 == max)
		{
			return;
		}
		if (q.Rear==max-1)
		{
			int f = q.Front;
			int r = q.Rear;
			for (int i=f; i < r; i++)
				q.a[i - f] = q.a[i];
			q.Front = 0;
			q.Rear = r - f;
		}
		q.Rear++;
		q.a[q.Rear] = x;

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
		x = q.a[q.Front];
		q.Front++;
		if (q.Front > q.Rear)
		{
			q.Front = -1;
			q.Rear = -1;
		}
		return true;
	}
}
int DemSoPhanTuTrongQueue(QUEUE q)
{
	int dem = 0;
	for (int i= q.Front ; i<=q.Rear ; i++)
	{
		++dem;
	}
	return dem;
}
void XoaTatCaCacPhanTuTrongQueue(QUEUE& q)
{
	q.Front = q.Rear = -1;
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
			EnQueue(q, i);
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