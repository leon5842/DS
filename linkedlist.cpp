#include <iostream>
#include <vector>
using namespace std;

/* add dummy */
struct node 
{
	int data;
	struct node *next;
};

class linked_list
{
	private:
		struct node *head;
		struct node *tail;
	public:
		linked_list();
		int node_allocate(struct node **new_node, int input);
		void add_tail(int);
		void add_head(int);
		void del_head();
		void del_tail();
		void del_node(int);
		void display();
		void delete_node(int);
};

linked_list::linked_list()
{
	head = tail = NULL;
	cout << "list initalized\n";
}

int linked_list::node_allocate(struct node **tmp, int input)
{
	*tmp = new node;

	/* check dram allocation success */
	if (*tmp) {
		(*tmp)->data = input;
	} else {
		cout << "malloc faield\n";
		return -1;
	}
	return 0;
}

void linked_list::del_head()
{
	struct node *tmp;

	if (head) {
		tmp = head;
		head = head->next;
		delete tmp;
	} else {
		cout << "fuck you\n";
	}
}

void linked_list::del_tail()
{
	struct node *tmp;

	tmp = head;

	while (tmp->next->next)
		tmp = tmp->next;
	delete tmp->next;
	tmp->next = NULL;
}

void linked_list::add_head(int input)
{
	struct node *tmp;

	if (node_allocate(&tmp, input)) {
		cout << "failed of allocate\n";
		return;
	}
	tmp->next = head;
	head = tmp;
}

void linked_list::add_tail(int input)
{
	struct node *tmp;

	if (node_allocate(&tmp, input)) {
		cout << "failed of allocate\n";
		return;
	}

	if (head == NULL) {
		head = tmp;
		head->next = NULL;
	} else {

		struct node *runner = NULL;

		runner = head;

		while(runner->next)
			runner = runner->next;
		runner->next = tmp;
	}
}

void linked_list::del_node(int pos)
{
	struct node *tmp;
	int counter = 0;
	
	tmp = head;

	while(tmp) {
		if (pos - 1 == counter++)
			break;
		tmp = tmp->next;
	}

	if (tmp) {
		struct node *del;

		del = tmp->next;
		tmp->next = tmp->next->next;
		delete del;
	}
}

void linked_list::display()
{
	struct node *runner = NULL;
	int i = 0;
	runner = head;
	while (runner) {
		cout << "data[" << runner->data << "]  ";
		runner = runner->next;
	}
	cout << "\n";
}

int main()
{
	linked_list list;
	vector<int> test(128, 13);

	for (int i = 0; i < test.size(); i++)
		cout << test[i] << endl;

	list.add_tail(3);
	list.add_tail(2);
	list.display();
	list.add_head(0);
	list.display();
	list.add_tail(3);
	list.add_tail(5);
	list.display();
	list.del_tail();
	list.display();
	list.add_tail(4);
	list.display();
	list.add_tail(5);
	list.add_tail(6);
	list.add_tail(5);
	list.display();
	list.del_node(2);
	list.display();
	return 0;
}
