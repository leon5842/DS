#include <iostream>
#include <queue>
#include <vector>
#include <list>

using namespace std;

list<int> g_list;

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
	int insertNode_Iteration(int data);
	int search(int key, TreeNode* &parent, TreeNode * &ret);
	int search(int key);
	void delete_node_recursion(TreeNode* &go, int key);
	void delete_node(TreeNode* &go, int key);
	void delete_node(int key);
	void inOrder(TreeNode* cur);
	void inOrder();
	void levelOrder();

	/* get the tree node first visiting in inorder traversal */
	TreeNode* leftMost(TreeNode *cur);

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

int BST::search(int key, TreeNode* &parent, TreeNode * &ret)
{
	TreeNode *cur;

	cur = ret;

	while (cur && cur->val != key) {

		parent = cur;

		if (cur->val < key)
			cur = cur->right;
		else if (cur->val > key)
			cur = cur->left;
	}

	ret = cur;

	if (cur)
		return 0;
	else
		return -1;

}

int BST::search(int key)
{
	TreeNode *parent, *tmp;
	tmp = root;
	return search(key, parent, tmp);
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

int BST::insertNode_Iteration(int data)
{
	TreeNode *cur, *parent, *NewNode;

	parent = NULL;
	cur = root;

	while (cur) {
		if (cur->val < data) {
			parent = cur;
			cur = cur->right;
		} else if (cur->val > data) {
			parent = cur;
			cur = cur->left;
		}
	}

	NewNode = new TreeNode;
	NewNode->val = data;
	NewNode->left = NULL;
	NewNode->right = NULL;

	if (parent->val < data) {
		parent->right = NewNode;
	} else if (parent->val > data) {
		parent->left = NewNode;
	}

	cout << "using iteration to inserted node " << data << endl;
	return 0;
}

void BST::levelOrder()
{
	TreeNode *cur;
	queue<TreeNode*> q;

	q.push(root);

	cout << "LEVEL ORDER" << endl;

	while (!q.empty())
	{
		cur = q.front();
		q.pop();

		cout << cur->val << endl;

		if (cur->left)
			q.push(cur->left);
		if (cur->right)
			q.push(cur->right);
	}
}

TreeNode* BST::leftMost(TreeNode* cur)
{
	while (cur->left){
		cur = cur->left;
	}
	return cur;
}

void BST::inOrder(TreeNode* cur)
{
	if (cur == NULL)
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
		//insertNode(root, data);
		insertNode_Iteration(data);
	} else {
		cout << "allocate new mode " << data << endl; 
		root = new TreeNode;
		root->val = data;
		root->left = NULL;
		root->right = NULL;
	}

	return 0;
}


void BST::delete_node_recursion(TreeNode* &cur, int key)
{
	int ret = 0;

	/* base case, key not found */
	if (cur == NULL)
		return;

	if (cur->val < key)
		delete_node_recursion(cur->right, key);
	else if (cur->val > key)
		delete_node_recursion(cur->left, key);
	else {

		if (cur->left == NULL && cur->right == NULL)
		{
			delete cur;

			cur = NULL;

		} else if (cur->left && cur->right) {

			TreeNode *successor = leftMost(cur->right);

			cur->val = successor->val;

			delete_node_recursion(cur->right, successor->val);

		} else {
			/* check left or right */
			TreeNode *child = cur->left ? cur->left:cur->right;
			TreeNode *tmp = cur;

			/* replace del_node with child */
			cur = child;
			/* delete del_node */
			delete tmp;
		}
	}
}

void BST::delete_node(TreeNode* &go, int key)
{
	TreeNode *cur = NULL, *parent = NULL;
	int ret = 0;

	cur = go;

	ret = search(key, parent, cur);
	if (ret)
		return;

	/* case 1, node was leaf node */
	if (cur->left == NULL && cur->right == NULL)
	{
		if (cur != go) {

			cout << "del node paren = " << parent->val << endl;
			/* check deleted node is in parent left or right child */
			if (parent->left == cur)
				parent->left = NULL;
			else 
				parent->right = NULL;
		} else {
			go = NULL;
		}
		delete cur;

	/* case 2, has both child */
	} else if (cur->left && cur->right) {

		/* get in-order travel successor */
		TreeNode *successor = leftMost(cur->right);
		int tmp = successor->val;
		
		/* free successor */
		delete_node(go, successor->val);

		/* store successor data into delete node */
		cur->val = tmp;

	} else {
			TreeNode *child = (cur->left) ? cur->left:cur->right;

			/* if cur node not root, set cur child to its parent*/
			if (cur != go)
			{
				if (cur == parent->left)
					parent->left = child;
				else
					parent->right = child;
			}
			else
				go = child;
			delete cur;
	}
}

void BST::delete_node(int key)
{
	TreeNode *tmp;

	tmp = root;

delete_node(tmp, key);
//	delete_node_recursion(tmp, key);
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

	if (tree.search(3) == 0)
		cout << "found node" << endl;
	else
		cout << "key val not found" << endl;

	if (tree.search(20) == 0)
		cout << "found node " << endl;
	else
		cout << "key val not found" << endl;

	tree.delete_node(9);
	tree.levelOrder();
	return 0;
}

