//��̬����̬�����أ�����׶�     ��̬����������麯�������н׶�
#include <iostream>
using namespace std;

class Animal
{
public:
    //�麯��
    void speak()
    {
        cout << "ooooooo" << endl;
    }
};

class Cat:public Animal
{
public:
    void speak()
    {
        cout << "miao miao miao" <<endl;
    }
};

//��ַ��󶨣�����׶ξ�ȷ����ַ��animal��
//��̬��̬������ 1.�̳й�ϵ  2.������д�������أ������麯��
//��̬��̬ʹ�ã� �����ָ�������ָ���������
void doSpeak(Animal &animal)  //��������ָ��������󣨸�������ת��)
{
    animal.speak();
}

void test01()
{
    Cat cat;
    doSpeak(cat);
    cat.speak();

}

int main(int argc, char const *argv[])
{
    /* code */
    test01();
    system("pause");
    return 0;
}
