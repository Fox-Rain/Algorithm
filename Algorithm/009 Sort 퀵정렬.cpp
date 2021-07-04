// Quick Sort ������    <- quick sort ���� ������������ ����Ѵ�
// �������� pivot�̶�� ���ذ��� ���� ���غ��� �����Ͱ� ���غ��� ū������ ������.  ����� �Ǻ����� ����ϴ°��� ������ ��ġ���ϳ�, ū���̰� ���� ������ �̹� �˰����� �ǵڿ� ���� �Ǻ����� �����Ѵ�
// 1. �Ǻ��� �����Ͽ��� �Ǻ��� �������� ������ ū���� ������.   2. ���� �ٽ� recursion(quick Sort) �Ѵ�.
// �Ǻ��� �պ����İ� �ٸ��� �� ��Ȯ�� �ݹ��� ������������ �����Ƿ�, �ð����⵵�� �Ǻ��� ���� �ణ ���� �� �ִ�.

// Pivot //
// ù��°�� ������ ���� �Ǻ����� ���� -> �����Ͱ� ���ĵǾ����� ��� �־��� ��찡 �߻��� �� ����. (������ �����ʹ� ������ ���ִ� ��찡 �����Ƿ� ���ǿ��� ��������̶� �� �� ����)
// ù°��, ��������,�߰��� ���� ũ�Ⱑ �߰��� ���� �Ǻ����� ���� (�Ǻ��� ����ũ�ų� �������� ���� ���� ���ֱ�) -> �־��� ��� �ð����⵵�� �޶������� �ʴ´�.
// �Ǻ��� �������� ���� Randomized QuickSort -> � �����Ͱ� ������ � ���� �ӵ��� ������
#include<iostream>

using namespace std;

// partition    quick Sort�� ���� �Լ�
int partition(int arr[], int p, int r)
{
	int pivot = arr[r];
	int index = 0;
	int Temp;

	for (int i = 0; i < r; ++i)
	{
		if (arr[i] < pivot)
		{
			Temp = arr[index];
			arr[index] = arr[i];
			arr[i] = Temp;

			index++;
		}
	}

	Temp = arr[index];
	arr[index] = pivot;
	arr[r] = Temp;

	return index;
}

// quick Sort �� ����          < �ð����⵵�� �־��� ��� O(n^2)������ �̰��� �ؼҼ��̰� ��κ� O(n logn)�̴�. >
void quick_Sort(int arr[], int p, int r)
{
	if (p < r)
	{
		int q = partition(arr, p, r);

		quick_Sort(arr, p, q - 1);
		quick_Sort(arr, q + 1, r);

	}
}

int main()
{
	int arr[] = { 3,3,6,1,8,4,9,2 };

	quick_Sort(arr, 0, 7);

	for (int i = 0; i < 8; ++i)
	{
		cout << arr[i] << endl;
	}
	return 0;
}