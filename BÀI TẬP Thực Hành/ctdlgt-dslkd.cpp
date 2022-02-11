
//DE: Cài đặt cấu trúc dữ liệu danh sách liên kết đơn (DSLKD) có phần tử là số nguyên với bốn phép toán:
//1) Bổ sung phần tử x vào sau nút M
//2) Loại bỏ nút M
//3) Duyệt DSLKD
//4) Ghép hai danh sách

#include<iostream>
#include<stdio.h>

using namespace std;

//Khai báo kiểu cấu trúc nút nhớ của DSLKD
struct node
{
    int infor;
    node *link;
};

//Khai báo hàm cài đặt các phép toán của DSLKD
void SLPostIntern(node* &F, node *M, int x);
void SLDelete(node* &F, node *M);
void SLDisplay(node* F);
void SLConcat(node* &P, node *Q);

//===Chuong trinh chinh===
int main()
{
    //Cài đặt cấu trúc lưu trữ phân tán của DSLKD
    node *F = NULL;

    cout<<endl;
    return 0;
}
//===Dinh nghia ham===
void SLPostIntern(node* &F, node *M, int x)
{
    //1. Tạo nút mới
    node *N = new node'
    N->infor = x;
    N->link = NULL;

    //2. Nối nút mới vào sau nút M
    if(F == NULL) F = N;
    else
    {
	N->link = M->link;
	M->link = N;
    }
}

void SLDelete(node* &F, node *M)
{
    //1. Trường hợp danh sách rỗng
    if(F == NULL)
	cout<<"Danh sách rỗng";
    return;
    //2. Thay đổi liên kết, ngắt kết nối với nút M
    //M là nút đầu tiên của danh sách
    else
	if(M == F) F = F->link;
	else
	{
	    //Tìm đến nút đứng trước nút M
	    int *P = F;
	    while(P->link != M) P = P->link;

	    //Nối nút trước M với nút sau M
	    P->link = M->link;

	    //Huỷ nút M
	    M -> AVAIL;
	return;
}

void SLDisplay(node *F)
{
    int *P = F;
    while(P)
    {
	cout<<P->infor<< " ";
	P = P->link;
    }
}
void SLConcat(node* &P, node *Q)
{

}
