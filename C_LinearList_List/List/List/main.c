#include"List.h"

/* 测试表判空 */
void test_IsEmpty();

/* 测试尾插法 */
void test_PushBack();

/* 测试链表遍历 */
void test_Print();

/* 测试头插法 */
void test_PushFront();

/* 测试尾删法 */
void test_PopBack();

/* 测试头删法 */
void test_PopFront();

/* 测试按值查找 */
void test_FindByValue();

int main() {
	printf("\n================================================\n");
	test_IsEmpty();

	printf("\n================================================\n");
	test_PushBack();

	printf("\n================================================\n");
	test_Print();

	printf("\n================================================\n");
	test_PushFront();

	printf("\n================================================\n");
	test_PopBack();

	printf("\n================================================\n");
	test_PopFront();

	printf("\n================================================\n");
	test_FindByValue();
	return 0;
}


/* 测试表判空 */
void test_IsEmpty() {
	printf("测试表判空\n");
	List* plist = InitList();

	if (IsEmpty(plist)) {
		printf("链表为空！\n");
	}
	else {
		printf("链表非空！\n");
	}
}


/* 测试尾插法 */
void test_PushBack() {
	printf("测试尾插法\n");

	List* plist = InitList();

	for (int i = 1; i <= 10; i++) {
		PushBack(plist, 10 * i);
	}

	if (IsEmpty(plist)) {
		printf("链表为空！\n");
	}
	else {
		Print(plist);
	}
}


/* 测试链表遍历 */
void test_Print() {
	printf("测试链表遍历\n");

	List* plist = InitList();

	for (int i = 1; i <= 10; i++) {
		PushBack(plist, 10 * i);
	}

	if (IsEmpty(plist)) {
		printf("链表为空！\n");
	}
	else {
		Print(plist);
	}
}

/* 测试头插法 */
void test_PushFront() {
	printf("测试头插法\n");

	List* plist = InitList();

	for (int i = 1; i <= 10; i++) {
		PushBack(plist, 10 * i);
	}

	for (int i = 1; i <= 5; i++) {
		PushFront(plist,  i);
	}

	if (IsEmpty(plist)) {
		printf("链表为空！\n");
	}
	else {
		Print(plist);
	}
}

/* 测试尾删法 */
void test_PopBack() {
	printf("测试尾删法（1）\n");

	List* plist = InitList();

	for (int i = 1; i <= 10; i++) {
		PushBack(plist, 10 * i);
	}

	for (int i = 1; i <= 5; i++) {
		PushFront(plist, i);
	}

	if (IsEmpty(plist)) {
		printf("链表为空！\n");
	}
	else {
		Print(plist);
	}

	PopBack(plist);
	Print(plist);

	printf("测试尾删法（2）\n");

	List* pplist = InitList();

	PushBack(pplist, 10);
	if (IsEmpty(pplist)) {
		printf("链表为空！\n");
	}
	else {
		Print(pplist);
	}
	PopBack(pplist);
	if (IsEmpty(pplist)) {
		printf("链表为空！\n");
	}
	else {
		Print(pplist);
	}
}

/* 测试头删法 */
void test_PopFront() {
	printf("测试头删法（1）\n");

	List* plist = InitList();

	for (int i = 1; i <= 10; i++) {
		PushBack(plist, 10 * i);
	}

	for (int i = 1; i <= 5; i++) {
		PushFront(plist, i);
	}

	if (IsEmpty(plist)) {
		printf("链表为空！\n");
	}
	else {
		Print(plist);
	}

	PopFront(plist);
	Print(plist);

	printf("测试头删法（2）\n");

	List* pplist = InitList();

	PushBack(pplist, 10);
	if (IsEmpty(pplist)) {
		printf("链表为空！\n");
	}
	else {
		Print(pplist);
	}
	PopFront(pplist);
	if (IsEmpty(pplist)) {
		printf("链表为空！\n");
	}
	else {
		Print(pplist);
	}
}


/* 测试按值查找 */
void test_FindByValue() {
	printf("测试按值查找\n");

	List* plist = InitList();

	for (int i = 1; i <= 10; i++) {
		PushBack(plist, 10 * i);
	}

	if (IsEmpty(plist)) {
		printf("链表为空！\n");
	}
	else {
		Print(plist);
	}

	printf("查找目标：10（首元素）\n");

	printf("查询结果：%d\n" ,FindByValue(plist, 10)->data);

	printf("查找目标：100（尾元素）\n");
	printf("查询结果：%d\n", FindByValue(plist, 100)->data);


	printf("查找目标：60（其他元素）\n");
	printf("查询结果：%d\n", FindByValue(plist, 60)->data);



}