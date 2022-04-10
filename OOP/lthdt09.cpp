/*
Bài 09(lthdtbai09.cpp):Sắp xếp danh sách n họ tên theo vần ABC,
nếu trùng tên thì sắp xếp theo họ, nếu trùng cả họ thì sắp xếp theo tên đệm.
Danh sách họ tên đọc vào từ tệp văn bản "dsten.txt", danh sách tên đã sắp xếp ghi ra
tệp văn bản "ketqua-lthdtbai09.txt". Y/c viết 1 hàm đưa ra danh sách tên, 1 hàm sắp xếp danh sách
tên và 1 hàm hoán đổi nội dung 2 biến xâu chứa tên.
*/
#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

void duaRaDS(char **ds,int n);
void sapXepDS(char **ds,int n);
void doiCho(char *s1,char *s2);

//===chuong trinh chinh===
int main()
{

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void duaRaDS(char **ds,int n)
{

}

void sapXepDS(char **ds,int n)
{

}

void doiCho(char *s1,char *s2)
{
    char tg[31];

    strcpy(tg,s1);
    strcpy(s1,s2);
    strcpy(s2,tg);
}
