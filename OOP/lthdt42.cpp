//De:42
/*42(lthdtbai42.cpp): Tính diện tích và chu vi các hình: Hình chữ nhật biết 2 cạnh,
hình tam giác biết 3 cạnh, hình tròn biết bán kính. Nhập vào một số hình trong đó
có cả hình chữ nhật, hình tam giác và hình tròn. Đưa ra diện tích
và chu vi các hình đã nhập. Y/c cài đặt đa hình động và lớp trừu tượng; viết 1 hàm
lựa chọn hình, nhập kích thước cho hình và trả về hình đã nhập; viết 1 hàm đưa ra
diện tích và chu vi của một hình truyền vào qua đối số.
*/

#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

//Khai bao lop
class hinh
{
    private:

    public:
        virtual void nhap()=0;
        virtual float tinhDT()=0;
        virtual float tinhCV()=0;
};

class hinhCN:public hinh
{
    private:
        float a,b;

    public:
        void nhap();
        float tinhDT();
        float tinhCV();
};


class hinhTG:public hinh
{
    private:
        float a,b,c;

    public:
        void nhap();
        float tinhDT();
        float tinhCV();
};

class hinhTR:public hinh
{
    private:
        float r;

    public:
        void nhap();
        float tinhDT();
        float tinhCV();
};

//Khai bao ham thong thuong
hinh* nhapDL();
void hienTT(hinh *h);

//===chuong trinh chinh===
int main()
{
    hinh *dsHinh[50];
    int n=0,i;
    char traLoi;

    do
    {
        dsHinh[n++] = nhapDL();
        cout<<"\nCó nhập tiếp không(c/k)? ";
        cin>>traLoi;
    }
    while(traLoi=='c' || traLoi=='C');

    //Dua ra
    cout<<"\n\nDiện tích và chu vi các hình đã nhập là:";
    for(i=0;i<n;i++)
    {
        cout<<"\nHình thứ "<<i+1<<":\n";
        hienTT(dsHinh[i]);
        cout<<endl;
    }

    cout<<endl;
    return 0;
};
//===dinh nghia ham===
//ham lop HCN
void hinhCN::nhap()
{
    cout<<"Nhập vào 2 cạnh của hình chữ nhật: ";
    cin>>a>>b;
}

float hinhCN::tinhDT()
{
    return a*b;
}

float hinhCN::tinhCV()
{
    return (a+b)*2;
}

//ham lop hinh tam giac
void hinhTG::nhap()
{
    do
    {
        cout<<"Nhập vào 3 cạnh tam giác: ";
        cin>>a>>b>>c;
        if(a+b<=c || a+c<=b || b+c<=a)
            cout<<"3 số đã nhập không phải 3 cạnh tam giác. Nhập lại!\n";
    }
    while(a+b<=c || a+c<=b || b+c<=a);
}

float hinhTG::tinhDT()
{
    float p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

float hinhTG::tinhCV()
{
    return a+b+c;
}

//ham lop hinh tron
void hinhTR::nhap()
{
    cout<<"Nhập vào bán kính hình tròn: ";
    cin>>r;
}

float hinhTR::tinhDT()
{
    return 3.14*r*r;
}

float hinhTR::tinhCV()
{
    return 2*3.14*r;
}


//Ham thong thuong
hinh* nhapDL()
{
    hinh *h;
    char chon;

    cout<<"Bạn nhập kích thước hình nào(1-CN,2-TG,3-TR): ";
    cin>>chon;

    //Tao doi hinh tuong ung voi lua chon cua nguoi dung
    switch(chon)
    {
        case '1':
            h = new hinhCN;
            break;

        case '2':
            h = new hinhTG;
            break;

        case '3':
            h = new hinhTR;
            break;

        default:
            h = new hinhCN;
    }

    //Nhap kich thuoc hinh da chon
    h->nhap(); //Da hinh dong

    //Tra ve hinh da nhap
    return h;
}

void hienTT(hinh *h)
{
    printf("Diện tích là: %0.1f",h->tinhDT());
    printf("\nChu vi là: %0.1f",h->tinhCV());
}

