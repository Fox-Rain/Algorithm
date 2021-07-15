// 이진검색트리 Binary Search Tree
/*
Dynamic set ?    여러개의 키를 저장하며  Insert, Search, Delete 연산을 지원하는 자료구조를 말한다.    (배열, 연결리스트.....)

정렬 혹은 정렬되지않은 배열/연결리스트를 이용할 경우 Insert, Search, Delete 중 적어도 하나는 시간복잡도가 O(N)이다.

검색트리는 Dynaic Set을 트리형태로 구현한것으로, 일반적으로 Insert, Search, Delete 연산이 트리높이에 비례하는 시간복잡도를 갖는다.  종류로는 이진검색트리, 레드블랙트리, B-트리 등이 있다.
*/

// 이진검색트리 (Binary Search Tree)란?  1. 이진트리이면서  2. 각노드에 하나의 데이터를 저장하며  3. 각노드들에 대해 그노드의 왼쪽부트리의 데이터들은 그노드의 데이터보다 작거나같고 오른쪽부트리들은 크거나 같다.  
// *** 이진검색트리는 꼭 Complete Binary Tree일 필요가 없다. (모든 노드들이 순차적으로 차있을 필요가 없음), 힙과 다른점으로 힙은 부모보다 무조건 자식노드들이 작아야하지만( max property), 이진검색트리는 다르다.


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
Node &Tree_Search(Node *node, int key) // Binary Tree Search        <Recursion>         시간복잡도는 O(h)  h는 트리의 높이이다.  즉, 최악의 복잡도는 O(n)이 될 수 있다.  (트리가 만약 1자로 쭉 나열시)
{                                     //                                                                                          왜냐하면, binaryTree는 꼭 complete binary 일 필요가 없으므로
	if (node->data == NULL) // 데이터가 비었을 경우 종료
		return;
	else if (node->data == key) // 데이터가 key일 경우 그 노드를 래퍼런스로 리턴
		return *node;
	else if (key > node->data)
		Tree_Search(node->right, key);
	else if (key < node->data)
		Tree_Search(node->left, key);
}

// Minimun Search
Node *Tree_Minimun(Node *node) // Binary Tree Minimun    시간복잡도는 O(h) <-무조건    이진트리에서의 최소값은 무조건 왼쪽을 따라 내려가면 된다. (정렬 자체가 왼쪽은 큰것, 오른쪽은 작은것으로 되어있으므로)
{
	Node *minimunNode = node; // return 노드 포인터
	while (minimunNode->left != nullptr) // 노드의 왼쪽자식이 없을 때 까지 내려감
		minimunNode = minimunNode->left;
	return minimunNode; // 최소값노드를 포인터로 리턴
}

// Maximun Search
Node *Tree_Maximun(Node *node) // Binary Tree Maximun    시간복잡도는 O(h) <-무조건    이진트리에서의 최대값은 무조건 오른쪽을 따라 내려가면 된다. (정렬 자체가 왼쪽은 큰것, 오른쪽은 작은것으로 되어있으므로)
{
	Node *maximunNode = node; // return 노드 포인터
	while (maximunNode->right != nullptr) // 노드의 오른쪽자식이 없을 때 까지 내려감
		maximunNode = maximunNode->right;
	return maximunNode; // 최대값노드를 포인터로 리턴
}

// Successor Search
/*   Successor의 3가지 경우
	 1. 노드 x의 오른쪽 부트리가 존재할 경우, 오른쪽 부트리의 최소값
	 2. 노드 x의 오른쪽 부트리가 없을 경우, 부모를 따라 루트방향으로 올라가다가 처음으로 누군가의 왼쪽 자식이 되는 경우의 노드가 Successor   (즉, 처음으로 링크가 왼쪽으로 꺾이는 경우의 부모 노드가 successor이다.)
	 3. 1과2의 해당하는것이 둘다 없다면 그자체 x노드가 최대값이다. (즉, Successor가 존재하지 않음)
*/

