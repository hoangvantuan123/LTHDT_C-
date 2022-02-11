/*Bài 29(lthdtbai29.cpp): Nhập vào một số nguyên dương, đưa ra số hex tương ứng.
Y/c trong chương trình có sử dụng ngăn xếp để chuyển từ số thập phân sang hex.
Ngăn xếp sử dụng cấu trúc lưu trữ phân tán.
*/

#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop ngan xep
class Stack
{
    private:
        struct node
        {
            int infor;
            node *link;
        } *T;

    public:
        Stack();
        ~Stack();
        Stack(const Stack &s);
        Stack operator=(const Stack &s2);
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
    int n,thuong,du;

    //Nhap du lieu
    cout<<"Nhập vào 1 số nguyên dương: "; cin>>n;

    //Chuyen sang so hex
    thuong=n;
    while(thuong)
    {
        S.push(thuong%16);
        thuong/=16;
    }

    //Dua ra so hex
    cout<<"Số hex của "<<n<<" là: ";
    while(!S.isEmpty())
    {
        du = S.pop();
        if(du<10) cout<<du;
        else printf("%c",du+55);
    }

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
Stack::Stack():T(NULL)
{

}

Stack::~Stack()
{
    while(T)
    {
        node *P=T;
        T=T->link;
        delete P;
    }
}

Stack::Stack(const Stack &s)
{

}

Stack Stack::operator=(const Stack &s2)
{

}

void Stack::push(int x)
{
    //1.Tao nut moi
    node *N = new node;
    N->infor = x;
    N->link = NULL;
    if(T==NULL)
    {
    //2.Noi nut moi vao tren nut T
        N->link = T;

    //3.Cho T tro sang nut moi
        T = N;
    }
}


int Stack::pop()
{
    int tg;
    //1.Kiem tra rong
    if(T==NULL)
    {
        cout<<"Ngăn xếp đã rỗng!";
        return tg;
    }

    //2.Giu lai nut dinh
    tg=T->infor;
    node *P=T;

    //3.Cho T tro xuong nut ben duoi
    T = T->link;

    //4.Huy nut va tra ve phan tu loai bo
    delete P;
    return tg;
}

bool Stack::isEmpty()
{
    return T==NULL;
}


