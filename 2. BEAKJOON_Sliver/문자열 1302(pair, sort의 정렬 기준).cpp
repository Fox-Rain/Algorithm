// https://www.acmicpc.net/problem/1302
/*
문제
김형택은 탑문고의 직원이다. 김형택은 계산대에서 계산을 하는 직원이다. 김형택은 그날 근무가 끝난 후에, 오늘 판매한 책의 제목을 보면서 가장 많이 팔린 책의 제목을 칠판에 써놓는 일도 같이 하고 있다.

오늘 하루 동안 팔린 책의 제목이 입력으로 들어왔을 때, 가장 많이 팔린 책의 제목을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 오늘 하루 동안 팔린 책의 개수 N이 주어진다. 이 값은 1,000보다 작거나 같은 자연수이다. 둘째부터 N개의 줄에 책의 제목이 입력으로 들어온다. 책의 제목의 길이는 50보다 작거나 같고, 알파벳 소문자로만 이루어져 있다.

출력
첫째 줄에 가장 많이 팔린 책의 제목을 출력한다. 만약 가장 많이 팔린 책이 여러 개일 경우에는 사전 순으로 가장 앞서는 제목을 출력한다.
*/
#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

bool Compare(pair<string, int> A, pair<string, int> B) // ******  Sort에서 compare함수로 쓰일 떄 A<B는 작은것부터 정렬   A>B는 큰것부터 정렬  ****** //
{
	if (A.second == B.second) // 1순위로 바교한 second가 같다면
		return A.first < B.first; // 2순위로 first를 비교
	return A.second > B.second; // 1순위로 second를 비교함
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; // 팔린 책의 개수
	cin >> N;

	unordered_map<string, int> bookCheck; // bookCheck unordered_map으로 선언
	for (int i = 0; i < N; ++i)
	{
		string book; // 책이름
		cin >> book;

		if (bookCheck.find(book) == bookCheck.end()) // 없을 경우
		{
			bookCheck.insert(make_pair(book, 1));
		}
		else // 이미 존재할 경우
			bookCheck[book]++;
	}

	vector<pair<string, int>>bookCheck_vec(bookCheck.begin(), bookCheck.end()); // *** vector에서 pair<>을 통해서 2개의 값을 한번에 저장이 가능하다.   그래서 map -> vector로 옮길때 사용함
																				// *** pair는 map에서와 마찬가지로 first, second로 접근이 가능하다.
	sort(bookCheck_vec.begin(), bookCheck_vec.end(), Compare); // sort는 map에서 사용이 불가능하므로 시퀀스컨테이너인 vector로 복사하여서 sort를 호출한것임.

	cout << bookCheck_vec[0].first;

	return 0;
}