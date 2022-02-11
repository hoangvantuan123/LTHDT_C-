//Ho ten: Hoang Thi Hoa
//MaSV: 637634
//Lop: K63TH
//De: Ứng dụng ngăn xếp lưu trữ phân tán để chuyển số nguyên dương hệ 10 sang hệ 2. 

#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop
class Stack
{
    private:
	struct node
	{
	    int infor;
	    node *link;
	} *T;

    public:
	Stack();//Ham tao ko tham so
	~Stack();//Ham huy
	Stack(const Stack &ST);
	Stack operator = (const Stack &right);
	void push(int x);
	int pop();
	bool isEmpty();
};

//===Chuong trinh chinh===
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
//===Dinh nghia ham===
Stack::Stack():T(NULL)
{
}

Stack::~Stack()
{
    node *P;
    while(T)
    {
	P=T;
	T=T->link;
	delete P;
    }
}

Stack::Stack(const Stack &ST):T(NULL)
{
    node *P,*N,*Botton;
    //Duyet qua cac nut ngan xep s
    while(P)
    {
	//Tao nut moi copy pt tu P sang
	N = new node;
	N->infor=P->infor;
	N->link=NULL;
	//Noi nut moi vao day ngan xep moi tao
	if(T==NULL)
	{
	    T=Botton=N;
	}
	else {
	{
	    Botton->link=N;
	    Botton=N;
	}
	}
}

Stack Stack::operator=(const Stack &right)
{
    //Huy cac nut dt ben trai
    //Tao cac nut cua doi tuong ben trai la ban sao dt ben phai
}

void Stack::push(int x)
{
    node *N = new node;
    N->infor=x;
    N->link=NULL;
    if(T==NULL)
    {
	N->link=T;
	T=N;
    }
}

int Stack::pop()
{
    int check;
    if(T==NULL)
    {
	cout<<"Ngan xep rong";
	return check;
    }
    check=T->infor;
    node *P=T;
    T=T->link;
    delete P;
    return check;
}

bool Stack::isEmpty()
{
    return T==NULL;
}


