#include <stdio.h>
#include <stdlib.h>

typedef struct lst{
	int data;
	struct lst *next;
}list;

void	lst_wr(struct lst *node)
{
	struct lst *iter;
	iter = node;
	while(iter !=NULL)
	{
		printf("%d\n", iter -> data);
		iter = iter -> next;
	}
}

void	reverse_rotate_a(struct lst **a_list)
{
	struct lst *iter;
	int i  = 0;
	iter = *a_list;
	while(iter -> next != NULL)
	{
		iter = iter -> next;
		i++;
	}
	iter -> next = *a_list;
	(*a_list) = iter;
	while(i > 0)
	{
		iter = iter -> next;
		i--;
	}
	iter -> next = NULL;
}

void	reverse_rotate_b(struct lst **b_list)
{
	struct lst *iter;
	int i  = 0;
	iter = *b_list;
	while(iter -> next != NULL)
	{
		iter = iter -> next;
		i++;
	}
	iter -> next = *b_list;
	(*b_list) = iter;
	while(i > 0)
	{
		iter = iter -> next;
		i--;
	}
	iter -> next = NULL;
}

void	reverse_rotate_both_of_them(struct lst **a_list, struct lst **b_list)
{
	reverse_rotate_a(&*a_list);
	reverse_rotate_b(&*b_list);
}

int main()
{
	int i = 1;
	struct lst *a_list;
	struct lst *a_list_holder;
	a_list = (struct lst *)malloc(sizeof(struct lst));
	a_list -> data = 2;
	a_list -> next = NULL;
	a_list_holder = a_list;
	while(i <= 4)
	{
		a_list_holder -> next = (struct lst *)malloc(sizeof(struct lst));
		a_list_holder -> next -> data = i * 10;
		a_list_holder -> next -> next =NULL;
		a_list_holder = a_list_holder -> next;
		i++;
	}
	struct lst *b_list;
	struct lst *b_list_holder;
	b_list = (struct lst *)malloc(sizeof(struct lst));
	b_list -> data = 3;
	b_list -> next = NULL;
	b_list_holder = b_list;
	i = 1;
	while(i <= 4)
	{
		b_list_holder -> next = (struct lst *)malloc(sizeof(struct lst));
		b_list_holder -> next -> data = i * 10;
		b_list_holder -> next -> next =NULL;
		b_list_holder = b_list_holder -> next;
		i++;
	}
	reverse_rotate_both_of_them(&a_list, &b_list);
	lst_wr(a_list);
	printf("---------------------------------------------------------------------------------------------------\n");
	lst_wr(b_list);
}
