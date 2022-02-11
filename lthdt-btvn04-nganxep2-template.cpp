
  4 //De bai: Tao mau ngan xep luu tru phan tan. Su dung doi tuong
  5 //ngan xep co phan tu la so nguyen de chuyen hej 10 thanh he hai
  6 //va doi tuong ngan xep co phan tu la ky tu de chuyen he 10 thanh 16
  7
  8 #include<iostream>
  9 #include<stdio.h>
 10
 11 using namespace std;
 12
 13 //Khai bao lop
 14 template <class Type>
 15 class Stack
 16 {
 17     private:
 18         struct node
 19         {
 20             int infor;
 21             node *link;
 22         } *T;
 23
 24     public:
 25         Stack();
 26         ~Stack();
 27         Stack(const Stack &s);
 28         Stack operator=(const Stack &right);
 29         void push(Type x);
 30         Type pop();
 31         bool isEmpty();
 32 };
 33
 34 //===chuong trinh chinh===
 35 int main()
 36 {
 37
 38     //Tao doi tuong ngan xep S1 co kieu phan tu la so nguyen
 39     Stack<int> S1;
 40
 41     //Tao doi tuong ngan xep S2 co kieu phan tu la ky tu
 42     Stack<char> S2;
 43
 44     //Khai bao bien
 45     int n,thuong,du;
 46
 47     cout<<"Nhập vào một số nguyên dương: "; cin>>n;
 48
 49     //Chuyen he 10 thanh he 2
 50     thuong=n;
 51     while(thuong)
 52     {
 53         S1.push(thuong%2);
 54         thuong/=2;
 55     }
 56
 57     cout<<"Số nhị phân của "<<n<<" là: ";;
 58     while(!S1.isEmpty()) cout<<S1.pop();
 59
 60     //Chuyen he 10 thanh he 16
 61     thuong=n;
 62     while(thuong)
 63     {
 64         du=thuong%16;
 65
 66         if(du<10) S2.push(du+48); //chuyen so thanh chu so roi day vao ngan xep
 67         else S2.push(du+55); //chuyen so thanh chu cai roi day vao ngan xep
 68
 69         thuong/=16;
 70     }
 71     cout<<"\nSố hex của "<<n<<" là: ";;
 72     while(!S2.isEmpty()) cout<<S2.pop();
 73
 74 cout<<endl;
 75 return 0;
 76 }
 77 //===dinh nghia ham===
 78 template <class Type>
 79 Stack<Type>::Stack():T(NULL)
 80 {
 81
 82 }
 83
 84 template <class Type>
 85 Stack<Type>::~Stack()
 86 {
 87 while(T)
 88 {
 89     node *P=T;
 90     T=T->link;
 91         delete P;
 92     }
 93 }
 94
 95 template <class Type>
 96 Stack<Type>::Stack(const Stack &s):T(NULL)
 97 {
 98     node *P=s.T,*N,*Bottom;
 99     while(P)
100     {
101         N = new node;
102         N->infor = P->infor;
103         N->link = NULL;
104         if(T==NULL)
105         {
106              T = Bottom = N;
107         }
108         else
109         {
110              Bottom->link = N;
111              Bottom = N;
112         }
113         P = P->link;
114     }
115 }
116
117 template <class Type>
118 Stack<Type> Stack<Type>::operator=(const Stack<Type> &right)
119 {
120      while(T)
121      {
122          node *P=T;
123          T = T->link;
124          delete P;
125      }
126      node *P = right.T;
127      node *N,*Bottom;
128      while(P)
129      {
130          N = new node;
131          N -> infor = P -> infor;
132          N -> link = NULL;
133          if(T==NULL)
134          {
135              T=N;Bottom=N;
136          }
137          else
138         {
139              Bottom->link = N;
140              Bottom = N;
141         }
142          P = P -> link;
143      }
144      return *this;
145 }
146
147 template <class Type>
148 void Stack<Type>::push(Type x)
149 {
150     node *N = new node;
151     N -> infor = x;
152     N -> link = NULL;
153     N -> link = T;
154     T = N;
155 }
156 template <class Type>
157 Type Stack<Type>::pop()
158 {
159     if(T==NULL)
160     {
161         cout<<"Ngan xep rong\n";
162         return 1;
163     }
164     int tg = T -> infor;
165     node *P = T;
166     T = T -> link;
167     delete P;
168     return tg;
169 }
170
171 template <class Type>
172 bool Stack<Type>::isEmpty()
173 {
174     return T == NULL;
175 }
176
