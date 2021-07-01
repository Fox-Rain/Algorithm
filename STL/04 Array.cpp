// array
// std::array는 고정된 크기의 배열을 담은 컨테이너로, 반복자라던지 대입연산자를 사용할 수 있습니다. (즉, algorithm에서의 메소드를 array에서도 쓸 수 있습니다.)
// 참고로 array의 크기가 0일 경우 array.begin()==array.end()이며  front()와 back()은 사용할 수 없습니다.
#include<iostream>
#include<array>

using namespace std;

int main()
{
	// 대입 
	std::array<int, 3> arr = { 1,2,3 }; // std::array<자료형, 개수> 배열명 ={초기화};
	std::array<int, 3>arr_copy;

	arr_copy = arr; // std::array는 일반 배열과 다르게 대입연산자를 통해서 대입할 수 있다.



	// at()
	std::array<int, 5> arr1 = { 1,2,3,4,5 };
	cout << arr1.at(3) << endl; // 일반배열과 다르게 at()을 사용할 수 있다. at은 []과 다르게 배열범위를 체크합니다.



	// front back        front()는 맨앞의것, back()은 뒤에것의 참조라르 리턴함
	std::array<int, 3> arr2 = { 1,3,5 };
	cout << arr2.front() << endl; // 1
	cout << arr2.back() << endl; // 5



	// data         array의 배열의 첫 시작 주소값을 리턴합니다.
	array<int, 5> arr3 = { 1,2,3,4,5 };
	cout << &arr3[0] << " " << arr3.data() << endl; // cout해보면 배열의 첫주소와 .data가 동일



	// 반복자
	// begin() cbegin()
	array<int, 3>arr4 = { 2,3,4 };
	array<int, 3>::iterator itr4;
	itr4 = arr4.begin(); // begin()은 array의 배열 첫원소의 iterator을 리턴

	array<int, 3>::const_iterator itr4_const;
	itr4_const = arr.cbegin(); // cbegin()은 array의 배열 첫원소의 const iterator을 리턴 따라서 대입할시 const_iterator로 선언된 반복자에 넣어줘야 함



	// rbegin() crbegin()  역참조의 시작점 (배열의 맨뒤)    rend() crend()   역참조 반복자의 끝점(맨앞)을 리턴합니다.
	array<int, 3>arr5 = { 1,2,3 };

	for (auto ele = arr5.rbegin(); ele != arr5.rend(); ++ele)
		cout << *ele << endl; // 3 2 1



	// empty
	array<int, 3>arr6 = { 1,2,3 };
	array<int, 0>arr6_empty;

	cout << arr6.empty() << endl; // 비지않았으므로 false
	cout << arr6_empty.empty() << endl; // 비어있으므로 true



	// fill
	array<int, 5>arr7;
	arr7.fill(7); // 배열을 모두 ()안의 값으로 채웁니다.  전에 어떤값이 들어있던간에 ()안의 값응로 모두 채웁니다.

	for (auto &ele : arr7)
		cout << ele << endl; // 7 7 7 7 7



	// swap
	array<int, 3>arr8 = { 1,2,3 };
	array<int, 3>arr8_swap = { 3,4,5 };

	arr8.swap(arr8_swap); // .swap() ()안의배열과 서로 swap합니다.  단, 서로 배열의 크기가 같아야 합니다.

	return 0;
}