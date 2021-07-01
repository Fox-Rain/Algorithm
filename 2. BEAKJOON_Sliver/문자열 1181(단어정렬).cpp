// https://www.acmicpc.net/problem/1181
/*
����
���ĺ� �ҹ��ڷ� �̷���� N���� �ܾ ������ �Ʒ��� ���� ���ǿ� ���� �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

1. ���̰� ª�� �ͺ���
2. ���̰� ������ ���� ������

�Է�
ù° �ٿ� �ܾ��� ���� N�� �־�����. (1 �� N �� 20,000) ��° �ٺ��� N���� �ٿ� ���� ���ĺ� �ҹ��ڷ� �̷���� �ܾ �� �ٿ� �ϳ��� �־�����. �־����� ���ڿ��� ���̴� 50�� ���� �ʴ´�.

���
���ǿ� ���� �����Ͽ� �ܾ���� ����Ѵ�. ��, ���� �ܾ ���� �� �Էµ� ��쿡�� �� ������ ����Ѵ�.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(string i, string j)
{
	if (i.length() == j.length()) // ũ�Ⱑ ���ٸ�
		return i < j; // ũ�Ⱑ ������ �����ΰ�����
	return i.length() < j.length(); // *** string��ü�� <(�����ε�)�� ���ؼ� �����Ĺ迭�� ũ�⸦ ���� �� �ִ� ***  
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<string>str_arr;
	str_arr.reserve(N); // push_back�� �޸� �Ҵ��Ҷ� ����� ���� �����ս� ���ϸ� ���̱����� ó������ reserve�� �޸� �Ҵ�

	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;

		if (find(str_arr.begin(), str_arr.end(), str) == str_arr.end()) // find�� str�� ��ã�����  ��, �ߺ��� �ƴ� ���
			str_arr.push_back(str); // str�� push_back(str);
	}

	sort(str_arr.begin(), str_arr.end(), compare); // ***

	for (auto &ele : str_arr)
		cout << ele << '\n';

	return 0;
}