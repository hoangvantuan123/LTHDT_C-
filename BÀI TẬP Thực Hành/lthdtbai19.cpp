
/* //DE: Bài 19(lthdtbai19.cpp): Cho điểm A(x1,y1) và
 điểm B(x2,y2).
Tính khoảng cách AB.
 */

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
	//Ham tao
	Diem();
	Diem(float x, float y);

	float tinhKC(const Diem &d);

	friend istream& operator >> (istream &cin, Diem &diem);
	friend ostream& operator << (ostream &cout, Diem &diem);
};
//===Chuong trinh chinh===
int main()
{
    //Tao doi tuong
    Diem A,B;

    //Nhap toa do hai diem
    cout<<"Nhập toạ độ điểm A:\n";
    cin>>A;
    cout<<"Nhập toạ độ điểm B:\n";
    cin>>B;

    //Tinh khoang cach va in ra man hinh
    cout<<"Toạ độ điểm A là: ";
    cout<<A;
    cout<<"\nToạ độ điểm B là: ";
    cout<<B;
    cout<<"\nKhoảng cách giữa hai điểm A và B là: "<<A.tinhKC(B)<<endl;
    return 0;
}
//===Dinh nghia ham===
Diem::Diem(float x, float y)
{
    this->x=x;
    this->y=y;
}
Diem::Diem(): x(0),y(0){}
istream& operator >> (istream &cin, Diem &diem)
{
    cout<<"x = ";
    cin>>diem.x;
    cout<<"y = ";
    cin>>diem.y;
    return cin;
}
ostream& operator << (ostream &cout, Diem &diem)
{
    printf("(%d;%d)",diem.x,diem.y);
    return cout;
}
float Diem::tinhKC(const Diem &d)
{
    return sqrt((this->x - d.x)*(this->x - d.x) + (this->y - d.y)*(this->y - d.y));
}
