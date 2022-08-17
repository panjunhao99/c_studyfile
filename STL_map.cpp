#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <map>

using namespace std;

// * map������Ԫ�ض���pair
// * pair�е�һ��Ԫ��Ϊkey����ֵ�������������ã��ڶ���Ԫ��Ϊvalue��ʵֵ��
// * ����Ԫ�ض������Ԫ�صļ�ֵ�Զ�����
// **���ʣ�**
// * map/multimap����**����ʽ����**���ײ�ṹ���ö�����ʵ�֡�
// **�ŵ㣺**
// * ���Ը���keyֵ�����ҵ�valueֵ
// map��multimap**����**��
// - map���������������ظ�keyֵԪ��
// - multimap�������������ظ�keyֵԪ��

class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

void printMap(const map<int, int>&m)
{
    for(map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)  
    {
        //ֻ���ĵ������� �����޸�
        cout << (*it).first << " " << it->second << endl;
    }
    cout << endl;
}

void printMap(const map<int, int, MyCompare>&m)
{
    for(map<int, int, MyCompare>::const_iterator it = m.begin(); it != m.end(); it++)  
    {
        //ֻ���ĵ������� �����޸�
        cout << (*it).first << " " << it->second << endl;
    }
    cout << endl;
}

void test01()
{
    // ����
    map<int, int> m;

    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));

    printMap(m);

    map<int, int>m2(m);
    printMap(m2);

    //size empty swap
    m2.insert(make_pair(2, 20));
    m2.insert(map<int, int>::value_type(3, 30));
    m2[4] = 30;  // ������
    m2.erase(1);  // ɾ����Ӧkey
    m2.erase(m2.begin(), m2.end());

    map<int, int>::iterator it = m2.find(3);
    int num = m2.count(3);

    map<int, int, MyCompare>m3;   // ����map�º������������ͣ�ģ���ڣ�����find_if�ﴫ���Ƕ���
    m3.insert(pair<int, int>(1, 10));
    m3.insert(pair<int, int>(2, 20));
    m3.insert(pair<int, int>(3, 30));
    printMap(m3);

   


    




}



int main(int argc, char const *argv[])
{
    test01();
    
    system("pause");
    return 0;
}