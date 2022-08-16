#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};


void printVector(vector<int>& v) {

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}


void myPrint(int val)
{
    cout << val << endl;
}

void test02()
{
    vector<vector<int>> v;

    vector<int>v1;
    vector<int>v2;
    vector<int>v3;

    for(int i = 0; i < 3; i++)
    {
        v1.push_back(i+1);
        v2.push_back(i+1);
        v3.push_back(i+1);
    }

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    for(vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        for(vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
        {
            cout << *vit << " ";
        }
        cout << endl;
    }

}

void test01()
{
    vector<int> v;
    v.push_back(10);  //β��
    v.push_back(9);
    v.push_back(8);
    v.push_back(7);

    vector<int>v3(v.begin(), v.end());

    // vector<int>::iterator itBegin = v.begin();  // ָ���һ��Ԫ��
    // vector<int>::iterator itEnd = v.end();      // ָ�����ĺ�һ��Ԫ��

    // while (itBegin != itEnd)
    // {
    //     cout << *itBegin << endl;
    //     itBegin++;
    // }

    // for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    // {
    //     cout << *it << endl;
    // }

    for_each(v.begin(), v.end(), myPrint);

    vector<Person>v2;

    Person p1("a", 10);
    Person p2("b", 11);
    Person p3("c", 12);

    v2.push_back(p1);
    v2.push_back(p2);
    v2.push_back(p3);

    for(vector<Person>::iterator it = v2.begin(); it != v2.end(); it++)
    {
        cout << (*it).m_Name <<" " << it->m_Age << endl;
    }

    
    
}

void test03()
{
    // ��ֵ
    vector<int> v;
    v.push_back(10);  //β��
    v.push_back(9);
    v.push_back(8);
    v.push_back(7);

    vector<int>v2;
    // v2 = v;
    v2.assign(v.begin(), v.end());

    bool ifkong = v2.empty();  // �շ���true
    int m_Cap = v2.capacity();
    int m_Size = v2.size();

    cout << m_Cap << m_Size << endl;

    v2.resize(15, 100);   // ��100��䣬����ָ����Сsize
    m_Cap = v2.capacity();
    m_Size = v2.size();

    cout << m_Cap << m_Size << endl;

}

void test04()
{
    // ����ɾ��
    vector<int> v;
    v.push_back(10);  //β��
    v.push_back(9);
    v.push_back(8);
    v.push_back(7);

    printVector(v);
    v.pop_back();

    v.insert(v.begin(), 100);  //��Ҫ�ṩһ�����������в���

    v.insert(v.begin(), 2, 100);  //������

    printVector(v);

    v.erase(v.begin()); // ���Է����䣬����Ҫ�ǵ�����

    printVector(v);

    v.clear();

    printVector(v);


    // ȡֵ
    cout << v[1] << endl;
    cout << v.at(1) << endl;
    cout << v.front() << endl;     // ��һ��
    cout << v.back() << endl;      // ���һ��

}

void test05()
{
    //����
    vector<int> v1;
    v1.push_back(10);  
    v1.push_back(9);
    v1.push_back(8);
    v1.push_back(7);

    vector<int> v;
    v.push_back(1);  
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    v1.swap(v);
    printVector(v);
    printVector(v1);

    //swap���������ռ�
    vector<int>(v).swap(v);         //��ʼ����һ�����������ٻ���

    v.reserve(1000);  //Ԥ���ռ䣬���Լ��ٿռ俪�ٴ���


}



int main(int argc, char const *argv[])
{
    // test01();
    test05();
    
    system("pause");
    return 0;
}
