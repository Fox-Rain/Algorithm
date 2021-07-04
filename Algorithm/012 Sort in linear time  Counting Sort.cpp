// Comparsion Sort //
// 데이터들간에 상대적인 크기관계만 이용하여서 정리하는 알고리즘   따라서 데이터들간에 크기관계가 정해져있다면 어떤 데이터드 정렬이 가능  (버블소트, 삽입정렬, 합병정렬. 퀵소트, 힙정렬)

// Non-Comparsion Sort //
// 정렬할 데이터의 사전지식을 이용( Ex) 세자리이다.  정수이다...) 제한을 더 넣을 수 있음     (Bucket Sort, Radix Sort)

// 어떤 Comparsion Sort도 시간복잡도가 nlogn보다 낮을 순 없다.    O(nlogn)이 최선 (즉 하한이다.)

// Sorting in Linear Time 선형시간 정렬 알고리즘 O(n) (Non-Comparsion Sort) //
// < Counting Sort >    n개의 정수를 정렬하라. 단, 모든 정수는 0에서 k사이의 정수이다.  <-- 사전지식이 쓰이므로, non-comparsion sort
// 1. 0~K까지 요소를 갖는 배열을 만들고, 자신index이하의 값이 몇개인지 저장한다.  2. 이후 그 배열을 보면서 그대로 다시 정렬을 해주면 된다.

#include<iostream>
#include<vector>

using namespace std;

// counting Sort Algorithm 계수정렬    < O(n) >   k가 클 경우 비실용적임   stable 정렬 알고리즘이다.
void countingSort(vector<int> &arr, int k)
{
	vector<int>counting_arr(k + 1, 0); // 받아온 vector에 요소들의 분포를 저장할 vector 생성 index가 0~k 인 vector에 모든 요소를 0으로 초기화

	for (int i = 0; i < arr.size(); ++i) // counting_arr[i] 생성 배열의 인덱스보다 작거같은값의 개수를 값으로 갖는다.    Ex) counting_arr[2]=3   배열에서 2보다작은값들은 모두 3개이다. 
	{
		for (int j = k; j >= arr[i]; --j)
		{
			counting_arr[j]++;
		}
	}

	vector<int>result_arr(arr.size()); // 정리된값을 넣을 vector
	for (int i = arr.size() - 1; i >= 0; --i) // arr[i]의 값을 result_arr의 counting_arr[arr[i]-1]에 넣어주고 counting_arr[arr[i]]값을 1개 줄이는 과정을 반복한다.
	{
		result_arr[counting_arr[arr[i]] - 1] = arr[i];
		counting_arr[arr[i]]--;
	}
	arr = result_arr; // vector arr에 result_arr값을 복사해서 넣음
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