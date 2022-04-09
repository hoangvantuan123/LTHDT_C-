/*
Câu 1: TÍnh di?n tích n h?nh, trong đó có c? h?nh ch?
nh?t và h?nh tr?n , h?nh ch? nh?t bi?t 2 c?nh, h?nh
tr?n bi?t bán kính. Yêu c?u trong chương tr?nh cài
đ?t đa h?nh đ?ng cho hàm nh?p kích thư?c và hàm
tính di?n tích
*/

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

class Hinh
{
private:
public:
    virtual void nhap() = 0;
    virtual float tinhDT() = 0;
};

class HinhCN : public Hinh
{
private:
    float a, b;

public:
    void nhap();
    float tinhDT();
};

class HinhTron : public Hinh
{
private:
    float r;

public:
    void nhap();
    float tinhDT();
};

// Khai bao ham thong thuong
Hinh *nhapKT();
void hienDT(Hinh *h);

//===Chuong trinh chinh===
int main()
{
    // Khai bao bien
    Hinh *dshinh[100];
    char traLoi;
    int n = 0;

    do
    {
        // Nhap kich thuoc
        dshinh[n++] = nhapKT();

        // Hoi co nhap tiep khong
        cout << "\nCo nhap tiep khong (c/k)? ";
        cin >> traLoi;
    } while (traLoi == 'c' || traLoi == 'C');

    // Dua ra danh sach hinh da nhap
    cout << "\nDien tich cac hinh da nhap la:\n";
    for (int i = 0; i < n; i++)
    {
        printf("\nHinh thu %d co ", i + 1);
        hienDT(dshinh[i]);
        cout << endl;
    }

    cout << endl;
    return 0;
}
//===Dinh nghia ham===
void HinhCN::nhap()
{
    // THong bao
    cout << "Nhap vao 2 canh a va b hinh chu nhat la :" << endl;
    cout << "Nhap vao canh a: ";
    cin >> a;
    cout << "Nhap vao canh b: ";
    cin >> b;
}

float HinhCN::tinhDT()
{
    return a * b;
}

void HinhTron::nhap()
{
    cout << "Nhap vao ban kinh hinh tron la  :" << endl;
    cout << "Nhap vao r la: ";
    cin >> r;
}

float HinhTron::tinhDT()
{
    return 3.14 * r * r;
}

// Ham thong thuong
Hinh *nhapKT()
{
    Hinh *h;
    char chon;

    cout << "Lua chon hinh de nhap kich thuoc (1-CN,2-Tron): ";
    cin >> chon;

    // Tao doi tuong hinh theo lua chon
    switch (chon)
    {
    case '1':
        h = new HinhCN;
        break;
    default:
        h = new HinhTron;
    }

    // Dung da hinh dong de nhap kich thuoc doi tuong hinh da tao
    h->nhap();

    // Tra ve hinh da nhap kich thuoc
    return h;
}

void hienDT(Hinh *h)
{
    // Dung da hinh dong de tinh va dua ra dien tinh hinh
    printf("Dien tich la: %0.1f", h->tinhDT());
}