#include"Stack.h"

void test_Stack() {
	ST st;
	InitStack(&st);
	printf("��ջ���ԣ���ջ˳��");
	for (int i = 0; i < 6; i++) {
		printf("%d ", i + 1);
		StackPush(&st, i + 1);
	}
	printf("\n\n");
	printf("��ȡջ��Ԫ�ظ�����%d", StackSize(&st));
	printf("\n\n");

	printf("��ջ���ԣ���ջ˳��");
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