// 상태공간트리 // 
/* 상태공간트리란? 경우의수를 나열한 찾는 해를 포함하는 트리로   즉, 해가 존재한다면 그것은 반드시 이 트리의 어떤 한 노드에 해당하게 된다.
   또한 상태공간트리는 꼭 모든 노드를 탐색할 필요는 없다.(즉, 앞의 조건에서 벌써 필요조건이 깨진다면 그 뒤는 볼 필요가 없다는 의미이다.)*/
// 백트래킹 Backtracking //
/* 상태공간트리를 깊이우선방식으로 탐색하여 해를 찾는 알고리즘을 말한다.     구현하는방법으로는 recursion, stack이 있다. */
#include<iostream>

using namespace std;

class N_QUEENS
{
public:
	// 1부터 num까지의 가로,세로로 이루어진 체스판
	int num;
	int *position = new int[num + 1]; // 세로라인 배열 index 1~n 만들기 위해서 동적할당    Ex) position[1]=3; 이라면 1열의 3행에 퀸이 두어졌다는 것을 의미함.

	bool n_Queens(int level) // level은 새로 행을 말함.
	{
		if (level > num)
			return true;

		else if (position[1] > num)
			return false;

		for (int i = 1; i < num + 1; ++i)
		{
			
		}
	}


};

int main()
{
	return 0;
}