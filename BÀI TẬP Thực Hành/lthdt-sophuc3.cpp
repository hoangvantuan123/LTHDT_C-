
/* // De:Tinh tong 2 so phuc, chong toan tu +, >>, <<;
dung ham tao va ham huy
 */
#include <iostream>
#include <stdio.h>

using namespace std;

// Kbao bao lop
class SoPhuc
{
private:
    float a, b;

public:
    // Ham tao
    SoPhuc();
    SoPhuc(float x);
    SoPhuc(float x, float y);
    // Ham huy
    ~SoPhuc();

    SoPhuc operator+(SoPhuc &p2);

    // Ham ban
    friend istream &operator>>(istream &cin, SoPhuc &p);
    friend ostream &operator<<(ostream &cout, SoPhuc &p);
};
//======Chuong trinh chinh====================
int main()
{
    // Tao 3 doi tuong so phuc
    SoPhuc p1, p2, tong;

    // Nhap
    cout << "Nhap vao so phuc p1:\n";
    cin >> p1; // Uoc gi duoc cin>>p1;

    cout << "Nhap vao so phuc p2:\n";
    cin >> p2;

    // Tinh tong 2 so phuc
    tong = p1 + p2;

    // Dua ra
    cout << "\nSo phuc p1: " << p1; // Uoc gi cout<<p1
    cout << "\nSo phuc p2: " << p2;
    cout << "\nTong cua so phuc p1 va p2 la: " << tong;

    cout << endl;
    return 0;
}
//=====Dinh nghia ham=========================
SoPhuc::SoPhuc() {}
SoPhuc::SoPhuc(float x) {}
SoPhuc::SoPhuc(float x, float y)
{
}
// Ham huy
SoPhuc::~SoPhuc() {}

SoPhuc SoPhuc::operator+(SoPhuc &p2)
{
    SoPhuc tong;

    tong.a = a + p2.a;
    tong.b = b + p2.b;

    return tong;
}

// Ham ban - ham thong thuong
istream &operator>>(istream &cin, SoPhuc &p)
{
    cout << "Nhap vao phan thuc: ";
    cin >> p.a;
    cout << "Nhap vao phan ao: ";
    cin >> p.b;

    return cin;
}
//-------------------------------------------
ostream &operator<<(ostream &cout, SoPhuc &p)
{
    if (p.b >= 0)
        cout << p.a << " + " << p.b << "j";
    else
        cout << p.a << " - " << -p.b << "j";

    return cout;
}
