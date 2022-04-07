
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop nhan su
class NhanSu
{
    private:
        char hoTen[36];
        char ngaySinh[11];

    public:
        virtual void nhap();
        virtual void hien();
};
class NhanVien:public NhanSu
{
	 private:
        char maNV[11];
        float heSoLuong;

    public:
        void nhap();
        void hien();
};
class CBQL:public NhanVien
{
	private:
        char chucVu[30];

    public:
        void nhap();
        void hien();
};
class GiaoVien:public NhanVien
{
		private:
        char monDay[31];

    public:
        void nhap();
        void hien();
};

NhanSu *nhapTT();
void hienTT(NhanSu *x);

//===chuong trinh chinh===
int main()
{
   	NhanSu *ds[100];

   	//Khai bao bien
   	int n= 0;
   	char traLoi;

   	do
    {
        // Nhap thong tin
        ds[n++] = nhapTT();

        // Hoi co nhap tiep ko
        cout << "\nCo nhap tiep khong(c/k)? ";
        cin >> traLoi;
    } while (traLoi == 'c' || traLoi == 'C');

	// Dua ra danh sach nhan su da nhap
	cout<<"\nDanh sach nhan su da nhap la: ";
	for ( int i=0 ; i<n ; i++)
	{
		//Dua ra so thu tu nhap
		cout<<"\nSST "<<i+1<<":" ;
		hienTT(ds[i]);
		cout<<endl;
	}

     cout<<endl;
     return 0;
 }
 //===dinh nghia ham===
 //Ham lop nhan su
 void NhanSu::nhap()
 {
     cout<<"Nhap vao ho ten: ";
     scanf(" "); cin.get(hoTen,sizeof(hoTen));
     cout<<"Nhap vao ngay sinh (dd/mm/yyyy): ";
    cin>>ngaySinh;
 }

 void NhanSu::hien()
 {
     cout<<"\n\tHo ten: "<<hoTen;
       cout<<"\n\tNgay sinh: "<<ngaySinh;
 }


void NhanVien::nhap()
{
    NhanSu::nhap();
    cout<<"Nhap vao ma nhan vien: ";cin>>maNV;
    cout<<"Nhap vao he so luong: ";cin>>heSoLuong;
}

void NhanVien::hien()
{
    NhanSu::hien();
    cout<<"\n\tMa NV: "<<maNV;
    cout<<"\n\tHe so luong: "<<heSoLuong;
}

void CBQL::nhap()
{
    NhanVien::nhap();
    cout<<"Nhap vao chuc vu: ";
    scanf(" "); cin.get(chucVu,sizeof(chucVu));
}

void CBQL::hien()
{
    NhanVien::hien();
    cout<<"\n\tChuc vu: "<<chucVu;
}

void GiaoVien::nhap()
{
	NhanVien::nhap();
	cout<<"Nhap vao mon day: ";
	scanf(" "); cin.get(monDay,sizeof(monDay)) ;
}

void GiaoVien::hien()
{
	NhanVien::hien();
	cout<<"\n\tMon day: "<<monDay;
}

// Ham thong thuong
NhanSu *nhapTT()
{
    NhanSu *ns;
    char chon;

    // Lay lua chon
    cout << "Chon loai nhan su can nhap thong tin (1-NV , 2-CBQL, 3-GV): ";
    cin >> chon;

    // Tao doi tuong nhan su theo lua chon
    if (chon == '1')
    {
    	ns = new NhanVien;
	}

    else if(chon == '2')
    {
    	 ns = new CBQL;
	}
	else
		ns= new GiaoVien;


    // Dung da hinh donh de nhap thong tin cho doi tuong da tao
    ns->nhap();

    // Tra ve nhan su da nhap thong tin
    return ns;
}

void hienTT(NhanSu *x)
{
    // Dung da hinh dong de dua ra thong tin cua nhan su
    x->hien();
}



