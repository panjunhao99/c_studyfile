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
    // 开始比赛
    void startSpeech();
    //抽签
	void speechDraw();

    void speechContest();
    //显示比赛结果
	void showScore();
    //保存记录
	void saveRecord();

    //读取记录
	void loadRecord();

    //显示往届得分
	void showRecord();
    //清空记录
    void clearRecord();



    ~SpeechManager();

    int m_index;
    vector<int>v1;
    vector<int>v2;
    vector<int>vVictory;
    map<int, Speaker> m_Speaker;
    //文件为空的标志
	bool fileIsEmpty;

	//往届记录
	map<int, vector<string>> m_Record;




};