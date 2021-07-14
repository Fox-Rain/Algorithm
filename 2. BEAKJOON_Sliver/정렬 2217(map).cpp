// https://www.acmicpc.net/problem/2217
/*
����
N(1 �� N �� 100,000)���� ������ �ִ�. �� ������ �̿��Ͽ� �̷� ���� ��ü�� ���ø� �� �ִ�. ������ ������ �� ���⳪ ���̰� �ٸ��� ������ �� �� �ִ� ��ü�� �߷��� ���� �ٸ� ���� �ִ�.

������ ���� ���� ������ ���ķ� �����ϸ� ������ ������ �ɸ��� �߷��� ���� �� �ִ�. k���� ������ ����Ͽ� �߷��� w�� ��ü�� ���ø� ��, ������ �������� ��� ���� w/k ��ŭ�� �߷��� �ɸ��� �ȴ�.

�� �����鿡 ���� ������ �־����� ��, �� �������� �̿��Ͽ� ���ø� �� �ִ� ��ü�� �ִ� �߷��� ���س��� ���α׷��� �ۼ��Ͻÿ�. ��� ������ ����ؾ� �� �ʿ�� ������, ���Ƿ� �� ���� ������ ��� ����ص� �ȴ�.

�Է�
ù° �ٿ� ���� N�� �־�����. ���� N���� �ٿ��� �� ������ ��ƿ �� �ִ� �ִ� �߷��� �־�����. �� ���� 10,000�� ���� �ʴ� �ڿ����̴�.

���
ù° �ٿ� ���� ����Ѵ�.
*/
#include<iostream>
#include<map>
#include<climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	map<int, int>machine; // *** map���� ��ƿ���ִ¹��Ը� key�� �� ���Ը� ��Ƽ�� ���� ������ value�� �޴´�.
	for (int i = 0; i < N; ++i)
	{
		int weight;
		cin >> weight;

		if (machine.find(weight) != machine.end()) // �ߺ��Ͻ� ����++;
			machine[weight]++;
		else
			machine.insert(make_pair(weight, 1)); // �ߺ��ƴҽ� key�� value 1�� insert
	}

	// map �ڷᱸ���� �̿��Ͽ����Ƿ�, key���� ���� "��������"���� ���ĵǾ�����
	int max = INT_MIN;
	int counting = 0;

	map<int, int>::reverse_iterator itr; // *** reverse_iterator   rbegin(), rend()�� �̿��ϱ� ���ؼ� reverse_iterator (������ ���ͷ�����)�� ������
	for (itr = machine.rbegin(); itr != machine.rend(); ++itr)
	{
		counting += itr->second; // itr-first���� ũ�ų� ���� ���� ���� (counting)

		if (max < (itr->first * counting)) // max ���� �߷��� Ŭ���
			max = (itr->first * counting); // max���� �ٲپ� ��
	}
	cout << max;

	return 0;
}