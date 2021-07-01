// https://www.acmicpc.net/problem/1181
/*
문제
알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.

1. 길이가 짧은 것부터
2. 길이가 같으면 사전 순으로

입력
첫째 줄에 단어의 개수 N이 주어진다. (1 ≤ N ≤ 20,000) 둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다. 주어지는 문자열의 길이는 50을 넘지 않는다.

출력
조건에 따라 정렬하여 단어들을 출력한다. 단, 같은 단어가 여러 번 입력된 경우에는 한 번씩만 출력한다.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(string i, string j)
{
	if (i.length() == j.length()) // 크기가 같다면
		return i < j; // 크기가 작은걸 앞으로가게함
	return i.length() < j.length(); // *** string객체는 <(오버로딩)을 통해서 사전식배열의 크기를 비교할 수 있다 ***  
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<string>str_arr;
	str_arr.reserve(N); // push_back시 메모리 할당할때 복사로 인한 퍼포먼스 저하를 줄이기위해 처음부터 reserve로 메모리 할당

	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;

		if (find(str_arr.begin(), str_arr.end(), str) == str_arr.end()) // find로 str을 못찾을경우  즉, 중복이 아닐 경우
			str_arr.push_back(str); // str을 push_back(str);
	}

	sort(str_arr.begin(), str_arr.end(), compare); // ***

	for (auto &ele : str_arr)
		cout << ele << '\n';

	return 0;
}