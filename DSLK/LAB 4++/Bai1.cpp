#include <iostream>
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
void KhoiTaoSTACK(STACK& s)
{
    s.pHead = NULL;
    s.pTail = NULL;
}
bool IsEmpty(STACK s)
{
    if (s.pHead == NULL) return true;
    else return false;
}
NODE* KhoiTaoNODE(int x)
{
    NODE* p = new NODE;
    if (p == NULL) return NULL;
    p->data = x;
    p->pNext = NULL;
    return p;
}
void Push(STACK& s, NODE *p)
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
    if (IsEmpty(s))
    {
        return;
    }
    else
    {
        NODE* p = s.pHead;
        x = p->data;
        s.pHead = s.pHead->pNext;
        delete p;
    }
   
}
int main()
{
    STACK s;
    KhoiTaoSTACK(s);
    int n;
    cout << " Nhap so " << endl;
    cin >> n;
    while (n != 0)
    {
        int x = n % 2;
        NODE* p = KhoiTaoNODE(x);
        Push(s, p);
        n /= 2;
    }
    while (!IsEmpty(s))
    {
        int x;
        Pop(s, x);
        cout << x;
    }
    return 0;
}

