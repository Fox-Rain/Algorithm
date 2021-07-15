// 트리 (Tree)      <- 계층적인 구조를 표현한것으로  Ex) 조직도, 폴더구조,가계도 등 이 있다.
/*
트리는 노드들과 그 노드들을 연결하는 선인 링크로 구성된다.   맨위에 있는 한개밖에 없는 노드를  루트노드, 자식이없는 노드를 리프노드라고 부른다. 그외 내부노드는 인터널노드라고 부른다.
서브트리 <- 트리를 나눈 어느한 부분을 SubTree라고 부른다.     레벨 <- 노드들의 높이를 높은것부터 level 1, 2 , 3..
트리의 기본적인 성질    1. 노드가 n개인 트리는 n-1개의 링크를 갖는다.    2. 루트노드에서 임의의어떠한 노드로 가는 경로는 유일하다.  임이의 두노드간의 경로는 유일하다. (단, 노드들을 한번만 지난다고 가정시)

이진트리 (binary tree) //    <- 각 노드가 최대 2개의 자식을 갖는 트리를 말한다.    각각의 자식노드들은 부모기준으로 왼쪽인지 오른쪾인지에 따라 왼쪽자식, 오른쪽자식으로 구분이 된다. (자식노드가 1개일때도)
Full binary tree (모든 레벨에서 노드들이 꽉 차있는 트리)    <- 높이(level)이 h인 full binary tree는 노드의 개수가 2^h-1개이다.
Complete binary tree (마지막 레벨 말고는 모든 노드들이 꽉 차있는 트리 단, 마지막 레벨은 오른쪽부터 연속적으로만 비어있을 수 있다.)
노드의 개수가 n개인 full또는 complete binary tree인 이진트리의 높이는 O(logn)이다.

이진트리의 특징 부모의 index가 i 일경우 왼쪽자식은 2i, 오른쪽자식은 2i+1의 index를 갖게된다.

연결구조(link) 표현    <- 각노드에 하나의 데이터(데이터 필드)와 왼쪽자식의 주소,오른쪽자식의 주소,부모노드의 주소를 저장한다.   node[left data parents right]  
    				     부모노드는 생략하기도 함   (단, 루트노드의 경우 부모노드가없으므로 자신의 노드주소는 따로 저장해야한다.) * 루트노드를 잃어버리게된다면 모든 노드에 접근이 불가능해짐. (연결구조라)

이진트리의 순회 (traversal)     순회란? 이진트리의 모든 노드들을 방문하는 것을 말한다.	
순회방법으로는 중순위(inorder) 순회, 선순위(preorder) 순회, 후순위(postorder) 순회 그리고 레벨오더(level-order) 순회가 있다.
*/
#include<iostream>

using namespace std;

struct Node // Node 구조체
{
	int data; // 자기 데이터 
	Node *left; // 왼쪽 자식노드 포인터
	Node *right; // 오른쪽 자식노드 포인터
	Node *parent; // 부모노드 포인터
};

// 이진트리의-Inorder순회 //  Recursion Algorithm임
// 1. 루트노드(R), 루트노드의 왼쪽 서브트리(TL), 오른쪽 서브트리(TR)로 나눈다.    2. TL을 inorder로 순회    3. R을 순회   4. 마지막으로 TR을 inorder로 순회한다.

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

// Preorder 순회
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

// Postorder 순회
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

// levelorder   queue큐를 이용하여서 구현

int main()
{
	return 0;
}