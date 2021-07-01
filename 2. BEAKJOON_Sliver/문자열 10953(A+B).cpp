// https://www.acmicpc.net/problem/10953
/*
문제
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다.

각 테스트 케이스는 한 줄로 이루어져 있으며, 각 줄에 A와 B가 주어진다. A와 B는 콤마(,)로 구분되어 있다. (0 < A, B < 10)

출력
각 테스트 케이스마다 A+B를 출력한다.
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		string A;
		string B;

		getline(cin, A, ','); // ,까지 읽고 ,는 버린뒤 저장함
		getline(cin, B);

		cout << stoi(A) + stoi(B) << '\n'; // <string> stoi()는 ()안의 string을 int형으로 변환
	}

	return 0;
}