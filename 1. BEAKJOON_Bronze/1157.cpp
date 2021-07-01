// https://www.acmicpc.net/problem/1157
/*
문제
알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 단, 대문자와 소문자를 구분하지 않는다.

입력
첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다. 주어지는 단어의 길이는 1,000,000을 넘지 않는다.

출력
첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다. 단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다.
*/
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str;
	cin >> str;

	int arr[26] = { 0 };

	for (int i = 0; i < str.length(); ++i)
	{
		str[i] = toupper(str[i]); // 소문자 대문자 구분이 없기 때문에 모두 대문자로 바꾼다.

		arr[int(str[i]) - 65]++; // 알파벳마다 몇개가 쓰였는지 배열로 표현
	}

	int max = 0;
	int count = 0;
	int target;
	for (int i = 0; i < 26; ++i) // max값의 index를 target에 저장하며, count가 1이상이 될경우(즉, 갯수가 같은 배열요소가 2개이상일 경우)는 ?, count가 0일 경우 char(target+65)
	{
		if (max < arr[i])
		{
			max = arr[i];
			count = 0;
			target = i;
		}
		else if (max == arr[i])
			count++;
	}

	if (count >= 1)
		cout << "?";
	else
		cout << char(target + 65);

	return 0;
}