
//DE:
/*Bài 39(lthdtbai39.cpp): Một nhân sự luôn có họ tên và ngày sinh.
Sinh viên là một loại nhân sự có thêm mã sinh viên và điểm tbc.
Nhập vào thông tin của một sinh viên. Đưa ra màn hình các thông tin về sinh viên có kèm theo
đánh gia, nếu điểm TBC >=8.0 thì đánh giá là sinh viên giỏi.*/


#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdio_ext.h>

using namespace std;

//Khai bao lop
class NhanSu
{
    private:
	string hoten;
	string ngaysinh;
    public:
	void nhap();
	void duaRa();
};
class SinhVien:public NhanSu
{
    private:
	string msv;
	float diemtb;
    public:
	void nhap();
	void duaRa();
};
//===Chuong trinh chinh===
int main()
{
    SinhVien sv;
    cout<<"Nhập thông tin sinh viên: \n";
    sv.nhap();
    cout<<"\nDanh sách sinh viên đã nhập:";
    sv.duaRa();
    cout<<endl;
    return 0;
}
//===Dinh nghia ham===
void NhanSu::nhap()
{
    cout<<"Nhập họ tên: ";
    __fpurge(stdin);
    getline(cin,hoten);
    cout<<"Nhập ngày sinh: ";
     __fpurge(stdin);
    getline(cin,ngaysinh);

}
void NhanSu::duaRa()
{
    cout<<"\nHọ tên: "<<hoten;
    cout<<"\nNgày sinh: "<<ngaysinh;
}
void SinhVien::nhap()
{
    cout<<"Nhập mã sinh viên: ";
  __fpurge(stdin);
    getline(cin,msv);
    cout<<"Nhập điểm trung bình: ";
    cin>>diemtb;
    NhanSu::nhap();
}
void SinhVien::duaRa()
{
    NhanSu::duaRa();
    cout<<"\nMã sinh viên: " <<msv;
    cout<<"\nĐiểm trung bình: "<<diemtb;
    if(diemtb>=8.0)
	cout<<"\nSinh viên giỏi ";
}
