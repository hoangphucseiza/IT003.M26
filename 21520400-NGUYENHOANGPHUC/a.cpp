#include<iostream>
using namespace std;
struct NODE
{
	int data;
	NODE* pNext;
};
struct LIST {
	NODE* pHead;
	NODE* pTail;
};
void KhoiTaoLIST(LIST& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
NODE * KhoiTaoNODE(int x)
{
	NODE* p = new NODE;
	if (p == NULL)
	{
		cout << "Khong du bo nho" << endl;
		return 0 ;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}
void ThemVaoDau(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void ThemVaoCuoi(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void InDanhSachTheoChieuNguocLai(LIST l)
{
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{

	}
}
void XuatDanhSachNguocLai( LIST l)
{
	int n = 0;
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		n++;
	}
	for (int i = n; i >= 1; i--)
	{
		NODE* tmp = l.pHead;
		for (int j = 1; j <= i - 1; j++)
		{
			tmp = tmp->pNext;
		}
		cout << tmp->data << " ";
	}
}
void XoaDau(LIST& l)
{
	if (l.pHead == NULL)
		return;
	NODE* p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;
}
void XoaCuoi(LIST& l)
{
	if (l.pHead == NULL)
		return;
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->pNext == l.pTail)
		{
			delete l.pTail;
			k->pNext = NULL;
			l.pTail = k;
			return;
		}
	}
}
void TimNutCoDuLieuX(LIST l,int x)
{
	int dem = 1;
	bool co = false;
	cout << " Cac vi tri xuat hien du lieu X : ";
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->data == x)
		{
			co = true;
			cout << dem << " ";
		}
		dem++;
	}
	if (co == false) cout << "KHONG CO DU LIEU X TRONG DANH SACH";
}
void Them_Node_p_VaoViTriBatKi(LIST& l, NODE* p, int vt)
{
	int n = 0;
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		n++;
	}
	if (l.pHead == NULL || vt == 1)
	{
		ThemVaoDau(l, p);
	}
	else if (vt == n + 1)
	{
		ThemVaoCuoi(l, p);
	}
	else
	{
		int dem = 0;
		NODE* g = new NODE;
		for (NODE* k = l.pHead; k != NULL; k = k->pNext)
		{
			dem++;
			if (dem == vt)
			{
				NODE* h = KhoiTaoNODE(p->data);
				h->pNext = k;
				g->pNext = h;
				break;
			}
			g = k;
		}
	}
}
void XoaNodeCoKhoaBatKi(LIST& l, int x)
{
	bool co = false;
	if (l.pHead->data == x)
	{
		XoaDau(l);
		return;
	}
	if (l.pTail->data == x)
	{
		XoaCuoi(l);
		return;
	}
	NODE* g = new NODE;
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->data == x)
		{
			co = true;
			g->pNext = k->pNext;
			delete k;
			return;
		}
		g = k;
	}
	if (co == false) cout << " Khong co" << endl;
	system("pause");
}
void XuatDanhSach(LIST l)
{
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
		cout << k->data << " " ;
	cout << endl;
}
void MENU(LIST& l)
{

	while (69)
	{
		system("cls");
		cout << "===========MENU=========" << endl;
		cout << "1.Nhap vao va xuat ra n phan tu bang cac them vao dau" << endl;
		cout << "2.Nhap vao va xuat ra n phan tu bang cac them vao cuoi" << endl;
		cout << "3.Xuat Danh Sach" << endl;
		cout << "4.In Ra Danh Sach Theo Chieu Cuoi" << endl;
		cout << "5.Dem so nut cua danh sach lien ket don" << endl;
		cout << "6.Tim mot nut co thanh phan du lieu bang X duoc nhap vao" << endl;
		cout << "7.Xoa nut dau danh sach" << endl;
		cout << "8.Xoa nut cuoi danh sach" << endl;
		cout << "9.Xoa mot nut co du lieu X, neu khong co thi bao khong co" << endl;
		cout << "10.Chen 1 nut co du lieu X vao vi tri thu n nhap vao tu ban phim" << endl;
		cout << "0.Thoat" << endl;
		int luachon;
		cin >> luachon;
		if (luachon == 1)
		{
			
				int x;
				cout << "Nhap gia tri can them vao" << endl;
				cin >> x;
				NODE* p = KhoiTaoNODE(x);
				ThemVaoDau(l, p);
			
		}
		if (luachon == 2)
		{
			int x;
			cout << "Nhap gia tri can them vao" << endl;
			cin >> x;
			NODE* p = KhoiTaoNODE(x);
			ThemVaoCuoi(l, p);
		}
		if (luachon == 3)
		{
			XuatDanhSach(l);
			system("pause");
		}
		if (luachon == 4)
		{
			XuatDanhSachNguocLai(l);
			system("pause");
		}
		if (luachon == 5)
		{
			
			int dem = 0;
			for (NODE* k = l.pHead; k != NULL; k = k->pNext)
				dem++;
			cout << "Co tat ca " << dem << " nut trong danh sach lien ket don" << endl;
			system("pause");

		}
		if (luachon == 6)
		{
			int x;
			cout << "Nhap du lieu X" << endl;
			cin >> x;
			TimNutCoDuLieuX(l, x);
			system("pause");
		}
		if (luachon == 7)
		{
			XoaDau(l);

		}
		if (luachon == 8)
		{
			XoaCuoi(l);

		}
		if (luachon == 9)
		{
			int x;
			cout << " Nhap gia tri can xoa" << endl;
			cin >> x;
			XoaNodeCoKhoaBatKi(l, x);

		}if (luachon == 10)
		{
			int x;
			cout << " Nhap gia tri can them vao" << endl;
			cin >> x;
			NODE* p = KhoiTaoNODE(x);
			int vt;
			cout << "Nhap vi tri can them vao" << endl;
			cin >> vt;
			Them_Node_p_VaoViTriBatKi(l, p, vt);
		}
		if (luachon == 0)
		{
			break;
		}

	}
}
int main()
{
	LIST l;
	KhoiTaoLIST(l);
	MENU(l);
	return 0;
}