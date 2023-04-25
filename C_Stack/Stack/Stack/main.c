#include"Stack.h"

void test_Stack() {
	ST st;
	InitStack(&st);
	printf("入栈测试：入栈顺序：");
	for (int i = 0; i < 6; i++) {
		printf("%d ", i + 1);
		StackPush(&st, i + 1);
	}
	printf("\n\n");
	printf("获取栈中元素个数：%d", StackSize(&st));
	printf("\n\n");

	printf("出栈测试：出栈顺序：");
	while (!IsEmpty(&st)) {
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n\n");
}

int main() {

	test_Stack();

	return 0;
}