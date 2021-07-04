// Heap Sort     �־��� ��� �ð����⵵ O(n logn)    mergeSort��� �ٸ��� �߰��迭�� ���ʿ� (�������⵵�� ����)     ���� ��( binary heap) �ڷᱸ���� ���

// Heap (��)�̶�?   1. ���� complete binary tree �̸鼭      2. heap porperty�� �����ؾ� �Ѵ�.

// binary tree (����Ʈ��) -> �̾����� �ڽĳ�尡 �ִ� 2���� Ʈ���� ����.   ���� complete binaray	tree��  ������������ �����ϰ�� ��尡 2���� �����ְ� '���������������� ���� �����ʺ��� ���ӵ�
// ���'���� �ణ�� ������ �� �ִ� Ʈ���� ���Ѵ�. (���� �������������� �� ������ ��쿣 full binary tree��� �θ���.)

// heap property�� �����Ѵ�. == max heap property || min heap property�� �����Ѵ�. (���� �ϳ��� �����ؾ���.)
// max hip property �θ�� �ڽĺ��� ũ�Ⱑ ũ�ų� ����.    min heap property �θ�� �ڽĺ��� �۰ų� ����

// ���� ������ �����͸� �����ٰ� �ص� ���� ����� �������� �� �ִ�.

// ���� ������ �迭�� ǥ���� �����ϴ�. A[1,....n]     (��尳�� n��)     < complete binary tree �̱⿡ �迭�� ǥ���ص� �θ��ڽİ��԰� ������ >
// ��Ʈ��� A[1]
// A[i]�� �θ� = A{i/2]
// A[i]�� ���� �ڽ� = A[2i]
// A[i]�� ������ �ڽ� = A[2i+1] 

#include<iostream>

using namespace std;

// ���� �⺻���� MAX-HEAPIFY   (Recursion)     �����ϰ� ��Ʈ���� ���� ������Ű�� ���� �� (��, ��Ʈ���� ���������� ���� ���, ���� Ʈ������� complete binary tree������)
// �� ��Ȳ���� 1. ��Ʈ�� �ڱ� �ڽ��� �ڽĵ��� ū���� ���Ͽ� ��Ʈ<���õ� �ڽ��ǰ� �� ��� Swap�Ѵ� 2. ���� �ٽ� �Ʒ��� �ڽĳ��� �Ȱ��� ������ �ݺ��Ѵ�. 3. ���� ���� �ڽ��� ���ԵǸ� �����Ѵ�.
// or �񱳽� ��Ʈ>���õȰ��� ��쵵 ����
// build_Max_Heap���� ȣ��Ǵ� �Լ�
void max_Heapify(int arr[], int length, int i) // max_heapify    arr, �迭����, �Ѹ� indexs 1        * �Լ����� �迭�� ���� ��� "������"�� �ޱ� ������ �Լ��ȿ����� �迭��ũ�⸦ ���� �� �����Ƿ�,         
{                                              //                                                     �Լ��� �Ķ���ͷ� �迭�� ũ�⸦ �����ش�.
	if (2 * i > (length - 1) || (2 * i + 1) > (length - 1)) // �Ʒ��� �ڽĳ�尡 ���� ��� �Լ�����
		return;

	int big = (arr[2 * i] > arr[2 * i + 1]) ? 2 * i : 2 * i + 1; // �ڽĳ��� �� ū���� index�� big�� �ʱ�ȭ

	if (arr[i] < arr[big]) // �ڽĳ�� �� ���Ͽ� �θ��尡 ���� ���
	{
		// Swap //
		int Temp = arr[i];
		arr[i] = arr[big];
		arr[big] = Temp;
	}
	else // �ڽĳ��� ���Ͽ� �θ��尡 ũ�ų� ���� ��� ( max_heapify��� ���ĵ��ִ� ���̹Ƿ�) �Լ�����
		return;

	max_Heapify(arr, length, big); // Recursion ���� �ٽ� max_Heapfiy�� ȣ���Ͽ��� �Ʒ��� ����
}

void build_Max_Heap(int arr[], int length) // build_Max_Heap    arr, �迭����            ( ������ �迭�� ������ ����� �Լ� )
{
	for (int i = (length - 1) / 2; i > 0; --i) // (length-1)/2 ���� �����ϴ°��� (length-1)/2������ index�� ��� 1���� �ڽĳ�带 ���� ����̱� ������ �������� �ȴ�.
	{
		max_Heapify(arr, length, i); // max_Heapify�� ȣ���Ͽ��� ���Ʒ��� max_heapify��� ����
	}
}

// Heap Sort ������
// 1. �־��� �����ͷ� ���� �����.      2. ������ �ִ밪(��Ʈ����� ��) �� ���� ������ ���� �ٲ۴�.      3. ���� ũ�Ⱑ 1 �پ������� �����Ѵ�. ( ��, ������ ���ǰ��� ���°����� �����Ѵ�.)
// 4. ��Ʈ��忡 ���ؼ� max_Heapify(arr,1);          5. 2~4���� �ݺ��Ѵ�.
// ���� ������ ������ heapfiy�� ���ؼ� "��Ʈ��忡 ���� ��忡���� �ִ밪"�� �ø��� �װ��� �迭�� �ڷ� ����� ������ �ݺ��Ͽ��� �迭�� �����ϴ� ���̴�.
void heapSort(int arr[], int length)
{
	build_Max_Heap(arr, length); // ������ �迭�� �ϴ� ������ ����.

	for (int i = length - 1; i > 1; --i)
	{
		// ù��°�� ������ �迭��Ҹ� ���� // 
		int Temp = arr[1];
		arr[1] = arr[i];
		arr[i] = Temp;

		length--;

		max_Heapify(arr, length, 1);	
	}
}

int main()
{
	int my_arr[] = { 0,1,13,2,4,1,6,8,3 };

	heapSort(my_arr, 9);

	for (int i = 1; i < 9; ++i)
	{
		cout << my_arr[i] << endl;
	}

	return 0;
}