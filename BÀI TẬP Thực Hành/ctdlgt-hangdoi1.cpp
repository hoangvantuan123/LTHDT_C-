
//Đề: Cài đặt cấu trúc dữ liệu hàng đợi lưu trữ kế tiếp có phần
// tử dữ liệu là số nguyên. Ứng dụng hàng đợi cho bài toán: Đọc dãy số nguyên dương từ tệp văn bản ‘daysonguyen.txt’, trên tệp không có thông tin về số lượng số, tách thành dãy số lẻ và dãy số chẵn theo đúng thứ tự xuất hiện trên tệp, đưa 2 dãy số ra màn hình.

#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

//Khai báo hằng
#define N 100

//Khai báo hàm cài đặt các phép toán trên ngăn xếp
void CQInsert(int *Q,int &F,int &R,int x);
int CQDelete(int *Q,int &F,int &R);
bool CQIsEmpty(const int *Q,int F, int R);

//===Chuong trinh chinh===
int main()
{
    //Khai báo tệp vào
    ifstream fin("daysonguyen.txt");

    //Cài đặt cấu trúc của hàng đợi lưu trữ kế tiếp
    int Q[N];
    int F=-1;
    int R=-1;


    cout<<endl;
    return 0;
}
//===Dinh nghia ham===
void CQInsert(int *Q,int &F,int &R,int x)
{

}

int CQDelete(int *Q,int &F,int &R)
{

}

bool CQIsEmpty(const int *Q,int F, int R)
{
    return F==-1;
}
