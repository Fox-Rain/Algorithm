// �׷����� ��ȭ Graph traversal
/*
	*��ȸ (traversal)
		* �׷����� ��� ������ �湮�ϴ� ��
		* ��ǥ������ �ΰ��� ������ִ�.  BFS (�ʺ�켱��ȸ)  DFS (���̿켱��ȸ)
*/
#include<iostream>
#include<vector> 
#include<queue> // BFS
#include<stack> // DFS by stack 

using namespace std;

// BFS (�ʺ�켱Ž��)     ��Ʈ��忡�� �����ؼ� ������ ���� ���� Ž���ϴ� �˰���      ��, ��� Ž���ϱ����� �а� Ž���ϴ� �˰���
	//                       �� ��� ������ "�ִܰ��" �Ǵ� "������ ���"�� ã����� �� �̿���   Ex) SNS ģ�������
	/*
		< BFS Ư¡ >
			* ��������� �۵����� �ʴ´�.
			* �׷���Ž���� ��� � ��带 �湮�Ͽ����� ���θ� �ݵ�� üũ�ϰ� �˻��ؾ� �Ѵ�.
			* "ť"(queue)�� ����Ѵ�.  ��, ���Լ���(FIFO)�� ����Ѵ�.

		< BFS ���� >
			1. ���� ����� ������� ���������� Ž���ѵ�, ť�� �ִ´�.  <-- �̶� ť�� �־����Ƿ� �湮���θ� o true�� �ٲپ��ش�.
			2. ���� ť�� ���� �������� ť���� �����鼭 �ٽ� ���� ����� ������ Ž��(�湮����x�� ���鸸)
			3. ���� ������ ���̻��� �湮����x�� ��尡 ���������� �ݺ��Ѵ�.

		< BFS�� �ִܰ�� >
			* �Է�: ���� Ȥ�� ������ �׷��� G = (V,E), �׸��� ��߳�� �� �Է��Ѵ�.
			* ���: ��� ��忡 ���ؼ�
				* d[v] = s�� ���� v������ �ִܰ���� ���� (������ ����)
				* pi[v] = s�� ���� v������ �ִܰ�λ��� v�� ���� ��� ( predecessor )

		< BFS ���ǻ��� >
			* �׷����� disconnected�̰ų� Ȥ�� ���� �׷����� ��� BFS�� ���ؼ� ��� ��尡 �湮���� ���� ���� �ִ�.
			* disconnecte�̰ų� Ȥ�� ���� �׷����� ��쿡�� ����带 �湮�ϴ� ��
				* �ϴ� BFS�� ���� �湮�ѵ�   BFS-ALL( G)
											{
												while there exists unvisitednode V      // �湮���� ���� ������ ��Ʈ���� �Ͽ��� ��� BFS�� �����ԵǸ�  ��� �湮�� ���� �ִ�.
													BFS(G, V);
											}
	*/
	// BFS //
void BFS(vector<int>graph[], bool check_BFS[], int n) // BFS�� �׷���(vector), ������ ��Ʈ����� �ε����� ���ڷ� ����
{
	queue<int>q; // �������� ����ְԵ� ť ����
	q.push(n); // ��Ʈ��� �ε����� ť�� ����
	check_BFS[n] = true; // ��Ʈ��尡 ť�������Ƿ� �湮���θ� O ���� check_BFS[n]�� true�� �ٲپ��ش�.

	while (q.empty() != true) // ť�� �������� 
	{
		int current = q.front(); // ť�� ����ִ� ���ϸ������� ������ ������ ����
		q.pop(); // ���� �� ������ ť���� ����

		cout << current << endl; // �� ������ ���

		for (int i = 0; i < graph[current].size(); ++i)
		{
			if (check_BFS[graph[current][i]] == false) // ������ ������ִ� ��尡 �湮���ΰ� x�� ���
			{
				q.push(check_BFS[graph[current][i]]); // ť�� �� ��带 ���� �ִ´�.
				check_BFS[graph[current][i]] = true; // ���� �� ������ �湮���θ� o�� �ٲ۴�.
			}
		}
	}
}

// DFS (���̿켱Ž��)  ��� ��Ʈ��忡�� �����Ͽ� �����带 visited�ϸ鼭 unvisited ��带 ã�ư��� ���� �ݺ��Ѵ�. ���ٸ� ���� �����ߴٸ� �ѳ�� �ڷΰ��� �ٽ� �ݺ��Ѵ�. �ᱹ ���۳��� �ٽ� ���ƿ��� ������ ������ �����Ѵ�  
	// ��Ʈ��忡�� �����ؼ� �����б�� �Ѿ������ �ش�б⸦ �Ϻ��ϰ� Ž���ϴ� �˰������� BFS�� ���ؼ� �ܼ��˻� �ӵ��� ������.  
	/*
		< DFS Ư¡ >
			* Recursion �˰����� ���¸� ������ �ִ�.
			* � ��带 �湮�ߴ����� ���θ� �� üũ�ؾ��Ѵ�.

		< DFS ���� >
			1. ��Ʈ������ unvisited�� ��带 ���� Ž���� �Ѵ�.
			2. ���� 1���� �ݺ��ϴٰ� unvisited ��尡 ���̻� �������� �ʰԵȴٸ�, �� �ٷ����� ���� ���ư��� �ٽ� 1���� �ݺ��Ѵ�.
			3. 1,2���� �ݺ��ϴٰ� ��Ʈ��忡���� unvisted��尡 ���̻� �������� �ʰ� �ȴٸ� DFS�� �����Ѵ�.

		< DFS ��� �� >
			* �̷�ã���...

		< DFS�� ����>
			* Recursion�� ����ϰų� ������ ����Ѵ�.
	*/
	// DFS //
void DFS_by_stack(vector<int>graph[], bool check_DFS[], int n) // DFS�� �׷���(vector), ������ ��Ʈ����� �ε����� ���ڷ� ����
{
	stack<int> s; // ������ ���� ����
	s.push(n); // ��Ʈ��带 Ǫ����
	check_DFS[n] = true; // n �湮���ΰ� o�̹Ƿ� true�� �ٲپ���

	cout << s.top() << '\n'; // �� ���

	while (s.size()) // ������ �������� while�� ����
	{
		int current = s.top(); // ���� ������ �� ���� �ִ� ���� current������ ����
		for (int i = 0; i < graph[current].size(); ++i)
		{
			if (check_DFS[graph[current][i]] == false) // unvisited �� ���
			{
				cout << graph[current][i] << '\n'; // ���
				check_DFS[graph[current][i]] = true; // visited�����Ƿ� true�� �ٲپ��ش�.
				s.push(graph[current][i]); // �� ������ ���ÿ� push
				break;
			}
			else if (i == graph[current].size() - 1) // unvisited �� ��츦 ������ ���ϴ� ���
				s.pop(); // �� ������ �����ǰ��� pop�Ѵ�.
		}
	}
}

// DFS //
void DFS_by_recursion(vector<int>graph[], bool check_DFS[], int n) // DFS�� �׷���(vector), ������ ��Ʈ����� �ε����� ���ڷ� ����
{
	cout << n << '\n'; // ���
	for (int i = 0; i < graph[n].size(); ++i)
	{
		if (check_DFS[graph[n][i]] == false) // unvisited�� ������ ���
			DFS_by_recursion(graph, check_DFS, graph[n][i]); // DFS_by_recursion�� Recursion
	}
}

int main()
{
	const int v = 10;
	vector<int>graph[v]; // graph�� ������ v��
	bool check_BFS[v]; // v 

	return 0;
}