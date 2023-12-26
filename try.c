#include <stdio.h>
#include <stdlib.h>
typedef struct a
{
	int data;
	struct a *next;
}	a_list;


void	rotate_a(struct a **list)
{
	struct a *iter;
	struct a *holder;
	iter = *list;
	*list = (*list) -> next;
	holder = *list;
	while(holder -> next != NULL)
		holder = holder -> next;
	holder -> next = iter;
	iter -> next = NULL;
}


int main()
{
	struct a *head;
	struct a *iter;
	int i = 1;
	head = (struct a *)malloc(sizeof(struct a));
	head -> data  = 2;
	head -> next = NULL;
	iter = head;
	while(i <= 5)
	{
		iter -> next = (struct a *)malloc(sizeof(struct a));
		iter -> next -> data = i * 10;
		iter -> next -> next = NULL;
		i++;
		iter = iter -> next;
	}

	rotate_a(&head);
	iter = head;
	while(iter != NULL)
	{
		printf("%d\n", iter-> data);
		iter = iter -> next;
	}
}