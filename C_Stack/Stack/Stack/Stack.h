#pragma

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

/* 动态顺序栈 */
typedef int DataType;
typedef struct Stack {
	DataType* array;
	int top;			// 用于标识栈顶位置，同时可记录当前站内元素个数
	int capacity;		// 栈容量
}ST;

/* 初始化一个栈 */
void InitStack(ST* stack);

/* 判空 */
bool IsEmpty(ST* stack);

/* 入栈 */
void StackPush(ST* stack, DataType data);

/* 出栈 */
void StackPop(ST* stack);

/* 获取栈顶元素 */
int StackTop(ST* stack);

/* 获取栈内元素个数 */
int StackSize(ST* stack);
