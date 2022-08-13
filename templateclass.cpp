#include <iostream>
#include <string>

using namespace std;

template<class T1, class T2>
class Person;                    // ��ǰ�ñ�����֪����

//����ʵ��
template<class T1, class T2>
void printPerson2(Person<T1,T2> p)
{
    cout << p.m_Name << p.m_Age << endl;
}


template<class T1, class T2>
class Person
{
    friend void printPerson2<>(Person<T1,T2> p);
    //ȫ�ֺ���������ʵ��
    friend void printPerson(Person<T1,T2> p)
    {
        cout << p.m_Name << p.m_Age << endl;
    }
public:
    Person(T1 name, T2 age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
private:
    T1 m_Name;
    T2 m_Age;
};



void test01()
{
    Person<string, int>p("tom", 18);
    printPerson(p);
    printPerson2(p);
}

int main(int argc, char const *argv[])
{
    /* code */
    test01();
    system("pause");
    return 0;
}
