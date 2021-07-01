// 연관 컨테이너 //
// set은 시퀀스컨테이너(vector, list, deque)와 다른  "연관컨테이너" 이다.     연관컨테이너는 시퀀스컨테이너와 다르게 key-value (키-값) 구조를 갖는다.  즉, 어느 키를 넣으면 그에 다응하는 값을 돌려준다.
// 즉, 연관컨테이너는 키를 바탕으로 키에 대응되는 값을 구할 수 있는 구조이다.    C++에서는  1. 키와 연관되는 값이 있는지 true/false   2. 키와 연관되는 값을 가져오기    << 이러한 기능을 사용할 수 있는데,
// 그중 찾는값의 유뮤만 처리하는 것으로 셋(set)과 멀티셋(multiset)이 있고,    만약 존재한다면 키에 대응하는 값을 구하는 맵(map)과 멀티맵(multimap)이 있다.
// *** 크기의 유무만 처리하면 되는 경우 셋을 사용하는것이 좋다.  (셋이 맵보다 메모리 크기가 작기 때문이다.)
// 또한 set의 특징으로는 원소들이 중복이 되지않는다는 접입니다.

// set //   *** set의 경우 key만 보관합니다. *** 
#include<iostream>
#include<set>

using namespace std;

template <typename T> // 함수 템플릿 T
// set은 시퀀스컨테이너처럼 임의의 위치 원소에 접근은 불가능하기 때문에 iterator을 통해 순차적인 접근만이 가능합니다.
void print_set(set<T> &s)
{
	typename std::set<int>::iterator itr;
	cout << "[";
	for (itr = s.begin(); itr != s.end(); ++itr)
		cout << *itr << " ";
	cout << "]";
}

template <typename T> // 함수 템플릿 T
void print_set_class(set<T> &s) // > operator가 정의된 class 용
{
	cout << "[" << endl;
	for (const auto &ele : s)
		cout << ele << " " << endl;
	cout << "]" << endl;
}

template <typename T, typename C>
void print_set_class_2(set<T, C> &s) // *** set의 경우 set<A,B> 이런식으로 뒤에 compare 관련된 함수 또한 인자로 받습니다.     앞에처럼 set에 두번째 인자로 넘겨주면 set은 이를 받아서 B클래스에 정의된 함수를 바탕으로 비교를
{                                    //                                                                                    수행하여 정렬하게 됩니다.
	for (auto &ele : s)
		cout << ele << " " << endl;
}

class Todo // 클래스 선언
{
private:
	int priority;
	string job_desc;

public:
	Todo(int priority, string job_desc)
		:priority(priority), job_desc(job_desc)
	{}

	bool operator < (const Todo &t)const
	{
		if (priority == t.priority) // 중요도가 같다면
			return job_desc < t.job_desc; // job의 사전식 순서에 따라 정렬

		return priority < t.priority; // 중요도가 다를 경우
	}

	friend ostream &operator << (ostream &out, const Todo &td)
	{
		out << "중요성: " << td.priority << "    " << td.job_desc;
		return out;
	}
};

class Todos // 또다른 set에 사용할 클래스 선언법
{
private:
	int priority;
	string job_desc;

public:
	Todos(int priority, string job_desc)
		:priority(priority), job_desc(job_desc)
	{}

	friend struct TodoCmp; // < operator가 없는대신에  TodoCmp를 선언하여 사용할 수 있다.

	friend ostream &operator << (ostream &out, const Todos &td)
	{
		out << "[ 중요도: " << td.priority << "]" << td.job_desc;
		return out;
	}
};

struct TodoCmp // ***  < operator 대신 사용할 struct 객체       TodoCmp를 set의 인자로 넣었기 때문에 정렬할때 비교연산을 TodoCmp class의 따라서 수행합니다.
{
	bool operator()(const Todos &t1, const Todos &t2) const// () 을 구현하여서 크기를 비교한다.
	{
		if (t1.priority == t2.priority)
			return t1.job_desc < t2.job_desc;
		else
			return t1.priority < t2.priority;
	}
};
// **** 즉, set에서 class를 사용하려면  < operator을 사용하던지 말던지 일단 크기를 비교할 수 있는 operator을 구현해야 set에 class을 이용할 수 있다.

