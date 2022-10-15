#include <iostream>
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
// LNR, LRN, NLR, NRL, RNL, RLN
void Duyet_LNR(TREE t)
{
	if (t != NULL)
	{
		Duyet_LNR(t->pLeft);
		cout << t->data << " ";
		Duyet_LNR(t->pRight);
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
void Duyet_NLR(TREE t)
{
	if (t != NULL)
	{
		cout << t->data << " ";
		Duyet_NLR(t->pLeft);
		Duyet_NLR(t->pRight);	
	}
}
void Duyet_NRL(TREE t)
{
	if (t != NULL)
	{
		cout << t->data << " ";
		Duyet_NRL(t->pRight);
		Duyet_NRL(t->pLeft);
	}
}
void Duyet_RNL(TREE t)
{
	if (t != NULL)
	{
		Duyet_RNL(t->pRight);
		cout << t->data << " ";
		Duyet_RNL(t->pLeft);
	}
}
void Duyet_RLN(TREE t)
{
	if (t != NULL)
	{
		Duyet_RLN(t->pRight);
		Duyet_RLN(t->pLeft);
		cout << t->data << " ";
	}
}
void TimKiem(TREE t, int x)
{
	if (t == NULL)
	{
		cout << "Khong Co" << endl;
		return;
	}
	else
	{
		if (x < t->data)
		{
			TimKiem(t->pLeft, x);
		}
		else if (x > t->data)
		{
			TimKiem(t->pRight, x);
		}
		else
		{
			cout << "Co" << endl;
			return;
		}
	}
}
int TongSoNodeTrenCay(TREE t)
{
	if (t == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + TongSoNodeTrenCay(t->pLeft) + TongSoNodeTrenCay(t->pRight);
	}
}
void Node_Co_2_Con(TREE t)
{
	if (t != NULL)
	{
		if (t->pLeft != NULL && t->pRight != NULL)
		{
			cout << t->data << " ";
		}
		Node_Co_2_Con(t->pLeft);
		Node_Co_2_Con(t->pRight);
	}
}
void Node_Co_1_Con(TREE t)
{
	if (t != NULL)
	{
		if ((t->pLeft != NULL && t->pRight == NULL) || (t->pLeft == NULL && t->pRight != NULL))
		{
			cout << t->data << " ";
		}
		Node_Co_1_Con(t->pLeft);
		Node_Co_1_Con(t->pRight);
	}
}
void Node_Co_1_ConPhai(TREE t)
{
	if (t != NULL)
	{
		if ( t->pLeft == NULL && t->pRight != NULL)
		{
			cout << t->data << " ";
		}
		Node_Co_1_ConPhai(t->pLeft);
		Node_Co_1_ConPhai(t->pRight);
	}
}
void Node_La(TREE t)
{
	if (t != NULL)
	{
		if (t->pLeft == NULL && t->pRight == NULL)
		{
			cout << t->data << " ";
		}
		Node_La(t->pLeft);
		Node_La(t->pRight);
	}
}
int TimMax(TREE t)
{
	if (t->pRight == NULL)
	{
		return t->data;
	}
	else if (t->pRight != NULL)
	{
		return TimMax(t->pRight);
	}
}
int TimMin(TREE t)
{
	if (t->pLeft == NULL)
	{
		return t->data;
	}
	else if (t->pLeft != NULL)
	{
		return TimMin(t->pLeft);
	}
}
void DiTimNodeTheMang(TREE &X, TREE &Y)
{
	if (Y->pLeft != NULL)
	{
		DiTimNodeTheMang(X, Y->pLeft);
	}
	else
	{
		X->data = Y->data;
		X = Y;
		Y = Y->pRight;
	}
}
// Tim Node Trai Nhat Cua Cay Con Phai
void XoaNode(TREE &t, int data)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		if (data < t->data)
		{
			XoaNode(t->pLeft, data);
		}
		else if (data > t->data)
		{
			XoaNode(t->pRight, data);
		}
		else
		{
			NODE* X = t;
			if (t->pLeft == NULL)
			{
				t = t->pRight;
			}
			else if (t->pRight == NULL)
			{
				t = t->pLeft;
			}
			else
			{
				NODE* Y = t->pRight;
				DiTimNodeTheMang(X, Y);
			}
			delete X;
		}
	}
} 
int InRaChieuCaoCuaCay(TREE t)
{
	if (t == NULL)
		return 0;
	int a = InRaChieuCaoCuaCay(t->pLeft);
	int b = InRaChieuCaoCuaCay(t->pRight);
	if (a > b)
		return a + 1;
	return b + 1;
}
void InRaNodeCoGiaTriChan(TREE t)
{
	if (t != NULL)
	{
		if (t->data % 2 == 0)
		{
			cout << t->data << " ";
		}
		InRaNodeCoGiaTriChan(t->pRight);
		InRaNodeCoGiaTriChan(t->pLeft);
	}
}
void TimCacNodeLonHonX(TREE t, int x)
{
	if (t != NULL)
	{
		if (t->data > x)
		{
			cout << x << " ";
		}
		TimCacNodeLonHonX(t->pLeft, x);
		TimCacNodeLonHonX(t->pRight, x);
	}
}
void TimGiaTriNhoNhatCuaCayConPhai(TREE t)
{	
	if (t == NULL)
	{
		cout << "Cay khong ton tai" << endl;
	}
	else if (t->pRight == NULL)
	{
		cout << "Khong co cay con phai" << endl;
	}
	else
	{
		t = t->pRight;
		while (t->pLeft != NULL)
		{
			t = t->pLeft;
		}
		cout << "Gia Tri Nho Nhat " << t->data << endl;
	}
	
}
void DoDaiDuongDi(TREE t, int x, int &dem)
{
	if (x > TimMax(t))
	{
		cout << "Khong co gia tri phu hop" << endl;
		return;
	}
	if (x < TimMin(t))
	{
		cout << "Khong co gia tri phu hop" << endl;
		return;
	}
	if (x > t->data)
	{
		dem = dem + 1;
		DoDaiDuongDi(t->pRight, x,dem);
		
	}
	else if (x < t->data)
	{
		dem = dem + 1;
		DoDaiDuongDi(t->pLeft, x,dem);
		
	}
	else
	{
		cout << "So buoc di " << dem << endl;
	}
}
void InCungMuc(TREE t, int muc, int mucgoc) {
	if (t != NULL) {
		if (mucgoc == muc) cout << t->data << " ";
		else {
			InCungMuc(t->pLeft, muc, mucgoc + 1);
			InCungMuc(t->pRight, muc, mucgoc + 1);
		}
	}
}
void MENU(TREE &t)
{
	while (true)
	{
		system("cls");
		cout << "=================MENU==================" << endl;
		cout << "1.Nhap cay nhi phan" << endl;
		cout << "2.Xuat danh sach theo LNR, LRN, NLR, NRL, RNL, RLN " << endl;
		cout << "3.Tim Kiem Mot Node" << endl;
		cout << "4.Xoa mot node tren cay" << endl;
		cout << "5.In ra tong so Node tren cay" << endl;
		cout << "6.In ra so Node co day du 2 cay con" << endl;
		cout << "7.In ra so Node co 1 cay con" << endl;
		cout << "8.In ra so Node chi co 1 cay con phai" << endl;
		cout << "9.In ra so Node la trong cay" << endl;
		cout << "10.In ra chieu cao cua cay" << endl;
		cout << "11.In ra cac Node co gia tri chan" << endl;
		cout << "12.In ra cac Node co gia tri lon hon x duoc nhap tu ban phim" << endl;
		cout << "13.In ra gia tri cua Node co gia tri lon nhat trong cay" << endl;
		cout << "14.In ra gia tri cua Node co key nho nhat cua cay con phai cua cay" << endl;
		cout << "15.In cac Node tren tung muc cua cay" << endl;
		cout << "16.Cho biet do dai duong di tu goc den Node co gia tri X nhap vao tu ban phim" << endl;
		cout << "0.Thoat" << endl;
		int luachon;
		cout << "Nhap lua chon" << endl;
		cin >> luachon;
		if (luachon == 1)
		{
			int x;
			cout << "Nhap du lieu" << endl;
			cin >> x;
			ThemNodeVaoCay(t, x);
		}
		if(luachon == 2)
		{
			Duyet_LNR(t);
			cout << endl;
			Duyet_LRN(t);
			cout << endl;
			Duyet_NLR(t);
			cout << endl;
			Duyet_NRL(t);
			cout << endl;
			Duyet_RNL(t);
			cout << endl;
			Duyet_RLN(t);
			cout << endl;
			system("pause");
		}
		if (luachon == 3)
		{
			int x;
			cout << "Nhap du lieu muon tim kiem" << endl;
			cin >> x;
			TimKiem(t, x);
			system("pause");
		}
		if (luachon == 4)
		{
			int x;
			cout << "Nhap du lieu can xoa" << endl;
			cin >> x;
			XoaNode(t, x);
		}
		if (luachon == 5)
		{
			cout << "Tong so node tren cay la " << TongSoNodeTrenCay(t) << endl;
			system("pause");
		}
		if (luachon == 6)
		{
			Node_Co_2_Con(t);
			system("pause");
		}
		if (luachon == 7)
		{
			Node_Co_1_Con(t);
			system("pause");
		}
		if (luachon == 8)
		{
			Node_Co_1_ConPhai(t);
			system("pause");
		}
		if (luachon == 9)
		{
			Node_La(t);
			system("pause");
		}
		if (luachon == 10)
		{
			cout << "Chieu Cao Cua Cay La " << InRaChieuCaoCuaCay(t) << endl;
			system("pause");
		}
		if (luachon == 11)
		{
			cout << "Cac Node Co Gia Tri Chan La "; 
			InRaNodeCoGiaTriChan(t);
			system("pause");
		}
		if (luachon == 12)
		{
			int x;
			cout << "Nhap x" << endl;
			cin >> x;
			cout << "Cac Gia Tri Lon Hon X La ";
			TimCacNodeLonHonX(t, x);
			system("pause");
		}
		if (luachon == 13)
		{
			cout << "Gia tri lon nhat trong TREE la " << TimMax(t) << endl;
			system("pause");
		}
		if (luachon == 14)
		{
			TimGiaTriNhoNhatCuaCayConPhai(t);
		}
		if (luachon == 15)
		{
			int muc;
			cout << "Nhap muc" << endl;
			cin >> muc;
			int mucgoc = 0;
			cout << "Cac Node cua muc " << muc << " la "; InCungMuc(t, muc, mucgoc);
			system("pause");
		}
		if (luachon == 16)
		{
			int dem = 0;
			int x;
			cout << "Nhap gia tri x" << endl;
			cin >> x;
			DoDaiDuongDi(t, x, dem);
		}
		if (luachon == 0)
			break;
	}
}
int main()	
{
	TREE t;
	KhoiTaoCay(t);
	MENU(t);
	return 0;
}