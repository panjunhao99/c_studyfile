#include <iostream>
using namespace std;
#include "speechManager.h"
#include "speechManager.cpp"

int main()
{
    SpeechManager sm;
    srand((unsigned int)time(NULL));

    // sm.printSpeaker(sm.m_Speaker);
    // sm.startSpeech();
    int choice = 0;
    // sm.show_Menu();

    while(true)
    {
        sm.show_Menu();
        cout << "ÇëÊäÈëÑ¡Ïî" << endl;
        cin >> choice;
        switch(choice)
        {
        case 1:
            sm.startSpeech();
            break;
        case 2:
            sm.loadRecord();
            sm.showRecord();
            break;
        case 3:
            sm.clearRecord();
            break;
        case 0:
            sm.exitsystem();
            break;
        default:
            system("cls");
            break;
        }

    }


    system("pause");

    return 0;
}
