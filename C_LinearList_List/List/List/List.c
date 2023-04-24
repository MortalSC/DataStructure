#include "List.h"

/* ��ʼ��һ��˫���� */
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

/* ������� */
List* CreateNode(DataType data) {
	List* node = (List*)malloc(sizeof(List));
	assert(node);
	node->next = NULL;
	node->prev = NULL;
	node->data = data;
	return node;
}

/* ���п� */
bool IsEmpty(List* phead) {
	return (phead->next == phead);
}

/* ��ȡ�� */
int GetSize(List* phead) {
	if (IsEmpty(phead)) return 0;
	int size = 0;
	List* cur = phead->next;
}


/* ������ */
void Print(List* phead) {
	if (IsEmpty(phead)) return;

	List* cur = phead->next;
	printf("List��");
	while (cur != phead) {
		printf("%d -> ", cur->data);
		cur = cur->next;
	}
	printf("\n");

}

/* β�巨 */
void PushBack(List* phead, DataType data) {
	assert(phead);

#if 0
	List* node = CreateNode(data);
	/*
		ע��㣺β�巨�ȼ������ڱ����֮ǰ������
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


/* ͷ�巨 */
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

/* βɾ�� */
void PopBack(List* phead) {
	assert(phead && phead->next != phead);
#if 0
	List* node = phead->prev;				/* ָ��β��� */
	node->prev->next = phead;			/* β����ǰһ�����ָ���ڱ���� */
	phead->prev = node->prev;			/* �ڱ�����ǰָ��ָ�����ڶ������ */
	free(node);
#else
	EarsePos(phead->prev);
#endif
}

/* ͷɾ�� */
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


/* ָ�����֮ǰ���� */
void InsertPos(List* pos, DataType data) {
	assert(pos);

	List* node = CreateNode(data);			// �����½��
	node->next = pos;
	pos->prev->next = node;
	node->prev = pos->prev;
	pos->prev = node;
}

/* ɾ��ָ����� */
void EarsePos(List* pos) {
	assert(pos);

	List* prev = pos->prev;
	List* next = pos->next;

	prev->next = next;
	next->prev = prev;
	free(pos);
}


/* ��ֵ��ѯ���� */
List* FindByValue(List* phead, DataType data) {
	if (IsEmpty(phead)) return NULL;				// �ձ���

	// �ǿղ����������α�ָ�븨����ѯ��˫���������ǰ��Ҳ�����飬ֻ��ע��ѭ���������ɣ�
	List* cur = phead->next;
	while (cur != phead) {
		if (cur->data == data) return cur;
		cur = cur->next;
	}
	return NULL;
}