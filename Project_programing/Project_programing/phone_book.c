/**
 * @file phone_book.c
 * @author Tomasz Bogdan, Maciej Cedzyński, Filip Borowiec
 * @brief plik zaweira funkjce do oblsugi elemntow listy
 * @version 0.1
 * @date 2022-03-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//funckcje odpowiedzlane za zarz�dzanie ksi�zk� telefoniczn�

#include "phone_book.h"
#include <stdlib.h>

// funckcja wy�wietlaj�c podany jej konkat wraz z podpisamy
/**
 * @brief funkcja odpowiada ze wyświeltnie jedeno wpisu w kontakcie
 *
 * funckcja wypisuje elemnt konatku na zasadzie: 
 *
 * ID
 *
 * imie, nazwisko
 *
 *miasto, st.ullica numer, kod pocztowy
 *
 * numer telefonu
 *
 *
 *
 * 
 * @param contact - typ conact_type zawierajace dane do wysiwtlenia przez funckje 
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
 * @brief funckcja duplikuje otrzymana liste dynamiczną
 *
 * funkcja ta przyjmuje jako paremtr lsit_pointers okreslajaca lsite do zdubplikowania
 * nastepnie tworzy nowa liste new i jezeli nie podana lsita nie jest pusta funkjca wchodiz petle
 * przechodząca przez wszystkie elemnty listy i kazdy z elemntow dodaje do nowej listy
 * po przepisaniu wszystkich elemntow funkcja zwraca nowo wytworozna liste
 * 
 * @param list - strutura list_pointers okreslaja liste do zduplikowania
 * @return list_pointers  - struktura lsit_pointers okreslajaca nowa zduplikowana lsite
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
 * @brief funkcja genruje dla listy unikatowe id
 * 
 * funckja ta duplikuje liste do ktorej ma zostac wygenrwoany uniktowe id 
 * nastepnie sortuje ja wedlug id po czym bierze wartsoc i=0 i idzie przez kazdy elemnty posortownej listy
 * zwiekszjac wartosc i o 1 jezeli w kotryms momecnie  wartosc i nie bedzie sie zgadzac z wartoscia id elemntu listy
 * znaczy ze to id jest wolne lub jesli lsita sie skonczyla to rowniez powieskzone i bedzie oznaczac wolne id
 * i takie zatem zwracaca
 * 
 * @param list - strutura list_pointers okreslaja liste do zduplikowania
 * @return int - zwraca wartosc int okreslajaca najmniejsze wolne id
 */
int generate_id(list_pointers list)
{
	int i=0;
	list_pointers tmp = duplicate_book(list);
	tmp = merge_sort(tmp, id_cmp);
	
	list_node* active = tmp.head;

	if (tmp.head == NULL)
	{
		printf("your list is empty\n");
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