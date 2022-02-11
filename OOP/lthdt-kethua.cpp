//De: Ke thua
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop
class HinhTron
{
        private:
                float r;

        public:
                void nhap();
                float tinhDT();
                float tinhCV();
};

class HinhTru:public HinhTron
{
        private:
                float h;

        public:
                void nhap();
                float tinhDT();
                float tinhTT();
};
//===chuong trinh chinh===
int main()
{
        //Tao doi tuong hinh tru
        HinhTru h;

        cout<<"Nhap vao kich thuoc hinh tru:\n";
        h.nhap();

        cout<<"\nDien tich be mat hinh tru la: "<<h.tinhDT();
        cout<<"\nThe tich hinh tru la: "<<h.tinhTT();

        cout<<endl;
        return 0;
}
//===dinh nghia ham===
void HinhTron::nhap()
{
        cout<<"Nhap vao ban kinh r: ";
        cin>>r;
}

float HinhTron::tinhDT()
{
        return 3.14*r*r;
}

float HinhTron::tinhCV()
{
        return 2*3.14*r;
}
//Dinh nghia ham lop hinh tru
void HinhTru::nhap()
{
        HinhTron::nhap();
        cout<<"Nhap vao chieu cao: ";
        cin>>h;
}

float HinhTru::tinhDT()
{
        return HinhTron::tinhCV()*h + 2*HinhTron::tinhDT();
}

float HinhTru::tinhTT()
{
        return HinhTron::tinhDT()*h;
}
