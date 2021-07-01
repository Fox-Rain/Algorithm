// https://www.acmicpc.net/problem/1541
/*
����
�����̴� ����� +, -, �׸��� ��ȣ�� ������ ���� �������. �׸��� ���� �����̴� ��ȣ�� ��� ������.

�׸��� ���� �����̴� ��ȣ�� ������ �ļ� �� ���� ���� �ּҷ� ������� �Ѵ�.

��ȣ�� ������ �ļ� �� ���� ���� �ּҷ� ����� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� �־�����. ���� ��0��~��9��, ��+��, �׸��� ��-�������� �̷���� �ְ�, ���� ó���� ������ ���ڴ� �����̴�. �׸��� �����ؼ� �� �� �̻��� �����ڰ� ��Ÿ���� �ʰ�, 5�ڸ����� ���� ���ӵǴ� ���ڴ� ����. ���� 0���� ������ �� �ִ�. �Է����� �־����� ���� ���̴� 50���� �۰ų� ����.

���
ù° �ٿ� ������ ����Ѵ�.
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
        if (expression[i] == '-' || expression[i] == '+' || i == expression.size()) // ��ȣ�� ���
        {
            if (minus_flag == true) // minus_flag�� true�� ���  ��, 1���̶� minus�� ������ ���
            {
                result -= stoi(num);
                num.clear();
            }
            else // minus_flag�� false�� ���  ��, minus�� ���� �ȳ����� ���
            {
                result += stoi(num);
                num.clear();
            }
        }

        else // ������ ���
        {
            num += expression[i]; // num string�� ����
        }

        if (expression[i] == '-') // expression[i]�� minus�� ���
        {
            minus_flag = true; // minus_flag�� true�� 
        }
    }

    cout << result;
}
