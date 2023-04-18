#pragma

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int DataType;		/* 定义一个泛型数据类型：方便修改测试其他数据 */

typedef struct ListNode {		/* 链表结点 */
	DataType data;				/* 数据域 */
	struct ListNode* next;		/* 指针域 */
}LstNode;


/*
	基本方法合集说明：
		1. 初始化一个空链表；
		2. 求表长；
		3. 新增结点（头插法、尾插法、测试指定位置之后插入）；
		4. 删除结点（头删法、尾删法、指定位置删除）；
		5. 查找节点（指定值查找【返回位序】、指定位置查找【返回值/结点】）
		6. 输出表；
		7. 判空表；
		...
*/

/* 初始化一个空链表 */
LstNode* InitLinkList();

/* 新建结点：此处单独使用一个函数新建结点 */
LstNode* CreateNode(DataType data);

/* 链表判空：此处注意：C 语言中使用 bool 类型，需要 stdbool.h 头文件 */
bool IsEmpty(LstNode* pHead);

/* 输出表 */
void ListPrint(LstNode* pHead);

/* 尾插法 */
void LinkListPushBack(LstNode** pHead, DataType data);

/* 头插法 */
void LinkListPushFront(LstNode** pHead, DataType data);

/* 尾删法 */
void LinkListPopBack(LstNode** pHead);

/* 头删法 */
void LinkListPopFront(LstNode** pHead);

/* 求表长 */
int GetLength(LstNode* pHead);

/* 按值查找：返回结点 */
LstNode* FindByValue(LstNode* pHead, DataType data);

/* 查找指定位置：返回结点 */
LstNode* FindByPos(LstNode* pHead, int pos);

/* 指定位置之后插入 */
void InsertPos(LstNode** pHead, int pos, DataType data);

/* 删除指定位次上的值 */
LstNode* DelPos(LstNode** pHead, int pos);