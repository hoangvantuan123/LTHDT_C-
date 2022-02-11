//Ho ten:
//MaSV:
//Lop:
//De: Ung dung ngan xep luu tru phan tan de chuyen so he 10 thanh he 16

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
    //Tao 1 doi tuong ngan xep
    Stack S;

    //Khai bao bien
    int n,thuong,du;

    cout<<"Nhập vào một số nguyên dương: "; cin>>n;

    //Chuyen he 10 thanh he 16
    thuong=n;
    while(thuong)
    {
	S.push(thuong%16);
	thuong/=16;
    }

    cout<<"Số hex của "<<n<<" là: ";;
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
    node *P;

    while(T)
    {
	T=T->link;
	delete P;
    }

    //2.Tao cac nut cua doi tuong ben trai la ban sao cac nut cua doi tuong ben phai (right)
    node *N,*Bottom;
    
    //Duyet cac nut cua ngan xep right de gan cho doi tuong phai
    P = right.T;
    while(P)
    {
        //Tao nut moi
        N = new node;
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
    //1.Tao nut moi
    node *N = new node;
    N->infor = x;
    N->link = NULL;

    //2.Noi nut moi vao tren nut T
    N->link = T;

    //3.Cho T tro sang nut moi
    T = N;
}

int Stack::pop()
{
    //Kiem tra ngan xep rong
    if(T==NULL)
    {
        cout<<"Ngan xep rong!!!";
        return 1;
    }

    //Giu lai phan tu dinh
    int tg = T->infor;
    node *P = T;

    //Cho T tro xuong nut ben duoi
    T = T->link;

    //Huy nut va tra ve phan tu dinh
    delete P;
    return tg;
}

bool Stack::isEmpty()
{
    return T==NULL;
}


