#pragma

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

/* ��̬˳��ջ */
typedef int DataType;
typedef struct Stack {
	DataType* array;
	int top;			// ���ڱ�ʶջ��λ�ã�ͬʱ�ɼ�¼��ǰվ��Ԫ�ظ���
	int capacity;		// ջ����
}ST;

/* ��ʼ��һ��ջ */
void InitStack(ST* stack);

/* �п� */
bool IsEmpty(ST* stack);

/* ��ջ */
void StackPush(ST* stack, DataType data);

/* ��ջ */
void StackPop(ST* stack);

/* ��ȡջ��Ԫ�� */
int StackTop(ST* stack);

/* ��ȡջ��Ԫ�ظ��� */
int StackSize(ST* stack);
