//funkcje odopwiadaj¹ce za wyszukiwanie we liscie

#include "phone_book.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void string_to_low(char string[30])
{
	for (int i=0; i< strlen(string); i++)
	{
		string[i] = tolower(string[i]);

	}

}



int is_search_name(char string[30], contact_type node)
{
	string_to_low(node.name);
	char temp[30];
	strncpy_s(temp, 30, string, 30);
	string_to_low(temp);
	if (strncmp(node.name, temp, strlen(temp)) != 0)
		return 0;
	else
		return 1;
}


int is_search_surname(char string[30], contact_type node)
{
	string_to_low(node.surname);
	char temp[30];
	strncpy_s(temp, 30, string, 30);
	string_to_low(temp);
	if (strncmp(node.surname, temp, strlen(temp)) != 0)
		return 0;
	else
		return 1;
}


int is_search_phone_number(char string[30], contact_type node)
{
	string_to_low(node.phone_number);
	char temp[30];
	strncpy_s(temp, 30, string, 30);
	string_to_low(temp);
	if (strncmp(node.phone_number, temp, strlen(temp)) != 0)
		return 0;
	else
		return 1;
}


int is_search_city(char string[30], contact_type node)
{
	string_to_low(node.adress.city);
	char temp[30];
	strncpy_s(temp,30, string, 30);
	string_to_low(temp);
	if (strncmp(node.adress.city, temp, strlen(temp)) != 0)
		return 0;
	else
		return 1;
}

int is_search_street(char string[30], contact_type node)
{
	string_to_low(node.adress.street);
	char temp[30];
	strncpy_s(temp, 30, string, 30);
	string_to_low(temp);
	if (strncmp(node.adress.street, temp, strlen(temp)) != 0)
		return 0;
	else
		return 1;
}



int is_search_postal_code(char string[30], contact_type node)
{

	if (strncmp(node.adress.postal_code, string, strlen(string)) != 0)
		return 0;
	else
		return 1;
}


int is_search_number(char string[30], contact_type node)
{
	int number = atoi(string);
	if (node.adress.number!= number)
		return 0;
	else
		return 1;
}


list_pointers search_results(list_pointers list, int(*is_selected)(char[30], contact_type), char text[30])
{
	list_pointers new_list = list_init();


	if (list.head == NULL)
	{
		return new_list;
	}
	while (list.tail != list.head)
	{
		
		if(is_selected(text,list.tail->data))
			new_list=list_add_head(new_list,list.tail->data);


		list.tail = list.tail->next;


	}
	
	printf("\n");

		print_list_tail(new_list);


		return new_list;
}