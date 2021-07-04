// 힙의 응용: 우선순위 큐 (최대우선순위 큐, 최소우선순위 큐)        "큐" 란? 데이터를 넣어둘 수 있는 컨테이너인데, 대이터를 꺼낼때는 "FIFO" (first int first out)의 특징을 가지고 있다.
// 즉, 먼저들어온 데이터가 먼저나가게 되는 뚫린 통로와 같은 형태를 하고 있다.
// 여러 큐 중 최대 우선순위 큐는 데이터를 꺼낼때 현제 큐에 있는 값들중 우선순위 값이 최대인값을 꺼내는 큐를 말한다.
// 즉 최대 우선순위큐는 INsert(삽입)과 Max_out(최대값을 꺼냄)을 가지고 있다.

// Insert Algorithm     1. 노드의 추가가 일어날 경우 힙의 구조를 유지해야하기 때문에 무조건 마지막 index+1부분에 추가가 되어야 한다. (binary tree만족을 위해)
// 2. 추가후 max_property를 유지못할 수 있으므로 새로들어온 노드와 그노드의 부모들과의 비교를 통해서 property가 만족될때까지 올리면서 부모와만 비교를 하면 된다.

// Extract_Max Algorithm     1. arr[1]의 값을 일단 저장해둔다(최대값)    2. heap을 유지해야하므로 arr의 맨끝의 배열요소를 arr[1]에 대입하고, arr맨끝값을 제거한다.
// 3. max property가 깨졌을 수있으므로 heapify를 통해 property를 다시 지켜준다.    4. 처음 저장해두었던 최대값을 리턴한다.

#include<iostream>
#include<vector>

using namespace std;

void max_Heapify(vector<int> &arr, int i)
{

	if (2 * i > arr.size() - 1) // 자식노드 아에 없을때
		return;
	if (2 * i + 1 <= arr.size() - 1)
	{
		int big = (arr[2 * i] > arr[2 * i + 1]) ? 2 * i : 2 * i + 1;

		if (arr[i] < arr[big])
		{
			int Temp = arr[i];
			arr[i] = arr[big];
			arr[big] = Temp;
		}
		else
			return;

		max_Heapify(arr, big);
	}
	else
	{
		if (arr[i] < arr[2 * i]) {
			int Temp = arr[i];
			arr[i] = arr[2 * i];
			arr[2 * i] = Temp;
		}
		else
			return;

		max_Heapify(arr, 2 * i);
	}
}

// Insert Algorithm 삽입 알고리즘     ( 새 값을 넣고 다시 Max_property를 만족하는 힙으로 만들어주는 함수 )    < 시간복잡도 O(log n)
void max_Heap_Insert(vector<int> &arr, int key) // 함수내부에서 값을 바꾸어야하기 때문에 vector<int>을 &arr 래퍼런스로 받아야 한다.  &arr 배열, key 넣을값을 의미
{
	arr.push_back(key); // 배열의 맨뒤 요소에 key값을 넣음 (메모리할당이 되어있지 않으면 알아서 메모리 할당해서 넣어준다.)
						// Tip) *** 주의할점   arr.capacity(); capacity는 allocator에 따라서 자신이 맘대로 메모리를 더 할당하기도 하므로  메모리할당이 얼마가 될지 알 수 없다. 
						// 이런식으로 메모리 할당을 하는 이유는 push_back이 일어날때 마다 동적할당을 하면, 비효율적이므로 미리 정해둔 만큼 동적할당을 한번에 하는 것 입니다.

	int i = arr.size() - 1; // 값이 들어가있는 배열 요소중 끝의 값의 index를 i에 초기화

	while (i > 1 && arr[i / 2] < arr[i]) // i>1이면서 부모노드보다 자식노드가 클 경우
	{
		// Swap //
		int Temp = arr[i];
		arr[i] = arr[i / 2];
		arr[i / 2] = Temp;

		i /= 2; // index를 부모노드의 index로 바꿈
	}
}

// Extract_Max Algorithm 최대값 추출 알고리즘
int Extract_Max(vector<int> &arr)
{
	int result = arr[1]; // index 1에서의 값이 max property에서는 최대값이므로 그값은 result로 초기화

	arr[1] = arr[arr.size() - 1]; // arr[1]에 arr의 마지막 값을 대입해주고
	arr.pop_back(); // 마지막의 arr요소는 pop_back()을 통해서 제거

	// Heapify //
	max_Heapify(arr, 1);

	return result;
}

int main()
{
	vector<int>arr = { 0,10,9,9,7,4,3,2,1 };

	cout << Extract_Max(arr) << endl;

	for (int i = 1; i < arr.size(); ++i)
	{
		cout << arr[i] << endl;
	}
	return 0;
}