#include<iostream>

#define counting_Cells_in_a_Blob cciab

#define BACKGROUND 0 // 이미지가 아닌 배경
#define IMAGE 1      // 이미지
#define CHECKED 2    // 이미 선택된 이미지

using namespace std;

class Cell
{
public:
	static const int num = 8;
	int grid[num][num] =
	{
		{1,0,0,0,0,0,0,1},
		{0,1,1,0,0,1,0,0},
		{1,1,0,0,1,0,1,0},
		{0,0,0,0,0,1,0,0},
		{0,1,0,1,0,1,0,0},
		{0,1,0,1,0,1,0,0},
		{1,0,0,0,1,0,0,1},
		{0,1,1,0,0,1,1,1}
	};

	int counting_Cells_in_a_Blob(int x, int y)
	{
		if (x < 0 || y < 0 || x >= num || y >= num)
			return 0;

		else if (grid[x][y] != IMAGE)
			return 0;

		else
		{
			grid[x][y] = CHECKED;

			return 1 + cciab(x + 1, y + 1) + cciab(x + 1, y) + cciab(x + 1, y - 1) + cciab(x, y + 1)
				+ cciab(x, y - 1) + cciab(x - 1, y + 1) + cciab(x - 1, y) + cciab(x - 1, y - 1);
		}
	}
};

int main()
{
	cout << Cell().counting_Cells_in_a_Blob(7, 7);

	return 0;
}