#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

typedef struct node
{
	int key;
	struct node *lchild, *rchild;
}Node, *BST; // ����BST�൱�� node*  

// �ڸ�����BST�в���element,ʹ֮��Ϊ�µ�BST 
//ָ��Ҳ�ǰ���ֵ���ݵģ������ͻᵼ��һ�����⣬������ʹ��ֵ���ݵ�ʱ��
//��������ں������޸���ָ�������ָ�򣬵������˳�ʱ����Ӱ�첻�ᱣ����
bool BSTInsert(Node* &p, int element)
{
	if(p == NULL) // �½��ڵ� 
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

// ����BST 
void createBST(Node* &T, int a[], int n)
{
	T = NULL;
	for(int i = 0; i < n; i++)
	{
		BSTInsert(T, a[i]);
	}
}

// ����������1
Node *BST_Search(Node* T, int key)
{
	while(T != NULL && key != T->key)
	{
		if(key < T->key)	T = T->lchild;
		else T = T->rchild;	
	}
	return T;
} 

// ����������2 �ݹ�
Node *BSTSearch(Node* T, int key)
{
	if(T == NULL)	return NULL;
	if(T->key == key)	return T;
	else if(T->key < key)	return BSTSearch(T->rchild, key);
	return BSTSearch(T->lchild, key);
} 

// �������
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
//	InOrder(T); // ��� 123468 
//	Node *res = BST_Search(T, 4);
	Node *res = BSTSearch(T, 4);
	if(res != NULL)	cout << "�ҵ��˸�Ԫ�أ�" << res->key << endl;
	else	cout << "δ�ҵ���Ԫ��" << endl;
	return 0;
}

