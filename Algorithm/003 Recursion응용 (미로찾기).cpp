// 미로찾기 Recursion
// 시작점에서 도착점까지 갈 수 있다면 true, 불가능하다면 false를 Maze의 메소드 findPath
#include<iostream>

#define PATHWAY 0  // 지나갈 수 있는 길
#define WALL 1     // 지나갈 수 없는 벽
#define BLOCKED 2  // 다시 돌아갈 수 없는 길 <꽝>
#define PATH 3     // 지나온 길

using namespace std;

class Maze
{
public:
	static const int N = 8;
	int maze[N][N] =        // 미로
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
		if (x < 0 || y < 0 || x >= N || y >= N) // 미로밖일 경우
			return false;

		else if (maze[x][y] != PATHWAY) // 다닐 수 있는 길('0')이 아닐 경우
			return false;

		else if (x == N - 1 && y == N - 1) // x,y가 7,7 출구 일 경우
		{
			maze[x][y] = PATH;
			return true; // True 리턴
		}

		else
		{
			maze[x][y] = PATH;

			if (findPath(x - 1, y) || findPath(x, y + 1) || findPath(x + 1, y) || findPath(x, y - 1)) // *** 주의하기
				return true;

			maze[x][y] = BLOCKED;
			return false;
		}
	}
};

int main()
{
	Maze MZ;

	cout << bool(MZ.findPath(0, 0)); // 탈출이 가능하므로 true   즉, 1출력

	return 0;
}