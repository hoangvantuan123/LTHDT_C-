#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

// Khai báo lớp trừu tượng cho lớp hình
class Hinh
{
private:
public:
    virtual void nhap() = 0;
    virtual float tinhDT() = 0;
};

// Khai báo lớp hình chữ nhật
class HinhCN : public Hinh
{
private:
    float a, b;

public:
    void nhap();
    float tinhDT();
};

// Khai báo lớp hình tam giác
class HinhTG : public Hinh
{
private:
    float a, b, c;

public:
    void nhap();
    float tinhDT();
};

// Khai báo lớp hình tròn
class HinhTron : public Hinh
{
private:
    float r;

public:
    void nhap();
    float tinhDT();
    float tinhCV();
};

// Khai báo lớp hình trụ
class HinhTru : public HinhTron
{
private:
    float h;

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
// Các hàm lớp hình chữ nhật
void HinhCN::nhap()
{
    cout << "Nhap vao 2 canh hinh chu nhat: ";
    cin >> a >> b;
}

float HinhCN::tinhDT()
{
    return a * b;
}

// Các hàm lớp hình tam giác
void HinhTG::nhap()
{
    do
    {
        cout << "Nhap vao 3 canh tam giac: ";
        cin >> a >> b >> c;

        if (a + b <= c || a + c <= b || b + c <= a)
            cout << "3 so da nhap khong phai 3 canh tam giac. Nhap lai.\n";
    } while (a + b <= c || a + c <= b || b + c <= a);
}

float HinhTG::tinhDT()
{
    float p = (a + b + c) / 2;

    return sqrt(p * (p - a) * (p - b) * (p - c));
}

// Các hàm lớp hình tròn
void HinhTron::nhap()
{
    cout << "Nhap vao ban kinh hinh tron: ";
    cin >> r;
}

float HinhTron::tinhDT()
{
    return 3.14 * r * r;
}

float HinhTron::tinhCV()
{
    return 2 * 3.14 * r;
}

// Các hàm lớp hình trụ
void HinhTru::nhap()
{
    // Nhập vào bán kinh r
    HinhTron::nhap();

    // Nhập chiều cao h
    cout << "Nhập vào chiều cao hình trụ: ";
    cin >> h;
}

float HinhTru::tinhDT()
{
    return 2 * HinhTron::tinhDT() + HinhTron::tinhCV() * h;
}

// Ham thong thuong
Hinh *nhapKT()
{
    Hinh *h;
    char chon;

    cout << "Lua chon hinh de nhap kich thuoc (1-TG,2-CN,3-Tron,4-Tru): ";
    cin >> chon;

    // Tao doi tuong hinh theo lua chon
    switch (chon)
    {
    case '1':
        h = new HinhTG;
        break;
    case '2':
        h = new HinhCN;
        break;
    case '3':
        h = new HinhTron;
        break;
    case '4':
        h = new HinhTru;
        break;
    default:
        h = new HinhTG;
    }

    // Dung da hinh dong de nhap kich thuoc doi tuong hinh da tao
    h->nhap();

    // Tra ve hinh da nhap kich thuoc
    return h;
}

void hienDT(Hinh *h)
{
    // Dung da hinh dong de tinh va dua ra dien tinh hinh
    printf("dien tich la: %0.1f", h->tinhDT());
}
