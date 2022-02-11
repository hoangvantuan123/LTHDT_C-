//Ho ten:
//MaSV:
//Lop:
//De: Ứng dụng ngăn xếp lưu trữ kế tiếp để chuyển số nguyên dương hệ 10 sang hệ 2. 

#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop
class Stack
{
    private:
	enum {size=32};
	int S[size];
	int T;

    public:
	Stack();//Ham tao khong doi so

	void push(int x);
	int pop();
	bool isEmpty();
};

//===chuong trinh chinh===
int main()
{
    //Tao 1 doi tuong ngan xep
    Stack S;

    //Khai bao bien
    int n,thuong;

    cout<<"Nhập vào một số nguyên dương: "; cin>>n;

    //Chuyen he 10 thanh he 2
    thuong=n;
    while(thuong)
    {
	S.push(thuong%2);
	thuong/=2;
    }

    cout<<"Số nhị phân của "<<n<<" là: ";;
    while(!S.isEmpty()) cout<<S.pop();

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
Stack::Stack():T(-1)
{

}

void Stack::push(int x)
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

int Stack::pop()
{
    //1.Kiem tra rong
    if(T==-1)
    {
	cout<<"Ngăn xếp đã rỗng!";
	return 1;
    }

    //2.Lay va tra ve phan tu dinh
    return S[T--];
}

bool Stack::isEmpty()
{
    return T==-1;
}


