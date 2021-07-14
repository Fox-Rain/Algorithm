// https://www.acmicpc.net/problem/1969
/*
����
DNA�� � ���������� �����ϴ� �����̴�. �� DNA�� ���� �ٸ� 4������ ��Ŭ����Ƽ��� �̷���� �ִ�(Adenine, Thymine, Guanine, Cytosine). �츮�� � DNA�� ������ ǥ���� ��,
�� DNA�� �̷�� ��Ŭ����Ƽ���� ù���ڸ� ���� ǥ���Ѵ�. ���࿡ Thymine-Adenine-Adenine-Cytosine-Thymine-Guanine-Cytosine-Cytosine-Guanine-Adenine-Thymine�� �̷���� DNA�� �ִٰ� �ϸ�,
��TAACTGCCGAT���� ǥ���� �� �ִ�. �׸��� Hamming Distance�� ���̰� ���� �� DNA�� ���� ��, �� ��ġ�� ��Ŭ��Ƽ�� ���ڰ� �ٸ� ���� �����̴�. ���࿡ ��AGCAT"�� ��GGAAT"�� ù ��° ���ڿ� �� ��° ���ڰ� �ٸ��Ƿ�
Hamming Distance�� 2�̴�.

�츮�� �� ���� ������ ����. N���� ���� M�� DNA s1, s2, ..., sn�� �־��� ���� �� Hamming Distance�� ���� ���� ���� DNA s�� ���ϴ� ���̴�.
��, s�� s1�� Hamming Distance + s�� s2�� Hamming Distance + s�� s3�� Hamming Distance ... �� ���� �ּҰ� �ȴٴ� �ǹ��̴�.

�Է�
ù �ٿ� DNA�� �� N�� ���ڿ��� ���� M�� �־�����. �׸��� ��° �ٺ��� N+1��° �ٱ��� N���� DNA�� �־�����. N�� 1,000���� �۰ų� ���� �ڿ����̰�, M�� 50���� �۰ų� ���� �ڿ����̴�.

���
ù° �ٿ� Hamming Distance�� ���� ���� ���� DNA �� ����ϰ�, ��° �ٿ��� �� Hamming Distance�� ���� ����Ͻÿ�. �׷��� DNA�� ���� �� ���� ������ ���������� ���� �ռ��� ���� ����Ѵ�.
*/

#include<iostream>
#include<string>
#include<map>
#include<climits>
#include<vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; // DNA ����
	int m; // DNA ����

	cin >> n >> m;

	vector<string>DNAvec;
	for (int i = 0; i < n; ++i)
	{
		string DNA;
		cin >> DNA;

		DNAvec.push_back(DNA);
	}

	int sum = 0;
	map<char, int>check;
	for (int i = 0; i < m; ++i)
	{
		check = { make_pair('A',0),make_pair('G',0),make_pair('C',0),make_pair('T',0) };
		for (int j = 0; j < n; j++)
			check[DNAvec[j][i]]++;

		int max = INT_MIN;
		map<char, int>::iterator result_itr;
		map<char, int>::iterator itr;
		for (itr = check.begin(); itr != check.end(); ++itr)
		{
			if (max < itr->second)
			{
				max = itr->second;
				result_itr = itr;
			}
		}
		sum += n - max;
		cout << result_itr->first;
	}
	cout << '\n';
	cout << sum;

	return 0;
}