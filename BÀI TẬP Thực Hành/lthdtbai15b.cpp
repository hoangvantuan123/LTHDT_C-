
//De: Tính diện tích và chu vi hình tam giác có 3 cạnh a,b,c. Nhap vao tu tep ten 'tamgiac.txt'

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<fstream>

using namespace std;

//===Chuong trinh chinh===
int main()
{
    float a,b,c;
    ifstream fin("tamgiac.txt");

    //Nhap vao 3 canh tam giac
	if(a+b<=c || a+c<=b || b+c<=a)
	    cout<<"3 số vừa nhập không phải 3 cạnh tam giác. Nhập lại.\n";

	else
	{
	 //Tinh va in ra chu vi dien tich tam giac
	 float p = (a+b+c)/2;
	 printf("\nDiện tích của tam giác là: %.1f",sqrt(p*(p-a)*(p-b)*(p-c)));
	 printf("\nChu vi của tam giác là: %.1f",a+b+c);
	};
    cout<<endl;
    return 0;
}
//===Dinh nghia ham===


