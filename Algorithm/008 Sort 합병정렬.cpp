// Merge Sort 합병정렬     <- 분할정복법을 이용 (분할정복법=== 해결하고자하는 문제를 작은크기의 "동일한" 문제들로 분할)
// 합병 ==　작은문제들의　해를　합하여　보면서　원래문제의　해를　구함
// 합병정렬이란?     1. 데이터가 저장된 배열을 반으로 나누고   2. 각각을 순환적으로 정렬   3. 그후 정렬된 배열을 합쳐 전체를 정렬 (합병)

// Tip) C3861 '~~'식별자를 찾을 수 없습니다 오류 >>>> 즉, 예를 들어 A함수에서 B함수를 호출 할경우 B가 A보다 먼저 선언이 되어있어야하는데 만약 A가 B보다 먼저 선언되있으면 이런 오류가 발생할 수 있다.
// 호출되는 순서에 맞추어 변수나, 함수등을 순서에 맞게 선언해주어야 이러한 오류를 피할 수 있다.
#include<iostream>

using namespace std;

// 합병정렬 함수에서 호출될 합병 함수
void merge(int arr[], int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = left; // new_arr용 index

	int	new_arr[8]; // 합병시 쓰일 임시 배열
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
			new_arr[k++] = arr[i++];

		else
			new_arr[k++] = arr[j++];
	}

	while (i <= mid) // j쪽의 배열요소가 모두 새배열에 들어갔을때    남은 i의 배열요소를 모두 새배열에 넣음
		new_arr[k++] = arr[i++];

	while (j <= right) // i쪽의 배열요소가 모두 새배열에 들어갔을때    남은 j의 배엶요소를 모두 새배열에 넣음
		new_arr[k++] = arr[j++];

	for (int i = left; i <= right; ++i) // 새배열에 배열되었던것을 다시 arr에 복사해 넣음
	{
		arr[i] = new_arr[i];
	}
}



// 합병정렬 함수          < 시간복잡도는 O(n logn) >
void mergeSort(int arr[], int left, int right) // 인자로 arr[] 배열, 정렬할 배열의 첫요소 left, 정렬할 배열의 마지막요소 r을 보내준다.
{
	if (left < right)
	{
		int mid = (left + right) / 2; // 정렬할 요소의 index의 중앙값 q를 초기화

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