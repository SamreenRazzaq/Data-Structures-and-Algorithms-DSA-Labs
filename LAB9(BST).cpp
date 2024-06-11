// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;

// Class describing a node of tree
class Node {
public:
	int val;
	int data;
	Node* left;
	Node* right;
	Node(int v)
	{
		this->data = v;
		this->left = this->right = NULL;
	}
};

// Inorder Traversal
void printInorder(Node* node)
{
	if (node == NULL)
		return;

	// Traverse left subtree
	printInorder(node->left);

	// Visit node
	cout << node->data << " ";

	// Traverse right subtree
	printInorder(node->right);
}
// Preorder Traversal
void printPreOrder(Node* node)
{
    if (node == NULL)
        return;
 
    // Visit Node
    cout << node->data << " ";
 
    // Traverse left subtree
    printPreOrder(node->left);
 
    // Traverse right subtree
    printPreOrder(node->right);
}
// PostOrder Traversal
void printPostOrder(Node* node)
{
    if (node == NULL)
        return;
 
    // Traverse left subtree
    printPostOrder(node->left);
 
    // Traverse right subtree
    printPostOrder(node->right);
 
    // Visit node
    cout << node->data << " ";
}
// Utility function to insert node in BST
void insert(Node*& root, int key)
{
    Node* node = new Node(key);
    if (!root) {
        root = node;
        return;
    }
    Node* prev = NULL;
    Node* temp = root;
    while (temp) {
        if (temp->val > key) {
            prev = temp;
            temp = temp->left;
        }
        else if (temp->val < key) {
            prev = temp;
            temp = temp->right;
        }
    }
    if (prev->val > key)
        prev->left = node;
    else
        prev->right = node;
}

// Driver code
int main()
{
	// Build the tree
	Node* root = new Node(100);
	root->left = new Node(20);
	root->right = new Node(200);
	root->left->left = new Node(10);
	root->left->right = new Node(30);
	root->right->left = new Node(150);
	root->right->right = new Node(300);
	insert(root, 10);

	// Function call
	cout << "Inorder Traversal: "<<endl;
	printInorder(root);
	cout <<endl<<"Preorder Traversal: "<<endl;
    printPreOrder(root);
    cout <<endl<< "PostOrder Traversal: "<<endl;
    printPostOrder(root);
    cout << "\n";
	return 0;
}

