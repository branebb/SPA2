#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int key;
    int height;
    //new
    int size;
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

    //new
    int size(Node *node)
    {
        if(node == nullptr)
            return 0;
        
        return node->size;
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

        //new
        int ySize = size(y);
        int xSize = size(x);
        int tempSize = size(temp);

        x->size = ySize;
        y->size = size(y->right) + tempSize + 1;

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

        //new
        int ySize = size(y);
        int xSize = size(x);
        int tempSize = size(temp);

        y->size = xSize;
        x->size = size(x->left) + tempSize + 1;

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
        //new
        if(node == nullptr)
            node = new Node {key, 0, 1, nullptr, nullptr, nullptr};
        else if(key < node->key)
        {
            node->left = insert(node->left, key);
            node->left->parent = node;
            node->size++;
        }
        else if(key > node->key)
        {
            node->right = insert(node->right, key);
            node->right->parent = node;
            node->size++;
        }

        node->height = 1 + max(height(node->left), height(node->right));

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
        cout << "[K: " << node->key << ", H: " << node->height << ", B: " << balanceOfNode(node) << ", S: " << node->size << "] ";
        inorder(node->right);
    }

    void preorder(Node *node)
    {
        if(node == nullptr)
            return;
        
        cout << "[K: " << node->key << ", H: " << node->height << ", B: " << balanceOfNode(node) << ", S: " << node->size << "] ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node *node)
    {
        if(node == nullptr)
            return;
        
        postorder(node->left);
        postorder(node->right);
        cout << "[K: " << node->key << ", H: " << node->height << ", B: " << balanceOfNode(node) << ", S: " << node->size << "] ";
    }

    Node* OS_SELECT(Node* node, int i) 
    {
        if (node == nullptr) 
            return nullptr;

        int r = size(node->left) + 1;

        if (i == r)
            return node;
        else if (i < r)
            return OS_SELECT(node->left, i);
        else 
            return OS_SELECT(node->right, i - r);
    }

    int OS_KEY_RANK(Node *node, int k) 
    {
        if (node == nullptr)
            return 0;
        if (node->key == k)
            return 1 + size(node->left);
        if (node->key > k)
            return OS_KEY_RANK(node->left, k);
        return 1 + size(node->left) + OS_KEY_RANK(node->right, k);
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

    void OS_SELECT(int i) 
    {
        Node* node = OS_SELECT(root, i);
        cout << "[K: " << node->key << ", H: " << node->height << ", B: " << balanceOfNode(node) << ", S: " << node->size << "] ";
    }

    void ithSuccessor(int key, int i) 
    {
        int r = OS_KEY_RANK(root, key) + i;
        Node* succ = OS_SELECT(root, r);
        cout << "[K: " << succ->key << ", H: " << succ->height << ", B: " << balanceOfNode(succ) << ", S: " << succ->size << "] ";
    }

    int OS_KEY_RANK(AVL T, int k) 
    {
        return OS_KEY_RANK(T.root, k);
    }
};

int main()
{
	
}