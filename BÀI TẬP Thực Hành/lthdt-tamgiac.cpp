
//De bai: lap trinh huong doi tuong tinh chu vi va dien tich tam giac
#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

//Khai bao lop
class hinhTamgiac
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
    //Tao 1 doi tuong hinh tam giac
    hinhTamgiac htg;

    //Tuong tac voi doi tuong
    htg.nhap();

    
    cout<<"Diện tích hình tam giac là: "<<htg.tinhDT();
    cout<<"\nChu vi hình tam giac là: "<<htg.tinhCV();

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void hinhTamgiac::nhap()
{
    do{
        cout<<"Nhập vào 3 cạnh hình tam giac: ";
        cin>>a>>b>>c;
        if(a>=b+c || b>=a+c || c>=a+b)
	cout<<"Ba canh khong phai canh tam giac. Hay nhap lai!!!\n";
    }while(a>=b+c || b>=a+c || c>=a+b);
}

float hinhTamgiac::tinhDT()
{
    float p = (a+b+c)/2.0;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

float hinhTamgiac::tinhCV()
{
    return a+b+c;
}

