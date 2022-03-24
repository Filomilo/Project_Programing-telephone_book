/**
 * @file user_interface.c
 * @author your name (you@domain.com)
 * @brief plik zawiera funkcje odpowidzeialne konsolowy interfejs użytkownika 
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
 * @brief funckja odpwodzialna za pisywanie danych do dowanie nowego elmntu do listy o podanych przez użytkowniak danych
 *
 * funkjca towrzy nowy elemnt contact_type a nastepnei po kolei prosi uzytkowniak o podanie
 * imeinai i nazwiska, nazyw ulicy, numeru domu/budynku, kodu pocztowego, nazwy miasta, numer telefonu
 * nastepnei elemnt_conatact_type zostaje dodany do listy z uzyciem funckji list_add_head
 * 
 * @param list - struktura list_pointers okreslajaca lsite do ktorej uztykownik ma dopisac elemnt
 * @return list_pointers - zwraca struktura lsit_pointers z dodanym elemntem przez uzytkownika
 */
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
	 
	//contact_type contact = generate_rand_contact(time(0));
	contact.id = generate_id(list);
	list = list_add_head(list, contact);


	return list;
}



/**
 * @brief funckja odpowada za interferjsc pozwalajcay pszeszukac liste
 * 
 * funckja wpiew w poroszi uzytkownika o podanie ciagu znakow wedlug ktorej ma zostac pszeszukana lsita
 * a nastepnie tworzy lsite resultatow z uzyciem tego caigu znakow oraz funkcji podanej jako arugmnt funkji okreslajaca
 * wedlug ktoergo elemntu jest pszeszukwiane 
 *
 * @param list - struktura list_pointers okreslajaca lsite która uzytkonik pszesuzkuje
 * @param search_option - wskaxnik na funkcje okresljaca wedlug ktoego elemtu kontaktu bedzie pszeszukiwanr mozna wybrac: 
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
 * @brief funkcja genuruajca intrefjs wyboru elemtów do pszeszukania
 * 
 * funkcja ta na poacztku wysiwtala opcje wyboru od 0 do 7 i pobiera od uztykowniak wartsoc wyboru 
 * w zaleznoci od wyboru funkjca poźniej przechodzi do do funkcji searching z odpwdnio wybrana fucnkje "is_searching_******"
 *
 * 
 * @param list - struktura list_pointers okreslajaca lsite która uzytkonik pszesuzkuje
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
 * @brief funckja genruje interefjs umozliwajacy posortowanie listy
 *
 * funckja na poczatku wysiwrtla uztkoniwi opcje wybriu wedlug ktorego elemtu chce uzytkonik posrotwac liste
 * w zaleznosci od wyboru uzytkniak urchamia sie funckja merge_sort ze wskaźnikiem na na funckje "****_cmp" 
 * na koniec zwraa posrotwana lsite do głownego programu
 * 
 * @param list -  struktura list_pointers okreslajaca lsite która uzytkonik che posrotwac
 * @return list_pointers -  struktura list_pointers okreslajaca posortownaa lsite w zaleznosci od wyboru uzytkownika
 */
