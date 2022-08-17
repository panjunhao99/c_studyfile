#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <functional>
#include <numeric>
using namespace std;

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    bool operator==(const Person & p)
    {
        if(this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    string m_Name;
    int m_Age;
};

//��ͨ����
void print01(int val)
{
    cout << val << " ";
}

//�º���
class print02
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

class Transform
{
public:
    int operator()(int val)
    {
        return val + 100;
    }
};

void test01()
{
    //for_each ����
    vector<int>v;
    for(int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), print01);
    for_each(v.begin(), v.end(), print02());   //�º���������Ǻ�������
    cout << endl;
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

}

void test02()
{
    //transform ����
    vector<int>v;
    for(int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int>vTarget;   //Ŀ��������Ҫ��ǰ���ٿռ�
    vTarget.resize(v.size());  
    transform(v.begin(), v.end(), vTarget.begin(), Transform());   //���˹����п��Զ����ݽ��д���
    for_each(vTarget.begin(), vTarget.end(), print02()); 


}

class GreatFive
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};

class Great5
{
public:


    bool operator()(Person & p)
    {
        return p.m_Age > 5;
    }

};



void test03()
{
    //find
    vector<int>v;
    for(int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int>::iterator it = find(v.begin(), v.end(), 5);

    //�Զ������ͣ�find��Ҫ����==��
    vector<Person>v2;

    Person p1("a", 10);
    Person p2("b", 11);
    Person p3("c", 12);

    v2.push_back(p1);
    v2.push_back(p2);
    v2.push_back(p3);
    vector<Person>::iterator it2 = find(v2.begin(), v2.end(), p2);
    // if(it2 != v2.end())
    // {
    //     cout << "�ҵ���" << it2->m_Name << it2->m_Age << " ";
    // }

    //find_if
    vector<int>::iterator it3 = find_if(v.begin(), v.end(), GreatFive());  //ֻ�ҵ���һ��
    cout << *it3 << endl;
    vector<Person>::iterator it4 = find_if(v2.begin(), v2.end(), Great5());

    // if(it4 != v2.end())
    // {
    //     cout << "�ҵ���" << it4->m_Name << it4->m_Age << " ";
    // }

    //adjacent_find�����ظ�Ԫ�ز���
    vector<int>::iterator it5 = adjacent_find(v.begin(), v.end());
    //bool binary_search(iterator beg, iterator end, value); 
    // ����ָ����Ԫ�أ��鵽 ����true  ����false
    // ע��: �����������в�����
    //���ֲ���
	bool ret = binary_search(v.begin(), v.end(),2);

    // count(iterator beg, iterator end, value);
    // ͳ��Ԫ�س��ִ���
    int num = count(v.begin(), v.end(), 4);
    int num2 = count(v2.begin(), v2.end(), p2);   //����д==
    cout << num2 << endl;

    //count_if ͬ��find_if
    


    
}

void myPrint(int val)
{
	cout << val << " ";
}

class myPrint2
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};


void test04()
{
    //��������
    // sort(iterator beg, iterator end, _Pred);
    // ��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
    vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	//sortĬ�ϴ�С��������
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

	//�Ӵ�С����
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

    // random_shuffle(iterator beg, iterator end); 
    // ָ����Χ�ڵ�Ԫ�������������
    srand((unsigned int)time(NULL));
	vector<int> v2;
	for(int i = 0 ; i < 10;i++)
	{
		v2.push_back(i);
	}
	for_each(v2.begin(), v2.end(), myPrint2());
	cout << endl;

	//����˳��
	// random_shuffle(v2.begin(), v2.end());
	for_each(v2.begin(), v2.end(), myPrint2());
	cout << endl;

    // merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
    // ����Ԫ�غϲ������洢����һ������
    // ע��: ��������������**�����**
    vector<int> vtarget;
	//Ŀ��������Ҫ��ǰ���ٿռ�
	vtarget.resize(v.size() + v2.size());
	//�ϲ�  ��Ҫ������������
	merge(v.begin(), v.end(), v2.begin(), v2.end(), vtarget.begin());
	for_each(vtarget.begin(), vtarget.end(), myPrint);
	cout << endl;

    //reverse(iterator beg, iterator end); 
    // ��תָ����Χ��Ԫ��
    cout << "��תǰ�� " << endl;
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

	cout << "��ת�� " << endl;

	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;


}

class ReplaceGreater5
{
public:
	bool operator()(int val)
	{
		return val >= 5;
	}

};

void test05()
{
    //���ÿ����滻
    // copy(iterator beg, iterator end, iterator dest);
    // ��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
    vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i + 1);
	}
	vector<int> v2;
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());

	for_each(v2.begin(), v2.end(), myPrint);
	cout << endl;


    //replace(iterator beg, iterator end, oldvalue, newvalue); 
    // �������ھ�Ԫ�� �滻�� ��Ԫ��
    replace(v1.begin(), v1.end(), 2,2000);    // 2�滻Ϊ2000
	for_each(v1.begin(), v1.end(), myPrint);
	cout << endl;

    // replace_if(iterator beg, iterator end, _pred, newvalue);
    // �������滻Ԫ�أ������������滻��ָ��Ԫ��
    replace_if(v1.begin(), v1.end(), ReplaceGreater5(), 3000);   // �����д���5���滻��3000
	for_each(v1.begin(), v1.end(), myPrint);
	cout << endl;

    // swap(container c1, container c2);  
    // ��������������Ԫ��

}

void test06()
{
    // #include <numeric>���õ����������㷨
    // accumulate(iterator beg, iterator end, value);
    // ��������Ԫ���ۼ��ܺ�
    vector<int> v;
	for (int i = 0; i <= 100; i++) {
		v.push_back(i);
	}

	int total = accumulate(v.begin(), v.end(), 0);   // sum+0

	cout << "total = " << total << endl;

    // fill(iterator beg, iterator end, value);
    // �����������Ԫ��
    vector<int> v2;
	v2.resize(10);
	//���
	fill(v2.begin(), v2.end(), 100);

	for_each(v2.begin(), v2.end(), myPrint);
	cout << endl;  

}

void test07()
{
    //���ճ��õļ����㷨
    // set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
    // ���������ϵĽ���
    // **ע��:�������ϱ�������������**
    vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
    {
		v1.push_back(i);
		v2.push_back(i+5);
	}

	vector<int> vTarget;
	//ȡ���������С��ֵ��Ŀ���������ٿռ�
	vTarget.resize(min(v1.size(), v2.size()));

	//����Ŀ�����������һ��Ԫ�صĵ�������ַ
	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for_each(vTarget.begin(), itEnd, myPrint);
	cout << endl;

    //set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest); 
    // ���������ϵĲ���
    //set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
    // ���������ϵĲ

}

int main(int argc, char const *argv[])
{
    test07();
    system("pause");
    return 0;
}
