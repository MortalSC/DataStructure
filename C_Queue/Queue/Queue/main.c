#include"link_queue.h"

void test() {
	Queue queue;
	QueueInit(&queue);

	printf("�����пղ��ԣ�");
	if (IsEmpty(&queue)) printf("����Ϊ��\n");
	else printf("���зǿ�\n\n");
	printf("��ǰ����Ԫ�ظ�����%d\n\n", Size(&queue));


	printf("��Ӳ��ԣ�\n");
	for (int i = 0; i < 10; i++) Push(&queue, i * 10);

	printf("��ǰ����Ԫ�ظ�����%d\n\n", Size(&queue));


	printf("��ȡ��ͷԪ�أ�%d\n\n", ElemBack(&queue));
	printf("��ȡ��βԪ�أ�%d\n\n", ElemFront(&queue));

	printf("����ɾ��Ԫ�أ�ɾ����������\n");
	for (int i = 0; i < 3; i++) {
		printf("ɾ��Ԫ�أ�%d\n", ElemFront(&queue));
		Pop(&queue);
	}
	printf("��ǰ����Ԫ�ظ�����%d\n\n", Size(&queue));


	printf("�������ٶ��У�\n");
	Destory(&queue);
	printf("��ǰ����Ԫ�ظ�����%d\n\n", Size(&queue));




}

int main() {
	test();

	return 0;
}