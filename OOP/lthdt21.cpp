/*Bài 21(lthdtbai21.cpp): Tính tổng 2 ma trận nguyên: Cmxn = Amxn + Bmxn. Ma trận Amxn để trong
  tệp văn bản 'matran-A.txt', ma trận Bmxn để trong tệp văn bản 'matran-B.txt'.
  Đưa các ma trận ra màn hình theo định dạng hàng, cột.
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
        int m,n; //m chua so hang, n chua so cot

    public:
        MaTran();
        MaTran operator+(const MaTran &mt2);

        //Ham ban
        friend ifstream& operator>>(ifstream &fin,MaTran &mt);
        friend ostream& operator<<(ostream &cout,MaTran &mt);
};

//===Chuong Trinh Chinh===
int main()
{
    //Tao 3 doi tuong ma tran
    MaTran A,B,C;

    //Tao doi tuong tep doc vao
    ifstream finA("matran-A.txt");
    ifstream finB("matran-B.txt");

    //Doc ma tran A va B tu tep vao doi tuong ma tran
    finA>>A;
    finB>>B;

    cout<<"Ma trận A đọc được từ tệp là:\n";
    cout<<A;
    cout<<"\n\nMa trận B đọc được từ tệp là:\n";
    cout<<B;

    //Tinh tong 2 ma tran
    C = A + B;

    //Dua ra ma tran tong
    cout<<"\n\nMa trận C = A + B là:\n";
    cout<<C;

    cout<<endl;
    return 0;
}
//===Dinh nghia ham===
MaTran::MaTran():m(0),n(0)
{

}

MaTran MaTran::operator+(const MaTran &mt2)
{
    MaTran tong;

    if(m != mt2.m || n != mt2.n)
    {
        cout<<"Hai ma trận không cùng kích thước, không cộng được!";
        return tong;
    }

    //Cong 2 ma tran cung kich thuoc
    tong.m = m;
    tong.n = n;
    for(int i=0;i<tong.m;i++)
        for(int j=0;j<tong.n;j++)
            tong.a[i][j]= a[i][j] + mt2.a[i][j];

    //Tra ve ma tran tong
    return tong;
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
                                