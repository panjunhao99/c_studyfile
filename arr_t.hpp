#pragma once
#include <iostream>
#include <string>

using namespace std;

template<class T>
class MyArray
{
public:
    MyArray(int capacity)
    {
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
        cout << "有参构造" << endl;
    }

    MyArray(const MyArray& arr)
    {
        cout << "拷贝构造" << endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        //this->pAddress = arr.pAddress 浅拷贝

        this->pAddress = new T[arr.m_Capacity];  //深拷贝

        for(int i = 0; i < arr.m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    //operator=防止浅拷贝
    MyArray& operator=(const MyArray& arr)
    {
        //先判断原来堆区是否有数据
        if(this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;

        }
        
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[arr.m_Capacity];  //深拷贝

        for(int i = 0; i < arr.m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }

        return *this;
    }

    void Push_Back(const T & val)
    {
        if(this->m_Capacity == this->m_Size)
        {
            return;
        }
        this->pAddress[this->m_Size] = val;
        this->m_Size++;
    }

    void Pop_Back()
    {
        if(this->m_Size == 0)
        {
            return;
        }
        this->m_Size--;
    }

    int getSize()
    {
        return this->m_Size;
    }

    T& operator[](int index)          //这里使用T&使得结果可以作为左值存在
    {
        return this->pAddress[index];
    }

    ~MyArray()
    {
        cout << "析构" << endl;
        if(this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }

private:
    T * pAddress;
    int m_Capacity;
    int m_Size;

};