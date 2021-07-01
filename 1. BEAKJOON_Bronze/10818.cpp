// https://www.acmicpc.net/problem/10818
/*
문제
N개의 정수가 주어진다. 이때, 최솟값과 최댓값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정수의 개수 N (1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄에는 N개의 정수를 공백으로 구분해서 주어진다. 모든 정수는 -1,000,000보다 크거나 같고, 1,000,000보다 작거나 같은 정수이다.

출력
첫째 줄에 주어진 정수 N개의 최솟값과 최댓값을 공백으로 구분해 출력한다.
*/
#include<iostream>
#include<climits>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int max = INT_MIN; // max을 구하기 위해선 일단 처음에 가장작은수로 초기화
	int min = INT_MAX; // min을 구하기 위해선 일단 처으므에 가작큰수로 초기화
	int input;
	for (int i = 0; i < N; ++i)
	{
		cin >> input;

		if (input > max) // 최대값
			max = input;

		if (input < min) // 최소값
			min = input;
	}

	cout << min << " " << max;

	return 0;
}