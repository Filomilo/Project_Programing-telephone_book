/**
 * @file list_cmp.c
 * @author Tomasz Bogdan, Maciej Cedzyński, Filip Borowiec
  * @brief plik ten zawiera funkcje porównujące ze sobą dwa elementy listy
 * @version 0.1
 * @date 2022-03-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */



#include "phone_book.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


 /**
  * @brief funkcja porównuje ze sobą od dwóch elementów listy
  *
  * funkcja ta porównuje id dwóch elementów listy i zwraca -1 jeżeli a jest mniejsze od b,
  * 0 jeśli a i b są równe,
  * i 1 jeśli a jest większe od b
  *
  * @param a - wskaźnik lsit_node na element listy a do porównania
  * @param b - wskaźnik lsit_node na element listy b do porównania
  * @return int - zwraca wynik porównania na zasadzie : -1 jeżeli a jest mniejsze od b,
  * 0 jeśli a i b są równe,
  * i 1 jeśli a jest większe od b
  */

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





/**
 * @brief funkcja porównuje ze sobą imię i nazwisko dwóch elementów listy
 *
 * funkcja ta porównuje imię i nazwiska dwóch elementów listy i zwraca -1 jeżeli a jest mniejsze od b,
 * 0 jeśli a i b są równe,
 * i 1 jeśli a jest większe od b
 *
 * @param a - wskaźnik lsit_node na element listy a do porównania
 * @param b - wskaźnik lsit_node na element listy b do porównania
 * @return int - zwraca wynik porównania na zasadzie : -1 jeżeli a jest mniejsze od b,
 * 0 jeśli a i b są równe,
 * i 1 jeśli a jest większe od b
 */

int name_cmp(list_node* a, list_node* b)
{
	if (strcmp(a->data.surname, b->data.surname) == 0)
	{

		return strcmp(a->data.name, b->data.name);
	}
	else
		return strcmp(a->data.surname, b->data.surname);
}



/**
 * @brief funkcja porównuje ze sobą numer telefonu dwóch elementów listy
 *
 * funkcja ta porównuje numer telefonu dwóch elementów listy i zwraca -1 jeżeli a jest mniejsze od b,
 * 0 jeśli a i b są równe,
 * i 1 jeśli a jest większe od b
 *
 * @param a - wskaźnik lsit_node na element listy a do porównania
 * @param b - wskaźnik lsit_node na element listy b do porównania
 * @return int - zwraca wynik porównania na zasadzie : -1 jeżeli a jest mniejsze od b,
 * 0 jeśli a i b są równe,
 * i 1 jeśli a jest większe od b
 */

int phone_cmp(list_node* a, list_node* b)
{
	return strcmp(a->data.phone_number, b->data.phone_number);
}




/**
 * @brief funkcja porównuje ze sobą nazwy miast dwóch elementów
 *
 * funkcja ta porównuje nazwy miast dwóch elementów listy i zwraca -1 jeżeli a jest mniejsze od b,
 * 0 jeśli a i b są równe,
 * i 1 jeśli a jest większe od b
 *
 * @param a - wskaźnik lsit_node na element listy a do porównania
 * @param b - wskaźnik lsit_node na element listy b do porównania
 * @return int - zwraca wynik porównania na zasadzie : -1 jeżeli a jest mniejsze od b,
 * 0 jeśli a i b są równe,
 * i 1 jeśli a jest większe od b
 */

int city_cmp(list_node* a, list_node* b)
{
	return strcmp(a->data.adress.city, b->data.adress.city);
}





/**
 * @brief funkcja porównuje ze sobą nazwy ulic dwóch elementów listy
 *
 * funkcja ta porównuje ulice dwóch elementów listy i zwraca -1 jeżeli a jest mniejsze od b,
 * 0 jeśli a i b są równe,
 * i 1 jeśli a jest większe od b
 *
 * @param a - wskaźnik lsit_node na element listy a do porównania
 * @param b - wskaźnik lsit_node na element listy b do porównania
 * @return int - zwraca wynik porównania na zasadzie : -1 jeżeli a jest mniejsze od b,
 * 0 jeśli a i b są równe,
 * i 1 jeśli a jest większe od b
 */

int street_cmp(list_node* a, list_node* b)
{
	return strcmp(a->data.adress.street, b->data.adress.street);
}

/**
 * @brief funkcja porównuje ze sobą kod pocztowy dwóch elementów listy
 *
 * funkcja ta porównuje kod pocztowy dwóch elementów listy i zwraca -1 jeżeli a jest mniejsze od b,
 * 0 jeśli a i b są równe,
 * i 1 jeśli a jest większe od b
 *
 * @param a - wskaźnik lsit_node na element listy a do porównania
 * @param b - wskaźnik lsit_node na element listy b do porównania
 * @return int - zwraca wynik porównania na zasadzie : -1 jeżeli a jest mniejsze od b,
 * 0 jeśli a i b są równe,
 * i 1 jeśli a jest większe od b
 */

int postal_code_cmp(list_node* a, list_node* b)
{
	return strcmp(a->data.adress.postal_code, b->data.adress.postal_code);
}



/**
 * @brief funkcja porównuje ze sobą numer domu/budynku dwóch elementów listy
 *
 * funkcja ta porównuje numer domu/budynku dwóch elementów listy i zwraca -1 jeżeli a jest mniejsze od b,
 * 0 jeśli a i b są równe,
 * i 1 jeśli a jest większe od b
 *
 * @param a - wskaźnik lsit_node na element listy a do porównania
 * @param b - wskaźnik lsit_node na element listy b do porównania
 * @return int - zwraca wynik porównania na zasadzie : -1 jeżeli a jest mniejsze od b,
 * 0 jeśli a i b są równe,
 * i 1 jeśli a jest większe od b
 */

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
