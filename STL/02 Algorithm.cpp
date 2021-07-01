// Algorithm //
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool check_negative(int i)
{
	if (i >= 0)
		return false;
	else
		return true;
}

void print(string &str)
{
	cout << str << " ";
}

bool isOdd(int i)
{
	return i % 2;
}

bool two(int i, int j)
{
	if (i == 2 * j)
		return true;
	else
		false;
}

bool smmp(int i, int j)
{
	return i > j;
}

int biggest(int i, int j)
{
	if (i > j)
		return i;
	else
		return j;
}

int g()
{
	static int g = 1;
	return g++;
}

bool compare(int i, int j)
{
	return i > j;
}
int main()
{
	// all_of (iterator first, iterator second, "인자를 한개만 가지고 bool타입으로 변환가능한 값을 리턴하는 함수")
	vector<int>v1 = { 1,3,5,7,9,11 };

	if (std::all_of(v1.begin(), v1.end(), [](int i) {return i % 2; })) // [v.begin(),v.end()) 구간안에서 [](int i)가 모두 true일경우 true리턴,  하나라도 false일 경우 false 리턴
		cout << "All number is odd" << endl;



	// any_of (iterator first, iterator second, "인자를 한개만 가지고 bool타입으로 변환가능한 값을 리턴하는 함수")
	vector<int>v2 = { 1,3,5,7,-9 };

	if (std::any_of(v2.begin(), v2.end(), check_negative)) // [v.begin(),v.end()) 구간안에서 [](int i)가 하나라도 true면 true, 모두 false면 false을 리턴
		cout << "Negative is exist" << endl;



	// none_of (iterator first, iterator second, "인자를 한개만 가지고 bool타입으로 변환가능한 값을 리턴하는 함수")
	// 모두가 false면 true, 하나라도 true가 있다면 false를 리턴한다.



	// for_each(iterator first, iterator second, "인자를 한개만 갖는 함수")     for_each문은 그안에서 인자를 수정하는것은 지양하는것이 좋다. (인자 수정이 필요할땐 transform 이용하기)
	vector<string>v3 = { "hello","hi","lol" };

	for_each(v3.begin(), v3.end(), print); // for_each문을 통해서 [v3.begin(), v3.end()) 구간 만큼 print함수를 반복한다 <<< print함수 인자로는 vector의 요소들이 차례로 들어감.
	cout << endl;                          // hello hi lol이 출력됨



	// find(iterator first, iterator second, const T &i)    i는 찾을 값을 의미
	vector<string>v4 = { "hello","hi","coding" };

	std::vector<string>::iterator itr;
	// find는 찾을값을 찾을 경우 그값의 반복자를 리턴하고, 만약 찾지못했을 경우 end()을 리턴한다.
	itr = std::find(v4.begin(), v4.end(), "coding"); // vector을 사용하였으므로 리턴값을 ierator에 받음

	// find를 반복자말고 배열에도 사용할 수 있다.
	int myints[] = { 10, 20, 30, 40 };
	int *p;

	p = std::find(myints, myints + 4, 30); // 이때는 반복자를 사용하지않으므로, 포인터를 이용하여 대입함.
	if (p != myints + 4)
		std::cout << "Element found in myints: " << *p << '\n';
	else
		std::cout << "Element not found in myints\n";



	// find_if(iteator first, iterator second,"인자를 하나만 갖으며 리턴값이 bool인 함수")
	vector<int>v5 = { 1,2,3,4,5 };
	std::vector<int>::iterator itr2;
	itr2 = std::find_if(v5.begin(), v5.end(), isOdd); // 이렇게 되면 isOdd실행시 true가 되는 첫번째 반복자를 리턴한다.  만약 한개도 없다면 v5.end()을 리턴한다.



	// find_if_not(iterator first, iterator second, "인자를 하나만 받는 리턴형이 bool인 함수")
	vector<int>v6 = { 1,2,3,4,5 };
	std::vector<int>::iterator itr3;
	itr3 = std::find_if_not(v6.begin(), v6.end(), isOdd); // isOdd가 처음으로 false되는 반복자를 리턴함, 만약 false가 하나도 없다면 v6.end()을 리턴한다.



	// find_end
	vector<int>v7 = { 1,3,5,2,4,6,2,3,4,5,1,2,3 };
	int arr7[] = { 1,2,3 };

	std::vector<int>::iterator itr4;
	itr4 = std::find_end(v7.begin(), v7.end(), arr7, arr7 + 3); // find_end(iterator first1, iterator second1, iterator first2, iterator second2)
	cout << "첫번째 부분집합 첫원소 값은 " << *itr4 << " 마지막으로 부분집합이 나오는 첫 index " << itr4 - v7.begin() << endl; // 1   10



	// count
	vector<string>v8 = { "hello","hi","hi","lol" };

	int str_counting;
	str_counting = std::count(v8.begin(), v8.end(), "hi"); // count(iterator first, iterator second, 찾을 값)  count는 찾는값의 개수를 리턴한다.
	cout << str_counting << endl;



	// count_if
	vector<int>v9 = { 1,3,5,7,12,14,12,7 };

	int number_counting;
	number_counting = std::count_if(v9.begin(), v9.end(), [](int i) {return i < 10; }); // count_if(iterator first, iterator second, 리턴값이 bool이면서 인자가 1개인 조건이 달린 함수) 조건에 맞는 값을 리턴
	cout << number_counting << endl;



	// fill
	vector<string>v10(10);

	std::fill(v10.begin(), v10.end(), "fuxk"); // fill(iterator first, iterator second, 대입할 value)  fill은 first부터 second전까지 모두 value로 체운다.
	for (int i = 0; i < 10; ++i)
		cout << v10[i] << endl;



	// remove
	vector<int>v11 = { 1,2,3,1,3,2 };

	vector<int>::iterator itr5;
	itr5 = std::remove(v11.begin(), v11.end(), 1); // remove(iterator frist, iterator second, 지우고싶은 value) 주의할점은 value값이 지워지고 vector가 당겨지지만, "vector의 capacity와 size는
												   // 그대로 유지된다. 즉, value가 삭제되고 당겨진 vector뒤에 원소에 쓰레기값이 들어감. {1,2,3,1,3,2} -> {2,3,3,2,2,3}이 됨.
												   // 그리고 remove는 쓰레기값이 시작되는 index의 iterator을 리턴함
	for (int i = 0; i < 6; ++i) // 2 3 3 2 2 3 
		cout << v11[i] << endl;



	// remove_if
	vector<int>v12 = { 1,13,12,3,5 };

	vector<int>::iterator itr6;
	itr6 = std::remove_if(v12.begin(), v12.end(), [](int i) {return i > 10; }); // remove(iterator first, iterator second, 인수를1개로 갖으며 리턴이 bool타입인 함수)
																				// 함수가 true를 리턴할시 그값을 remove하고 배열을 당김 + capacity,size는 유지 + 당긴배열뒤에 쓰레기원소들어감
	for (int i = 0; i < 5; ++i) // 1 3 5 3 5 
		cout << v12[i] << endl;



	// sort <- sort의 경우 임의접근반복자만 인자로 들어갈 수 있다. ex) vector, deque 등...     시간복잡도는 O(NlogN)  N=std::distance(first,second)로 정의된다.

	// (1)
	vector<int>v13 = { 3,15,4,8,6,1 };
	sort(v13.begin(), v13.end()); // sort(random iterator first, ramdom iterator second)    begin()부터 end()-1까지 정렬

	for (int i = 0; i < 6; ++i) // 1 3 4 6 8 15
		cout << v13[i] << endl;

	// (2)
	vector<int>v14 = { 15,3,2,6,9,3 };
	sort(v14.begin(), v14.end(), smmp); // sort(radom iterator frist, random iterator second, 함수(인자2개를 받으며 리턴값이 bool))

	for (int i = 0; i < 6; ++i) // 15 9 6 3 3 2
		cout << v14[i] << endl;



	// partition     partition은 기준에 따라 나뉘는 부분을 iterator로 리턴한다.
	vector<int>v15 = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int>::iterator itr7;
	itr7 = partition(v15.begin(), v15.end(), [](int i) {return i % 2; }); // partition(iterator first, iterator second, bool타입을 리턴하는 인자가 하나인 함수(true가 리턴될시 앞으로 배치한다))
																		  // 단, true인것은 앞쪽에 false인것은 뒤쪽에 배치되지만 그것들의 순서는 유지되지 않는다.
	for (int i = 0; i < 10; ++i) // 1 9 3 7	5 6 4 8 2 10
		cout << v15[i] << endl;



	// transform

	// (1) unary transform    실행하는 함수의 인자가 1개인 경우
	vector<int>v16 = { 14,3,23,6 };
	transform(v16.begin(), v16.end(), v16.begin(), [](int i) {return 2 * i; }); // transform(iterator first, iterator second, 함수에서 실행된후 리턴될값이 어디부터 저장될지, 인자 1개인 함수)

	for (int i = 0; i < 4; ++i) // 함수에서 2*i 두배씩 하므로, 28 6 46 12 출력됨
		cout << v16[i] << endl;

	// (2) binary transform    실행하는 함수의 인자가 2개인 경우
	vector<int>v17 = { 13,1,5,9,3 };
	vector<int>v18 = { 1,3,7,12,3 };
	transform(v17.begin(), v17.end(), v18.begin(), v17.begin(), biggest); // transform(iterator first, iterator second, 또다른 비교시작할 iterator, 저장시작할 iterator, 인자가 2개인 함수)
																		  // iterator 처음부터 끝까지와 또다른 iterator 시작부터 인자 1개 1개씩 함수에 넣어 리턴값을 저장시작할 itr에 저장
	for (int i = 0; i < 5; ++i)
		cout << v17[i] << endl;



	// iter_swap
	vector<int>v19 = { 1,13,13,7 };
	iter_swap(v19.begin(), v19.end() - 1); // iter_swap(iterator1, iterator2) iterator둘의 값을 바꾼다.

	for (int i = 0; i < 4; ++i) // 7 13 13 1
		cout << v19[i] << endl;



	// reverse
	vector<int>v20 = { 1,2,3,4,5,6,7,8,9 };
	reverse(v20.begin(), v20.end()); // reverse(iterator first, iterator second) first 부터 second까지의 원소들을 거꾸로 배열한다.

	for (int i = 0; i < 9; ++i)
		cout << v20[i] << endl;



	// *** 아래의 lower_bound , upper_bound는 범위안의 원소들이 정렬 상태일 때에만 사용할 수 있다. //
	// lower_bound 와 upper_bound의 차이점은 크기가같은 원소를 포함하냐 안하냐이다.

	// lower_bound
	vector<int>v21 = { 1,3,5,7,9,11,13 };
	vector<int>::iterator itr8;
	itr8 = lower_bound(v21.begin(), v21.end(), 10); // lower_bound(iterator first, ierator second, value)  value보다 "크거나 같은"것들중 가장 value와 가까운 값을 반복자로 리턴 (하한선의미)
													// 만약 모든값이 value보다 작다면 .end()반복자를 리턴
	cout << *itr8 << endl;



	// upper_bound
	vector<int>v22 = { 1,3,5,7,9,11 };
	vector<int>::iterator itr9;
	itr9 = upper_bound(v22.begin(), v22.end(), 10); // upper_bound(iterator first, iterator second, value) value보다 "큰" 원소들중 가장 가까운값의 반복자을 리턴
													// 만약 모든값이 value보다 작거나 같다면 .end()반복자를 리턴
	cout << *itr9 << endl;



	// copy 
	vector<int>v23 = { 1,2,3,4,5 };
	vector<int>v23_copy;
	v23_copy.resize(6); // 리턴값으로 index 5 즉, end()의 반복자를 리턴받아야 하므로 size을 6으로 resize
	vector<int>::iterator itr10;
	itr10 = copy(v23.begin(), v23.end(), v23_copy.begin()); // copy(iterator first, iterator second, 카피한것을 넣을 곳의 첫 반복자) ** 주의할점이 copy는 복사된게 들어가는 곳의 end()를 리턴
															// 하는데, 복사하는곳의 end()부분까지 크기가 확장되어 있지 않으면 리턴을 못받아서 런타임에러가 발생하니 유의하자.
	cout << *itr10 << endl; // 0
	for (int i = 0; i < v23.size(); ++i) // 1 2 3 4 5
		cout << v23_copy[i] << endl;



	// copy_if
	vector<int>v24 = { 1,2,3,4,5 };
	vector<int>v24_copy;
	v24_copy.resize(6); // capacity를 6으로 만들고 "모두 0으로 초기화"
	copy_if(v24.begin(), v24.end(), v24_copy.begin(), [](int i) {return i % 2; }); // copy_if(iterator first, iterator second, 카피한것을 넣을곳의 첫반복자, 인자1개, 리턴값이 bool인 함수)
																				   // 함수에서 리턴값이 true인 것들만 복사하여 저장한다. 이것또한 마찬가지로 복사들어오는 곳의 end() 반복자 리턴
	for (auto &ele : v24_copy) // 1 3 5 0 0
		cout << ele << endl;



	// replace
	vector<int>v25 = { 1,2,3,4,5 };
	replace(v25.begin(), v25.end(), 3, 3333); // replace(iterator first, iterator second, 변경할값, 바뀌게될 숫자)   

	for (auto &ele : v25) // 1 2 3333 4 5
		cout << ele << endl;



	// repalce_if
	vector<int>v26 = { 1,2,3,4,5 };
	replace_if(v26.begin(), v26.end(), [](int i) {return i % 2; }, 3333); // replace_if(iterator first, iterator second, 인자를1개며 리턴값이 bool인 함수, 함수가 true할경우 바꿀 값)
																		  // 함수가 true를 반환하는 값들만 3333으로 변경
	for (auto &ele : v26)
		cout << ele << endl;



	// generate
	vector < int>v27 = { 1,2,3,4,5 };
	generate(v27.begin(), v27.end(), g); // generate(iterator first, iterator second, 인자가없으며 리턴값이 있는 함수)   순차적으로 함수의 리턴값을 vector에 저장함 

	for (auto &ele : v27)
		cout << ele << endl;



	// serach    시간복잡도는 first_부터 second_까지의 거리 S와 first부터 second 까지의 거리 N의 곱과 같다.  S*N
	// (1)
	vector<int>v28{ 1,2,4,1,2,3 };
	vector<int>v28_compare = { 1,2,3 };
	vector<int>::iterator itr11;
	itr11 = search(v28.begin(), v28.end(), v28_compare.begin(), v28_compare.end()); // search(iterator first, iterator second, iterator first_, iterator second_)
																					// first_부터 second_까지의 배열이 시작되는 반복자를 리턴한다. 만약 없다면 마지막 end()반복자를 리턴,
																					// 아예 비교하려는 vector가 없을경우엔 begin()반복자를 리턴한다.
	cout << itr11 - v28.begin() << endl; // 3이 출력 즉, v28_compare의 문자열이 시작되는 곳이 v28의 index 3부터라는 의미이다.

	// (2)
	vector<int>v29{ 1,2,5,8,10 };
	vector<int>v29_compare = { 4,6,8 };
	vector<int>::iterator itr12;
	itr12 = search(v29.begin(), v29.end(), v29_compare.begin(), v29_compare.end(), compare); // search(iterator first, iterator second, iterator first_, iterator second_, 인자를 두개 갖으며 bool타입을 리턴하는 함수)
																							 // 함수에서 true가 대조되는 원소만큼 연속으로 나올때의 첫 반복자를 리턴함  만약 없다면 end()리턴, 아예 비교하는게 비어있을 경우 begin()리턴

	cout << itr12 - v29.begin() << endl; // 2가 출력  참인것이 연속으로 나오기 시작하는 index가 2라는 의미이다.

	// (3) searcher을 통한 search
	// search(v.begin, v.end(), v_compare.begin(), v_compare.end(), searcher)    <-- 여기서 searcher은 종류로 C++표준라이브러리에서 제공하는 것은 
	//                                                                               default_searcher, boyer_moore_searcher, boyer_moore_horspool_searcher 등이 있다.



	// partial_sort    시간복잡도가 first와 middle사이의 거리 M     O(MlogM)
	vector<int>v30{ 12,5,3,6,2 };
	partial_sort(v30.begin(), v30.begin() + 2, v30.end()); // partial_sort(iterator first, iterator middle, iterator second) first부터 middle까지 오름차순으로 정렬하고
														   // 나머지를 middle부터 second까지 넣는다. 단, 뒤에 middle부터 second까지 넣는 원소들은 순서가 바뀔 수 있다.
	for (auto &ele : v30)
		cout << ele << endl; // 2 3 12 6 5



	// stable_sort    범위내 원소들을 오름차순으로 정렬 +  *** "안정정렬"을 수행함 ("안정정렬은 값이같은 원소끼리에도 순서를 유지하는것을 의미") ***
	vector<int>v31 = { 13,2,5,2,3,1 };
	stable_sort(v31.begin(), v31.end());

	for (auto &ele : v31)
		cout << ele << endl; // 1 2 2 3 5 13



	// binary_search     binary_search는 선형탐색이 아닌 이진탐색을 사용하기때문에 [first,last) 범위의 원소들이 최소한 "value를 기준으로 부분정렬"이 되어있어야 한다.
	// 원소의 개수가 N이라면 최대 O(log N)
	vector<int>v32 = { 1,3,5,16,23,100,1234 }; // binary_search는 이진탐색을 하기에 빠르긴하나, 정렬이 되어있는 것만 사용할 수 있다.
	bool check;
	check = binary_search(v32.begin(), v32.end(), 1234); // binary_search(iterator first, iterator second, value);   찾으면 true, 못찾으면 false를 리턴

	return 0;
}