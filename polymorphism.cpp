//多态：静态（重载）编译阶段     动态（派生类和虚函数）运行阶段
#include <iostream>
using namespace std;

class Animal
{
public:
    //虚函数
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

//地址早绑定，编译阶段就确定地址（animal）
//动态多态条件： 1.继承关系  2.子类重写（非重载）父类虚函数
//动态多态使用： 父类的指针或引用指向子类对象
void doSpeak(Animal &animal)  //父类引用指向子类对象（父子类型转换)
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
