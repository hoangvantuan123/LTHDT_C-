
// Bài 21(lthdtbai21.cpp): Tính tổng 2 ma trận nguyên: Cmxn = Amxn + Bmxn. Ma trận Amxn để trong
// tệp văn bản 'matran-A.txt', ma trận Bmxn để trong tệp văn bản 'matran-B.txt'.
//Đưa các ma trận ra màn hình theo định dạng hàng, cột.

#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;
// khai bao lop
class MaTran
{
private:
    enum
    {
        size = 10
    };
    int a[size][size];
    int m, n;

public:
    MaTran();
    MaTran operator+(const MaTran &right);

    friend ifstream &operator>>(ifstream &fin, MaTran &mt);
    friend ostream &operator<<(ostream &cout, MaTran &mt);
};
//===Chuong trinh chinh===
int main()
{
    MaTran A, B, C;

    ifstream finA("matran-A.txt");
    ifstream finB("matran-B.txt");

    finA >> A;
    finB >> B;

    cout << "Ma trận A\n";
    cout << A;
    cout << "Ma trận B\n";
    cout << B;

    C = A + B;

    cout << "Tổng hai ma trận là\n";
    cout << C;
    cout << endl;
    return 0;
}
//===Dinh nghia ham===
MaTran::MaTran() : m(0), n(0)
{
}
MaTran MaTran::operator+(const MaTran &right)
{
    MaTran tong;
    if (m == right.m && n == right.n)
    {
        // Tinh tong ma tran cung kich thuoc
        tong.m = m;
        tong.n = n;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                tong.a[i][j] = a[i][j] + right.a[i][j];
    }
    return tong;
}
ifstream &operator>>(ifstream &fin, MaTran &mt)
{
    fin >> mt.m >> mt.n;
    for (int i = 0; i < mt.m; i++)
        for (int j = 0; j < mt.n; j++)
            fin >> mt.a[i][j];
    return fin;
}
ostream &operator<<(ostream &cout, MaTran &mt)
{
    for (int i = 0; i < mt.m; i++)
    {
        for (int j = 0; j < mt.n; j++)
            printf("%5d", mt.a[i][j]);
        cout << endl;
    }
    return cout;
}
