//Ho ten:
//MaSV:
//Lop:
/* //De: Tạo mẫu lớp ngăn xếp lưu trữ kế tiếp.
 Ứng dụng ngăn xếp để chuyển số nguyên dương hệ 10 sang hệ 2 và hệ 16.  */

#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop
template <class Type>
class Stack
{
    private:
	enum {size=32};
	Type S[size];
	int T;

    public:
	Stack();//Ham tao khong doi so

	void push(Type x);
	Type pop();
	bool isEmpty();
};

//===chuong trinh chinh===
int main()
{

    //Tao doi tuong ngan xep S1 co kieu phan tu la so nguyen
    Stack<int> S1;

    //Tao doi tuong ngan xep S2 co kieu phan tu la ky tu
    Stack<char> S2;

    //Khai bao bien
    int n,thuong,du;

    cout<<"Nhập vào một số nguyên dương: "; cin>>n;

    //Chuyen he 10 thanh he 2
    thuong=n;
    while(thuong)
    {
	S1.push(thuong%2);
	thuong/=2;
    }

    cout<<"Số nhị phân của "<<n<<" là: ";;
    while(!S1.isEmpty()) cout<<S1.pop();

    //Chuyen he 10 thanh he 16
    thuong=n;
    while(thuong)
    {
	du=thuong%16;

	if(du<10) S2.push(du+48); //chuyen so thanh chu so roi day vao ngan xep
	else S2.push(du+55); //chuyen so thanh chu cai roi day vao ngan xep

	thuong/=16;
    }

    cout<<"\nSố hex của "<<n<<" là: ";;
    while(!S2.isEmpty()) cout<<S2.pop();

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
template <class Type>
Stack<Type>::Stack():T(-1)
{

}

template <class Type>
void Stack<Type>::push(Type x)
{
    //1.Kiem tra day
    if(T==size-1)
    {
	cout<<"Ngăn xếp đã đầy!";
	return;
    }

    //2.Bổ sung x vào ngăn xếp
    S[++T]=x;
}

template <class Type>
Type Stack<Type>::pop()
{
    //1.Kiem tra rong
    if(T==-1)
    {
	cout<<"Ngăn xếp đã rỗng!";
	Type tg;
	return tg;
    }

    //2.Lay va tra ve phan tu dinh
    return S[T--];
}

template <class Type>
bool Stack<Type>::isEmpty()
{
    return T==-1;
}


