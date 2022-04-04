/*
Bài 23(lthdtbai23.cpp): Đọc danh sách n mặt hàng từ tệp văn bản "mathang.txt";
mỗi mặt hàng có tên hàng, số lượng, đơn giá. Tính tổng tiền của n mặt hàng.
*/
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>

using namespace std;

//Khai bao lop mat hang
class MatHang
{
    private:
        char tenHang[31];
        int soLuong;
        float donGia;

    public:
        void duaVao(const char *tenHang,int soLuong,float donGia);
        void duaRa();
        float tinhTien();
};
//===chuong trinh chinh===
int main()
{
    //Tao doi tuong tep vao
    ifstream fin("mathang.txt");

    //Khai bao bien
    int n,soLuong;
    char tenHang[31],tg[2];
    float donGia,tongTien=0;

    //Doc so luong mat hang tu tep
    fin>>n;

    //Tao mang n doi tuong mat hang de chua thong tin cua n mat hang
    MatHang *a = new MatHang[n];

    //Doc n mat hang tu tep vao mang doi tuong, dua ra man hinh, tinh tong tien
    cout<<"Danh sách mặt hàng đọc từ tệp là:";
    for(int i=0;i<n;i++)
    {
        //Doc ky tu Enter de dua con tro tep xuong dong duoi
        fin.getline(tg,sizeof(tg));

        //Doc cac thong tin cua mat hang i
        fin.getline(tenHang,sizeof(tenHang),'\t');
        fin>>soLuong>>donGia;

        //Dua mat hang thu i vao doi tuong mat hang i
         a[i].duaVao(tenHang,soLuong,donGia);

         //Dua mat hang thu i ra man hinh
         cout<<"\nMặt hàng thứ "<<i+1<<":\n";
         a[i].duaRa();
         cout<<endl;

         //Cong tien cua mat hang i vao tongTien
         tongTien += a[i].tinhTien();
     }

     printf("\nTổng tiền của %d mặt hàng là: %0.1f",n,tongTien);

     cout<<endl;
     return 0;
 }
 //===dinh nghia ham===
 void MatHang::duaVao(const char *tenHang,int soLuong,float donGia)
 {
     strcpy(this->tenHang,tenHang);
     this->soLuong = soLuong;
     this->donGia = donGia;
 }

 void MatHang::duaRa()
 {
    cout<<"Tên hàng: "<<tenHang;
    cout<<"\nSố lượng: "<<soLuong;
    cout<<"\nĐơn giá: "<<donGia;
    cout<<"\nThành tiền: "<<soLuong*donGia;
}

float MatHang::tinhTien()
{
    return soLuong * donGia;
}


