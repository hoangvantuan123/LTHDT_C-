//Ho ten:
//MaSV:
//Lop:
//De:

#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop
class HinhTron
{
    private:
	float r;

    public:
	void nhap();
	float tinhDT();
	float tinhCV();
};

class HinhTru:public HinhTron
{
    private:
	float h;

    public:
	void nhap();
	float tinhDT(); //Tinh dien tich be mat
	float tinhTT(); //Tinh the tich
};

//===chuong trinh chinh===
int main()
{
    //Tao 1 doi tuong hinh tru
    HinhTru h;

    cout<<"Nhập vào kích thước hình trụ:\n";
    h.nhap();

    cout<<"\nDiện tích bề mặt của hình trụ là: "<<h.tinhDT();
    cout<<"\nThể tích của hình trụ là: "<<h.tinhTT();
    
    cout<<endl;
    return 0;
}
//===dinh nghia ham===
//Ham thanh vien lop hinh tron
void HinhTron::nhap()
{
    cout<<"Nhập vào bán kính: ";cin>>r;
}

float HinhTron::tinhDT()
{
    return 3.14*r*r;
}

float HinhTron::tinhCV()
{
    return 2*3.14*r;
}

//Ham thanh vien lop hinh tru
void HinhTru::nhap()
{
    //Nhap ban kin
    HinhTron::nhap();

    //Nhap chieu cao
    cout<<"Nhập vào chiều cao: ";cin>>h;
}

float HinhTru::tinhDT()
{
    return 2*HinhTron::tinhDT() + HinhTron::tinhCV()*h;
}

float HinhTru::tinhTT()
{
    return HinhTron::tinhDT()*h;
}

