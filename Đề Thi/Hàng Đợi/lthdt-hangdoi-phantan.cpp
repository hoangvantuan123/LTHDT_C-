// Ho Ten :Hoang Van Tuan
// MaSV :650024
// Lop : K65CNTTA
// De :`
/*
   Bài 31(lthdtbai31.cpp): Cho tệp văn bản "daysonguyen-bai31.txt" chứa một
   dãy số nguyên,
   trên tệp không có thông tin về số lượng số. Đọc từng số của dãy số từ
   tệp,
   nếu là số nguyên tố thì đưa vào hàng đợi. Đưa ra màn hình dãy số đọc từ
   tệp và
   dãy số nguyên tố trong hàng đợi. Yêu cầu cài đặt và sử dụng hàng đợi lưu
   trữ phân tán.
   */

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>

using namespace std;

// khai bao lop
class Queue
{
private:
    struct node
    {
        int infor;
        node *link;
    } * F, *R;

public:
    Queue();
    ~Queue();

    void insert(int x);
    int remove();
    bool isEmpty();
};

// Khai bao ham thong thuong
bool laNguyenTo(int x);

//=== chuong trinh chinh ===
int main()
{
    // Tao mot doi tuong hang doi
    Queue Q;

    // Tao mot doi tuong tep vao
    ifstream fin("daysonguyen-bai31.txt");

    // Khai bao bien
    int x;
    // Doc day so tu tep
    cout << "Day so duoc doc tu tep la: ";
    while (fin >> x)
    {
        cout << x << "";
        if (laNguyenTo(x))
            Q.insert(x);
    }

    // Dua ra
    cout << "\n\nCac so nguyen to trong day so la:\n";
    while (!Q.isEmpty())
        cout << Q.remove() << "  ";

    cout << endl;
    return 0;
}
//=== Dinh nghia ham ===

Queue::Queue() : F(NULL), R(NULL)
{
}

Queue::~Queue()
{
    while (F)
    {
        node *P = F;
        F = F->link;
        delete P;
    }
}

void Queue::insert(int x)
{
    // 1.Tao nut nho moi chua x
    node *N = new node;
    N->infor = x;
    N->link = NULL;

    // 2.Noi nut moi vao sau nut R
    if (R == NULL)
        F = N;
    else
        R->link = N;

    // 3. Cho R tro sang nut moi
    R = N;
}

int Queue::remove()
{
    // 1.Kiem tra rong
    if (F == NULL)
    {
        cout << "Hang doi da rong.";
        return 1;
    }

    // 2.Giu lai phan tu loi truoc (dau hang doi)
    int tg = F->infor;
    node *P = F;

    // 3.Cho F tro sang nut tiep theo
    F = F->link;
    // 4. Huy nut va tra ve phan tu da loaij bo
    delete P;
    return tg;
}

bool Queue::isEmpty()
{
    return F == NULL;
}

bool laNguyenTo(int x)
{
    for (int i = 2; i <= (int)sqrt(x); i++)
        if (x % i == 0)
            return 0;

    // La so nguy to
    return 1;
}
