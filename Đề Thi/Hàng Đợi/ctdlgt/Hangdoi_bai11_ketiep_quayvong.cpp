
/*De:
Bài 11(thctdlgtbai11.cpp): Cài đặt cấu trúc dữ liệu hàng đợi sử dụng
cấu trúc lưu trữ kế tiếp theo kiểu quay vòng. Sử dụng hàng đợi cho bài toán:
Có một tệp danh sách sinh viên, mỗi sinh viên có thông tin gồm mã sv, họ tên, giới tính, điểm tbc.
Danh sách sinh viên trên tệp đã được sắp xếp theo điểm tbc giảm dần.
Ghi lại tệp sao cho tất cả sinh viên nữ ở đầu danh sách, tất cả sinh viên nam ở cuối danh sách,
điểm tbc vẫn giảm dần trong nhóm nam và nữ.
*/
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

//Khai bao hang
#define N 50

//Khai bao kieu truc sinh vien
struct SinhVien
{
    char maSV[7];
    char hoTen[31];
    char gioiTinh[5];
    float diemTBC;
};

//Khai bao kieu cau truc gop 3 bien
struct Queue
{
    int F, R;
    SinhVien Q[N];
};

//khai bao ham cai dat cac phep toan tren hang doi
void CQInsert(Queue &QFR, SinhVien x);
SinhVien CQDelete(Queue &QFR);
bool CQIsEmpty(Queue QFR);

//Chuong trinh chinh
int main()
{
    //Cai dat cau truc luu tru ke tiep cua hang doi
    Queue QFR = {-1, 1};

    //Khai bao tep vao ra
    ifstream fin("sinhvien.txt");
    ofstream fout("sinhvien2.txt");

    //Khai bao bien
    int n;
    SinhVien x;

    //Doc so luong sv tu tep va ghi ra tep sinhvien2.txt
    fin >> n;
    fout << n << endl;

    //Doc tung sv tu tep, neu la sv nu thi ghi ra tep, neu la sv nam thi dua vao hang doi
    for (int i = 0; i < n; i++)
    {
        //Doc Enter tren tep
        fin.getline(x.maSV, sizeof(x.maSV));

        //Doc thong tin sv
        fin.getline(x.maSV, sizeof(x.maSV), '\t');
        fin.getline(x.hoTen, sizeof(x.hoTen), '\t');
        fin.getline(x.gioiTinh, sizeof(x.gioiTinh), '\t');
        fin >> x.diemTBC;

        //Neu la nu thi ghi ra tep, con lai dua vao hang doi
        if (strcasecmp(x.gioiTinh, "Nữ") == 0)
        {
            fout << x.maSV << '\t' << x.hoTen << '\t' << x.gioiTinh << '\t' << x.diemTBC << endl;
        }
        else
            CQInsert(QFR, x);
    }

    //Lay danh sach sv nam tu hang doi ghi tiep ra tep
    while (!CQIsEmpty(QFR))
    {
        //Lay sv tu hang doi
        x = CQDelete(QFR);

        //Ghi sv ra tep
        fout << x.maSV << '\t' << x.hoTen << '\t' << x.gioiTinh << '\t' << x.diemTBC << endl;
    }

    cout << "\nDa ghi lai danh sach sinh vien ra tep sinhvien2.txt";

    cout << endl;
    return 0;
}
//==Dinh nghia ham
void CQInsert(Queue &QFR, SinhVien x)
{
    //1.Kiem tra day
    if (QFR.F == 0 && QFR.R == N - 1 || QFR.R + 1 == QFR.F)
    {
        cout << "Hang doi da day!";
        return;
    }

    //2.Tang R len 1
    if (QFR.R == -1)
        QFR.F = QFR.R = 0;
    else if (QFR.R == N - 1)
        QFR.R = 0;
    else
        QFR.R++;

    //3.Dua x vao hang doi tai vi tri R
    QFR.Q[QFR.R] = x;
}

SinhVien CQDelete(Queue &QFR)
{
    SinhVien tg;

    //1.Kiem tra rong
    if (QFR.F == -1)
    {
        cout << "Hang doi rong!";
        return tg;
    }

    //2.Luu lai phan tu dau hang doi
    tg = QFR.Q[QFR.F];

    //3.Tang F len 1
    if (QFR.F == QFR.R)
        QFR.F = QFR.R = -1;
    else if (QFR.F == N - 1)
        QFR.F = 0;
    else
        QFR.F++;

    //tra ve
    return tg;
}

bool CQIsEmpty(Queue QFR)
{
    return QFR.F == -1;
}
