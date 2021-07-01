// https://www.acmicpc.net/problem/10610
/*
문제
어느 날, 미르코는 우연히 길거리에서 양수 N을 보았다. 미르코는 30이란 수를 존경하기 때문에, 그는 길거리에서 찾은 수에 포함된 숫자들을 섞어 30의 배수가 되는 가장 큰 수를 만들고 싶어한다.

미르코를 도와 그가 만들고 싶어하는 수를 계산하는 프로그램을 작성하라.

입력
N을 입력받는다. N는 최대 105개의 숫자로 구성되어 있으며, 0으로 시작하지 않는다.

출력
미르코가 만들고 싶어하는 수가 존재한다면 그 수를 출력하라. 그 수가 존재하지 않는다면, -1을 출력하라.
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string N;
	cin >> N;

	int sum = 0;
	bool zero_flag = false;
	for (int i = 0; i < N.length(); ++i)
	{
		if (N[i] == '0')
			zero_flag = true;

		sum += N[i] - '0'; // *** atoi()의 경우는 문자열을 숫자로 바꾸기 때문에 여기서는 사용하기에 적합하지 않다.     문자인 숫자를 정수인 숫자로 나타내기
	}

	if (zero_flag == true && sum % 3 == 0)
	{
		sort(N.begin(), N.end(), [](int i, int j) {return i > j; });
		cout << N;
	}
	else
		cout << "-1";
	return 0;
}