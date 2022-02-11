/*
Bài 16(lthdtbai16.cpp): Đọc vào bán kính và màu nền (Xanh, Đỏ, Tím, Vàng) của n hình tròn
từ tệp văn bản "hinhtron.txt". Đưa ra màn hình bán kính, màu nền, diện tích và chu vi
của các hình tròn. Tính tổng diện tích và chu vi của n hình tròn.
Đếm số lượng hình tròn có nền màu Xanh, Đỏ, Tím, Vàng.
*/
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>

using namespace std;

//Khai bao lop
class hinhTron
{
    private:
        float r;
        char mauNen[6];

    public:
        void thietLap(float r,const char *mauNen);
        void hien();
        float tinhCV();
        float tinhDT();
        int layMaMau();
};

//===Chuong trinh chinh===
int main()
{
    //Tao doi tuong tep doc vao
    ifstream fin("hinhtron.txt");

    //Khai bao bien
    int n,i;

    //Doc vao so luong hinh tron
    fin>>n;

    //Tao mang dong n doi tuong hinh tron
    hinhTron *dshinh = new hinhTron[n];

    //Doc du lieu n hinh tron tu tep vao doi tuong
    float r,tongCV=0,tongDT=0;          //Bien luu ban kinh r va tong chu vi, dien tich
    char mauNen[6];                     //Xau ki tu luu ten mau nen
    int demHinhTR[4]={0};
    char tenMau[4][6]={"Xanh","Đỏ","Tím","Vàng"};

    for(i=0;i<n;i++)
    {
        //Doc ban kinh va mau nen tu file
        fin>>r>>mauNen;

        //Dua ban kinh r va mau nen mauNen vao doi tuong
        dshinh[i].thietLap(r,mauNen);

        //Dua ra ban kinh va mau nen
        printf("Hình tròn thứ %d:\n",i+1);
        dshinh[i].hien();
        cout<<endl;

        //Tinh tong chu vi va dien tich
        tongCV += dshinh[i].tinhCV();
        tongDT += dshinh[i].tinhDT();

        //Dem so luong hinh
        demHinhTR[dshinh[i].layMaMau()]++;
    }

    printf("\nTống diện tích %d hình tròn là: %0.1f",n,tongDT);
    printf("\nTống chu vi %d hình tròn là: %0.1f",n,tongCV);

    cout<<"\n\nSố lượng hình tròn theo các màu là:\n";
    for(i=0;i<4;i++) cout<<tenMau[i]<<": "<<demHinhTR[i]<<endl;

    //Huy mang doi tuong
    delete [] dshinh;

    cout<<endl;
    return 0;
}
//===Dinh nghia ham===
void hinhTron::thietLap(float r,const char *mauNen)
{
   this->r = r;
   strcpy(this->mauNen,mauNen);
}

void hinhTron::hien()
{
    printf("Bán kính: %0.1f; Màu nền: %s; Diện tích: %0.1f; Chu vi: %0.1f\n",r,mauNen,3.14*r*r,2*3.14*r);
}

float hinhTron::tinhCV()
{
    return 2*3.14*r;
}

float hinhTron::tinhDT()
{
    return 3.14*r*r;
}
int hinhTron::layMaMau()
{
    if(strcasecmp(mauNen,"Xanh")==0) return 0;
    if(strcasecmp(mauNen,"Đỏ")==0) return 1;
    if(strcasecmp(mauNen,"Tím")==0) return 2;
    if(strcasecmp(mauNen,"Vàng")==0) return 3;
}
