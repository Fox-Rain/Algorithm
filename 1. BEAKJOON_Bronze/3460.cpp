// https://www.acmicpc.net/problem/3460
/*
����
���� ���� n�� �־����� ��, �̸� �������� ��Ÿ���� �� 1�� ��ġ�� ��� ã�� ���α׷��� �ۼ��Ͻÿ�. ������ ��Ʈ(least significant bit, lsb)�� ��ġ�� 0�̴�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����. �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ְ�, n�� �־�����. (1 �� T �� 10, 1 �� n �� 106)

���
�� �׽�Ʈ ���̽��� ���ؼ�, 1�� ��ġ�� �������� �����ؼ� �� �ϳ��� ����Ѵ�. ��ġ�� ���� �ͺ��� ����Ѵ�.
*/
#include<iostream>
#include<bitset> // bitset�� ���� include

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		int n;
		cin >> n;

		bitset<32>bs(n); // n�� 32��Ʈ�� ǥ���Ѱ��� bs�� ������

		for (int j = 0; j < 32; ++j)
		{
			if (bs[j] == 1) // bitset���� ������ �������� ����迭ó�� �̿��� �� �ִ�.
				cout << j << " ";
		}
	}

	return 0;
}