/*
Bài 43(lthdtbai43.cpp): Viết chương trình quản lý nhân sự của một trường học;
nhân sự gồm có giảng viên và sinh viên; giảng viên có mã gv, họ tên và số bài báo;
sinh viên có mã sv, họ tên và điểm tbc. Nhập vào một số nhân sự trong đó có cả giảng viên
và sinh viên. Đưa ra thông tin của các nhân sự đã nhập kèm theo đánh giá:
giảng viên đánh giá là giỏi nếu số bài báo >=5, sinh viên đánh giá là giỏi
nếu điểm TBC>=8.0. Y/c cài đặt đa hình động.
Yêu cầu thêm:
1) Viết một hàm lựa chọn loại nhân sự cần nhập thông tin, nhập thông tin cho nhân sự
    và trả về nhân sự đã nhập thông tin;
2) Viết một hàm đưa ra thông tin của nhân sự truyền vào qua đối số.
*/
#include <iostream>
#include <stdio.h>

using namespace std;

// Khai bao lop nhan su
class NhanSu
{
private:
    char hoTen[36];

public:
    virtual void nhap();
    virtual void hien();
};

// Khai bao lop giang vien
class GiangVien : public NhanSu
{
private:
    char maGV[11];
    int soBB;

public:
    void nhap();
    void hien();
};

// Khai bao lop sinh vien
class SinhVien : public NhanSu
{
private:
    char maSV[11];
    float diemTBC;

public:
    void nhap();
    void hien();
};

// Khai bao ham thong thuong
NhanSu *nhapTT();
void hienTT(NhanSu *x);

//===chuong trinh chinh===
int main()
{
    // Tao mang con tro lop co so nhan su
    NhanSu *ds[100];

    // Khai bao bien
    int n = 0;
    char traLoi;

    do
    {
        // Nhap thong tin
        ds[n++] = nhapTT();

        // Hoi co nhap tiep ko
        cout << "\nCo nhap tiep khong(c/k)? ";
        cin >> traLoi;
    } while (traLoi == 'c' || traLoi == 'C');

    // Dua ra danh sach nhan su da nhap
    cout << "\nDanh sach nhan su da nhap la:";
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhan su thu " << i + 1 << ":";
        hienTT(ds[i]);
        cout << endl;
    }

    cout << endl;
    return 0;
}
//===dinh nghia ham===
// Ham lop nhan su
void NhanSu::nhap()
{
    cout << "Nhap vao ho ten: ";
    scanf(" ");
    cin.get(hoTen, sizeof(hoTen));
}

void NhanSu::hien()
{
    cout << "\n\tHo ten: " << hoTen;
}

// Ham lop giang vien
void GiangVien::nhap()
{
    cout << "Nhap ma giang vien: ";
    cin >> maGV;

    // Nhap ho ten
    NhanSu::nhap();
    cout << "Nhap so bai bao: ";
    cin >> soBB;
}

void GiangVien::hien()
{
    cout << "\n\tMa giang vien: " << maGV;

    // Hien ho ten
    NhanSu::hien();

    cout << "\n\tSo bai bao: " << soBB;
    if (soBB >= 5)
        cout << "\n\tDanh gia: Giang vien gioi.";
}

// Ham lop sinh vien
void SinhVien::nhap()
{
    cout << "Nhap ma sinh vien: ";
    cin >> maSV;

    // Nhap ho ten
    NhanSu::nhap();
    cout << "Nhap diem TBC: ";
    cin >> diemTBC;
}

void SinhVien::hien()
{
    cout << "\n\tMa sinh vien: " << maSV;

    // Hien ho ten
    NhanSu::hien();

    cout << "\n\tDiem TBC: " << diemTBC;
    if (diemTBC >= 8)
        cout << "\n\tDanh gia: Sinh vien gioi.";
}

// Ham thong thuong
NhanSu *nhapTT()
{
    NhanSu *ns;
    char chon;

    // Lay lua chon
    cout << "Chon loai nhan su can nhap thong tin (1-GV,2-SV): ";
    cin >> chon;

    // Tao doi tuong nhan su theo lua chon
    if (chon == '1')
        ns = new GiangVien;
    else
        ns = new SinhVien;

    // Dung da hinh donh de nhap thong tin cho doi tuong da tao
    ns->nhap();

    // Tra ve nhan su da nhap thong tin
    return ns;
}

void hienTT(NhanSu *x)
{
    // Dung da hinh dong de dua ra thong tin cua nhan su
    x->hien();
}
