#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <stack>
#include <queue>

using namespace std;

// stack特点后进先出
// queue特点先进先出

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


void test01()
{
    // 构造
    stack<int>s;
    s.push(10);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.pop();
    int a = s.top();

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    cout << s.size() << endl;
    
    queue<Person>q;

    Person p1("tom", 12);
    Person p2("tom1", 13);
    Person p3("tom2", 14);

    q.push(p1);
    q.push(p2);
    q.push(p3);

    while (!q.empty())
    {
        cout << q.front().m_Name << q.back().m_Name << endl;
        q.pop();
    }

    cout << q.size() << endl;
    






}



int main(int argc, char const *argv[])
{
    test01();
    
    system("pause");
    return 0;
}