//tynmczasowe funkcje wykorzystywane do sprawdzeniea poprawnoœæi dzia³ania programu


#include "phone_book.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


//funckcje generuj¹ca losowy kontakt z okreœlengo wczeœniej zakresu w zale¿nosæi od podanego ziarna losowania

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
	case 1: strncpy_s(contact.surname, 30, "Wójcik", 30); break;
	case 2: strncpy_s(contact.surname, 30, "Kowalczyk", 30); break;
	case 3: strncpy_s(contact.surname, 30, "WoŸniak", 30); break;
	case 4: strncpy_s(contact.surname, 30, "Mazur", 30); break;
	case 5: strncpy_s(contact.surname, 30, "Krawczyk", 30); break;
	case 6: strncpy_s(contact.surname, 30, "Kaczmarek", 30); break;
	case 7: strncpy_s(contact.surname, 30, "Stêpieñ", 30); break;
	case 8: strncpy_s(contact.surname, 30, "Wróbel", 30); break;
	case 9: strncpy_s(contact.surname, 30, "Baran", 30); break;
	case 10: strncpy_s(contact.surname, 30, "Sikora", 30); break;
	case 11: strncpy_s(contact.surname, 30, "B¹k", 30); break;
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
	case 1: strncpy_s(contact.adress.street, 30, "Leœna", 30); break;
	case 2: strncpy_s(contact.adress.street, 30, "S³oneczna", 30); break;
	case 3: strncpy_s(contact.adress.street, 30, "Krótka", 30); break;
	case 4: strncpy_s(contact.adress.street, 30, "Szkolna", 30); break;
	case 5: strncpy_s(contact.adress.street, 30, "Ogrodowa", 30); break;
	case 6: strncpy_s(contact.adress.street, 30, "Lipowa", 30); break;
	case 7: strncpy_s(contact.adress.street, 30, "Brzozowa", 30); break;
	case 8: strncpy_s(contact.adress.street, 30, "£¹kowa", 30); break;
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
	case 1: strncpy_s(contact.adress.city, 30, "Kraków", 30); break;
	case 2: strncpy_s(contact.adress.city, 30, "£ódŸ", 30); break;
	case 3: strncpy_s(contact.adress.city, 30, "Wroc³aw", 30); break;
	case 4: strncpy_s(contact.adress.city, 30, "Poznañ", 30); break;
	case 5: strncpy_s(contact.adress.city, 30, "Gdañsk", 30); break;
	case 6: strncpy_s(contact.adress.city, 30, "Szczecin", 30); break;
	case 7: strncpy_s(contact.adress.city, 30, "Bydgoszcz", 30); break;
	case 8: strncpy_s(contact.adress.city, 30, "Bia³ystok", 30); break;
	case 9: strncpy_s(contact.adress.city, 30, "Katowice", 30); break;
	case 10: strncpy_s(contact.adress.city, 30, "Czêstochowa", 30); break;
	case 11: strncpy_s(contact.adress.city, 30, "Radom", 30); break;
	case 12: strncpy_s(contact.adress.city, 30, "Toruñ", 30); break;
	}
	return contact;
}


//funkjca generujaca i wyœwietlajaca 200 losowych konkató wylosowanych funkcj¹ generate_rand_contact

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


//funkcja testuj¹ca dzia³anie funkcji soryj¹cej liste na losowo wygenerowanej liœæie

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