// https://www.acmicpc.net/problem/1764
/*
����
�������� �赵 ���� ����� ��ܰ�, ���� ���� ����� ����� �־��� ��, �赵 ���� ���� ����� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �赵 ���� ����� �� N, ���� ���� ����� �� M�� �־�����. �̾ ��° �ٺ��� N���� �ٿ� ���� �赵 ���� ����� �̸���, N+2° �ٺ��� ���� ���� ����� �̸��� ������� �־�����. �̸��� ���� ���� ���� �ҹ��ڷθ� �̷������, �� ���̴� 20 �����̴�. N, M�� 500,000 ������ �ڿ����̴�.



�赵 ���� ����� ��ܿ��� �ߺ��Ǵ� �̸��� ������, ���� ���� ����� ��ܵ� ���������̴�.

���
�躸���� ���� �� ����� ���������� ����Ѵ�.
*/

// ���⿡�� �Ϲ����� �����ƻ��� ����ϰ� �Ǹ� �ð��ʰ��� �߻��Ѵ�.  ���� sort�� ���Ͽ� ���������� �����ѵ�, binary_search(����Ž��)�� ���Ͽ� �������� ã�´�.
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int N;
	int M;
	cin >> N >> M;

	int count = 0; // ����

	vector<string>names;
	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;

		names.push_back(str);
	}

	sort(names.begin(), names.end()); // ó������ string vector�� ���������� ����

	vector<string>result;
	for (int i = 0; i < M; ++i)
	{
		string str;
		cin >> str;

		if (binary_search(names.begin(), names.end(), str)) // names vector�� ������ �Ǿ������Ƿ� binary_search�� ����� �� �ִ�.  ��, str�� names vector�ȿ� �����Ѵٸ�
		{
			count++; // count�� �ø���
			result.push_back(str); // result vector�� �� ���ڿ��� push back���ش�.
		}
	}

	sort(result.begin(), result.end());

	cout << count << '\n';
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << '\n';
	}

	return 0;
}