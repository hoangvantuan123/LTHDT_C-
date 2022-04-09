
/*
Bài 2: Tính diện tích các hình: hình chữ nhật có hai
cạnh a,b; hình tròn có bán kính r; hình hộp chữ nhật
có hai cạnh a,b và chiều cao h; hình trụ có bán kính r
và chiều cao h. Biết rằng hình hộp chữ nhật là một
loại hình chữ nhật được kéo cao lên với chiều cao h;
hình trụ là một loại hình tròn kéo cao lên với chiều
cao h. Nhập vào kích thước của n hình, trong đó có
cả hình chữ nhật, hình tròn, hình hộp chữ nhật và
hình trụ. Đưa ra màn hình diện tích các hình đã
nhập. Yêu cầu cài đặt đa hình động cho hàm nhập
kích thước và tính diện tích */

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

class Hinh
{
	private:

	public:
    virtual void nhap() = 0;
    virtual float tinhDT() = 0;
};


class HinhCN : public Hinh
{
private:
    float a, b;

public:
    void nhap();
    float tinhDT();
    float tinhCV();
};

class HinhTron : public Hinh
{
private:
    float r;

public:
    void nhap();
    float tinhDT();
     float tinhCV();

};


class HinhHopCN : public HinhCN
{
private:
    float h;

public:
    void nhap();
    float tinhDT();
};
class HinhTru:public HinhTron
{
	private:
    	float h;

	public:
    	void nhap();
    	float tinhDT();
 } ;

// Khai bao ham thong thuong
Hinh *nhapKT();
void hienDT(Hinh *h);

//===Chuong trinh chinh===
int main()
{
    // Khai bao bien
    Hinh *dshinh[100];
    char traLoi;
    int n = 0;

    do
    {
        // Nhap kich thuoc
        dshinh[n++] = nhapKT();

        // Hoi co nhap tiep khong
        cout << "\nCo nhap tiep khong (c/k)? ";
        cin >> traLoi;
    } while (traLoi == 'c' || traLoi == 'C');

    // Dua ra danh sach hinh da nhap
    cout << "\nDien tich cac hinh da nhap la:\n";
    for (int i = 0; i < n; i++)
    {
        printf("\nHinh thu %d co ", i + 1);
        hienDT(dshinh[i]);
        cout << endl;
    }

    cout << endl;
    return 0;
}
//===Dinh nghia ham===
void HinhCN::nhap()
{
	// THong bao
	cout<<"Nhap vao 2 canh a va b hinh chu nhat la :"<<endl;
    cout << "Nhap vao canh a: ";
    cin>>a;
    cout<<"Nhap vao canh b: ";
    cin>>b;

}
float HinhCN::tinhCV()
{
	return 2* (a +b);
 }

float HinhCN::tinhDT()
{
    return a * b;
}


void HinhTron::nhap()
{
	cout<<"Nhap vao ban kinh hinh tron la  :"<<endl;
    cout << "Nhap vao r la: ";
    cin >> r;
}

float HinhTron::tinhDT()
{
    return 3.14 * r * r;
}

float HinhTron::tinhCV()
{
    return 2 * 3.14 * r;
}
void HinhHopCN::nhap()
{
    HinhCN::nhap();
    cout << "Nhap vao chieu cao (h) hinh tru:: ";
    cin >> h;
}

float HinhHopCN::tinhDT()
{
	//Tinh dien tich toan phan hinh hop chu nhat
   return h*HinhCN::tinhCV() + 2*HinhCN::tinhDT() ;
}
void HinhTru::nhap()
{
    // Nh?p vào bán kinh r
    HinhTron::nhap();

    // Nh?p chi?u cao h
    cout << "Nhap vao chieu cao h: ";
    cin >> h;
}

float HinhTru::tinhDT()
{
    return 2 * HinhTron::tinhDT() + HinhTron::tinhCV() * h;
}

// Ham thong thuong
Hinh *nhapKT()
{
    Hinh *h;
    char chon;

    cout << "Lua chon hinh de nhap kich thuoc (1-CN,2-Tron,3-HopCN,4-HTR): ";
    cin >> chon;

    // Tao doi tuong hinh theo lua chon
    switch (chon)
    {
    case '1':
        h = new HinhCN;
        break;
    case '2':
        h = new HinhTron;
        break;
    case '3':
    	 h = new HinhHopCN;
        break;
    default:
         h = new HinhTru;
    }

    // Dung da hinh dong de nhap kich thuoc doi tuong hinh da tao
    h->nhap();

    // Tra ve hinh da nhap kich thuoc
    return h;
}

void hienDT(Hinh *h)
{
    // Dung da hinh dong de tinh va dua ra dien tinh hinh
    printf("Dien tich la: %0.1f", h->tinhDT());
}