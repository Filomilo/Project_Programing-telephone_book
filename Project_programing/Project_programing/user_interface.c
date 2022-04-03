/**
 * @file user_interface.c
 * @author Tomasz Bogdan, Maciej Cedzyński, Filip Borowiec
 * @brief plik zawiera funkcje odpowiedzialne konsolowy interfejs użytkownika
 * @version 0.1
 * @date 2022-03-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "phone_book.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>










 /**
  * @brief funkcja odpowiedzialna za wpisywanie danych do dowanie nowego elementu do listy o podanych przez użytkownika danych
  *
  * funkcja tworzy nowy element contact type a następnie po kolei prosi użytkownika o podanie
  * imienia i nazwiska, nazwy ulicy, numeru domu/budynku, kodu pocztowego, nazwy miasta, numer telefonu
  * następnie elemnt_conatact_type zostaje dodany do listy z użyciem funkcji list_add_head
  *
  * @param list - struktura list_pointers określająca listę do której użytkownik ma dopisać element
  * @return list_pointers - zwraca struktura lsit_pointers z dodanym elementem przez użytkownika
  */
/*
list_pointers add_new_element(list_pointers list)
{
	system("cls");
	

	system("cls");
	contact_type contact;
	printf("please provide full name of your contact:\n");
	scanf_s("%s", contact.name, 30);
	scanf_s("%s", contact.surname, 30);

	printf("please provide street name of your contact:\n");
	scanf_s("%s", contact.adress.street, 30);

	printf("please provide house number of your contact:\n");
	scanf_s("%d", &contact.adress.number, 1);

	printf("please provide postal code of your contact:\n");
	scanf_s("%s", contact.adress.postal_code, 7);

	printf("please provide city name of your contact:\n");
	scanf_s("%s", contact.adress.city, 30);

	printf("please provide phone number of your contact:\n");
	scanf_s("%s", contact.phone_number, 10);
	contact.id = 1;
	 
	contact.id = generate_id(list);
	list = list_add_head(list, contact);


	return list;
}
*/
int i = 1;
list_pointers add_new_element(list_pointers list)
{
	system("cls");


	system("cls");
	contact_type contact=generate_rand_contact(time(0)*clock()*i+i);
	list = list_add_head(list, contact);

	i++;
	return list;
}


/**
 * @brief funkcja odpowiada za interfejs pozwalający przeszukać listę
 *
 * funkcja wpierw w porodzi użytkownika o podanie ciągu znaków według której ma zostać przeszukana lista
 * a następnie tworzy listę rezultatów z użyciem tego ciągu znaków oraz funkcji podanej jako argument funkcji określająca
 * według którego elementu jest przeszukiwane
 *
 * @param list - struktura list_pointers określająca listę która użytkownik przeszukuje
 * @param search_option - wskaźnik na funkcje określające według którego elementu kontaktu będzie przeszukiwanie można wybrać:
 * is_search_city, is_search_name, is_search_number,  is_search_phone_number, is_search_postal_code, is_search_street, is_search_surname
 */

void searching(list_pointers list, int(*search_option)(char[30]))
{
	printf("Please provide text by which your going to search: \n");
	char text[30];
	scanf_s("%s", text, 30);
	list_pointers result;
	result = list_init();
	result = search_results(list, search_option, text);
	print_list_head(result);
	free_list(result);
	printf("push eneter to return\n");
	getchar();
	getchar();



}




/**
 * @brief funkcja generująca interfejs wyboru elementów do przeszukania
 *
 * funkcja ta na początku wyświetla opcje wyboru od 0 do 7 i pobiera od użytkownika wartość wyboru
 * w zależności od wyboru funkcja później przechodzi do do funkcji searching z odpowiednio wybrana funkcja "is_searching_******"
 *
 *
 * @param list - struktura list_pointers określająca listę która użytkownik przeszukuje
 */

