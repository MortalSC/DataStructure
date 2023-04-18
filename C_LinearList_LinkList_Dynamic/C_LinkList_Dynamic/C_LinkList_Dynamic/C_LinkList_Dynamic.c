#include"C_LinkList_Dynamic.h"

/* ��ʼ��һ�������������ڱ����Ŀ����� */
/*
	�޲�����
	����ֵ��������ͣ���ʼ��һ���ձ�
*/
LstNode* InitLinkList() {
	LstNode* plist = NULL;
	return plist;
}

/* �½���㣺�˴�����ʹ��һ�������½���� */
/* 
	��������ָ����洢��ֵ
	����ֵ���������
*/
LstNode* CreateNode(DataType data) {
	/* 1. ��̬����ռ� */
	LstNode* pnode = (LstNode*)malloc(sizeof(LstNode));
	assert(pnode);			/* ����ڴ������Ƿ�ɹ� */

	/* 2. ��ʼ����������ָ���� */
	pnode->data = data;
	pnode->next = NULL;		/* һ��Ҫָ�����ÿ� */

	/* 3. ���ؽ�� */
	return pnode;
}

/* �����пգ��˴�ע�⣺C ������ʹ�� bool ���ͣ���Ҫ stdbool.h ͷ�ļ� */
/*
	������������ͣ���ȷ�ж϶��󣩣�
	����ֵ��bool ����
*/
bool IsEmpty(LstNode* pHead) {
	return pHead == NULL;	/* ֱ���ж�ͷ����Ƿ�Ϊ�ռ��� */
}


/* ����� */
/*
	������������ͣ���ȷ�������󣩣�
	�޷���ֵ��
*/
void ListPrint(LstNode* pHead) {
	/* 1. �жϱ���ӡ�����Ƿ�Ϊ�գ� */
	if (IsEmpty(pHead)) {
		printf("����Ϊ��\n");
		return;
	}
	/* 2. �����Ƿ��ʽ�㲢���ֵ */
	/* ����һ���α�ָ����ʽ�� */
	LstNode* current = pHead;
	printf("List: ");
	while (current) {
		printf("%d -> ", current->data);
		current = current->next;	/* �����ʸ��� */
	}
	printf("NULL\n");
}

/* β�巨 */
/*
	������������ͣ���ȷ�������󣩣�
	�޷���ֵ��

	�ѵ㣺�ձ��β�壡�漰����ָ�룡
	ԭ��ֱ�Ӵ��� LstNode* pHead �漰��������ʵ�κ��βε�����
*/
void LinkListPushBack(LstNode** pHead, DataType data) {
	/* 1. �½�һ����� */
	LstNode* pnode = CreateNode(data);
	/* 2. �ж�ԭ���Ƿ�Ϊ�� */
	if (IsEmpty(*pHead)) {
		/* ע��㣺
			void LinkListPushBack(LstNode* pHead, DataType data)
			��ֱ��ʹ��һ��ָ�룬�����ʵ�κ��βε����⣻
			pHead ���βΣ�����������������ˣ�
			pHead = pnode; ֻ�Ƕ��βθ�ֵ������Ӱ���ⲿʵ�� plist
			�ʴ�ʹ�ö���ָ���������⣡
		*/
		*pHead = pnode;
	}
	else {
		/* ԭ��ǿգ������α�ָ�븨������ */
		LstNode* current = *pHead;
		while (current->next) {	/* Ѱ��β��� */
			current = current->next;
		}
		current->next = pnode;	/* ������ */
	}
}

/* ͷ�巨 */
/*
	������������ͣ���ȷ�������󣩣�
	�޷���ֵ��

	�ѵ㣺�ձ��β�壡�漰����ָ�룡
	ԭ��ֱ�Ӵ��� LstNode* pHead �漰��������ʵ�κ��βε�����
*/
void LinkListPushFront(LstNode** pHead, DataType data) {
	/* 1. �½���� */
	LstNode* pnode = CreateNode(data);

	/* 2. ͷ������ */
	pnode->next = *pHead;		/* �½��ָ��ԭ���ͷ�ڵ� */
	*pHead = pnode;		/* �����½��Ϊ����ͷ��� */
	/*
		˵����Ϊʲô����Ҫ����ԭ���пգ�
		��Ϊ����ԭ���Ƿ�Ϊ�գ�ͷ�嶼ִ�� pnode->next = *pHead; �����½ڵ�ָ��ԭ��ͷ��㣻
		��ʱ����֪��ԭ��ͷ����Ƿ�Ϊ�գ��ò��趼�ǰ�ȫ�ġ�

		ע����⣺*pHead �����壺�Ǳ�ʶ����ͷ����ָ�롣
	*/
}

