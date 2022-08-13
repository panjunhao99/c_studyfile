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
        cout << "�вι���" << endl;
    }

    MyArray(const MyArray& arr)
    {
        cout << "��������" << endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        //this->pAddress = arr.pAddress ǳ����

        this->pAddress = new T[arr.m_Capacity];  //���

        for(int i = 0; i < arr.m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    //operator=��ֹǳ����
    MyArray& operator=(const MyArray& arr)
    {
        //���ж�ԭ�������Ƿ�������
        if(this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;

        }
        
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[arr.m_Capacity];  //���

        for(int i = 0; i < arr.m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }

        return *this;
    }

    ~MyArray()
    {
        cout << "����" << endl;
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