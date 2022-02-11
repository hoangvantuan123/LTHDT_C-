//Bài 20(lthdtbai20.cpp): Cho ma trận nguyên Amxn. Tính tổng và trung bình cộng
//các phần tử của ma trận. Đưa ra ma trận chuyển vị của A. Ma trận Amxn đọc từ tệp văn bản "matran.txt".

#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;

//Khai bao lop ma tran
class MaTran
{
    private:
        enum {size=10};
        int a[size][size];
        int m,n; //m chua so hang, n chua so cot

    public:
        MaTran();
        int tinhTong();
        float tinhTBC();
        void chuyenVi();

        //Ham ban
        friend ifstream& operator>>(ifstream &fin,MaTran &mt);
        friend ostream& operator<<(ostream &cout,MaTran &mt);
};


//===chuong trinh chinh===
int main()
{

    //Tạo đối tượng ma trận
    MaTran A;

    //Tạo đối tượng tệp doc vao
    ifstream fin("matran.txt");

    //Đọc ma trận A từ trong tệp
    fin>>A;

    //Đưa ra ma trận A được lấy từ trong tệp
    cout<<"Ma trận A được đọc từ tệp là:\n";
    cout<<A;

    cout<<"\nMa trận chuyển vị của ma trận A là: "<<endl;
    A.chuyenVi();

    cout<<"\n\nTổng của các phần tử trong ma trận A là: "<<A.tinhTong();
    printf("\nTrung bình cộng của các phần tử trong ma trận A là: %0.1f",A.tinhTBC());

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
MaTran::MaTran():m(0),n(0)
{

}

int MaTran::tinhTong()
{
    //Khởi tạo biến tong = 0 với tong là biến lưu trữ tổng của các phần tử trong ma trận
    int tong=0;

    //Lần lượt cộng biến tong với từng phần tử của ma trận
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            tong += a[i][j];

    //Trả về biến tong
    return tong;
}

float MaTran::tinhTBC()
{
    float tong=0;

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            tong += a[i][j];

    return tong/(m*n);
}

void MaTran::chuyenVi()
{
    //In ma trận chuyển vị ra màn hình theo định dạng hàng-cột
    for(int j=0;j<n;j++)
    {
        //Dua ra cac phan tu tren cot j
        for(int i=0;i<m;i++)
            printf("%6d",a[i][j]);

        //Xuong dong
        cout<<endl;
    }
}

//Ham ban
ifstream& operator>>(ifstream &fin,MaTran &mt)
{
    //Doc so hang, so cot cua ma tran tu tep
    fin>>mt.m>>mt.n;

    //Doc ma tran tu tep vao mang 2 chieu a
    for(int i=0;i<mt.m;i++)
        for(int j=0;j<mt.n;j++) fin>>mt.a[i][j];

    return fin;
}

ostream& operator<<(ostream &cout,MaTran &mt)
{
    //In ma trận ra màn hình theo định dạng hàng-cột
    for(int i=0;i<mt.m;i++)
    {
        //Dua ra hang i
        for(int j=0;j<mt.n;j++)
            printf("%6d",mt.a[i][j]);

        //Xuong dong
        cout<<endl;
    }

    return cout;
}