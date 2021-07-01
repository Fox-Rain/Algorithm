// https://www.acmicpc.net/problem/1316
/*
문제
그룹 단어란 단어에 존재하는 모든 문자에 대해서, 각 문자가 연속해서 나타나는 경우만을 말한다. 예를 들면, ccazzzzbb는 c, a, z, b가 모두 연속해서 나타나고, kin도 k, i, n이 연속해서 나타나기 때문에 그룹 단어이지만, aabbbccb는 b가 떨어져서 나타나기 때문에 그룹 단어가 아니다.

단어 N개를 입력으로 받아 그룹 단어의 개수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 단어의 개수 N이 들어온다. N은 100보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에 단어가 들어온다. 단어는 알파벳 소문자로만 되어있고 중복되지 않으며, 길이는 최대 100이다.

출력
첫째 줄에 그룹 단어의 개수를 출력한다.
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
	cin >> N; // case개수를 받음

	int count = 0; // 그룹단어 count
	string str;
	for (int i = 0; i < N; ++i)
	{
		cin >> str;

		int j = 0;
		vector<char>ch;
		while (str[j] != '\0') // Null character가 아닐경우 루프를 돌림
		{
			if (str[j] != str[j + 1])
			{
				ch.push_back(str[j]);

				vector<char>::iterator itr;
				itr = find(ch.begin(), ch.end(), str[j + 1]); // <algorithm>의 find메소드  str[j+1]이 있다면 그 index의 iterator를 리턴하고, 만약 없다면 .end() iterator을 리턴함

				if (itr != ch.end()) // str[j+1]이 있을 경우
					break;
			}

			j++;
		}

		if (str[j] == '\0') // while문을 끝까지 돌았으므로 그룹단어이다.
			count++;
	}

	cout << count;

	return 0;
}