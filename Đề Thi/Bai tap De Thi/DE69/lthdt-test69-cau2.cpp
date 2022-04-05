// Ho Ten :Hoang Van Tuan
// MaSV :650024
// Lop : K65CNTTA
// De :`
/*
   Câu 2: Cho tệp văn bản “daykhoa.txt” chứa dãy
   khóa là các số nguyên , trên tệp không có thông tin
   về số lượng khóa . Đọc từng khóa từ tệp để bổ sung
   vào cuối danh sách liên kết đơn. Đưa dãy khóa
   trong danh sách liên kết đơn ra màn hình . Xóa kháo
   trong danh sách liên kết đơn có giá trị bằng x nhập
   vào từ bàn phím
   */

#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;

//khai bao lop
class SList
{
    private:
        struct node
        {
            int infor;
            node *link;
        }*F;

    public:
        SList();
        ~SList();

        void lastInsert(int x);
        void show();
        bool remove(int x);
};


//=== chuong trinh chinh ===
int main()
{
    //Tao 1 doi tuong DSLKD
    SList list;

    //Tao doi tuong tep doc vao
    ifstream fin("daykhoa.txt");

    //Khai bao bien
    int x;

    //Doc ca day so tu tep vap DSLKD
    while(fin>>x) list.lastInsert(x);

    //Dua ra day so
    cout<<"Day khoa DSLKD la: \n";
    list.show();

    //Tim va xoa phan tu bang x
    cout<<"\n\nNhap vao gia tri x: ";
    cin>>x;

    if(list.remove(x)) cout<<"\n\nĐã loại bỏ "<<x<<" khỏi DSLKD.";
    else cout<<"\n\nKhông xóa được "<<x<<" trong DSLKD vì không thấy.";

    cout<<"\n\nDãy số trong DSLKD sau khi xóa là:\n";
    list.show();


    cout<<endl;
    return 0;
}
//=== Dinh nghia ham ===

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
    //1.Taoj nut moi
    node *N = new node;
    N->infor = x;
    N->link = NULL;

    //2. Noi nut moi vao cuoi DSLKD
    if(F==NULL) F = N;
    else
    {
        //Tim den nut cuoi
        node *P = F;
        while(P->link !=NULL) P = P->link;

        // Noi nut moi vao sau nut cuoi
        P->link = N;
    }
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
    // Truong hiop DSLKD rong
    if(F==NULL) return 0;

    //Tim nut co phan tu bang x
    node *M=F,*P;
    while(M)
        if(M->infor == x)
            break;
        else
        {
            P=M; M=M->link;
        }

    //Noi nut M
    if(M)
    {
        //ngat ket noi voi nut M
        if(M==F) F=F->link;
        else P->link = M->link ;

        //xoa nut M
        delete M;

        // tra ve thanh cong
        return 1;

    }
    return 0;

}


