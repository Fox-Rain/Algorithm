// https://www.acmicpc.net/problem/10610
/*
����
��� ��, �̸��ڴ� �쿬�� ��Ÿ����� ��� N�� ���Ҵ�. �̸��ڴ� 30�̶� ���� �����ϱ� ������, �״� ��Ÿ����� ã�� ���� ���Ե� ���ڵ��� ���� 30�� ����� �Ǵ� ���� ū ���� ����� �;��Ѵ�.

�̸��ڸ� ���� �װ� ����� �;��ϴ� ���� ����ϴ� ���α׷��� �ۼ��϶�.

�Է�
N�� �Է¹޴´�. N�� �ִ� 105���� ���ڷ� �����Ǿ� ������, 0���� �������� �ʴ´�.

���
�̸��ڰ� ����� �;��ϴ� ���� �����Ѵٸ� �� ���� ����϶�. �� ���� �������� �ʴ´ٸ�, -1�� ����϶�.
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string N;
	cin >> N;

	int sum = 0;
	bool zero_flag = false;
	for (int i = 0; i < N.length(); ++i)
	{
		if (N[i] == '0')
			zero_flag = true;

		sum += N[i] - '0'; // *** atoi()�� ���� ���ڿ��� ���ڷ� �ٲٱ� ������ ���⼭�� ����ϱ⿡ �������� �ʴ�.     ������ ���ڸ� ������ ���ڷ� ��Ÿ����
	}

	if (zero_flag == true && sum % 3 == 0)
	{
		sort(N.begin(), N.end(), [](int i, int j) {return i > j; });
		cout << N;
	}
	else
		cout << "-1";
	return 0;
}