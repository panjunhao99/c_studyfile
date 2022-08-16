#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

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


void printVector(vector<int>& v) {

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}


void myPrint(int val)
{
    cout << val << endl;
}

void test02()
{
    vector<vector<int>> v;

    vector<int>v1;
    vector<int>v2;
    vector<int>v3;

    for(int i = 0; i < 3; i++)
    {
        v1.push_back(i+1);
        v2.push_back(i+1);
        v3.push_back(i+1);
    }

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    for(vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        for(vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
        {
            cout << *vit << " ";
        }
        cout << endl;
    }

}

void test01()
{
    vector<int> v;
    v.push_back(10);  //尾插
    v.push_back(9);
    v.push_back(8);
    v.push_back(7);

    vector<int>v3(v.begin(), v.end());

    // vector<int>::iterator itBegin = v.begin();  // 指向第一个元素
    // vector<int>::iterator itEnd = v.end();      // 指向最后的后一个元素

    // while (itBegin != itEnd)
    // {
    //     cout << *itBegin << endl;
    //     itBegin++;
    // }

    // for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    // {
    //     cout << *it << endl;
    // }

    for_each(v.begin(), v.end(), myPrint);

    vector<Person>v2;

    Person p1("a", 10);
    Person p2("b", 11);
    Person p3("c", 12);

    v2.push_back(p1);
    v2.push_back(p2);
    v2.push_back(p3);

    for(vector<Person>::iterator it = v2.begin(); it != v2.end(); it++)
    {
        cout << (*it).m_Name <<" " << it->m_Age << endl;
    }

    
    
}

void test03()
{
    // 赋值
    vector<int> v;
    v.push_back(10);  //尾插
    v.push_back(9);
    v.push_back(8);
    v.push_back(7);

    vector<int>v2;
    // v2 = v;
    v2.assign(v.begin(), v.end());

    bool ifkong = v2.empty();  // 空返回true
    int m_Cap = v2.capacity();
    int m_Size = v2.size();

    cout << m_Cap << m_Size << endl;

    v2.resize(15, 100);   // 用100填充，重新指定大小size
    m_Cap = v2.capacity();
    m_Size = v2.size();

    cout << m_Cap << m_Size << endl;

}

void test04()
{
    // 插入删除
    vector<int> v;
    v.push_back(10);  //尾插
    v.push_back(9);
    v.push_back(8);
    v.push_back(7);

    printVector(v);
    v.pop_back();

    v.insert(v.begin(), 100);  //需要提供一个迭代器进行插入

    v.insert(v.begin(), 2, 100);  //插两个

    printVector(v);

    v.erase(v.begin()); // 可以放区间，但需要是迭代器

    printVector(v);

    v.clear();

    printVector(v);


    // 取值
    cout << v[1] << endl;
    cout << v.at(1) << endl;
    cout << v.front() << endl;     // 第一个
    cout << v.back() << endl;      // 最后一个

}

void test05()
{
    //交换
    vector<int> v1;
    v1.push_back(10);  
    v1.push_back(9);
    v1.push_back(8);
    v1.push_back(7);

    vector<int> v;
    v.push_back(1);  
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    v1.swap(v);
    printVector(v);
    printVector(v1);

    //swap可以收缩空间
    vector<int>(v).swap(v);         //初始化了一个匿名对象，再互换

    v.reserve(1000);  //预留空间，可以减少空间开辟次数


}



int main(int argc, char const *argv[])
{
    // test01();
    test05();
    
    system("pause");
    return 0;
}
