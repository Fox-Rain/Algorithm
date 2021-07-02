// https://www.acmicpc.net/problem/11656
/*
����
���̻� �迭�� ���ڿ� S�� ��� ���̻縦 ���������� ������ ���� �迭�̴�.

baekjoon�� ���̻�� baekjoon, aekjoon, ekjoon, kjoon, joon, oon, on, n ���� �� 8������ �ְ�, �̸� ���������� �����ϸ�, aekjoon, baekjoon, ekjoon, joon, kjoon, n, on, oon�� �ȴ�.

���ڿ� S�� �־����� ��, ��� ���̻縦 ���������� ������ ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���ڿ� S�� �־�����. S�� ���ĺ� �ҹ��ڷθ� �̷���� �ְ�, ���̴� 1,000���� �۰ų� ����.

���
ù° �ٺ��� S�� ���̻縦 ���������� �� �ٿ� �ϳ��� ����Ѵ�.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	vector<string>s_vec;
	int count = s.length();
	for (int i = 0; i < count; ++i) // *** �������� s.length()�� count ��ſ� �ְԵǸ�  erase�Ҷ����� length�� �پ��Ƿ� ó���� s.length()�� count�� �־ for���� ������ �Ѵ�.
	{
		s_vec.push_back(s);
		s.erase(0, 1);
	}

	sort(s_vec.begin(), s_vec.end());

	vector<string>::iterator itr;

	for (itr = s_vec.begin(); itr != s_vec.end(); ++itr)
		cout << *itr << '\n';

	return 0;
}