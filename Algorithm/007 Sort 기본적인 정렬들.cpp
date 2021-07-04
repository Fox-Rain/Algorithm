#include<iostream>
#include<typeinfo>

using namespace std;

// Selection Sort ��������                < ���ڸ����� �˰����� �ϳ� (�Էµ� ������ �ܿ� �߰� �޸𸮸� �䱸���� ����)    �ð����⵵�� O(n^2) >
// ���������� �����迭���� ����ũ�ų� �������� �ǵڳ� �Ǿ��� �迭�� �������Ͽ� �����ϴ� �˰����� ���Ѵ�.
void selection_Sort(int arr[], int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int index = NULL; // index

		int max = INT_MIN; // �ִ밪 ���Ҷ����� �ʱⰪ�� ���� �����ɷ� �ʱ�ȭ�صξ����
		// �ִ밪�� �ִ밪�� index ���ϴ� for�� // 
		for (int j = 0; j < n - i; ++j)
		{
			if (max > arr[j])
				max;

			else
			{
				max = arr[j];
				index = j; // max = arr[j]; �ɶ����� max���� ���ŵǹǷ� �׋��� index�� ������
			}
		}
		// Swap    �ִ밪�� �迭�� ���ݿ����� �ǵ��ǰ��� ������ //
		int Temp = arr[index];
		arr[index] = arr[n - i - 1];
		arr[n - i - 1] = Temp;
	}
}

// Bubble Sort ��������                   < �ð����⵵�� O(n^2) >

void bubble_Sort(int arr[], int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1]) // ������ �� ��Ұ� ���������� ���� ��� �� ��Ҹ� Swap
			{
				// Swap  
				int Temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = Temp;
			}
		}
	}
}

// Insertion Sort ��������                < �ּ��� ��� O(n)�̶�� ���� ȿ������ ������, �־��� ��� O(n^2)�̶�� �ð����⵵�� ������ �ȴ�. ������ ũ��� ���¿� ���� ���̰� ŭ. �ð����⵵�� O(n^2) >

void insertion_Sort(int array[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int j;

		int tmp = array[i];
		for (j = i - 1; j > -1; j--)
		{
			if (array[j] > tmp)
			{
				array[j + 1] = array[j];
			}
			else
				break;
		}

		array[j + 1] = tmp;
	}
}

int main()
{
	int selection[5] = { 1,6,3,8,2 };
	selection_Sort(selection, 5);

	for (int i = 0; i < 5; ++i)
	{
		cout << selection[i] << endl;
	}


	int bubble[5] = { 3,3,9,5,2 };
	bubble_Sort(bubble, 5);

	for (int i = 0; i < 5; ++i)
	{
		cout << bubble[i] << endl;
	}

	int insertion[5] = { 3,6,7,4,1 };
	insertion_Sort(insertion, 5);

	for (int i = 0; i < 5; ++i)
	{
		cout << insertion[i] << endl;
	}

	return 0;
}