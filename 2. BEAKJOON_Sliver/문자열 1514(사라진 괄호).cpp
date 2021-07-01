// https://www.acmicpc.net/problem/1541
/*
문제
세준이는 양수와 +, -, 그리고 괄호를 가지고 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.

그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.

괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

입력
첫째 줄에 식이 주어진다. 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다. 그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다. 수는 0으로 시작할 수 있다. 입력으로 주어지는 식의 길이는 50보다 작거나 같다.

출력
첫째 줄에 정답을 출력한다.
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string expression;
    cin >> expression;

    int result = 0;
    string num;
    bool minus_flag = false;

    for (int i = 0; i <= expression.size(); i++)
    {
        if (expression[i] == '-' || expression[i] == '+' || i == expression.size()) // 부호일 경우
        {
            if (minus_flag == true) // minus_flag가 true일 경우  즉, 1번이라도 minus가 나왔을 경우
            {
                result -= stoi(num);
                num.clear();
            }
            else // minus_flag가 false일 경우  즉, minus가 아직 안나왔을 경우
            {
                result += stoi(num);
                num.clear();
            }
        }

        else // 숫자일 경우
        {
            num += expression[i]; // num string에 대입
        }

        if (expression[i] == '-') // expression[i]가 minus일 경우
        {
            minus_flag = true; // minus_flag를 true로 
        }
    }

    cout << result;
}
