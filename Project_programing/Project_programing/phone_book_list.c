#include "phone_book.h"
#include <stdio.h>
#include <stdlib.h>



//funkcja incjuj¹c¹ pust¹ liste czyli nadaje .head i .tail wartosæi NULL,

list_pointers list_init()
{
	list_pointers list;
	list.head = NULL;
	list.tail = NULL;
	return list;
}



//funcja dodaj¹ca elemnt na pocz¹tku listy (za head),

list_pointers list_add_head(list_pointers list, contact_type data)
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



//funcja dodaj¹ca elemnt na koñcu listy(przed tail)

list_pointers list_add_tail(list_pointers list, contact_type data)
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



//funkcja znajduj¹ca elemnt o danym id we wprowadzonej lisæie

list_node* find_node(list_pointers list, int searched_value)
{
	while (list.tail != NULL || list.head == NULL)
	{
		if (list.tail->data.id == searched_value)
			return list.tail;
		list.tail = list.tail->next;

	}
	printf("no value found\n");
	return NULL;
}



//funcja usuwaj¹ca ostatni elemnt listy(tail), 

list_pointers list_remove_tail(list_pointers list)
{
	if (list.tail == NULL)
	{

		printf("ERROR: Nothing to remove\n");
		return list;

	}
	list_node* tmp;
	tmp = list.tail->next;
	free(list.tail);
	if (tmp == NULL)
	{
		list = list_init();
		return list;
	}
	tmp->prev = NULL;
	list.tail = tmp;

	return list;
}



//funcja usuwaj¹ca pierwszy elemnt listy(head)

list_pointers list_remove_head(list_pointers list)
{
	if (list.tail == NULL || list.head == NULL)
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



//funkcja usuwajaca wybrany element listy

list_pointers list_remove_node(list_pointers list, list_node* node_to_remove)
{
	if (node_to_remove == NULL)
	{
		printf("ERROR: no node to remove selected\n");
		return list;
	}
	else
	if (node_to_remove==list.tail)
	{
		printf("\nremoving tail\n");
		list = list_remove_tail(list);
		return list;
	}
	else
	if (node_to_remove == list.head)
	{
		printf("\nremoving head\n");

		list = list_remove_head(list);
		//print_list_head(list);
		print_contact(list.head->data);
		printf("\n\n finsihed test");
		getchar();
		return list;
	}
	else {
		node_to_remove->prev->next = node_to_remove->next;
		node_to_remove->next->prev = node_to_remove->prev;
		free(node_to_remove);
		return list;
	}


}



//funkcja zminiaj¹ca dane wybranego na dane wprowadzone jako argumeny

void list_edit_node(list_node* node_to_edit, contact_type data)
{
	if (node_to_edit == NULL)
	{
		printf("ERROR: no node to edit selected\n");
		return ;
	}
	node_to_edit->data = data;

}



//funckja wyœwietlj¹ca liste pocz¹wszy od head id¹æ do tail

void print_list_head(list_pointers list)
{
	if (list.head == NULL)
	{
		printf("your list is empty\n");
		return;
	}
	while (list.head != list.tail)
	{
		print_contact( list.head->data);
		list.head = list.head->prev;


	}
	print_contact(list.head->data);
	printf("\n");
}



//funckja wyœwietlj¹ca liste pocz¹wszy od tail id¹c do head

void print_list_tail(list_pointers list)
{
	if (list.head == NULL)
	{
		printf("your list is empty\n");
		return;
	}
	while (list.tail != list.head)
	{
		print_contact(list.tail ->data);
		list.tail = list.tail->next;


	}
	print_contact(list.tail->data);
	printf("\n");
}



//funkcja znajudj¹ca œrodek listy wykorzystywana przy sortowaniu

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
	return first;

}


//funkcja usuwajaca liste z pamiêci

list_pointers free_list(list_pointers list)
{

	while (list.head != list.tail)
		list = list_remove_head(list);
	list = list_remove_head(list);
	return list;
}



//funkcja ³acz¹ca ze sob¹ dwie listy sortuj¹c je

list_pointers merge(list_pointers left, list_pointers right, int (*cmp)(contact_type, contact_type))
{
	list_pointers list = list_init();
	
	list_node* lpointer = left.tail;
	list_node* rpointer = right.tail;
	list_node* delpointer = NULL;


	while (lpointer != left.head->next && rpointer != right.head->next)
	{
		if (cmp(lpointer->data, rpointer->data) >= 0)
		{
			list = list_add_head(list, lpointer->data);
			delpointer = lpointer;
			lpointer = lpointer->next;
		}
		else
		{
			list = list_add_head(list, rpointer->data);
			delpointer = rpointer;
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

	left = free_list(left);
	right = free_list(right);

	return list;
}



// funkcja wykorzstyj¹ca sposób merge sort do posortownaia listy

list_pointers merge_sort(list_pointers list, int (*cmp)(contact_type, contact_type))
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


