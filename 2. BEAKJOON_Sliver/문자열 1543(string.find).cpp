// https://www.acmicpc.net/problem/1543
/*
����
�����̴� ����θ� �̷���� � ������ �˻��ϴ� �Լ��� ������� �Ѵ�. �� �Լ��� � �ܾ �� �� �� �����ϴ��� ������ �Ѵ�. �׷���, �������� �Լ��� �ߺ��Ǿ� ���� ���� ���� ���� �Ѵ�. ���� ���, ������ abababa�̰�, �׸��� ã������ �ܾ ababa���, �������� �� �Լ��� �� �ܾ 0������ ã�� �� �ְ�, 2�����͵� ã�� �� �ִ�. �׷��� ���ÿ� �� ���� ����.

�����̴� ������ �˻��Ϸ��� �ܾ �־����� ��, �� �ܾ �ִ� �� �� �ߺ����� �ʰ� �����ϴ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ �־�����. ������ ���̴� �ִ� 2500�̴�. ��° �ٿ� �˻��ϰ� ���� �ܾ �־�����. �� ���̴� �ִ� 50�̴�. ������ �ܾ�� ���ĺ� �ҹ��ڿ� �������� �̷���� �ִ�.

���
ù° �ٿ� �ߺ����� �ʰ� �ִ� �� �� �����ϴ��� ����Ѵ�.
*/
#include<iostream>
#include<string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// getline�� �̿�������   string�� ��� default�δ� " "�� ������ �Է��� �׸� �����Ƿ�  getline���� �Է��� �׸��ް� �ϴ� ���ڸ� '\n'���� �ٲ�
	string document; // ����
	getline(cin, document, '\n');

	string word; // ã�� �ܾ�
	getline(cin, word, '\n');

	int count = 0;
	int index = 0;

	while (document.find(word, index) != -1) // *** <string>�� .find �޼ҵ��  ���ϴ� ���ڿ��� ã���� ��� �� ���ڿ��� �����ϴ� index, ã�� ������ ��� -1�� �����Ѵ�
	{
		count++;
		index = document.find(word, index) + word.length();
	}

	cout << count;

	return 0;
}