
/* Bài 1: Thời gian có giờ và phút, giờ có giá trị trong
khoảng 0-23, phút có giá trị trong khoảng 0-59.
Nhập vào thời gian bắt đầu một ca thi và số phút
làm bài thi. Tính thời gian kết thúc ca thi. Yêu cầu sử
dụng toán tử nhập >> và toán tử xuất << để nhập
vào và đưa ra thời gian ở dạng h:mm, sử dụng toán
tử + để cộng thời gian với số phút, thời gian được
khởi tạo tự động với giờ và phút bằng 0 hoặc khởi
tạo bằng giờ, phút cho trước. */


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

    cout<<"Nhap vao thoi gian bat dau mot ca thi ";
    cin>>bd;
    cout<<"Nhap vao so phut lam bai thi n = ";
    cin>>n;

    //Cong thoi gian bat dau voi so phut n
    kt = bd + n;

    //Dua ra kq
    cout<<"Thoi gian sau "<<n<<" phút là: "<<kt;
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
