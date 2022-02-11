// Bài 41: Thời điểm là một loại ngày tháng và cũng là một loại thời gian
// nhưng có thêm địa điểm. Ngày tháng có ngày, tháng, năm. Thời gian có giờ và phút. Nhập vào một thời điểm,
// đưa ra địa điểm, ngày và thời gian của thời điểm đó ở dạng Địa điểm, ngày dd/mm/yy - h:mm.
// Ví dụ: Hà Nội, ngày 22/04/19 - 9:30.

#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

//Khai bao lop
class NgayThang
{
    private:
        int date;
        int month;
        int year;
    public:
        void import();
        void display();
};
class ThoiGian
{
    private:
        int hour;
        int minute;
    public:
        void import();
        void display();
};
class ThoiDiem:public NgayThang,public ThoiGian
{
    private: 
        char place[50];
        // string place;
    public:
        void import();
        void display();
};
//===Chuong trinh chinh===
int main()
{
    ThoiDiem td;
    cout<<"Nhap thong tin \n";
    td.import();
    cout<<"\nDua ra thong tin \n";
    td.display();

    cout<<endl;
    return 0;
}
//===Dinh nghia ham==
void NgayThang::import()
{
    cout<<"Date: ";
    cin>>date;
    cout<<"Month: ";
    cin>>month;
    cout<<"Year: ";
    cin>>year;
}
void NgayThang::display()
{
    cout<<"Date: "<<date<<"/"<<month<<"/"<<year;
}
void ThoiGian::import()
{
    cout<<"Hour: ";
    cin>>hour;
    cout<<"Minute: ";
    cin>>minute;
}
void ThoiGian::display()
{
    cout<<hour<<":"<<minute;
    
}
void ThoiDiem::import()
{
    cout<<"Place: ";
    cin.get(place, 20);
    // cin>>place;
    NgayThang::import();
    ThoiGian::import();
}
void ThoiDiem::display()
{
    cout<<place<<", ";
    NgayThang::display();
    cout<<" - ";
    ThoiGian::display();
}
