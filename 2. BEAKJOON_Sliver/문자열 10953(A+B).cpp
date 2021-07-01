// https://www.acmicpc.net/problem/10953
/*
����
�� ���� A�� B�� �Է¹��� ����, A+B�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����.

�� �׽�Ʈ ���̽��� �� �ٷ� �̷���� ������, �� �ٿ� A�� B�� �־�����. A�� B�� �޸�(,)�� ���еǾ� �ִ�. (0 < A, B < 10)

���
�� �׽�Ʈ ���̽����� A+B�� ����Ѵ�.
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

		getline(cin, A, ','); // ,���� �а� ,�� ������ ������
		getline(cin, B);

		cout << stoi(A) + stoi(B) << '\n'; // <string> stoi()�� ()���� string�� int������ ��ȯ
	}

	return 0;
}