#include <iostream>
using namespace std;
#include <string>
#include "speechManager.h"
#include <functional>
#include <numeric>
#include <algorithm>
#include <deque>


SpeechManager::SpeechManager()
{
    //��ʼ��
    SpeechManager::initSpeech();
    SpeechManager::createSpeaker();
}

void SpeechManager::show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void SpeechManager::exitsystem()
{
    cout << "��ӭ�´�ʹ��" << endl;
    system("pause");
    exit(0);
}

void SpeechManager::initSpeech()
{
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_Speaker.clear();
    this->m_index = 1;
    this->m_Record.clear();

}

void SpeechManager::createSpeaker()
{
    string nameseed = "ABCDEFGHIJKL";
    for(int i = 0; i < nameseed.size(); i++)
    {
        string name = "ѡ��";
        name += nameseed[i];

        Speaker sp;
        sp.m_Name = name;

        for(int j = 0; j < 2; j++)
        {
            sp.m_Score[j] = 0;
        }

        this->v1.push_back(i + 10001);

        this->m_Speaker.insert(make_pair(i + 10001, sp));

    }
}

void SpeechManager::printSpeaker(const map<int, Speaker>&m)
{
    for(map<int, Speaker>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "ѡ�ֱ��:" << it->first
             << "����:" << it->second.m_Name
             << "����:" << it->second.m_Score[0] << endl;
    }
    cout << endl;

}

void SpeechManager::speechDraw()
{
    cout << "�� << " << this->m_index << " >> �ֱ���ѡ�����ڳ�ǩ"<<endl;
	cout << "---------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;

    if(this->m_index == 1)
    {
        random_shuffle(v1.begin(), v1.end());
        for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
    }
    else
    {
        random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
    }
    cout << "---------------------" << endl;
	system("pause");
	cout << endl;

}

void SpeechManager::speechContest()
{
    cout << "------------- ��"<< this->m_index << "����ʽ������ʼ��------------- " << endl;

    //��ʱ�������С�����
    multimap<double, int, greater<int>> groupScore;

    int num = 0;
    
    vector<int>v_Src;
    if(this->m_index == 1)
    {
        v_Src = v1;
    }
    else
    {
        v_Src = v2;
    }
    //��������ѡ�ֽ��б���
    for(vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
    {
        num++;
        //���
        deque<double> d;
        for(int i = 0; i < 10; i++)
        {
            double score = rand()%401 + 600 / 10.f;
            // cout << score << " ";
            d.push_back(score);
        }

        sort(d.begin(), d.end(), greater<double>());
        d.pop_front();
        d.pop_back();

        double sum = accumulate(d.begin(), d.end(), 0);
        double avg = sum / (double)d.size();

        //ƽ���ַ���map
        this->m_Speaker[*it].m_Score[this->m_index - 1] = avg;

        groupScore.insert(make_pair(avg, *it));

        if(num % 6 == 0)
        {
            cout << "��" << num / 6 << "С��������Σ�" << endl;
            for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
            {
                cout << "���: " << it->second << " ������ " << this->m_Speaker[it->second].m_Name << " �ɼ��� " 
                     << this->m_Speaker[it->second].m_Score[this->m_index - 1] << endl;
            }

            int count = 0;
			//ȡǰ����
			for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
			{
				if (this->m_index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vVictory.push_back((*it).second);
				}
			}

            groupScore.clear();

			cout << endl;
        }



    }
	
	cout << "------------- ��" << this->m_index << "�ֱ������  ------------- " << endl;
	system("pause");
}

void SpeechManager::showScore()
{
	cout << "---------��" << this->m_index << "�ֽ���ѡ����Ϣ���£�-----------" << endl;
	vector<int>v;
	if (this->m_index == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "ѡ�ֱ�ţ�" << *it << " ������ " << m_Speaker[*it].m_Name << " �÷֣� " << m_Speaker[*it].m_Score[this->m_index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->show_Menu(); 
}

void SpeechManager::startSpeech()
{
    //��һ�ֱ���
	//1����ǩ
	SpeechManager::speechDraw();
	//2������
    SpeechManager::speechContest();

	//3����ʾ�������
    SpeechManager::showScore();

	//�ڶ��ֱ���
    this->m_index++;
	//1����ǩ
    SpeechManager::speechDraw();
	//2������
    SpeechManager::speechContest();
	//3����ʾ���ս��
    SpeechManager::showScore();
	//4���������
    SpeechManager::saveRecord();

    this->initSpeech();
    this->createSpeaker();
    this->loadRecord();
    cout << "end" <<endl;

	system("pause");
	system("cls");
}

void SpeechManager::saveRecord()
{
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app);
    for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
    {
        ofs << *it << "," << m_Speaker[*it].m_Score[1] << ",";
    }
    ofs << endl;

    ofs.close();
    cout << "��¼�Ѿ�����" << endl;
}

void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in); //���������� ��ȡ�ļ�

	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

    //�ļ���յ����
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��!" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ���Ϊ��
	this->fileIsEmpty = false;

	ifs.putback(ch); //��ȡ�ĵ����ַ��Ż�ȥ

	string data;
	int index = 0;
	while (ifs >> data)
	{
		// cout << data << endl;
		vector<string>v;

		int pos = -1;
		int start = 0;

		while (true)
		{
			pos = data.find(",", start); //��0��ʼ���� ','
			if (pos == -1)
			{
				break; //�Ҳ���break����
			}
			string tmp = data.substr(start, pos - start); //�ҵ���,���зָ� ����1 ��ʼλ�ã�����2 ��ȡ����
			v.push_back(tmp);
			start = pos + 1;
		}

		this->m_Record.insert(make_pair(index, v));
		index++;
	}

	ifs.close();
}

void SpeechManager::showRecord()
{
	for (int i = 0; i < this->m_Record.size(); i++)
	{
		cout << "��" << i + 1 << "�� " <<
			"�ھ���ţ�" << this->m_Record[i][0] << " �÷֣�" << this->m_Record[i][1] << " "
			"�Ǿ���ţ�" << this->m_Record[i][2] << " �÷֣�" << this->m_Record[i][3] << " "
			"������ţ�" << this->m_Record[i][4] << " �÷֣�" << this->m_Record[i][5] << endl;
	}
    system("pause");
	system("cls");
}

void SpeechManager::clearRecord()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//��ģʽ ios::trunc �������ɾ���ļ������´���
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//��ʼ������
		this->initSpeech();

		//����ѡ��
		this->createSpeaker();

		//��ȡ�����¼
		this->loadRecord();
		

		cout << "��ճɹ���" << endl;
	}

	system("pause");
	system("cls");
}

SpeechManager::~SpeechManager()
{

}

