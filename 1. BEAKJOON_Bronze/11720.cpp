// https://www.acmicpc.net/problem/11720
/*
����
N���� ���ڰ� ���� ���� �����ִ�. �� ���ڸ� ��� ���ؼ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ���� N (1 �� N �� 100)�� �־�����. ��° �ٿ� ���� N���� ������� �־�����.

���
�Է����� �־��� ���� N���� ���� ����Ѵ�.
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
		sum += (int(ch[i]) - 48); // �ƽ�Ű�ڵ� ���̺��� ���ؼ� ������ ���ڸ� -> ���������ڷ� ���
	}

	cout << sum;

	return 0;
}