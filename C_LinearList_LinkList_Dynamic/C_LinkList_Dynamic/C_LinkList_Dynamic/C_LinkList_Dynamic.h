#pragma

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int DataType;		/* ����һ�������������ͣ������޸Ĳ����������� */

typedef struct ListNode {		/* ������ */
	DataType data;				/* ������ */
	struct ListNode* next;		/* ָ���� */
}LstNode;


/*
	���������ϼ�˵����
		1. ��ʼ��һ��������
		2. �����
		3. ������㣨ͷ�巨��β�巨������ָ��λ��֮����룩��
		4. ɾ����㣨ͷɾ����βɾ����ָ��λ��ɾ������
		5. ���ҽڵ㣨ָ��ֵ���ҡ�����λ�򡿡�ָ��λ�ò��ҡ�����ֵ/��㡿��
		6. �����
		7. �пձ�
		...
*/

/* ��ʼ��һ�������� */
LstNode* InitLinkList();

/* �½���㣺�˴�����ʹ��һ�������½���� */
LstNode* CreateNode(DataType data);

/* �����пգ��˴�ע�⣺C ������ʹ�� bool ���ͣ���Ҫ stdbool.h ͷ�ļ� */
bool IsEmpty(LstNode* pHead);

/* ����� */
void ListPrint(LstNode* pHead);

/* β�巨 */
void LinkListPushBack(LstNode** pHead, DataType data);

/* ͷ�巨 */
void LinkListPushFront(LstNode** pHead, DataType data);

/* βɾ�� */
void LinkListPopBack(LstNode** pHead);

/* ͷɾ�� */
void LinkListPopFront(LstNode** pHead);

/* ��� */
int GetLength(LstNode* pHead);

/* ��ֵ���ң����ؽ�� */
LstNode* FindByValue(LstNode* pHead, DataType data);

/* ����ָ��λ�ã����ؽ�� */
LstNode* FindByPos(LstNode* pHead, int pos);

/* ָ��λ��֮����� */
void InsertPos(LstNode** pHead, int pos, DataType data);

/* ɾ��ָ��λ���ϵ�ֵ */
LstNode* DelPos(LstNode** pHead, int pos);