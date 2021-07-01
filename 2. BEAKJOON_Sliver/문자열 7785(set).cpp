// https://www.acmicpc.net/problem/7785
/*
����
����̴� �������� ����Ʈ���� ȸ�� ��ۿ��� ���Ѵ�. �� ȸ���� ���� ū Ư¡�� �����ο� ����� �ð��̴�. ����, �������� �ݵ�� 9�ú��� 6�ñ��� ȸ�翡 ���� �ʾƵ� �ȴ�.

�� ������ �ڱⰡ ���� �� ����� �� �ְ�, �ƹ����� ����� �� �ִ�.

����̴� ��� ����� ����ī�� �ý����� �α׸� ������ �ִ�. �� �α״� � ����� ȸ�翡 ���Դ���, ���������� ��ϵǾ��� �ִ�. �αװ� �־����� ��, ���� ȸ�翡 �ִ� ��� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �α׿� ��ϵ� ���� ����� �� n�� �־�����. (2 �� n �� 106) ���� n���� �ٿ��� ���� ����� ������� �־�����, �� ����� �̸��� �־����� "enter"�� "leave"�� �־�����. "enter"�� ���� ���, "leave"�� ���� ����̴�.

ȸ�翡�� ���������� ������, ��ҹ��ڰ� �ٸ� ��쿡�� �ٸ� �̸��̴�. ������� �̸��� ���ĺ� ��ҹ��ڷ� ������ 5���� ������ ���ڿ��̴�.

���
���� ȸ�翡 �ִ� ����� �̸��� ���� ���� �������� �� �ٿ� �� �� ����Ѵ�.
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
	cin >> n; // case ����
	cin.ignore();

	std::set<string>enterPeople;
	for (int i = 0; i < n; ++i)
	{
		string name_log;
		string log;

		cin >> name_log >> log; // string�� " "�� ���� �ʱ� ������

		if (log == "enter")
			enterPeople.insert(name_log);
		else if (log == "leave")
			enterPeople.erase(name_log);
	}

	for (auto itr = enterPeople.rbegin(); itr != enterPeople.rend(); ++itr) // rbegin   rend�� ���ؼ� ������ �����.
		cout << *itr << '\n';
	return 0;



/*  // �Ǵٸ� Ǯ�� //
	#include <unordered_set> 

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n; // case ����
	cin.ignore();

	std::unordered_set<string>enterPeople; // unordered_set<> ���ĵ������� ��    (unordered_set�� find,erase,insert�� ��� O(1)�� �ð����⵵�� ������ �ֱ⿡ �� �ڷᱸ���� �����.)
	for (int i = 0; i < n; ++i)
	{
		string name_log;
		string log;

		cin >> name_log >> log; // string�� " "�� ���� �ʱ� ������

		if (log == "enter")
			enterPeople.insert(name_log);
		else if (log == "leave")
			enterPeople.erase(name_log);
	}

	// ***** unordered_set�� ���ĵ��� ���� �����̳��̱� ������ ó���� sort�� ��G�ƿ� �����Ϸ����ߴµ�, sort�� ���ӵ������̳�(vector,list,deque)�� ���� ���ӵ� �����̳ʿ��� �̿��� �� �ֱ⿡ vector�� �����͸� �Űܼ� �����ߴ�.
	vector<string>name_log;
	name_log.insert(name_log.end(), enterPeople.begin(), enterPeople.end()); // vector�� �ű�

	enterPeople.clear(); // ���� �ʿ���� unordered_set�� ���ҵ��� ����

	sort(name_log.begin(), name_log.end(), [](string i, string j) {return i > j; }); // vector�� �ű� ������ sort�� ����

	for (auto &ele : name_log)
		cout << ele << '\n';

	return 0;
*/
}