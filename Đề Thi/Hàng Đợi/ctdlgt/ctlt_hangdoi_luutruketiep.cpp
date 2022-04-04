// Ho va Ten : Hoang Van Tuan
// Ma SV :650024
// Lop :K65CNTTA
// DE :
/*
   *BTVN: Cài đặt cấu trúc dữ liệu hàng đợi lưu trữ kế tiếp có phần tử dữ liệu là số nguyên.
    Ứng dụng hàng đợi cho bài toán: Đọc dãy số nguyên dương từ tệp văn bản ‘d    aysonguyen.txt’,
    trên tệp không có thông tin về số lượng số, tách thành dãy số lẻ và dãy số chẵn theo đúng thứ tự xuất hiện trên tệp,
    đưa 2 dãy số ra màn hình.
   */
#include <iostream>
#include <stdio.h>

using namespace std;
//khai bao ham
void Enqueue(int *Q, int element, int &R, int x);
void Dequeue(int *Q, int &F, int &R);
int Front(int *Q, int &F);
bool ISempty(int &F, int &R);
//=== chuong trinh chinh ==
int main()
{
    // cai dat cau truc lu tru ke tiep cua hang doi
    cout << endl;
    return 0;
}
//=== Dinh nghia ham ==
// Them hang doi
void Enqueue(int *Q, int element, int &R, int x)
{
    if (R == x)
    {
        cout << "Hang doi da day";
        return;
    }
    else
    {
        Q[++R] = element;
    }
}
// xoa hang doi
void Dequeue(int *Q, int &F, int &R)
{
    if (F == R)
    {
        cout << "Hang doi da rong ";
        return;
    }
    else
    {
        Q[++R] = 0;
    }
}
//lay gia tri o hang doi
int Front(int *Q, int &F)
{
    return Q[F];
}
// kiem tra hang doi rong
bool ISempty(int &F, int &R)
{
    return (F == R);
}
