#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <map>
#include <ctime>

using namespace std;

// * ��˾������Ƹ��10��Ա����ABCDEFGHIJ����10��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
// * Ա����Ϣ��: ����  ������ɣ����ŷ�Ϊ���߻����������з�
// * �����10��Ա�����䲿�ź͹���
// * ͨ��multimap������Ϣ�Ĳ���  key(���ű��) value(Ա��)
// * �ֲ�����ʾԱ����Ϣ
#define CEHUA 0
#define MEISHU 0
#define YANFA 0

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

class Worker
{
public:
    string m_Name;
    int m_Salary;
};

void printVector(vector<Worker>& v) {

	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {
		cout << it->m_Name << " " << it->m_Salary << endl;
	}
	cout << endl;
}

void printMap(const multimap<int, Worker>&m)
{
    for(multimap<int, Worker>::const_iterator it = m.begin(); it != m.end(); it++)  
    {
        //ֻ���ĵ������� �����޸�
        cout << (*it).first << " " << it->second.m_Name << it->second.m_Salary << endl;
    }
    cout << endl;
}

void createWorker(vector<Worker>&v)
{
    string nameSeed = "ABCDEFGHIJ";
    for(int i = 0; i < 10; i++)
    {
        Worker worker;
        worker.m_Name = "Ա��";
        worker.m_Name += nameSeed[i];

        worker.m_Salary = rand() % 10000 + 10000;

        v.push_back(worker);

    }

}

void setGroup(vector<Worker>&v, multimap<int,Worker>&m)
{
    for(vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        int deptId = rand() % 3;
        m.insert(make_pair(deptId, *it));
    }
}

void showWorkerGroup(multimap<int, Worker>&m)
{
    cout << "�߻�" << endl;
    multimap<int, Worker>::iterator pos = m.find(CEHUA);  // ���ﷵ��һ��λ�ã���Ϊmap��������õģ����԰�λ������ȡ���漸��
    int count = m.count(CEHUA);
    int index = 0;
    for(; pos != m.end() && index < count; pos++, index++)
    {
        cout << pos->second.m_Name << " " << pos->second.m_Salary << endl;
    }

    cout << "����" << endl;
    pos = m.find(MEISHU);
    count = m.count(MEISHU);
    index = 0;
    for(; pos != m.end()&& index < count; pos++, index++)
    {
        cout << pos->second.m_Name << " " << pos->second.m_Salary << endl;
    }

    cout << "�з�" << endl;
    multimap<int, Worker>::iterator pos3 = m.find(YANFA);
    int count3 = m.count(YANFA);
    int index3 = 0;
    for(; pos3 != m.end()&& index3 < count3; pos3++, index3++)
    {
        cout << pos3->second.m_Name << " " << pos3->second.m_Salary << endl;
    }

}




int main(int argc, char const *argv[])
{
    // * ��˾������Ƹ��10��Ա����ABCDEFGHIJ����10��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
    // * Ա����Ϣ��: ����  ������ɣ����ŷ�Ϊ���߻����������з�
    // * �����10��Ա�����䲿�ź͹���
    // * ͨ��multimap������Ϣ�Ĳ���  key(���ű��) value(Ա��)
    // * �ֲ�����ʾԱ����Ϣ

    // ����Ա��
    vector<Worker>vWorker;
    createWorker(vWorker);
    // printVector(vWorker);

    // ����
    multimap<int, Worker>mWorker;
    setGroup(vWorker, mWorker);

    // printMap(mWorker);

    showWorkerGroup(mWorker);






    
    system("pause");
    return 0;
}