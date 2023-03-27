#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

typedef struct node
{
	int key;
	struct node *lchild, *rchild;
}Node, *BST; // 这里BST相当于 node*  

// 在给定的BST中插入element,使之成为新的BST 
//指针也是按照值传递的，这样就会导致一个问题，当我们使用值传递的时候，
//如果我们在函数中修改了指针变量的指向，当函数退出时这种影响不会保留。
bool BSTInsert(Node* &p, int element)
{
	if(p == NULL) // 新建节点 
	{
		p = new Node;
		p->key = element;
		p->lchild = p->rchild = NULL;
		return true;
	}
	
	if(element == p->key)	return false;
	
	if(element < p->key)
		return BSTInsert(p->lchild, element);
		
	return BSTInsert(p->rchild, element);
}

// 创建BST 
void createBST(Node* &T, int a[], int n)
{
	T = NULL;
	for(int i = 0; i < n; i++)
	{
		BSTInsert(T, a[i]);
	}
}

// 二叉树查找1
Node *BST_Search(Node* T, int key)
{
	while(T != NULL && key != T->key)
	{
		if(key < T->key)	T = T->lchild;
		else T = T->rchild;	
	}
	return T;
} 

// 二叉树查找2 递归
Node *BSTSearch(Node* T, int key)
{
	if(T == NULL)	return NULL;
	if(T->key == key)	return T;
	else if(T->key < key)	return BSTSearch(T->rchild, key);
	return BSTSearch(T->lchild, key);
} 

// 中序遍历
void InOrder(Node* T)
{
	if(T != NULL)
	{
		InOrder(T->lchild);
		printf("%d\n", T->key);
		InOrder(T->rchild);
	}
} 

int main()
{
	int a[6] = {6, 2, 8, 1, 4, 3};
	int n = 6;
	BST T = NULL;
	createBST(T, a, n);
//	InOrder(T); // 输出 123468 
//	Node *res = BST_Search(T, 4);
	Node *res = BSTSearch(T, 4);
	if(res != NULL)	cout << "找到了该元素！" << res->key << endl;
	else	cout << "未找到该元素" << endl;
	return 0;
}

