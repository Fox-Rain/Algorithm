// Ʈ�� (Tree)      <- �������� ������ ǥ���Ѱ�����  Ex) ������, ��������,���赵 �� �� �ִ�.
/*
Ʈ���� ����� �� ������ �����ϴ� ���� ��ũ�� �����ȴ�.   ������ �ִ� �Ѱ��ۿ� ���� ��带  ��Ʈ���, �ڽ��̾��� ��带 ��������� �θ���. �׿� ���γ��� ���ͳγ���� �θ���.
����Ʈ�� <- Ʈ���� ���� ����� �κ��� SubTree��� �θ���.     ���� <- ������ ���̸� �����ͺ��� level 1, 2 , 3..
Ʈ���� �⺻���� ����    1. ��尡 n���� Ʈ���� n-1���� ��ũ�� ���´�.    2. ��Ʈ��忡�� �����Ǿ�� ���� ���� ��δ� �����ϴ�.  ������ �γ�尣�� ��δ� �����ϴ�. (��, ������ �ѹ��� �����ٰ� ������)

����Ʈ�� (binary tree) //    <- �� ��尡 �ִ� 2���� �ڽ��� ���� Ʈ���� ���Ѵ�.    ������ �ڽĳ����� �θ�������� �������� �����U������ ���� �����ڽ�, �������ڽ����� ������ �ȴ�. (�ڽĳ�尡 1���϶���)
Full binary tree (��� �������� ������ �� ���ִ� Ʈ��)    <- ����(level)�� h�� full binary tree�� ����� ������ 2^h-1���̴�.
Complete binary tree (������ ���� ����� ��� ������ �� ���ִ� Ʈ�� ��, ������ ������ �����ʺ��� ���������θ� ������� �� �ִ�.)
����� ������ n���� full�Ǵ� complete binary tree�� ����Ʈ���� ���̴� O(logn)�̴�.

����Ʈ���� Ư¡ �θ��� index�� i �ϰ�� �����ڽ��� 2i, �������ڽ��� 2i+1�� index�� ���Եȴ�.

���ᱸ��(link) ǥ��    <- ����忡 �ϳ��� ������(������ �ʵ�)�� �����ڽ��� �ּ�,�������ڽ��� �ּ�,�θ����� �ּҸ� �����Ѵ�.   node[left data parents right]  
    				     �θ���� �����ϱ⵵ ��   (��, ��Ʈ����� ��� �θ��尡�����Ƿ� �ڽ��� ����ּҴ� ���� �����ؾ��Ѵ�.) * ��Ʈ��带 �Ҿ�����Եȴٸ� ��� ��忡 ������ �Ұ�������. (���ᱸ����)

����Ʈ���� ��ȸ (traversal)     ��ȸ��? ����Ʈ���� ��� ������ �湮�ϴ� ���� ���Ѵ�.	
��ȸ������δ� �߼���(inorder) ��ȸ, ������(preorder) ��ȸ, �ļ���(postorder) ��ȸ �׸��� ��������(level-order) ��ȸ�� �ִ�.
*/
#include<iostream>

using namespace std;

struct Node // Node ����ü
{
	int data; // �ڱ� ������ 
	Node *left; // ���� �ڽĳ�� ������
	Node *right; // ������ �ڽĳ�� ������
	Node *parent; // �θ��� ������
};

// ����Ʈ����-Inorder��ȸ //  Recursion Algorithm��
// 1. ��Ʈ���(R), ��Ʈ����� ���� ����Ʈ��(TL), ������ ����Ʈ��(TR)�� ������.    2. TL�� inorder�� ��ȸ    3. R�� ��ȸ   4. ���������� TR�� inorder�� ��ȸ�Ѵ�.

void Inorder_Tree_Walk(Node *node)
{
	if (node->data == NULL)
		return;
	else
	{
		Inorder_Tree_Walk(node->left);
		cout << node->data << " ";
		Inorder_Tree_Walk(node->right);
	}
}

// Preorder ��ȸ
void Preorder_Tree_Walk(Node *node)
{
	if (node->data == NULL)
		return;
	else
	{
		cout << node->data << " ";
		Inorder_Tree_Walk(node->left);
		Inorder_Tree_Walk(node->right);
	}
}

// Postorder ��ȸ
void Postorder_Tree_Walk(Node *node)
{
	if (node->data == NULL)
		return;
	else
	{
		Inorder_Tree_Walk(node->left);
		Inorder_Tree_Walk(node->right);
		cout << node->data << " ";
	}
}

// levelorder   queueť�� �̿��Ͽ��� ����

int main()
{
	return 0;
}