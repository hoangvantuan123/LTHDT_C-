// Bài 40: Một nhân sự nói chung có họ tên và ngày sinh. Nhân viên trong
// một công ty là một loại nhân sự nhưng có thêm mã nhân viên và hệ số lương. Lãnh đạo
// trong công ty là một loại nhân viên có thêm chức vụ.
// Nhập vào thông tin của một số nhân viên
// và lãnh đạo trong công ty. Đưa ra các thông tin đã nhập.

#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

//Khai bao lop
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
        char manv[10];
        float hesoluong;
    public:
        void nhap();
        void duara();
};
class LanhDao:public NhanVien
{
    private:
        char chucvu[50];
    public:
        void nhap();
        void duara();
};
//===Chuong trinh chinh===
int main()
{
    LanhDao ld;
    cout<<"Nhap thong tin nhan vien: \n";
    ld.nhap();

    cout<<"Thong tin da nhap la: \n";
    ld.duara();

    cout<<endl;
    return 0;
}
//===Dinh nghia ham===
void NhanSu::nhap()
{
    cout<<"Nhap ho ten: ";
    scanf(" ");cin.get(hoTen,sizeof(hoTen));
    cout<<"Nhap ngay sinh (dd/mm/yyyy): ";
    cin>>ngaySinh;
}
void NhanSu::duara()
{
    cout<<"Ho ten: "<<hoTen;
      cout<<"\nNgay sinh: "<<ngaySinh;
}
void NhanVien::nhap()
{
    cout<<"Nhap ma nhan vien: ";
    cin.getline(manv, 50, '\n');
    cout<<"Nhap he so luong: ";
    cin>>hesoluong;
    cin.ignore(INT_MAX, '\n');
    NhanSu::nhap();
}

void NhanVien::duara()
{
    cout<<"Ma nhan vien: "<<manv;
    cout<<"\nHe so luong: "<<hesoluong;
    NhanSu::duara();
}
void LanhDao::nhap()
{
    cout<<"Nhap chuc vu: ";
    cin.getline(chucvu, 50, '\n');
    fflush(stdin);
    NhanVien::nhap();
}

void LanhDao::duara()
{
    cout<<"Chuc vu: "<<chucvu;
    NhanVien::duara();
}

