// https://www.acmicpc.net/problem/1152
/*
문제
영어 대소문자와 띄어쓰기만으로 이루어진 문자열이 주어진다. 이 문자열에는 몇 개의 단어가 있을까? 이를 구하는 프로그램을 작성하시오. 단, 한 단어가 여러 번 등장하면 등장한 횟수만큼 모두 세어야 한다.

입력
첫 줄에 영어 대소문자와 띄어쓰기로 이루어진 문자열이 주어진다. 이 문자열의 길이는 1,000,000을 넘지 않는다. 단어는 띄어쓰기 한 개로 구분되며, 공백이 연속해서 나오는 경우는 없다. 또한 문자열의 앞과 뒤에는 공백이 있을 수도 있다.

출력
첫째 줄에 단어의 개수를 출력한다.
*/
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str;
	std::getline(cin, str); // cin>>str;을 하게되면 빈칸을 받을 수 없다. 따라서 getline()을 이용한다.  getline(cin,입력받을 변수명,만날경우 읽기를 중지할 문자)
							// getline(,,) 3번째 인자의 default값은 '\n'이다. 즉, 개행문자를 만날시 읽기를 중지함
	bool flag = false;
	int count = 0;
	for (int i = 0; i < str.length(); ++i) // flag를 이용하여 단어의 개수를 센다.
	{
		if (flag == false && str[i] != ' ')
		{
			flag = true;
			count++;
		}
		else if (flag == true && str[i] == ' ')
		{
			flag = false;
		}
	}
	cout << count;

	return 0;
}
// 문제의 조건에서 볼 수 있듯이, 공백을 포함한 문자열을 받아야하기 때문에, cin 함수보다는 getline 함수를 활용하여 문자열을 입력받아야한다.
// getline함수는 string헤더파일안에 들어있다.