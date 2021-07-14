// https://www.acmicpc.net/problem/10814
/*
문제
온라인 저지에 가입한 사람들의 나이와 이름이 가입한 순서대로 주어진다. 이때, 회원들을 나이가 증가하는 순으로, 나이가 같으면 먼저 가입한 사람이 앞에 오는 순서로 정렬하는 프로그램을 작성하시오.

입력
첫째 줄에 온라인 저지 회원의 수 N이 주어진다. (1 ≤ N ≤ 100,000)

둘째 줄부터 N개의 줄에는 각 회원의 나이와 이름이 공백으로 구분되어 주어진다. 나이는 1보다 크거나 같으며, 200보다 작거나 같은 정수이고, 이름은 알파벳 대소문자로 이루어져 있고, 길이가 100보다 작거나 같은 문자열이다. 입력은 가입한 순서로 주어진다.

출력
첫째 줄부터 총 N개의 줄에 걸쳐 온라인 저지 회원을 나이 순, 나이가 같으면 가입한 순으로 한 줄에 한 명씩 나이와 이름을 공백으로 구분해 출력한다.
*/

// map을 사용하는것 이외에도 들어가는 순서를 헤치지 않는 stable_Sort를 사용해도 된다. //
#include<iostream>
#include<map>

using namespace std;

int main()
{
	int N;
	cin >> N;

	multimap<int, string> members; // 나이를 키값으로 이용하는데  키값(나이)가 중복될 수 있으므로 multimap을 이용함
	for (int i = 0; i < N; ++i)
	{
		int age;
		string name;

		cin >> age >> name;

		members.insert(pair<int, string>(age, name));
	}

	for (auto &ele : members) // *** multimap은 내부에서 insert되고 정렬될 때, 들어가는 순서가 유지된다.
		cout << ele.first << " " << ele.second << '\n';

	return 0;
}