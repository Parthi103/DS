#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s
{
	int data;
	struct node_s *next;
}node_t;


node_t * create_node(int data)
{
	node_t *temp = NULL;
	temp = (node_t *)malloc(sizeof(node_t));
	if(temp == NULL)
		return NULL;
	memset(temp, 0, sizeof(node_t));

	temp->data = data;
	return temp;
}

node_t * create_list(node_t *head, int data)
{
	node_t *temp = NULL;

	if(head == NULL)
		return create_node(data);

	temp = head;

	while(temp->next != NULL)
		temp = temp->next;

	temp->next = create_node(data);

	return head;
}

void print_list(char *str, node_t *head)
{
	node_t *temp;
	temp = head;
	printf("\n%s:==\n", str);
	while(temp != NULL)
	{
		printf("%d \t", temp->data);
		temp = temp->next;
	}
	return;
}


node_t * insert_list(node_t *head, int *arr, int size)
{
	int i = 0;

	for(i = 0; i < size; i++)
	{
		head = create_list(head, arr[i]);
	}

	return head;
}

node_t * merge_list(node_t *head, node_t *list1, node_t *list2)
{
	if(list1 == NULL || list2 == NULL)
		return head;

	if(list1->data == list2->data)
	{
		head = create_list(head, list1->data);
		list1 = list1->next;
		list2 = list2->next;
	}
	else
	{
		if(list1->data < list2->data)
			list1 = list1->next;
		else
			list2 = list2->next;
	}
	return merge_list(head, list1, list2);

}

int main()
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int b[] = {2, 4, 6, 8, 10, 11, 12, 13, 14, 15};

	node_t *list1 = NULL;
	node_t *list2 = NULL;
	node_t *merge = NULL;

	list1 = insert_list(list1, a, (sizeof(a)/sizeof(int)));
	list2 = insert_list(list2, b, (sizeof(b)/sizeof(int)));

	print_list("Input1", list1);
	print_list("Input2", list2);

	merge = merge_list(NULL, list1, list2);

	print_list("Output", merge);

	return 0;
}
