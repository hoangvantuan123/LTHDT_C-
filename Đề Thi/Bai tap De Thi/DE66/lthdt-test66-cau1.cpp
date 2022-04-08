/* Câu 1: Cho tệp văn bản “Phanso1.txt” và
“Phanso2.txt” , Mỗi tệp có một dòng chứa phân số
ở dạng a/b . TÍnh hiệu hai phân số đọc vào từ tệp.
Đưa các phân số ra màn hình ở dạng rút gọn và
chưa rút gọn. Yêu cầu sử dụng toán tử nhập >> để
đọc vào phân số từ tệp , sử dụng toán tử xuất << để
đưa phân số ra màn hình ở dạng a/b , sử dụng toán
tử - để trừ hai phân số ; Phân số được tự động khởi
tạo tử số bằng 0 và mẫu số bằng 1 hoặc được khởi
tạo tử số và mẫu số bằng giá trị cho trước .
 */
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;
class PhanSo
{
private:
    int a, b;

public:
    PhanSo();

    PhanSo operator-(PhanSo &ps1);

    friend istream &operator>>(istream &cin, PhanSo &ps);
    friend ostream &operator<<(ostream &cout, PhanSo &ps);
};
//==Chuong trinh chinh==
int main()
{
    PhanSo A, B, h;

    ifstream finA("phanso1.txt");
    ifstream finB("phanso2.txt");

    finA >> A;
    finB >> B;
    // Dua ra phan so A,B
    cout << "\nPhan So thu nhat la :" << A;
    cout << "\nPhan So thu hai la :" << B;

    h = A - B;

    cout << "\nHieu hai phan so la: " << h;

    cout << endl;
    return 0;
}
//==dinh nghia ham==

PhanSo::PhanSo() : a(0), b(1)
{
}
PhanSo PhanSo::operator-(PhanSo &ps1)
{
    PhanSo h;
    h.a = this->a * ps1.b - ps1.a * this->b;
    h.b = this->b * ps1.b;
    return h;
}

istream &operator>>(istream &cin, PhanSo &ps)
{
    cin >> ps.a >> ps.b;
    return cin;
}

ostream &operator<<(ostream &cout, PhanSo &ps)
{
    cout << ps.a << "/" << ps.b;
    return cout;
}
