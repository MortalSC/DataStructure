#include "List.h"

/* 初始化一个双链表 */
List* InitList() {
	List* plist = (List*)malloc(sizeof(List));
	if (!plist) {
		perror("malloc fail!\n");
		exit(-1);
	}
	plist->next = plist;
	plist->prev = plist;
	return plist;
}

/* 创建结点 */
List* CreateNode(DataType data) {
	List* node = (List*)malloc(sizeof(List));
	assert(node);
	node->next = NULL;
	node->prev = NULL;
	node->data = data;
	return node;
}

/* 表判空 */
bool IsEmpty(List* phead) {
	return (phead->next == phead);
}

/* 获取表长 */
int GetSize(List* phead) {
	if (IsEmpty(phead)) return 0;
	int size = 0;
	List* cur = phead->next;
}


/* 遍历表 */
void Print(List* phead) {
	if (IsEmpty(phead)) return;

	List* cur = phead->next;
	printf("List：");
	while (cur != phead) {
		printf("%d -> ", cur->data);
		cur = cur->next;
	}
	printf("\n");

}

/* 尾插法 */
void PushBack(List* phead, DataType data) {
	assert(phead);

#if 0
	List* node = CreateNode(data);
	/*
		注意点：尾插法等价于在哨兵结点之前插入结点
	*/
	List* cur = phead->prev;
	cur->next = node;
	node->prev = cur;
	node->next = phead;
	phead->prev = node;
#else
	InsertPos(phead, data);
#endif
}


/* 头插法 */
void PushFront(List* phead, DataType data) {
	assert(phead);
#if 0
	List* node = CreateNode(data);
	node->next = phead->next;
	phead->next->prev = node;
	phead->next = node;
	node->prev = phead;
#else
	InsertPos(phead->next, data);
#endif
}

/* 尾删法 */
void PopBack(List* phead) {
	assert(phead && phead->next != phead);
#if 0
	List* node = phead->prev;				/* 指向尾结点 */
	node->prev->next = phead;			/* 尾结点的前一个结点指向哨兵结点 */
	phead->prev = node->prev;			/* 哨兵结点的前指针指向倒数第二个结点 */
	free(node);
#else
	EarsePos(phead->prev);
#endif
}

/* 头删法 */
void PopFront(List* phead) {
	assert(phead && phead->next != phead);
#if 0
	List* node = phead->next;

	phead->next = node->next;
	node->next->prev = phead;
	free(node);
#else
	EarsePos(phead->next);
#endif
}


/* 指定结点之前插入 */
void InsertPos(List* pos, DataType data) {
	assert(pos);

	List* node = CreateNode(data);			// 申请新结点
	node->next = pos;
	pos->prev->next = node;
	node->prev = pos->prev;
	pos->prev = node;
}

/* 删除指定结点 */
void EarsePos(List* pos) {
	assert(pos);

	List* prev = pos->prev;
	List* next = pos->next;

	prev->next = next;
	next->prev = prev;
	free(pos);
}


/* 按值查询操作 */
List* FindByValue(List* phead, DataType data) {
	if (IsEmpty(phead)) return NULL;				// 空表返回

	// 非空操作（借助游标指针辅助查询，双向链表可向前查也可向后查，只需注意循环条件即可）
	List* cur = phead->next;
	while (cur != phead) {
		if (cur->data == data) return cur;
		cur = cur->next;
	}
	return NULL;
}