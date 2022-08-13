#include <iostream>
using namespace std;
#include "arr_t.hpp"

void printIntArray(MyArray <int>&arr)
{
    for(int i = 0; i < arr.getSize(); i++)
    {
        cout << arr[i] << endl;
    }
}

void test01()
{
    MyArray <int>arr1(5);

    for(int i = 0; i < 5; i++)
    {
        arr1.Push_Back(i);
    }

    printIntArray(arr1);

    // MyArray <int>arr2(arr1);

    // MyArray <int>arr3(100);

    // arr3 = arr1;
}

int main(int argc, char const *argv[])
{
    test01();
    system("pause");
    return 0;
}
