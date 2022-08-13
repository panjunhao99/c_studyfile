#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void test01()
{
    ofstream ofs;

    ofs.open("test.txt", ios::out);

    ofs << "hello" << endl;
    ofs << "miao"  << endl;

    ifstream ifs;
    ifs.open("test.txt", ios::in);

    if(!ifs.is_open())
    {
        cout << "fail!" << endl;
        return;
    }

    char buf[1024] = {0};
    string buff;
    // while(ifs >> buf)
    // {
    //     cout << buf << endl;
    // }
    // while(ifs.getline(buf, sizeof(buf)))
    // {
    //     cout << buf << endl;
    // }
    while(getline(ifs, buff))
    {
        cout << buff << endl;
    }

    ifs.close();


}

int main(int argc, char const *argv[])
{
    /* code */
    test01();
    system("pause");
    return 0;
}
