//Ho ten:
//MaSV:
//Lop:
//De: Cai dat bien va ham cua lop

#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop sinh vien
class SinhVien
{
    private:
	int maSV;
	char hoTen[31];
	float diemTBC;

	//Bien cua lop
	static int stt;

    public:
	void nhap();
	void hien();

	//Ham cua lop
	static int laySL();
};

//Dinh nghia bien cua lop
int SinhVien::stt=10;

//===chuong trinh chinh===
int main()
{
    SinhVien *ds[100];
    char traloi;
    int i=0,n;

    do
    {
	//Tao doi tuong sinh vien dong
	ds[i] = new SinhVien;
	
	//Nhap thong tin sv
	ds[i++]->nhap();

	//Hoi nhap tiep ko
	cout<<"Có nhập tiếp không(c/k)? ";
	cin>>traloi;
    }
    while(traloi=='c' || traloi=='C');
    
    //Lay so luong sv da nhap
    n = SinhVien::laySL();
    cout<<"\n\nSố lượng sinh viên đã nhập là: "<<n;
    cout<<"\nThông tin về các sv đã nhập là:";
    for(i=0;i<n;i++)
    {
	cout<<"\nSinh viên thứ "<<i+1<<":\n";
	ds[i]->hien();
	cout<<endl;
    }

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void SinhVien::nhap()
{
    //Tao ma sv
    maSV = ++stt;

    cout<<"Nhập thông tin của sinh viên có mã là: "<<maSV;
    cout<<"\nHọ tên: ";
    scanf(" ");cin.get(hoTen,sizeof(hoTen));
    cout<<"Điểm TBC: ";cin>>diemTBC;
}

void SinhVien::hien()
{
    cout<<"Mã sinh viên: "<<maSV;
    cout<<"\nHọ tên: "<<hoTen;
    cout<<"\nĐiểm TBC: "<<diemTBC;
}

int SinhVien::laySL()
{
    return stt-10;
}


