#include <iostream>

using namespace std;

struct node {
	int data;
	struct node *left;
	struct node *right;
};

class BinaryTree
{
	public:
		BinaryTree(){}
		void createRoot(int);
		void insertLeft(struct node *, int);
		void insertRight(struct node *, int);
		void preOrder(struct node *start);
		void inOrder(struct node *start);
		void postOrder(struct node *start);
		struct node *root;
};

void BinaryTree::preOrder(struct node *cur)
{
	if (cur) {
		cout << cur->data << endl;
		preOrder(cur->left);
		preOrder(cur->right);
	}
}

void BinaryTree::inOrder(struct node *cur)
{
	if (cur) {
		inOrder(cur->left);
		cout << cur->data << endl;
		inOrder(cur->right);
	}
}

void BinaryTree::postOrder(struct node *cur)
{
	if (cur != NULL) {
		postOrder(cur->left);
		postOrder(cur->right);
		cout << cur->data << endl;
	}
}

void BinaryTree::createRoot(int input)
{
	root = new node;
	root->data = input;
	root->left = root->right = NULL;
}

void BinaryTree::insertLeft(struct node *sub, int input)
{
	struct node *tmp = new node;
	sub->left = tmp;
	sub->left->data = input;
}

void BinaryTree::insertRight(struct node *sub, int input)
{
	struct node *tmp = new node;
	tmp->data = input;
	sub->right = tmp;
}

int main()
{
	BinaryTree tree;
	tree.createRoot(1);
	tree.insertLeft(tree.root, 2);
	tree.insertRight(tree.root, 3);
	tree.insertRight(tree.root->left, 5);
	printf("preOrder\n");
	tree.preOrder(tree.root);
	printf("in-order\n");
	tree.inOrder(tree.root);
	printf("post-order\n");
	tree.postOrder(tree.root);
	return 0;
}
