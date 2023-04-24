#pragma

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int DataType;

/* ˫���ͷ���� */
typedef struct ListNode {
	struct ListNode* prev;
	struct ListNode* next;
	DataType data;
}List;

/*
	�����ϼ���
		1. ��ʼ��һ��˫����
		2. ������㣻
		3. ���пա���ȡ����������
		4. β�巨��ͷ�巨��
		5. βɾ����ͷɾ����
		6. ָ��λ�ò�����
		7. ��ѯ������
*/

/* ��ʼ��һ��˫���� */
List* InitList();

/* ������� */
List* CreateNode(DataType data);

/* ���п� */
bool IsEmpty(List* phead);

/* ��ȡ�� */
int GetSize(List* phead);

/* ������ */
void Print(List* phead);

/* β�巨 */
void PushBack(List* phead, DataType data);

/* ͷ�巨 */
void PushFront(List* phead, DataType data);

/* βɾ�� */
void PopBack(List* phead);

/* ͷɾ�� */
void PopFront(List* phead);

/* ָ�����֮ǰ���� */
void InsertPos(List* pos, DataType data);

/* ɾ��ָ����� */
void EarsePos(List* pos);

/* ��ֵ��ѯ���� */
List* FindByValue(List* phead, DataType data);