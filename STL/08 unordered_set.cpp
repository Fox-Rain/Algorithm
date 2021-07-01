// unordered_set (정렬되지않는 셋) //
// 즉, set과 다르게 정렬이 되지않고 내부에 저장됩니다.
// ******** unordered_set의 장점은 insert,erase,find가 모두 O(1)인 점입니다. ********* //
#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

template <typename K>
void print_unordered_set(unordered_set<K> &m)
{
	for (auto &ele : m)
		cout << ele << endl;
}

int main()
{
	unordered_set<string> s;

	s.insert("a");
	s.insert("c");
	s.insert("b");
	s.insert("d");

	print_unordered_set(s); // 출력해보면 알겠지만 정해진 순서가 아예 없습니다.

	return 0;
}