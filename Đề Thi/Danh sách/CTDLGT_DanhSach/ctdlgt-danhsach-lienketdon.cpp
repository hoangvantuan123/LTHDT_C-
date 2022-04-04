
/*
Bài 12(thctdlgtbai12.cpp): Cài đặt danh sách liên kết đơn có phần tử dữ liệu là số nguyên, với các
phép toán sau:
    1) Bổ sung phần tử dữ liệu x vào sau nút M
    2) Bổ sung phần tử dữ liệu x vào trước nút M
    3) Bổ sung vao cuoi danh sách
    4) Xóa nút M
    5) Duyệt danh sách để đưa các phần tử dữ liệu ra màn hình.
    6) Tìm một nút có phần tử dữ liệu bằng x, nếu có trả về địa chỉ nút, nếu không có trả về rỗng.
Sử dụng danh sách liên kết đơn P để lưu trữ dãy số nguyên theo thứ tự đọc vào
từ tệp văn bản 'daysonguyen.txt', trên tệp không có thông tin về số phần tử của dãy số.
Tạo danh sách liên kết đơn Q bao gồm các phần tử dữ liệu của P nhưng theo thứ tự đảo ngược.
Xóa một nút trên DSLK đơn P mà có phần tử dữ liệu bằng x nhập vào từ bàn phím.
*/
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

// Khai bao kieu cau truc nut nho cua DSLKD
struct node
{
    int infor;
    node *link;
};

// Khai bao cai dat cac phep toan tren DSLKD
node *SLPostInsert(node *&F, node *M, int x);
node *SLPreInsert(node *&F, node *M, int x);
node *SLLastInsert(node *&F, int x); // Bo sung vao cuoi danh sach
void SLDelete(node *&F, node *M);
void SLDisplay(node *F);
node *SLSearch(node *F, int x);

//===chuong trinh chinh===
int main()
{
    // Cai dat cau truc luu tru cua DSLKD P va Q
    node *P = NULL, *Q = NULL, *M;

    // Khai bao tep doc vao
    ifstream fin("daysonguyen.txt");

    // Khai bao bien
    int x;

    // Doc tung so cua day so tu tep va bo sung vao cuoi DSLKD P
    while (fin >> x)
        M = SLPostInsert(P, M, x);

    cout << "Day so nguyen trong DSLKD P la:\n";
    SLDisplay(P);

    // Tao DSLKD Q chua cac phan tu la dao nguoc cua P
    M = P;
    while (M)
    {
        x = M->infor;

        // Bo sung x vao truoc Q
        SLPreInsert(Q, Q, x);

        // Cho M tro sang nut tiep theo
        M = M->link;
    }

    cout << "\n\nDay so nguyen trong DSLKD Q la:\n";
    SLDisplay(Q);

    // Xoa phan tu trong DSLKD P co gia tri bang x
    cout << "\n\nNhap vao phan tu x can xoa: ";
    cin >> x;

    M = SLSearch(P, x);

    if (M)
    {
        // Xoa nut M co phan tu bang x
        SLDelete(P, M);

        // Dua ra P sau khi xoa
        cout << "\n\nDSLKD P sau khi xoa phan tu x la:\n";
        SLDisplay(P);
    }
    else
        cout << "\nTrong DSLKD P khong co phan tu bang " << x;

    cout << endl;
    return 0;
}
//===dinh nghia ham===
node *SLPostInsert(node *&F, node *M, int x)
{
    // Tao nut moi chua phan tu x
    node *N = new node;
    N->infor = x;
    N->link = NULL;

    // Noi nut moi vao sau nut M trong DSLKD
    if (F == NULL)
        F = N;
    else
    {
        N->link = M->link;
        M->link = N;
    }

    // Tra ve dia chi nut moi bo sung
    return N;
}

node *SLPreInsert(node *&F, node *M, int x)
{
    // 1.Tao nut nho moi chua x
    node *N = new node;
    N->infor = x;
    N->link = NULL;

    // 2.Noi nut moi vao truoc nut M trong DSLKD
    if (F == NULL)
        F = N;
    else if (M == F)
    {
        N->link = M;
        F = N;
    }
    else
    {
        // Tim den nut P dung truoc nut M
        node *P = F;
        while (P->link != M)
            P = P->link;

        // Noi nut moi vao truoc nut M
        P->link = N;
        N->link = M;
    }

    // Tra ve dia chi nut moi bo sung
    return N;
}
node *SLLastInsert(node *&F, int x) // Bo sung vao cuoi DSLKD
{
    // Tao nut moi
    node *N = new node;
    N->infor = x;
    N->link = NULL;

    // truong hop rong
    if (F == NULL)
        F = N;
    else
    {
        // tim den nunt cuoi danh sach
        node *P = F;
        while (P->link != NULL)
            P = P->link;

        // noi nut moi vao sau nut cuoi danh sach
        P->link = N;
    }
    return N;
}
void DLDelete(node *&F, node *M)
{
    // 1.Truong hop rong
    if (F == NULL)
    {
        cout << "Danh sach lien ket don da rong.";
        return;
    }

    // 2.Ngat ket noi voi nut M
    if (M == F)
        F = F->link;
    else
    {
        // Tim den nut P truoc nut M
        node *P = F;
        while (P->link != M)
            P = P->link;

        // Noi nut truoc M voi nut sau M
        P->link = M->link;
    }

    // 3.Huy nut M
    delete M;
}

void DLDisplay(node *F)
{
    while (F)
    {
        cout << F->infor << "  ";
        F = F->link;
    }
}

node *DLSearch(node *F, int x)
{
    // Tim nut P co phan tu bang x
    node *P = F;
    while (P)
        if (P->infor == x)
            break;
        else
            P = P->link;

    // Tra ve ket qua
    return P;
}
