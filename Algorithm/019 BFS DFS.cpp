// 그래프의 순화 Graph traversal
/*
	*순회 (traversal)
		* 그래프의 모든 노드들을 방문하는 일
		* 대표적으로 두가지 방법이있다.  BFS (너비우선순회)  DFS (깊이우선순회)
*/
#include<iostream>
#include<vector> 
#include<queue> // BFS
#include<stack> // DFS by stack 

using namespace std;

// BFS (너비우선탐색)     루트노드에서 시작해서 인접한 노드들 부터 탐색하는 알고리즘      즉, 깊게 탐색하기전에 넓게 탐색하는 알고리즘
	//                       두 노드 사이의 "최단경로" 또는 "임의의 경로"를 찾고싶을 때 이용함   Ex) SNS 친구관계망
	/*
		< BFS 특징 >
			* 재귀적으로 작동하지 않는다.
			* 그래프탐색의 경우 어떤 노드를 방문하였는지 여부를 반드시 체크하고 검사해야 한다.
			* "큐"(queue)을 사용한다.  즉, 선입선출(FIFO)을 사용한다.

		< BFS 순서 >
			1. 가장 가까운 노드들부터 순차적으로 탐색한뒤, 큐에 넣는다.  <-- 이때 큐에 넣었으므로 방문여부를 o true로 바꾸어준다.
			2. 이후 큐에 들어온 순서부터 큐에서 꺼내면서 다시 가장 가까운 노드들을 탐색(방문여부x인 노드들만)
			3. 앞의 과정을 더이상의 방문여부x인 노드가 없을때까지 반복한다.

		< BFS와 최단경로 >
			* 입력: 방향 혹은 무방향 그래프 G = (V,E), 그리고 출발노드 를 입력한다.
			* 출력: 모든 노드에 대해서
				* d[v] = s로 부터 v까지의 최단경로의 길이 (에지의 개수)
				* pi[v] = s로 부터 v까지의 최단경로상의 v의 직전 노드 ( predecessor )

		< BFS 유의사항 >
			* 그래프가 disconnected이거나 혹은 방향 그래프일 경우 BFS에 의해서 모든 노드가 방문되지 않을 수도 있다.
			* disconnecte이거나 혹은 방향 그래프일 경우에도 모든노드를 방문하는 법
				* 일단 BFS를 통해 방문한뒤   BFS-ALL( G)
											{
												while there exists unvisitednode V      // 방문되지 않은 노드들을 루트노드로 하여서 모두 BFS를 돌리게되면  모두 방문할 수는 있다.
													BFS(G, V);
											}
	*/
	// BFS //
void BFS(vector<int>graph[], bool check_BFS[], int n) // BFS할 그래프(vector), 시작할 루트노드의 인덱스를 인자로 받음
{
	queue<int>q; // 정점들을 집어넣게될 큐 선언
	q.push(n); // 루트노드 인덱스를 큐에 넣음
	check_BFS[n] = true; // 루트노드가 큐에들어갔으므로 방문여부를 O 따라서 check_BFS[n]을 true로 바꾸어준다.

	while (q.empty() != true) // 큐가 빌때까지 
	{
		int current = q.front(); // 큐에 들어있는 제일먼저들어온 정점을 변수에 저장
		q.pop(); // 이후 그 정점을 큐에서 삭제

		cout << current << endl; // 그 정점을 출력

		for (int i = 0; i < graph[current].size(); ++i)
		{
			if (check_BFS[graph[current][i]] == false) // 정점과 연결되있는 노드가 방문여부가 x일 경우
			{
				q.push(check_BFS[graph[current][i]]); // 큐에 그 노드를 집어 넣는다.
				check_BFS[graph[current][i]] = true; // 이후 그 노드들의 방문여부를 o로 바꾼다.
			}
		}
	}
}

// DFS (깊이우선탐색)  출발 루트노드에서 시작하여 현재노드를 visited하면서 unvisited 노드를 찾아가는 것을 반복한다. 막다른 곳에 도착했다면 한노드 뒤로가서 다시 반복한다. 결국 시작노드로 다시 돌아오고 갈곳이 없으면 종료한다  
	// 루트노드에서 시작해서 다음분기로 넘어가기전에 해당분기를 완벽하게 탐색하는 알고리즘으로 BFS에 비해서 단순검색 속도는 느리다.  
	/*
		< DFS 특징 >
			* Recursion 알고리즘의 형태를 가지고 있다.
			* 어떤 노드를 방문했는지의 여부를 꼭 체크해야한다.

		< DFS 순서 >
			1. 루트노드부터 unvisited인 노드를 향해 탐색을 한다.
			2. 이후 1번을 반복하다가 unvisited 노드가 더이상 존재하지 않게된다면, 그 바로전의 노드로 돌아가서 다시 1번을 반복한다.
			3. 1,2번을 반복하다가 루트노드에서도 unvisted노드가 더이상 존재하지 않게 된다면 DFS를 종료한다.

		< DFS 사용 예 >
			* 미로찾기등...

		< DFS의 구현>
			* Recursion을 사용하거나 스택을 사용한다.
	*/
	// DFS //
void DFS_by_stack(vector<int>graph[], bool check_DFS[], int n) // DFS할 그래프(vector), 시작할 루트노드의 인덱스를 인자로 받음
{
	stack<int> s; // 정점을 넣을 스택
	s.push(n); // 루트노드를 푸쉬함
	check_DFS[n] = true; // n 방문여부가 o이므로 true로 바꾸어줌

	cout << s.top() << '\n'; // 값 출력

	while (s.size()) // 스택이 빌때까지 while문 실행
	{
		int current = s.top(); // 현재 스택의 맨 위에 있는 값을 current변수에 저장
		for (int i = 0; i < graph[current].size(); ++i)
		{
			if (check_DFS[graph[current][i]] == false) // unvisited 일 경우
			{
				cout << graph[current][i] << '\n'; // 출력
				check_DFS[graph[current][i]] = true; // visited했으므로 true로 바꾸어준다.
				s.push(graph[current][i]); // 그 정점을 스택에 push
				break;
			}
			else if (i == graph[current].size() - 1) // unvisited 일 경우를 만나지 못하는 경우
				s.pop(); // 그 스택의 맨위의값을 pop한다.
		}
	}
}

// DFS //
void DFS_by_recursion(vector<int>graph[], bool check_DFS[], int n) // DFS할 그래프(vector), 시작할 루트노드의 인덱스를 인자로 받음
{
	cout << n << '\n'; // 출력
	for (int i = 0; i < graph[n].size(); ++i)
	{
		if (check_DFS[graph[n][i]] == false) // unvisited를 만나는 경우
			DFS_by_recursion(graph, check_DFS, graph[n][i]); // DFS_by_recursion을 Recursion
	}
}

int main()
{
	const int v = 10;
	vector<int>graph[v]; // graph의 정점은 v개
	bool check_BFS[v]; // v 

	return 0;
}