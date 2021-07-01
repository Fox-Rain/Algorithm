// https://www.acmicpc.net/problem/1120
/*
����
���̰� N���� ���� ���ڿ� X�� Y�� ���� ��, �� ���ڿ� X�� Y�� ���̴� X[i] �� Y[i]�� i�� �����̴�. ���� ���, X=��jimin��, Y=��minji���̸�, ���� ���̴� 4�̴�.

�� ���ڿ� A�� B�� �־�����. �̶�, A�� ���̴� B�� ���̺��� �۰ų� ����. ���� A�� ���̰� B�� ���̿� ������ �� ���� ������ ���� ������ �� �� �ִ�.

A�� �տ� �ƹ� ���ĺ��̳� �߰��Ѵ�.
A�� �ڿ� �ƹ� ���ĺ��̳� �߰��Ѵ�.
�̶�, A�� B�� ���̰� �����鼭, A�� B�� ���̸� �ּҷ� �ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� A�� B�� �־�����. A�� B�� ���̴� �ִ� 50�̰�, A�� ���̴� B�� ���̺��� �۰ų� ����, ���ĺ� �ҹ��ڷθ� �̷���� �ִ�.

���
A�� B�� ���̰� �����鼭, A�� B�� ���̸� �ּҰ� �ǵ��� ���� ��, �� ���̸� ����Ͻÿ�.
*/
#include<iostream>
#include<cstring> // strlen
#include<climits> // INT_MAX

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char A[51];
	char B[51];

	cin >> A;
	cin >> B;
	// ���� B >= A 
	int plus_count = strlen(B) - strlen(A); // �����ϼ� �ִ� count  ��������
	int min = INT_MAX;
	for (int i = 0; i <= plus_count; ++i)
	{
		int count = 0;
		int A_index = 0;
		for (int j = i; j < strlen(B) - plus_count + i; ++j)
		{
			if (B[j] != A[A_index++])
				count++;
		}

		(min > count) ? min = count : min;
	}

	cout << min;

	return 0;
}