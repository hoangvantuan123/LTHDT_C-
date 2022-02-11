//De: Cai dat da hinh dong
//Tinh dien tich hinh chu nhat va hinh tron
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop
class hinh
{
        private:

        public:
                virtual void nhap()=0; //Ham ao thuan tuy
                virtual float tinhDT()=0; //Ham ao thuan tuy
};

class hinhCN:public hinh
{
        private:
                float a,b;

        public:
                void nhap();
                float tinhDT();
};

class hinhTR:public hinh
{
        private:
                float r;

        public:
                void nhap();
                float tinhDT();
};
//===chuong trinh chinh===
int main()
{
        //Khai bao con tro lop co so
        hinh *p1,*p2;

        //Tao 1 doi tuong hinhCN va 1 doi tuong hinhTR
        p1 = new hinhCN;
        p2 = new hinhTR;

        //Thuc hien da hinh dong
        p1->nhap();
        p2->nhap();

        cout<<"\nDien tich hinh chu nhat la: "<<p1->tinhDT();
        cout<<"\nDien tich hinh tron la: "<<p2->tinhDT();

        //Huy doi tuong hinhCN va hinhTR
        delete p1;
        delete p2;

        cout<<endl;
        return 0;
}
//===dinh nghia ham===
//Ham lop hinhCN
void hinhCN::nhap()
{
        cout<<"Nhap vao 2 canh hinh chu nhat: ";
        cin>>a>>b;
}

float hinhCN::tinhDT()
{
        return a*b;
}

//Ham lop hinhTR
void hinhTR::nhap()
{
        cout<<"Nhap vao ban kinh hinh tron: ";
        cin>>r;
}

float hinhTR::tinhDT()
{
        return 3.14*r*r;
}
