// https://www.acmicpc.net/problem/7785
/*
문제
상근이는 세계적인 소프트웨어 회사 기글에서 일한다. 이 회사의 가장 큰 특징은 자유로운 출퇴근 시간이다. 따라서, 직원들은 반드시 9시부터 6시까지 회사에 있지 않아도 된다.

각 직원은 자기가 원할 때 출근할 수 있고, 아무때나 퇴근할 수 있다.

상근이는 모든 사람의 출입카드 시스템의 로그를 가지고 있다. 이 로그는 어떤 사람이 회사에 들어왔는지, 나갔는지가 기록되어져 있다. 로그가 주어졌을 때, 현재 회사에 있는 모든 사람을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 로그에 기록된 출입 기록의 수 n이 주어진다. (2 ≤ n ≤ 106) 다음 n개의 줄에는 출입 기록이 순서대로 주어지며, 각 사람의 이름이 주어지고 "enter"나 "leave"가 주어진다. "enter"인 경우는 출근, "leave"인 경우는 퇴근이다.

회사에는 동명이인이 없으며, 대소문자가 다른 경우에는 다른 이름이다. 사람들의 이름은 알파벳 대소문자로 구성된 5글자 이하의 문자열이다.

출력
현재 회사에 있는 사람의 이름을 사전 순의 역순으로 한 줄에 한 명씩 출력한다.
*/
#include<iostream>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n; // case 개수
	cin.ignore();

	std::set<string>enterPeople;
	for (int i = 0; i < n; ++i)
	{
		string name_log;
		string log;

		cin >> name_log >> log; // string은 " "을 받지 않기 때문에

		if (log == "enter")
			enterPeople.insert(name_log);
		else if (log == "leave")
			enterPeople.erase(name_log);
	}

	for (auto itr = enterPeople.rbegin(); itr != enterPeople.rend(); ++itr) // rbegin   rend을 통해서 역으로 출력함.
		cout << *itr << '\n';
	return 0;



/*  // 또다른 풀이 //
	#include <unordered_set> 

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n; // case 개수
	cin.ignore();

	std::unordered_set<string>enterPeople; // unordered_set<> 정렬되지않은 셋    (unordered_set은 find,erase,insert에 모두 O(1)의 시간복잡도를 가지고 있기에 이 자료구조를 사용함.)
	for (int i = 0; i < n; ++i)
	{
		string name_log;
		string log;

		cin >> name_log >> log; // string은 " "을 받지 않기 때문에

		if (log == "enter")
			enterPeople.insert(name_log);
		else if (log == "leave")
			enterPeople.erase(name_log);
	}

	// ***** unordered_set은 정렬되지 않은 컨테이너이기 때문에 처음엔 sort를 사욯아여 정렬하려고했는데, sort는 연속된컨테이너(vector,list,deque)와 같은 연속된 컨테이너에만 이용할 수 있기에 vector로 데이터를 옮겨서 정렬했다.
	vector<string>name_log;
	name_log.insert(name_log.end(), enterPeople.begin(), enterPeople.end()); // vector로 옮김

	enterPeople.clear(); // 이젠 필요없는 unordered_set의 원소들을 삭제

	sort(name_log.begin(), name_log.end(), [](string i, string j) {return i > j; }); // vector로 옮긴 값들을 sort로 정렬

	for (auto &ele : name_log)
		cout << ele << '\n';

	return 0;
*/
}