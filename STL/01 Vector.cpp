// Vector //     vector은 크기가 가변적으로 변하는 배열로, 속도적인 측면에서는 배열보다 떨어지지만 메모리를 효율적으로 관리할 수 있다.
// 크기를 가변적으로 변경해야될때나, 중간삽입/삭제가 적을때 이용하는것이 좋다.
// vector을 생성하면 메모리Heap에 생성되어 동적할당 됩니다.
// 임의접근 O(1)    벡터끝에 원소삽입/삭제 O(1)    원소삽입/삭제 O(n) 마지막 원소로부터 거리에 비례함
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	// Vector 선언 //               < > 안에 자료형으로 class를 넣어도 된다.
	vector<int> v1;              // int타입의 vector 생성
	vector<char> v2 = { 1,2,3 }; // char타입의 vector 생성 + 1,2,3 으로 초기화
	vector<double> v3[10];       // double타입의 vector 크기10으로 생성
	vector<int> v4(5);           // int타입의 vector을 크기5로 모두 0으로 초기화하여 생성
	vector<int> v5(5, 3);        // int타입의 vector을 크기 5로 모두 3으로 초기화하여 생성
	vector<int> v6(v1);          // int타입의 vector에 v1을 복사하여 생성



	// vector 멤버함수 //
	vector<int> v;

	// v.assign(n,m)    m으로 n개의 요소를 초기화함   만약 vector에 다른 요소들이 있어도 삭제하고 n,m으로 초기화 시킨다.
	v.assign(3, 5); // {5,5,5,}

	// v.at(index)    vector[index]의 요소를 리턴함.  일반 []과 다른점은 배열의 범위에 들어가는지 체크한다는 점에서 다르다.
	cout << v.at(2) << endl; // {5,5,5}중에서 vector범위에 맞는지 체크한후 5를 리턴함

	// v.front() 첫원소, v.back() 마지막원소을 리턴한다.

	// v.clear()    모든원소를 제거한다. 단, 메모리는 남아있다. (size는 0이되나 capacity 용량은 남아있다.    즉, 요소들의 값이 사라지는 것이지, 동적할당된 메모리는 유지된다.)
	v.clear(); // {5,5,5] -> {} 단 크기(capacity)는 3로 유지

	// v.push_back(n)    마지막원소에 n을 삽입한다. (마지막원소라는것은 원소가 저장되어있는 index의 다음 index 인  index+1을 말하는 것이다.)
	v.push_back(10); // {} -> {10} (capacity)는 3

	// v.pop_back()    마지막원소를 삭제

	// v.resize(n)    크기(capacity)을 n으로 만든다.   vector의 경우 메모리가 부족할 경우 메모리할당을 이런식으로 한다. -->   1. 원래 vector배열에 있던걸 복사한다.
	// 2. 원래 vector의 크기의 약 2배를 다른 메모리에 동적할당한다.   3. 복사한것을 새로만든 메모리에 저장한다.  (즉, 그냥 크기를 정해놓지않고 vector을 이용할 경우 복사하는과정등에서 퍼포먼스가 느려진다)
	// 따라서 처음부터 어느정도의 배열의 크기를 알고 있다면 resize()로 메모리할당을 처음부터 해두면 위에 과정을 통한 퍼포먼스 저하가 줄어든다.
	v.resize(10); // {10} (capacity)는 10

	// v.size()    원소들의 개수를 리턴함
	cout << v.size() << endl; // {10}이므로 1 출력

	// v.capacity()    할당된 공간의 크기를 반환한다. (capacity를 반환함)
	cout << v.capacity() << endl; // {10}이지만 capacity가 10이므로 10 출력

	// v2.swap(v1)    v2 v1을 스왑한다.

	// v.empty()     vector가 비어있으면 true, 비어있지않으면 false 리턴

	// v.max_size()    vector가 담을수 있는 총 요소수를 말함.
	cout << v.max_size() << endl; // 1004050....   즉, 저장용량크기를 말하는것이 아닌 vector 그자체의 최대저장가능한 값을 리턴함

	// v.shrink_to_fit()   capacity를 size와 같게 맞춘다.  즉, 실제크기에 용량을 맞춤
	// v.shrink_to_fit()은 size에 맞는 또다른 vector을 동적할당하여 복사하여 넘기는 것이므로, 큰 배열의 경우 퍼포먼스가 저하될 수 있다.
	v.shrink_to_fit(); // {10} capacity 10  ->  {10} capacity 1 이 된다.



	// iterator(반복자)관련 메소드 //

	vector<int> vec = { 1,2,3,4,5 };

	// 반복자 생성
	vector<int>::iterator itr; // 반복자를 변수로 만듦

	// v.begin()    첫번째원소를 가르키는 반복자를 리턴
	itr = vec.begin();
	for (int i = 0; i < vec.size(); ++i) // 1 2 3 4 5
		cout << itr[i] << endl;

	// v.end()    마지막원소 "다음"(last_index+1)을 가르키는 반복자를 리턴

	// v.rbegin()    벡터의 끝지점을 시작점으로 하는 반복자를 리턴

	// v.rend()    벡터의 시작+1 지점을 끝 부분으로 하는 반복자를 리턴

	// v.insert()     *** 앞에 itr에 삽입한것을 계속 대입하는것은 itr = vec.begin()이 삽입후에 바뀌기 때문에 refresh한다고 보면 된다.
	itr = vec.insert(itr, 0); // itr이 vec.begin()므로 맨앞에 0 삽입
	itr = vec.insert(itr, 2, 1); // 맨앞에 1을 2개 삽입
	itr = vec.insert(itr + 2, 1, 9); // 2번째에 9을 1개 삽입
	// 위의 insert과정을 다거치게되면    {1,2,3,4,5}   ->    {1,1,9,0,1,2,3,4,5}가 된다.

	// v.erase()    배열의 원소를 제거함
	vec.erase(vec.begin() + 7); // index 7값을 제거  (사이에서의 값이 제거된다면, 뒤에값을 땡겨서 배열을 맞춤)
	vec.erase(vec.begin(), vec.begin() + 5); // index 0~5 값을 제거

	return 0;
}