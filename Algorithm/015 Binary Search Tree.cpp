// �����˻�Ʈ�� Binary Search Tree
/*
Dynamic set ?    �������� Ű�� �����ϸ�  Insert, Search, Delete ������ �����ϴ� �ڷᱸ���� ���Ѵ�.    (�迭, ���Ḯ��Ʈ.....)

���� Ȥ�� ���ĵ������� �迭/���Ḯ��Ʈ�� �̿��� ��� Insert, Search, Delete �� ��� �ϳ��� �ð����⵵�� O(N)�̴�.

�˻�Ʈ���� Dynaic Set�� Ʈ�����·� �����Ѱ�����, �Ϲ������� Insert, Search, Delete ������ Ʈ�����̿� ����ϴ� �ð����⵵�� ���´�.  �����δ� �����˻�Ʈ��, �����Ʈ��, B-Ʈ�� ���� �ִ�.
*/

// �����˻�Ʈ�� (Binary Search Tree)��?  1. ����Ʈ���̸鼭  2. ����忡 �ϳ��� �����͸� �����ϸ�  3. �����鿡 ���� �׳���� ���ʺ�Ʈ���� �����͵��� �׳���� �����ͺ��� �۰ų����� �����ʺ�Ʈ������ ũ�ų� ����.  
// *** �����˻�Ʈ���� �� Complete Binary Tree�� �ʿ䰡 ����. (��� ������ ���������� ������ �ʿ䰡 ����), ���� �ٸ������� ���� �θ𺸴� ������ �ڽĳ����� �۾ƾ�������( max property), �����˻�Ʈ���� �ٸ���.


#include<iostream>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
	Node *parent;
};

// Search
Node &Tree_Search(Node *node, int key) // Binary Tree Search        <Recursion>         �ð����⵵�� O(h)  h�� Ʈ���� �����̴�.  ��, �־��� ���⵵�� O(n)�� �� �� �ִ�.  (Ʈ���� ���� 1�ڷ� �� ������)
{                                     //                                                                                          �ֳ��ϸ�, binaryTree�� �� complete binary �� �ʿ䰡 �����Ƿ�
	if (node->data == NULL) // �����Ͱ� ����� ��� ����
		return;
	else if (node->data == key) // �����Ͱ� key�� ��� �� ��带 ���۷����� ����
		return *node;
	else if (key > node->data)
		Tree_Search(node->right, key);
	else if (key < node->data)
		Tree_Search(node->left, key);
}

// Minimun Search
Node *Tree_Minimun(Node *node) // Binary Tree Minimun    �ð����⵵�� O(h) <-������    ����Ʈ�������� �ּҰ��� ������ ������ ���� �������� �ȴ�. (���� ��ü�� ������ ū��, �������� ���������� �Ǿ������Ƿ�)
{
	Node *minimunNode = node; // return ��� ������
	while (minimunNode->left != nullptr) // ����� �����ڽ��� ���� �� ���� ������
		minimunNode = minimunNode->left;
	return minimunNode; // �ּҰ���带 �����ͷ� ����
}

// Maximun Search
Node *Tree_Maximun(Node *node) // Binary Tree Maximun    �ð����⵵�� O(h) <-������    ����Ʈ�������� �ִ밪�� ������ �������� ���� �������� �ȴ�. (���� ��ü�� ������ ū��, �������� ���������� �Ǿ������Ƿ�)
{
	Node *maximunNode = node; // return ��� ������
	while (maximunNode->right != nullptr) // ����� �������ڽ��� ���� �� ���� ������
		maximunNode = maximunNode->right;
	return maximunNode; // �ִ밪��带 �����ͷ� ����
}

// Successor Search
/*   Successor�� 3���� ���
	 1. ��� x�� ������ ��Ʈ���� ������ ���, ������ ��Ʈ���� �ּҰ�
	 2. ��� x�� ������ ��Ʈ���� ���� ���, �θ� ���� ��Ʈ�������� �ö󰡴ٰ� ó������ �������� ���� �ڽ��� �Ǵ� ����� ��尡 Successor   (��, ó������ ��ũ�� �������� ���̴� ����� �θ� ��尡 successor�̴�.)
	 3. 1��2�� �ش��ϴ°��� �Ѵ� ���ٸ� ����ü x��尡 �ִ밪�̴�. (��, Successor�� �������� ����)
*/

