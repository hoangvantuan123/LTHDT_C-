//Ho ten: Hoang Thi Hoa
//Lop: K63TH
//Msv: 637634
//De: Ung dung ngan xep luu tru ke tiep de chuyen so nguyen duong he 10 sang he 2

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
	//Ham tao khong doi so
        Stack();

        void push(int x);
        int pop();
        bool isEmpty();
};
//===Chuong trinh chinh===
int main()
{ 
    Stack S;
    int n,thuong;
    cout<<"Nhập số nguyên dương: "; 
    cin>>n;
    thuong=n;
    while(thuong)
    {
        S.push(thuong%2);
        thuong/=2;
    }
    cout<<"Số nhị phân là: ";
    while(!S.isEmpty())
    cout<<S.pop();
    cout<<endl;
    return 0;
}
//===Dinh nghia ham===
Stack::Stack():T(-1)
{

}

void Stack::push(int x)
{
    //Kiem tra day
    if(T==size-1)
    {
        cout<<"Ngan xep day";
        return;
    }
    //Tang T len 1 dua x vao ngan xep
    S[++T] = x;
}

int Stack::pop()
{
    //Kiem tra rong
    if(T==-1)
    {
        cout<<"Ngan xep rong";
        return 1;
    }
    //Tra ve phan tu va giam T di 1
    return S[T--];
}

bool Stack::isEmpty()
{
    return T == -1;
}
