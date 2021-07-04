// Comparsion Sort //
// �����͵鰣�� ������� ũ����踸 �̿��Ͽ��� �����ϴ� �˰���   ���� �����͵鰣�� ũ����谡 �������ִٸ� � �����͵� ������ ����  (�����Ʈ, ��������, �պ�����. ����Ʈ, ������)

// Non-Comparsion Sort //
// ������ �������� ���������� �̿�( Ex) ���ڸ��̴�.  �����̴�...) ������ �� ���� �� ����     (Bucket Sort, Radix Sort)

// � Comparsion Sort�� �ð����⵵�� nlogn���� ���� �� ����.    O(nlogn)�� �ּ� (�� �����̴�.)

// Sorting in Linear Time �����ð� ���� �˰��� O(n) (Non-Comparsion Sort) //
// < Counting Sort >    n���� ������ �����϶�. ��, ��� ������ 0���� k������ �����̴�.  <-- ���������� ���̹Ƿ�, non-comparsion sort
// 1. 0~K���� ��Ҹ� ���� �迭�� �����, �ڽ�index������ ���� ����� �����Ѵ�.  2. ���� �� �迭�� ���鼭 �״�� �ٽ� ������ ���ָ� �ȴ�.

#include<iostream>
#include<vector>

using namespace std;

// counting Sort Algorithm �������    < O(n) >   k�� Ŭ ��� ��ǿ�����   stable ���� �˰����̴�.
void countingSort(vector<int> &arr, int k)
{
	vector<int>counting_arr(k + 1, 0); // �޾ƿ� vector�� ��ҵ��� ������ ������ vector ���� index�� 0~k �� vector�� ��� ��Ҹ� 0���� �ʱ�ȭ

	for (int i = 0; i < arr.size(); ++i) // counting_arr[i] ���� �迭�� �ε������� �۰Ű������� ������ ������ ���´�.    Ex) counting_arr[2]=3   �迭���� 2�������������� ��� 3���̴�. 
	{
		for (int j = k; j >= arr[i]; --j)
		{
			counting_arr[j]++;
		}
	}

	vector<int>result_arr(arr.size()); // �����Ȱ��� ���� vector
	for (int i = arr.size() - 1; i >= 0; --i) // arr[i]�� ���� result_arr�� counting_arr[arr[i]-1]�� �־��ְ� counting_arr[arr[i]]���� 1�� ���̴� ������ �ݺ��Ѵ�.
	{
		result_arr[counting_arr[arr[i]] - 1] = arr[i];
		counting_arr[arr[i]]--;
	}
	arr = result_arr; // vector arr�� result_arr���� �����ؼ� ����
}

int main()
{
	vector<int>arr = { 6,3,0,9 };

	countingSort(arr, 9);

	for (int i = 0; i < arr.size(); ++i)
	{
		cout << arr[i] << endl;
	}

	return 0;
}