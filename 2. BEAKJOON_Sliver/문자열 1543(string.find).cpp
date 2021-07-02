// https://www.acmicpc.net/problem/1543
/*
문제
세준이는 영어로만 이루어진 어떤 문서를 검색하는 함수를 만들려고 한다. 이 함수는 어떤 단어가 총 몇 번 등장하는지 세려고 한다. 그러나, 세준이의 함수는 중복되어 세는 것은 빼고 세야 한다. 예를 들어, 문서가 abababa이고, 그리고 찾으려는 단어가 ababa라면, 세준이의 이 함수는 이 단어를 0번부터 찾을 수 있고, 2번부터도 찾을 수 있다. 그러나 동시에 셀 수는 없다.

세준이는 문서와 검색하려는 단어가 주어졌을 때, 그 단어가 최대 몇 번 중복되지 않게 등장하는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 문서가 주어진다. 문서의 길이는 최대 2500이다. 둘째 줄에 검색하고 싶은 단어가 주어진다. 이 길이는 최대 50이다. 문서와 단어는 알파벳 소문자와 공백으로 이루어져 있다.

출력
첫째 줄에 중복되지 않게 최대 몇 번 등장하는지 출력한다.
*/
#include<iostream>
#include<string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// getline을 이용한이유   string의 경우 default로는 " "을 만나면 입력을 그만 받으므로  getline으로 입력을 그만받게 하는 문자를 '\n'으로 바꿈
	string document; // 문서
	getline(cin, document, '\n');

	string word; // 찾을 단어
	getline(cin, word, '\n');

	int count = 0;
	int index = 0;

	while (document.find(word, index) != -1) // *** <string>의 .find 메소드는  원하는 문자열을 찾았을 경우 그 문자열이 시작하는 index, 찾지 못했을 경우 -1을 리턴한다
	{
		count++;
		index = document.find(word, index) + word.length();
	}

	cout << count;

	return 0;
}