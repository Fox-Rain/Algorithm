#include<iostream>
#include<typeinfo>

using namespace std;

// Selection Sort 선택정렬                < 제자리정렬 알고리즘의 하나 (입력된 데이터 외에 추가 메모리를 요구하지 않음)    시간복잡도가 O(n^2) >
// 선택정렬은 남은배열에서 가장크거나 작은수를 맨뒤나 맨앞의 배열과 스와핑하여 정렬하는 알고리즘을 말한다.
void selection_Sort(int arr[], int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int index = NULL; // index

		int max = INT_MIN; // 최대값 구할때에는 초기값을 가장 작은걸로 초기화해두어야함
		// 최대값과 최대값의 index 구하는 for문 // 
		for (int j = 0; j < n - i; ++j)
		{
			if (max > arr[j])
				max;

			else
			{
				max = arr[j];
				index = j; // max = arr[j]; 될때마다 max값이 갱신되므로 그떄의 index를 저장함
			}
		}
		// Swap    최대값과 배열의 지금에서의 맨뒤의값을 스와핑 //
		int Temp = arr[index];
		arr[index] = arr[n - i - 1];
		arr[n - i - 1] = Temp;
	}
}

// Bubble Sort 버블정렬                   < 시간복잡도가 O(n^2) >

void bubble_Sort(int arr[], int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1]) // 인접한 두 요소가 순차적이지 않을 경우 두 요소를 Swap
			{
				// Swap  
				int Temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = Temp;
			}
		}
	}
}

// Insertion Sort 삽입정렬                < 최선의 경우 O(n)이라는 빠른 효율성을 가지나, 최악의 경우 O(n^2)이라는 시간복잡도를 가지게 된다. 데이터 크기와 상태에 따라 차이가 큼. 시간복잡도가 O(n^2) >

void insertion_Sort(int array[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int j;

		int tmp = array[i];
		for (j = i - 1; j > -1; j--)
		{
			if (array[j] > tmp)
			{
				array[j + 1] = array[j];
			}
			else
				break;
		}

		array[j + 1] = tmp;
	}
}

int main()
{
	int selection[5] = { 1,6,3,8,2 };
	selection_Sort(selection, 5);

	for (int i = 0; i < 5; ++i)
	{
		cout << selection[i] << endl;
	}


	int bubble[5] = { 3,3,9,5,2 };
	bubble_Sort(bubble, 5);

	for (int i = 0; i < 5; ++i)
	{
		cout << bubble[i] << endl;
	}

	int insertion[5] = { 3,6,7,4,1 };
	insertion_Sort(insertion, 5);

	for (int i = 0; i < 5; ++i)
	{
		cout << insertion[i] << endl;
	}

	return 0;
}