void search_phone_book(list_pointers list)
{
	int choice;
	do
	{
		system("cls");
		printf("Depending on what parameter, would you like to search: \n\n");
			printf("7- name\n6- surname\n5- phone number\n4- city \n3- street\n2- postal code\n1- house number\n0-fisnish searching phone book\n\n ");
		scanf_s("%d", &choice, 1);
		switch (choice)
		{
		case 0:  break;
		case 1: searching(list, is_search_number); break;
		case 2: searching(list, is_search_postal_code); break;
		case 3: searching(list, is_search_street); break;
		case 4: searching(list, is_search_city); break;
		case 5: searching(list, is_search_phone_number); break;
		case 6: searching(list, is_search_surname); break;
		case 7: searching(list, is_search_name); break;
		default: printf("\n ERROR: provided wrong value\n\n"); break;
		}


	} while (choice != 0);


	}


/**
 * @brief funkcja generuje interfejs umożliwiający sortowanie listy
 *
 * funckja na początku wyświetla użytkownika opcje wyboru według którego elementu chce użytkownik posortować listę
 * w zależności od wyboru użytkownika uruchamia się funkcja merge_sort ze wskaźnikiem na na funkcje "****_cmp"
 * na koniec zwraca posortowana listę do głównego programu
 *
 * @param list -  struktura list_pointers okreslajaca listę która użytkownik che posortować
 * @return list_pointers -  struktura list_pointers określająca posortowaną listę w zależności od wyboru użytkownika
 */

/**
 * @brief funkcja generuje interfejs umożliwiający sortowanie listy
 *
 * funckja na początku wyświetla użytkownika opcje wyboru według którego elementu chce użytkownik posortować listę
 * w zależności od wyboru użytkownika uruchamia się funkcja merge_sort ze wskaźnikiem na na funkcje "****_cmp"
 * na koniec zwraca posortowana listę do głównego programu
 *
 * @param list -  struktura list_pointers okreslajaca listę która użytkownik che posortować
 * @param order - wskaźnik na zmienna order określajaća w jakim kierunku ma się wyświetlać lista
 * @return list_pointers -  struktura list_pointers określająca posortowaną listę w zależności od wyboru użytkownika
 */
list_pointers sort_phone_book(list_pointers list, int *order)
{
	int choice;
	do
	{
		system("cls");
		if (*order)
			print_list_tail(list);
		else
			print_list_head(list);
		printf("Depending on what parameter, would you like to sort: \n\n");
		printf("7- id\n6- full name\n5- phone number\n4- city \n3- street\n2- postal code\n1- house number\n0-fisnish soting phone book\n\n ");
		scanf_s("%d", &choice, 1);
		if (choice != 0)
		{
			printf("In what order would you like to sort: \n\n");
			printf("1- descending \n0-Ascending\n\n ");
			scanf_s("%d", order, 1);
		}

		switch (choice)
		{
		case 0:  break;
		case 1: list=merge_sort(list,number_cmp); break;
		case 2: list = merge_sort(list, postal_code_cmp); break;
		case 3: list = merge_sort(list, street_cmp); break;
		case 4: list = merge_sort(list, city_cmp); break;
		case 5: list = merge_sort(list, phone_cmp); break;
		case 6: list = merge_sort(list, name_cmp); break;
		case 7: list = merge_sort(list, id_cmp); break;
		default: printf("\n ERROR: provided wrong value\n\n"); break;
		}


	} while (choice != 0);
	return list;

}



/**
 * @brief funkcja generująca interfejs umożliwiający usunięcie wybranego przez użytkownika elementu
 *
 * na samym początku funkcja prosi użytkownika o podanie id elementu który chce usunąć
 * następnie przeszukuje listę w poszukiwaniu elementu o tym id a następnie go usuwa
 *
 * @param list  struktura list_pointers określająca listę z której użytkownika ma usunąć element
 * @param order - zmienna order określajaća w jakim kierunku ma się wyświetlać lista
 * @return list_pointers -  struktura list_pointers określająca listę z usuniętymi przez użytkownika elementami
 */

list_pointers delete_element(list_pointers list, int order)
{
	int choice;
	int id;
	do
	{
		system("cls");
		
		if (order)
			print_list_tail(list);
		else
			print_list_head(list);

		printf("what is the id of an element  you'd like to remove: \n\n");
		scanf_s("%d", &id, 1);
		list_node* element_to_del = find_node(list, id);
		getchar();
		list=list_remove_node(list, element_to_del);
		printf("\n\n would you like to delete another element: \n 1- yes \n 0- no \n\n");
		scanf_s("%d", &choice, 1);
		if (choice == 0)
			break;
		if (choice == 1)
			continue;
		printf("\n ERROR: provided wrong value\n\n");
	} while (1);
	
	getchar();
	return list;
}



