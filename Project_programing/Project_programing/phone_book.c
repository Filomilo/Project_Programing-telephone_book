/**
 * @file phone_book.c
 * @author Tomasz Bogdan, Maciej Cedzyński, Filip Borowiec
 * @brief plik zawiera funkcje do obsługi elementów listy
 * @version 0.1
 * @date 2022-03-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//funckcje odpowiedzlane za zarz�dzanie ksi�zk� telefoniczn�

#include "phone_book.h"
#include <stdlib.h>

/**
 * @brief funkcja odpowiada za wyświetlanie jednego wpisu w kontakcie
 *
 * funkcja wypisuje element kontaktu na zasadzie:
 *
 * ID
 *
 * imię, nazwisko
 *
 *miasto, st.ulica numer, kod pocztowy
 *
 * numer telefonu
 *
 *
 *
 *
 * @param contact - typ conact_type zawierające dane do wyświetlenia przez funkcje
 */

void print_contact(contact_type contact)
{
	printf("ID: %d\n", contact.id);
	printf("Name: %s\tSurname: %s\n", contact.name,contact.surname);
	printf("%s, st.%s %d     %s\n", contact.adress.city, contact.adress.street, contact.adress.number, contact.adress.postal_code);
	printf("pohone number: %s", contact.phone_number);
	printf("\n\n\n");
}


/**
 * @brief funkcja duplikuje otrzymana listę dynamiczną
 *
 * funkcja ta przyjmuje jako parametr lsit_pointers określająca listę do duplikowania
 * następnie tworzy nowa liste new i jeżeli niepodana lista nie jest pusta funkcja wchodzi pętle
 * przechodząca przez wszystkie elementy listy i każdy z elementów dodaje do nowej listy
 * po przeniesieniu wszystkich elementów funkcja zwraca nowo wytworzona listę
 *
 * @param list - struktura list_pointers określają listę do duplikowania
 * @return list_pointers  - struktura lsit_pointers określająca nowa zduplikowaną listę
 */

list_pointers duplicate_book( list_pointers list)
{
	list_pointers new = list_init();
	

	if (list.head == NULL)
	{
		return new;
	}
	while (list.tail != list.head)
	{
		new=list_add_tail(new, list.tail->data);
		list.tail = list.tail->next;


	}
	new = list_add_tail(new, list.tail->data);





	return new;

}


/**
 * @brief funkcja generuje dla listy unikatowe id
 *
 * funkcja ta publikuje listę, do której ma zostać wygenerowany unikatowe id
 * następnie sortuje ja według id, po czym bierze wartość i=0 i idzie przez każdy element posortowanej listy
 * zwiększając wartość i o 1 jeżeli w którymś momencie  wartość i nie będzie się zgadzać z wartością id elementu listy
 * znaczy że to id jest wolne lub jeśli lista się skończyła to również powiększone i będzie oznaczać wolne id
 * i takie zatem zwracać
 *
 * @param list - struktura list_pointers określają listę do duplikowania
 * @return int - zwraca wartość int określająca najmniejsze wolne id
 */

int generate_id(list_pointers list)
{
	int i=0;
	list_pointers tmp = duplicate_book(list);
	tmp = merge_sort(tmp, id_cmp);
	
	list_node* active = tmp.head;

	if (tmp.head == NULL)
	{
		//printf("your list is empty\n");
		return i;
	}
	while (tmp.tail != active)
	{
		i++;
		
		active = active->prev;
		if (active->data.id != i)
		{
			free_list(tmp);
			return i;
		}
			

	}
	i++;
	free_list(tmp);
	
	return i;
}