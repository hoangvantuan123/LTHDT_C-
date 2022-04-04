//De:34
/*
Đọc vào một dãy số nguyên từ tệp văn bản.
Lưu dãy số trong danh sách liên kết kép (DSLKK) theo thứ tự giống như trên tệp.
Đưa dãy số trong DSLKK ra màn hình theo thứ tự từ trái sang phải và từ phải sang trái.
Cho biết số phần tử có trong DSLKK. Chèn phần tử x vào đầu danh sách.
Xóa nút có phần tử bằng x. Tìm nút có phần tử bằng x.
*/

#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;

//Khai bao lop DSLKK
class DList
{
    private:
        struct node
        {
            int infor;
            node *right,*left;
        } *L,*R;

    public:
        DList();
        ~DList();
        void lastInsert(int x);
        void firstInsert(int x);
        void display(bool leftToRight=1);
        bool find(int x);
        bool remove(int x);
        int count();
};


//===chuong trinh chinh===
int main()
{
    //Tao 1 doi tuong DSLKK
    DList DL;

    //Tao 1 doi tuong tep doc vao
    ifstream fin("daysonguyen-bai34.txt");

    //Khai bao bien
    int x;

    //Doc day so tu tep dua vao DSLKK
    while(fin>>x) DL.lastInsert(x);

    //Dua ra
    cout<<"\nDãy số trong DSLKK từ trái sang phải là:\n";
    DL.display();

    //cout<<"\n\nDãy số trong DSLKK từ phải sang trái là:\n";
    //DL.display(0);

    cout<<"\n\nSố phần tử trong DSLKK là: "<<DL.count();
    //Tim va xoa phan tu bang x
    cout<<"\n\nNhập vào giá trị của x: ";
    cin>>x;

    if(DL.find(x))
    {
        //Xoa nut co phan tu bang x
        DL.remove(x);

        //Dua ra day so sau khi xoa
        cout<<"\nDãy số trong DSLKK sau khi xóa phần tử bằng: "<<x<<":\n";
        DL.display();
    }
    else cout<<"\nTrong DSLKK không có phần tử bằng: "<<x;




    cout<<endl;
    return 0;
}
//===dinh nghia ham===
DList::DList():L(NULL),R(NULL)
{

}

DList::~DList()
{
    //Huy cac nut tu trai sang phai
    while(L)
    {
        node *P=L;
        L=L->right;
        delete P;
    }

    //Cho R rong
    R=NULL;
}

void DList::lastInsert(int x)
{
    //1.Tao nut moi
    node *N = new node;
    N->infor = x;
    N->left = N->right = NULL;

    //2.Noi nut moi vao cuoi danh sach
    if(R==NULL) L=R=N;
    else
    {
        //Noi nut moi vao sau nut R
        R->right = N;
        N->left = R;

        //Cho R tro sang nut moi
        R = N;
    }
}

void DList::firstInsert(int x)
{
    //1.Tao nut moi
    node *N = new node;
    N->infor = x;
    N->left = N->right = NULL;

    //2.Noi nut moi vao dau danh sach
    if(L==NULL) L=R=N;
    else
    {
        //Noi nut moi vao truoc nut L
        N->right = L;
        L->left = N;

        //Cho L tro sang nut moi
        L = N;
    }
}

void DList::display(bool leftToRight)
{
    node *P = leftToRight?L:R;

    while(P)
    {
        cout<<P->infor<<"  ";
        P = leftToRight?P->right:P->left;
    }
}


bool DList::find(int x)
{
    //Tim nut co phan tu bang x
    node *P=L;
    while(P)
    {
        if(P->infor==x) return 1;
        else P=P->right;
    }

    //Khong tim thay
    return 0;
}

bool DList::remove(int x)
{
    //Truong hop DSLKK rong
    if(L=NULL){
        cout <<"Danh sach rong!";
        return 0;
    }
        node *M = L;
    while(M)
        if(M->infor == x) break;
        else
        {
            M = M->right;
        }
    // Truong hop khong tim thay
    if(M==NULL)
        return 0;
    // Xoa nut M
    //Ngat ket noi nut M
    if (L == R)
        L = R = NULL;
    else if (M == L)
    {
        L = L->right;
        L->left = NULL;
    }
    else if (M == R)
    {
        R = R->left;
        R->right = NULL;
    }
    else
      {
      M->left->right = M->right;
      M->right->left = M->left;
  }

  // HUy nut M
  delete M;
  // Tra ve 1 de xoa thanh cong
  return 1;


}

int DList::count()
{
    node *P=L;
    int c=0;

    //Dem so nut (so phan tu) cua DSLKK
    while(P)
    {
        c++;
        P=P->right;
    }

    //Tra ve so dem
    return c;
}

