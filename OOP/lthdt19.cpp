//Bài 19(lthdtbai19.cpp): Cho điểm A(x1,y1) và điểm B(x2,y2). Tính khoảng cách AB.
#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

//Khai bao lop
class Diem
{
    private:
        int x,y;

    public:
        float operator-(const Diem &p2);

        //Ham ban
        friend istream& operator>>(istream &cin,Diem &p);
        friend ostream& operator<<(ostream &cout,Diem &p);
};


//===Chuong trinh chinh===
int main()
{
    //Tao 2 doi tuong diem A,B
    Diem A,B;

    //Nhap toa do hai diem A,B
    cout<<"Nhập vào tọa độ điểm A:\n";
    cin>>A;
    cout<<"Nhập vào tọa độ điểm B:\n";
    cin>>B;

    //Tinh khoang cach AB
    float kc = A-B;

    //Dua ra toa do hai diem
    cout<<"\nTọa độ các điểm:";
    cout<<"\nA"<<A;
    cout<<"\nB"<<B;

    //Dua ra khoang cach hai diem
    printf("\nKhoảng cách AB là: %.1f",kc);

    cout<<endl;
    return 0;
}
//===Dinh nghia ham===
float Diem::operator-(const Diem &p2)
{
    return sqrt((p2.x-x)*(p2.x-x) + (p2.y-y)*(p2.y-y));
}


//Ham ban - ham thong thuong, nam ngoai doi tuong
istream& operator>>(istream &cin,Diem &p)
{
    cout<<"Nhập tọa độ (dạng x y): ";
    cin>>p.x>>p.y;

    return cin;
}

ostream& operator<<(ostream &cout,Diem &p)
{
    printf("(%0.1f,%0.1f)",p.x,p.y);

    return cout;
}

