#include <iostream>
#include<string>
#include<string.h>
using namespace std;
struct MATHANG
{
	int masanpham;
	string tensanpham;
	int soluongcotrongcuahang;
	int namsanxuat;
	int dongiamotsanpham;
};
void NhapMatHang(MATHANG& a)
{
	cout << "Nhap Ma San Pham" << endl;
	cin >> a.masanpham;
	cout << "Nhap ten san pham" << endl;
	cin.ignore();
	getline(cin, a.tensanpham);
	cout << "Nhap so luong co trong cua hang" << endl;
	cin >> a.soluongcotrongcuahang;
	cout << "Nhap nam san xuat" << endl;
	cin >> a.namsanxuat;
	cout << "Nhap dong gia mot san pham" << endl;
	cin >> a.dongiamotsanpham;
}
void XuatMatHang(MATHANG a)
{
	cout << "Ma san pham la: " << a.masanpham << endl;
	cout << "Ten san pham la: " << a.tensanpham << endl;
	cout << "So luong co trong cua hang la " << a.soluongcotrongcuahang << endl;
	cout << "Nam san xuat la: " << a.namsanxuat << endl;
	cout << "Dong gia mot san pham la " << a.dongiamotsanpham << endl;
}
struct NODE
{
	MATHANG data;
	NODE* pNext;
};
struct LIST
{
	NODE* pHead;
	NODE* pTail;
};
void KhoiTaoLIST(LIST& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
NODE* KhoiTaoNODE(MATHANG x)
{
	NODE* p = new  NODE;
	if (p == NULL) return NULL;
	p->data = x;
	p->pNext = NULL;
	return p;
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
int DemTongSoNODE(LIST l)
{
	int dem = 0;
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		dem++;
	}
	return dem;
}
void XuatDanhSach(LIST l)
{
	int dem = 1;
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << "[ THONG TIN MAT HANG " << dem << " la ]" << endl;
		XuatMatHang(k->data);
		dem++;
	}
	cout << "======CO TAT CA " << DemTongSoNODE(l) << " MAT HANG====" << endl;
}
void TimMatHangCoGiaCaoNhat(LIST l)
{
	int caonhat = 0;
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->data.dongiamotsanpham > caonhat) caonhat = k->data.dongiamotsanpham;
	}
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->data.dongiamotsanpham == caonhat) XuatMatHang(k->data);
	}
}
void SapXepTangDan(LIST& l)
{
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		for (NODE* h = k->pNext; h != NULL; h = h->pNext)
		{
			if (h->data.masanpham < k->data.masanpham) swap(h->data, k->data);
		}
	}
	XuatDanhSach(l);
}
void MENU(LIST& l)
{
	while (true)
	{
		cout << "===============MENU==============" << endl;
		cout << "1.Nhap Mat Hang Bang Cach Them Vao Cuoi" << endl;
		cout << "2.Xuat Danh Sach" << endl;
		cout << "3.Tim Mat Hang Co Gia Cao Nhat" << endl;
		cout << "4.Sap Xep Tang Dan" << endl;
		cout << "0.Thoat" << endl;
		int luachon;
		cout << "Nhap lua chon" << endl;
		cin >> luachon;
		if (luachon == 1)
		{
			MATHANG a;
			NhapMatHang(a);
			NODE* p = KhoiTaoNODE(a);
			ThemVaoCuoi(l, p);
		}
		if (luachon == 2)
		{
			XuatDanhSach(l);
			system("pause");
		}
		if (luachon == 3)
		{
			cout << "MAT HANG CO GIA CAO NHAT LA" << endl;
			TimMatHangCoGiaCaoNhat(l);
			system("pause");
		}
		if (luachon == 4)
		{
			SapXepTangDan(l);
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
	LIST l;
	KhoiTaoLIST(l);
	MENU(l);
	return 0;
}

