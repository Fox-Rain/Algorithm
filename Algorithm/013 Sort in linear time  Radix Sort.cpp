//Non-Comparsion-Sort
// Radix Sort     n���� d�ڸ� ����(���ڿ��� �� ������ �ʿ�� ����)��  <- ũ�⸻�� �ٸ� ������ �����Ƿ� non-comparsion-sort�� ���̴�.

// Radix Sort �������   1. �� ���ڸ��� �������� ����   2. �״����ڸ� �������� ����..... �ݺ�   3. ù�ڸ� �������� ����  (stable Sort �� ���ؼ� �����̵�)


#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

// Radix Sort�ȿ��� �Ͼ countingSort
void countingSort_in_Radix(vector<int> &arr, int d, int n) // vector�� d�� n(���ڸ����� �ǹ��ϴ���) ���ڸ� �޴´�.
{
	vector<int>counting_arr(10); // 0~9 index�� ���ؼ� 10���� ��Ҹ� ���� vector

	for (int i = 0; i < arr.size(); ++i)
	{
		for (int j = 9; j >= ((arr[i] / n) % 10); --j)
		{
			counting_arr[j]++;
		}
	}

	vector<int>result_arr(arr.size());
	for (int i = arr.size() - 1; i >= 0; --i)
	{
		result_arr[counting_arr[((arr[i] / n) % 10)] - 1] = arr[i];
		counting_arr[((arr[i] / n) % 10)]--;
	}

	arr = result_arr;
}

//Radix Sort     < �ð����⵵ O(d(n+k)) >  ���⼭ d�� ���ڸ��������� ���Ѵ�.
void Radix_Sort(vector<int> &arr, int d) // vector�� d (���ڸ� ����) ������ �޴´�.    
{
	int number_of_digits = 1; // 1���ڸ����� ����

	for (int i = 0; i < d; ++i)
	{
		countingSort_in_Radix(arr, d, number_of_digits); // �ڸ����� �������� counting Sort

		number_of_digits *= 10; // ���� �ڸ����� �����ϴ� ��
	}
}

int main()
{
	vector<int>arr{ 123,253,634,443,735,979 };

	Radix_Sort(arr, 3);

	for (int i = 0; i < arr.size(); ++i)
	{
		cout << arr[i] << endl;
	}

	return 0;
}