#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;
#include <set>



// setԪ���ٲ���ʱ�Զ����򣬵ײ��ɶ�����ʵ��
// set���ɲ���ͬ������multiset����

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

class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }

};

class comparePerson
{
public:
    bool operator()(const Person &p1, const Person &p2)
    {
        return p1.m_Age < p2.m_Age;
    }
};

void printSet(const set<int>&s)
{
    for(set<int>::const_iterator it = s.begin(); it != s.end(); it++)  
    {
        //ֻ���ĵ������� �����޸�
        cout << (*it) << " ";
    }
    cout << endl;
}

void printSet(const set<int, MyCompare>&s)
{
    for(set<int, MyCompare>::const_iterator it = s.begin(); it != s.end(); it++)  
    {
        //ֻ���ĵ������� �����޸�
        cout << (*it) << " ";
    }
    cout << endl;
}

void printSet(const set<Person, comparePerson>&s)
{
    for(set<Person, comparePerson>::const_iterator it = s.begin(); it != s.end(); it++)  
    {
        //ֻ���ĵ������� �����޸�
        cout << (*it).m_Name << it->m_Age <<  " ";
        cout << endl;
    }
    cout << endl;
}



void test01()
{
    // ����
    set<int>s1;

    s1.insert(10);   // ���ﲻ��Ҫ�ṩ������
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);
    s1.insert(50);

    // printSet(s1);

    set<int>s2(s1); //��������
    set<int>s3;
    s3 = s2;
    int m_size = s3.size();
    bool ife = s3.empty();
    s1.swap(s2);  // ����

    // ��ͷβ�壨��������
    s1.erase(s1.begin());
    s1.erase(s1.begin(), s1.end());
    s1.erase(50);  // ����remove
    s1.clear();

    set<int>::iterator it =s2.find(10);  // ���ң����ص�����λ�ã��Ҳ�������end
    int i = s2.count(10);  // ����int ������set���� 0��1

    //���򣨷º����ı������������
    set<int, MyCompare>s4;
    s4.insert(10);   
    s4.insert(20);
    s4.insert(30);
    s4.insert(40);
    s4.insert(50);

    printSet(s4);



}

void test02()
{
    set<int>s;

    pair<set<int>::iterator, bool> ret = s.insert(10);
    if(ret.second)
    {
        cout << "����ɹ�" << endl;
    }
    else
    {
        cout << "����ʧ��" << endl;
    }

    ret = s.insert(10);
    if(ret.second)
    {
        cout << "����ɹ�" << endl;
    }
    else
    {
        cout << "����ʧ��" << endl;
    }

    multiset<int>ms; //�����ظ���������

    // pair ʹ��

    pair<string, int>p("tom", 9);

    cout << p.first << " " << p.second << endl;


}

void test03()
{
    // �����Զ������
    set<Person, comparePerson>s;

    Person p1("a", 10);
    Person p2("b", 11);
    Person p3("c", 12);
    Person p4("d", 13);
    Person p5("e", 14);

    // ֱ�Ӳ岻�У���Ҫ�ṩ�������
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);
    s.insert(p5);

    printSet(s);

}



int main(int argc, char const *argv[])
{
    test03();
    
    system("pause");
    return 0;
}