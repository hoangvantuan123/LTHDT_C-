//Ho Ten: Hoang Thi Hoa
//Lop: K63TH
//MaSV: 637634
//Bai slide chuong 4

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

//Khai bao lop
class SinhVien
{
    private:
	//Bien chung
	Static int STT;

	//Bien rieng
	int msv;
	char ten;
	float diemtb;

    public:
	//Ham chung
	static int laySL();

	//Ham rieng
	void nhap();
	void hien();
};
//Dinh nghia bien cua lop
int SinhVien::STT=10;
//===Chuong trinh chinh===
int main()
{
    //khai bao bien
    SinhVien *ds[100];
    char traloi;
    int i=0,n;
    do
    {
	//Tao doi tuong sinh vien dong 
	ds[i] = new SinhVien;

	//Nhap thong tin sinh vien
	ds[i]->nhap();

	//Hoi nhap tiep khong
	cout<<"Co nhap tiep khong(c/k)? ";
	cin>>traloi;
    }
    while(traloi=='c' || traloi=='C');

    //Lay so luong sinh vien
    n = SinhVien::LaySL();
    cout<<"\n\nSo luong sinh vien da nhap la: "<<n;
    cout<<"\nThong tin ve cac sinh vien da nhap la ";
    for(i=0;i<n;i++)
    {
	cout"\nSinh vien "<<i+1<<":\n";
	ds[i]->hien();

    int n,i;
    cout<<"Nhap so luong sinh vien: ";
    cin>>n;
    //Mang dong doi tuonng sv
    SinhVien *dssv = new SinhVien[n];

    //Nhap dssv


    cout<<endl;
    return 0;
}
//===Dinh nghia ham===
void SinhVien::nhap()
{
    //tang tu dong ma sinh vien
    msv=++STT;

    cout<<"Nhap ma sinh vien: "<<msv;
    cout<<"\nNhap ten sinh vien: "; 
    scanf(" ");
    cin.get(ten,sizeof(ten));
    cout<<"\nNhap diem trung binh: ";
    cin>>diemtb;
}
void SinhVien::hien()
{
    cout<<"Ma sinh vien: "<<msv;
    cout<<"Ten sinh vien: "<<ten;
    cout<<"Diem trung binh: "<<diemtb;
}
int SinhVien::laySL()
{
    return STT-10;
}
