
//DE:Cài đặt cấu trúc dữ liệu cây nhị phân có phần tử là số nguyên. Ứng dụng vào tạo cây nhị phân tìm kiếm cho dãy khóa k có n phần tử là các số nguyên đọc vào từ tệp văn bản “daykhoa.txt”. Tìm khóa trên có giá trị bằng x, nếu không tìm thấy thì bổ sung x trở thành khóa trên cây, cho biết x có trên cây hay không. Đưa các khóa trên cây ra màn hình theo thứ tự tang dần.

#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

//Khai báo cấu trúc nút nhớ cây nhị phân
struct node
{
    int infor;
    node *left, *right;
};

//Khai báo các hàm cài đặt phép toán
void preOrder(node *T);
void inOrder(node *T);
void postOrder(node *T);

node* BST(node* &T, int x);
//===Chuong trinh chinh===
int main()
{
    //Cài đặt cấu trúc lưu trữ
    node *T=NULL;
    //Khai báo tệp và biến
    ifstream fin("daykhoa.txt");
    int n, x;
    //Đọc số lượng khoá trong tệp dãy khoá
    fin>>n;
    //Đọc dãy khoá + tạo cây nhị phân tìm kiếm
    for(int i=0;i<n;i++)
    {
	fin>>x;
	BST(T,x);
    }
    cout<<"Dãy khoá sắp xếp tăng dần là: ";
    inOrder(T);
    cout<<"\nNhập khoá x cần tìm: ";
    cin>>x;

    if(BST(T,x)) cout<<"Tìm thấy x="<<x;
    else
    {
	cout<<"Không tìm thấy x="<<x<<" bổ sung vào cây được dãy khoá sau: ";
	inOrder(T);
    }

    cout<<endl;
    return 0;
}
//===Dinh nghia ham===
void preOrder(node *T)
{
    if(T==NULL) return;

    cout<<T->infor<<" ";
    preOrder(T->left);
    preOrder(T->right);
}

void inOrder(node *T)
{
    if(T==NULL) return;

    inOrder(T->left);
    cout<<T->infor<<" ";
    inOrder(T->right);
}

void postOrder(node *T)
{
    if(T==NULL) return;

    postOrder(T->left);
    postOrder(T->right);
    cout<<T->infor<<" ";
}

node* BST(node* &T, int x)
{
    //1. Khởi tạo con trỏ
    node *p=NULL, *q=T;
    //2. Tìm kiếm
    while(q!=NULL)
    {
	if(x<q->infor) {p=q; q=q->left;}
	else if(x>q->infor) {p=q; q=q->right;}
	else return q;
    }
    //3. Bổ sung
    q=new node;
    q->infor=x;
    q->left=q->right=NULL;

    if(T==NULL) T=q;
    else if(x<p->infor) p->left=q;
    else p->right=q;
    return NULL;
}
