
//De: 6
/*
Bài 16(lthdtbai16.cpp): Đọc vào bán kính và màu nền (Xanh, Đỏ, Tím, Vàng) của n hình tròn
từ tệp văn bản "hinhtron.txt". Đưa ra màn hình bán kính, màu nền, diện tích và chu vi
của các hình tròn. Tính tổng diện tích và chu vi của n hình tròn.
Đếm số lượng hình tròn có nền màu Xanh, Đỏ, Tím, Vàng.
*/

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

//Khai bao lop
class HinhTron
{
    private:
	float r;
	char mauNen[7];

    public:
	void thietLapR(float r);
	void thietLapMauNen(const char *mauNen);
	void hien();
	float tinhDT();
	float tinhCV();
	int layMaMau();
};

//===chuong trinh chinh===
int main()
{

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void HinhTron::thietLapR(float r)
{
    this->r = r;
}

void HinhTron::thietLapMauNen(const char *mauNen)
{
    strcpy(this->mauNen,mauNen);
}

void HinhTron::hien()
{
    cout<<"Ban Kinh:\n"<<r;
    cout<<"Mau nen:\n"<<mauNen;
    cout<<"Chu vi:\n"<<2*3.14*r;
    cout<<"Dien tich:\n"<<3.14*r*r;
}

float HinhTron::tinhDT()
{
    return 3.14*r*r;
}

float HinhTron::tinhCV()
{
    return 2*3.14*r;
}

int HinhTron::layMaMau()
{

}


