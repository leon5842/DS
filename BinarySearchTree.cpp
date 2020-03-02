#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/* construct a binary search tree */
class BST {

public:
	BST();
	~BST();
	int insertNode(int data);
	TreeNode* insertNode(TreeNode *node, int data);
	void inOrder(TreeNode* cur);
	void inOrder();

private:
		TreeNode *root;
};

BST::BST()
{
	root = NULL;
}

/* delete all nodes */
BST::~BST()
{

}

TreeNode* BST::insertNode(TreeNode *node,int data)
{
	if (node != NULL) {
		if (node->val < data) {
			node->right = insertNode(node->right, data);
		}
		else if (node->val > data) {
			node->left = insertNode(node->left, data);
		}
	} else {
		TreeNode *NewNode = new TreeNode;
		NewNode->val = data;
		NewNode->left = NULL;
		NewNode->right = NULL;
		return NewNode;
	}
	return node;
}


void BST::inOrder(TreeNode* cur)
{
	if (!cur)
		return;

	inOrder(cur->left);
	cout << cur->val << endl;
	inOrder(cur->right);
}

void BST::inOrder()
{
	inOrder(root);
	cout << "end of in-order parsing" << endl;
}

int BST::insertNode(int data)
{
	if (root) {
		insertNode(root, data);
	} else {
		cout << "allocate new mode " << data << endl; 
		root = new TreeNode;
		root->val = data;
		root->left = NULL;
		root->right = NULL;
	}

	return 0;
}

int main()
{
	BST tree;
	tree.insertNode(10);
	tree.insertNode(15);
	tree.insertNode(18);
	tree.insertNode(3);
	tree.insertNode(8);
	tree.insertNode(9);
	tree.insertNode(5);
	tree.inOrder();
	return 0;
}

