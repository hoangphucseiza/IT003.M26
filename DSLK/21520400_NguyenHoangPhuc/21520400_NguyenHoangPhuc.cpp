#include <iostream>
#include <string>

using namespace std;

struct SV
{
    string name;
    int mssv;
    int namsinh;
    float diemtb;
};

struct NODE
{
    SV* info;
    NODE* pNext;
};

struct LIST
{
    NODE* pHead;
    NODE* pTail;
};

// 
void CreateEmptyList(LIST& L)
{
    L.pHead = L.pTail = NULL;
}

void CreateSV(SV* sva)
{
    cin.ignore();
    cout << "Nhap Ten sinh vien: \n";
    cin.ignore();
    getline(cin, sva->name);
    cout << "Nhap Ma so cua sinh vien : ";
    cin >> sva->mssv;
    cout << "Nhap nam sinh cua sinh vien : ";
    cin >> sva->namsinh;
    cout << "Nhap diem trung binh cua sinh vien : ";
    cin >> sva->diemtb;
}

NODE* CreateNode()
{
    NODE* p;
    p = new NODE;

    SV* sva = new SV;
    CreateSV(sva);

    if (p == NULL) exit(1);
    p->info = sva;
    p->pNext = NULL;
    return p;
}

void AddHead(LIST& L, NODE* p)
{
    // NODE* p;
    // p = CreateNode(x);
    if (L.pHead == NULL)
    {
        L.pHead = p;
        L.pTail = L.pHead;
    }
    else
    {
        p->pNext = L.pHead;
        L.pHead = p;
    }
}


void AddTail(LIST& L, NODE* p)
{
    // NODE* p;
    // p = CreateNode(x);
    if (L.pHead == NULL)
    {
        L.pHead = p;
        L.pTail = L.pHead;
    }
    else
    {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

void OutputNode(NODE* p)
{
    cout << "----SV---/n";
    cout << "Ten  : " << p->info->name << endl;
    cout << "MSSV : " << p->info->mssv << endl;
    cout << "Náminh  : " << p->info->namsinh << endl;
    cout << "Diem TB : " << p->info->diemtb << endl;

}

void OutputList(LIST L)
{
    for (NODE* p = L.pHead; p != NULL; p = p->pNext)
        OutputNode(p);
}
void OutputListDuoi5(LIST L)
{
    cout << "Danh sach sinh vien diem trung binh duoi 5\n";
    for (NODE* p = L.pHead; p != NULL; p = p->pNext)
        if ((p->info->diemtb) < 5.0)
            OutputNode(p);
}
bool RemoveHead(LIST& L)
{
    NODE* p;
    if (L.pHead != NULL)
    {
        p = L.pHead;
        L.pHead = L.pHead->pNext;
        if (L.pHead == NULL)
            L.pTail = NULL;

        delete p;
        return 1;
    }
    return 0;
}

void Cau1(LIST& L)
{
    int n;
    cout << "Nhap so sv: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        NODE* p;
        p = CreateNode();
        AddHead(L, p);
    }

    cout << "Nhap thanh cong \n";
    OutputListDuoi5(L);

}

void Cau2(LIST& L)
{
    int n;
    cout << "Nhap so sv: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        NODE* p;
        p = CreateNode();
        AddTail(L, p);
    }

    cout << "Nhap thanh cong \n";
    OutputList(L);
}
void Cau3(LIST& L)
{
    int n;
    cout << "Nhap so sv: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        NODE* p;
        p = CreateNode();
        AddTail(L, p);
    }
    cout << "Nhap thanh cong \n";
    OutputListDuoi5(L);

}
void Cau4(LIST& L)
{
    int n;
    cout << "Nhap so sv: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        NODE* p;
        p = CreateNode();
        AddTail(L, p);
    }
    cout << "Nhap thanh cong \n";
    for (NODE* p = L.pHead; p != NULL; p = p->pNext)
        OutputNode(p);

}
int main()
{
    LIST L;
    CreateEmptyList(L);
    int chon;
    do {
        cout << "* CHUONG TRINH QUAN LY DS SINH VIEN *" << endl;
        cout << "1. Nhap va xuat danh sach sinh vien vao dau danh sach" << endl;
        cout << "2. Nhap va xuat danh sach sinh vien vao cuoi danh sach" << endl;
        cout << "3. In ra DS sinh vien co DTB < 5" << endl;
        cout << "4. Xoa cac sinh vien co nam sinh truoc nam 2000" << endl;
        cout << "5. Sap xep sinh vien theo thu tu tang dan DTB" << endl;
        cout << "6. Xoa tat ca sinh vien trong danh sach" << endl;
        cout << "0. Thoat CT" << endl;
        cout << "***************************************" << endl;
        cout << "Ban chon so: ";
        cin >> chon;
        switch (chon) {
        case 0: cout << "Dang thoat CT....!"; break;
        case 1: Cau1(L); break;
        case 2: Cau2(L); break;
        case 3: Cau3(L); break;
        case 4: Cau4(L); break;
        default:
            cout << "Vui long chon tu 0 -> 6." << endl;
            break;
        }
        cout << endl;
    } while (chon != 0);
    return 0;

}