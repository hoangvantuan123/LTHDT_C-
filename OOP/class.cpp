#include<iostream>
#include<string>
using namesace std;
//Nhap xuat thong tin cua mot hoc sinh(ten, dia chi, diem toan, diem van)
class HocSinh
{
    private:
        string HoTen, DiaChi;
        float DiemToan, DiemVan;
        //Co hai cach dinh nghia cho phuong thuc cua class
    public:
        //cach1 khai bao dinh nghia trong class
        void Xuat()
        {
            //thuc thi o day
            fflush(stdin);
            cout<<"\n Nhap ten hs";
            getline(cin,HoTen);
            fflush(stdin);
            cout<<"\n Nhap dia chi: ";
            getline(cin,DiaChi);
            cout<<"\n Nhap diem toan";
            cin>>DiemToan;
            cout<<"\n Nhap diem van";
            cin>>DiemVan;
        }
            //cach hai khai bao trong class va dinh nghia ben ngoai
            void Xuat();
};

//Kieu tra ve cua phuong thuc TenClass::TenPhuongThuc(){//viet code o day}
void HocSinh::Xuat()
{
    //thuc thi o day
    cout<<"\n Ho ten: "<<HoTen;
    cout<<"\n  Dia chi"<<DiaChi;
    cout<<"\n Diem Toan"<<DiemToan;
    cout<<"\n Diem Van"<<DiemVan;


}
int main()
{
    HocSinh HS;
    HS.Xuat();//Tinh dong goi
    system("pause");
    return 0
}