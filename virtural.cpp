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
    // virtual ~Animal()  //�������������ָ���ͷ��������ʱ���ɾ�������
    // {
    //     cout << "~ooooo" << endl;
    // }
    virtual void speak() = 0; //���麯��ֻ������
    virtual ~Animal() = 0; //����������Ҫ����Ҳ��Ҫʵ�֣�Ŀ���ǳ�����

};

Animal::~Animal()  // ��������ʵ��
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
