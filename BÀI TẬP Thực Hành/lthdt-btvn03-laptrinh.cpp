
//De bai: Tinh khoang cach giua hai diem tren mat phang A(x1,y1) va B(x2,y2)

#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;
//Khai bao lop doi tuong
class Diem
{
    private:
        float x,y;
    public:
        float operator-(const Diem&td);
        friend istream& operator>>(istream &cin,Diem &d);
        friend ostream& operator<<(ostream &cout,Diem &d);
};
//===Chuong trinh chinh===
int main()
{
    //Khoi tao hai doi tuong diem
    Diem A,B;
    //Nhap diem
    cout<<"Nhap toa do A(x1,y1)\n";cin>>A;
    cout<<"Nhap toa do B(x2,y2)\n";cin>>B;
    //In diem
    cout<<"Toa do da nhap la: ";
    cout<<"A"<<A<<" ; ";
    cout<<"B"<<B;
    //Tinh khoang cach hai diem tren mp
    float kc=A-B;
    cout<<"\nKhoang cach giua hai diem la: "<<kc;
    cout<<endl;
    return 0;
}
//===Dinh nghia ham===
//Diem - Diem
float Diem::operator-(const Diem &td)
{
    return sqrt((td.x-x)*(td.x-x) + (td.y-y)*(td.y-y));
}
//Ham ban
istream& operator>>(istream &cin,Diem &d)
{
    cin>>d.x>>d.y;
    return cin;
}
ostream& operator<<(ostream &cout,Diem &d)
{
    printf("(%0.1f,%0.1f)",d.x,d.y);
    return cout;
}


