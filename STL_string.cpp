#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


void test01()
{
    // string本质是一个类， 而char是一个指针
    string s1;
    const char * str = "hello world";
    string s2(str);
    string s3(s2);  //拷贝构造
    string s4(10, 'a'); 

    cout << s2 << endl;
  
    
}

void test02()
{
    //赋值
    string str1;
    str1 = "hello";
    str1.assign("hello!", 3);  // 前n个字符赋值
    string str2;
    str2 = str1;
    str2.assign(str1);
    str2 = 'a';
    str2.assign(10, 'a');
}

void test03()
{
    //拼接
    string str1;
    str1 = "hello";
    str1 += "!";
    str1.append("world", 0, 3); // 前n个字符 从0起，3个
    string str2;
    str2 = str1;
    str2.assign(str1);
    str2 = 'a';
    str2.assign(10, 'a');
}

void test04()
{
    //find
    string str1;
    str1 = "hello";
    int pos = str1.find("llo", 2);  //从2位置开始查,返回出现位置，未找到返回-1
    int pos2 = str1.rfind("llo", 2); //从右向左找

    //,replace
    string str2;
    str2 = "hello";
    str2.replace(1,3, "11111");    //从1起，3个，超过也替换

    cout << str2 << endl;

}

void test05()
{
    //比较
    string str1;
    string str2;
    str1 = "hello";
    str2 = "hello";
    int a = str1.compare(str2);   //=返回0， > 1, < -1
    cout << a << endl;



}

int main(int argc, char const *argv[])
{
    test04();
    
    system("pause");
    return 0;
}