#pragma

/* �˴�ʹ�õ������ʵ����ʽ���У��������һ��βָ���� */
/* ��ʵ��ָ��������ͷ���ӣ�����β��� */

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int DataType;

typedef struct QueueNode {
	DataType data;
	struct QueueNode* next;
}Node;

typedef struct Link_Queue {
	struct QueueNode* head;
	struct QueueNode* tail;
}Queue;

/* ���з����ϼ���
	1. ��ʼ��һ�����У�
	2. ���ٶ��У�
	3. ��ӡ����ӣ�
	4. �Ӵ�С���ӿգ�
	5. ��ͷ��βԪ�أ�
*/
/* ��ʼ��һ������ */
void QueueInit(Queue* queue);

/* �Ӵ�С */
int Size(Queue* queue);

/* �Ӵ�С */
bool IsEmpty(Queue* queue);

/* ��� */
void Push(Queue* queue, DataType data);

/* ���� */
void Pop(Queue* queue);

/* ��ͷԪ�� */
DataType ElemFront(Queue* queue);

/* ��βԪ�� */
DataType ElemBack(Queue* queue);

/* ���ٶ��� */
void Destory(Queue* queue);