// *** Recursion�Լ��� �Ű��������� �Ͻ��� �Ű������� ����� �Ű������� �ٲپ�� *** // 
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

// "����Ž��"           "���ĵ��� ���� �����͹迭"�ȿ��� target��Ҹ� ���������� ã�°��� ����Ž���̶�� �Ѵ�.
// ���⼭ Ž�� ������ [0, n-1]�� �Ǵµ� 0�� �Ͻ��� �Ű�����, n-1�� ����� �Ű������̴�.     ��, �Ͻ����Ű������� �ٲپ��ִ°��� ����.
int search(int data[], int n, int target)
{
	for (int i = 0; i < n; ++i)
	{
		if (data[i] == target) // target��Ҹ� ã���� ���
			return i; // target����� index ����
	}
	return -1; // for���� ���������� ã�� ���Ͽ��ٸ� -1����
}

// "����Ž��" Recursion
// ���⼭ Ž�������� [begin, end]�� ���۰� ���� ��� ����� �Ű������� �ٲ����.
int search_Recursion(int data[], int begin, int end, int target)
{
	if (begin > end) // �迭 �ε����� �Ѿ�Ƿ�
		return -1; // ã�������� ���� -1
	else if (data[begin] == target) // target�� ã������
		return begin; // target index����
	else
		return search_Recursion(data, begin + 1, end, target); // ��ͷ� begin+1�Ͽ��� ȣ��
}

// "�ִ밪 ã��" Recursion
int findMax(int data[], int begin, int end)
{
	if (begin == end)
		return data[begin];
	else
		return std::max(data[begin], findMax(data, begin + 1, end));
}

int main()
{
	return 0;
}