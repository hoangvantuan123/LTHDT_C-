//De: Tinh tong 2 so phuc
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop so phuc
class SoPhuc
{
        private:
                float a,b;

        public:
                void nhap();
                void hien();
                SoPhuc cong(const SoPhuc &p2);
};

//===chuong trinh chinh===
int main()
{
        SoPhuc p1,p2,tong;

        cout<<"Nhap vao so phuc p1:\n";
        p1.nhap();

        cout<<"Nhap vao so phuc p2:\n";
        p2.nhap();

        tong = p1.cong(p2);

        cout<<"\np1= ";p1.hien();
        cout<<"\np2= ";p2.hien();
        cout<<"\np1+p2= ";tong.hien();

        cout<<endl;
        return 0;
}
//===dinh nghia ham===
void SoPhuc::nhap()
{
        cout<<"Nhap phan thuc: ";cin>>a;
        cout<<"Nhap phan ao: ";cin>>b;
}

void SoPhuc::hien()
{
        if(b>=0) cout<<a<<" + j"<<b;
        else cout<<a<<" - j"<<-b;
}

SoPhuc SoPhuc::cong(const SoPhuc &p2)
{
        SoPhuc tg;

        tg.a = a + p2.a;
        tg.b = b + p2.b;

        return tg;
}

