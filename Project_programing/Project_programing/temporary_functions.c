/**
 * @file temporary_functions.c
 * @author your name (you@domain.com)
 * @brief zbiór funkcji tymczasowych wykorzystywancyh do poprawngo działania programu
 * @version 0.1
 * @date 2022-03-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */


//tynmczasowe funkcje wykorzystywane do sprawdzeniea poprawno��i dzia�ania programu


#include "phone_book.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


//funckcje generuj�ca losowy kontakt z okre�lengo wcze�niej zakresu w zale�nos�i od podanego ziarna losowania

/**
 * @brief funkjca genruje loswy wpis konaktu na podstawie podanego ziarna losowaia
 * 
 * @param seed - wartość ziarana na podstwie którego będzie generwoany kontakt 
 * @return contact_type - zwraca losowow wygenrerowany kontakt
 */
contact_type generate_rand_contact(int seed)
{
	srand(time(0));
	contact_type contact;
	contact.id = rand() % 20000;
	switch (rand()%13)
	{
	case 0: strncpy_s(contact.name, 30, "Julia",30); break;
	case 1: strncpy_s(contact.name, 30, "Zuzanna", 30); break;
	case 2: strncpy_s(contact.name, 30, "Zofia", 30); break;
	case 3: strncpy_s(contact.name, 30, "Hanna", 30); break;
	case 4: strncpy_s(contact.name, 30, "Maja", 30); break;
	case 5: strncpy_s(contact.name, 30, "Lena", 30); break;
	case 6: strncpy_s(contact.name, 30, "Antoni", 30); break;
	case 7: strncpy_s(contact.name, 30, "Jan", 30); break;
	case 8: strncpy_s(contact.name, 30, "Jakub", 30); break;
	case 9: strncpy_s(contact.name, 30, "Aleksander", 30); break;
	case 10: strncpy_s(contact.name, 30, "Franciszek", 30); break;
	case 11: strncpy_s(contact.name, 30, "Szymon", 30); break;
	case 12: strncpy_s(contact.name, 30,"Alicja", 30); break;
	}
	switch (rand() % 13)
	{
	case 0: strncpy_s(contact.surname, 30, "Nowak", 30); break;
	case 1: strncpy_s(contact.surname, 30, "W�jcik", 30); break;
	case 2: strncpy_s(contact.surname, 30, "Kowalczyk", 30); break;
	case 3: strncpy_s(contact.surname, 30, "Wo�niak", 30); break;
	case 4: strncpy_s(contact.surname, 30, "Mazur", 30); break;
	case 5: strncpy_s(contact.surname, 30, "Krawczyk", 30); break;
	case 6: strncpy_s(contact.surname, 30, "Kaczmarek", 30); break;
	case 7: strncpy_s(contact.surname, 30, "St�pie�", 30); break;
	case 8: strncpy_s(contact.surname, 30, "Wr�bel", 30); break;
	case 9: strncpy_s(contact.surname, 30, "Baran", 30); break;
	case 10: strncpy_s(contact.surname, 30, "Sikora", 30); break;
	case 11: strncpy_s(contact.surname, 30, "B�k", 30); break;
	case 12: strncpy_s(contact.surname, 30, "Lis", 30); break;
	}

	for (int i = 0; i < 9; i++)
	{
		contact.phone_number[i] = (char)(rand()%10 + 48);
	}
	contact.phone_number[9] = '\0';
	switch (rand() % 13)
	{
	case 0: strncpy_s(contact.adress.street, 30, "Polna", 30); break;
	case 1: strncpy_s(contact.adress.street, 30, "Le�na", 30); break;
	case 2: strncpy_s(contact.adress.street, 30, "S�oneczna", 30); break;
	case 3: strncpy_s(contact.adress.street, 30, "Kr�tka", 30); break;
	case 4: strncpy_s(contact.adress.street, 30, "Szkolna", 30); break;
	case 5: strncpy_s(contact.adress.street, 30, "Ogrodowa", 30); break;
	case 6: strncpy_s(contact.adress.street, 30, "Lipowa", 30); break;
	case 7: strncpy_s(contact.adress.street, 30, "Brzozowa", 30); break;
	case 8: strncpy_s(contact.adress.street, 30, "��kowa", 30); break;
	case 9: strncpy_s(contact.adress.street, 30, "Kwiatowa", 30); break;
	case 10: strncpy_s(contact.adress.street, 30, "Maczka", 30); break;
	case 11: strncpy_s(contact.adress.street, 30, "Marmurowa", 30); break;
	case 12: strncpy_s(contact.adress.street, 30, "Nowa", 30); break;
	}
	contact.adress.number = rand() % 100 + 1;
	

	char part[5];
	sprintf_s(part, 3, "%d", rand() % 90 + 10);
	strncpy_s(contact.adress.postal_code, 8, part, 8);
	strncat_s(contact.adress.postal_code,8 , "-",2);
	sprintf_s(part, 4, "%d", rand() % 900 + 100);
	strncat_s(contact.adress.postal_code, 8, part, 4);

	
	switch (rand() % 13)
	{
	case 0: strncpy_s(contact.adress.city, 30, "Warszawa", 30); break;
	case 1: strncpy_s(contact.adress.city, 30, "Krak�w", 30); break;
	case 2: strncpy_s(contact.adress.city, 30, "��d�", 30); break;
	case 3: strncpy_s(contact.adress.city, 30, "Wroc�aw", 30); break;
	case 4: strncpy_s(contact.adress.city, 30, "Pozna�", 30); break;
	case 5: strncpy_s(contact.adress.city, 30, "Gda�sk", 30); break;
	case 6: strncpy_s(contact.adress.city, 30, "Szczecin", 30); break;
	case 7: strncpy_s(contact.adress.city, 30, "Bydgoszcz", 30); break;
	case 8: strncpy_s(contact.adress.city, 30, "Bia�ystok", 30); break;
	case 9: strncpy_s(contact.adress.city, 30, "Katowice", 30); break;
	case 10: strncpy_s(contact.adress.city, 30, "Cz�stochowa", 30); break;
	case 11: strncpy_s(contact.adress.city, 30, "Radom", 30); break;
	case 12: strncpy_s(contact.adress.city, 30, "Toru�", 30); break;
	}
	return contact;
}


