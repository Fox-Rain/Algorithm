// Red-Black Tree     �����Ʈ��
/*
	�����Ʈ����  �����˻�Ʈ������ �־������ ����==������ �Ǵ� ��츦 ���ֱ� ���� ������ Ʈ���̴�.  <Ʈ���� balance�� ���������ʵ��� ���߾��� Ʈ��>

	����Ž��Ʈ���� ��������  "�������� Ʈ��"�� ���̰� O(logN)
	*** Insert, Serach, Delete ������ �־��� ��쿡�� O(logN)�ð��� �����Ѵ�.

	Red Black Tree
		* �������� �ϳ��ǵ�����, �����ڽ�, �������ڽ�, �θ����� �ּҸ� �������ִ�.
		* �ڽĳ�尡 ������������ ��� �ڽĳ���� NIL��带 �������ִٰ� �����Ѵ�. <--- *****
		* ���� �������� ��� NIL��尡 �ȴ�.  (�ڽ��̾�� �ڽĳ�带 NIL�����Ѵٰ��Ͽ��Ƿ�, ������ ������ NIL����� �� �ۿ�)
		* ��Ʈ�� �θ��嵵 NIL����� �����Ѵ�.
		* ���� ������ ���γ��� NIL���� �з��Ͽ� �����Ѵ�.

	������������ �����ϴ� ����Ž��Ʈ���� "�����Ʈ��"��� �Ѵ�.
		1. �������� Red Ȥ�� Black �̴�
		2. ��Ʈ���� Black���� �����Ǿ��ִ�.
		3. ��� ���������� Black�̴�.
		4. Red������ �ڽĳ����� ���� Black�̴�. (��, Red������ ���ӵǾ� �������� �ʴ´�.)
		5. ����忡 ���ؼ� �� ��忡�� �ڼ��� ���������� �̸��� ��� ��ο��� ������ ������ Black��尡 �����Ѵ�.

	����� ���̴� �ڽ����κ��� ������������ ���� �� ��ο� ���ԵǴ� ������ �����̴�.
	����� �����̴� �ڽ����κ��� ������������ ��λ��� ������� �����̴�.

	* ���̰� h�� ����� ��-���̴� bh >= h/2 �̴�.
		* ���� 4���� ���� ������� ���ӵ� �� ���� ����

	* ��� x�� ��Ʈ���ϴ� ������ ��Ʈ���� ��� 2^bh(x)-1 ���� ���γ�带 �����Ѵ�.

	*  n���� ���γ�带 ������ �����Ʈ���� ���̰� 2log(n+1)�����̴�.
		* n >= 2^(hb)-1 >= 2^(h/2)-1 �̹Ƿ�,  ���⼭ bh, h�� ���� ��v����� ��-���̿�  ���� �̴�.

	*/

#include<iostream>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
	Node *parent;
};

// Red-Black Tree Search    ==    Binary Search   ������ ����Ž���� ���� �˰����� ����Ѵ�.

// Left and Right Rotation       (delete, insert ������ �ϱ����� �⺻ ���� �˰���      �ѳ�带 �߽����� �κ������� ��带 �����ϴ� �˰���)                   ���� https://ict-nroo.tistory.com/70
// �ð����⵵�� O(1) ����ð��̸�,  ���ȿ����� ���� ��尡 �κ������� �ٲ� "����Ž��Ʈ��"�� Ư���� �����Ѵ�. (��, ����Ž��Ʈ���� ���� ���� ũ����´� �����ȴ�.)

void leftRotate(Node *targetNode)
{
	if (targetNode->parent->left == targetNode) // targetNode�� �θ��� ���� �ڽ��� ���
	{
		Node *temp;
		temp = targetNode->parent;
		targetNode->parent = targetNode->right;
		temp->left = targetNode->parent;
		targetNode->parent->parent = temp;
		temp = targetNode->parent->right;
		targetNode->parent->right == targetNode;
		targetNode->right = temp;
		temp->parent = targetNode;
	}
	else if (targetNode->parent->right == targetNode) // targetNode�� �θ��� ������ �ڽ��� ���
	{

	}
}


int main()
{
	return 0;
}