// Successor Search
Node *Successor_Search(Node *node) // Binary Tree Successor     시간복잡도 O(h)       node의 data값보다 크면서 가장작은 data를 가진 노드(다음노드)를 찾는 것 (단, 노드들의 값은 모두 다르다고 가정)
{
	// 1 case 의 경우
	if (node->right != nullptr) // 오른쪽 자식 존재핲 경우  
		Tree_Minimun(node->right); // 오른쪽 부트리의 최소값 찾아서 리턴
	// 2 case
	else if (node->right == nullptr) // 오른쪽 자식이 존재하지 않을 경우
	{
		Node *presentNode;
		while (presentNode->data <= presentNode->parent->data) // 부모노드가 자식노드보다 커지는 경우가 일어날 때 까지
		{
			if (presentNode->parent->data == NULL) // 만약 루트노드에 도착했을 경우 (즉, 끝까지 커지는 경우가 일어나지 않을 때)
				return nullptr; // nullptr 리턴
			presentNode = presentNode->parent;
		}
		return presentNode;
	}
}

// Predecessor 
Node *Predecessor_Search(Node *node) // Binary Tree Predecessor   시간복잡도 O(h)     node의 data값보다 작으면서 가장큰 data를 가진 노드를 찾는 것 (단, 노드값들은 다 다르다고 가정)
{
	// 1 case 의 경우
	if (node->left != nullptr) // 왼쪽 자식 존재핲 경우  
		Tree_Maximun(node->right); // 왼쪽 부트리의 최대값 찾아서 리턴
	// 2 case
	else if (node->left == nullptr) // 왼쪽 자식이 존재하지 않을 경우
	{
		Node *presentNode;
		while (presentNode->data <= presentNode->parent->data) // 부모노드가 자식노드보다 작아지는 경우가 일어날 때 까지
		{
			if (presentNode->parent->data == NULL) // 만약 루트노드에 도착했을 경우 (즉, 끝까지 작아지는 경우가 일어나지 않을 때)
				return nullptr; // nullptr 리턴
			presentNode = presentNode->parent;
		}
		return presentNode;
	}
}

// Insert
void *Insert_Node(Node *insertNode, Node *node) // 추가할 노드 와 루트노드 포인터를 받음    시간복잡도 O(h)
{
	Node *CompareNode = node;
	while (node != nullptr) // 비교할 노드가 없을 때까지
	{
		if (CompareNode->data > insertNode->data)
		{
			if (CompareNode->left != nullptr)
				CompareNode = CompareNode->left;
			else
			{
				// 이곳에 insert insertNode
				return;
			}
		}
		else
		{
			if (CompareNode->right != nullptr)
				CompareNode = CompareNode->right;
			else
			{
				// 이곳에 insert insertNode
				return;
			}
		}
	}
}

// Delete		// 참고 https://www.delftstack.com/ko/tutorial/data-structure/binary-search-tree-delete/
/*
	C1 삭제하려는 노드가 자식노드를 가지고있지 않은 경우 -> 그냥삭제
	C2 삭제하려는 노드가 자식노드 1개를 가지고있는 경우  -> 삭제하려는 노드의 자식노드를 원래 자신의 위치로 옮겨 연결해 주기만 하면 된다.
	C3 삭제하려는 노드가 자식노드 2개를 가지고있는 경우  -> 삭제하려는 노드의 데이터만 삭제를 하고 삭제하려는노드다음의 노드(Successor)을 가져와 저장한다. -> (Recursion)이후 successor을 삭제하면서 다시 case분류...
*/

void Tree_Delete(Node*node) // 삭제할 노드를 포인터인자로 받아옴   (삭제할 포인터는 Tree_Search로 찾아서 가져온다.)
{
	if (node->left == NULL && node->right == NULL) // 자식노드를 가지고있지 않을 경우
		node->parent = NULL;
	else if (node->left != NULL && node->right != NULL) // 자식노드를 2개 갖을 경우
	{
		Node *targetNode;
		targetNode = Successor_Search(node); // 오른쪽 부트리에서 가장 작은 Node 포인터를 가져옴      ( Successor Node)
		Tree_Delete(targetNode); // Recursion    리커젼하여서 targetNode가 자식노드를 1개이하(camp)로 갖게될 때까지 반복
	}
	else
	{
		if (node->left != NULL) // 왼쪽 자식노드만 갖을 경우
		{
			if (node->parent->left == node)
				node->parent->left - node->left;
			if (node->parent->right == node)
				node->parent->right = node->left;
		}
		else if (node->right != NULL) // 오른쪽 자식노드만 갖을 경우
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