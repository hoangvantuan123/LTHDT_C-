//Ho ten:
//MaSV:
//Lop:
//De: Ung dung ngan xep luu tru phan tan de chuyen so he 10 thanh he 2

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

Stack::~Stack()
{
    node *P;

    while(T)
    {
	P = T;
	T = T->link;
	delete P;
    }
}

Stack Stack::operator=(const Stack &right)
{
    //1.Huy cac nut cua doi tuong ben trai
    
    //2.Tao cac nut cua doi tuong ben trai la ban sao cac nut cua doi tuong ben phai (right)
}

void Stack::push(int x)
{

}

int Stack::pop()
{

}

bool Stack::isEmpty()
{

}


