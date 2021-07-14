//  https://www.acmicpc.net/problem/1931
/*
����
�� ���� ȸ�ǽ��� �ִµ� �̸� ����ϰ��� �ϴ� N���� ȸ�ǿ� ���Ͽ� ȸ�ǽ� ���ǥ�� ������� �Ѵ�. �� ȸ�� I�� ���� ���۽ð��� ������ �ð��� �־��� �ְ�, �� ȸ�ǰ� ��ġ�� �ʰ� �ϸ鼭 ȸ�ǽ��� ����� �� �ִ� ȸ���� �ִ� ������ ã�ƺ���. ��, ȸ�Ǵ� �ѹ� �����ϸ� �߰��� �ߴܵ� �� ������ �� ȸ�ǰ� ������ �Ͱ� ���ÿ� ���� ȸ�ǰ� ���۵� �� �ִ�. ȸ���� ���۽ð��� ������ �ð��� ���� ���� �ִ�. �� ��쿡�� �������ڸ��� ������ ������ �����ϸ� �ȴ�.

�Է�
ù° �ٿ� ȸ���� �� N(1 �� N �� 100,000)�� �־�����. ��° �ٺ��� N+1 �ٱ��� �� ȸ���� ������ �־����µ� �̰��� ������ ���̿� �ΰ� ȸ���� ���۽ð��� ������ �ð��� �־�����. ���� �ð��� ������ �ð��� 231-1���� �۰ų� ���� �ڿ��� �Ǵ� 0�̴�.

���
ù° �ٿ� �ִ� ����� �� �ִ� ȸ���� �ִ� ������ ����Ѵ�.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool Compare(pair<unsigned int, unsigned int> a, pair<unsigned int, unsigned int> b)
{
	if (a.second == b.second) // ����ð��� ���� ���
		return a.first < b.first; // ���۽ð��� �����ͺ��� ����

	else // 1��°�� ����ð� ��������
		return a.second < b.second; // ����ð� �����ͺ��� ����
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; // ȸ�� ��
	cin >> N;

	vector<pair<unsigned int, unsigned int>>conference; // conference vec ����
	for (int i = 0; i < N; ++i)
	{
		unsigned int start_time; // ȸ�� ���� �ð�
		unsigned int end_time; // ȸ�� ���� �ð�

		cin >> start_time >> end_time;

		conference.push_back(make_pair(start_time, end_time)); //make_pair�� push_back
	}

	sort(conference.begin(), conference.end(), Compare); // ����ð��� ���� ������ ���ʷ� ����

	int count = 0;
	int temp = 0;
	for (int i = 0; i < N; ++i)
	{
		if (temp <= conference[i].first)
		{
			count++;
			temp = conference[i].second;
		}
	}

	cout << count;

	return 0;
}