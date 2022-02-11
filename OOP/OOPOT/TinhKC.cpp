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
        void nhap();
        void xuat();
        float tinhKhoangCach(const Diem &b);
};

//===Chuong trinh chinh===
int main(){
    //Tao hai doi tuong diem
    Diem A, B;

    //Nhap toa do cua hai diem
    cout << "Nhap toa do cua diem A:\n";
    A.nhap();
    cout << "Nhap toa do cua diem B:\n";
    B.nhap();

    //Tinh khoang cach giua hai diem va in ra man hinh
    cout << "Toa do diem A la: ";
    A.xuat();
    cout << "\nToa do diem B la: ";
    B.xuat();
    cout << "\nKhoang cach giua 2 diem A va B la: " << A.tinhKhoangCach(B) << endl; 
}
//===Dinh nghia ham===
Diem::Diem(): x(0), y(0)
{
    //x=0;
    //y=0;
}
void Diem::nhap()
{
    cout << "x= ";
    cin >> x;
    cout << "y= ";
    cin >> y;
}
void Diem::xuat()
{
    printf("(%d;%d)", x, y);
}
float Diem::tinhKhoangCach(const Diem &b)
{
    return sqrt((this->x - b.x)*(this->x - b.x)+(this->y - b.y)*(this->y - b.y));
}