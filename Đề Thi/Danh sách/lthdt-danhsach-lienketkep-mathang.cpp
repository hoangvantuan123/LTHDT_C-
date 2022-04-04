// Ho Ten :Hoang Van Tuan
// MaSV :650024
// Lop : K65CNTTA
// De :`
/*
   Bài 35(lthdtbai35.cpp): Đọc danh sách n mặt hàng từ tệp văn bản 'mathang.txt', lưu vào
   danh sách liên kết kép (DSLKK), mỗi mặt hàng có thông tin về mã hàng, tên hàng, số lượng, đơn giá.
   Đưa danh sách mặt hàng ra màn hình kèm theo số tiền của từng mặt hàng. Tính tổng số tiền của tất cả mặt hàng.
   Xóa mặt hàng có mã nhập vào từ bàn phím.
   */

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

// khai bao lop

struct MatHang
{
    char maHang[11];
    char tenHang[31];
    int soLuong;
    float donGia;
};

// KHai bao lop doi tuown trong DLKK co phan tu la Ma Hang
class DList
{
private:
    struct node
    {
        MatHang infor;
        node *left, *right;
    } * L, *R;

public:
    DList();
    ~DList();

    void lastInsert(MatHang x);
    void display();
    float getSum();
    bool remove(const char *maHang);
};

//=== chuong trinh chinh ===
int main()
{

    // Tao doi tuong tep doc vao
    ifstream fin("mathang-bai35.txt");

    // Tao 1 doi tuong DSLKK
    DList list;

    // Khai bao bien
    MatHang x;
    int n;
    char tg[2];

    // Doc so luong mang hang tu tep
    fin >> n;

    // Doc danh sach n mat hang tu tep dua vao DSLKK
    for (int i = 0; i < n; i++)
    {
        // Doc Enter de dua con tro tep xuong dong duoi
        fin.getline(tg, sizeof(tg));

        // Doc va tach thong tin mat hang thu i dua vao bien x
        fin.getline(x.maHang, sizeof(x.maHang), '\t');
        fin.getline(x.tenHang, sizeof(x.tenHang), '\t');
        fin >> x.soLuong >> x.donGia;

        // Dua x vao DSLKK
        list.lastInsert(x);
    }

    // Dua danh sach mat hang trong DSLKK ra man hinh
    cout << "Danh sách mặt hàng trong DSLKK là:";
    list.display();

    cout << endl;
    return 0;
}
//=== Dinh nghia ham ===

DList::DList() : L(NULL), R(NULL)
{
}

DList::~DList()
{
    while (L)
    {
        node *P = L;
        L = L->right;
        delete P;
    }
}

void DList::lastInsert(MatHang x)
{
    // 1. Tao nut nho moi chua x
    node *N = new node;
    N->infor = x;
    N->left = N->right = NULL;

    // 2. Noi nut moi vao cuoi DSLKK
    if (R == NULL)
        L = R = N;
    else
    {
        R->right = N;
        N->left = R;
        R = N;
    }
}

void DList::display()
{
    node *P = L;
    while (P)
    {
        // dua ra mat hang trong P
        cout << "\n\t Ma mat hang la:" << P->infor.maHang;
        cout << "\n\t Ten mat hang la:" << P->infor.tenHang;
        cout << "\n\t So luong la:" << P->infor.soLuong;
        cout << "\n\t Don gia la:" << P->infor.donGia;
        printf("\n\t Thanh tien: %0.1f\n", P->infor.soLuong * P->infor.donGia);

        // Cho p tro sang nut dung sau
        P = P->right;
    }
}

float DList::getSum()
{
    float tongTien = 0;
    node *P = L;

    // Tinh Tong tien cua dan sach mat hang trong DSLKK

    while (P)
    {
        // tinh tong tien
        tongTien += P->infor.soLuong * P->infor.donGia;

        // cho p tro sang nut tiep theo
        P = P->right;
    }
    // tra ve tong so tien
    return tongTien;
}

bool DList::remove(const char *maHang)
{
    // Tim nut M co ma mat hang bang ma mat hang truyen vao
    node *M = L;
    while (M)
        if (strcasecmp(M->infor.maHang, maHang) == 0)
            break;
        else
            M = M->right;
    // Truong hop khong tim thay
    if (M == NULL)
        return 0;
    // Xoa nut M
    // Ngat ket noi nut M
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
    return 1;
}