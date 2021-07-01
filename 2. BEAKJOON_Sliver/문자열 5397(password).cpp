// https://www.acmicpc.net/problem/5397
/*
����
â���̴� �������� ��й�ȣ�� ��ġ�� ���ؼ� �����̰� ����ϴ� ��ǻ�Ϳ� Ű�ΰŸ� ��ġ�ߴ�. ��ĥ�� ��ٸ� ���� â���̴� �����̰� ��й�ȣ â�� �Է��ϴ� ���ڸ� ���´�.

Ű�ΰŴ� ����ڰ� Ű���带 ���� ����� ��� ����Ѵ�. ����, �����̰� ��й�ȣ�� �Է��� ��, ȭ��ǥ�� �齺���̽��� �Է��ص� ��Ȯ�� ��й�ȣ�� �˾Ƴ� �� �ִ�.

�����̰� ��й�ȣ â���� �Է��� Ű�� �־����� ��, �������� ��й�ȣ�� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ������ �־�����. �� �׽�Ʈ ���̽��� ���ٷ� �̷���� �ְ�, �����̰� �Է��� ������� ���̰� L�� ���ڿ��� �־�����. (1 �� L�� ���� �� 1,000,000) �����̰� �齺���̽��� �Է��ߴٸ�, '-'�� �־�����. �̶� Ŀ���� �ٷ� �տ� ���ڰ� �����Ѵٸ�, �� ���ڸ� �����. ȭ��ǥ�� �Է��� '<'�� '>'�� �־�����. �̶��� Ŀ���� ��ġ�� ������ �� �ִٸ�, ���� �Ǵ� ���������� 1��ŭ �����δ�. ������ ���ڴ� ��й�ȣ�� �Ϻ��̴�. ����, ���߿� �齺���̽��� ���ؼ� ���� ���� �ִ�. ���� Ŀ���� ��ġ�� ���� �������� �ƴ϶��, Ŀ�� �� Ŀ�� �����ʿ� �ִ� ��� ���ڴ� ���������� �� ĭ �̵��Ѵ�.

���
�� �׽�Ʈ ���̽��� ���ؼ�, �������� ��й�ȣ�� ����Ѵ�. ��й�ȣ�� ���̴� �׻� 0���� ũ��.
*/

/*
// vector�� �̿��� Ǯ�� //    <--- insert�� erase�� �ð����⵵�� ũ�⶧���� �ð��ʰ��� �Ͼ��.  insert, erase  O(n)  n�� �����Һ��� ���õ� ���ұ����� �Ÿ�

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int c;
	cin >> c; // ���̽� ����

	string keyboard_input; // Ű���� ��ǲ

	while (c--)
	{
		cin >> keyboard_input;
		int corsur_index = 0;
		vector <char> password; // password

		for (int i = 0; i < keyboard_input.size(); i++)
		{
			if (keyboard_input[i] == '<')
			{
				if (corsur_index == 0) // Ŀ���� �Ǿ��� ��� �������� ����
					continue;
				corsur_index--;
			}
			else if (keyboard_input[i] == '>')
			{
				if (corsur_index == password.size()) // Ŀ���� �ǵ��� ��� �������� ����
					continue;
				corsur_index++;
			}
			else if (keyboard_input[i] == '-')
			{
				if (corsur_index == 0) // Ŀ���� �Ǿ��� ��� ������ ����
					continue;
				password.erase(password.begin() + corsur_index - 1); // Ŀ���� �Ǿ��� �ƴ� ��� ����
				corsur_index--;
			}
			else // keyboard_input�� ���ڳ� ������ ���
			{
				password.insert(password.begin() + corsur_index, keyboard_input[i]); // *** insert�� �Լ���ü�� �˾Ƽ� size�� �۴ٸ� size�� �ø��� (���Ҹ� �ø�) ***
				corsur_index++;
			}
		}

		for (int i = 0; i < password.size(); i++)
			cout << password[i];

		cout << endl;
	}

	return 0;
}
*/

// list�� �̿��� Ǯ�� // �ð��ʰ��� ���� �ʴ´�.   list�� ���԰� ������ ȿ�����̱� ������ �����.
#include<iostream>
#include<list>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int c;
	cin >> c; // case ����

	for (int i = 0; i < c; ++i)
	{
		string keyboard_input;
		cin >> keyboard_input; // Ű���� ��ǲ

		list<char>password; // �н�����
		list<char>::iterator cursor = password.begin();
		for (int j = 0; j < keyboard_input.size(); ++j)
		{
			if (keyboard_input[j] == '-')
			{
				if (cursor != password.begin())
					cursor = password.erase(--cursor); // *** passwrod.erase(--cursor);�� ������ ���.  insert�� erase�� �ϰԵǸ� iterator�� ��ġ�� �ٲ�� �����̴�. ���� iterator���� �ٽ� cursor�� ��������� �Ѵ�.
			}
			else if (keyboard_input[j] == '<')
			{
				if (cursor != password.begin())
					cursor--;
			}
			else if (keyboard_input[j] == '>')
			{
				if (cursor != password.end())
					cursor++;
			}
			else
			{
				password.insert(cursor, keyboard_input[j]);
			}
		}

		list<char>::iterator print;
		for (print = password.begin(); print != password.end(); ++print)
			cout << *print;
		cout << endl;
	}

	return 0;
}