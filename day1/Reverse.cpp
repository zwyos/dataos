#include <iostream>
#include <iterator>

using namespace std;

struct tnode
{
	int data;
	tnode * next;
};

tnode * reverse_recursive(tnode *head);

int main()
{
	tnode *head = NULL;
	for(int i = 0;i < 10;i++)
	{
		tnode *new_node = new tnode;
		new_node -> data = i * 10;
		new_node -> next = head;
		head = new_node;
	}

	head = reverse_recursive(head);
	tnode *iterator = head;
	while(iterator)
	{
	    cout << iterator -> data << '	';
	    iterator = iterator -> next;
	}
	
	return 0;
}

tnode * reverse_recursive(tnode *head)
{
	if(head == NULL || head->next == NULL)
		return head;
	tnode *second = head -> next;
	tnode *new_head = reverse_recursive(second);
	second -> next = head;
	head -> next = NULL;
	return new_head;
}
