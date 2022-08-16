#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <stack>
#include <queue>
#include <list>

using namespace std;

// 链表

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

void printList(const list<int>&L)
{
    for(list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}


void test01()
{
    // 构造
    list<int>L1;
    L1.push_back(1);
    L1.push_back(2);
    L1.push_back(3);
    L1.push_back(4);
    L1.push_back(5);

    printList(L1);

    list<int>L2;
    L2 = L1;
    list<int>L3;
    L3.assign(L2.begin(), L2.end());

    L1.insert(L1.begin(), 100);
    L1.remove(100);  // remove删除所有匹配值
    list<int>::iterator it = L1.begin();
    L1.erase(++it);

    printList(L1);

    //数据访问，不支持随机访问，不可以用[]和at访问
    it++;    //支持
    cout << L1.front() << L1.back() << endl;





    


}



int main(int argc, char const *argv[])
{
    test01();
    
    system("pause");
    return 0;
}