/**
 * @brief funkcja generująca interfejs umożliwiający zapisanie listy do pliku
 *
 * na początku funkcja pytanie sie użytkownika o podanie ciągu znaków określającego nazwę pliku pod jaką ma być zapisany
 * a następnie zapisuje ta liste pod tą nazwę z użyciem funkcji save()
 *
 * @param list  struktura list_pointers określająca listę z którą użytkownik chce zapisać
 */

void save_phone_book(list_pointers list)
{
	char file_name[30];
	int choice;
	do
	{
		system("cls");
		printf("how would you like to name your phone_book: \n\n");
		scanf_s("%s", file_name, 30);
		save(list, file_name);
		printf("\n\n would you like to save  another copy of your phone book: \n 1- yes \n 0- no \n\n");
		scanf_s("%d", &choice, 1);
		if (choice == 0)
			break;
		if (choice == 1)
			continue;
		printf("\n ERROR: provided wrong value\n\n");
	} while (1);

}


/**
 * @brief funkcja generuje interfejs umożliwiająca edycja konkretnego elementu wpisu w książce telefonicznej
 *
 * najpierw funkcja prosi użytkownika o wybór który element tego wpisu chcę zmienić następnie podaje ciąg znaków który ma nadpisać
 * aktualny stan elementu a następnie nadpisuje ten element w zależności od wyboru
 *
 *
 * @param element_to_edit - wskaźnik na element który ma być poddany edycji
 */

void edit_element(list_node* element_to_edit)
{
	system("cls");
	print_contact(element_to_edit->data);
	printf("\n");

		int choice;
	do {
		printf("what element would you like to edit: \n\n");
		printf("7- edit name\n6- edit surname\n5- edit street name\n4- house number\n3- edit postal code\n2- edit city\n1- edit phone number\n0-fisnish editing this contact\n\n ");
		scanf_s("%d", &choice, 1);
		if (choice == 0)
			break;
		printf("\n please provide new value:\n");
		char new[30];
			scanf_s("%s", new, 30);

		switch (choice)
		{
		case 0:  break;
		case 1: strncpy_s(element_to_edit->data.phone_number,11,new,11); break;
		case 2: strncpy_s(element_to_edit->data.adress.city, 30, new, 30); break;
		case 3: strncpy_s(element_to_edit->data.adress.postal_code, 11, new, 11); break;
		case 4: element_to_edit->data.adress.number=atoi(new); break;
		case 5: strncpy_s(element_to_edit->data.adress.street, 30, new, 30); break;
		case 6: strncpy_s(element_to_edit->data.surname, 30, new, 30); break;
		case 7: strncpy_s(element_to_edit->data.name, 30, new, 30); break;
		default: printf("\n ERROR: provided wrong value\n\n"); break;
		}


	} while (choice != 0);



}

/**
 * @brief funkcja generująca interfejs wyboru elementu do edycji
 *
 * na początku funkcja prosi użytkownika o podanie id elementu który ma być poddany edycji
 * następnie przeszukuje listę w jego poszukiwaniu, jeżeli nie nie ma elementu o takim id funkcja wyświetla że nie znaleziono takiego
 * element, po znaleziono elementu funkcja aktywuje funkcję edit_element na wybranym elemencie listy. po zakończeniu funkcja zwraca\
 * zedytowana listę
 *
 * @param list  struktura list_pointers określająca listę z którą użytkownik chce zapisać
 * @return list_pointers  struktura list_pointers określają listę z edytowanymi elementami
 */

list_pointers edit_phone_list(list_pointers list)
{
	int choice;
	int id;
	do
	{
		system("cls");
		printf("what is the id of an element  you'd like to edit: \n\n");
		scanf_s("%d", &id, 1);
		list_node* element_to_edit = find_node(list, id);
		if (element_to_edit == NULL)
		{
			printf("there is no eelemt with that id\n");
			continue;

		}



		edit_element(element_to_edit);



		printf("\n\n would you like to eddit another element: \n 1- yes \n 0- no \n\n");
		scanf_s("%d", &choice, 1);
		if (choice == 0)
			break;
		if (choice == 1)
			continue;
		printf("\n ERROR: provided wrong value\n\n");
	} while (1);

	return list;
}

