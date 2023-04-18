#include"C_LinkList_Dynamic.h"

/* 测试初始化一个链表 */
void test_InitLinkList();

/* 测试尾插法 */
void test_LinkListPushBack();

/* 测试头插法 */
void test_LinkListPushFront();

/* 测试尾删法 */
void test_LinkListPopBack();

/* 测试头删法 */
void test_LinkListPopFront();

/* 测试获取表长 */
void test_GetLength();

/* 测试按值查找 */
void test_FindByValue();

/* 测试指定位置查找 */
void test_FindByPos();

/* 测试指定位置之后插入 */
void test_InsertPos();

/* 测试指定位次删除 */
void test_DelPos();

int main() {

	printf("====================================\n");
	test_InitLinkList();

	printf("====================================\n");
	test_LinkListPushBack();

	printf("====================================\n");
	test_LinkListPushFront();

	printf("====================================\n");
	test_LinkListPopBack();

	printf("====================================\n");
	test_LinkListPopFront();

	printf("====================================\n");
	test_GetLength();

	printf("====================================\n");
	test_FindByValue();

	printf("====================================\n");
	test_FindByPos();

	printf("====================================\n");
	test_InsertPos();

	printf("====================================\n");
	test_DelPos();

	return 0;
}

/* 测试初始化一个链表 */
void test_InitLinkList() {
	LstNode* plist = InitLinkList();
	ListPrint(plist);
}

/* 测试尾插法 */
void test_LinkListPushBack() {
	LstNode* plist = InitLinkList();

	LinkListPushBack(&plist, 10);

	for (int i = 2; i <= 10; i++) {
		LinkListPushBack(&plist, i * 10);
	}

	ListPrint(plist);
}

/* 测试头插法 */
void test_LinkListPushFront() {
	LstNode* plist = InitLinkList();

	LinkListPushFront(&plist, 1);

	for (int i = 2; i <= 10; i++) {
		LinkListPushFront(&plist, i);
	}

	ListPrint(plist);
}

/* 测试尾删法 */
void test_LinkListPopBack() {

	LstNode* plist = InitLinkList();

#if 0		/* 测试链表结点数为：1 */
	LinkListPushBack(&plist, 10);
	ListPrint(plist);
#else		/* 测试链表结点数大于：1 */
	for (int i = 1; i <= 10; i++) {
		LinkListPushBack(&plist, i * 10);
	}
	ListPrint(plist);
#endif

	LinkListPopBack(&plist);
	ListPrint(plist);

}


/* 测试头删法 */
void test_LinkListPopFront() {
	LstNode* plist = InitLinkList();

#if 0		/* 测试链表结点数为：1 */
	LinkListPushBack(&plist, 10);
	ListPrint(plist);
#else		/* 测试链表结点数大于：1 */
	for (int i = 1; i <= 10; i++) {
		LinkListPushBack(&plist, i * 10);
	}
	ListPrint(plist);
#endif

	LinkListPopFront(&plist);
	ListPrint(plist);
}


/* 测试获取表长 */
void test_GetLength() {
	LstNode* plist = InitLinkList();
	printf("length: %d\n", GetLength(plist));

	for (int i = 1; i <= 10; i++) {
		LinkListPushBack(&plist, i * 10);
	}
	ListPrint(plist);
	printf("length: %d\n", GetLength(plist));
}

/* 测试按值查找 */
void test_FindByValue() {
	LstNode* plist = InitLinkList();
	for (int i = 1; i <= 10; i++) {
		LinkListPushBack(&plist, i * 10);
	}
	ListPrint(plist);

	printf("目标值为：20\n");
	if (FindByValue(plist, 20)) {
		printf("找到目标，值为：%d\n", FindByValue(plist, 20)->data);
	}
	else {
		printf("未找到目标值 或 链表为空！\n");
	}

	printf("目标值为：1\n");
	if (FindByValue(plist, 1)) {
		printf("找到目标，值为：%d\n", FindByValue(plist, 20)->data);
	}
	else {
		printf("未找到目标值 或 链表为空！\n");
	}
}


/* 测试指定位置查找 */
void test_FindByPos() {
	LstNode* plist = InitLinkList();
	for (int i = 1; i <= 10; i++) {
		LinkListPushBack(&plist, i * 10);
	}
	ListPrint(plist);

	printf("目标位置为：20\n");
	if (FindByPos(plist, 20)) {
		printf("找到目标，值为：%d\n", FindByPos(plist, 20)->data);
	}
	else {
		printf("未找到目标值！\n");
	}

	printf("目标位置为：1\n");
	if (FindByPos(plist, 1)) {
		printf("找到目标，值为：%d\n", FindByPos(plist, 1)->data);
	}
	else {
		printf("未找到目标值！\n");
	}
}


/* 测试指定位置之后插入 */
void test_InsertPos() {
	LstNode* plist = InitLinkList();

	if (0) {		/* 测试空表插入 */
		InsertPos(&plist, 1, 111);
	}

	for (int i = 1; i <= 5; i++) {
		LinkListPushBack(&plist, i * 10);
	}
	ListPrint(plist);

	printf("尾部插入：\n");
	InsertPos(&plist, 5, 111);
	ListPrint(plist);

	printf("头部插入：\n");
	InsertPos(&plist, 1, 222);
	ListPrint(plist);

	printf("中部插入：\n");
	InsertPos(&plist, 3, 333);
	ListPrint(plist);
}

/* 测试指定位次删除 */
void test_DelPos() {
	LstNode* plist = InitLinkList();

	if (0) {		/* 测试空表插入 */
		DelPos(&plist, 1);
	}

	for (int i = 1; i <= 10; i++) {
		LinkListPushBack(&plist, i * 10);
	}
	ListPrint(plist);

	printf("尾部删除：\n");
	printf("被删除的结点值为：%d\n", DelPos(&plist, 10)->data);
	ListPrint(plist);

	printf("中部删除：\n");
	printf("被删除的结点值为：%d\n", DelPos(&plist, 4)->data);
	ListPrint(plist);

	printf("头部删除：\n");
	printf("被删除的结点值为：%d\n", DelPos(&plist, 1)->data);
	ListPrint(plist);

}