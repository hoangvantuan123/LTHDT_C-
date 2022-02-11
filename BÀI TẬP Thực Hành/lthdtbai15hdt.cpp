
//DE: Tinh dien tich chu vi hinh tam giac cos 3 canh a,b,c. Yc lam theo pp lap trinh huong doi tuong

#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;
//Khai bao lop
class HinhTamGiac
{
    private:
	float a,b,c;

    public:
	void input();
	float tinhCV();
	float tinhDT();
};
//===Chuong trinh chinh===
int main()
{
    //Khoi tao doi tuong
    HinhTamGiac htg;

    //Nhap
    htg.input();

    //Dua ra
    cout<<"Chu vi tam giac la: "<<htg.tinhCV();
    cout<<"\nDien tich tam giac la: "<<htg.tinhDT();
    cout<<endl;
    return 0;
}
//===Dinh nghia ham===
void HinhTamGiac::input()
{
    cout<<"Nhap vao 3 canh tam giac ";
    cin>>a>>b>>c;

    if(a>=b+c || b>=c+a || c>= a+b)
	cout<<"Ba canh da nhap ko phai la ba canh tam giac";
	cin>>a>>b>>c;

