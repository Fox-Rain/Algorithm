#include<iostream>
#include<string>
#include<map>

using namespace std;
// *** map의 경우도 중복된 키에 값이 들어오게된다면  키를 늘리는 것이 아닌, 원래있던 키에 값을 변경합니다.

/*
	 < map에 insert 형식 >
	 template <class T1, class T2>
	 struct std::pair
	 {
		T1 first;      <-- 여기에 key값
		T2 second;     <-- 여기에 value값
	 };
*/

template <typename K, typename V> //  map<A,B>에서보면 알 수 있듯   map은 키,값 이렇게 있으므로 A, B 나누어 template 인자로 넣을 수 있다. 
void print_map(std::map<K, V> &m) // *** 맵의 경우 템플릿 인자로 2개를 갖는데 1번째는 키타입, 2번째는 값의 타입을 받습니다.
{
	for (auto itr = m.begin(); itr != m.end(); ++itr) // map도 마찬가지로 순서 index가 아닌 iterator을 통해서 탐색할 수 있습니다.   map에 insert를 "객체"를 통해서 넣기 때문에
		cout << itr->first << " " << itr->second << endl; // 위에서의 insert될 때의 형식을 보면     '->' 연산자를 통해서 값에 접근할 수 있다.
														  // itr은 객체를 가르키고  객체->을 통해서 멤버에 접근할 수 잇는 것이다.
	/*
	for (auto& ele:m)                                    <-- 이런식으로 for문에 iterator대신 일반적인 for문을 이용할 경우
	{
		cout<< ele.first <<" "<< ele.second << endl;     <-- .first    .second 처럼    .을 통해서 접근할 수 있다.
	}
	*/
}

template <typename K, typename V>
void search_print(std::map<K, V> &m, K key) // find -> 이후 []값을 가져오는 함수 
{
	auto itr = m.find(key); // .find()는 ()안의 값이 존재한다면 그것의 iterator을 리턴한다.  만약, 값이 존재하지 않는다면 .end() iterator을 리턴한다. 

	if (itr != m.end()) // map에 있다면
		cout << key << "--->" << itr->second << endl;
	else // map에 존재하지 않는다면
		cout << key << "는(은) 목록에 존재하지 않습니다." << endl;
}

int main()
{
	map<string, double> pitcher_list;

	// map에 키/값을 넣는 방법 //  ***** 객체를 통해서 넣는다 *****
	// (1) map에서 insert을 통하여 값을 넣을 때에는 pair<>() "객체"를 통해 넣을 수 있습니다.
	pitcher_list.insert(pair<string, double>("니퍼트", 2.23));
	pitcher_list.insert(pair<string, double>("김선우", 1.53));
	pitcher_list.insert(pair<string, double>("양현종", 3.23));

	// (2) map에서 insert할때 pair<>()말고도 간단히 make_pair()을 통해서도 넣을 수 있습니다.     make_pair는 그냥 들어오는 것에 따라서 알아서 자료형을 바꾸어 줍니다.
	pitcher_list.insert(make_pair("이용찬", 2.73));

	// (3) map에서 insert말고도 []을 통해서 원소를 추가할 수도 있습니다.
	pitcher_list["윤석민"] = 0.97;

	print_map(pitcher_list); // 김선우 1.53    니퍼트 2.23    양현종 3.23    윤석민 0.97    이용찬 2.73

	cout << pitcher_list["니퍼트"] << endl; // 이런식으로 키값을 통해 값에 접근할 수 있습니다.

	cout << pitcher_list["류현진"] << endl; // 0이 출력     이런식으로 키값이 없는것을 출력해보면 0이 출력된다.  즉, map은 키값이 존재하지 않을 경우 default로 0으로 선언해버린다.
	// *** 따라서 find를 통해 키값의 존재유무부터 파악한후, []을 통해서 값을 찾아오는 식으로 하는것이 좋다. ***

	search_print(pitcher_list, string("류현진")); // *** 키값에 넣을때 string()으로 감싸주어야함 

	// ****** 주의할 점은 map도 또한 insert시 중복되는 키값이 있을 경우 insert를 실행하지 않습니다.   따라서 키의 값을 바꾸고 싶을 경우 insert 대신 []을 통하면 수정할 수 있다. ****** //

	return 0;
}