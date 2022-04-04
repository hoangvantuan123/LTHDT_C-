
//De: 18
/*
Bài 18(thctdlgtbai18.cpp): Cài đặt và sử dụng hàng đợi lưu trữ phân tán cho bài toán sau:
Cho tệp văn bản 'dathuc.txt' chứa đa thức tuyến tính bậc n. Đọc tệp, đưa ra màn hình đa thức bậc n
theo dạng Pn(x) = a0 + a1x + a2x^2 + a3x^3 +...+ anx^n. Nhập vào x, tính Pn(x).
*/

#include<iostream>
#include<fstream>
#include<stdio.h>
#include<math.h>

using namespace std;

//Khai bao cau truc mot so hang gom he so va so mu
struct term
{
    float coeff;
    int power;
};

//Khai bao cau truc nut nho cua hang doi
struct node
{
    term infor;
    node *link;
};

//Khai bao cau truc gop 2 bien F va R
struct Queue
{
    node *F,*R;
};

//Khai bao ham cai dat cac phep toan tren hang doi
void QInsert(Queue &Q, term x);
term QDelete(Queue &Q);
bool QIsEmpty(Queue Q);

//===chuong trinh chinh===
int main()
{
    //Cai dat cau truc luu tru phan tan cua hang doi
    Queue Q={NULL,NULL};

    //Khai bao tep vao
    ifstream fin("dathuc.txt");

    //Khai bao bien
    term t;

    //Doc da thuc tu tep dua vao hang doi va dua ra man hinh
    cout<<"Đa thức đọc từ tệp là:\nP(x) = ";
    while(fin>>t.coeff>>t.power)
    {
	if(t.power==0) printf("%0.1f",t.coeff);
	else printf(" + %0.1fx^%d",t.coeff,t.power);
	QInsert(Q,t);
    }

    //Tinh P(x)
    float x,Px=0;
    cout<<"\n\nNhập vào x: ";cin>>x;

    while(!QIsEmpty(Q))
    {
	t = QDelete(Q);
	Px += t.coeff*pow(x,t.power);
    }

    printf("P(x) = %0.1f",Px);

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void QInsert(Queue &Q, term x)
{
    //1.Tao nut moi
    node *N=new node;
    N->infor=x;
    N->link=NULL;

    //2.Noi nut moi vao sau nut R
    if(Q.R==NULL) Q.F=N;
    else Q.R->link=N;

    //3.Cho R tro sang nut moi
    Q.R=N;
}

term QDelete(Queue &Q)
{
    term tg;

    //1.Kiem tra rong
    if(Q.F==NULL)
    {
	cout<<"Hang doi da rong!";
	return tg;
    }

    //2.Giu lai nut F
    tg=Q.F->infor;
    node *P=Q.F;

    //3.Cho F tro toi nut dung sau
    if(Q.F==Q.R) Q.F=Q.R=NULL;
    else Q.F=Q.F->link;

    //4.Huy va tra ve nut
    delete P;
    return tg;
}

bool QIsEmpty(Queue Q)
{
    return Q.F==NULL;
}


