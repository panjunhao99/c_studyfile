#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <map>
#include <ctime>

using namespace std;

// * 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
// * 员工信息有: 姓名  工资组成；部门分为：策划、美术、研发
// * 随机给10名员工分配部门和工资
// * 通过multimap进行信息的插入  key(部门编号) value(员工)
// * 分部门显示员工信息
#define CEHUA 0
#define MEISHU 0
#define YANFA 0

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

class Worker
{
public:
    string m_Name;
    int m_Salary;
};

void printVector(vector<Worker>& v) {

	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {
		cout << it->m_Name << " " << it->m_Salary << endl;
	}
	cout << endl;
}

void printMap(const multimap<int, Worker>&m)
{
    for(multimap<int, Worker>::const_iterator it = m.begin(); it != m.end(); it++)  
    {
        //只读的迭代器， 不可修改
        cout << (*it).first << " " << it->second.m_Name << it->second.m_Salary << endl;
    }
    cout << endl;
}

void createWorker(vector<Worker>&v)
{
    string nameSeed = "ABCDEFGHIJ";
    for(int i = 0; i < 10; i++)
    {
        Worker worker;
        worker.m_Name = "员工";
        worker.m_Name += nameSeed[i];

        worker.m_Salary = rand() % 10000 + 10000;

        v.push_back(worker);

    }

}

void setGroup(vector<Worker>&v, multimap<int,Worker>&m)
{
    for(vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        int deptId = rand() % 3;
        m.insert(make_pair(deptId, *it));
    }
}

void showWorkerGroup(multimap<int, Worker>&m)
{
    cout << "策划" << endl;
    multimap<int, Worker>::iterator pos = m.find(CEHUA);  // 这里返回一个位置，因为map内是排序好的，所以按位置数量取后面几个
    int count = m.count(CEHUA);
    int index = 0;
    for(; pos != m.end() && index < count; pos++, index++)
    {
        cout << pos->second.m_Name << " " << pos->second.m_Salary << endl;
    }

    cout << "美术" << endl;
    pos = m.find(MEISHU);
    count = m.count(MEISHU);
    index = 0;
    for(; pos != m.end()&& index < count; pos++, index++)
    {
        cout << pos->second.m_Name << " " << pos->second.m_Salary << endl;
    }

    cout << "研发" << endl;
    multimap<int, Worker>::iterator pos3 = m.find(YANFA);
    int count3 = m.count(YANFA);
    int index3 = 0;
    for(; pos3 != m.end()&& index3 < count3; pos3++, index3++)
    {
        cout << pos3->second.m_Name << " " << pos3->second.m_Salary << endl;
    }

}




int main(int argc, char const *argv[])
{
    // * 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
    // * 员工信息有: 姓名  工资组成；部门分为：策划、美术、研发
    // * 随机给10名员工分配部门和工资
    // * 通过multimap进行信息的插入  key(部门编号) value(员工)
    // * 分部门显示员工信息

    // 创建员工
    vector<Worker>vWorker;
    createWorker(vWorker);
    // printVector(vWorker);

    // 分组
    multimap<int, Worker>mWorker;
    setGroup(vWorker, mWorker);

    // printMap(mWorker);

    showWorkerGroup(mWorker);






    
    system("pause");
    return 0;
}