// https://www.acmicpc.net/problem/11720
/*
문제
N개의 숫자가 공백 없이 쓰여있다. 이 숫자를 모두 합해서 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 숫자의 개수 N (1 ≤ N ≤ 100)이 주어진다. 둘째 줄에 숫자 N개가 공백없이 주어진다.

출력
입력으로 주어진 숫자 N개의 합을 출력한다.
*/
#include<iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	char *ch = new char[N];

	int sum = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> ch[i];
		sum += (int(ch[i]) - 48); // 아스키코드 테이블을 통해서 문자형 숫자를 -> 정수형숫자로 계산
	}

	cout << sum;

	return 0;
}