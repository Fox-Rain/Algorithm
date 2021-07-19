// �׷��� ( Graph )
/*
* (������) �׷���  G = (V,E)						�� ���鸶�� ����Ǵ� ��ũ�� �������� �� ������, ��ũ�� ������ ���� �ʴ�. (�瓇�� �Ѵ� ��)     Ex) ���� (u,v) == (v,u)
*	* V : ��� Ȥ�� ����
	* E : ������ �����ϴ� ���� Ȥ�� ��ũ
	* ��ü���� �������踦 ǥ���Ѵ�.
	* n = |V| , m = |E|
	* ������ �׷������� ���� ��带 �����ϴ� ��ΰ� �����ϴ� ���, v,u�� ���� ����Ǿ��ִٰ� �Ѵ�.
	* ��� ������ ������ ���� ����Ǿ��ִ� �׷����� "����׷���"��� �Ѵ�.

* ���� �׷���  G = (V,E)							�� ���鸶�� ����Ǵ� ��ũ�� �������� �� ������, ��ũ�� ������ �����Ѵ�. (����� x)           Ex) ���� (u,v) != (v,u)
	* ���� (u,v)�� u�κ��� v���� ������ ���´�.

* ����ġ �׷���
	* �������� ����ġ(weight)�� �����ȴ�.	       ����(��ũ)���� ���� �ο��ϴ� ��...

* ���� �׷���
	* �� �������� �ٸ� ��� ������ �����Ͽ� �ִ��� �������� ���� �׷����̴�.   (������׷������� n(n-1)/2   ���� �׷������� n(n-1)�� �ִ� ������ ���� �� �ִ�.)
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	// �׷����� ǥ�� //

	// �������     ---> ������ ���� V����� ���� ��, V*Vũ���� ������ �迭�� �̿��Ѵ�.     * ������� O(V^2)     * ���忡 ������ ��� ���ã�� O(n)     * ����� (u,v)�� �����ϴ��� �˻� O(1) ����ð�

	/*
		������ ����ġ�� �������� ���� ���      A[i][j] = 1; (i -> j ������ ������ ���)
											 A[i][j] = 0; (i -> j ������ �������� ���� ���)
	*/
	const int v = 10; // ������ 10����� ������ ��
	int e = 10; // ������ 10����� ������ ��
	int g[v + 1][v + 1]; // 10*10 2���� �迭 ����

	for (int i = 0; i < v + 1; ++i)
	{
		int x, y;
		cin >> x >> y;

		// �瓇�� �׷����� ��� (x,y�� y,x ����)
		g[x][y] = g[y][x] = 1;

		// ���� �׷����� ��� (x,y�� y,x �������� �����Ƿ� ���ʸ� 1 ����)
		g[x][y] = 1;
	}

	/*
		������ ����ġ�� �����ϴ� ��� ���� �ٽ� 2�����迭�� ���� ǥ���Ѵ�.
	*/
	const int v = 10; // ������ 10����� ������ ��
	int e = 10; // ������ 10����� ������ ��
	int g[v + 1][v + 1]; // 10*10 2���� �迭 ����
	int B[v + 1][v + 1]; // ����ġ �迭
	int W = 123; // ����ġ
	for (int i = 0; i < v + 1; ++i)
	{
		int x, y;
		cin >> x >> y;

		// �瓇�� �׷����� ��� (x,y�� y,x ����)
		g[x][y] = g[y][x] = 1;
		B[x][y] = B[y][x] = W;

		// ���� �׷����� ��� (x,y�� y,x �������� �����Ƿ� ���ʸ� 1 ����)
		g[x][y] = 1;
	}


	// ��������Ʈ           �������  O(E) �ַ� �ٷ�� �׷����z E < V �̹Ƿ� ��������Ʈ�� ȿ�����̴�.   ������ ������ ��� �� ã�� �� ������ ���Ḯ��Ʈ ������ ���, ������� �����ϴ��� ���Ḯ��Ʈ�� ���
	// �� ���� ������ ǥ���ϴ� �ϳ��� �迭�� ���������� ������ ���� ���Ḯ��Ʈ
	const int v = 10; // ������ ����
	int e = 10; // ������ ����
	vector<pair<int, int>>graph[v + 1];
	for (int i = 0; i < e; ++i)
	{
		int u, v, w; // ������ ������ �ְ� (u,v)  ����ġ�� w�� ���
		cin >> u >> v >> w;

		graph[u].push_back(make_pair(v, w)); // ���� ������ �� ��� graph[v].push_back(make_pair(u,w)); �� ���� Ÿ���� ���ָ� �ȴ�.
	}




	return 0;
}