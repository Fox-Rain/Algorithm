// https://www.acmicpc.net/problem/1302
/*
����
�������� ž������ �����̴�. �������� ���뿡�� ����� �ϴ� �����̴�. �������� �׳� �ٹ��� ���� �Ŀ�, ���� �Ǹ��� å�� ������ ���鼭 ���� ���� �ȸ� å�� ������ ĥ�ǿ� ����� �ϵ� ���� �ϰ� �ִ�.

���� �Ϸ� ���� �ȸ� å�� ������ �Է����� ������ ��, ���� ���� �ȸ� å�� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� �Ϸ� ���� �ȸ� å�� ���� N�� �־�����. �� ���� 1,000���� �۰ų� ���� �ڿ����̴�. ��°���� N���� �ٿ� å�� ������ �Է����� ���´�. å�� ������ ���̴� 50���� �۰ų� ����, ���ĺ� �ҹ��ڷθ� �̷���� �ִ�.

���
ù° �ٿ� ���� ���� �ȸ� å�� ������ ����Ѵ�. ���� ���� ���� �ȸ� å�� ���� ���� ��쿡�� ���� ������ ���� �ռ��� ������ ����Ѵ�.
*/
#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

bool Compare(pair<string, int> A, pair<string, int> B) // ******  Sort���� compare�Լ��� ���� �� A<B�� �����ͺ��� ����   A>B�� ū�ͺ��� ����  ****** //
{
	if (A.second == B.second) // 1������ �ٱ��� second�� ���ٸ�
		return A.first < B.first; // 2������ first�� ��
	return A.second > B.second; // 1������ second�� ����
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; // �ȸ� å�� ����
	cin >> N;

	unordered_map<string, int> bookCheck; // bookCheck unordered_map���� ����
	for (int i = 0; i < N; ++i)
	{
		string book; // å�̸�
		cin >> book;

		if (bookCheck.find(book) == bookCheck.end()) // ���� ���
		{
			bookCheck.insert(make_pair(book, 1));
		}
		else // �̹� ������ ���
			bookCheck[book]++;
	}

	vector<pair<string, int>>bookCheck_vec(bookCheck.begin(), bookCheck.end()); // *** vector���� pair<>�� ���ؼ� 2���� ���� �ѹ��� ������ �����ϴ�.   �׷��� map -> vector�� �ű涧 �����
																				// *** pair�� map������ ���������� first, second�� ������ �����ϴ�.
	sort(bookCheck_vec.begin(), bookCheck_vec.end(), Compare); // sort�� map���� ����� �Ұ����ϹǷ� �����������̳��� vector�� �����Ͽ��� sort�� ȣ���Ѱ���.

	cout << bookCheck_vec[0].first;

	return 0;
}