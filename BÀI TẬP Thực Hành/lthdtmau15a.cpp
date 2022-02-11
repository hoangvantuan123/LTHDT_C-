
//De: Tính diện tích và chu vi hình tam giác có 3 cạnh a,b,c.

#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

//===Chuong trinh chinh===
int main()
{
    //Khai báo biến
    float a,b,c;

    //Nhap vao 3 canh tam giac
    do
    {
	cout<<"Nhập vào 3 cạnh của tam giác: ";
	cin>>a>>b>>c;

	if(a+b<=c || a+c<=b || b+c<=a) //Kiểm tra 3 canh có phải 3 cạnh của một tam giác không
	    cout<<"3 số vừa nhập không phải 3 cạnh tam giác. Nhập lại.\n";
    }
    while(a+b<=c || a+c<=b || b+c<=a);

    //Tinh va in ra chu vi dien tich tam giac
    float p = (a+b+c)/2;
    printf("\nDiện tích của tam giác là: %.1f",sqrt(p*(p-a)*(p-b)*(p-c)));
    printf("\nChu vi của tam giác là: %.1f",a+b+c);

    cout<<endl;
    return 0;
}
//===Dinh nghia ham===


