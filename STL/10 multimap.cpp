// multimap (멀티맵) //
// 멀티맵은 맵과 다르게 원소 중복이 가능합니다.
#include<iostream>
#include<string>
#include<map>

using namespace std;

template <typename K, typename V>
void print_map(multimap<K, V> &m)
{
	for (auto &ele : m)
		cout << ele.first << " " << ele.second << endl;
}

int main()
{
	multimap<int, string> m;

	m.insert(make_pair(1, "hello"));
	m.insert(make_pair(2, "hi"));
	m.insert(make_pair(1, "hi"));
	m.insert(make_pair(1, "hello"));

	print_map(m); // 1 hello  1 hi   1 hello   2 hi

	cout << m.find(1)->second << endl; // hello 출력           m.find(1)을 통해서 key값이 1인 iterator을 찾고  -> 을 통해서 second에 접근한다.    *** 단, (1)에 여러개의 값이 있다면, 어떠한 값이 나올지는 랜덤입니다.

	// **** 또한 멀티맵은 []연산자를 지원하지 않습니다.

	// eqaul_range()       ()안의 키값을 가지는 반복자들의 시작과 끝을 pair로 만들어서 리턴합니다.
	auto range = m.equal_range(1);
	for (auto itr = range.first; itr != range.second; ++itr) // 반복자들의 첫 first, 끝 second 
		cout << itr->first << " : " << itr->second << endl; // 1 : hello   1 : hi    1 : hello

	return 0;
}