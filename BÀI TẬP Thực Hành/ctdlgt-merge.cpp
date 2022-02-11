
//DE: Cài đặt giải thuật trộn hai dãy khóa đã sắp xếp tăng dần thành một dãy khóa tăng dần. Áp dụng trộn 2 dãy khóa đã sắp xếp tăng dần đọc vào từ tệp "daykhoa1.txt" và "daykhoa2.txt".

#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

//Khai bao ham cai dat giai thuat tron 2 day da sap xep tang dan thanh 1 day tang dan
void merge(int *X,int b,int m,int n, int *Z);

//===Chuong trinh chinh===
int main()
{
    //Khai bao bien
    int i,n,*a;

    //Khai bao tep
    ifstream fin("daykhoa1.txt");
    ifstream fin("daykhoa2.txt");

    //Doc day khoa

    cout<<endl;
    return 0;
}
//===Dinh nghia ham===
void merge(int *X,int b,int m,int n, int *Z)
{
    //1.
    int i=b,k=b,j=m+1;

    //2.
    while(i<=m &&j<=n)
	if(X[i]<=X[j]) Z[k++]=X[i++];
	else Z[k++]=X[j++];

    //3.Dua not day con lai vao day dich
    if(i>m) while(k<=n) Z[k++]=X[j++];
    else while(k<=n) Z[k++]=X[i++];
}

