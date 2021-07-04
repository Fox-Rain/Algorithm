// Recursion 재귀
// 재귀함수는 반복문으로, 반복문은 재귀함수로 바꿀 수 있음           재귀함수는 퍼포먼스 면에서는 조금 떨어진다.
#include<iostream>

using namespace std;
// 재귀함수가 무한루프에 빠지지 않기 위해서 갖추어야하는 조건  1. Base Case : 적어도 하나의 recursion에 다시 빠지지 않는 경우가 존재해야 한다.
													   // 2. Recursion Case: 재귀를 반복하다보면 Base Case로 반드시 수렴해야 한다. (즉, Base Case가 언젠간 일어나야 함)
void func(int n)
{
	if (n <= 0) // Base Case (n이 0이하일 경우 재귀호출을 하지않고 종료됨)
		return;
	else
	{
		cout << "Hello" << endl;
		func(n - 1); // Recursion Case (n이 점점 작아지다 보면 Base Case의 n<=0 조건에 수렴하게 됨)
	}
}

// Factorial  n!
int factorial(int n)
{
	if (n == 0)
		return 1;
	else
	{
		return n * factorial(n - 1);
	}
}

// Fibonacci Number
int fibonacci(int n)
{
	if (n < 2)
		return n;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}

// 최대 공약수 : Euclid Method        m>=n인 두양의 정수 m,n 에서 m이 n의 배수이면 gcd(m,n)=n이고 그렇지 않으면 gcd(m,n)=gcd(n,M%n)이다
int gcd(int m, int n)
{
	if (m < n)
	{
		int temp = m;
		m = n;
		n = temp;
	}
	if (m % n == 0)
		return n;
	else
		return gcd(n, m % n);
}

// 배열의 합구하기
int sum(int n, int array[])
{
	if (n <= 0)
		return 0;
	else
		return array[n - 1] + sum(n - 1, array);
}

int main()
{
	func(5);

	cout << factorial(5) << endl;

	cout << fibonacci(30) << endl;

	cout << gcd(48, 32) << endl;

	int My_array[5] = { 1,2,3,4,5 };
	cout << sum(5, My_array) << endl;

	return 0;
}