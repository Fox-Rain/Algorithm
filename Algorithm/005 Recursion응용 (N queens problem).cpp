// ���°���Ʈ�� // 
/* ���°���Ʈ����? ����Ǽ��� ������ ã�� �ظ� �����ϴ� Ʈ����   ��, �ذ� �����Ѵٸ� �װ��� �ݵ�� �� Ʈ���� � �� ��忡 �ش��ϰ� �ȴ�.
   ���� ���°���Ʈ���� �� ��� ��带 Ž���� �ʿ�� ����.(��, ���� ���ǿ��� ���� �ʿ������� �����ٸ� �� �ڴ� �� �ʿ䰡 ���ٴ� �ǹ��̴�.)*/
// ��Ʈ��ŷ Backtracking //
/* ���°���Ʈ���� ���̿켱������� Ž���Ͽ� �ظ� ã�� �˰����� ���Ѵ�.     �����ϴ¹�����δ� recursion, stack�� �ִ�. */
#include<iostream>

using namespace std;

class N_QUEENS
{
public:
	// 1���� num������ ����,���η� �̷���� ü����
	int num;
	int *position = new int[num + 1]; // ���ζ��� �迭 index 1~n ����� ���ؼ� �����Ҵ�    Ex) position[1]=3; �̶�� 1���� 3�࿡ ���� �ξ����ٴ� ���� �ǹ���.

	bool n_Queens(int level) // level�� ���� ���� ����.
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