int main()
{
	std::set<int> set;

	// set에 원소를 추가하기 위해서는 insert를 사용하면 된다.   그런데 시퀀스컨테이너들과 다른점으로 시퀀스컨테이너는 원소하나씩 담고 그상자에 번호를 매긴 것이라면, set은 그냥 큰 상자에 모든 원소를 쑤셔넣은 것이라고 생각하면 됩니다.
	// 즉, 어디에 추가할지 정보가 없고 그져 상자에 원소가 있냐/없냐만 구분한다는 점입니다.   시퀀스컨테이너는 지우는 작업이 O(N)인것에 비해 set은 추가/지우기 작업이  O(logN)으로 시간복잡도가 작습니다.
	// set은 시퀀스 컨테이너보다 값을 지우고 추가하는 작업에 시간복잡도가 작다는 장점이 있습니다.
	set.insert(10);
	set.insert(30);
	set.insert(20);
	set.insert(50);
	set.insert(40);

	print_set(set); // 10 20 30 40 50       출력해보면 정렬되어서 나오는 것을 볼 수 있다.   즉, "set은 내부에 원소가 추가될 때 정렬이 되도록 추가된다는 것을 알 수 있습니다."
					// *** set은 내부적으로 트리구조로 이루어져있습니다. ***  따라서 원소를 찾아 삭제/추가 하는데 트리의 높이 N  O(logN)이 됩니다.

	auto itr = set.find(20); // set에서의 .find() ()안에 해당되는 원소가 존재한다면 이것을 가르키는 반복자를 리턴하고, 만일 존재하지 않는다면 .end()를 리턴합니다.
	cout << endl;

	if (itr != set.end()) // 찾았을때
		cout << *itr << endl; // 20 출력
	else // itr == set.end() 찾지못했을때
		cout << "Not find" << endl;


	std::set<int> set2;

	set2.insert(1);
	set2.insert(3);
	set2.insert(3);
	set2.insert(3);
	set2.insert(5);

	print_set(set2); // 1 3 5 가 출력됨.   *** 즉, set에서는 중복을 제거하고 저장하는것을 알 수 있다.
	cout << endl;    // set은 inset시 중복되는 값이 존재한다면 아예 insert을 실행하지 않습니다. 



	std::set<Todo> set3;

	// class를 insert할 때에는 거기에서 필요한 연산자 오버로딩이 다 구현되어있어야 한다. 여기선 set은 내부적으로 정렬을 하므로 class안에서 < operator가 구현되어 있어야한다.....  <-- 이런식으로 여러가지가 클래스내에 구현되어 있어야함
	set3.insert(Todo(1, "잠자기"));
	set3.insert(Todo(2, "코딩하기"));
	set3.insert(Todo(1, "밥먹기"));
	set3.insert(Todo(3, "취미 즐기기"));

	print_set_class(set3); // 중요성: 1 밥먹기    중요성: 1  잠자기     중요성: 2  코딩하기      중요성: 3  취미 즐기기


	std::set<Todo> set4;
	set4.insert(Todo(1, "잠자기"));
	set4.insert(Todo(1, "잠자기"));

	print_set_class(set4); // 중요성: 1 잠자기       중복되므로 한개만 출력되는 것을 알 수 있다.

	// *** set에서 중복인지 확인하는 법은   operator < , > 을 사용하였을 때 둘다 false 즉, 다른 한원소보다 작지도, 크지도 않을 경우 같다고 판단합니다.
	//                                    다시 말해서 A,B 가 다른 객체라면 A<B 또눈 A>B중 하나는 true가 리턴이 되어야 합니다.


	// 클래스안에서 또다른 크기를 비교하는 oerator을 가진 class 통해 set
	std::set<Todos, TodoCmp> set5;
	set5.insert(Todos(1, "잠자기"));
	set5.insert(Todos(3, "피아노"));
	set5.insert(Todos(2, "코딩"));
	set5.insert(Todos(2, "밥먹기"));

	print_set_class_2(set5);

	return 0;
}