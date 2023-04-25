#include "Stack.h"

/* 初始化一个栈 */
void InitStack(ST* stack) {
	stack->array = NULL;
	stack->capacity = stack->top = 0;		
 	return stack;
}

/* 判空 */
bool IsEmpty(ST* stack) {
	assert(stack);
	return stack->top == 0;		
}


/* 入栈 */
void StackPush(ST* stack, DataType data) {
	assert(stack);
	// 扩容处理
	if (stack->capacity == stack->top) {
		int newCapacity = stack->capacity == 0 ? 4 : stack->capacity * 2;
		ST* temp = (ST*)realloc(stack->array, sizeof(ST)*newCapacity);
		if (temp == NULL) {
			perror("realloc fail！\n");
			exit(-1);
		}
		stack->array = temp;
		stack->capacity = newCapacity;
	}
	// 数据插入
	stack->array[stack->top] = data;
	stack->top++;						// 栈顶标识自增
}

/* 出栈 */
void StackPop(ST* stack) {
	assert(stack);
	assert(!IsEmpty(stack));
	stack->top--;
}

/* 获取栈顶元素 */
int StackTop(ST* stack) {
	assert(stack);
	assert(!IsEmpty(stack));
	return stack->array[stack->top - 1];
}

/* 获取栈内元素个数 */
int StackSize(ST* stack) {
	assert(stack);
	if (IsEmpty(stack)) return 0;
	return stack->top;
}