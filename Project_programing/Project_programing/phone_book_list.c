#include "phone_book.h"
#include <stdio.h>
#include <stdlib.h>



list_pointers list_init()
{
	list_pointers list;
	list.head = NULL;
	list.tail = NULL;
	return list;
}

list_pointers list_add_head(list_pointers list, list_data data)
{
	list_node* new_node = (list_node*)malloc(sizeof(list_node));
	if (new_node == NULL)
	{

		printf("ERROR: Stack oberflow");
		return list;

	}

	new_node->next = NULL;
	new_node->prev = list.head;
	new_node->data = data;
	if (list.head != NULL)
	{
		list.head->next = new_node;
	}

	if (list.tail == NULL)
		list.tail = new_node;

	list.head = new_node;



		return list;
}

list_pointers list_add_tail(list_pointers list, list_data data)
{
	list_node* new_node = (list_node*)malloc(sizeof(list_node));
	if (new_node == NULL)
	{

		printf("ERROR: Stack oberflow");
		return list;

	}

	new_node->next = list.tail;
	new_node->prev = NULL;
	new_node->data = data;
	if (list.head == NULL)
	{
		list.head = new_node;
	}

	if (list.tail != NULL)
		list.tail->prev = new_node;

	list.tail = new_node;



	return list;
}

list_node* find_node(list_pointers list, list_data searched_value)
{
	while (list.tail != NULL)
	{
		if (list.tail->data == searched_value)
			return list.tail;
		list.tail = list.tail->next;

	}
	printf("no value found\n");
	return NULL;
}

list_pointers list_remove_tail(list_pointers list)
{
	if (list.tail == NULL)
	{

		printf("ERROR: Nothing to remove\n");
		return list;

	}
	list_node* tmp;
	tmp = list.tail->next;
	tmp->prev = NULL;
	free(list.tail);
	list.tail = tmp;

	return list;
}

list_pointers list_remove_head(list_pointers list)
{
	if (list.tail == NULL)
	{

		printf("ERROR: Nothing to remove\n");
		return list;

	}
	if (list.head->prev == NULL)
	{
		free(list.head);
		list.head = NULL;
		list.tail = NULL;
		return list;
	}

	list_node* tmp;
	
	tmp = list.head->prev;
	tmp->next = NULL;
	free(list.head);
	list.head = tmp;

	return list;
}

list_pointers list_remove_node(list_pointers list, list_node* node_to_remove)
{
	if (node_to_remove == NULL)
	{
		printf("ERROR: no node to remove selected\n");
		return list;
	}
	if (node_to_remove == list.head)
	{
		list = list_remove_head(list);
		return list;
	}
	if (node_to_remove == list.tail)
	{
		list = list_remove_tail(list);
		return list;
	}
	node_to_remove->prev->next = node_to_remove->next;
	node_to_remove->next->prev = node_to_remove->prev;
	free(node_to_remove);
	return list;



}

void list_edit_node(list_node* node_to_edit, list_data data)
{
	if (node_to_edit == NULL)
	{
		printf("ERROR: no node to edit selected\n");
		return ;
	}
	node_to_edit->data = data;

}

void print_list_head(list_pointers list)
{
	if (list.head == NULL)
	{
		printf("your list is empty\n");
		return;
	}
	while (list.head != list.tail)
	{
		printf("%d, ", list.head->data);
		list.head = list.head->prev;


	}
	printf("%d, ", list.head->data);
	printf("\n");
}

void print_list_tail(list_pointers list)
{
	if (list.head == NULL)
	{
		printf("your list is empty\n");
		return;
	}
	while (list.tail != list.head)
	{
		printf("%d, ", list.tail ->data);
		list.tail = list.tail->next;


	}
	printf("%d, ", list.tail ->data);
	printf("\n");
}

list_node* find_middle_node(list_pointers list)
{
	if (list.head==NULL )
	{
		printf("ERROR: list is empty");
		return NULL;
	}
	if (list.head == list.tail)
	{
		return list.head;
	}
	list_node* first = list.tail;
	list_node* sec = list.tail;
	while (sec->next != list.head && sec->next->next != list.head)
	{
		first = first->next;
		sec=sec->next->next;
	}
	//first = first->next;
	return first;

}

list_pointers merge(list_pointers left, list_pointers right, int (*cmp)(list_data, list_data))
{
	list_pointers list = list_init();
	
	list_node* lpointer = left.tail;
	list_node* rpointer = right.tail;



	while (lpointer != left.head->next && rpointer != right.head->next)
	{
		if (cmp(lpointer->data, rpointer->data) >= 0)
		{
			list = list_add_head(list, lpointer->data);
			lpointer = lpointer->next;
		}
		else
		{
			list = list_add_head(list, rpointer->data);
			rpointer = rpointer->next;
		}
	}

	while (lpointer!= left.head->next)
	{
		list = list_add_head(list, lpointer->data);
		lpointer = lpointer->next;
	}

	while (rpointer != right.head->next)
	{
		list = list_add_head(list, rpointer->data);
		rpointer = rpointer->next;
	}


	printf("tst: \n");
	print_list_tail(list);

	return list;
}

list_pointers merge_sort(list_pointers list, int (*cmp)(list_data, list_data))
{
	if (list.head == list.tail)
		return list;
	list_node* mid = find_middle_node(list);
	list_pointers left_list;
	left_list.head = list.head;
	left_list.tail = mid->next;

	list_pointers right_list;
	right_list.head = mid;
	right_list.tail = list.tail;



	left_list = merge_sort(left_list, cmp);
	right_list = merge_sort(right_list, cmp);
	return merge(left_list,right_list, cmp);
}




