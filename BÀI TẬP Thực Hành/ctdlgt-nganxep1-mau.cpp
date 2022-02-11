
/*
Cài đặt cấu trúc dữ liệu ngăn xếp lưu trữ kế tiếp có phần tử là số nguyên.
Ứng dụng ngăn xếp đã cài đặt cho bài toán chuyển đổi số nguyên hệ 10 sang hệ 2.
*/
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao hang kich thuoc cua vector luu tru S
#define N 32

//Khai bao ham cai dat dat cac phep toan tren ngan xep
void push(int *S,int &T,int x);
int pop(int *S,int &T);
bool isEmpty(const int *S,int T);

//===chuong trinh chinh===
int main()
{
    //Cai dat cau truc luu tru ke tiep cua ngan xep
    int S[N];
    int T=-1;

    //Khai bao bien
    int n,thuong;

    //Nhap so he 10
    cout<<"Nhap vao 1 so nguyen duong: ";
    cin>>n;

    //Chuyen so he 10 thanh he 2
    thuong=n;
    while(thuong)
    {
	push(S,T,thuong%2);
	thuong/=2;
    }

    //Dua ra so he 2
    cout<<"So nhi phan cua "<<n<<" la: ";
    while(!isEmpty(S,T)) cout<<pop(S,T);

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void push(int *S,int &T,int x)
{
    //1.Kiem tra day
    if(T==N-1)
    {
	cout<<"Ngan xep da day.";
	return;
    }

    //2-3.Tang T len 1 roi dua x vao ngan xep tai vi tri T
    S[++T] = x;
}

int pop(int *S,int &T)
{
    //1.Kiem tra ngan xep rong
    if(T==-1)
    {
	cout<<"Ngan xep da rong.";
	return 1;
    }

    //2-3-4.Tra ve phan tu dinh va giam T di 1
    return S[T--];
}

bool isEmpty(const int *S,int T)
{
    return T==-1;
}


