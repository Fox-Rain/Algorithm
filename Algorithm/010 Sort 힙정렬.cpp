// Heap Sort     최악의 경우 시간복잡도 O(n logn)    mergeSort등과 다르게 추가배열이 불필요 (공간복잡도가 좋음)     이진 힙( binary heap) 자료구조를 사용

// Heap (힙)이란?   1. 힙은 complete binary tree 이면서      2. heap porperty를 만족해야 한다.

// binary tree (이진트리) -> 이어지는 자식노드가 최대 2개인 트리를 말함.   이중 complete binaray	tree란  마지막레벨을 제외하고는 노드가 2개씩 꽉차있고 '마지막레벨에서만 가장 오른쪽부터 연속된
// 노드'들이 약간씩 비여있을 수 있는 트리를 말한다. (이중 마지막레벨까지 꽉 차있을 경우엔 full binary tree라고 부른다.)

// heap property를 만족한다. == max heap property || min heap property를 만족한다. (둘중 하나를 만족해야함.)
// max hip property 부모는 자식보다 크기가 크거나 같다.    min heap property 부모는 자식보다 작거나 같다

// 힙은 동일한 데이터를 가진다고 해도 힙의 모양은 제각각일 수 있다.

// 힙은 일차원 배열로 표현이 가능하다. A[1,....n]     (노드개수 n개)     < complete binary tree 이기에 배열로 표현해도 부모자식관게가 유지됨 >
// 루트노드 A[1]
// A[i]의 부모 = A{i/2]
// A[i]의 왼쪽 자식 = A[2i]
// A[i]의 오른쪽 자식 = A[2i+1] 

#include<iostream>

using namespace std;

// 힙의 기본연산 MAX-HEAPIFY   (Recursion)     유일하게 루트만이 힙을 만족시키지 않을 때 (즉, 루트만이 순차적이지 않을 경우, 또한 트리모양은 complete binary tree여야함)
// 이 상황에서 1. 루트를 자기 자신의 자식들중 큰값과 비교하여 루트<선택된 자식의값 일 경우 Swap한다 2. 이후 다시 아래의 자식노드와 똑같은 과정을 반복한다. 3. 이후 비교할 자식이 없게되면 종료한다.
// or 비교시 루트>선택된값일 경우도 종료
// build_Max_Heap에서 호출되는 함수
void max_Heapify(int arr[], int length, int i) // max_heapify    arr, 배열길이, 뿌리 indexs 1        * 함수에서 배열을 받을 경우 "포인터"로 받기 때문에 함수안에서는 배열의크기를 구할 수 없으므로,         
{                                              //                                                     함수의 파라미터로 배열의 크기를 보내준다.
	if (2 * i > (length - 1) || (2 * i + 1) > (length - 1)) // 아래에 자식노드가 없을 경우 함수종료
		return;

	int big = (arr[2 * i] > arr[2 * i + 1]) ? 2 * i : 2 * i + 1; // 자식노드들 중 큰것의 index를 big에 초기화

	if (arr[i] < arr[big]) // 자식노드 와 비교하여 부모노드가 작을 경우
	{
		// Swap //
		int Temp = arr[i];
		arr[i] = arr[big];
		arr[big] = Temp;
	}
	else // 자식노드와 비교하여 부모노드가 크거나 같을 경우 ( max_heapify대로 정렬되있는 것이므로) 함수종료
		return;

	max_Heapify(arr, length, big); // Recursion 으로 다시 max_Heapfiy를 호출하여서 아래도 정렬
}

void build_Max_Heap(int arr[], int length) // build_Max_Heap    arr, 배열길이            ( 정렬할 배열을 힙으로 만드는 함수 )
{
	for (int i = (length - 1) / 2; i > 0; --i) // (length-1)/2 부터 시작하는것은 (length-1)/2부터의 index가 적어도 1개의 자식노드를 갖는 노드이기 때문에 시작점이 된다.
	{
		max_Heapify(arr, length, i); // max_Heapify를 호출하여서 노드아래를 max_heapify대로 정렬
	}
}

// Heap Sort 힙정렬
// 1. 주어진 데이터로 힙을 만든다.      2. 힙에서 최대값(루트노드의 값) 을 가장 마지막 값과 바꾼다.      3. 힙의 크기가 1 줄어든것으로 간주한다. ( 즉, 마지막 힙의값은 없는것으로 간주한다.)
// 4. 루트노드에 대해서 max_Heapify(arr,1);          5. 2~4번을 반복한다.
// 위의 과정의 원리는 heapfiy를 통해서 "루트노드에 남은 노드에서의 최대값"을 올리고 그값을 배열에 뒤로 옯기는 과정을 반복하여서 배열을 정렬하는 것이다.
void heapSort(int arr[], int length)
{
	build_Max_Heap(arr, length); // 정렬할 배열을 일단 힙으로 만듦.

	for (int i = length - 1; i > 1; --i)
	{
		// 첫번째와 마지막 배열요소를 스왑 // 
		int Temp = arr[1];
		arr[1] = arr[i];
		arr[i] = Temp;

		length--;

		max_Heapify(arr, length, 1);	
	}
}

int main()
{
	int my_arr[] = { 0,1,13,2,4,1,6,8,3 };

	heapSort(my_arr, 9);

	for (int i = 1; i < 9; ++i)
	{
		cout << my_arr[i] << endl;
	}

	return 0;
}