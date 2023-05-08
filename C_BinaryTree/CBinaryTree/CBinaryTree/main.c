#include"CBinaryTree.h"

/*
	注：二叉树可以使用顺序存储方式表示，但一般仅用于表示完全二叉树！！！
	在算法比赛中一般会使用顺序存储方式：空间换时间（可以使用下标访问结点，查询效率高！）

	本篇使用 C 语言实现链式二叉树（一般实现方式）
	注：普通二叉树的增删查改没有多大意义！！！

	本篇将实现二叉树的前中后序遍历！！！ 【 注：遍历过程中，空结点打印：# 标识 】
	测试用例直接“手搓”。

	二叉树的前中后序遍历：记忆方式：前中后描述的是 root 结点的打印次序；左右子节点始终有序；
	前序遍历：中左右；
	中序遍历：左中右；
	后序遍历：左右中；
*/

/* 测试手搓测试实例 */
BTNode* create_BTree() {
	BTNode* root = CreateNode(0);
	BTNode* node1 = CreateNode(1);
	BTNode* node2 = CreateNode(2);
	BTNode* node3 = CreateNode(4);
	BTNode* node4 = CreateNode(3);
	BTNode* node5 = CreateNode(5);
	BTNode* node6 = CreateNode(6);

	/*	实例结构：
						1
				2				4
			3		空		5		6
		空	空			空	空		空	空
	*/

	root = node1;
	node1->leftChild = node2;
	node2->leftChild = node4;
	node1->rightChild = node3;
	node3->leftChild = node5;
	node3->rightChild = node6;
	return root;
}



int main() {
	BTNode* root = create_BTree();

	PreOrder(root);
	printf("\n");

	InOrder(root);
	printf("\n");

	PostOrder(root);
	printf("\n");

	return 0;
}