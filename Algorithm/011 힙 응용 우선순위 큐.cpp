// ���� ����: �켱���� ť (�ִ�켱���� ť, �ּҿ켱���� ť)        "ť" ��? �����͸� �־�� �� �ִ� �����̳��ε�, �����͸� �������� "FIFO" (first int first out)�� Ư¡�� ������ �ִ�.
// ��, �������� �����Ͱ� ���������� �Ǵ� �ո� ��ο� ���� ���¸� �ϰ� �ִ�.
// ���� ť �� �ִ� �켱���� ť�� �����͸� ������ ���� ť�� �ִ� ������ �켱���� ���� �ִ��ΰ��� ������ ť�� ���Ѵ�.
// �� �ִ� �켱����ť�� INsert(����)�� Max_out(�ִ밪�� ����)�� ������ �ִ�.

// Insert Algorithm     1. ����� �߰��� �Ͼ ��� ���� ������ �����ؾ��ϱ� ������ ������ ������ index+1�κп� �߰��� �Ǿ�� �Ѵ�. (binary tree������ ����)
// 2. �߰��� max_property�� �������� �� �����Ƿ� ���ε��� ���� �׳���� �θ����� �񱳸� ���ؼ� property�� �����ɶ����� �ø��鼭 �θ�͸� �񱳸� �ϸ� �ȴ�.

// Extract_Max Algorithm     1. arr[1]�� ���� �ϴ� �����صд�(�ִ밪)    2. heap�� �����ؾ��ϹǷ� arr�� �ǳ��� �迭��Ҹ� arr[1]�� �����ϰ�, arr�ǳ����� �����Ѵ�.
// 3. max property�� ������ �������Ƿ� heapify�� ���� property�� �ٽ� �����ش�.    4. ó�� �����صξ��� �ִ밪�� �����Ѵ�.

#include<iostream>
#include<vector>

using namespace std;

void max_Heapify(vector<int> &arr, int i)
{

	if (2 * i > arr.size() - 1) // �ڽĳ�� �ƿ� ������
		return;
	if (2 * i + 1 <= arr.size() - 1)
	{
		int big = (arr[2 * i] > arr[2 * i + 1]) ? 2 * i : 2 * i + 1;

		if (arr[i] < arr[big])
		{
			int Temp = arr[i];
			arr[i] = arr[big];
			arr[big] = Temp;
		}
		else
			return;

		max_Heapify(arr, big);
	}
	else
	{
		if (arr[i] < arr[2 * i]) {
			int Temp = arr[i];
			arr[i] = arr[2 * i];
			arr[2 * i] = Temp;
		}
		else
			return;

		max_Heapify(arr, 2 * i);
	}
}

// Insert Algorithm ���� �˰���     ( �� ���� �ְ� �ٽ� Max_property�� �����ϴ� ������ ������ִ� �Լ� )    < �ð����⵵ O(log n)
void max_Heap_Insert(vector<int> &arr, int key) // �Լ����ο��� ���� �ٲپ���ϱ� ������ vector<int>�� &arr ���۷����� �޾ƾ� �Ѵ�.  &arr �迭, key �������� �ǹ�
{
	arr.push_back(key); // �迭�� �ǵ� ��ҿ� key���� ���� (�޸��Ҵ��� �Ǿ����� ������ �˾Ƽ� �޸� �Ҵ��ؼ� �־��ش�.)
						// Tip) *** ��������   arr.capacity(); capacity�� allocator�� ���� �ڽ��� ����� �޸𸮸� �� �Ҵ��ϱ⵵ �ϹǷ�  �޸��Ҵ��� �󸶰� ���� �� �� ����. 
						// �̷������� �޸� �Ҵ��� �ϴ� ������ push_back�� �Ͼ�� ���� �����Ҵ��� �ϸ�, ��ȿ�����̹Ƿ� �̸� ���ص� ��ŭ �����Ҵ��� �ѹ��� �ϴ� �� �Դϴ�.

	int i = arr.size() - 1; // ���� ���ִ� �迭 ����� ���� ���� index�� i�� �ʱ�ȭ

	while (i > 1 && arr[i / 2] < arr[i]) // i>1�̸鼭 �θ��庸�� �ڽĳ�尡 Ŭ ���
	{
		// Swap //
		int Temp = arr[i];
		arr[i] = arr[i / 2];
		arr[i / 2] = Temp;

		i /= 2; // index�� �θ����� index�� �ٲ�
	}
}

// Extract_Max Algorithm �ִ밪 ���� �˰���
int Extract_Max(vector<int> &arr)
{
	int result = arr[1]; // index 1������ ���� max property������ �ִ밪�̹Ƿ� �װ��� result�� �ʱ�ȭ

	arr[1] = arr[arr.size() - 1]; // arr[1]�� arr�� ������ ���� �������ְ�
	arr.pop_back(); // �������� arr��Ҵ� pop_back()�� ���ؼ� ����

	// Heapify //
	max_Heapify(arr, 1);

	return result;
}

int main()
{
	vector<int>arr = { 0,10,9,9,7,4,3,2,1 };

	cout << Extract_Max(arr) << endl;

	for (int i = 1; i < arr.size(); ++i)
	{
		cout << arr[i] << endl;
	}
	return 0;
}