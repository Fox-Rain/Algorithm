// https://www.acmicpc.net/problem/11656
/*
문제
접미사 배열은 문자열 S의 모든 접미사를 사전순으로 정렬해 놓은 배열이다.

baekjoon의 접미사는 baekjoon, aekjoon, ekjoon, kjoon, joon, oon, on, n 으로 총 8가지가 있고, 이를 사전순으로 정렬하면, aekjoon, baekjoon, ekjoon, joon, kjoon, n, on, oon이 된다.

문자열 S가 주어졌을 때, 모든 접미사를 사전순으로 정렬한 다음 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 문자열 S가 주어진다. S는 알파벳 소문자로만 이루어져 있고, 길이는 1,000보다 작거나 같다.

출력
첫째 줄부터 S의 접미사를 사전순으로 한 줄에 하나씩 출력한다.
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
	for (int i = 0; i < count; ++i) // *** 주의할점 s.length()을 count 대신에 넣게되면  erase할때마다 length가 줄어드므로 처음의 s.length()을 count에 넣어서 for문을 돌려야 한다.
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