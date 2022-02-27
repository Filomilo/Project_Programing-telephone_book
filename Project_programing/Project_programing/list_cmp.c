//funkcje porónuj¹æe ze sob¹ dwa wpsiy w ks¹zæê teleofniczej wykorzystywane w funkcji sortuj¹cej

#include "phone_book.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//funkcja porównuej ze sob¹ dwa wpisy w ksi¹¿æe telefoniczej w zale¿noœci od wartoœci id
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


//funkcja porównuej ze sob¹ dwa wpisy w ksi¹¿æe telefoniczej w zale¿noœci od nazwiska i imienia
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


//funkcja porównuej ze sob¹ dwa wpisy w ksi¹¿æe telefoniczej w zale¿noœci numeru telefonu
// 1 - dla a>B		0 - dla a=B			-1 - dla a<B

int phone_cmp(list_node* a, list_node* b)
{
	return strcmp(a->data.phone_number, b->data.phone_number);
}


//funkcja porównuej ze sob¹ dwa wpisy w ksi¹¿æe telefoniczej w zale¿noœci nazwy miasta
// 1 - dla a>B		0 - dla a=B			-1 - dla a<B

int city_cmp(list_node* a, list_node* b)
{
	return strcmp(a->data.adress.city, b->data.adress.city);
}


//funkcja porównuej ze sob¹ dwa wpisy w ksi¹¿æe telefoniczej w zale¿noœci nazwy ulicy
// 1 - dla a>B		0 - dla a=B			-1 - dla a<B

int street_cmp(list_node* a, list_node* b)
{
	return strcmp(a->data.adress.street, b->data.adress.street);
}


//funkcja porównuej ze sob¹ dwa wpisy w ksi¹¿æe telefoniczej w zale¿noœci od kodu pocztowego
// 1 - dla a>B		0 - dla a=B			-1 - dla a<B

int postal_code_cmp(list_node* a, list_node* b)
{
	return strcmp(a->data.adress.postal_code, b->data.adress.postal_code);
}


//funkcja porównuej ze sob¹ dwa wpisy w ksi¹¿æe telefoniczej w zale¿noœci od numeru telefonu
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