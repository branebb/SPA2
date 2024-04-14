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

	int height(Node *node)
	{
		if (node == nullptr)
			return 0;
		
        return node->height;
	}

    Node* rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *temp = x->right;
 
        x->right = y;
        y->left = temp;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        if(temp != nullptr)
            temp->parent = y;

        x->parent = y->parent;
        y->parent = x;

        return x;
    }

    Node* leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *temp = y->left;

        y->left = x;
        x->right = temp;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        if(temp != nullptr)
            temp->parent = x;

        y->parent = x->parent;
        x->parent = y;

        return y;
    }

    int balanceOfNode(Node *node)
    {
        if(node == nullptr)
            return 0;
        
        return height(node->left) - height(node->right);
    }

    Node* insert(Node *node, int key)
    {
		//insert dio
		
        if(node == nullptr)
            node = new Node {key, 0, nullptr, nullptr, nullptr};
        else if(key < node->key)
        {
            node->left = insert(node->left, key);
            node->left->parent = node;
        }
        else if(key > node->key)
        {
            node->right = insert(node->right, key);
            node->right->parent = node;
        }

        node->height = 1 + max(height(node->left), height(node->right));
		
		//balance dio

        int balance = balanceOfNode(node);

        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        if (balance < -1 && key > node->right->key)
            return leftRotate(node);
        
        if (balance > 1 && key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    
        return node;
    }

    void inorder(Node *node)
    {
        if(node == nullptr)
            return;
        
        inorder(node->left);
        cout << "[K: " << node->key << ", H: " << node->height << ", B: " << balanceOfNode(node) << "] ";
        inorder(node->right);
    }

    void preorder(Node *node)
    {
        if(node == nullptr)
            return;
        
        cout << "[K: " << node->key << ", H: " << node->height << ", B: " << balanceOfNode(node) << "] ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node *node)
    {
        if(node == nullptr)
            return;
        
        postorder(node->left);
        postorder(node->right);
        cout << "[K: " << node->key << ", H: " << node->height << ", B: " << balanceOfNode(node) << "] ";
    }

public:
    AVL() : root(nullptr) {}

	void insert(int key)
	{
        root = insert(root, key);
	}

    void printInorder()
    {
        inorder(root);
    }

    void printPreorder()
    {
        preorder(root);
    }

    void printPostorder()
    {
        preorder(root);
    }
};

int main()
{
	vector<int> keys = {21, 26, 30, 9, 4, 14, 28, 18, 15, 10, 2, 3, 7};
	
	AVL T;
	
	for(auto& el : keys)
		T.insert(el);
	
	T.printInorder();
}