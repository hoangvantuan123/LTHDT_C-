
//Bài 29(lthdtbai29.cpp): Nhập vào một số nguyên dương, đưa ra số hex tương ứng.
//Y/c trong chương trình có sử dụng ngăn xếp để chuyển từ số thập phân sang hex.
//Ngăn xếp sử dụng cấu trúc lưu trữ phân tán.


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
    Stack S;
    int n, thuong,du;
    cout<<"Nhập số nguyên dương: ";
    cin>>n;

    //Chuyen he 10 thanh 16
    thuong=n;
    while(thuong)
    {
	S.push(thuong%16);
	thuong/=16;
    }

    cout<<"\nSố hex của "<<n<<" là: ";
    while(!S.isEmpty())
    {
	du=S.pop();
	if(du<10)
	    cout<<du;
	else
	    printf("%c",du+55);
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
Stack::Stack(const Stack &s):T(NULL)
{
    node *P=s.T,*N,*Bottom;

    //Duyet qua cac nut cua ngan xep s
    while(P)
    {
	//Tao nut moi, copy phan tu tu P sang
	N = new node;
	N->infor = P->infor;
	N->link = NULL;

	//Noi nut moi vao day ngan xep moi tao
	if(T==NULL)
	{
	    T = Bottom = N;
	}
	else
	{
	    Bottom->link = N;
	    Bottom = N;
	}
    }
}

Stack Stack::operator=(const Stack &right)
{   //Xoa ngan xep
    while(T)
    {
	node *P=T;
	T=T->link;
	delete P;
    }
    //Tao mot ngan xep ban sao
    node *P=right.T,*N,*Bottom;
    while(P)
    {
	//Tao nut moi chua phan tu du lieu cua P
	N=new node;
	N->infor=P->infor;
	N->link=NULL;

	//Noi nut moi vao doi tuong ben trai
	if(T==NULL)
	    T=Bottom=N;
	else
	{
	    Bottom->link=N;
	    Bottom=N;
	}
	//Cho P tro xuong nut ben duoi
	P=P->link;
    }
    //Tra ve doi tuong ngan xep ben trai
    return *this;
}

void Stack::push(int x)
{
    //Tao nut moi
    node *N=new node;
    N->infor=x;
    N->link=NULL;
    //Noi nut moi vao tren nut T
    N->link=T;
    //T tro vao nut moi
    T=N;
}

int Stack::pop()
{
    //Check NULL
    if(T==NULL)
    {
	cout<<"Ngăn xếp rỗng\n";
	return 1;
    }
    //Giu nut dau
    int tg=T->infor;
    node *P=T;
    //T tro xuong nut duoi
    T=T->link;
    delete P;
    return tg;
}

bool Stack::isEmpty()
{
    return T==NULL;
}