/* βɾ�� */
void LinkListPopBack(LstNode** pHead) {
	/* 1. �жϲ�������ĺϷ��ԣ��ձ� */
	assert(*pHead);	/* �ǿ��򱨴� */
	/*
		ע�⣺
			1. assert(); ��ʹ��ǿ���ʹ�����飨�ձ���
			2. ����ʹ�� if() ���򵥴�����飨�ձ�+�����Ի�����ʾ��
	*/

	/* 2. βɾ�� */
	/* ע�⣺��Ҫά�������α�ָ�룺�ҵ������ڶ������ */
	LstNode* del = *pHead;
	if (del->next) {					/* ��������� ���ڵ��� 2 */
		del = del->next;
		LstNode* delPrev = *pHead;
		while (del->next) {				/* Ѱ������������ */
			del = del->next;
			delPrev = delPrev->next;
		}
		delPrev->next = NULL;
		free(del);
	}
	else {								/* ���������Ϊ��1 */
		*pHead = NULL;
	}

}

/* ͷɾ�� */
void LinkListPopFront(LstNode** pHead) {
	/* 1. �жϲ�������ĺϷ��ԣ��ձ� */
	assert(*pHead);	/* �ǿ��򱨴� */
	/*
		ע�⣺
			1. assert(); ��ʹ��ǿ���ʹ�����飨�ձ���
			2. ����ʹ�� if() ���򵥴�����飨�ձ�+�����Ի�����ʾ��
	*/

	/* 2. ͷɾ�� */
	LstNode* current = (*pHead)->next;
	free(*pHead);		/* �ͷſռ� */
	*pHead = current;
}


/* ��� */
int GetLength(LstNode* pHead) {
	if (IsEmpty(pHead)) return 0;
	int res = 0;
	LstNode* current = pHead;
	while (current) {
		res++;
		current = current->next;
	}
	return res;
}

/* ��ֵ���ң����ؽ�� */
/*
	��������������Ŀ��ֵ
	����ֵ��Ŀ���� / NULL
*/
LstNode* FindByValue(LstNode* pHead, DataType data) {
	/* 1. �жϲ�������ĺϷ��ԣ��ձ� */
	if (IsEmpty(pHead)) return NULL;

	/* 2. �����α���в��� */
	LstNode* current = pHead;
	while (current) {
		if (current->data == data) return current;
		current = current->next;
	}
	return NULL;
}


/* ����ָ��λ�ã����ؽ�� */
/*
	��������������ָ��λ�á�λ�Ρ�
	����ֵ��Ŀ���� / NULL

	˵����ע�� ָ��λ�õĺϷ���
*/
LstNode* FindByPos(LstNode* pHead, int pos) {
	/* 1. �жϲ�������ĺϷ��ԣ��ձ� */
	if (IsEmpty(pHead)) return NULL;
	
	if (pos < 0 || pos > GetLength(pHead)) {
		printf("ָ��λ�ò��Ϸ���\n");
		return NULL;
	}
	LstNode* current = pHead;
	for (int i = 0; i < pos-1; i++) {
		current = current->next;
	}
	return current;
}

/* ����ָ��λ��֮����룺ע��ʵ��ʹ���У��÷�ʽЧ��� */
/*
	��������������ָ��λ�á�λ�Ρ�������ֵ
	����ֵ����
	˵����
		ע��:	1. ָ��λ�õĺϷ���
				2. ָ��λ�ò��������д����
				2.1 ������λ����[1,GetLength(plist)]֮��ʱ������ͷ���β�壻
				2.2 �޶�ֻ���ںϷ�λ���ڲ��룻�����½�ʵ�ָ������
*/
void InsertPos(LstNode** pHead, int pos, DataType data) {
	/* 1. �Ϸ��Լ��� */
	assert(*pHead);
	assert(pos > 0 && pos <= GetLength(*pHead));

	/* 2. ���룺�����α�ָ��ʵ�� */
	/* �½���� */
	LstNode* pnode = CreateNode(data);

	/* ʹ��ѭ���ҵ�ָ�������λ�� */
	LstNode* current = *pHead;
	for (int i = 0; i < pos - 1; i++) {
		current = current->next;
	}
	pnode->next = current->next;
	current->next = pnode;
}

/* ɾ��ָ��λ���ϵ�ֵ */
/*
	��������������ָ��λ�á�λ�Ρ�
	����ֵ�����
	˵����
		ע��:	1. ָ��λ�õĺϷ���
				2. ָ��λ�ò��������д����
				2.1 ��ɾ��λ����[1,GetLength(plist)]֮��ʱ������ͷɾ��βɾ��
				2.2 �޶�ֻ���ںϷ�λ����ɾ���������½�ʵ�ָ������
*/
LstNode* DelPos(LstNode** pHead, int pos) {
	/* 1. �Ϸ��Լ��� */
	assert(*pHead);
	assert(pos > 0 && pos <= GetLength(*pHead));

	/* ʹ��ѭ���ҵ�ָ��ɾ����λ�� */
	LstNode* current = *pHead;
	if (GetLength(*pHead) == 1) {
		free(*pHead);
		*pHead = NULL;
		return current;
	}
	else {
		LstNode* prev = *pHead;
		if (pos == 1) {
			*pHead = (*pHead)->next;
			return prev;
		}
		else {
			for (int i = 0; i < pos - 1; i++) {
				current = current->next;
			}

			while (prev->next != current) {
				prev = prev->next;
			}
			prev->next = current->next;
			return current;
		}
	}
}