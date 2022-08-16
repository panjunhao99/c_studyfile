#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


void test01()
{
    // string������һ���࣬ ��char��һ��ָ��
    string s1;
    const char * str = "hello world";
    string s2(str);
    string s3(s2);  //��������
    string s4(10, 'a'); 

    cout << s2 << endl;
  
    
}

void test02()
{
    //��ֵ
    string str1;
    str1 = "hello";
    str1.assign("hello!", 3);  // ǰn���ַ���ֵ
    string str2;
    str2 = str1;
    str2.assign(str1);
    str2 = 'a';
    str2.assign(10, 'a');
}

void test03()
{
    //ƴ��
    string str1;
    str1 = "hello";
    str1 += "!";
    str1.append("world", 0, 3); // ǰn���ַ� ��0��3��
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
    int pos = str1.find("llo", 2);  //��2λ�ÿ�ʼ��,���س���λ�ã�δ�ҵ�����-1
    int pos2 = str1.rfind("llo", 2); //����������

    //,replace
    string str2;
    str2 = "hello";
    str2.replace(1,3, "11111");    //��1��3��������Ҳ�滻

    cout << str2 << endl;

}

void test05()
{
    //�Ƚ�
    string str1;
    string str2;
    str1 = "hello";
    str2 = "hello";
    int a = str1.compare(str2);   //=����0�� > 1, < -1
    cout << a << endl;



}

int main(int argc, char const *argv[])
{
    test04();
    
    system("pause");
    return 0;
}