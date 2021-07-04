// *** Recursion함수의 매개변수들은 암시적 매개변수를 명시적 매개변수로 바꾸어라 *** // 
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

// "순차탐색"           "정렬되지 않은 데이터배열"안에서 target요소를 순차적으로 찾는것을 순차탐색이라고 한다.
// 여기서 탐색 구간은 [0, n-1]이 되는데 0은 암시적 매개변수, n-1은 명시적 매개변수이다.     즉, 암시적매개변수는 바꾸어주는것이 좋다.
int search(int data[], int n, int target)
{
	for (int i = 0; i < n; ++i)
	{
		if (data[i] == target) // target요소를 찾았을 경우
			return i; // target요소의 index 리턴
	}
	return -1; // for문이 끝났음에도 찾지 못하였다면 -1리턴
}

// "순차탐색" Recursion
// 여기서 탐색구가는 [begin, end]로 시작과 끝이 모두 명시적 매개변수로 바뀌었다.
int search_Recursion(int data[], int begin, int end, int target)
{
	if (begin > end) // 배열 인덱스를 넘어서므로
		return -1; // 찾지못했음 리턴 -1
	else if (data[begin] == target) // target을 찾았을때
		return begin; // target index리턴
	else
		return search_Recursion(data, begin + 1, end, target); // 재귀로 begin+1하여서 호출
}

// "최대값 찾기" Recursion
int findMax(int data[], int begin, int end)
{
	if (begin == end)
		return data[begin];
	else
		return std::max(data[begin], findMax(data, begin + 1, end));
}

int main()
{
	return 0;
}