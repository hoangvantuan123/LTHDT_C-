/* Bài 30(lthdtbai30.cpp): Đọc vào một dãy số nguyên từ tệp văn bản, trong
đó có cả số dương và số âm.
Sử dụng hàng đợi lưu trữ kế tiếp theo kiểu quay vòng để tách, đưa ra màn
hình đồng thời
ghi ra tệp văn bản dãy các số dương và dãy các số âm. */


#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

// Khai bao lop doi tuong hang doi luu tru ke tiep
class Queue
{
private:
    enum
    {
        size = 100
    };
    int Q[size];
    int F, R;

public:
    Queue();
    void insert(int x);
    int remove();
    bool isEmpty();
};

//===chuong trinh chinh===
int main()
{
    // Tao 2 doi tuong hang doi
    Queue Q1, Q2;

    // Tao doi tuong tep vao,ra
    ifstream fin("daysonguyen.txt");
    ofstream fout("kq-bai30.txt");

    // Khai bao bien
    int x;

    // Doc day so tu tep, dua ra man hinh, gap so duong thi dua vao Q1, so am dua vao Q2
    cout << "Dãy số ban đầu đọc được từ tệp là:\n";
    while (fin >> x)
    {
        cout << x << "  ";
        if (x >= 0)
            Q1.insert(x);
        else
            Q2.insert(x);
    }

    // Dua ra day so duong va am
    cout << "\n\nCác số dương trong dãy số là:\n";
    fout << "Các số dương trong dãy số là:\n";
    while (!Q1.isEmpty())
    {
        x = Q1.remove();
        cout << x << "  ";
        fout << x << "  ";
    }

    cout << "\n\nCác số âm trong dãy số là:\n";
    fout << "\n\nCác số dương trong dãy số là:\n";
    while (!Q2.isEmpty())
    {
        x = Q2.remove();
        cout << x << "  ";
        fout << x << "  ";
    }

    cout << "\n\nKết quả cũng đã ghi ra tệp kq-bai30.txt";

    cout << endl;
    return 0;
}
//===dinh nghia ham===
Queue::Queue() : F(-1), R(-1)
{
}

void Queue::insert(int x)
{
    // 1.Kiem tra hang doi day
    if (F == 0 && R == size || R + 1 == F)
    {
        cout << "Hàng đợi đã đầy!";
        return;
    }

    // 2.Tang R len 1
    if (R == -1)
        F = R = 0;
    else if (R == size - 1)
        R = 0;
    else
        R++;

    // 3.Dua x vao Q tai vi tri R
    Q[R] = x;
}

int Queue::remove()
{
    // 1.Kiem tra hang doi rong
    if (F == -1)
    {
        cout << "Hàng đợi đã rỗng.";
        return 1;
    }

    // 2.Giu lai phan tu dau hang doi (loi truoc)
    int tg = Q[F];

    // 3.Tang F len 1
    if (F == R)
        F = R = -1;
    else if (F == size - 1)
        F = 0;
    else
        F++;

    // 4.Tra ve phan tu dau hang doi da loai bo
    return tg;
}

bool Queue::isEmpty()
{
    return F == -1;
}
