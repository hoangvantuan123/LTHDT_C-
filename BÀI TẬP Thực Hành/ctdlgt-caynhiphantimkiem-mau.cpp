
/*
Bài tập (ctdlgt-caynhiphantimkiem.cpp): Cài đặt cấu trúc dữ liệu cây nhị phân có phần tử là số nguyên.
Ứng dụng vào tạo cây nhị phân tìm kiếm cho dãy khóa k có n phần tử là các số nguyên đọc vào từ tệp văn bản “daykhoa.txt”.
Tìm khóa trên có giá trị bằng x, nếu không tìm thấy thì bổ sung x trở thành khóa trên cây, cho biết x có trên cây hay không.
Đưa các khóa trên cây ra màn hình theo thứ tự tang dần.
*/
#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

//Khai bao kieu cau truc nut nho cua cay nhi phan
struct node
{
    int infor;
    node *left,*right;
};

//Khai bao ham cai dat cac phep toan tren cay nhi phan
void preOrder(node *T);
void inOrder(node *T);
void postOrder(node *T);

//Khai bao ham cai dat giai thuat tim kiem nhi phan tren cay
node* BST(node* &T,int x);

//===Chuong trinh chinh===
int main()
{
    //Cai dat cau truc luu tru phan tan cua cay nhi phan
    node *T=NULL;

    //Khai bao tep doc vao
    ifstream fin("daykhoa.txt");

    //Khai bao bien
    int n,x;

    //Doc so luong khoa tu tep
    fin>>n;

    //Doc day khoa tu tep de tao cay nhi phan tim kiem, dua ra day khoa
    cout<<"Day khoa ban dau doc duoc tu tep la:\n";
    for(int i=0;i<n;i++)
    {
	fin>>x;
	cout<<x<<"  ";

	//Tao cay nhi phan tim kiem
	BST(T,x);
    }

    cout<<"\n\nNhap vao khoa x can tim x: ";
    cin>>x;

    if(BST(T,x)) cout<<"Tim thay khoa "<<x<<" tren cay nhi phan tim kiem.";
    else cout<<"Khong tim thay khoa "<<x<<" tren cay nhi phan tim kiem, da bo sung vao cay.";

    cout<<"\n\nDay khoa tren cay theo thu tu tang dan la:\n";
    inOrder(T);

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void preOrder(node *T)
{
    if(T==NULL) return;

    cout<<T->infor<<"  ";
    preOrder(T->left);
    preOrder(T->right);
}

void inOrder(node *T)
{
    if(T==NULL) return;

    inOrder(T->left);
    cout<<T->infor<<"  ";
    inOrder(T->right);
}

void postOrder(node *T)
{
    if(T==NULL) return;

    postOrder(T->left);
    postOrder(T->right);
    cout<<T->infor<<"  ";
}

node* BST(node* &T,int x)
{
    //1. Khoi tao con tro
    node *p = NULL;
    node *q = T;

    //2. Tim kiem
    while(q)
    {
	if(x < q->infor)
	{
	    p = q;
	    q = q->left;
	}
	else if(x > q->infor)
	{
	    p = q;
	    q = q->right;
	}
	else return q;
    }

    //3. Bo sung
    q = new node;
    q->infor = x;
    q->left = q->right = NULL;

    if(T==NULL) T = q;
    else if(x < p->infor) p->left = q;
    else p->right = q;

    //4. Tra ve rong
    return NULL;
}


