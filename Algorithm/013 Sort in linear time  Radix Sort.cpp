//Non-Comparsion-Sort
// Radix Sort     n개의 d자리 정수(문자열등 꼭 정수일 필요는 없음)들  <- 크기말고도 다른 정보가 있으므로 non-comparsion-sort인 것이다.

// Radix Sort 기수정렬   1. 맨 끝자리를 기준으로 정렬   2. 그다음자리 기준으로 정렬..... 반복   3. 첫자리 기준으로 정렬  (stable Sort 에 의해서 정렬이됨)


#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

// Radix Sort안에서 일어날 countingSort
void countingSort_in_Radix(vector<int> &arr, int d, int n) // vector와 d와 n(몇자리수를 의미하는지) 인자를 받는다.
{
	vector<int>counting_arr(10); // 0~9 index를 위해서 10개의 요소를 가진 vector

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

//Radix Sort     < 시간복잡도 O(d(n+k)) >  여기서 d는 몇자리수인지를 말한다.
void Radix_Sort(vector<int> &arr, int d) // vector와 d (몇자리 정수) 인지를 받는다.    
{
	int number_of_digits = 1; // 1의자리부터 시작

	for (int i = 0; i < d; ++i)
	{
		countingSort_in_Radix(arr, d, number_of_digits); // 자릿수를 기준으로 counting Sort

		number_of_digits *= 10; // 기준 자릿수를 변경하는 것
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