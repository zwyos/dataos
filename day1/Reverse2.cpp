#include <iostream>
#include <iterator>

using namespace std;

struct tnode
{
	int data;
	tnode * next;
};

tnode * reverse_iteration(tnode *head);

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

	head = reverse_iteration(head);
	tnode *iterator = head;
	while(iterator)
	{
	    cout << iterator -> data << '	';
	    iterator = iterator -> next;
	}
	
	return 0;
}

tnode * reverse_iteration(tnode *head)
{
	if(head == NULL || head->next == NULL)
		return head;
	tnode *p = head -> next;
	tnode *p_previous = head;
	head -> next = NULL;
	while(p != NULL) 
	{
	    tnode *p_next = p -> next;
	    p -> next = p_previous;
	    p_previous = p;
	    p = p -> next;
	}
	return p_previous;
}


