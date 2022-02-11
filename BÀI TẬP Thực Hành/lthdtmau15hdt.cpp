
//De:Bài 15(lthdtbai15.cpp): Bài 15 (phiên bản 3, lthdtbai15hdt.cpp). Tính diện tích và chu vi hình tam giác có 3 cạnh a,b,c. Y/c làm theo phương pháp lập trình hướng đối tượng, 3 cạnh a, b, c đọc vào từ bàn phím hoặc tệp văn bản 'tamgiac.txt'.

#include<iostream>
#include<fstream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

using namespace std;

//khai bao class
class TamGiac
{
    private:
	float a,b,c;

    public:
	float tinhCV();
	float tinhDT();

	//Ham ban
	friend istream& operator>>(istream &cin, TamGiac &tg);
	friend ifstream& operator>>(ifstream &fin, TamGiac &tg);
	friend ostream& operator<<(ostream &cout, TamGiac &tg);
};
//===chuong trinh chinh===
int main()
{
    //Tao 1 doi tuong tam giac
    TamGiac tg;

    //Tao doi tuong tep vao
    ifstream fin("tamgiac.txt");

    //Nhap vao kich thuoc tam giac
    //cin>>tg;
    fin>>tg;

    //Dua ra kich thuoc tam giac
    cout<<tg;

    //Dua ra dt va cv
    printf("\nDiện tích của tam giác là: %.1f",tg.tinhDT());
    printf("\nChu vi của tam giác là: %.1f",tg.tinhCV());

    cout<<endl;
    return 0;
}
//===dinh nghia ham thanh vien===
float TamGiac::tinhCV()
{
    return a+b+c;
}

float TamGiac::tinhDT()
{
    float p = (a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

istream& operator>>(istream &cin, TamGiac &tg)
{
    //Nhap vao 3 canh tam giac
    do
    {
	cout<<"Nhập vào 3 cạnh của tam giác: ";
	cin>>tg.a>>tg.b>>tg.c;

	if(tg.a+tg.b<=tg.c || tg.a+tg.c<=tg.b || tg.b+tg.c<=tg.a) //Kiểm tra 3 canh có phải 3 cạnh của một tam giác không
	    cout<<"3 số vừa nhập không phải 3 cạnh tam giác. Nhập lại.\n";
    }
    while(tg.a+tg.b<=tg.c || tg.a+tg.c<=tg.b || tg.b+tg.c<=tg.a);

    return cin;
}

ifstream& operator>>(ifstream &fin, TamGiac &tg)
{
    float x,y,z;

    fin>>x>>y>>z;
    if(x+y>z && x+z>y && y+z>x)
    {
	tg.a=x; tg.b=y; tg.c=z;
    }
    else cout<<"\n3 số trên tệp không phải 3 cạnh tam giác.";

    return fin;
}

ostream& operator<<(ostream &cout, TamGiac &tg)
{
    printf("a=%.1f; b=%.1f; c=%.1f",tg.a,tg.b,tg.c);

    return cout;
}


