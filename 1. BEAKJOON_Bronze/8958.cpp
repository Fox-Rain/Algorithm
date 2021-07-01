// https://www.acmicpc.net/problem/8958
/*
����
"OOXXOXXOOO"�� ���� OX������ ����� �ִ�.O�� ������ ���� ���̰�, X�� ������ Ʋ�� ���̴�.������ ���� ��� �� ������ ������ �� �������� ���ӵ� O�� ������ �ȴ�.���� ���, 10�� ������ ������ 3�� �ȴ�.

"OOXXOXXOOO"�� ������ 1 + 2 + 0 + 0 + 1 + 0 + 0 + 1 + 2 + 3 = 10���̴�.

OX������ ����� �־����� ��, ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ������ �־�����.�� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ְ�, ���̰� 0���� ũ�� 80���� ���� ���ڿ��� �־�����.���ڿ��� O�� X������ �̷���� �ִ�.

���
�� �׽�Ʈ ���̽����� ������ ����Ѵ�.
*/
#include<iostream>
#include<cstring> // strlen()�� ���ؼ� include

using namespace std;

int main()
{
	int num;
	cin >> num;

	for (int i = 0; i < num; ++i)
	{
		char ch[80]; // char�迭���� ���ڰ� ���� �Ҵ� �迭��Ҵ� '\0'���� �� ä������.
		cin >> ch;

		int sum = 0;
		int count = 0;
		for (int j = 0; j < strlen(ch); ++j)
		{
			if (ch[j] == 'O')
			{
				count++;
				sum += count;
			}
			else if (ch[j] == 'X')
			{
				count = 0;
			}
		}

		cout << sum << "\n";
	}
	return 0;
}