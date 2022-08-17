#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <functional>
#include <numeric>
using namespace std;

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    bool operator==(const Person & p)
    {
        if(this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    string m_Name;
    int m_Age;
};

//普通函数
void print01(int val)
{
    cout << val << " ";
}

//仿函数
class print02
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

class Transform
{
public:
    int operator()(int val)
    {
        return val + 100;
    }
};

void test01()
{
    //for_each 遍历
    vector<int>v;
    for(int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), print01);
    for_each(v.begin(), v.end(), print02());   //仿函数放入的是函数对象
    cout << endl;
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

}

void test02()
{
    //transform 遍历
    vector<int>v;
    for(int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int>vTarget;   //目标容器需要提前开辟空间
    vTarget.resize(v.size());  
    transform(v.begin(), v.end(), vTarget.begin(), Transform());   //搬运过程中可以对数据进行处理
    for_each(vTarget.begin(), vTarget.end(), print02()); 


}

class GreatFive
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};

class Great5
{
public:


    bool operator()(Person & p)
    {
        return p.m_Age > 5;
    }

};



void test03()
{
    //find
    vector<int>v;
    for(int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int>::iterator it = find(v.begin(), v.end(), 5);

    //自定义类型，find需要重载==号
    vector<Person>v2;

    Person p1("a", 10);
    Person p2("b", 11);
    Person p3("c", 12);

    v2.push_back(p1);
    v2.push_back(p2);
    v2.push_back(p3);
    vector<Person>::iterator it2 = find(v2.begin(), v2.end(), p2);
    // if(it2 != v2.end())
    // {
    //     cout << "找到了" << it2->m_Name << it2->m_Age << " ";
    // }

    //find_if
    vector<int>::iterator it3 = find_if(v.begin(), v.end(), GreatFive());  //只找到第一个
    cout << *it3 << endl;
    vector<Person>::iterator it4 = find_if(v2.begin(), v2.end(), Great5());

    // if(it4 != v2.end())
    // {
    //     cout << "找到了" << it4->m_Name << it4->m_Age << " ";
    // }

    //adjacent_find相邻重复元素查找
    vector<int>::iterator it5 = adjacent_find(v.begin(), v.end());
    //bool binary_search(iterator beg, iterator end, value); 
    // 查找指定的元素，查到 返回true  否则false
    // 注意: 在无序序列中不可用
    //二分查找
	bool ret = binary_search(v.begin(), v.end(),2);

    // count(iterator beg, iterator end, value);
    // 统计元素出现次数
    int num = count(v.begin(), v.end(), 4);
    int num2 = count(v2.begin(), v2.end(), p2);   //需重写==
    cout << num2 << endl;

    //count_if 同理find_if
    


    
}

void myPrint(int val)
{
	cout << val << " ";
}

class myPrint2
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};


void test04()
{
    //常用排序
    // sort(iterator beg, iterator end, _Pred);
    // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
    vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	//sort默认从小到大排序
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

	//从大到小排序
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

    // random_shuffle(iterator beg, iterator end); 
    // 指定范围内的元素随机调整次序
    srand((unsigned int)time(NULL));
	vector<int> v2;
	for(int i = 0 ; i < 10;i++)
	{
		v2.push_back(i);
	}
	for_each(v2.begin(), v2.end(), myPrint2());
	cout << endl;

	//打乱顺序
	// random_shuffle(v2.begin(), v2.end());
	for_each(v2.begin(), v2.end(), myPrint2());
	cout << endl;

    // merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
    // 容器元素合并，并存储到另一容器中
    // 注意: 两个容器必须是**有序的**
    vector<int> vtarget;
	//目标容器需要提前开辟空间
	vtarget.resize(v.size() + v2.size());
	//合并  需要两个有序序列
	merge(v.begin(), v.end(), v2.begin(), v2.end(), vtarget.begin());
	for_each(vtarget.begin(), vtarget.end(), myPrint);
	cout << endl;

    //reverse(iterator beg, iterator end); 
    // 反转指定范围的元素
    cout << "反转前： " << endl;
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

	cout << "反转后： " << endl;

	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;


}

class ReplaceGreater5
{
public:
	bool operator()(int val)
	{
		return val >= 5;
	}

};

void test05()
{
    //常用拷贝替换
    // copy(iterator beg, iterator end, iterator dest);
    // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
    vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i + 1);
	}
	vector<int> v2;
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());

	for_each(v2.begin(), v2.end(), myPrint);
	cout << endl;


    //replace(iterator beg, iterator end, oldvalue, newvalue); 
    // 将区间内旧元素 替换成 新元素
    replace(v1.begin(), v1.end(), 2,2000);    // 2替换为2000
	for_each(v1.begin(), v1.end(), myPrint);
	cout << endl;

    // replace_if(iterator beg, iterator end, _pred, newvalue);
    // 按条件替换元素，满足条件的替换成指定元素
    replace_if(v1.begin(), v1.end(), ReplaceGreater5(), 3000);   // 容器中大于5的替换成3000
	for_each(v1.begin(), v1.end(), myPrint);
	cout << endl;

    // swap(container c1, container c2);  
    // 互换两个容器的元素

}

void test06()
{
    // #include <numeric>常用的算术生成算法
    // accumulate(iterator beg, iterator end, value);
    // 计算容器元素累计总和
    vector<int> v;
	for (int i = 0; i <= 100; i++) {
		v.push_back(i);
	}

	int total = accumulate(v.begin(), v.end(), 0);   // sum+0

	cout << "total = " << total << endl;

    // fill(iterator beg, iterator end, value);
    // 向容器中填充元素
    vector<int> v2;
	v2.resize(10);
	//填充
	fill(v2.begin(), v2.end(), 100);

	for_each(v2.begin(), v2.end(), myPrint);
	cout << endl;  

}

void test07()
{
    //掌握常用的集合算法
    // set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
    // 求两个集合的交集
    // **注意:两个集合必须是有序序列**
    vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
    {
		v1.push_back(i);
		v2.push_back(i+5);
	}

	vector<int> vTarget;
	//取两个里面较小的值给目标容器开辟空间
	vTarget.resize(min(v1.size(), v2.size()));

	//返回目标容器的最后一个元素的迭代器地址
	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for_each(vTarget.begin(), itEnd, myPrint);
	cout << endl;

    //set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest); 
    // 求两个集合的并集
    //set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
    // 求两个集合的差集

}

int main(int argc, char const *argv[])
{
    test07();
    system("pause");
    return 0;
}
