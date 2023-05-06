#pragma

/* 此处使用单链表表实现链式队列：其中添加一个尾指针标记 */
/* 本实现指定：链表头出队，链表尾入队 */

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

/* 队列方法合集：
	1. 初始化一个队列；
	2. 销毁队列；
	3. 入队、出队；
	4. 队大小、队空；
	5. 队头队尾元素；
*/
/* 初始化一个队列 */
void QueueInit(Queue* queue);

/* 队大小 */
int Size(Queue* queue);

/* 队大小 */
bool IsEmpty(Queue* queue);

/* 入队 */
void Push(Queue* queue, DataType data);

/* 出队 */
void Pop(Queue* queue);

/* 队头元素 */
DataType ElemFront(Queue* queue);

/* 队尾元素 */
DataType ElemBack(Queue* queue);

/* 销毁队列 */
void Destory(Queue* queue);