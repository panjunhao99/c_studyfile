#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "speaker.h"
#include <functional>
#include <numeric>
#include <fstream>
#include <ctime>

using namespace std;

class SpeechManager
{
public:
    SpeechManager();

    void show_Menu();

    void exitsystem();

    void initSpeech();

    void createSpeaker();

    void printSpeaker(const map<int, Speaker>&m);
    // ��ʼ����
    void startSpeech();
    //��ǩ
	void speechDraw();

    void speechContest();
    //��ʾ�������
	void showScore();
    //�����¼
	void saveRecord();

    //��ȡ��¼
	void loadRecord();

    //��ʾ����÷�
	void showRecord();
    //��ռ�¼
    void clearRecord();



    ~SpeechManager();

    int m_index;
    vector<int>v1;
    vector<int>v2;
    vector<int>vVictory;
    map<int, Speaker> m_Speaker;
    //�ļ�Ϊ�յı�־
	bool fileIsEmpty;

	//�����¼
	map<int, vector<string>> m_Record;




};