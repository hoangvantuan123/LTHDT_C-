/*(lthdtbai27.cpp): Viết chương trình nhập vào danh sách n sinh viên,
mỗi sinh viên có thông tin về mã sinh viên, tên và điểm tbc.
Mã SV là các số nguyên được lấy tự động có giá trị từ 11 trở đi.
Đưa ra màn hình số lượng (không dùng n) và danh sách sinh viên đã nhập.
Yêu cầu trong chương trình có sử dụng biến tĩnh và hàm tĩnh;
sử dụng mảng đối tượng động.
 */
#include<iostream>
#include<stdio.h>

using namespace std;

 //khai bao lop
class SinhVien
{
    private:
        int maSV;
        char tenSV[10];
        float diemTBC;

        //Bien cua lop
        static int stt;

    public:
        void nhap();
        void hien();

        //Ham cua lop
        static int laySL();
};

//Dinh nghia bien cua lop
int SinhVien::stt=10;

//===chuong trinh chinh===
int main()
{
    //Khai bao bien
    int n,i;

    cout<<"Nhập vào số lượng sv: ";cin>>n;

    //Tao mang dong n doi tuong sv
    SinhVien *dssv = new SinhVien[n];

    //Nhap dssv
    cout<<"Nhập thông tin sinh viên:";
    for(i=0;i<n;i++)
    {
        printf("\nNhập sinh viên thứ %d:\n",i+1);
        dssv[i].nhap();
    }

    cout<<"\nSố lượng sinh viên đã nhập là: "<<SinhVien::laySL();

    cout<<"\nDanh sách sinh viên đã nhập là:\n";
    printf("%-4s%-6s%-10s%10s\n","TT","Ma SV","Ten SV","Diem TBC");
    for(i=0;i<n;i++)
    {
        printf("%-4d",i+1);
        dssv[i].hien();
    }

    //Huy mang dong
    delete [] dssv;

    cout<<endl;
    return 0;
}
//===Dinh nghia ham===
void SinhVien::nhap()
{
    //Lay tu dong ma sv
    maSV = ++stt;

    cout<<"Mã sinh viên: "<<maSV;
    cout<<"\nNhập vào tên: ";cin>>tenSV;
    cout<<"Nhập điểm tbc: ";cin>>diemTBC;
}

void SinhVien::hien()
{
    printf("%-6d%-6s%6.1f\n",maSV,tenSV,diemTBC);
}

int SinhVien::laySL()
{
    return stt-10;
}
