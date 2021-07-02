// https://www.acmicpc.net/problem/9375
/*
����
�غ��̴� �мǿ� �ſ� �ΰ��ؼ� �ѹ� �Ծ��� �ʵ��� ������ ���� �ٽ� ���� �ʴ´�. ���� ��� ���� �غ��̰� �Ȱ�, ��Ʈ, ����, �Ź��� �Ծ��ٸ�, �������� ������ �߰��� �԰ų� �Ȱ��� ��� �����ϰų� �ؾ��Ѵ�. �غ��̰� ���� �ǻ���� �־������� ���� �غ��̴� �˸��� �ƴ� ���·� ��ĥ���� �ۿ� ���ƴٴ� �� ������?

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� �־�����. �׽�Ʈ ���̽��� �ִ� 100�̴�.

�� �׽�Ʈ ���̽��� ù° �ٿ��� �غ��̰� ���� �ǻ��� �� n(0 �� n �� 30)�� �־�����.
���� n������ �غ��̰� ���� �ǻ��� �̸��� �ǻ��� ������ �������� ���еǾ� �־�����. ���� ������ �ǻ��� �ϳ��� ���� �� �ִ�.
��� ���ڿ��� 1�̻� 20������ ���ĺ� �ҹ��ڷ� �̷���������� ���� �̸��� ���� �ǻ��� �������� �ʴ´�.

���
�� �׽�Ʈ ���̽��� ���� �غ��̰� �˸��� �ƴ� ���·� �ǻ��� ���� �� �ִ� ��츦 ����Ͻÿ�.
*/

#include<iostream>
#include<map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int c; // case ����
	cin >> c;

	for (int i = 0; i < c; ++i)
	{
		int clothes_count; // ���� �ǻ� ��
		cin >> clothes_count;

		map<string, int> fashion; // fashion    map�� ����
		for (int j = 0; j < clothes_count; ++j)
		{
			string clothes_type; // �ǻ� ����
			string clothes_name; // �ǻ� �̸�

			cin >> clothes_name >> clothes_type;

			if (fashion.find(clothes_type) == fashion.end()) // clothes_type�� �������� ���� ���
				fashion.insert(make_pair(clothes_type, 1));

			else // clothes_type�� ������ ���
				fashion[clothes_type]++; // clothes_type�� +1
		}

		int sum = 1;
		map<string, int>::iterator itr;
		for (itr = fashion.begin(); itr != fashion.end(); ++itr)
		{
			sum *= ((itr->second) + 1); // map������ tierator�� ���ٽ� Ű���� -> first    ���� -> second
		}

		cout << sum - 1 << '\n';
	}

	return 0;
}