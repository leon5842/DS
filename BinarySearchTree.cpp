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
	int search(int key, TreeNode * &ret);
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

int BST::search(int key, TreeNode * &ret)
{
	TreeNode *cur;

	cur = root;

	while (cur) {
		if (cur->val < key)
			cur = cur->right;
		else if (cur->val > key)
			cur = cur->left;
		else
			break;
	}

	ret = cur;

	if (cur)
		return 0;
	else
		return -1;

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
	TreeNode *result = NULL;

	tree.insertNode(10);
	tree.insertNode(15);
	tree.insertNode(18);
	tree.insertNode(3);
	tree.insertNode(8);
	tree.insertNode(9);
	tree.insertNode(5);
	tree.inOrder();

	if (tree.search(3, result) == 0)
		cout << "found node -->" << result->val << endl;
	else
		cout << "key val not found" << endl;
	if (tree.search(20, result) == 0)
		cout << "found node -->" << result->val << endl;
	else
		cout << "key val not found" << endl;



	return 0;
}

