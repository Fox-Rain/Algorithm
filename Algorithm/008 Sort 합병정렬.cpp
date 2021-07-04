// Merge Sort �պ�����     <- ������������ �̿� (����������=== �ذ��ϰ����ϴ� ������ ����ũ���� "������" ������� ����)
// �պ� ==�������������ǡ��ظ������Ͽ������鼭�����������ǡ��ظ�������
// �պ������̶�?     1. �����Ͱ� ����� �迭�� ������ ������   2. ������ ��ȯ������ ����   3. ���� ���ĵ� �迭�� ���� ��ü�� ���� (�պ�)

// Tip) C3861 '~~'�ĺ��ڸ� ã�� �� �����ϴ� ���� >>>> ��, ���� ��� A�Լ����� B�Լ��� ȣ�� �Ұ�� B�� A���� ���� ������ �Ǿ��־���ϴµ� ���� A�� B���� ���� ����������� �̷� ������ �߻��� �� �ִ�.
// ȣ��Ǵ� ������ ���߾� ������, �Լ����� ������ �°� �������־�� �̷��� ������ ���� �� �ִ�.
#include<iostream>

using namespace std;

// �պ����� �Լ����� ȣ��� �պ� �Լ�
void merge(int arr[], int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = left; // new_arr�� index

	int	new_arr[8]; // �պ��� ���� �ӽ� �迭
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
			new_arr[k++] = arr[i++];

		else
			new_arr[k++] = arr[j++];
	}

	while (i <= mid) // j���� �迭��Ұ� ��� ���迭�� ������    ���� i�� �迭��Ҹ� ��� ���迭�� ����
		new_arr[k++] = arr[i++];

	while (j <= right) // i���� �迭��Ұ� ��� ���迭�� ������    ���� j�� �迮��Ҹ� ��� ���迭�� ����
		new_arr[k++] = arr[j++];

	for (int i = left; i <= right; ++i) // ���迭�� �迭�Ǿ������� �ٽ� arr�� ������ ����
	{
		arr[i] = new_arr[i];
	}
}



// �պ����� �Լ�          < �ð����⵵�� O(n logn) >
void mergeSort(int arr[], int left, int right) // ���ڷ� arr[] �迭, ������ �迭�� ù��� left, ������ �迭�� ��������� r�� �����ش�.
{
	if (left < right)
	{
		int mid = (left + right) / 2; // ������ ����� index�� �߾Ӱ� q�� �ʱ�ȭ

		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		merge(arr, left, mid, right);
	}
}

int main()
{
	int arr[] = { 3,6,8,3,2,1,6,2 };

	mergeSort(arr, 0, 7);

	for (int i = 0; i < 8; ++i)
	{
		cout << arr[i] << endl;
	}

	return 0;
}