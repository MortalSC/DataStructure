#include "C_SequenceList_Static.h"


/* 测试初始化一个顺序表 */
void test_InitSeList();

/* 测试获取数组容量和当前元素个数 */
void test_GetInfo();

/* 测试尾部插入 */
void test_PushBack();

/* 测试头部插入 */
void test_PushFront();

/* 测试尾删法 */
void test_PopBack();

/* 测试头删法 */
void test_PopFront();

/* 测试指定位次插入 */
void test_InsertPos();

/* 测试指定位次删除 */
void test_DelPos();

/* 查找元素：返回索引 */
void test_GetElemPos();

/* 查找指定索引：返回元素 */
void test_GetElemByPos();

int main() {

	printf("==============================================\n");
	test_InitSeList();

	printf("==============================================\n");
	test_GetInfo();

	printf("==============================================\n");
	test_PushBack();

	printf("==============================================\n");
	test_PushFront();

	printf("==============================================\n");
	test_PopBack();

	printf("==============================================\n");
	test_PopFront();

	printf("==============================================\n");
	test_InsertPos();

	printf("==============================================\n");
	test_DelPos();

	printf("==============================================\n");
	test_GetElemPos();

	printf("==============================================\n");
	test_GetElemByPos();

	return 0;
}


/* 初始化一个顺序表 */
void test_InitSeList() {
	SeList sl;
	InitSeList(&sl);
}

/* 测试获取数组容量和当前元素个数 */
void test_GetInfo() {
	SeList sl;
	InitSeList(&sl);
	printf("%d \n", GetCapacity(sl));
	printf("%d \n", GetSize(sl));
}

/* 测试尾部插入 */
void test_PushBack() {
	SeList sl;
	InitSeList(&sl);

	for (int i = 0; i < 10; i++) {
		PushBack(&sl, i + 1);
		printf("%d ", GetCapacity(sl));
		printf("%d ：", GetSize(sl));
		TravelSeList(sl);
	}
}

/* 测试头部插入 */
void test_PushFront() {
	SeList sl;
	InitSeList(&sl);

	for (int i = 0; i < 10; i++) {
		PushFront(&sl, i + 1);
		printf("%d ", GetCapacity(sl));
		printf("%d ：", GetSize(sl));
		TravelSeList(sl);
	}
}


/* 测试尾删法 */
void test_PopBack() {
	SeList sl;
	InitSeList(&sl);

	for (int i = 0; i < 10; i++) {
		PushFront(&sl, i + 1);
	}
	TravelSeList(sl);

	PopBack(&sl);
	TravelSeList(sl);
}

/* 测试头删法 */
void test_PopFront() {
	SeList sl;
	InitSeList(&sl);

	for (int i = 0; i < 10; i++) {
		PushFront(&sl, i + 1);
	}
	TravelSeList(sl);

	PopFront(&sl);
	TravelSeList(sl);
}


/* 测试指定位次插入 */
void test_InsertPos() {
	SeList sl;
	InitSeList(&sl);

	for (int i = 0; i < 10; i++) {
		PushFront(&sl, i + 1);
	}
	TravelSeList(sl);
	printf("第 2 个位置插入：");
	InsertPos(&sl, 2,100);
	TravelSeList(sl);
}

/* 测试指定位次删除 */
void test_DelPos() {
	SeList sl;
	InitSeList(&sl);

	for (int i = 0; i < 10; i++) {
		PushFront(&sl, i + 1);
	}
	TravelSeList(sl);
	printf("删除：第 2 个：");
	DelPos(&sl,2);
	TravelSeList(sl);
}


/* 查找元素：返回索引 */
void test_GetElemPos() {
	SeList sl;
	InitSeList(&sl);

	for (int i = 0; i < 10; i++) {
		PushFront(&sl, i + 1);
	}
	TravelSeList(sl);
	printf("5 的索引值：%d\n", GetElemPos(&sl,5));
}

/* 查找指定索引：返回元素 */
void test_GetElemByPos() {
	SeList sl;
	InitSeList(&sl);

	for (int i = 0; i < 10; i++) {
		PushFront(&sl, i + 1);
	}
	TravelSeList(sl);
	printf("索引为 5 的元素：%d\n", GetElemByPos(&sl, 5));
}