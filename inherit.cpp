#include <iostream>
using namespace std;

// ��������size, �����������˳�� ͬ������������򣨰�����̬������̬����ͨ���������������
// ��̬��Ա�����������������ʼ��
// �������ͬ����Ա���������ظ�������ͬ����Ա����
// ���μ̳У�������̳н�����������ݣ�
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
