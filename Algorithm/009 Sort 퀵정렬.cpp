// Quick Sort 퀵정렬    <- quick sort 역시 분할정복법을 사용한다
// 퀵정렬은 pivot이라는 기준값을 정해 기준보다 작은것과 기준보다 큰것을오 나눈다.  어떤값을 피봇으로 사용하는가가 영향을 미치긴하나, 큰차이가 없기 때문에 이번 알고리즘은 맨뒤에 것을 피봇으로 설정한다
// 1. 피봇을 선정하여서 피봇을 기준으로 작은것 큰것을 나눈다.   2. 이후 다시 recursion(quick Sort) 한다.
// 피봇은 합병정렬과 다르게 꼭 정확히 반반이 나누어지지는 않으므로, 시간복잡도가 피봇에 따라 약간 변할 수 있다.

// Pivot //
// 첫번째나 마지막 값을 피봇으로 선택 -> 데이터가 정렬되어있을 경우 최악의 경우가 발생할 수 있음. (현실의 데이터는 정렬이 되있는 경우가 많으므로 현실에선 좋은방법이라 볼 수 없음)
// 첫째값, 마지막값,중간값 중의 크기가 중간인 값을 피봇으로 선택 (피봇이 제일크거나 제일작은 값인 경우는 없애기) -> 최악의 경우 시간복잡도가 달라지지는 않는다.
// 피봇을 렌덤으로 선택 Randomized QuickSort -> 어떤 데이터가 들어오든 운에 따라서 속도가 결정됨
#include<iostream>

using namespace std;

// partition    quick Sort에 쓰일 함수
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

// quick Sort 퀵 정렬          < 시간복잡도가 최악의 경우 O(n^2)이지만 이것은 극소수이고 대부분 O(n logn)이다. >
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