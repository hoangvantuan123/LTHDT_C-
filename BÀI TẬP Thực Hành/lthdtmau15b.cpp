
//De: Tính diện tích và chu vi hình tam giác có 3 cạnh a,b,c đọc vào từ tệp 'tamgiac.txt'

#include<iostream>
#include<fstream>
#include<stdio.h>
#include<math.h>

using namespace std;

//===Chuong trinh chinh===
int main()
{
    //Tao doi tuong tep vao
    ifstream fin("tamgiac.txt");

    //Khai báo biến
    float a,b,c;

    //Doc vao 3 canh tu tep
    fin>>a>>b>>c;

    printf("3 cạnh tam giác đọc từ tệp là:");
    printf("\na = %0.1f; b = %0.1f; c = %0.1f",a,b,c);

    if(a+b>c && a+c>b && b+c>a)
    {
	float cv = a+b+c;
	float p = cv/2;

	printf("\nDiện tích của tam giác là: %.1f",sqrt(p*(p-a)*(p-b)*(p-c)));
	printf("\nChu vi của tam giác là: %.1f",cv);
    }
    else cout<<"\n3 số đọc từ tệp không phải 3 cạnh tam giác.";

    cout<<endl;
    return 0;
}
//===Dinh nghia ham===


