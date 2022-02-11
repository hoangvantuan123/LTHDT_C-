#include<iostream>
using namespace std;
//Phuongthuc co doi tuong la tham so truyyen vao
//yc tinh tong cua 2 gio (so gio va so phut)
//2h56p +1h4 = 4h
class ThoiGian
{
    private:
        int Gio, Phut;
    public:
        void Nhap(int gio, int phut);//co hai tham so truyen vao
        {
            Gio=gio;
            Phut= phut;
        }
        void Xuat()
        {
            cout<<Gio<<"h"<<Phut<<"p";

        }
        ThoiGian Tong(ThoiGian T1, Thoigian T2)
        {
            Phut=T1.Phut+T2.Phut;
            Gio=Phut/60;
            Phut=Phut%60;
            Gio=Gio+T1.Gio+T2.Gio;
            return *this;
        }
};
int main()
{
    ThoiGian T1,T2,T3;
    T1.Nhap(2,56);
    T2.Nhap(1,4);
    T3.Tong(T1,T2);
    T3.Xuat();
    
    system("pause");
    return 0;
}