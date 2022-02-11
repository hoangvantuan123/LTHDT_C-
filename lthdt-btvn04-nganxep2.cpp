
  4 //De bai: Cho tep chuong trinh "lthdt-btvn04-nganxep2.cpp"
  5 //duoi day. Viet tiep cac dinh nghia ham con thieu va chuong trinh
  6 //chinh su dung ngan xep chuyen mot so nguyen duong thanh so nhi phan
  7
  8 #include<iostream>
  9 #include<stdio.h>
 10
 11 using namespace std;
 12
 13 //Khai bao lop ngan xep
 14 class Stack
 15 {
 16     private:
 17         struct node
 18         {
 19             int infor;
 20             node *link;
 21         } *T;
 22
 23     public:
 24         //Ham tao
 25         Stack();
 26         Stack(const Stack &s);
 27
 28         //Ham huy
 29         ~Stack();
 30
 31         //Ham chong toan toan tu gan
 32         Stack operator=(const Stack &right);
 33
 34         //Cac ham thanh vien cai dat cac phep toan
 35         void push(int x);
 36         int pop();
 37         bool isEmpty();
 38 };
 39
 40 //===chuong trinh chinh===
 41 int main()
 42 {
 43         Stack S;
 44         int n,thuong;
 45         cout << "Nhap so nguyen duong: \n";
 46         cin>>n;
 47         //Chuyen he 10 thanh he 2
 48         thuong=n;
 49         while(thuong)
 50         {
 51           S.push(thuong%2);
 52           thuong/=2;
 53         }
 54         cout<<"So nhi phan la: \n";
 55         while(!S.isEmpty()) cout<<S.pop();
 56         cout<<endl;
 57         return 0;
 58 }
 59 //===dinh nghia ham===
 60 Stack::Stack():T(NULL)
 61 {
 62
 63 }
 64
 65 Stack::Stack(const Stack &s):T(NULL)
 66 {
 67     node *P=s.T,*N,*Bottom;
 68
 69     //Duyet qua cac nut cua ngan xep s
 70     while(P)
 71     {
 72         //Tao nut moi
 73         N = new node;
 74         N->infor = P->infor;
 75         N->link = NULL;
 76
 77         //Noi nut moi vao ngan xep moi tao
 78         if(T==NULL)
 79         {
 80             T = Bottom = N;
 81         }
 82         else
 83         {
 84             Bottom->link = N;
 85             Bottom = N;
 86         }
 87         P = P->link;
 88     }
 89 }
 90
 91 Stack::~Stack()
 92 {
 93     while(T)
 94     {
 95         node *P=T;
 96         T=T->link;
 97         delete P;
 98     }
 99 }
100
101 Stack Stack::operator=(const Stack &right)
102 {
103     //Xoa ngan xep
104     while(T)
105     {
106         node *P=T;
107         T = T->link;
108         delete P;
109     }
110     //Tao mot ngan xep ban sao
111     node *P = right.T;
112     node *N,*Bottom;
113     while(P)
114     {
115         //Tao nut moi chua phan tu du lieu cua P
116         N = new node;
117         N -> infor = P -> infor;
118         N -> link = NULL;
119         //Noi nut moi vao ngan xep moi
120         if(T==NULL)
121         {
122             T=N;Bottom=N;
123         }
124         else
125         {
126             Bottom->link = N;
127             Bottom = N;
128         }
129         //P chuyen xuong nut duoi
130         P = P -> link;
131     }
132     return *this;
133 }
134
135 void Stack::push(int x)
136 {
137     //Tao nut moi
138     node *N = new node;
139     N -> infor = x;
140     N -> link = NULL;
141     //Noi nut moi vao tren nut T
142     N -> link = T;
143     //T tro vao nut moi
144     T = N;
145 }
146
147 int Stack::pop()
148 {
149     //Check NULL
150     if(T==NULL)
151     {
152         cout<<"Ngan xep rong\n";
153         return 1;
154     }
155     //Giu nut dau
156     int tg = T -> infor;
157     node *P = T;
158     //T tro xuong nut duoi
159     T = T -> link;
160     delete P;
161     return tg;
162 }
163
164 bool Stack::isEmpty()
165 {
166     return T == NULL;
167 }
