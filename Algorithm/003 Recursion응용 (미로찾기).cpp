// �̷�ã�� Recursion
// ���������� ���������� �� �� �ִٸ� true, �Ұ����ϴٸ� false�� Maze�� �޼ҵ� findPath
#include<iostream>

#define PATHWAY 0  // ������ �� �ִ� ��
#define WALL 1     // ������ �� ���� ��
#define BLOCKED 2  // �ٽ� ���ư� �� ���� �� <��>
#define PATH 3     // ������ ��

using namespace std;

class Maze
{
public:
	static const int N = 8;
	int maze[N][N] =        // �̷�
	{
		{0,0,0,0,0,0,0,1},
		{0,1,1,0,1,1,0,1},
		{0,0,0,1,0,0,0,1},
		{0,1,0,0,1,1,0,0},
		{0,1,1,1,0,0,1,1},
		{0,1,0,0,0,1,0,1},
		{0,0,0,1,0,0,0,1},
		{0,1,1,1,0,1,0,0}
	};

	bool findPath(int x, int y) 
	{
		if (x < 0 || y < 0 || x >= N || y >= N) // �̷ι��� ���
			return false;

		else if (maze[x][y] != PATHWAY) // �ٴ� �� �ִ� ��('0')�� �ƴ� ���
			return false;

		else if (x == N - 1 && y == N - 1) // x,y�� 7,7 �ⱸ �� ���
		{
			maze[x][y] = PATH;
			return true; // True ����
		}

		else
		{
			maze[x][y] = PATH;

			if (findPath(x - 1, y) || findPath(x, y + 1) || findPath(x + 1, y) || findPath(x, y - 1)) // *** �����ϱ�
				return true;

			maze[x][y] = BLOCKED;
			return false;
		}
	}
};

int main()
{
	Maze MZ;

	cout << bool(MZ.findPath(0, 0)); // Ż���� �����ϹǷ� true   ��, 1���

	return 0;
}