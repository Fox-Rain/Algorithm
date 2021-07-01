// multiset (멀티셋) //
// 멀티셋은 셋과 다르게 원소의 중복을 허락합니다.
#include<iostream>
#include<string>
#include<set>

using namespace std;

template<typename K>
void print_set(multiset<K> &s)
{
	for (auto &ele : s)
		cout << ele << endl;
}

int main()
{
	multiset<string> s;

	s.insert("a");
	s.insert("c");
	s.insert("a");
	s.insert("b");
	s.insert("c");

	print_set(s); // a a b c c    이렇게 중복된 것도 다 insert된다.

	return 0;
}