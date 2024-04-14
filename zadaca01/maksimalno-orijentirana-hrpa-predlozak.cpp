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
	// (1)
	MaxHeap(int capacity)
	{

	}

	// ovdje odmah za dano proizvoljno polje odmah izgradite maksimalno orijentiranu hrpu
	// (3)
	MaxHeap(vector<int> A)
	{
		
	}

	// (1)
	bool empty()
	{
		
	}

	// (1)
	bool full()
	{
		
	}

	// možete napraviti po formuli, no pogledajte kako funkcioniraju shift operatori (<< i >>)
	// (1)
	int left(int i)
	{
		
	}

	// možete napraviti po formuli, no pogledajte kako funkcioniraju shift operatori (<< i >>)
	// (1)
	int right(int i)
	{
		
	}

	// možete napraviti po formuli, no pogledajte kako funkcioniraju shift operatori (<< i >>)
	// (1)
	int parent(int i)
	{
		
	}

	// (5)
	void max_heapify(int i)
	{
		
	}

	// (4)
	void insert_key(int key)
	{
		
	}

	// (1)
	int get_max()
	{
		
	}

	// (3)
	int extract_max()
	{ 
		
	}

	// (5)
	void increase_key(int i, int key)
	{
		
	}

	// (3)
	void delete_key(int i)
	{
		
	}

	// neobavezan dio (nece se ocjenjivati)
	friend ostream& operator<<(ostream &os, const MaxHeap& mh)
	{

	}
};

// (10)
void heapsort(vector<int> &A)
{
			
}

int main()
{
	//izradite svoj testni primjer i testirajte
	//za bolji test mozete koristiti random number generator
	//koji se moze naci na
	//https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
	// (10)
}