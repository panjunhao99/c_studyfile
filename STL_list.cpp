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
    Person(string name, int age, int height)
    {
        this->m_Name = name;
        this->m_Age = age;
        this->m_Height = height;
    }

    string m_Name;
    int m_Age;
    int m_Height;
};


void printList(const list<int>&L)
{
    for(list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void printList(const list<Person>&L)
{
    for(list<Person>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << (*it).m_Name << " " << it->m_Age << " " << it-> m_Height;
        cout << endl;
    }
    cout << endl;
}

bool myCompare(int a, int b)
{
    //降序 a>b
    return a > b;
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

    //反转
    L1.reverse();
    printList(L1);
    //排序 所有不支持随机访问迭代器的容器，不可用标准算法
    // sort(L1.begin(), L1.end());
    L1.sort();  //可以用内部的成员函数，默认升序
    printList(L1);
    L1.sort(myCompare); //仿函数，降序
    printList(L1);

}

bool comparePerson(const Person &p1, const Person &p2)
{   
    //按年龄升序
    if(p1.m_Age == p2.m_Age)
    {
        //年龄相同时，按身高升序排列
        return p1.m_Height < p2.m_Height;
    }
    else
    {
        return p1.m_Age < p2.m_Age;
    }

}

void test02()
{
    list<Person>L;

    Person p1("a", 35, 175);
    Person p2("b", 35, 176);
    Person p3("c", 19, 180);
    Person p4("d", 23, 178);
    Person p5("e", 5, 50);

    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);

    printList(L);

    //排序
    cout << "----------排序后-----------" << endl;
    L.sort(comparePerson);
    printList(L);





}



int main(int argc, char const *argv[])
{
    test02();
    
    system("pause");
    return 0;
}