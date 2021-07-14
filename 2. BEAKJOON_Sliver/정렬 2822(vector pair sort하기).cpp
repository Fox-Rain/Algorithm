// https://www.acmicpc.net/problem/2822
/*
����
����̴� ������� PD�̴�. �� ������� �����ڴ� �� 8�� ������ Ǭ��. �����ڴ� �� ������ Ǯ��, �� ������ Ǯ���� �� ��� ������ ������ Ǯ�� ������ �ð����� ����� �ð��� ���̵��� �����Ѵ�. ������ Ǯ�� ���� ��쿡�� 0���� �޴´�. �������� �� ������ ���� ���� ���� 5���� ���̴�.

����̴� ��� ����ģ���� ��ȭ ��ȭ�� �ϴ��� �������� ������ ������� �ʰ� �־���. �������� 8�� ���� ������ �־����� ��, �� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
8�� �ٿ� ���ļ� �� ������ ���� �������� ������ �־�����. ������ 0���� ũ�ų� ����, 150���� �۰ų� ����. ��� ������ ���� ������ ���� �ٸ���. �Է����� �־����� ������� 1�� ����, 2�� ����, ... 8�� �����̴�.

���
ù° �ٿ� �������� ������ ����Ѵ�. ��° �ٿ��� � ������ ���� ������ ���ԵǴ����� �������� �����Ͽ� ����Ѵ�. ����� ���� ��ȣ�� �����ϴ� �����̾�� �Ѵ�.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool Compare_By_Frist(pair<int, int> x, pair<int, int> y)
{
	return x.first < y.first;
}

bool Compare_By_Second(pair<int, int> x, pair<int, int> y)
{
	return x.second > y.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>>scoreVec;
	for (int i = 0; i < 8; ++i)
	{
		int score;
		cin >> score;

		scoreVec.push_back(make_pair(i + 1, score));
	}

	sort(scoreVec.begin(), scoreVec.end(), Compare_By_Second);

	int sum = 0;
	for (int i = 0; i < 5; ++i)
		sum += scoreVec[i].second;

	cout << sum << '\n';

	sort(scoreVec.begin(), scoreVec.begin() + 5, Compare_By_Frist);

	for (int i = 0; i < 5; ++i)
		cout << scoreVec[i].first << " ";

	return 0;
}