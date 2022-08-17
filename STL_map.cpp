#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <map>

using namespace std;

// * map中所有元素都是pair
// * pair中第一个元素为key（键值），起到索引作用，第二个元素为value（实值）
// * 所有元素都会根据元素的键值自动排序
// **本质：**
// * map/multimap属于**关联式容器**，底层结构是用二叉树实现。
// **优点：**
// * 可以根据key值快速找到value值
// map和multimap**区别**：
// - map不允许容器中有重复key值元素
// - multimap允许容器中有重复key值元素

class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

void printMap(const map<int, int>&m)
{
    for(map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)  
    {
        //只读的迭代器， 不可修改
        cout << (*it).first << " " << it->second << endl;
    }
    cout << endl;
}

void printMap(const map<int, int, MyCompare>&m)
{
    for(map<int, int, MyCompare>::const_iterator it = m.begin(); it != m.end(); it++)  
    {
        //只读的迭代器， 不可修改
        cout << (*it).first << " " << it->second << endl;
    }
    cout << endl;
}

void test01()
{
    // 构造
    map<int, int> m;

    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));

    printMap(m);

    map<int, int>m2(m);
    printMap(m2);

    //size empty swap
    m2.insert(make_pair(2, 20));
    m2.insert(map<int, int>::value_type(3, 30));
    m2[4] = 30;  // 不建议
    m2.erase(1);  // 删除对应key
    m2.erase(m2.begin(), m2.end());

    map<int, int>::iterator it = m2.find(3);
    int num = m2.count(3);

    map<int, int, MyCompare>m3;   // 这里map仿函数传的是类型（模板内），而find_if里传的是对象
    m3.insert(pair<int, int>(1, 10));
    m3.insert(pair<int, int>(2, 20));
    m3.insert(pair<int, int>(3, 30));
    printMap(m3);

   


    




}



int main(int argc, char const *argv[])
{
    test01();
    
    system("pause");
    return 0;
}