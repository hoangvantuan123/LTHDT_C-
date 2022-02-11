

//De: Viet tiep cac dinh nghia ham con thieu va chuong trinh chinh su dung ngan xep
//chuyen mot so duong thanh so nhi phan

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
        //Ham tao
        Stack();
        Stack(const Stack &s);

        //Ham huy
        ~Stack();

        //Ham chong toan toan tu gan
        Stack operator=(const Stack &right);

        //Cac ham thanh vien cai dat cac phep toan
        void push(int x);
        int pop();
        bool isEmpty();
};

//===chuong trinh chinh===
int main()
{
     //Tao doi tuong ngan xep
     Stack S;
    //Khai bao bien
    int n,thuong;
    cout<<"Nhập vào một số nguyên dương: ";
    cin>>n;
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
Stack::Stack():T(NULL)
{

}

Stack::Stack(const Stack &s):T(NULL)
{
    node *P=s.T,*N,*Bottom;

    //Duyet qua cac nut cua ngan xep s
    while(P)
    {
        //Tao nut moi
        N = new node;
        N->infor = P->infor;
        N->link = NULL;

        //Noi nut moi vao ngan xep moi tao
        if(T==NULL)
        {
            T = Bottom = N;
        }
        else
        {
            Bottom->link = N;
            Bottom = N;
        }
        P = P->link;
    }
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

Stack Stack::operator=(const Stack &right)
{
    //Xoa ngan xep ben trai
    while(T)
    {
        node *P=T;
        T = T->link;
        delete P;
    }
    //Tao ngan xep ben trai la ban sao cua ngan xep ben phai
    node *P = right.T;
    node *N,*Bottom;
    while(P)
    {
        //Tao nut moi chua phan tu du lieu cua P
        N = new node;
        N -> infor = P->infor;
        N -> link = NULL;
        //Noi nut moi vao ngan xep moi
        if(T==NULL)
        {
            T=N;Bottom=N;
        }
        else
        {
            Bottom->link = N;
            Bottom = N;
        }
        //P chuyen xuong nut duoi
        P = P -> link;
    }
    return *this;
}

void Stack::push(int x)
{
    //Tao nut moi
    node *N = new node;
    N -> infor = x;
    N -> link = NULL;
    //Noi nut moi vao tren nut T
    N -> link = T;
    //T tro vao nut moi
    T = N;
}

int Stack::pop()
{
    //Kiem tra ngan xep rong
    if(T==NULL)
    {
        cout<<"Ngan xep rong\n";
        return 1;
    }
    //De lai nut dinh
    int tg = T -> infor;
    node *P = T;
    //T tro xuong nut duoi
    T = T -> link;
    //Xoa nut
    delete P;
    //Tra ve nut dinh
    return tg;
}

bool Stack::isEmpty()
{
    return T == NULL;
}