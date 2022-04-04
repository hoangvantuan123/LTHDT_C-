/* #include<iostream>
class PhanSo
{
    private:
        int  TuSo,MauSo;

    public:
        PhanSo()
        {
            TuSo=0;
            MauSo=1;
        }

};
using namesapce std;
int main()
{
    PhanSo ps;
    system("pause");
    return 0;
}
 */

// phan so_operator.cpp : Defines the entry point for the console application.
#include <iostream>
using namespace std;
class PHANSO
{
private:
    int tu, mau;

public:
    PHANSO() {}
    PHANSO(int _tu, int _mau = 1)
    {
        tu = _tu;
        mau = _mau;
    }
    PHANSO(const PHANSO &src)
    {
        this->tu = src.tu;
        this->mau = src.mau;
    }
    void nhap()
    {
        cout << "nhap tu: ";
        cin >> tu;
        cout << "nhap mau: ";
        cin >> mau;
    }
    void xuat()
    {
        cout << "phan so:= ";
        dongian();
        cout << tu << "/" << mau << endl;
    }
    friend istream &operator>>(istream &ist, PHANSO &b)
    {
        cout << "nhap tu: ";
        ist >> b.tu;
        cout << "nhap mau: ";
        ist >> b.mau;
        return ist;
    }
    friend ostream &operator<<(ostream &ost, PHANSO &b)
    {
        b.dongian();
        ost << b.tu << "/" << b.mau << endl;
        return ost;
    }
    int ucln(int a, int b)
    {
        a = abs(a);
        b = abs(b);
        while (a != 0 && b != 0)
        {
            if (a > b)
                a -= b;
            else
                b -= a;
        }
        return a;
    }
    void dongian()
    {
        int uc = ucln(tu, mau);
        tu /= uc;
        mau /= uc;
    }
    friend PHANSO operator+(PHANSO a, PHANSO b);
    friend PHANSO operator-(PHANSO a, PHANSO b);
    friend PHANSO operator*(PHANSO a, PHANSO b);
};
PHANSO operator+(PHANSO a, PHANSO b)
{
    PHANSO temp;
    temp.tu = a.tu * b.mau + b.tu * a.mau;
    temp.mau = b.mau * a.mau;
    return temp;
}
PHANSO operator-(PHANSO a, PHANSO b)
{
    PHANSO temp;
    temp.tu = a.tu * b.mau - b.tu * a.mau;
    temp.mau = b.mau * a.mau;
    return temp;
}
PHANSO operator*(PHANSO a, PHANSO b)
{
    PHANSO temp;
    temp.tu = a.tu * b.tu - b.mau * a.mau;
    temp.mau = b.mau * a.mau;
    return temp;
}
int _tmain(int argc, _TCHAR *argv[])
{
    PHANSO a, b(1), c(2, 3);
    cin >> a;
    PHANSO Tong = a + b;
    cout << " Tong hai phan so " << a << "+" << b << "=" << Tong << endl;
    PHANSO Hieu = a - 5;
    cout << "Hieu=" << Hieu << endl;
    PHANSO Tich = 5 * c;
    cout << " Tich=" << Tich << endl;
    cin.get();
    cin.get();
    return 0;
}