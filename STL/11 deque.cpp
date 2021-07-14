// ���ʿ��� ������ ť�� <deque>�� ���ǵǾ� �ִ�. //
/*
	����(LIFO)�� ��� �ֻ�ܿ����� ������ ������ �Ͼ��, ť(FIFO)�� ��쿡�� ���ʿ����� ����, �ٸ� ���ʿ����� ������ �Ͼ���� ���� ������ ���ʿ��� �� �� ���� ����.
	�׷��� "��ũdeque�� ��� ���� ������ ���԰� ������ �Ѵ� �� �� �ִ�." �ٸ� ���� �����̳ʿ� ���������� ��ũ�� �������� �޸� �� ��ġ�ϰ� �ǰ�, ���Ҵ� ���ǹݺ��ڸ� ���� ������ �� ������ �޸𸮴� �˾Ƽ� �Ҵ�ȴ�.

	< deque�� ��/���� >

		(����) 1. ������ ���ҵ��� �ε����Ͽ��� ������ �� �ִ�.   2. ���Ҹ� ��� �������ε� �����س��� �� �ִ�. (iterator�� ����)	3. *** ��ũ�� "����"/"��"�� ȿ�������� ���Ҹ� �߰�/���� �� �� �ִ�.
			   ��, deque�� ��� vector���� ���� ���ۿ��� �Ѵ� ���Ҹ� ����/�����ϱ⿡ ȿ�����̴�.
			   ���� deque�� vector�� �޸� �Ϻ��� ���ҵ��� ������ �޸𸮻� �����ϴ� ���� �ƴ�, �����ͷ� �̷���� �޸𸮻� �����ϴ� �޸𸮱� ������ �Ҵ��Ҷ����� vector�� �ٸ��� 1���� �Ҵ��ϱ� ������
			   (vector�� ��� capapctiy�� �ѹ��� ����� �Ҵ���) �޸𸮸� ���� ȿ�������� ����� �� �ְ�,  �����Ͱ� Ŭ ���� vector���� �޸����Ҵ��ϴ°��� ���� ������ vector���� �����ٰ� �� �� �ִ�.
			   * �����Ͱ� ����, ���� ���ۺα�(�߰�x)������ ����/������ ����ϴٸ� deque�� ����ϴ°��� ����.

*/

#include<iostream>
#include<deque>
#include<typeinfo>

using namespace std;

int main()
{
	// deque������ ���Ϳ� ����ϴ�.
	deque<int>test1 = { 1,2,3,4,5 };


	// iterator�� vector�� ���������� begin(), end(), rbegin(), rend() �� �ִ�.
	deque<int>::iterator itr_deq; // iterator �����ϴ¹�


	// ����� *** ���Ϳ� �ٸ��� capactiy�� reserve�� ����.   (�ڽ� ������ �Ҵ��ҽ� 1���� �ϹǷ�)


	// size		��ũ�� ����� �����Ѵ�. (������ ������ ����)
	deque<int>test2 = { 1,2,3 };

	cout << test2.size() << endl; // 3 ���


	// resize	��ũ�� ���ϴ� ��ŭ�� ���Ҹ� ������ �����.
	deque<int>test3 = { 1,2 };

	test3.resize(5);
	cout << test3.size() << endl; // resize(5)�� ���������Ƿ� size�� 5���Ǿ���.   5 ���
	for (int i = 0; i < 5; ++i)   // 1,2,0,0,0 ���   ��, resize�� ���� �Ҵ�� ���� ��� 0���� ä���.
		cout << test3[i] << endl;


	// empty    ��ũ�� ������� Ȯ��
	deque<int>test4 = { 1,2,3 };
	deque<int>test5;

	cout << test4.empty() << endl; // �����ʾ��� ��� 0 ����
	cout << test5.empty() << endl; // ����� ��� 1 ����


	// assign   ��ũ�� ���Ҹ� ����ִ´�.
	deque<string>test6 = { "hello","haha" };

	test6.assign(4, "hi"); // hi��� ���Ҹ� 4�� �Ҵ��Ѵٴ� �ǹ��̴�.    dequeName.assign(count, value);
	deque<string>::iterator test6_itr;
	for (test6_itr = test6.begin(); test6_itr != test6.end(); ++test6_itr++) // hi hi hi hi    ��, ���� deque�� ���� ����־�������  �� �����ϰ� assign��� �Ҵ���
		cout << *test6_itr << endl;


	// push_back(), push_front(), pop_back(), pop_front()   front()�� �ִٴ� ���� vector�� �ٸ����̴�.


	// insert    ��ũ�� �߰��� ���Ҹ� �����Ѵ�.		erase    ��ũ�� �߰����Ҹ� �����Ѵ�.		clear ������ü�� ����
	deque<int>test7 = { 1,2,3,4 };

	test7.insert(test7.begin() + 2, 3); // .insert(��������ġ, ������ ��);
	deque<int>::iterator test7_itr;
	for (test7_itr = test7.begin(); test7_itr != test7.end(); ++test7_itr) // 1 2 3 3 4
		cout << *test7_itr << endl;

	test7.erase(test7.begin() + 3); // .erase(������ ��ġ);
	for (test7_itr = test7.begin(); test7_itr != test7.end(); ++test7_itr) // 1 2 3 4
		cout << *test7_itr << endl;

	test7.clear(); // ������ü����
	cout << test7.empty() << endl; // ���Ҹ� ��ü �����Ͽ����Ƿ� 1 ����

	return 0;
}