//funkjca generujaca i wy�wietlajaca 200 losowych konkat� wylosowanych funkcj� generate_rand_contact
/**
 * @brief funkcja testująca funckje generowanie losowego kontkatu
 *
 * funkcje genruje i wypisuje 200 przykładowo losowo wygenerowanych kontaktków
 * 
 */
void genrating_contacts_test()
{
	srand((int)time(0));
	contact_type contact;
	for (int i = 0; i < 200; i++)
	{
		contact = generate_rand_contact(rand());
		print_contact(contact);

	}



}


//funkcja testuj�ca dzia�anie funkcji soryj�cej liste na losowo wygenerowanej li��ie
/**
 * @brief funckcja pozwala na przetesotwanie funkcji sortujących
 *
 * funkcka ta najpierw pozwala wygenerowac liste kontaktów a następnie sortuję tą liste według wartości id i ja wypisuje
 * 
 */
void list_contact_test_sort()
{
	srand(time(0));
	printf("\n\n\n\n\n thisi s the test of sorting list data structure: \n\n");
	
	getchar();
	
	list_pointers list = list_init();
	for (int i = 0; i < 20; i++)
	{
		list = add_new_element(list);

	}
	print_list_tail(list);
	getchar();
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n sorted by id: \n\n\n\n");
	list = merge_sort(list, id_cmp);
	print_list_tail(list);
	getchar();


}


/**
 * @brief funkcja pozwala na przetestowanie funkcji pszeszukiwania listy
 *
 * funkcja na poczatku towrzy 1000 elemtową losową lsite kontaktów następnie wykonuje operacje sortowania na tej liście wedlug parametrów podanych bezpośrednio w kodzie
 * 
 */
void list_contact_test_search()
{
	srand(time(0));
	printf("\n\n\n\n\n thisi s the test of sorting list data structure: \n\n");

	getchar();

	list_pointers list = list_init();
	for (int i = 0; i < 1000; i++)
	{
		list = list_add_head(list, generate_rand_contact(rand()));

	}
	print_list_tail(list);
	printf("\n\n\n\n\n\n");
	list=search_results(list, is_search_street, "l");



}



/**
 * @brief funckja pozwala na przetestowanie funkcji odczyytu i zapisu list do pliku
 * 
 * funkcja na początek pozwala stworzyć liste złożona z 10 elemntów a na steonie ja wypisuje
 * po czym zapiuje utworzona liste do pliku o nazwie "test" i ponownie załaduwje tą liste z pliku i wypisuje ją na akrenie
 */
void list_file_test()
{
	srand(time(0));
	printf("\n\n\n\n\n thisi s the test of sorting list data structure: \n\n");

	getchar();

	list_pointers list = list_init();
	for (int i = 0; i < 10; i++)
	{
		list = add_new_element(list);

	}
	print_list_tail(list);
	save(list, "test");
	list=free_list(list);
	print_list_tail(list);
	getchar();
	list = load("test");
	print_list_tail(list);
}


/**
 * @brief funkcja ta pozwala na prztestowanie generowania unikatowego id
 * 
 * funkjca na początek genruje 10 elemntową lsite a następnie usuwa z listy elemnty o id 3,1,5,7,8 
 * nastepnie do akiej talbicy dodaje koljen 10 elemntó i przy każym doadniu wyświetla stan listy aby możńa było zaobserować czy genwrowane id jest unikatowe
 */
void list_id_test()
{
	srand(time(0));
	printf("\n\n\n\n\n thisi s the test of sorting list data structure: \n\n");

	getchar();

	list_pointers list = list_init();
	for (int i = 0; i < 10; i++)
	{
		printf("\n\n");
		list = add_new_element(list);
		printf("list:\n");
		print_list_tail(list);

		getchar();
	}
	print_list_tail(list);
	printf("\n\n");
	getchar();
	list = list_remove_node(list, find_node(list,3));
	list = list_remove_node(list, find_node(list, 1));
	list = list_remove_node(list, find_node(list, 5));
	list = list_remove_node(list, find_node(list, 7));
	list = list_remove_node(list, find_node(list, 8));
	print_list_tail(list);
	getchar();


	for (int i = 0; i < 10; i++)
	{
		printf("\n\n");
		list = add_new_element(list);
		printf("list:\n");
		print_list_tail(list);
	
		getchar();
	}

}
