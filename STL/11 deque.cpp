// 양쪽에서 끝나는 큐로 <deque>에 정의되어 있다. //
/*
	스택(LIFO)의 경우 최상단에서만 삭제와 삽입이 일어나고, 큐(FIFO)의 경우에도 한쪽에서는 삭제, 다른 한쪽에서는 삽입이 일어나지만 삽입 삭제를 한쪽에서 다 할 수는 없다.
	그러나 "데크deque의 경우 양쪽 끝에서 삽입과 삭제를 둘다 할 수 있다." 다른 순차 컨테이너와 마찬가지로 데크도 선형으로 메모리 상에 위치하게 되고, 원소는 임의반복자를 통해 접근할 수 있으며 메모리는 알아서 할당된다.

	< deque의 장/단점 >

		(장점) 1. 개개의 원소들을 인덱싱하여서 접근할 수 있다.   2. 원소를 어떠한 방향으로도 참조해나갈 수 있다. (iterator을 통한)	3. *** 데크의 "시작"/"끝"에 효율적으로 원소를 추가/삭제 할 수 있다.
			   즉, deque의 경우 vector보다 끝과 시작에서 둘다 원소를 삭제/삽입하기에 효율적이다.
			   또한 deque는 vector와 달리 완벽히 원소들이 나란히 메모리상에 존재하는 것이 아닌, 포인터로 이루어져 메모리상에 존재하는 메모리기 때문에 할당할때마다 vector와 다르게 1개씩 할당하기 때문에
			   (vector의 경우 capapctiy를 한번에 덩어리로 할당함) 메모리를 좀더 효율적으로 사용할 수 있고,  데이터가 클 수록 vector보다 메모리재할당하는것이 적기 때문에 vector보다 빠르다고 볼 수 있다.
			   * 데이터가 많고, 끝과 시작부근(중간x)에서의 삽입/삭제가 빈번하다면 deque를 사용하는것이 좋다.

*/

#include<iostream>
#include<deque>
#include<typeinfo>

using namespace std;

int main()
{
	// deque선언은 벡터와 비슷하다.
	deque<int>test1 = { 1,2,3,4,5 };


	// iterator는 vector와 마찬가지로 begin(), end(), rbegin(), rend() 가 있다.
	deque<int>::iterator itr_deq; // iterator 선언하는법


	// 참고로 *** 벡터와 다르게 capactiy와 reserve가 없다.   (자신 스스롷 할당할시 1개씩 하므로)


	// size		데크의 사이즈를 리턴한다. (원소의 개수를 리턴)
	deque<int>test2 = { 1,2,3 };

	cout << test2.size() << endl; // 3 출력


	// resize	데크가 원하는 만큼의 원소를 갖도로 만든다.
	deque<int>test3 = { 1,2 };

	test3.resize(5);
	cout << test3.size() << endl; // resize(5)를 실행했으므로 size는 5가되었다.   5 출력
	for (int i = 0; i < 5; ++i)   // 1,2,0,0,0 출력   즉, resize로 새로 할당된 곳은 모두 0으로 채운다.
		cout << test3[i] << endl;


	// empty    데크가 비었는지 확인
	deque<int>test4 = { 1,2,3 };
	deque<int>test5;

	cout << test4.empty() << endl; // 비지않았을 경우 0 리턴
	cout << test5.empty() << endl; // 비었을 경우 1 리턴


	// assign   데크에 원소를 집어넣는다.
	deque<string>test6 = { "hello","haha" };

	test6.assign(4, "hi"); // hi라는 원소를 4개 할당한다는 의미이다.    dequeName.assign(count, value);
	deque<string>::iterator test6_itr;
	for (test6_itr = test6.begin(); test6_itr != test6.end(); ++test6_itr++) // hi hi hi hi    즉, 원래 deque에 뭐가 들어있었던간에  다 삭제하고 assign대로 할당함
		cout << *test6_itr << endl;


	// push_back(), push_front(), pop_back(), pop_front()   front()가 있다는 것이 vector와 다른점이다.


	// insert    데크의 중간에 원소를 삽입한다.		erase    데크의 중간원소를 삭제한다.		clear 원소전체를 삭제
	deque<int>test7 = { 1,2,3,4 };

	test7.insert(test7.begin() + 2, 3); // .insert(삽입할위치, 삽입할 수);
	deque<int>::iterator test7_itr;
	for (test7_itr = test7.begin(); test7_itr != test7.end(); ++test7_itr) // 1 2 3 3 4
		cout << *test7_itr << endl;

	test7.erase(test7.begin() + 3); // .erase(삭제할 위치);
	for (test7_itr = test7.begin(); test7_itr != test7.end(); ++test7_itr) // 1 2 3 4
		cout << *test7_itr << endl;

	test7.clear(); // 원소전체삭제
	cout << test7.empty() << endl; // 원소를 전체 삭제하였으므로 1 리턴

	return 0;
}