
//DE:
//Bài 16(lthdtbai16.cpp): Đọc vào bán kính và màu nền (Xanh, Đỏ, Tím, Vàng) của n hình tròn
//từ tệp văn bản "hinhtron.txt". Đưa ra màn hình bán kính, màu nền, diện tích và chu vi
//của các hình tròn. Tính tổng diện tích và chu vi của n hình tròn.
//Đếm số lượng hình tròn có nền màu Xanh, Đỏ, Tím, Vàng.



#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;

//Khai bao lop
class HinhTron
{
    private:
	float r;
	char color[7];
    public:
	void khoiTao(float r, const char* color);
	void duaRa();
	float tinhCV();
	float tinhDT();
	int demHinhCungMau();
};

//===Chuong trinh chinh===
int main()
{
    //Tao doi tuong
    HinhTron ht;

    ifstream fin("hinhtron.txt");
    int n;
    fin>>n;
    //Tao mang dong chua doi tuong
    HinhTron *dshinh=new HinhTron[n];

    float r, sumCV, sumDT;

    //Tinh chu vi va dien tich
    cout<<endl;
    return 0;
}
//===Dinh nghia ham==
void HinhTron::khoiTao(float r, const char* color)
{
}
void HinhTron::duaRa()
{

}
float HinhTron::tinhCV()
{
    return 2*3.14*r;
}
float HinhTron::tinhDT()
{
    return 3.14*r*r;
}
int HinhTron::demHinhCungMau()
{
}

