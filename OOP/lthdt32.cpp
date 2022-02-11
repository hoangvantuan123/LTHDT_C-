//De:32
/*
Bài 32(lthdtbai32.cpp): Cho tệp văn bản chứa dãy số nguyên "lthdtbai32-daysonguyen.txt",
trên tệp không có thông tin về số phần tử của dãy số. Đọc dãy số từ tệp văn bản,
lưu dãy số trong danh sách liên kết đơn theo đúng thứ tự trên tệp. Đưa dãy số trong DSLKD ra màn hình.
Tìm xem trong dãy số có phần tử nào bằng x không. Xóa một phần tử có giá trị bằng x.
*/

#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop DSLKD
class SList
{
    private:
        struct node
        {
            int infor;
            node *link;
        } *F;

    public:
        SList();
        ~SList();
        void lastInsert(int x);
        void display();
        bool find(int x);
        void remove(int x);
};


//===chuong trinh chinh===
int main()
{

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
