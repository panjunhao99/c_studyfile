#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

// 内部使用中控器实现，可以快速访问头部，但总的访问速度小于vector

void printDeque(const deque<int>&d)
{
    for(deque<int>::const_iterator it = d.begin(); it != d.end(); it++)  
    {
        //只读的迭代器， 不可修改
        cout << (*it) << " ";
    }
    cout << endl;
}

void test01()
{
    // 构造
    deque<int>dl;
    for(int i = 0; i < 10; i++)
    {
        dl.push_back(i);
    }
    printDeque(dl);

    deque<int>d2(dl.begin(), dl.end());

    // 赋值
    // d2 = dl;
    d2.assign(dl.begin(), dl.end());

    bool ife = d2.empty();
    int m_Size = d2.size();
    d2.resize(15,1);
    d2.resize(3);

    //deque没有容量的概念



}
void test02()
{
    // 插入删除
    deque<int> d1;

    d1.push_back(1);       //尾插
    d1.push_front(2);      //头插
    d1.pop_back();
    d1.pop_front();

    d1.insert(d1.begin(), 2, 9);

    //区间插入
    deque<int>d2(d1);
    d2.insert(d2.begin(), d1.begin(), d1.end());
    d2.erase(d2.begin()+1);



    printDeque(d2);
}

void test03()
{
    // 排序
    deque<int> d1;

    d1.push_back(1);       //尾插
    d1.push_front(2);      //头插
    d1.push_back(4);
    d1.push_back(3);
    d1.push_back(9);
    printDeque(d1);

    sort(d1.begin(), d1.end());   //默认升序

    printDeque(d1);






}


int main(int argc, char const *argv[])
{
    test03();
    
    system("pause");
    return 0;
}