/**
 * @brief funkcja generująca interfejs umożliwiający wybranie operacji na książce telefonicznej
 *
 * funkcja wyświetla użytkownikowi wybór i w zależności od wyboru funkcja może przejść do funkcji interfejsu: save_phone_book, search_phone_book
 * sort_phone_book, edit_phone_list, delete_element, add_new_element.
 * po zakończeniu pracy lista funkcja zwalnia pamięć zajmowana przez listę
 *
 * @param list - struktura list_pointers określająca listę która użytkownik ma poddać edycji
 */

void phone_book_manage(list_pointers list)
{
	int choice;
	int order = 0;
	do {
		system("cls");

		if(order)
		print_list_tail(list);
		else
			print_list_head(list);

		printf("what would you like to do with your phone list: \n\n");
		printf("6- add new element\n5- delete element\n4- edit element\n3- sort phone book \n2- search for element\n1- save phone book\n0-fisnish working with this phone book\n\n ");
		scanf_s("%d", &choice, 1);
		switch (choice)
		{
			case 0:  break;
			case 1 :  save_phone_book(list); break;
			case 2 : search_phone_book(list); break;
			case 3 : list= sort_phone_book(list, &order); break;
			case 4 : list = edit_phone_list(list); break;
			case 5 : list = delete_element(list,order); break;
			case 6 : list=add_new_element(list); break;
		default: printf("\n ERROR: provided wrong value\n\n"); break;
		}


	} while (choice != 0);

	free_list(list);
}



/**
 * @brief funkcja odpowiada za tworzenie nowej listy
 * funkcja torzy nowa psuta listę a następnie prosi użytkownika o podanie elementu z pomocą funkcji add_new_element
 * az użytkownik nie zdecyduje że chce przestać, po zakończeniu w wpisywania przechodzi z ta lista do interfejsu zarządzania
 * phone_book_manage()
 *
 */

void create_new_phone_book()
{
	int i = 0;
	int choice;
	list_pointers list = list_init();
	do{
		printf("please provide your contact details: \n\n");
		list = add_new_element(list);
	printf("\n\n would you like to add another element: \n 1- yes \n 0- no \n\n");
	scanf_s("%d", &choice, 1);
	if (choice == 0)
		break;
	if (choice == 1)
		continue;
	printf("\n ERROR: provided wrong value\n\n");
	} while (1);



	phone_book_manage(list);

}



/**
 * @brief funkcja odpowiada za segment menu odpowiedzialny za otwarcie książki z pliku
 *
 * funkcja wyświetla uztkonkowi listę książek dostępnych w dedykowanym folderze
 * a następnie pozwala użytkownikowi numer pliku który chce otworzyć'
 * następnie na podstawie wybranego numeru ładuje plik do nowej listy i przechodzi z ta lista do interfejsu zarządzania
 * phone_book_manage()
 */

void opening_book()
{
	int choice;
	if (!phone_book_list())
		return;
	printf("\n\n please choose number of phone you would like to open: \n");
	scanf_s("%d", &choice, 1);
	char file_name[30] = "";
	if (!get_file_name(file_name, choice))
	{
		printf("there is phone book with that number");
		return NULL;
	}
	printf("%s", file_name);
	list_pointers list;
	list = load(file_name);
	phone_book_manage(list);

}


/**
 * @brief funkcja rozpoczyna konsolowy interfejs użytkownika
 *
 * funkcja daje użytkownikowi wybór liczby od 0-2, 0 pozwala na wyjście z programu, 1 przechodzi do funkcji odpowiedzialnej za tworzenie nowej listy
 * a 2 odpowiada za otwarcie książki z pliku
 *
 */

void start_ui()
{
	int choice=0;
	do{
		system("cls");
		printf("\nwhat would you like to do: \n\n2- open phone_book \n1- create_new\n0- close software:\n\n ");
		scanf_s("%d", &choice, 1);
		switch (choice)
		{
		case 0:  break;
		case 1: create_new_phone_book(); break;
		case 2: opening_book(); break;
		default: printf("Wrong value provided"); break;
		}

		
	} while (choice != 0);
	printf("\n\n\nThank you for using software, see you again next time\n\n\n");
	return;
}
