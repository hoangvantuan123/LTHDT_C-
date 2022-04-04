// Ho ten:
// MaSV:
// Lop:
// De: Tinh dien tich va chu vi hinh chu nhat co 2 canh a va b

#include <iostream>
#include <stdio.h>

using namespace std;

// Khai bao lop
class hinhCN
{
private:
    float a, b;

public:
    void nhap();
    float tinhDT();
    float tinhCV();
};

//===chuong trinh chinh===
int main()
{
    // Tao 1 doi tuong hinh chu nhat
    hinhCN hcn;

    // Tuong tac voi doi tuong
    hcn.nhap();

    cout << "Diện tích hình chữ nhật là: " << hcn.tinhDT();
    cout << "\nChu vi hình chữ nhật là: " << hcn.tinhCV();

    cout << endl;
    return 0;
}
//===dinh nghia ham===
void hinhCN::nhap()
{
    cout << "Nhập vào 2 cạnh hình chữ nhật: ";
    cin >> a >> b;
}

float hinhCN::tinhDT()
{
    return a * b;
}

float hinhCN::tinhCV()
{
    return (a + b) * 2;
}
