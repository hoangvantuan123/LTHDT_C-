//Tinh dien tich cua cac hinh tam giac, hinh chu nhat va hinh tron
//Nguoi dung nhap khi nao chan thi thoi
//Da hinh dong ham ao

#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

//Khai bao lop HinhHoc
class HinhHoc
{
    private:
        
    public:
        virtual void nhap()=0;
        virtual float tinhChuVi()=0;
        virtual float tinhDienTich()=0;
};

//Khai bao lop HinhTron
class HinhTron:public HinhHoc
{
    private:
        int bankinh;
    public:
        void nhap();
        float tinhChuVi();
        float tinhDienTich();
};

//Khai bao lop HinhTamGiac
class HinhTG:public HinhHoc
{
    private:
        int a,b,c;
    public:
        void nhap();
        float tinhChuVi();
        float tinhDienTich();
};

//Khai bao lop HinhCN
class HinhCN:public HinhHoc
{
    private:
        int chieuDai,chieuRong;
    public:
        void nhap();
        float tinhChuVi();
        float tinhDienTich();
};

void xuLyThongTin(HinhHoc *h, int luaChon);
//===Chuong trinh chinh===
int main()
{
    //Khai bao bien
    batDau:
    HinhHoc *h;
    cout << "===========================\n";
    cout << "Nhap hinh ban muon tinh chu vi va dien tich\n";
    cout << "1. Hinh tron\n";
    cout << "2. Hinh TG\n";
    cout << "3. Hinh CN\n";
    cout << "\n\nLua chon cua ban: ";
    int luaChon;
    cin >> luaChon;
    xuLyThongTin(h, luaChon);
    cout << "\n\n=================\n";
    cout << "Ban co muon tiep tuc khong:\n";
    cout << "1. Yes\n";
    cout << "2. No\n";
    cin >> luaChon;
    if(luaChon == 1)     goto batDau;
    cout << endl;    
    return 0;
}
//===Dinh nghia ham
void HinhTron::nhap()
{
    cout << "Nhap ban kinh: ";
    cin >> bankinh;
}
float HinhTron::tinhChuVi()
{
    return 3.14*2*bankinh;
}
float HinhTron::tinhDienTich()
{
    return 3.14*bankinh*bankinh;
}
void HinhTG::nhap()
{
    cout << "Nhap ba canh a, b, c cua tam giac";
    cin >> a >> b >> c;
}
float HinhTG::tinhChuVi()
{
    return a + b + c;
}
float HinhTG::tinhDienTich()
{
    float p = (a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
void HinhCN::nhap()
{
    cout << "Nhap chieu rong: ";
    cin >> chieuRong;
    cout << "Nhap chieu dai ";
    cin >> chieuDai;
}
float HinhCN::tinhChuVi()
{
    return (chieuRong + chieuDai)*2;
}
float HinhCN::tinhDienTich()
{
    return (chieuRong*chieuDai);
}
void xuLyThongTin(HinhHoc *h, int luaChon)
{
    switch (luaChon)
    {
    case 1:
        h = new HinhTron();
        break;
    case 2:
        h = new HinhTG();
        break;
    case 3:
        h = new HinhCN();
        break;
    }
        h -> nhap();
        cout << "Chu vi: " << h -> tinhChuVi()<<endl;
        cout << "Dien tich: " << h -> tinhDienTich()<<endl;
}