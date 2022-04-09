/*
Bài 25(lthdtbai25.cpp): Viết chương trình nhập vào một thời gian có giờ và phút.
Tính và đưa ra màn hình thời gian sau n phút nhập vào từ bàn phím.
Yêu cầu thêm:
1) Sử dụng toán tử nhập >> để nhập vào thời gian ở dạng h:m
2) Sử dụng toán tử xuất << để đưa ra thời gian ở dạng h:mm
3) Sử dụng toán tử cộng + để cộng thời gian với số phút n và trả về thời gian
4) Tự động khởi tạo thời gian có giờ, phút bằng 0.
*/
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop doi tuong thoi gian
class ThoiGian
{
    private:
        int gio,phut;

    public:
        ThoiGian();
        ThoiGian operator+(int n);

        //Ham ban
                //Ham ban
        friend istream& operator>>(istream &cin,ThoiGian &tg);
        friend ostream& operator<<(ostream &cout,ThoiGian &tg);
};

//===chuong trinh chinh===
int main()
{
    //Tao doi tuong thoi gian
    ThoiGian bd,kt;

    //Khai bao bien
    int n;

    cout<<"Nhập vào thời gian bắt đầu ";
    cin>>bd;
    cout<<"Nhập vào số phút n = ";
    cin>>n;

    //Cong thoi gian bat dau voi so phut n
    kt = bd + n;

    //Dua ra kq
    cout<<"Thời gian sau "<<n<<" phút là: "<<kt;
    cout<<endl;
    return 0;
}
//===dinh nghia ham===
ThoiGian::ThoiGian():gio(0),phut(0)
{

}

ThoiGian ThoiGian::operator+(int n)
{
    ThoiGian tg;

    //Cong thoi gian voi n phut de trong doi tuong tg
    tg.gio = gio;
    tg.phut = phut + n;

    //Hieu chinh gio va phut cua tg sao 0<=gio<=23, 0<=phut<=59
    tg.gio += tg.phut/60;
    tg.phut = tg.phut%60;
    tg.gio = tg.gio%24;

    //Tra ve thoi gian sau khi cong n phut
    return tg;
}

//Ham ban
istream& operator>>(istream &cin,ThoiGian &tg)
{
    char kt;

    cout<<"(dang h:m): ";
    cin>>tg.gio>>kt>>tg.phut;

    return cin;
}

ostream& operator<<(ostream &cout,ThoiGian &tg)
{
    printf("%d:%02d",tg.gio,tg.phut);

    return cout;
}

