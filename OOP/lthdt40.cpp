/*
Bài 40(lthdtbai40.cpp): Một nhân sự nói chung có họ tên và ngày sinh. Nhân viên trong
một công ty là một loại nhân sự có thêm mã nhân viên và hệ số lương. Cán bộ quản lý
trong công ty là một loại nhân viên có thêm chức vụ. Nhập vào danh sách n cán bộ quản lý.
Đưa ra danh sách cán bộ quản lý đã nhập.
*/
#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

class NhanSu
{
    private:
        char hoTen[41];
        char ngaySinh[11];

    public:
        void nhap();
        void hien();
};

class NhanVien:public NhanSu
{
    private:
        char maNV[11];
        float heSoLuong;

    public:
        void nhap();
        void hien();
};

class CBQL:public NhanVien
{
    private:
        char chucVu[30];

    public:
        void nhap();
        void hien();
};

//===chuong trinh chinh===
int main()
{
    //Khai bao bien
    int n;

    cout<<"Nhap vao so luong can bo quan ly: ";
    cin>>n;

    //Tao mang n doi tuong can bo quan ly
    CBQL *CB = new CBQL[n];

    cout<<"Nhap thong tin can bo quan ly:";
    for(int i=0;i<n;i++)
    {
        cout<<"\nCan bo thu "<<i+1<<":\n";
        CB[i].nhap();
    }

    cout<<"\nDanh sach can bo quan ly vua nhap la:\n";
    for(int i=0;i<n;i++)
    {
        CB[i].hien();
        cout<<"\n\n";
    }

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void NhanSu::nhap()
{
    cout<<"Nhap vao ho ten: ";
    scanf(" "); cin.get(hoTen,sizeof(hoTen));
    cout<<"Nhap vao ngay sinh (dd/mm/yyyy): ";
    cin>>ngaySinh;
}

void NhanSu::hien()
{
    cout<<"Ho ten: "<<hoTen;
    cout<<"\nNgay sinh: "<<ngaySinh;
}

void NhanVien::nhap()
{
    NhanSu::nhap();
    cout<<"Nhap vao ma nhan vien: ";cin>>maNV;
    cout<<"Nhap vao he so luong: ";cin>>heSoLuong;
}

void NhanVien::hien()
{
    NhanSu::hien();
    cout<<"Ma NV: "<<maNV;
    cout<<"He so luong: "<<heSoLuong;
}

void CBQL::nhap()
{
    NhanVien::nhap();
    cout<<"Nhap vao chuc vu: ";
    scanf(" "); cin.get(chucVu,sizeof(chucVu));
}

void CBQL::hien()
{
    NhanVien::hien();
    cout<<"\nChuc vu: "<<chucVu;
}

