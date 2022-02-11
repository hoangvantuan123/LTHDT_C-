//De: Minh hoa khai bao va dinh nghia ham tao, ham huy
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop so phuc
class SoPhuc
{
        private:
                float a,b;

        public:
                SoPhuc(); //Ham tao khong doi so
                SoPhuc(float x); //Ham tao 1 doi so
                SoPhuc(float x,float y); //Ham tao 2 doi so
                ~SoPhuc(); //Ham huy
                SoPhuc operator+(const SoPhuc &p2);

                //Ham ban
                friend istream& operator>>(istream &cin,SoPhuc &p);
                friend ostream& operator<<(ostream &cout,SoPhuc &p);
};

//===chuong trinh chinh===
int main()
{
        SoPhuc p1=2,p2(-3,6),tong;

        /*
        cout<<"Nhap vao so phuc p1:\n";
        cin>>p1;

        cout<<"Nhap vao so phuc p2:\n";
        cin>>p2;

        tong = p1 + p2;
        */

        tong=2.5;

        cout<<"\np1= ";cout<<p1;
        cout<<"\np2= ";cout<<p2;
        cout<<"\ntong= ";cout<<tong;

        cout<<endl;
        return 0;
}
//===dinh nghia ham===
SoPhuc::SoPhuc():a(0),b(0)
{

}

SoPhuc::SoPhuc(float x):a(x),b(0)
{
        cout<<"\nHam tao 1 doi so da thuc hien.";
}

SoPhuc::SoPhuc(float x,float y):a(x),b(y)
{

}

SoPhuc::~SoPhuc()
{

}

SoPhuc SoPhuc::operator+(const SoPhuc &p2)
{
        SoPhuc tg;

        tg.a = a + p2.a;
        tg.b = b + p2.b;

        return tg;
}

//Ham thong thuong, khong nam trong doi tuong
istream& operator>>(istream &cin,SoPhuc &p)
{
        cout<<"Nhap phan thuc: ";cin>>p.a;
        cout<<"Nhap phan ao: ";cin>>p.b;

        return cin;
}
ostream& operator<<(ostream &cout,SoPhuc &p)
{
        if(p.b>=0) cout<<p.a<<" + j"<<p.b;
        else cout<<p.a<<" - j"<<-p.b;

        return cout;
}

