//Bài 15(lthdtbai15.cpp): Tính diện tích và chu vi hình tam giác có 3 cạnh a,b,c.
#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

//Khai bao lop tam giac
class TamGiac
{
    private:
        float a,b,c;

    public:
        void nhap();
        float tinhDT();
        float tinhCV();
};

//===chuong trinh chinh===
int main()
{
    //Tao 1 doi tuong tam giac
    TamGiac htg;

    //Tuong tac voi doi tuong tam giac
    htg.nhap();

    printf("Dien tich tam giac la: %0.1f",htg.tinhDT());
    printf("\nChu vi tam giac la: %0.1f",htg.tinhCV());

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void TamGiac::nhap()
{
    do
    {
        cout<<"Nhap vao 3 canh cua tam giac: ";
        cin>>a>>b>>c;

        if(a+b<=c || a+c<=b || b+c<=a)
            cout<<"3 so da nhap khong phai 3 canh tam giac. Nhap lai!\n";
    }
    while(a+b<=c || a+c<=b || b+c<=a);
}

float TamGiac::tinhDT()
{
    float p=(a+b+c)/2;

    return sqrt(p*(p-a)*(p-b)*(p-c));
}

float TamGiac::tinhCV()
{
    return a+b+c;
}
