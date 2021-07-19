// Red-Black Tree     레드블랙트리
/*
	레드블랙트리는  이진검색트리에서 최악으경우 높이==갯수가 되는 경우를 없애기 위해 수정한 트리이다.  <트리의 balance가 무너지지않도록 맞추어진 트리>

	이진탐색트리의 일종으로  "균형잡힌 트리"로 높이가 O(logN)
	*** Insert, Serach, Delete 연산을 최악의 경우에도 O(logN)시간을 지원한다.

	Red Black Tree
		* 각노드들은 하나의데이터, 왼쪽자식, 오른쪽자식, 부모노드의 주소를 가지고있다.
		* 자식노드가 존재하지않을 경우 자식노드대신 NIL노드를 가지고있다고 가정한다. <--- *****
		* 따라서 리프노드는 모두 NIL노드가 된다.  (자식이없어도 자식노드를 NIL노드라한다고하였므로, 마지막 노드들은 NIL노드일 수 밖에)
		* 루트의 부모노드도 NIL노드라고 가정한다.
		* 따라서 노드들은 내부노드와 NIL노드로 분류하여 생각한다.

	다음의조건을 만족하는 이진탐색트리를 "레드블랙트리"라고 한다.
		1. 각노드들은 Red 혹은 Black 이다
		2. 루트노드는 Black으로 고정되어있다.
		3. 모든 리프노드들은 Black이다.
		4. Red노드들의 자식노드들은 전부 Black이다. (즉, Red노드들은 연속되어 등장하지 않는다.)
		5. 모든노드에 대해서 그 노드에서 자손인 리프노드까지 이르는 모드 경로에는 동일한 개수의 Black노드가 존재한다.

	노드의 높이는 자신으로부터 리프노드까지의 가장 긴 경로에 포함되는 에지의 개수이다.
	노드의 블랙높이는 자신으로부터 리프노드까지의 경로상의 블랙노드의 개수이다.

	* 높이가 h인 노드의 블랙-높이는 bh >= h/2 이다.
		* 조건 4번에 의해 레드노드는 연속될 수 없기 때문

	* 노드 x를 루트로하느 임의의 부트리는 적어도 2^bh(x)-1 개의 내부노드를 포함한다.

	*  n개의 내부노드를 가지는 레드블랙트리는 높이가 2log(n+1)이하이다.
		* n >= 2^(hb)-1 >= 2^(h/2)-1 이므로,  여기서 bh, h는 각각 루틍노드의 블랙-높이와  높이 이다.

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

// Red-Black Tree Search    ==    Binary Search   완전히 이진탐색과 같은 알고리즘을 사용한다.

// Left and Right Rotation       (delete, insert 연산을 하기위한 기본 연산 알고리즘      한노드를 중심으로 부분적으로 노드를 수정하는 알고리즘)                   참고 https://ict-nroo.tistory.com/70
// 시간복잡도는 O(1) 상수시간이며,  위읜연산을 통해 노드가 부분적으로 바뀌어도 "이진탐색트리"의 특성을 유지한다. (즉, 이진탐색트리의 노드들 간의 크기상태는 유지된다.)

void leftRotate(Node *targetNode)
{
	if (targetNode->parent->left == targetNode) // targetNode가 부모의 왼쪽 자식일 경우
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
	else if (targetNode->parent->right == targetNode) // targetNode가 부모의 오른쪽 자식일 경우
	{

	}
}


int main()
{
	return 0;
}