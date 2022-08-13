#include <iostream>
using namespace std;
#include <string>

class MyPrint
{
public:
    //overload ()
    void operator()(string test)
    {
        cout << test << endl;
    }


};

void test01()
{
    MyPrint myPrint;
    myPrint("hello world");

    //cout << MyPrint()("hello world!") << endl;  //匿名函数对象,需要重写<<
}

int main(int argc, char const *argv[])
{
    test01();
    system("pause");
    return 0;
}
