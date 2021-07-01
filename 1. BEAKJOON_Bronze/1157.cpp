// https://www.acmicpc.net/problem/1157
/*
����
���ĺ� ��ҹ��ڷ� �� �ܾ �־�����, �� �ܾ�� ���� ���� ���� ���ĺ��� �������� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�. ��, �빮�ڿ� �ҹ��ڸ� �������� �ʴ´�.

�Է�
ù° �ٿ� ���ĺ� ��ҹ��ڷ� �̷���� �ܾ �־�����. �־����� �ܾ��� ���̴� 1,000,000�� ���� �ʴ´�.

���
ù° �ٿ� �� �ܾ�� ���� ���� ���� ���ĺ��� �빮�ڷ� ����Ѵ�. ��, ���� ���� ���� ���ĺ��� ���� �� �����ϴ� ��쿡�� ?�� ����Ѵ�.
*/
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str;
	cin >> str;

	int arr[26] = { 0 };

	for (int i = 0; i < str.length(); ++i)
	{
		str[i] = toupper(str[i]); // �ҹ��� �빮�� ������ ���� ������ ��� �빮�ڷ� �ٲ۴�.

		arr[int(str[i]) - 65]++; // ���ĺ����� ��� �������� �迭�� ǥ��
	}

	int max = 0;
	int count = 0;
	int target;
	for (int i = 0; i < 26; ++i) // max���� index�� target�� �����ϸ�, count�� 1�̻��� �ɰ��(��, ������ ���� �迭��Ұ� 2���̻��� ���)�� ?, count�� 0�� ��� char(target+65)
	{
		if (max < arr[i])
		{
			max = arr[i];
			count = 0;
			target = i;
		}
		else if (max == arr[i])
			count++;
	}

	if (count >= 1)
		cout << "?";
	else
		cout << char(target + 65);

	return 0;
}