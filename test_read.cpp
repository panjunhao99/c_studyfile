//#include "stdafx.h"
#include <windows.h>
#include <iostream> 
using namespace std;
 
#define BUF_SIZE 4096
 
int main()
{
	// ���干������
	UINT32 szBuffer[] = {0x34ff,0x12ff,0x0345678,0x04,0x00,0,0,0};
 
	// ���������ļ���� 
	HANDLE hMapFile = CreateFileMapping(
		INVALID_HANDLE_VALUE,   // �����ļ����
		NULL,   // Ĭ�ϰ�ȫ����
		PAGE_READWRITE,   // �ɶ���д
		0,   // ��λ�ļ���С
		BUF_SIZE,   // ��λ�ļ���С
		L"S_ME"   // �����ڴ�����
	);
 
	// ӳ�仺������ͼ , �õ�ָ�����ڴ��ָ��
	LPVOID lpBase = MapViewOfFile(
		hMapFile,            // �����ڴ�ľ��
		FILE_MAP_ALL_ACCESS, // �ɶ�д���
		0,
		0,
		BUF_SIZE
	);
 
	// �����ݿ����������ڴ�
	//strcpy((UINT32*)lpBase, szBuffer);
	memcpy((UINT32*)lpBase, szBuffer,sizeof(szBuffer));
	cout <<"����"<< (UINT32*)lpBase << endl;
 
	// �̹߳���������̶߳�ȡ����
	Sleep(2000000);
 
	// ����ļ�ӳ��
	UnmapViewOfFile(lpBase);
	// �ر��ڴ�ӳ���ļ�������
	CloseHandle(hMapFile);
	return 0;
}