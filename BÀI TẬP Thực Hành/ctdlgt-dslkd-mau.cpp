
/*
Cài đặt cấu trúc dữ liệu danh sách liên kết đơn (DSLKD) có phần tử là số nguyên với bốn phép toán:
1) Bổ sung phần tử x vào sau nút M
2) Loại bỏ nút M
3) Duyệt DSLKD
4) Ghép hai danh sách
*/
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao kieu cau truc nut nho cua DSLKD
struct node
{
    int infor;
    node *link;
};

//Khai bao ham cai dat cac phep toan tren DSLKD
void SLPostInsert(node* &F,node *M,int x);
void SLDelete(node* &F,node *M);
void SLDisplay(node* F);
void SLConcat(node* &P,node *Q);

//===chuong trinh chinh===
int main()
{
    //Cai dat cau truc luu tru phan tan cua DSLKD
    node *F=NULL;


    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void SLPostInsert(node* &F,node *M,int x)
{
    //1.Tao nut nho moi chua x
    node *N = new node;
    N->infor = x;
    N->link = NULL;

    //2.Noi nut moi vao sau nut M
    if(F==NULL) F = N;
    else
    {
	N->link = M->link;
	M->link = N;
    }
}

void SLDelete(node* &F,node *M)
{

}

void SLDisplay(node* F)
{

}

void SLConcat(node* &P,node *Q)
{

}


