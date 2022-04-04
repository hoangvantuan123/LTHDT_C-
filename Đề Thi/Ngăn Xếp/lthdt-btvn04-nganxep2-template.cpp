
// De bai: Tao mau ngan xep luu tru phan tan. Su dung doi tuong
// ngan xep co phan tu la so nguyen de chuyen hej 10 thanh he hai
// va doi tuong ngan xep co phan tu la ky tu de chuyen he 10 thanh 16
#include <iostream>
#include <stdio.h>
using namespace std;
// Khai bao lop
template <class Type>
class Stack
{
private:
  struct node
  {
    int infor;
    node *link;
  } * T;

public:
  Stack();
  ~Stack();
  Stack(const Stack &s);
  Stack operator=(const Stack &right);
  void push(Type x);
  Type pop();
  bool isEmpty();
};

//===chuong trinh chinh===
int main()
{

  // Tao doi tuong ngan xep S1 co kieu phan tu la so nguyen
  Stack<int> S1;

  // Tao doi tuong ngan xep S2 co kieu phan tu la ky tu
  Stack<char> S2;

  // Khai bao bien
  int n, thuong, du;

  cout << "Nhập vào một số nguyên dương: ";
  cin >> n;

  // Chuyen he 10 thanh he 2
  thuong = n;
  while (thuong)
  {
    S1.push(thuong % 2);
    thuong /= 2;
  }

  cout << "Số nhị phân của " << n << " là: ";
  ;
  while (!S1.isEmpty())
    cout << S1.pop();

  // Chuyen he 10 thanh he 16
  thuong = n;
  while (thuong)
  {
    du = thuong % 16;

    if (du < 10)
      S2.push(du + 48); // chuyen so thanh chu so roi day vao ngan xep
    else
      S2.push(du + 55); // chuyen so thanh chu cai roi day vao ngan xep

    thuong /= 16;
  }
  cout << "\nSố hex của " << n << " là: ";
  ;
  while (!S2.isEmpty())
    cout << S2.pop();
  cout << endl;
  return 0;
}
//===dinh nghia ham===
template <class Type>
Stack<Type>::Stack() : T(NULL)
{
}

template <class Type>
Stack<Type>::~Stack()
{
  while (T)
  {
    node *P = T;
    T = T->link;
    delete P;
  }
}

template <class Type>
Stack<Type>::Stack(const Stack &s) : T(NULL)
{
  node *P = s.T, *N, *Bottom;
  while (P)
  {
    N = new node;
    N->infor = P->infor;
    N->link = NULL;
    if (T == NULL)
    {
      T = Bottom = N;
    }
    else
    {
      Bottom->link = N;
      Bottom = N;
    }
    P = P->link;
  }
}

template <class Type>
Stack<Type> Stack<Type>::operator=(const Stack<Type> &right)
{
  while (T)
  {
    node *P = T;
    T = T->link;
    delete P;
  }
  node *P = right.T;
  node *N, *Bottom;
  while (P)
  {
    N = new node;
    N->infor = P->infor;
    N->link = NULL;
    if (T == NULL)
    {
      T = N;
      Bottom = N;
    }
    else
    {
      Bottom->link = N;
      Bottom = N;
    }
    P = P->link;
  }
  return *this;
}

template <class Type>
void Stack<Type>::push(Type x)
{
  node *N = new node;
  N->infor = x;
  N->link = NULL;
  N->link = T;
  T = N;
}
template <class Type>
Type Stack<Type>::pop()
{
  if (T == NULL)
  {
    cout << "Ngan xep rong\n";
    return 1;
  }
  int tg = T->infor;
  node *P = T;
  T = T->link;
  delete P;
  return tg;
}

template <class Type>
bool Stack<Type>::isEmpty()
{
  return T == NULL;
}
