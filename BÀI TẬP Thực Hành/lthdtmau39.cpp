
//De:
/*
Bài 39(lthdtbai39.cpp): Một nhân sự luôn có họ tên và ngày sinh.
Sinh viên là một loại nhân sự có thêm mã sinh viên và điểm tbc.
Nhập vào thông tin của một sinh viên. Đưa ra màn hình các thông tin về sinh viên có kèm theo
đánh gia, nếu điểm TBC >=8.0 thì đánh giá là sinh viên giỏi.
*/


#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop
class NhanSu
{
    private: 
	char hoTen[31];
	char ngaySinh[11];

    public:
	void nhap();
	void hien();
};

class SinhVien:public NhanSu
{
    private:
	char MSV[7];
	float diemTBC;

    public:
	void nhap();
	void hien();
};

//===chuong trinh chinh===
int main()
{
    SinhVien sv;

    cout<<"Nhap thong tin sinh vien:\n";
    sv.nhap();

    cout<<"\nThong tin sinh vien da nhap la: \t";
    sv.hien();

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void NhanSu::nhap()
{
    cout<<"Nhap ho ten: ";
    scanf(" ");cin.get(hoTen,sizeof(hoTen));
    cout<<"Nhap ngay sinh (dd/mm/yyyy): ";
    cin>>ngaySinh;
}

void NhanSu::hien()
{
    cout<<"\nHo ten: "<<hoTen;
    cout<<"\nNgay sinh: "<<ngaySinh;
}

void SinhVien::nhap()
{
    NhanSu::nhap();
    cout<<"Nhap ma sinh vien: ";
    cin>>MSV;
    cout<<"Nhap diem TBC: ";
    cin>>diemTBC;
}

void SinhVien::hien()
{
    NhanSu::hien();
    cout<<"\nMa sinh vien: "<<MSV;
    cout<<"\nDiem TBC: "<<diemTBC;
    if(diemTBC >= 8.0)
	cout<<"\nDay la sinh vien gioi.\n";
}


