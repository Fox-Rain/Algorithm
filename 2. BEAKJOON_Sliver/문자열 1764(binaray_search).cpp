// https://www.acmicpc.net/problem/1764
/*
문제
김진영이 듣도 못한 사람의 명단과, 보도 못한 사람의 명단이 주어질 때, 듣도 보도 못한 사람의 명단을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 듣도 못한 사람의 수 N, 보도 못한 사람의 수 M이 주어진다. 이어서 둘째 줄부터 N개의 줄에 걸쳐 듣도 못한 사람의 이름과, N+2째 줄부터 보도 못한 사람의 이름이 순서대로 주어진다. 이름은 띄어쓰기 없이 영어 소문자로만 이루어지며, 그 길이는 20 이하이다. N, M은 500,000 이하의 자연수이다.



듣도 못한 사람의 명단에는 중복되는 이름이 없으며, 보도 못한 사람의 명단도 마찬가지이다.

출력
듣보잡의 수와 그 명단을 사전순으로 출력한다.
*/

// 여기에서 일반적인 선형탬색을 사용하게 되면 시간초과가 발생한다.  따라서 sort를 통하여 사전순으로 정렬한되, binary_search(이진탐색)을 통하여 교집합을 찾는다.
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int N;
	int M;
	cin >> N >> M;

	int count = 0; // 개수

	vector<string>names;
	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;

		names.push_back(str);
	}

	sort(names.begin(), names.end()); // 처음받은 string vector을 사전순으로 정렬

	vector<string>result;
	for (int i = 0; i < M; ++i)
	{
		string str;
		cin >> str;

		if (binary_search(names.begin(), names.end(), str)) // names vector은 정렬이 되어있으므로 binary_search를 사용할 수 있다.  즉, str이 names vector안에 존재한다면
		{
			count++; // count를 올리고
			result.push_back(str); // result vector에 그 문자열을 push back해준다.
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