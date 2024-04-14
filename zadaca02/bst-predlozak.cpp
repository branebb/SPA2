#include <iostream>
using namespace std;

struct Node
{
	int key;
	Node *left, *right, *parent;
};

class BST
{
	Node *root;
	
	// (5)
	Node* insert(int key, Node *node)
	{
		
	}

	// (3)
	void inorder(Node *node)
	{
		
	}

	// (3)
	Node* search(int key, Node *node)
	{
		
	}

	// (2)
	Node* find_min(Node *node)
	{
		
	}

	// (2)
	Node* find_max(Node *node)
	{
		
	}

	// (5)
	Node* successor(Node *node)
	{
		
	}

	// (5)
	Node* predecessor(Node *node)
	{
		
	}

	// (10)
	Node* BSTdelete(int key, Node *node)
    {
        
	}

public:
	
	BST() : root(NULL) {}
	
	void print()
	{
		
	}

	void insert(int key)
	{
		
	}

	bool search(int key)
	{
		
	}

	int find_min()
	{
	
	}

	int find_max()
	{

	}

	int successor(int key)
	{

	}

	int predecessor(int key)
	{

	}

	void BSTdelete(int key)
    {

    }
};

int main()
{
	// (10)
}
