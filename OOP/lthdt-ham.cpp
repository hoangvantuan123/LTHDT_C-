//De: Su dung mang dong và ham
#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;

//Khai bao ham
void doiCho(int &x, int &y);
void sapXep(int *a,int n);

//===chuong trinh chinh===
int main()
{
        //Khai bao tep
        ifstream fin("daysonguyen.txt");

        //Khai bao bien
        int n,i;
        int *a; //dung mang dong

        //Doc so luong so tu tep
        fin>>n;

        //Tao mang dong a co n o nho chua day so nguyen
        a = new int[n];

        //Doc day so tu tep vao mang dong
        for(i=0;i<n;i++) fin>>a[i];

        //Dua ra day so ban dau
        cout<<"Day so doc duoc tu tep la:\n";
        for(i=0;i<n;i++) cout<<a[i]<<"  ";

        //Sap xep day so tang dan
        sapXep(a,n);

        //Dua ra day sx
        cout<<"\n\nDay so sap xep tang dan la:\n";
        for(i=0;i<n;i++) cout<<a[i]<<"  ";

        //Huy mang dong
        delete [] a;

        cout<<endl;
        return 0;
}
//===dinh nghia ham===
void doiCho(int &x, int &y)
{
        int tg=x;
        x=y;
        y=tg;
}

void sapXep(int *a,int n)
{
        for(int i=0;i<n-1;i++)
                for(int j=i+1;j<n;j++)
                        if(a[j]<a[i]) doiCho(a[i],a[j]);
}
                                                               