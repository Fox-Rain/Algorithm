// https://www.acmicpc.net/problem/5397
/*
문제
창영이는 강산이의 비밀번호를 훔치기 위해서 강산이가 사용하는 컴퓨터에 키로거를 설치했다. 며칠을 기다린 끝에 창영이는 강산이가 비밀번호 창에 입력하는 글자를 얻어냈다.

키로거는 사용자가 키보드를 누른 명령을 모두 기록한다. 따라서, 강산이가 비밀번호를 입력할 때, 화살표나 백스페이스를 입력해도 정확한 비밀번호를 알아낼 수 있다.

강산이가 비밀번호 창에서 입력한 키가 주어졌을 때, 강산이의 비밀번호를 알아내는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수가 주어진다. 각 테스트 케이스는 한줄로 이루어져 있고, 강산이가 입력한 순서대로 길이가 L인 문자열이 주어진다. (1 ≤ L의 길이 ≤ 1,000,000) 강산이가 백스페이스를 입력했다면, '-'가 주어진다. 이때 커서의 바로 앞에 글자가 존재한다면, 그 글자를 지운다. 화살표의 입력은 '<'와 '>'로 주어진다. 이때는 커서의 위치를 움직일 수 있다면, 왼쪽 또는 오른쪽으로 1만큼 움직인다. 나머지 문자는 비밀번호의 일부이다. 물론, 나중에 백스페이스를 통해서 지울 수는 있다. 만약 커서의 위치가 줄의 마지막이 아니라면, 커서 및 커서 오른쪽에 있는 모든 문자는 오른쪽으로 한 칸 이동한다.

출력
각 테스트 케이스에 대해서, 강산이의 비밀번호를 출력한다. 비밀번호의 길이는 항상 0보다 크다.
*/

/*
// vector을 이용한 풀이 //    <--- insert와 erase가 시간복잡도가 크기때문에 시간초과가 일어난다.  insert, erase  O(n)  n은 끝원소부터 선택된 원소까지의 거리

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int c;
	cin >> c; // 케이스 개수

	string keyboard_input; // 키보드 인풋

	while (c--)
	{
		cin >> keyboard_input;
		int corsur_index = 0;
		vector <char> password; // password

		for (int i = 0; i < keyboard_input.size(); i++)
		{
			if (keyboard_input[i] == '<')
			{
				if (corsur_index == 0) // 커서가 맨앞일 경우 움직이지 않음
					continue;
				corsur_index--;
			}
			else if (keyboard_input[i] == '>')
			{
				if (corsur_index == password.size()) // 커서가 맨뒤일 경우 움직이지 않음
					continue;
				corsur_index++;
			}
			else if (keyboard_input[i] == '-')
			{
				if (corsur_index == 0) // 커서가 맨앞일 경우 지우지 않음
					continue;
				password.erase(password.begin() + corsur_index - 1); // 커서가 맨앞이 아닐 경우 삭제
				corsur_index--;
			}
			else // keyboard_input이 문자나 숫자일 경우
			{
				password.insert(password.begin() + corsur_index, keyboard_input[i]); // *** insert는 함수자체가 알아서 size가 작다면 size를 늘리고 (원소를 늘림) ***
				corsur_index++;
			}
		}

		for (int i = 0; i < password.size(); i++)
			cout << password[i];

		cout << endl;
	}

	return 0;
}
*/

// list를 이용한 풀이 // 시간초과가 나지 않는다.   list는 삽입과 삭제에 효율적이기 때문에 사용함.
#include<iostream>
#include<list>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int c;
	cin >> c; // case 개수

	for (int i = 0; i < c; ++i)
	{
		string keyboard_input;
		cin >> keyboard_input; // 키보드 인풋

		list<char>password; // 패스워드
		list<char>::iterator cursor = password.begin();
		for (int j = 0; j < keyboard_input.size(); ++j)
		{
			if (keyboard_input[j] == '-')
			{
				if (cursor != password.begin())
					cursor = password.erase(--cursor); // *** passwrod.erase(--cursor);은 에러가 뜬다.  insert나 erase를 하게되면 iterator의 위치가 바뀌기 때문이다. 따라서 iterator값을 다시 cursor에 대입해줘야 한다.
			}
			else if (keyboard_input[j] == '<')
			{
				if (cursor != password.begin())
					cursor--;
			}
			else if (keyboard_input[j] == '>')
			{
				if (cursor != password.end())
					cursor++;
			}
			else
			{
				password.insert(cursor, keyboard_input[j]);
			}
		}

		list<char>::iterator print;
		for (print = password.begin(); print != password.end(); ++print)
			cout << *print;
		cout << endl;
	}

	return 0;
}