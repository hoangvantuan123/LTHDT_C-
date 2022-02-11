// Bài 37: Tạo lớp đối tượng xâu ký tự có các đặc điểm giống như xâu ký tự
// trong Pascal: Có thể khởi tạo đối tượng xâu bằng một hằng xâu; có thể gán hằng xâu hoặc
// đối tượng xâu cho đối tượng xâu; có thể dùng phép toán + để nối xâu; có thể dùng các
// phép toán so sánh để so sánh xâu; có thể dùng cin và cout để nhập vào và đưa ra đối tượng xâu.
#include<iostream>
#include<stdio.h>
#include<cstring>

using namespace std;
//Khai bao lop
class String
{
    private:
        char char_array[50];
    public:
        String();
        String(const char *str) {
            strcpy(char_array, str);
        }

        String operator + (String str);
        void operator = (String str);
        void operator = (const char *str);
        bool operator < (const char *str);
        bool operator > (const char *str);
        bool operator <= (const char *str);
        bool operator >= (const char *str);
        bool operator == (const char *str);

        friend istream& operator >> (istream &cin,String &str);
        friend ostream& operator << (ostream &cout,String &str);
};

//===Chuong trinh chinh
int main()
{
    String s1("Hello"), s2(" World");
    if(s1 < "hello") 
    {
        cout << "s1 < \"hello\" ";
    }

    cout<<endl;
    return 0;
}
//===Dinh ngia ham
String::String()
{
    strcpy(char_array,"");
}

String String::operator + (String str)
{
  return String(strcat(char_array, str.char_array));
}

void String::operator = (String str)
{
    strcpy(this->char_array, str.char_array);
}

void String::operator = (const char *str)
{
    strcpy(this->char_array,str);
}

bool String::operator < (const char *str)
{
    return (strcmp(this->char_array,str) < 0);
}

bool String::operator > (const char *str)
{
    return (strcmp(this->char_array,str)>0);
}

bool String::operator <= (const char *str)
{
    return (strcmp(this->char_array,str)<=0);    
}

bool String::operator >= (const char *str)
{
    return (strcmp(this->char_array,str)>=0);
}

bool String::operator == (const char *str)
{
    return (strcmp(this->char_array,str)==0);
}

istream& operator >> (istream &cin,String &str)
{
    cin.getline(str.char_array, sizeof(str.char_array), '\n');
    return cin;
}

ostream& operator << (ostream &cout,String &str)
{
    cout<<str.char_array;
    return cout;
}
// str1 = "Name";
    // str2 = "NoName";
    // strcat(str1,str2);
    // str1 = "NameNoName";
    // str2 = "NoName";
    // strcmp(str1, str2); //Phan biet chu hoa/chu thuong
    // strcasecmp(str1, str2);//Khong phan biet
      // str1 = "Hello";
    // str2 = "hello";
    // cout<<strcmp(str1, str2);   //"-1" ... <0
    // + <0 str1 < str2 
    // + =0 str==str2
    // + >0 str1 > str2

