#ifndef TREE_H
#define TREE_H

#include "single_linked_list.h"

struct tTreeNode
{
	void						* pTreeNodeData;
	struct tTreeNode			* pParent;
	struct tSingleLinkedList	* pChilds;
}

struct tTree
{
	struct tTreeNode * pRoot;
}

struct tTree * tree_init(void * pTreeRootData)
{
	struct tTree pTree = (struct tTreNode *)malloc(sizeof(struct tTree));
	pTree->root = NULL;
	return pTree;
}

struct tTreeNode * tree_get_root_node(struct tTree * pTree)
{
	return pTree->pRoot;
}

void tree_append_child(struct tTreeNode *pParentNode,void * pTreeNodeData)
{
	struct tTreeNode * pTreeNode = (struct tTreeNode *)malloc(sizeof(struct tTreeNode));
}

#endif
