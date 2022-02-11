
//Đề: Cài đặt cấu trúc dữ liệu ngăn xếp lưu trữ kế tiếp có phần tử là số nguyên. Ứng dụng ngăn xếp đã cài đặt cho bài toán chuyển đổi số nguyên hệ 10 sang hệ 2

#include<iostream>
#include<stdio.h>

using namespace std;

//Khai báo hằng kích thước của vector lưu trữ S
#define N 32

//Khai báo hàm cài đặt các phép toán trên ngăn xếp
void push(int *S,int &T,int x);
int pop(int *S, int &T);
bool isEmpty(const int *S,int T);

//===Chuong trinh chinh===
int main()
{
    //Cài đặt cấu trúc lưu trữ kế tiếp của ngăn xếp
    int S[N];
    int T=-1;

    //Khai báo biến
    int n,thuong;

    //Nhập số hệ 10
    cout<<"Nhập vào 1 số nguyên dương: ";
    cin>>n;

    //Chuyển số hệ 10 thành hệ 2
    thuong=n;
    while(thuong)
    {
	push(S,T,thuong%2);
	thuong/=2;
    }

    //Đưa ra số hệ 2
    cout<<"Số nhị phân của "<<n<<" là: ";
    while(!isEmpty(S,T))
	cout<<pop(S,T);

    cout<<endl;
    return 0;
}
//===Dinh nghia ham===
void push(int *S,int &T,int x)
{
    //B1. Kiểm tra ngăn xếp đầy
    if(T==N-1){
	cout<<"Ngăn xếp đầy";
	return;
    }
    //B2+3. Tăng T lên 1 và đưa phần tử vào ngăn xếp tại vị trí T
    S[++T]=x;
}

int pop(int *S, int &T)
{
    //B1. Kiểm tra ngăn xếp rỗng
    if(T==-1){
	cout<<"Ngăn xếp rỗng";
	return 1;
    }
    //B2. Giữ lại phần tử đỉnh
    int tg=S[T];
    //B3. Giảm T đi 1
    T--;
    //B4. Trả về phần tử đỉnh đã loại bỏ
    return tg;
}

bool isEmpty(const int *S,int T)
{
    return T==-1;
}
