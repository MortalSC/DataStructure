#pragma

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/* ��̬���� / ˳��� ��ʵ�� */

typedef int DataType;
#define Max 10

typedef struct SeqArray {
	DataType* arr;						/* ָ�������ָ�� */
	int capacity;						/* ��ʾ�������� */
	int CSize;							/* ��ʾ��ǰ����Ԫ�ظ��� */
}SeList;

/*
	���������ϼ���
		1. ��ʼ��һ��˳���
		2. ��ȡ��ǰ�����������С��
		3. ������������ݣ�
		4. ��ȡ��ǰ������Ԫ�ظ�����
		5. ����Ԫ�ء�β�巨��ͷ�巨��ָ�����롿��
		6. ɾ��Ԫ�ء�βɾ����ͷɾ����ָ��ɾ������
		7. ��������Ԫ�أ�
		8. ����Ԫ�ء�����ָ��λ��Ԫ�ء�����ָ��Ԫ��������
*/

/* ��ʼ��һ��˳��� */
void InitSeList(SeList* sl);

/* ��ȡ��ǰ�����������С */
int GetCapacity(SeList sl);

/* ��ȡ��ǰ������Ԫ�ظ��� */
int GetSize(SeList sl);

/* ������������� */
void CheckCapacity(SeList* sl);

/* ��������Ԫ�� */
void TravelSeList(SeList sl);

/* β�巨 */
void PushBack(SeList* sl, DataType data);

/* ͷ�巨 */
void PushFront(SeList* sl, DataType data);

/* βɾ�� */
void PopBack(SeList* sl);

/* ͷɾ�� */
void PopFront(SeList* sl);

/* ָ��λ�β��� */
void InsertPos(SeList* sl, int pos, DataType data);

/* ָ��λ��ɾ�� */
void DelPos(SeList* sl, int pos);


/* ����Ԫ�أ��������� */
int GetElemPos(SeList* sl, DataType data);

/* ����ָ������������Ԫ�� */
DataType GetElemByPos(SeList* sl, int pos);
