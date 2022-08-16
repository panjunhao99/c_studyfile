#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

// �ڲ�ʹ���п���ʵ�֣����Կ��ٷ���ͷ�������ܵķ����ٶ�С��vector

void printDeque(const deque<int>&d)
{
    for(deque<int>::const_iterator it = d.begin(); it != d.end(); it++)  
    {
        //ֻ���ĵ������� �����޸�
        cout << (*it) << " ";
    }
    cout << endl;
}

void test01()
{
    // ����
    deque<int>dl;
    for(int i = 0; i < 10; i++)
    {
        dl.push_back(i);
    }
    printDeque(dl);

    deque<int>d2(dl.begin(), dl.end());

    // ��ֵ
    // d2 = dl;
    d2.assign(dl.begin(), dl.end());

    bool ife = d2.empty();
    int m_Size = d2.size();
    d2.resize(15,1);
    d2.resize(3);

    //dequeû�������ĸ���



}
void test02()
{
    // ����ɾ��
    deque<int> d1;

    d1.push_back(1);       //β��
    d1.push_front(2);      //ͷ��
    d1.pop_back();
    d1.pop_front();

    d1.insert(d1.begin(), 2, 9);

    //�������
    deque<int>d2(d1);
    d2.insert(d2.begin(), d1.begin(), d1.end());
    d2.erase(d2.begin()+1);



    printDeque(d2);
}

void test03()
{
    // ����
    deque<int> d1;

    d1.push_back(1);       //β��
    d1.push_front(2);      //ͷ��
    d1.push_back(4);
    d1.push_back(3);
    d1.push_back(9);
    printDeque(d1);

    sort(d1.begin(), d1.end());   //Ĭ������

    printDeque(d1);






}


int main(int argc, char const *argv[])
{
    test03();
    
    system("pause");
    return 0;
}