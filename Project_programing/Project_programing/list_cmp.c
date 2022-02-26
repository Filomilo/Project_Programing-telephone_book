#include "phone_book.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int id_cmp(list_node* a, list_node* b)
{
	if(a->data.id> b->data.id)
		return 1;
	else
		if(a->data.id < b->data.id)
			return -1;
		else
			return 0;

}

int name_cmp(list_node* a, list_node* b)
{
	if (strcmp(a->data.surname, b->data.surname) == 0)
	{

		return strcmp(a->data.name, b->data.name);
	}
	else
		return strcmp(a->data.surname, b->data.surname);
}


int phone_cmp(list_node* a, list_node* b)
{
	return strcmp(a->data.phone_number, b->data.phone_number);
}


int city_cmp(list_node* a, list_node* b)
{
	return strcmp(a->data.adress.city, b->data.adress.city);
}

int street_cmp(list_node* a, list_node* b)
{
	return strcmp(a->data.adress.street, b->data.adress.street);
}

int postal_code_cmp(list_node* a, list_node* b)
{
	return strcmp(a->data.adress.postal_code, b->data.adress.postal_code);
}

int number_cmp(list_node* a, list_node* b)
{
	if (a->data.adress.number > b->data.adress.number)
		return 1;
	else
		if (a->data.adress.number < b->data.adress.number)
			return -1;
		else
			return 0;

}