#pragma

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

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

typedef int DataType;					// 自定义数据类型
	
typedef struct BinaryTreeNode {
	DataType data;
	struct BinaryTreeNode* leftChild;			// 左孩子结点
	struct BinaryTreeNode* rightChild;		// 右孩子结点
}BTNode;

/* 创建二叉树结点 */
BTNode* CreateNode(DataType data);

/* 前序遍历：中左右 */
void PreOrder(BTNode* root);

/* 中序遍历：左中右 */
void InOrder(BTNode* root);

/* 后序遍历：左右中 */
void PostOrder(BTNode* root);