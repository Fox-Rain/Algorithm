// String //
#include<iostream>
#include<string>

using namespace std;

int main()
{
	// erase
	// *** erase는 반복자를 사용하지않는경우 지워진 후의 문자열을 리턴하고, 반복자를 사용할 경우 마지막으로 지워진 문자다음을 가르키는 반복자를 리턴한다. 
	// (1) erase로 삭제하면 삭제된 빈곳은 채워지도록 앞으로 당겨지긴하지만, 총 전체의 메모리 capacity는 변화하지 않는다.
	string str1 = "This is an example";
	cout << str1.length() << " " << str1.capacity() << endl; // 18 31

	string return_str;
	return_str = str1.erase(5, 2); // .erase(index, count)   삭제하기 시작할 index, count는 거기서부터 지울 갯수를 넣는다.

	cout << str1.length() << " " << str1.capacity() << endl; // 16 31
	cout << return_str << endl; // This  an example
	cout << str1 << endl; // This  an example 출력


	// (2) erase로 삭제하면 삭제된 빈곳은 채워지도록 앞으로 당겨지긴하지만, 총 전체의 메모리 capacity는 변화하지 않는다.
	string str2 = "sexy";
	cout << str2.length() << " " << str2.capacity() << endl; // 4 15

	str2.erase(3); // .erase(index)  index의 값을 하나 지운다.
	cout << str2.length() << " " << str2.capacity() << endl; // 3 15
	cout << str2 << endl; // sex

	// (3)
	string str3 = "hello world";
	string::iterator itr1;

	itr1 = str3.erase(str3.begin(), str3.begin() + 6); // .erase(iterator first, iterator second) first부터 second 전까지의 문자들을 지운다.
	cout << itr1 - str3.begin() << endl;
	cout << str3 << endl; // world



	// find
	// (1)
	string str4 = "coding everyone";
	string str4_compare = "everyone";

	int index4;
	index4 = str4.find(str4_compare, 4); // .find(찾을 string, 찾기를 시작할 index)    find함수에서 찾게되면 찾은 문자열의 첫번째 index를 리턴한다.

	cout << index4 << endl; // 7

	// (2)
	string str5 = "kakaotalk";
	char ch = 't';

	int index5;
	index5 = str5.find(ch, 0); // .find(찾을문자, 찾기를 시작할 index)  찾게되면 그 문자의 첫번째 index을 리턴한다.

	cout << index5 << endl;



	// find_first_of
	// (1)
	string str6 = "hello";
	string str6_compare = "eol";

	int index6;
	index6 = str6.find_first_of(str6_compare, 0); // .find_first_of(대조할 string, 찾기시작할 index) 대조할 string의 문자들중 원문자열에서 맨처음으로 나오는 곳의 index을 리턴

	cout << index6 << endl; // e,o,l중에서 e가 맨처음으로 맞는 문자므로 index 1이 출력됨  1

	// (2)
	string str7 = "kakao";
	const char *str7_compare = "abc";

	int index7;
	index7 = str7.find_first_of(str7_compare, 0, 4); // .find_first_of(대조할 문자열/문자 포인터, 찾기를 시작할 index, 범위) [index, index+범위) 안에서 첫번째로 나타나는 문자를 찾고 index를 리턴

	cout << index7 << endl; // a가 index=1이므로 1출력

	// (3)
	string str8 = "I love you";
	char c = 'l';

	int index8;
	index8 = str8.find_first_of(c, 2); // .find_first_of(찾을 문자, 찾기시작할 index);

	cout << index8 << endl; // 2 



	// getline
	// getline함수는 입력스트림에서 문자를 읽는데 "delim문자를 읽게되면 해당 delim문자는 버리고", 읽어들이기를 종료한뒤, 인자로 받은 문자열에 저장합니다.  (delim을 설정안했을시, '\n'가 default)
	// 만약 어떤연유로든 읽기오류가 발생한다면 failbit을 설정하여서 오류를 발생시킨다. 또한 입력스트림에서 읽다가 End-of-File에 도달하면 eofbit을 설정하여 읽기를 종료합니다.
	// 참고로 입력받는 문자는 push_back함수를 통해 덧붙여지므로, reserve를 통해 어느정도 크기를 안다면 할당해두는 것이 퍼포먼스 면에서 좋습니다.
	// *** 주의할점 getline은 default delim이 '\n'이므로 공백문자를 스트림에 남기는 입력방식뒤에 바로 getline이 오게되면 공백문자를 읽고 바로 종료하게 되어 원하지 않게 프로그램이 작동할 수 있습니다.
	// *** 이와 같은 상황을 막기 위해서 스트림에 남는 공백문자를 지워야하는데 아래의 과정을 통하여 지울 수 있습니다.
	// *** cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')

	string str9;  // hello world를 입력할시 //  
	getline(std::cin, str9, ' '); // hello world를 입력하면, delim이 ' '이므로 hello 까지 읽고 ' '는 버리게된다.  즉, 입력스트림에는 world만 남게됨.
	cout << str9 << endl; // 읽어온 hello를 출력

	getline(cin, str9); // world가남아있으므로 world까지 받아온뒤, '\n'를 삭제함
	cout << str9 << endl; // world 출력

	getline(cin, str9); // 위에서 hello world 모두 입력스트림에서 읽어들여졌으므로, 입력스트림이 비어있기에 다시 입력을 받는다.
	cout << str9 << endl;



	// insert
	string str10 = "hello coding";
	str10.insert(5, 3, 'x'); // .insert(삽입할 index, 삽입할개수, 문자) index에 문자를 갯수만큼 삽입
	cout << str10 << endl; // helloxxx coding 

	string str11 = "hello coding";
	str11.insert(5, "hello"); // .insert(삽입할 index, 삽입할 문자열(ptr도 가능))
	cout << str11 << endl; // hellohello coding

	string str12 = "hello coding";
	str12.insert(5, "hello", 3); // .insert(삽입할 index, 삽입할 문자열(ptr도 가능), 문자열에서 삽입할 개수)
	cout << str12 << endl; // 여기서 hellohel coding   3개므로 hel만 삽입



	// replace
	string str13 = "everyone coding";
	str13.replace(0, 3, "hill"); // .replace(바꾸기 시작할 index, 바꿀 갯수, 삽입할 str)
	cout << str13 << endl; // hillryone coding

	string str14 = "everyone coding";
	str14.replace(str14.begin(), str14.end(), "hi"); // replace(iterator first, iterator second, 삽입할str)    first부터 second전까지의 문자열에 str를 삽입
	cout << str14 << endl; // hi

	string str15 = "hi hello";
	str15.replace(0, 3, "hill", 0, 3); // replace(삽입시작index, 바뀔갯수, 문자열str, 삽입될 문자열의 시작 index, 문자열 개수)
	cout << str15 << endl; // hilhello // 인덱스를 마찬가지로 ierator로 바꾸어서 코딩할 수도 있다.



	// substr
	string str16 = "belong";
	string str16_substr;
	str16_substr = str16.substr(0, 2); // .substr(복사시작index, 갯수) + 복사하여 리턴     즉 여기선 be를 복사하여 리턴함.
	cout << str16_substr << endl; // be



	// append
	// (1)
	string str17 = "kakao talk";
	str17.append(5, 'k'); // .append(개수, 뒤에추가할 문자)   k를 5개 뒤에 추가
	cout << str17 << endl; // kakao talkkkkkk

	// (2)
	string str18 = "maple";
	str18.append("story"); // .append(문자열)   뒤에 문자열을 추가
	cout << str18 << endl; // maplestory

	// (3)
	string str19 = "hahaha";
	str19.append("kakao", 1, 3); // .append(부분을붙일 문자열, 붙일문자열의 시작index, 시작index부터 범위)  즉, 여기선 kako에서 aka를 뒤에 붙여서 hahahaako
	cout << str19 << endl; // hahahaaka

	// (4)
	string str20 = "bitcoin";
	const char *ch_20 = "hello"; // 문자열 포인터
	str20.append(ch_20, 4); // .append(문자열 포인터, 처음부터 몇개의 문자를 뒤에 붙일것인가의 개수)   여기선 4므로 hell을 뒤에 붙이게 된다.
	cout << str20 << endl; // bitcoinhell

	// (5)
	string str21 = "dogecoin";
	string str21_ = "ELM";
	str21.append(str21_.begin(), str21_.begin() + 2); // .append(iterator first, iterator second) first부터 second전까지의 str21_의 문자를 뒤에 붙임
	cout << str21 << endl;

	return 0;
}