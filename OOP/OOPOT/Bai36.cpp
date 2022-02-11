//Chồng toán tử:
// Bài 36: Tính tổng n số phức. 
// Yêu cầu dùng toán tử + để cộng hai số phức,
// dùng toán tử nhập >> nhập vào số phức, 
// dùng toán tử xuất << để đưa ra số phức ở dạng a + bi,
// có thể khởi tạo giá trị ban đầu 
// cho phần thực và phần ảo.
#include<iostream>
#include<stdio.h>

using namespace std;

class SoPhuc
{
    private:
        float a,b;

    public:
        //Ham tao
        SoPhuc();
        ~SoPhuc();
        
        //Ham thanh vien
        SoPhuc operator + (SoPhuc &sp);
        friend istream& operator >> (istream &cin,SoPhuc &sp);
        friend ostream& operator << (ostream &cout,SoPhuc &sp);
};
//===Chuong trinh chinh===
int main()
{
    SoPhuc z1,z2,sum;

    cout << "Nhap so phuc z1:\n";
    cin >> z1; 

    cout <<"Nhap so phuc z2:\n";
    cin >> z2;

    sum = z1 + z2;

    cout << "\nSo phuc z1: " << z1; 
    cout << "\nSo phuc z2: " << z2;
    cout << "\nTong hai so phuc la: "<< sum;

    cout<<endl;
    return 0;
}
//===Dinh nghia ham===
SoPhuc::SoPhuc():a(0),b(0)
{

}
SoPhuc::~SoPhuc()
{

}
SoPhuc SoPhuc::operator + (SoPhuc &sp)
{
    SoPhuc sum;

    sum.a = a + sp.a;
    sum.b = b + sp.b;

    return sum;
}
istream& operator >> (istream &cin,SoPhuc &sp)
{
    cout << "Phan thuc: ";
    cin >> sp.a;
    cout << "Phan ao: ";
    cin >> sp.b;

    return cin;
}
ostream& operator << (ostream &cout,SoPhuc &sp)
{
    if(sp.b>=0) 
    cout<<sp.a<<" + "<<sp.b<<"i";
    else 
    cout<<sp.a<<" - "<<-sp.b<<"i";

    return cout;
}
//SoPhuc::SoPhuc(): a(0), b(0){}
//SoPhuc::SoPhuc()(int a, int b): a(a), b(b) {}
//SoPhuc SoPhuc::operator+(SoPhuc sp)
// {
//     return SoPhuc(a + sp.a, b + sp.b);
// }
