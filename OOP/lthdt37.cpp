/*
Bài 37(lthdtbai37.cpp): Tạo lớp đối tượng xâu ký tự có các đặc điểm giống như xâu ký tự
trong Pascal: Có thể khởi tạo đối tượng xâu bằng một hằng xâu; có thể gán hằng xâu hoặc
đối tượng xâu cho đối tượng xâu; có thể dùng phép toán + để nối xâu; có thể dùng các
phép toán so sánh để so sánh xâu; có thể dùng cin và cout để nhập vào và đưa ra đối tượng xâu.
*/

#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>

using namespace std;

class String
{
    private:
        enum {size=256};
        char str[size];

    public:
        String();
        String(const char *s);
        String operator+(const String &s2);
        bool operator>(const String &s2);
        bool operator>=(const String &s2);
        bool operator<(const String &s2);
        bool operator<=(const String &s2);
        bool operator==(const String &s2);
        bool operator!=(const String &s2);

        //Ham ban
        friend istream& operator>>(istream &cin,String &s);
        friend ostream& operator<<(ostream &cout,String &s);
};

//===chuong trinh chinh===
int main()
{

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
String::String()
{
    strcpy(str,"");
}

String::String(const char *s)
{
    if(strlen(s)<size) strcpy(str,s);
    else
    {
        cout<<"Xâu khởi tạo quá dài!";
        strcpy(str,"");
    }
}

String String::operator+(const String &s2)
{
    //Neu chieu dai cua 2 xau < size thi noi
    if(strlen(str)+strlen(s2.str)<size) strcat(str,s2.str);

    //Tra ve xau ben trai
    return *this;
}

bool String::operator>(const String &s2)
{
    return strcasecmp(str,s2.str)>0;
}


bool String::operator>=(const String &s2)
{
    return strcasecmp(str,s2.str)>=0;
}

bool String::operator<(const String &s2)
{
    return strcasecmp(str,s2.str)<0;
}

bool String::operator<=(const String &s2)
{
    return strcasecmp(str,s2.str)<=0;
}

bool String::operator==(const String &s2)
{
    return strcasecmp(str,s2.str)==0;
}

bool String::operator!=(const String &s2)
{
    return strcasecmp(str,s2.str);
}

//Ham ban
istream& operator>>(istream &cin,String &s)
{
    scanf(" ");cin.get(s.str,s.size);

    return cin;
}

ostream& operator<<(ostream &cout,String &s)
{
    cout<<s.str;
    return cout;
}
