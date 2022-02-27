//funkcje por�nuj��e ze sob� dwa wpsiy w ks�z�� teleofniczej wykorzystywane w funkcji sortuj�cej

#include "phone_book.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//funkcja por�wnuej ze sob� dwa wpisy w ksi���e telefoniczej w zale�no�ci od warto�ci id
// 1 - dla a>B		0 - dla a=B			-1 - dla a<B

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


//funkcja por�wnuej ze sob� dwa wpisy w ksi���e telefoniczej w zale�no�ci od nazwiska i imienia
// 1 - dla a>B		0 - dla a=B			-1 - dla a<B

int name_cmp(list_node* a, list_node* b)
{
	if (strcmp(a->data.surname, b->data.surname) == 0)
	{

		return strcmp(a->data.name, b->data.name);
	}
	else
		return strcmp(a->data.surname, b->data.surname);
}


//funkcja por�wnuej ze sob� dwa wpisy w ksi���e telefoniczej w zale�no�ci numeru telefonu
// 1 - dla a>B		0 - dla a=B			-1 - dla a<B

int phone_cmp(list_node* a, list_node* b)
{
	return strcmp(a->data.phone_number, b->data.phone_number);
}


//funkcja por�wnuej ze sob� dwa wpisy w ksi���e telefoniczej w zale�no�ci nazwy miasta
// 1 - dla a>B		0 - dla a=B			-1 - dla a<B

int city_cmp(list_node* a, list_node* b)
{
	return strcmp(a->data.adress.city, b->data.adress.city);
}


//funkcja por�wnuej ze sob� dwa wpisy w ksi���e telefoniczej w zale�no�ci nazwy ulicy
// 1 - dla a>B		0 - dla a=B			-1 - dla a<B

int street_cmp(list_node* a, list_node* b)
{
	return strcmp(a->data.adress.street, b->data.adress.street);
}


//funkcja por�wnuej ze sob� dwa wpisy w ksi���e telefoniczej w zale�no�ci od kodu pocztowego
// 1 - dla a>B		0 - dla a=B			-1 - dla a<B

int postal_code_cmp(list_node* a, list_node* b)
{
	return strcmp(a->data.adress.postal_code, b->data.adress.postal_code);
}


//funkcja por�wnuej ze sob� dwa wpisy w ksi���e telefoniczej w zale�no�ci od numeru telefonu
// 1 - dla a>B		0 - dla a=B			-1 - dla a<B

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