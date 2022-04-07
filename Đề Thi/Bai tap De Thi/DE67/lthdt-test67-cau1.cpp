/* i
Cho tệp văn bản "matran.txt " chưa ma trận số thực Amxn đọc vào ma trận A từ tệp .
Tính trung bình cộng các phần tử của ma trận A.
Nhân ma trận A với một số thực x nhập vào từ bàn phím để đưcoj ma trận B ( B= A*x) . Đưa ma trận A và B ra màn hình
theo định dạng hàng cột . Yêu cầu sử dụng toán tử nhập >> để đọc vào ma trận từ tệp
sử dụng toán tủw xuất << để đưa ma trận ra màn hình theo định dạng hàng , cột ; sử dụng toán tử nhân  *
để nhân ma trận với một số; ma trận được tạo tự động khởi tạo kích thức  m,n  bằng 0;
 */

#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;

class MaTran
{
    private:
        enum {size=10};
        int a[size][size];
        int m,n;


    public:
        MaTran();
        float tinhTBC();
        MaTran operator*(const int x );
        //Ham ban
        friend ifstream& operator>>(ifstream &fin,MaTran &mt);
        friend ostream& operator<<(ostream &cout,MaTran &mt);
};

//===Chuong Trinh Chinh===
int main()
{
    MaTran A, B ;
    float x;
      ifstream finA("matran.txt");

      finA>> A;
      cout <<"\nMa tran  A doc tu tep la : \n" <<A ;

      // Dua ra tbc cac phan tu ma tran A
      printf("\nTrung binh cong cac phan tu cua ma tran A la: %0.1f",A.tinhTBC());

      //Tinh ma tran vo huong
      cout<<"\n\nNhap vao so thuc x : " ;
      cin >> x;

      //Phep nhan ma tran vo huong
      B = A * x ;

      cout <<"\nMa tran B khi duoc tinh la : \n" <<B ;


    cout<<endl;
    return 0;
}
//===Dinh nghia ham===
MaTran::MaTran():m(0),n(0)
{

}
float MaTran::tinhTBC()
{
	float tong=0;

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            tong += a[i][j];

    return tong/(m*n);
}
MaTran MaTran::operator*( const int x )
{
	MaTran B;
	B.m = m;
    B.n = n;
	for (int i=0; i<B.m; i++){
        for (int j=0; j<B.n; j++){
            B.a[i][j]=a[i][j]*x;
        }
    }
    return B ;

}

//Ham ban
ifstream& operator>>(ifstream &fin,MaTran &mt)
{
    fin>>mt.m>>mt.n;

    for(int i=0;i<mt.m;i++)
        for(int j=0;j<mt.n;j++)
            fin>>mt.a[i][j];

    return fin;
}

ostream& operator<<(ostream &cout,MaTran &mt)
{
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
