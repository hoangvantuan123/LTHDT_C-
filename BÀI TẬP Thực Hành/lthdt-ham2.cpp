
//DE: Tinh to hop chap k cua n phan tu

#include<iostream>
#include<stdio.h>

using namespace std;
int gt(int a)
{
    int s=1;
    for (int i=1;i<=a;i++)
	s*=i;
    return s;
}
int c(int k, int n)
{
    return gt(n)/(gt(k)*gt(n-k));
}
//===Chuong trinh chinh===
main()
{
    int n,k;
    cout<<"Nhap n= ";cin>>n;
    cout<<"Nhap k= ";cin>>k;
	cout<<endl;
	return 0;
}
//===Dinh nghia ham===
