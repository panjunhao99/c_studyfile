#include <iostream>

using namespace std;

class Person
{
public:

    // 传统初始化
    // Person(int a, int b, int c)
    // {
    //     m_A = a;
    //     m_B = b;
    //     m_C = c;
    // }

    Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c) {}



    int m_A;
    int m_B;
    int m_C;


    // 静态变量 类内申明 类外初始化
    static int m_D;

    static void func()
    {
        m_D = 200;
        cout << "func调用" <<endl;
    }


    

};

int Person::m_D = 100;    

void test01()
{
    Person p(10, 20, 30);
    cout << "m_A =" << p.m_A <<endl;
    cout << "m_B =" << p.m_B <<endl;
    cout << "m_C =" << p.m_C <<endl;
    cout << "m_C =" << p.m_D <<endl;

    Person::func();



}

int main()
{
    test01();
    system("pause");
    return 0;
}
