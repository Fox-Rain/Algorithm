// https://www.acmicpc.net/problem/10818
/*
����
N���� ������ �־�����. �̶�, �ּڰ��� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ���� N (1 �� N �� 1,000,000)�� �־�����. ��° �ٿ��� N���� ������ �������� �����ؼ� �־�����. ��� ������ -1,000,000���� ũ�ų� ����, 1,000,000���� �۰ų� ���� �����̴�.

���
ù° �ٿ� �־��� ���� N���� �ּڰ��� �ִ��� �������� ������ ����Ѵ�.
*/
#include<iostream>
#include<climits>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int max = INT_MIN; // max�� ���ϱ� ���ؼ� �ϴ� ó���� ������������ �ʱ�ȭ
	int min = INT_MAX; // min�� ���ϱ� ���ؼ� �ϴ� ó���ǿ� ����ū���� �ʱ�ȭ
	int input;
	for (int i = 0; i < N; ++i)
	{
		cin >> input;

		if (input > max) // �ִ밪
			max = input;

		if (input < min) // �ּҰ�
			min = input;
	}

	cout << min << " " << max;

	return 0;
}