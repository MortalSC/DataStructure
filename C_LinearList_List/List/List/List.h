#pragma

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int DataType;

/* 双向带头链表 */
typedef struct ListNode {
	struct ListNode* prev;
	struct ListNode* next;
	DataType data;
}List;

/*
	方法合集：
		1. 初始化一个双链表；
		2. 创建结点；
		3. 表判空、获取表长、遍历表；
		4. 尾插法、头插法；
		5. 尾删法、头删法；
		6. 指定位置操作；
		7. 查询操作；
*/

/* 初始化一个双链表 */
List* InitList();

/* 创建结点 */
List* CreateNode(DataType data);

/* 表判空 */
bool IsEmpty(List* phead);

/* 获取表长 */
int GetSize(List* phead);

/* 遍历表 */
void Print(List* phead);

/* 尾插法 */
void PushBack(List* phead, DataType data);

/* 头插法 */
void PushFront(List* phead, DataType data);

/* 尾删法 */
void PopBack(List* phead);

/* 头删法 */
void PopFront(List* phead);

/* 指定结点之前插入 */
void InsertPos(List* pos, DataType data);

/* 删除指定结点 */
void EarsePos(List* pos);

/* 按值查询操作 */
List* FindByValue(List* phead, DataType data);