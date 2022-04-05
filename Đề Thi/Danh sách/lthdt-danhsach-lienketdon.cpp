//Ho ten:
//MaSV:
//Lop:
//De:
/*
Bài 32(lthdtbai32.cpp): Cho tệp văn bản chứa dãy số nguyên "lthdtbai32-daysonguyen.txt",
trên tệp không có thông tin về số phần tử của dãy số. Đọc dãy số từ tệp văn bản,
lưu dãy số trong danh sách liên kết đơn theo đúng thứ tự trên tệp. Đưa dãy số trong DSLKD ra màn hình.
Tìm xem trong dãy số có phần tử nào bằng x không. Xóa một phần tử có giá trị bằng x.
*/

#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;

//Khai bao lop
class SList
{
    private:
        struct node
        {
            int infor;
            node *link;
        } *F;
    public:
        SList();
        ~SList();
        void lastInsert(int x);
        void show(); //display
        bool search(int x); //find
        bool remove(int x);
};

//===chuong trinh chinh===
int main()
{
    //Tao cac doi tuong
    ifstream fin("lthdtbai32-daysonguyen.txt");
    SList SL;

    //Doc day so tu tep vao DSLKD
    int x;
    while(fin>>x) SL.lastInsert(x);

    //Dua day so trong DSLKD ra man hinh
    cout<<"Dãy số trong DSLKD là:\n";
    SL.show();

    //Tim va xoa x
    cout<<"\nNhập vào x: ";
    cin>>x;

    if(SL.search(x)) cout<<"\n\nĐã tìm thấy "<<x<<" trong DSLKD.";
    else cout<<"\n\nKhông tìm thấy "<<x<<" trong DSLKD.";

    if(SL.remove(x)) cout<<"\n\nĐã loại bỏ "<<x<<" khỏi DSLKD.";
    else cout<<"\n\nKhông xóa được "<<x<<" trong DSLKD vì không thấy.";

    cout<<"\n\nDãy số trong DSLKD sau khi xóa là:\n";
    SL.show();

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
SList::SList():F(NULL)
{

}

SList::~SList()
{
    while(F)
    {
	node *P=F;
	F=F->link;
	delete P;
    }
}

void SList::lastInsert(int x)
{
    //1.Tao nut moi
    node *N = new node;
    N->infor = x;
    N->link = NULL;

    //2.Noi nut moi vao cuoi DSLKD
    if(F==NULL) F = N;
    else
    {
        //Tim den nut cuoi cung
        node *P = F;
        while(P->link) P = P->link;

        //Noi nut moi vao sau nut cuoi
        P->link = N;
    }
}

bool SList::search(int x)
{
    node *M=F;
    while(M)
    {
	if(M->infor==x) return 1;
	else M=M->link;
    }

    //Khong tim thay
    return 0;
}

void SList::show()
{
    node *P=F;
    while(P)
    {
	cout<<P->infor<<"  ";
	P=P->link;
    }
}

bool SList::remove(int x)
{
    //Truong hop DSLKD rong
    if(F==NULL) return 0;

    //Tim nut co phan tu bang x, M, va nut dung truoc M, P
    node *M=F,*P;
    while(M)
	if(M->infor == x) break;
	else
	{
	    P=M; M=M->link;
	}

    //Xoa nut M
    if(M)
    {
	//Ngat ket noi voi nut M
	if(M==F) F=F->link;
	else P->link = M->link; //Noi nut truoc M voi nut sau M

	//Xoa nut M
	delete M;

	//Tra 1 de bao da xoa thanh cong
	return 1;
    }

    //Khong co phan tu bang x
    return 0;
}


