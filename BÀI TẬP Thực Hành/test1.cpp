/*Bai 32(lthdtbai32.cpp): Cho tệp văn bản chứa dãy số nguyên "lthdtbai32-daysonguyen.txt",
trên tệp không có thông tin về số phần tử của dãy số. Đọc dãy số từ tệp văn bản,
lưu dãy số trong danh sách liên kết đơn theo đúng thứ tự trên tệp. Đưa dãy số trong DSLKD ra màn hình.
Tìm xem trong dãy số có phần tử nào bằng x không. Xóa một phần tử có giá trị bằng x.*/
#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;
//Khai bao lop
class SingleList
{
    private:
	struct node
	{
	    int infor;
	    node *link;
	} *F = NULL;
    public:

	void firstInsert(int x);
	void lastInsert(int x);
	void display();
	bool find(int x);
	bool remove(int x);
};
//Chuong trinh chinh
int main()
{
    //Tao doi tuong
    SingleList SL;

    ifstream fin("dayso.txt");
    
    int x;
    //Doc day so tu dslkd
    while(fin>>x)
    {
	SL.lastInsert(x);
    }

    //Hien thi
    cout<<"Day so nguyen cua dslkd la: \n";
    SL.display();

    //Xoa
    cout<<"\nNhap x can xoa: ";
    cin>>x;
    if(SL.find(x))
    {
	cout<<"Co x ";
	SL.remove(x);
	cout<<"Display ds then remove x ";
	SL.display();
    }
    else
    {
	cout<<"No find x ";
    }
    return 0;
    cout<<endl;
}
//Dinh nghia ham
void SingleList::firstInsert(int x)
{
    //Create new node
    node *N = new node;
    N->infor = x;
    N->link = NULL;

    //Check list NULL
    if(F == NULL) F = N;
    else
    {
	N->link = F;
	F = N;
    }
}

void SingleList::lastInsert(int x)
{
    //Create new node
    node *N = new node;
    N->infor = x;
    N->link = NULL;

    //Check list NULL
    if(F == NULL) F = N;
    else
    {
	//Tim nut cuoi danh sach
	node *P = F;
	while(P->link != NULL)	P = P->link;

	P->link = N;
    }
}

void SingleList::display()
{
    node *P = F;
    while(P != NULL)
    {
	cout << P->infor<<"  ";
	P = P->link;
    }
}

bool SingleList::find(int x)
{
    //Check list NULL
    if(F == NULL) return false;
    //Dung nut P de duyet danh sach
    node *P = F;
    while(P!=NULL)
    {
	//Khi tim thay nut co truong hop infor = x thi dung
	//va tra ve true
	if(P->infor == x)
	{
	    return true;
	}

	P = P->link;
    }

    //Khong tim thay tra ve false
    return false;
}

bool SingleList::remove(int x)
{
    //Tim nut can xoa
    node *M = F;
    while(M)
    {
	cout << M->infor << "  ";
	if(M->infor == x) break;
	M = M->link;
    }
    //Neu khong tim thay x thi ket thuc ham
    if(M == NULL) return false;

    //Neu tim thay thi ngat ket noi vs nut day
	//Nut can xoa la nut dau ds
	if(F == M){ F=F->link;}
	else{
	//thop con lai
	node *P = F;
	while(P->link !=M)
	    P=P->link;
        P->link = M->link;
	}
    //Huy nut
    delete M;
    return true;
}
