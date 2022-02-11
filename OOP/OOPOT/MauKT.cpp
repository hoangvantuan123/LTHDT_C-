//De: Tinh dien tich be mat va the tich cua hinh tru
//Biet hinh tru la hinh tron co them chieu cao

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
        float tinhDT();
        float tinhTT();
};
//===Chuong trinh chinh===
int main()
{
//Tao 1 doi tuong hinh tru ten ht
    HinhTru ht;
    ht.nhap();
    cout<<"Dien tich be mat hinh tru: "<<ht.tinhDT();
    cout<<"\nThe tich hinh tru: "<<ht.tinhTT();
    cout<<endl;
    return 0;
}
//===Dinh nghia ham===
void HinhTron::nhap()
{
    cout<<"Nhap ban kinh r: ";
    cin>>r;
}
float HinhTron::tinhDT()
{
    return 3.14*r*r;
}
float HinhTron::tinhCV()
{
    return 2*3.14*r;
}
void HinhTru::nhap()
{
    HinhTron::nhap();
    cout<<"Nhap chieu cao h: ";
    cin>>h;
}
float HinhTru::tinhDT()
{
    return HinhTron::tinhCV()*h + 2*HinhTron::tinhDT();
}
float HinhTru::tinhTT()
{
    return HinhTron::tinhDT()*h;
}