list_pointers sort_phone_book(list_pointers list)
{
	int choice;
	do
	{
		system("cls");
		print_list_tail(list);
		printf("Depending on what parameter, would you like to sort: \n\n");
		printf("7- id\n6- full name\n5- phone number\n4- city \n3- street\n2- postal code\n1- house number\n0-fisnish searching phone book\n\n ");
		scanf_s("%d", &choice, 1);
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
 * @brief funckja genrujaca interjs umozliwiajacy usuniecie wybranego przez uztykonika elemntu
 * 
 * na samym poczatku funckja prosi uztkowinka o podanie id elemtu ktory chce usunac
 * nastepnei pszeszukuje liste w poszukiwaniu elemnutu o tym id a nastepnei go usuwa
 * 
 * @param list  struktura list_pointers okreslajaca lsite z ktorej uztkonika ma usunac elemnt
 * @return list_pointers -  struktura list_pointers okreslajaca lsite z usunietymi przez uztykonika elemntami
 */
list_pointers delete_element(list_pointers list)
{
	int choice;
	int id;
	do
	{
		system("cls");
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
 * @brief funkcja genrujaca interefjs umozliwajacy zapisanie lsity do pliku
 * 
 * na poczatku funkcja pytanie sie uzytkownika o podanue caigu znakow okreslajacego nzawe pliku pod jaka ma byc zapsiany 
 * a na stepnie zapisuje ta lsite pod ta nazwe z uzyciem funckji save()
 * 
 * @param list  struktura list_pointers okreslajaca lsite z ktora uzytkownik chce zapisac 
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
 * @brief funkcja genruje interefjs umozliwajaca edcyje konkretnego elemntu wpisu w ksiazce telefonczije
 * 
 * najpiewr funkcja prosi uzytkonika o wybor który elemnt tego wpisu chce zmeinc nastepnei podaje ciag znakow ktory ma nadpisac
 * aktualny stan elemntu a nastpenie nadpsiuje ten elemnt w zaleznosci od wyboru
 * 
 * 
 * @param element_to_edit - wskaznik na elemnt kotry ma byc poddany edycji
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
 * @brief funkckja generujaa interfejs wyboru elemntu do edycji
 * 
 * na poczatku funkcja prosi uzytkowniak o podaniue id elemntu kotry ma byc poddany edycji
 * nastepnie pszeszukuje lsite w jego poszukiwaniu, jezeli nie nie ma elemntu o takim id fucnkja wysiwetal że nie znaleziono takiego 
 * elemnut, po znalezionu elemntu funkcja aktywuje funckje edit_element na wybranym elemencie listy. po zakonczeniu funckja zwraca\
 * zedytowana lsite 
 * 
 * @param list  struktura list_pointers okreslajaca lsite z ktora uzytkownik chce zapisac 
 * @return list_pointers  struktura list_pointers okreslajaa lsite z zedytowanymi elementami
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
 * @brief funkcja genrujaca interfejs umozliwajacy wybraniae opracji na ksiazce telefonicznej
 * 
 * funckja wyswietal uzytkonikowi wybor i w zalenzosci od wyboru funckja moze pszejsc do funkcji intefejsu: save_phone_book, search_phone_book
 * sort_phone_book, edit_phone_list, delete_element, add_new_element.
 * po zakonczeniu pracy lista funkcja zwalnia pamiec zajmowana przez liste
 * 
 * @param list - struktura list_pointers okreslajaca lsite ktora uzytnik ma poddac edycji
 */
void phone_book_manage(list_pointers list)
{
	int choice;
	do {
		system("cls");
		print_list_tail(list);
		printf("what would you like to do with your phone list: \n\n");
		printf("6- add new element\n5- delete element\n4- edit element\n3- sort phone book \n2- search for element\n1- save phone book\n0-fisnish working with this phone book\n\n ");
		scanf_s("%d", &choice, 1);
		switch (choice)
		{
			case 0:  break;
			case 1 :  save_phone_book(list); break;
			case 2 : search_phone_book(list); break;
			case 3 : list= sort_phone_book(list); break;
			case 4 : list = edit_phone_list(list); break;
			case 5 : list = delete_element(list); break;
			case 6 : list=add_new_element(list); break;
		default: printf("\n ERROR: provided wrong value\n\n"); break;
		}


	} while (choice != 0);

	free_list(list);
}



/**
 * @brief funckja odpowiada za tworzenie nwoej listy
 * funckja torzy nowa psuta liste a na stepnie prosi uzytkonia o podaniaeanie elmntu z pomoca funkji add_new_element
 * az uzytkonik nie zdecyduje ze chce przestac, po zakonczeniu w wpisywnia przecchodzi z ta lista do interefjsu zarzadzania 
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
 * @brief funckja odpowiada za segment menu odpowiadzilany za otawcie ksiazki z pliku
 * 
 * funckja wyswirtla uztkonkowi liste ksiazek dostepnych w dedykowanym folderze 
 * a nastepnie pozwala uztykowniowi numer pliku ktory chce otworzyc'
 * nastpenie na podstawie wybranego numeru ładuje plik do nowej listy i przecchodzi z ta lista do interefjsu zarzadzania 
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
 * @brief funckja rozpoczyna konsolowy interefejsc użykownika
 * 
 * funckja daje uztkonikw wybór liczby od 0-2, 0 pozwala na wyjscie z programu, 1 przechodzi do funkcji odpowadizlnej za towrzenie nowej listy
 * a 2 odpowiada za otwracie ksiażki z pliku
 * 
 */
void start_ui()
{
	int choice=0;
	do{
		system("cls");
		printf("\nwhat would you like to do: \n\n 2- open phone_book \n1- create_new\n0- close software:\n\n ");
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
