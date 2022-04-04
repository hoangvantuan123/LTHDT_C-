
/*
Bài 14(thctdlgtbai14.cpp): Cài đặt danh sách liên kết kép có phần tử dữ liệu là số nguyên, với các
phép toán sau:
    1) Bổ sung phần tử dữ liệu x vào sau nút M
    2) Bổ sung phần tử dữ liệu x vào trước nút M
    3) Bổ sung vao cuoi danh sách
    4) Xóa nút M
    5) Duyệt danh sách để đưa các phần tử dữ liệu ra màn hình từ trái sang phải
	và từ phải sang trái.
    6) Tìm một nút có phần tử dữ liệu bằng x, nếu có trả về địa chỉ nút, nếu không có trả về rỗng.
Sử dụng danh sách liên kết kép để lưu trữ dãy số nguyên theo thứ tự đọc vào
từ tệp văn bản 'daysonguyen.txt', trên tệp không có thông tin về số phần tử của dãy số.
Đưa dãy số nguyên trong DSLKK ra màn hình theo thứ tự từ trái sang phải và từ phải sang trái.
Xóa tất cả các nút mà có phần tử dữ liệu bằng x nhập vào từ bàn phím.

*/
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

// Khai bao kieu cau truc nut nho cua DSLKK
struct node
{
    int infor;
    node *left, *right;
};

// Khai bao kieu cau truc gop 2 con tro L,R.
struct DList
{
    node *L, *R;
};

// Khai bao ham cai dat cac phep toan tren DSLKK
node *DLPostInsert(DList &LR, node *M, int x);//Bổ sung phần tử dữ liệu x vào sau nút M
node *DLPreInsert(DList &LR, node *M, int x);// Bổ sung phần tử dữ liệu x vào trước nút M
node *DLLastInsert(DList &LR, int x); // Bo sung vao cuoi danh sach
void DLDelete(DList &LR, node *M);
void DLDisplay(DList LR, bool leftToRight = 1);
node *DLFind(DList LR, int x);

//===Chuong trinh chinh===
int main()
{
    // Cai dat cau truc luu tru cua DSLKK
    DList LR = {NULL, NULL};

    // Khai bao tep vao
    ifstream fin("daysonguyen.txt");

    // Khai bao bien
    int x;

    // Doc day so tu tep dua vao DSLKK
    while (fin >> x)
        DLPostInsert(LR, LR.R, x);

    // Dua ra day so
    cout << "Day so trong DSLKK tu trai qua phai la:\n";
    DLDisplay(LR);

    cout << "\n\nDay so trong DSLKK tu phai qua trai la:\n";
    DLDisplay(LR, 0);

    cout << endl;
    return 0;
}
//===Dinh nghia ham===
node *DLPostInsert(DList &LR, node *M, int x)
{
    // Tao nut moi chua phan tu x
    node *N = new node;
    N->infor = x;
    N->left = N->right = NULL;

    // Truong hop DSLKK rong
    if (LR.L == NULL)
        LR.L = LR.R = N;
    else if (M == LR.R)
    {
        M->right = N;
        N->left = M;
        LR.R = N;
    }
    else
    {
        N->right = M->right;
        M->right->left = N;
        M->right = N;
        N->left = M;
    }

    // Tra ve dia chi moi bo sung
    return N;
}

node *DLPreInsert(DList &LR, node *M, int x)
{
    // Tao nut moi chua phan tu x
    node *N = new node;
    N->infor = x;
    N->left = N->right = NULL;

    // Noi nut moi vao truoc nut M
    if (LR.L == NULL)
        LR.L = LR.R = N;
    else if (M == LR.L)
    {
        N->right = M;
        M->left = N;
        LR.L = N;
    }
    else
    {
        M->left->right = N;
        N->left = M->left;
        N->right = M;
        M->left = N;
    }

    // Tra ve dia chi nut moi bo xung
    return N;
}
node *DLLastInsert(DList &LR, int x) // Bo sung vao cuoi danh sach
{
    // Tao nunt moi
    node *N = new node;
    N->infor = x;
    N->left = N->right = NULL;

    // THuc hien bo sung vao cuoi danh sach
    if (LR.L == NULL)
    {
        LR.L = LR.R = N;
    }
    else
    {
        // Bo sung vao sau nut cuc phai
        N->left = LR.R;
        LR.R->right = N;
        LR.R = N;
    }
}
void DLDelete(DList &LR, node *M)
{
    // Truong hop rong
    if (LR.L == NULL)
    {
        cout << "Danh sach da rong!";
        return;
    }

    // Ngat ket noi voi nut M
    if (LR.L == LR.R)
        LR.L = LR.R = NULL; // DSLKK chi con 1 nut
    else if (M == LR.L)     // M la nut dau
    {
        LR.L = LR.L->right;
        LR.L->left = NULL;
    }
    else if (M == LR.R)
    {
        LR.R = LR.R->left;
        LR.R->right = NULL;
    }
    else
    {
        M->left->right = M->right;
        M->right->left = M->left;
    }

    // Huy nut M
    delete M;
}

void DLDisplay(DList LR, bool leftToRight)
{
    node *P = leftToRight ? LR.L : LR.R;

    while (P)
    {
        cout << P->infor << "  ";
        P = leftToRight ? P->right : P->left;
    }
}

node *DLFind(DList LR, int x)
{
    node *P = LR.L;
    while (P)
        if (P->infor == x)
            return P;
        else
            P = P->right;

    // Truong hop khong thay
    return P;
}
