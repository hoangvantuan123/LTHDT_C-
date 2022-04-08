// Ho Ten :Hoang Van Tuan
// MaSV :650024
// Lop : K65CNTTA
// De :`
/*
   Câu 1: Cho t?p van b?n “diemmonhoc.txt” ch?a
   danh sách di?m môn h?c c?a n sinh viên, m?i sinh
   viên có thông tin v? mă sinh viên , tên( không có h?
   d?m) ,di?m ki?m tra , di?m thi . Đi?m môn h?c
   du?c tính b?ng 0.3 x Đi?m ki?m tra + 0,7 x Đi?m thi
   . Đ?m s? lu?ng và dua ra màn h́nh danh sách các
   sinh viên chua d?t ( có di?m môn h?c <4) . Yêu c?u
   s? d?ng toán t? nhâp >> và toán t? xu?t << d? nh?p
   vào và dua ra thông tin c?a t?ng sinh viên .
   */

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>

using namespace std;

// khai bao lop
class SinhVien
{
private:
    char maSV[11];
    char tenSV[12];
    float diemKTra, diemThi;

public:
    // Ham thanh vien
    friend istream &operator>>(istream &cin, SinhVien &sv);
    friend ostream &operator<<(ostream &cout, SinhVien &sv);
    float diemMH();
};

//=== chuong trinh chinh ===
int main()
{

    // Tao doi tuong tep doc vao
    ifstream fin("diemmonhoc.txt");

    if (!fin)
    {
        cout << "Khong doc duoc tep! ";
        return 1;
    }
    // Khai bao
    SinhVien ds;
    int n, i;

    // Doc tu tep
    fin >> n;
    cout<<"So Luong sinh vien trong tep la: "<<n<<"\n";
    cout << "Danh sach sinh vien duoc doc tu tep la: \n";
    for (i = 0; i < n; i++)
    {
        cout << "\nSST " << i + 1 << ":";
        fin >> ds;
        cout<< " "<<ds;

        cout<<"\t\tDiem mon hoc la: "<<ds.diemMH();
        if (ds.diemMH() < 4)
        {
            cout << "\t\tSinh vien chua dat!";
        }
    }

    cout << endl;
    return 0;
}
//=== Dinh nghia ham =

istream &operator>>(istream &cin, SinhVien &sv)
{
    cout << "\nMa Sinh Vien ";
    cin >> sv.maSV;

    cout << "\tTen Sin Vien ";
    cin >> sv.tenSV;

    cout << "\tDiem Kiem Tra ";
    cin >> sv.diemKTra;

    cout << "\tDiem Thi ";
    cin >> sv.diemThi;

    return cin;
}

ostream &operator<<(ostream &cout, SinhVien &sv)
{

    cout << "\n"
         << sv.maSV << "\t\t" << sv.tenSV << "\t\t" << sv.diemKTra << "\t\t" << sv.diemThi;
    return cout;
}

float SinhVien::diemMH()
{
    return 0.3 * diemKTra + 0.7 * diemThi;
}
