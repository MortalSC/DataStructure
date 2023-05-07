#pragma

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

/* 
	�ѣ�
	�������ʣ�
	��	һ����һ������ȫ������������
	��	С���ѣ����ڵ���������С�ڵ����ӽڵ㣩������ѣ����ڵ��������Ǵ��ڵ��ӽڵ㣩

	ʹ��˳��洢��ʽ���߼��ϵĶ�������

	��	С���ѣ����ڵ�Ԫ��һ���Ƕ�����СԪ�أ�����ѣ����ڵ�Ԫ��һ���Ƕ������Ԫ�أ�
	��	���ѣ�ָ���ӶѶ����ѣ�
*/

typedef int DataType;

typedef struct Heap {
	DataType* data;
	int capacity;					// ��������
	int size;						// ��ǰԪ�ظ���
}HP;

/*	�����ϼ���
		1. �����ѣ�
		2. ���ٶѣ�
		3. ��ѡ����ѣ�
		4. ��ȡ�Ѷ�Ԫ�أ�
		5. �пգ�
		6. ��ȡԪ�ظ�����
		7. ��ӡ�ѣ��Ǳ�Ҫ�ӿڣ�

	ע�⣺�ѿ���������
*/

/* ������ */
void HeapInit(HP* hp);

/* �п� */
bool IsEmpty(HP* hp);

/* ��ȡ����Ԫ�ظ��� */
int GetSize(HP* hp);

/* �������� */
void Swap(DataType* a, DataType* b);

/* ���ϵ������㷨��������ݵ��������ɴ���� / С���� */
void AjustUp(DataType* arr, int child);

/* ���µ������㷨���������ݵ�������ȡ��ֵ���ڶѶ��� */
/* ���µ����㷨��һ��ǰ�᣺��������������һ���ѣ����ܵ����� */
void AjustDown(DataType* arr, int size, int parent);


/* ��� */
void PushHeap(HP* hp, DataType data);

/* ���� */
void PopHeap(HP* hp);

/* ��ȡ�Ѷ�Ԫ�� */
DataType HeapTop(HP* hp);

/* ���ٶ� */
void Destroy(HP* hp);


/* ��ӡ�� */
void PrintHeap(HP* hp);