
//De:Bài 21(lthdtbai21.cpp): Tính tổng 2 ma trận nguyên: Cmxn = Amxn + Bmxn. Ma trận Amxn để trong
//tệp văn bản 'matran-A.txt', ma trận Bmxn để trong tệp văn bản 'matran-B.txt'.
//Đưa các ma trận ra màn hình theo định dạng hàng, cột.

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
	MaTran operator+(const MaTran &mt2);

	//Hàm bạn
    	friend ifstream& operator>>(ifstream &fin,MaTran &mt);
	friend ostream&  operator<<(ostream &cout,const MaTran &mt);
};

//===chương trình chính===
int main()
{
    //Tao 3 doi tuong ma tran
    MaTran A,B,C;

    //Tao 2 doi tuong tep
    ifstream finA("matran-A.txt");
    ifstream finB("matran-B.txt");

    //Doc 2 ma tran A va B tu tep vao doi tuong A, B tuong ung
    finA>>A;
    finB>>B;

    //Tinh tong
    C = A + B;

    //Dua ra cac ma tran
    cout<<"Ma trận A:\n"<<A;

    cout<<"\n\nMa trận B:\n"<<B;

    cout<<"\n\nMa trận C = A + B:\n"<<C;

    cout<<endl;
    return 0;
}

//===đinh nghĩa hàm===
MaTran::MaTran():m(0),n(0)
{

}

MaTran MaTran::operator+(const MaTran &mt2)
{
    MaTran tg;

    if(m != mt2.m || n != mt2.n)
    {
	cout<<"Hai ma trận không cùng kích thước,không cộng được.";
	return tg;
    }

    //Cong 2 ma tran
    tg.m = m; tg.n = n;
    for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	    tg.a[i][j] = a[i][j] + mt2.a[i][j];

    //Tra ve ma tran tong
    return tg;
}

ifstream& operator>>(ifstream &fin,MaTran &mt)
{
    fin>>mt.m>>mt.n;
    for(int i=0;i<mt.m;i++)
	for(int j=0;j<mt.n;j++)
	    fin>>mt.a[i][j];

    return fin;
}

ostream& operator<<(ostream &cout,const MaTran &mt)
{
    for(int i=0;i<mt.m;i++)
    {
	for(int j=0;j<mt.n;j++)
	    printf("%5d",mt.a[i][j]);

	//Xuong dong
	printf("\n");
    }

    return cout;
}

