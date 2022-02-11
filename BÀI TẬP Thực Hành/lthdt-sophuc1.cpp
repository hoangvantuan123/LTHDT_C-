
//De:Tinh tong 2 so phuc

#include<iostream>
#include<stdio.h>

using namespace std;

//Kbao bao lop
class SoPhuc
{
    private:
	float a,b;

    public:
	void nhap();
	void hien();
	SoPhuc cong(SoPhuc &p2);
};
//======Chuong trinh chinh====================
int main()
{
    //Tao 3 doi tuong so phuc
    SoPhuc p1,p2,tong;

    //Nhap
    cout<<"Nhap vao so phuc p1:\n";
    p1.nhap();

    cout<<"Nhap vao so phuc p2:\n";
    p2.nhap();

    //Tinh tong 2 so phuc
    tong = p1.cong(p2);
    
    //Dua ra
    cout<<"\nSo phuc p1: ";p1.hien();
    cout<<"\nSo phuc p2: ";p2.hien();
    cout<<"\nTong cua so phuc p1 va p2 la: ";tong.hien();
    
    cout<<endl;
    return 0;
}
//=====Dinh nghia ham=========================
void SoPhuc::nhap()
{
    cout<<"Nhap vao phan thuc: ";
    cin>>a;
    cout<<"Nhap vao phan ao: ";
    cin>>b;
}
//-------------------------------------------
void SoPhuc::hien()
{
    if(b>=0) cout<<a<<" + "<<b<<"j";
    else cout<<a<<" - "<<-b<<"j";
}
//----------------------------------------
SoPhuc SoPhuc::cong(SoPhuc &p2)
{
    SoPhuc tong;

    tong.a = a + p2.a;
    tong.b = b + p2.b;
    
    return tong;
}
