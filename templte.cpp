#include <iostream>
#include <string>

using namespace std;

//��ͨ�����Զ���ʽת��
//ģ�庯�� �Զ������Ƶ���ʱ�򲻿ɷ�����ʽ����ת��
//ģ�庯�� ����ʾָ�����͵�ʱ�� �ɷ�����ʽ����ת��

template<typename T>
void mySwap(T&a, T&b)  //�Ƶ����ͱ���һ��
{
    T temp = a;
    a = b;
    b = temp;
}

//�����㷨
template<typename T>
void mySort(T arr[], int len)
{
    for(int i = 0; i < len; i++)
    {
        int max = i;
        for(int j = i + 1; j < len; j++)
        {
            if(arr[max] < arr[j])
            {
                max = j;
            }
        }
        if(max != i)
        {
            mySwap(arr[max], arr[i]);
        }
    }
}

template<typename T>
void printArr(T arr[], int len)
{
    for(int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";

    }
    cout << endl;
}
void test01()
{
    int a = 1;
    int b = 2;
    mySwap(a, b);
    cout << a << b << endl;

    char charArr[] = "badcfe";
    int num = sizeof(charArr)/sizeof(char);
    mySort(charArr, num);
    printArr(charArr, num);

    int intArr[] = {7,3,1,5,6,8,9};
    int num2 = sizeof(intArr)/sizeof(int);
    mySort<int>(intArr, num);
    printArr(intArr, num);

}

int main(int argc, char const *argv[])
{
    /* code */
    test01();
    system("pause");
    return 0;
}
