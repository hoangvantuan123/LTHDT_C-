
//De: So Phuc

#include<iostream>
#include<stdio.h>

using namespace std;
//Khai bao lop
class SoPhuc
{
    private:
	float a,b;
    public:
	SoPhuc();
	SoPhuc operator+(SoPhuc &sp);

	friend istream& operator>>(istream &cin,SoPhuc &sp);
	friend ostream& operator<<(ostream &cout,SoPhuc &sp);
};
//===Chuong Trinh Chinh===
int main()
{
    //Tạo đối tượng số phức
    SoPhuc z1,z2,z;
    cout<<"Nhap so phuc z1: ";
    cin>>z1;
    cout<<"Nhap so phuc z2: ";
    cin>>z2;

    z=z1+z2;
    cout<<"Ket qua: ";
    cout<<"\nz1= "<<z1;
    cout<<"\nz2= "<<z2;
    cout<<"\nz= "<<z;
    cout<<endl;
    return 0;
}
//===Dinh nghia ham===
SoPhuc::SoPhuc()
{
    a=0;
    b=0;
}

SoPhuc SoPhuc::operator+(SoPhuc &sp)
{
    SoPhuc z;
    z.a=a+sp.a;
    z.b=b+sp.b;
    return z;
}

istream& operator>>(istream &cin,SoPhuc &sp)
{
   cout<<"Nhap phan thuc: ";
   cin>>sp.a;
   cout<<"Nhap phan ao: ";
   cin>>sp.b;
   return cin;
}

ostream& operator<<(ostream &cout,SoPhuc &sp)
{
    if(sp.b>=0)
	cout<<sp.a<<" + "<<sp.b<<" i ";
    else
	cout<<sp.a<<" - "<<-sp.b<<" i ";
    return cout;
}

