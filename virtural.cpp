#include <iostream>
using namespace std;
#include <string>

class Animal
{
public:
    Animal()
    {
        cout << "ooooo" << endl;
    }
    // virtual ~Animal()  //虚析构解决父类指针释放子类对象时不干净的问题
    // {
    //     cout << "~ooooo" << endl;
    // }
    virtual void speak() = 0; //纯虚函数只需声明
    virtual ~Animal() = 0; //纯虚析构需要声明也需要实现，目的是抽象类

};

Animal::~Animal()  // 纯虚析构实现
{
    cout << "~ooooo" << endl;
}

class Cat:public Animal
{
public:
    Cat(string name)
    {
        m_Name = new string(name);
    }
    virtual void speak()
    {
        cout << *m_Name << "miao" << endl;
    }

    ~Cat()
    {
        if(m_Name != NULL)
        {
            cout << "~miao" << endl;
            delete m_Name;
            m_Name = NULL;
        }
    }

    string *m_Name;
};

void test01()
{
    Animal *animal = new Cat("Tom");
    animal->speak(); 
    delete animal;
}

int main(int argc, char const *argv[])
{
    /* code */
    test01();
    system("pause");
    return 0;
}
