/*
bai:11(lthdtbai11.cpp):Nhập vào một dãy n số nguyên. Sắp xếp day giảm dần theo giải thuật sủi bọt. Y/c viết 1 hàm sắp xếp hoán đổi nội dung 2 ô nhớ.
*/
#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;

//khai bao ham
void sapXep(int *a, int n);
void doiCho(int &x, int &y);
void duaRa(int *a, int n);
//===chuong trinh chinh===
int main()
{
    //Tao doi tuong tep doc vao
    ifstream fin("daysonguyen.txt");

    //Khai bao bien
    int n;

    //Doc vao so luong so tu tep
    fin>>n;

    //Tao mang dong a co n o nho de chua day so
    int *a = new int[n];

    //Doc day so tu tep vao dong a
    for(int i=0;i<n;i++) fin>>a[i];

    //Dua ra day ban dau
    cout<<"Dãy số ban đầu đọc được từ tệp là:\n";
    duaRa(a,n);

    //Sao xep giam dan
    sapXep(a,n);

    //Dua ra day so sau sx
    cout<<"\n\nDãy số sắp xếp giảm dần là:\n";
    duaRa(a,n);

    //Huy mang dong
    delete [] a;

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void sapXep(int *a,int n)
{
    //Sap xep day so giam dan theo giai thuat sui bot
    for(int i=0;i<n-1;i++)
        for(int j=n-1;j>i;j--)
            if(a[j]>a[j-1]) doiCho(a[j],a[j-1]);
}

void doiCho(int &x, int &y)
{
    int tg=x;
    x=y;
    y=tg;
}

void duaRa(int *a,int n)
{
    for(int i=0;i<n;i++) cout<<a[i]<<"  ";
}
