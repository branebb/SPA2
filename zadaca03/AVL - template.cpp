#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int key;
    int height;
	Node *left, *right, *parent;
};

class AVL
{
private:
    
    Node *root; 
    //(2)
	int height(Node *node)
	{
		
	}
    //(5)
    Node* rightRotate(Node *y)
    {
       
    }
    //(5)
    Node* leftRotate(Node *x)
    {
       
    }
    //(1)
    int balanceOfNode(Node *node)
    {
        
    }
    //(10)
    Node* insert(Node *node, int key)
    {
       
    }
    //(3)
    void inorder(Node *node)
    {
        
    }
    //(3)
    void preorder(Node *node)
    {
        
    }
    //(3)
    void postorder(Node *node)
    {
        
    }

public:
    AVL() : root(nullptr) {}

	void insert(int key)
	{
        
	}

    void printInorder()
    {
        
    }

    void printPreorder()
    {
        
    }

    void printPostorder()
    {
        
    }
};

int main()
{
	//(8)
}