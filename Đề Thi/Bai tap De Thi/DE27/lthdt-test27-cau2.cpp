// Ho ten:
// MaSV:
// Lop:
// De:
/*
Câu 2: TÍnh t?ng các ch? s? c?a m?t s? nguyên ..
Yêu c?u trong chýõng tr?nh có s? d?ng danh sách
liên k?t ðõn ð? ch?a các ch? s? c?a s? nguyên
*/

#include <iostream>
#include <stdio.h>

using namespace std;

// Khai bao lop
class SList
{
private:
    struct node
    {
        int infor;
        node *link;
    } * F;

public:
    SList();
    ~SList();
    void lastInsert(int x);
    int remove(); // xóa nút d?u c?a ds
    bool empty(); // ki?m tra ds r?ng
};

//===chuong trinh chinh===
int main()
{
    SList SL;

    int n, sum = 0;
    cout << "Nhap vao :";
    cin >> n;
    while (n > 0)
    {
        SL.lastInsert(n % 10);
        n /= 10;
        while (!SL.empty())
        {
            sum += SL.remove();
        };
    };

    cout << "Tong cac chu so cua la: " << sum;

    cout << endl;
    return 0;
}
//===dinh nghia ham===
SList::SList() : F(NULL)
{
}

SList::~SList()
{

    while (F)
    {
        node *P = F;
        F = F->link;
        delete P;
    }
}

void SList::lastInsert(int x)
{
    // 1.Tao nut moi
    node *N = new node;
    N->infor = x;
    N->link = NULL;

    N->link = F;
    F = N;
}

int SList::remove()
{
    if (F == NULL)
        return 0;
    node *P = F;
    int x = F->infor;
    F = F->link;
    delete P;
    return x;
}

bool SList::empty()
{
    if (F == NULL)

        return 1;
    return 0;
}
