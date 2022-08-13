#include <iostream>
using namespace std;

// 调用子类size, 构造和析构的顺序， 同名父类加作用域（包括静态），静态可以通过对象或类名访问
// 静态成员，类内声明，类外初始化
// 子类出现同名成员函数会隐藏父类所有同名成员函数
// 菱形继承，利用虚继承解决（共享数据）
class Base
{
public:
    int m_A;
    static int m_E;
    Base()
    {
        m_A = 100;
    }
protected:
    int m_B;
private:
    int m_C;

};
int Base::m_E = 100;

class Son:public Base
{
public:
    int m_A;
    Son()
    {
        m_A = 200;
    }
};

void test01()
{
    cout << "size of Son:" << sizeof(Son) << endl;
}

void test02()
{
    Son s;
    cout << s.m_A << endl;
    cout << s.Base::m_A << endl;

    cout << Son::m_E << endl;
    cout << Son::Base::m_E << endl;
}


int main(int argc, char const *argv[])
{
    /* code */
    test01();
    system("pause");
    return 0;
}
