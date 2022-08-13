#include <iostream>
#include <string>
using namespace std;

class Person
{
    friend ostream &operator<<(ostream &cout, Person &p);
    friend void test01();
public:
    Person(int a, int b)
    {
        this->m_A = a;
        this->m_B = b;
    } 

    Person()
    {
        this->m_A = 1;
        this->m_B = 2;
    }

    ~Person()
    {
        cout << "Îö¹¹" <<endl;
    }

private:
    int m_A;
    int m_B;

};

ostream &operator<<(ostream &cout, Person &p)
{
    cout << p.m_A << p.m_B;
    return cout;

}

void test01()
{
    Person p1(1, 2);
    // p1.m_A = 1;
    // p1.m_B = 2;
    cout << p1 << endl;


}


int main(int argc, char const *argv[])
{
    /* code */
    test01();
    system("pause");
    return 0;
}
