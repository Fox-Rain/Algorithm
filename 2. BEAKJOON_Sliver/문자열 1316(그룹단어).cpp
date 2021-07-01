// https://www.acmicpc.net/problem/1316
/*
����
�׷� �ܾ�� �ܾ �����ϴ� ��� ���ڿ� ���ؼ�, �� ���ڰ� �����ؼ� ��Ÿ���� ��츸�� ���Ѵ�. ���� ���, ccazzzzbb�� c, a, z, b�� ��� �����ؼ� ��Ÿ����, kin�� k, i, n�� �����ؼ� ��Ÿ���� ������ �׷� �ܾ�������, aabbbccb�� b�� �������� ��Ÿ���� ������ �׷� �ܾ �ƴϴ�.

�ܾ� N���� �Է����� �޾� �׷� �ܾ��� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ܾ��� ���� N�� ���´�. N�� 100���� �۰ų� ���� �ڿ����̴�. ��° �ٺ��� N���� �ٿ� �ܾ ���´�. �ܾ�� ���ĺ� �ҹ��ڷθ� �Ǿ��ְ� �ߺ����� ������, ���̴� �ִ� 100�̴�.

���
ù° �ٿ� �׷� �ܾ��� ������ ����Ѵ�.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N; // case������ ����

	int count = 0; // �׷�ܾ� count
	string str;
	for (int i = 0; i < N; ++i)
	{
		cin >> str;

		int j = 0;
		vector<char>ch;
		while (str[j] != '\0') // Null character�� �ƴҰ�� ������ ����
		{
			if (str[j] != str[j + 1])
			{
				ch.push_back(str[j]);

				vector<char>::iterator itr;
				itr = find(ch.begin(), ch.end(), str[j + 1]); // <algorithm>�� find�޼ҵ�  str[j+1]�� �ִٸ� �� index�� iterator�� �����ϰ�, ���� ���ٸ� .end() iterator�� ������

				if (itr != ch.end()) // str[j+1]�� ���� ���
					break;
			}

			j++;
		}

		if (str[j] == '\0') // while���� ������ �������Ƿ� �׷�ܾ��̴�.
			count++;
	}

	cout << count;

	return 0;
}