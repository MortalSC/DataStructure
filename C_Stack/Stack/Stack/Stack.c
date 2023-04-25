#include "Stack.h"

/* ��ʼ��һ��ջ */
void InitStack(ST* stack) {
	stack->array = NULL;
	stack->capacity = stack->top = 0;		
 	return stack;
}

/* �п� */
bool IsEmpty(ST* stack) {
	assert(stack);
	return stack->top == 0;		
}


/* ��ջ */
void StackPush(ST* stack, DataType data) {
	assert(stack);
	// ���ݴ���
	if (stack->capacity == stack->top) {
		int newCapacity = stack->capacity == 0 ? 4 : stack->capacity * 2;
		ST* temp = (ST*)realloc(stack->array, sizeof(ST)*newCapacity);
		if (temp == NULL) {
			perror("realloc fail��\n");
			exit(-1);
		}
		stack->array = temp;
		stack->capacity = newCapacity;
	}
	// ���ݲ���
	stack->array[stack->top] = data;
	stack->top++;						// ջ����ʶ����
}

/* ��ջ */
void StackPop(ST* stack) {
	assert(stack);
	assert(!IsEmpty(stack));
	stack->top--;
}

/* ��ȡջ��Ԫ�� */
int StackTop(ST* stack) {
	assert(stack);
	assert(!IsEmpty(stack));
	return stack->array[stack->top - 1];
}

/* ��ȡջ��Ԫ�ظ��� */
int StackSize(ST* stack) {
	assert(stack);
	if (IsEmpty(stack)) return 0;
	return stack->top;
}