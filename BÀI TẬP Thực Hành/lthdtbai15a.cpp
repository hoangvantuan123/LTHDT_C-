
/* DE: Bài 15(lthdtbai15a.cpp): Tính diện tích và chu vi hình tam giác có 3 cạnh a,b,c.
Yc lam theo phuong phap lap trinh cau truc 3 canh a, b, c nhap tu ban phim */

#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

//===Chuong trinh chinh===
int main()
{
    float a,b,c,cv,dt;
    cout<<"Nhap cac canh tam giac \n";
    cin>>a>>b>>c;
    if(a>=b+c || b>=a+c || c>=a+b)
	cout<<"Ba canh vua nhap ko phai la canh cua tam giac, nhap lai";
    else
    {
	cv=a+b+c;
	cout<<"Chu vi tam giac la: "<<cv;
	float p=(a+b+c)/2.0;
	dt=sqrt(p*(p-a)*(p-b)*(p-c));
	cout<<"\nDien tich tam giac la: "<<dt;
    }
	cout<<endl;
	return 0;
}
//===Dinh nghia ham===
