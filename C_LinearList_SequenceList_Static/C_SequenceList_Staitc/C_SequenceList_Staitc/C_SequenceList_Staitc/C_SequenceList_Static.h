#pragma

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/* 动态数组 / 顺序表 的实现 */

typedef int DataType;
#define Max 10

typedef struct SeqArray {
	DataType* arr;						/* 指向数组的指针 */
	int capacity;						/* 表示数组容量 */
	int CSize;							/* 表示当前数组元素个数 */
}SeList;

/*
	基本方法合集：
		1. 初始化一个顺序表；
		2. 获取当前数组的容量大小；
		3. 容量检查与扩容；
		4. 获取当前数组中元素个数；
		5. 插入元素【尾插法、头插法、指定插入】；
		6. 删除元素【尾删法、头删法、指定删除】；
		7. 遍历数组元素；
		8. 查找元素【返回指定位置元素、返回指定元素索引】
*/

/* 初始化一个顺序表 */
void InitSeList(SeList* sl);

/* 获取当前数组的容量大小 */
int GetCapacity(SeList sl);

/* 获取当前数组中元素个数 */
int GetSize(SeList sl);

/* 容量检查与扩容 */
void CheckCapacity(SeList* sl);

/* 遍历数组元素 */
void TravelSeList(SeList sl);

/* 尾插法 */
void PushBack(SeList* sl, DataType data);

/* 头插法 */
void PushFront(SeList* sl, DataType data);

/* 尾删法 */
void PopBack(SeList* sl);

/* 头删法 */
void PopFront(SeList* sl);

/* 指定位次插入 */
void InsertPos(SeList* sl, int pos, DataType data);

/* 指定位次删除 */
void DelPos(SeList* sl, int pos);


/* 查找元素：返回索引 */
int GetElemPos(SeList* sl, DataType data);

/* 查找指定索引：返回元素 */
DataType GetElemByPos(SeList* sl, int pos);
