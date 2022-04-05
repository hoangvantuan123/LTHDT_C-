// Ho Ten :Hoang Van Tuan
// MaSV :650024
// Lop : K65CNTTA
// De :`
/*
   Câu 1: Một nhân sự nói chung có họ tên và ngày
   sinh . Nhân viên trong một công ty là một loại nhân
   sự nhưng có thêm mã nhân viene và hệ số lươn .
   Cán bộ quản lý trong công ty là một loại nhân viên
   nhưng có thêm chức vụ và hệ số phụ cấp chức vụ .
   Nhập vào thông tin của n cán bộ quản lý trong công
   ty . Đưa ra thông tin các cán bộ quản lý đã nhập .
   Tìm cán bộ quản lý có lương cao nhất . Lương của
   cán bộ quản lý được tính theo công thức : ( hệ số
   lương + hệ số phụ cấp chức vụ ) * 1490
   */

#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

//khai bao lop
class NhanSu
{
    private:
        char hoTen[31];
        char ngaySinh[11];
    public:
        void nhap();
        void duara();
};

class NhanVien:public NhanSu
{
    private:
        char maNV[10];
        float hsLuong;

    public:
        void nhap();
        void duara();
        void tinhLuong();
};
class CanBo:public NhanVien
{
    private:
        char chucVu[50];
        float hsPhuCap;

    public:
        void nhap();
        void duara();
         void tinhLuong();
};


//=== chuong trinh chinh ===
int main()
{
    //khai bao bien
    int n;

    cout <<"Nhap vao so luong can bo quan ly trong cong ty : ";
    cin >>n;

    // Tao mang n doi tuong can bo
    CanBo *id = new CanBo[n];

    cout<<"\nNhap thong tin nhan vien: \n";
    for(int i=0 ; i<n; i++)
    {
        cout<<"\n STT" <<i+1<<":\n";
        id[i].nhap();
    }

    cout<<"\n\nDanh sach thong tin da nhap la: \n";
    for( int i =0 ;i<n;i++)
    {
        id[i].duara();
        cout<<"\n\n";
    }


    cout<<endl;
    return 0;
}
//=== Dinh nghia ham ===
void NhanSu::nhap()
{
    cout<<"Nhap ho ten: ";
    scanf(" ");
    cin.get(hoTen,sizeof(hoTen));

    cout<<"Nhap ngay sinh (dd/mm/yyyy): ";
    cin>>ngaySinh;
}

void NhanSu::duara()
{
    cout<<"\nHo ten: "<<hoTen;
    cout<<"\nNgay sinh: "<<ngaySinh;
}

void NhanVien::nhap()
{
    cout<<"Nhap ma nhan vien: ";
    cin>>maNV;

    NhanSu::nhap();
    cout<<"Nhap he so luong: ";
    cin>>hsLuong;

}

void NhanVien::duara()
{
    cout<<"\nMa nhan vien: "<<maNV;

    NhanSu::duara();
    cout<<"\nHe so luong: "<<hsLuong;

}

void CanBo::nhap()
{
    cout<<"\nNhap chuc vu: ";
    scanf(" ");cin.get(chucVu,sizeof(chucVu));

    NhanVien::nhap();
    cout<<"Nhap he so phu cap chuc vu: ";
    cin>>hsPhuCap;

}

void CanBo::duara()
{

    cout<<"\nChuc vu: "<<chucVu;

    NhanVien::duara();
    cout<<"\nHe so phu cap chuc vu: " <<hsPhuCap;

}
float CanBo::tinhLuong()
{
    return  this->hsLuong + hsPhuCap *1490;
}

