#include <iostream>
#include<string>
using namespace std;
struct SinhVien {
    string hovaten;
    string mssv;
    int namsinh;
    double DTB;
};
struct NODE {
    SinhVien data;
    NODE* pNext;
};
struct LIST {
    NODE* pHead;
    NODE* pTail;
};
void KhoiTao(LIST &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}
NODE* KhoiTaoNODE(SinhVien x)
{
    NODE* p = new NODE;
    if (p == NULL) return NULL;
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
void NhapSinhVien(SinhVien& a)
{
    cout << " Nhap Ho Va Ten" << endl;
    cin.ignore();
    getline(cin, a.hovaten);
    cout << " Nhap MSSV" << endl;
    getline(cin, a.mssv);
    cout << " Nhap Nam Sinh" << endl;
    cin >> a.namsinh;
    cout << " Nhap Diem Trung Binh" << endl;
    cin >> a.DTB;
}
void XuatSinhVien(SinhVien a)
{
    cout << a.hovaten << endl;
    cout << a.mssv << endl;
    cout << a.namsinh << endl;
    cout << a.DTB << endl;
}
void XuatDanhSach(LIST l)
{
    int dem = 1;
    for (NODE* k = l.pHead; k != NULL; k = k->pNext)
    {
        cout << "Sinh vien thu " << dem << "la: " << endl;;
        XuatSinhVien(k->data);
        cout << endl;
        dem++;
    }
}
void XuatDanhSachSinhVienDiemNhoHon5(LIST l)
{
    for (NODE* k = l.pHead; k != NULL; k = k->pNext)
    {
        if (k->data.DTB < 5)
        {
            XuatSinhVien(k->data);
        }
    }
}
void SapXepSinhVienTheoTangDan(LIST &l)
{
    for (NODE* k = l.pHead; k != NULL; k = k->pNext)
    {
        for (NODE* g = k->pNext; g != NULL; g = g->pNext)
        {
            if (g->data.DTB  < k->data.DTB) swap(g->data, k->data);
        }
    }
}
void XoaCacSinhVienCoNamSinhTruoc2000(LIST& l)
{
    NODE* g = new NODE;
    for (NODE* k = l.pHead; k != NULL; k = k->pNext)
    {
        if (k->data.namsinh < 2000)
        {
            NODE* h = k;
            g->pNext = k->pNext;
            delete h;
            return;
        }
        g = k;
    }
}
void HuyVaXuatDanhSach(LIST& l)
{
    int dem = 1;
    while(l.pHead !=NULL)
    {
        NODE* p = l.pHead;
        cout << " XUAT SINH VIEN " <<dem<< endl;
        XuatSinhVien(p->data);
        l.pHead = l.pHead->pNext;
        delete p;
        dem++;
    }
}
void Menu(LIST& l)
{
    int luachon;
    while (69)
    {
        system("cls");
        cout << "===========MENU============" << endl;
        cout << "1.Nhap Sinh Vien Vao Danh Sach Bang Cach Them Vao Dau" << endl;
        cout << "2.Nhap Sinh Vien Vao Danh Sach Bang Cach Them Vao Cuoi" << endl;
        cout << "3. Xuat Danh Sach Sinh Vien" << endl;
        cout << "4.Xuat Danh Sach Sinh Vien Co Diem Trung Binh Nho Hon 5" << endl;
        cout << "5.Xoa Sinh Vien Co Nam Sinh Truoc 2000" << endl;
        cout << "6.Sap xep sinh vien theo thu tu tang dan DTB" << endl;
        cout << "7.Xoa all, truoc khi xoa in ra" << endl;
        cout << "0. Thoat" << endl;
        cout << "===========END========" << endl;
        cout << "Nhap lua chon" << endl;
        cin >> luachon;
        if (luachon > 8 || luachon < 1)
        {
            cout << " Nhap lai lua chon" << endl;
            system("pause");

        }
        if (luachon == 1)
        {
            SinhVien a;
            NhapSinhVien(a);
            NODE* p = KhoiTaoNODE(a);
            ThemVaoDau(l, p);
        }
        if (luachon == 2)
        {
            SinhVien a;
            NhapSinhVien(a);
            NODE* p = KhoiTaoNODE(a);
            ThemVaoCuoi(l, p);
        }
        if (luachon == 3)
        {
            XuatDanhSach(l);
            system("pause");
        }
        if (luachon == 4)
        {
            XuatDanhSachSinhVienDiemNhoHon5(l);
            system("pause");
        }
        if (luachon == 5)
        {
            XoaCacSinhVienCoNamSinhTruoc2000(l);
        }
        if (luachon == 6)
        {
            SapXepSinhVienTheoTangDan(l);
        }
        if (luachon == 7)
        {
            HuyVaXuatDanhSach(l);
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
    KhoiTao(l);
    Menu(l);
    return 0;
}
