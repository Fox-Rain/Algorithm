// https://www.acmicpc.net/problem/2217
/*
문제
N(1 ≤ N ≤ 100,000)개의 로프가 있다. 이 로프를 이용하여 이런 저런 물체를 들어올릴 수 있다. 각각의 로프는 그 굵기나 길이가 다르기 때문에 들 수 있는 물체의 중량이 서로 다를 수도 있다.

하지만 여러 개의 로프를 병렬로 연결하면 각각의 로프에 걸리는 중량을 나눌 수 있다. k개의 로프를 사용하여 중량이 w인 물체를 들어올릴 때, 각각의 로프에는 모두 고르게 w/k 만큼의 중량이 걸리게 된다.

각 로프들에 대한 정보가 주어졌을 때, 이 로프들을 이용하여 들어올릴 수 있는 물체의 최대 중량을 구해내는 프로그램을 작성하시오. 모든 로프를 사용해야 할 필요는 없으며, 임의로 몇 개의 로프를 골라서 사용해도 된다.

입력
첫째 줄에 정수 N이 주어진다. 다음 N개의 줄에는 각 로프가 버틸 수 있는 최대 중량이 주어진다. 이 값은 10,000을 넘지 않는 자연수이다.

출력
첫째 줄에 답을 출력한다.
*/
#include<iostream>
#include<map>
#include<climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	map<int, int>machine; // *** map선언 버틸수있는무게를 key로 그 무게를 버티는 줄의 개수를 value로 받는다.
	for (int i = 0; i < N; ++i)
	{
		int weight;
		cin >> weight;

		if (machine.find(weight) != machine.end()) // 중복일시 개수++;
			machine[weight]++;
		else
			machine.insert(make_pair(weight, 1)); // 중복아닐시 key와 value 1로 insert
	}

	// map 자료구조를 이용하였으므로, key값에 따라 "오름차순"으로 정렬되어있음
	int max = INT_MIN;
	int counting = 0;

	map<int, int>::reverse_iterator itr; // *** reverse_iterator   rbegin(), rend()을 이용하기 위해선 reverse_iterator (역방향 이터레이터)를 선언함
	for (itr = machine.rbegin(); itr != machine.rend(); ++itr)
	{
		counting += itr->second; // itr-first보다 크거나 같은 루프 개수 (counting)

		if (max < (itr->first * counting)) // max 보다 중량이 클경우
			max = (itr->first * counting); // max값을 바꾸어 줌
	}
	cout << max;

	return 0;
}