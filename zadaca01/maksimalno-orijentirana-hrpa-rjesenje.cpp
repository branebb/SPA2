#include <iostream>
#include <vector>
#include <random>

using namespace std;

class MaxHeap
{
public:
	vector<int> A;
	int heap_size;
	int capacity;

public:
	MaxHeap(int capacity)
	{
		A.resize(capacity);
		heap_size = 0;
		this->capacity = capacity;
	}

	MaxHeap(vector<int> A)
	{
		this->A = A;
		heap_size = A.size();
		capacity = A.size();

		for (int i = (capacity - 2) / 2; i >= 0; --i)
			max_heapify(i);
	}

	bool empty()
	{
		return heap_size == 0;
	}

	bool full()
	{
		return heap_size == capacity;
	}

	int left(int i)
	{
		// 2i + 1
		return (i << 1) + 1;
	}

	int right(int i)
	{
		// 2i + 2
		return (i << 1) + 2;
	}

	int parent(int i)
	{
		// (i - 1) / 2
		return (i - 1) >> 1;
	}

	void max_heapify(int i)
	{
		if (i >= heap_size) 
		{
			cout << "Out of bounds in max_heapify!" << endl;
			return;
		}

		int l = left(i);
		int r = right(i);
		int largest = i;

		if (l < heap_size && A[l] > A[largest])
			largest = l;
		if (r < heap_size && A[r] > A[largest])
			largest = r;
		if (largest != i) 
		{
			swap(A[largest], A[i]);
			max_heapify(largest);
		} 
	}

	void insert_key(int key)
	{
		if (full()) 
		{
			cout << "Heap overflow in insert_key" << endl;
			return;
		}

		heap_size++;
		int i = heap_size - 1;
		A[i] = key;
		while (i != 0 && A[parent(i)] < A[i]) 
		{
			swap(A[i], A[parent(i)]);
			i = parent(i);
		}
	}

	int get_max()
	{
		if (empty()) 
		{
			cout << "Heap underflow in get_max!" << endl;
			return -1e9;
		}

		return A[0];
	}

	int extract_max()
	{ 
		if (empty()) 
		{
			cout << "Heap underflow in extract_max!" << endl;
			return -1e9;
		}

		int mx = A[0];
		A[0] = A[heap_size - 1];
		heap_size -= 1;
		max_heapify(0);

		return mx;
	}

	void increase_key(int i, int key)
	{
		if (i >= heap_size) 
		{
			cout << "Out of bounds in increase_key!" << endl;
			return;
		}

		if (key < A[i]) 
		{
			cout << "Error in increase_key, new key smaller than old key!" << endl;
			return;
		}

		A[i] = key;

		while (i != 0 && A[parent(i)] < A[i]) 
		{
			swap(A[i], A[parent(i)]);
			i = parent(i);
		}
	}

	void delete_key(int i)
	{
		if (i >= heap_size) 
		{
			cout << "Out of bounds in delete_key!" << endl;
			return;
		}

		increase_key(i, 1e9);
		extract_max();
	}

	friend ostream& operator<<(ostream &os, const MaxHeap& mh)
	{
		for (int i = 0; i < mh.heap_size; ++i)
			os << mh.A[i] << ' ';
		return os;
	}
};

void heapsort(vector<int> &A)
{
	MaxHeap mh(A);

	for (int i = A.size() - 1; i > 0; --i) 
	{
		swap(mh.A[0], mh.A[i]);
		mh.heap_size -= 1;
		mh.max_heapify(0);
	}

	mh.heap_size = A.size();
	mh.capacity = A.size();
	A = mh.A;		
}

int main()
{

}