// Successor Search
Node *Successor_Search(Node *node) // Binary Tree Successor     �ð����⵵ O(h)       node�� data������ ũ�鼭 �������� data�� ���� ���(�������)�� ã�� �� (��, ������ ���� ��� �ٸ��ٰ� ����)
{
	// 1 case �� ���
	if (node->right != nullptr) // ������ �ڽ� �����J ���  
		Tree_Minimun(node->right); // ������ ��Ʈ���� �ּҰ� ã�Ƽ� ����
	// 2 case
	else if (node->right == nullptr) // ������ �ڽ��� �������� ���� ���
	{
		Node *presentNode;
		while (presentNode->data <= presentNode->parent->data) // �θ��尡 �ڽĳ�庸�� Ŀ���� ��찡 �Ͼ �� ����
		{
			if (presentNode->parent->data == NULL) // ���� ��Ʈ��忡 �������� ��� (��, ������ Ŀ���� ��찡 �Ͼ�� ���� ��)
				return nullptr; // nullptr ����
			presentNode = presentNode->parent;
		}
		return presentNode;
	}
}

// Predecessor 
Node *Predecessor_Search(Node *node) // Binary Tree Predecessor   �ð����⵵ O(h)     node�� data������ �����鼭 ����ū data�� ���� ��带 ã�� �� (��, ��尪���� �� �ٸ��ٰ� ����)
{
	// 1 case �� ���
	if (node->left != nullptr) // ���� �ڽ� �����J ���  
		Tree_Maximun(node->right); // ���� ��Ʈ���� �ִ밪 ã�Ƽ� ����
	// 2 case
	else if (node->left == nullptr) // ���� �ڽ��� �������� ���� ���
	{
		Node *presentNode;
		while (presentNode->data <= presentNode->parent->data) // �θ��尡 �ڽĳ�庸�� �۾����� ��찡 �Ͼ �� ����
		{
			if (presentNode->parent->data == NULL) // ���� ��Ʈ��忡 �������� ��� (��, ������ �۾����� ��찡 �Ͼ�� ���� ��)
				return nullptr; // nullptr ����
			presentNode = presentNode->parent;
		}
		return presentNode;
	}
}

// Insert
void *Insert_Node(Node *insertNode, Node *node) // �߰��� ��� �� ��Ʈ��� �����͸� ����    �ð����⵵ O(h)
{
	Node *CompareNode = node;
	while (node != nullptr) // ���� ��尡 ���� ������
	{
		if (CompareNode->data > insertNode->data)
		{
			if (CompareNode->left != nullptr)
				CompareNode = CompareNode->left;
			else
			{
				// �̰��� insert insertNode
				return;
			}
		}
		else
		{
			if (CompareNode->right != nullptr)
				CompareNode = CompareNode->right;
			else
			{
				// �̰��� insert insertNode
				return;
			}
		}
	}
}

// Delete		// ���� https://www.delftstack.com/ko/tutorial/data-structure/binary-search-tree-delete/
/*
	C1 �����Ϸ��� ��尡 �ڽĳ�带 ���������� ���� ��� -> �׳ɻ���
	C2 �����Ϸ��� ��尡 �ڽĳ�� 1���� �������ִ� ���  -> �����Ϸ��� ����� �ڽĳ�带 ���� �ڽ��� ��ġ�� �Ű� ������ �ֱ⸸ �ϸ� �ȴ�.
	C3 �����Ϸ��� ��尡 �ڽĳ�� 2���� �������ִ� ���  -> �����Ϸ��� ����� �����͸� ������ �ϰ� �����Ϸ��³������� ���(Successor)�� ������ �����Ѵ�. -> (Recursion)���� successor�� �����ϸ鼭 �ٽ� case�з�...
*/

void Tree_Delete(Node*node) // ������ ��带 ���������ڷ� �޾ƿ�   (������ �����ʹ� Tree_Search�� ã�Ƽ� �����´�.)
{
	if (node->left == NULL && node->right == NULL) // �ڽĳ�带 ���������� ���� ���
		node->parent = NULL;
	else if (node->left != NULL && node->right != NULL) // �ڽĳ�带 2�� ���� ���
	{
		Node *targetNode;
		targetNode = Successor_Search(node); // ������ ��Ʈ������ ���� ���� Node �����͸� ������      ( Successor Node)
		Tree_Delete(targetNode); // Recursion    ��Ŀ���Ͽ��� targetNode�� �ڽĳ�带 1������(camp)�� ���Ե� ������ �ݺ�
	}
	else
	{
		if (node->left != NULL) // ���� �ڽĳ�常 ���� ���
		{
			if (node->parent->left == node)
				node->parent->left - node->left;
			if (node->parent->right == node)
				node->parent->right = node->left;
		}
		else if (node->right != NULL) // ������ �ڽĳ�常 ���� ���
		{
			if (node->parent->left == node)
				node->parent->left - node->right;
			if (node->parent->right == node)
				node->parent->right = node->right;
		}
	}
}

int main()
{

	return 0;
}