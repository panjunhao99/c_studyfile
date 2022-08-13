#include <iostream>
#include <string>

using namespace std;

//普通函数自动隐式转换
//模板函数 自动类型推导的时候不可发生隐式类型转换
//模板函数 用显示指定类型的时候 可发生隐式类型转换

template<typename T>
void mySwap(T&a, T&b)  //推导类型必须一致
{
    T temp = a;
    a = b;
    b = temp;
}

//排序算法
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
