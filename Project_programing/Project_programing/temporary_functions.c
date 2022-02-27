//tynmczasowe funkcje wykorzystywane do sprawdzeniea poprawno��i dzia�ania programu


#include "phone_book.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


//funckcje generuj�ca losowy kontakt z okre�lengo wcze�niej zakresu w zale�nos�i od podanego ziarna losowania

contact_type generate_rand_contact(int seed)
{
	srand(seed);
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

void list_contact_test_sort()
{
	srand(time(0));
	printf("\n\n\n\n\n thisi s the test of sorting list data structure: \n\n");
	
	getchar();
	
	list_pointers list = list_init();
	for (int i = 0; i < 10; i++)
	{
		list = list_add_head(list, generate_rand_contact(rand()));

	}
	print_list_tail(list);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n sorted by id: \n\n\n\n");
	list = merge_sort(list, id_cmp);
	print_list_tail(list);
	getchar();


	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n sorted by name: \n\n\n\n");
	list = merge_sort(list, name_cmp);
	print_list_tail(list);
	getchar();
	getchar();

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n sorted by phone: \n\n\n\n");
	list = merge_sort(list, phone_cmp);
	print_list_tail(list);

	getchar();


	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n sorted by city: \n\n\n\n");
	list = merge_sort(list, city_cmp);
	print_list_tail(list);
	getchar();

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n sorted by street: \n\n\n\n");
	list = merge_sort(list, street_cmp);
	print_list_tail(list);
	getchar();

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n sorted by postal_code: \n\n\n\n");
	list = merge_sort(list, postal_code_cmp);
	print_list_tail(list);
	getchar();

}