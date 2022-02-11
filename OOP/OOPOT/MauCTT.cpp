//De: Nhap ao hai diem co toa do (x1,y1) va (x2,y2)
//Roi tinh khoang cach giua 2 diem. Su dung chong toan
//tu nhap, xuat va "-" de tinh khoang cach

#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

//===Khai bao lop Diem
class Diem{
    private: 
        int x,y;
    
    public:
        //Ham tao
        Diem();

        //Ham thanh vien
        friend istream& operator >> (istream &cin, Diem &diem);
        friend ostream& operator << (ostream &cout, Diem &diem);
        float operator - (const Diem &diem);
};

//===Chuong trinh chinh===
int main(){
    //Tao hai doi tuong diem
    Diem A, B;

    //Nhap toa do cua hai diem
    cout << "Nhap toa do cua diem A:\n";
    cin >> A;
    cout << "Nhap toa do cua diem B:\n";
    cin >> B;

    //Tinh khoang cach giua hai diem va in ra man hinh
    cout << "Toa do diem A la: ";
    cout << A;
    cout << "\nToa do diem B la: ";
    cout << B;
    cout << "\nKhoang cach giua 2 diem A va B la: " << A - B << endl; 
}
//===Dinh nghia ham===
Diem::Diem(): x(0), y(0)
{
    //x=0;
    //y=0;
}
istream& operator >> (istream &cin, Diem &diem)
{
    cout << "x= ";
    cin >> diem.x;
    cout << "y= ";
    cin >> diem.y;

    return cin;
}
ostream& operator << (ostream &cout, Diem &diem)
{
    printf("(%d;%d)", diem.x, diem.y);
    return cout;
}
float Diem::operator - (const Diem &diem)
{
    return sqrt((this->x - diem.x)*(this->x - diem.x)+(this->y - diem.y)*(this->y - diem.y));
}