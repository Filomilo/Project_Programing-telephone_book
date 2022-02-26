#include "phone_book.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



void list_test()
{
	printf("\n\n\n\n\n thisi s the test of list data structure: \n\n");
	list_pointers list = list_init();
	printf("\ninitiation list using: list_pointers list= list_init();\n");
	print_list_head(list);

	printf("\nadding vale of 5 to list from head side using : list=list_add_head(list, 5);\t printing list from head side using: print_list_head(list);\n");
	list = list_add_head(list, 5);
	print_list_head(list);


	printf("\nadding vale of 82 to list from head side using : list=list_add_head(list, 82);\t printing list from head side using: print_list_head(list);\n");
	list = list_add_head(list, 82);
	print_list_head(list);

	printf("\nadding vale of 22 to list from head side using :	list = list_add_head(list, 22);;\tprinting list from tail side using:print_list_tail(list);;\n");
	list = list_add_head(list, 22);
	print_list_tail(list);

	printf("\nadding vale of 123 to list from tail side using : list_add_tail(list, 123);\tprinting list from tail side using: print_list_tail(list);\n");
	list = list_add_tail(list, 123);
	print_list_tail(list);

	printf("\nremoving tail of list using : list = list_remove_tail(list);\tprinting list from tail side using: print_list_tail(list);\n");
	list = list_remove_tail(list);
	print_list_tail(list);

	printf("\nremoving tail of list using : list = list_remove_tail(list);\tprinting list from tail side using: print_list_tail(list);\n");
	list = list_remove_tail(list);
	print_list_tail(list);

	printf("\nremoving head of list using : list = list_remove_head(list);;\tprinting list from tail side using: print_list_tail(list);\n");
	list = list_remove_head(list);
	print_list_tail(list);

	printf("\nremoving head of list using : list = list_remove_head(list);;\tprinting list from tail side using: print_list_tail(list);\n");
	list = list_remove_head(list);
	print_list_tail(list);

	printf("\nremoving head of list using : list = list_remove_head(list);;\tprinting list from tail side using: print_list_tail(list);\n");
	list = list_remove_head(list);
	print_list_tail(list);

	printf("\nremoving tail of list using : list = list_remove_tail(list);\tprinting list from tail side using: print_list_tail(list);\n");
	list = list_remove_tail(list);
	print_list_tail(list);

	printf("\nadding vale of 55 to list from head side using : list=list_add_head(list, 5);\t printing list from head side using: print_list_head(list);\n");
	list = list_add_head(list, 55);
	print_list_head(list);


	printf("\nadding vale of 78 to list from head side using : list=list_add_head(list, 82);\t printing list from head side using: print_list_head(list);\n");
	list = list_add_head(list, 78);
	print_list_head(list);

	printf("\nadding vale of 4 to list from head side using :	list = list_add_head(list, 22);;\tprinting list from tail side using:print_list_tail(list);;\n");
	list = list_add_head(list, 4);
	print_list_tail(list);

	printf("\nadding vale of 33 to list from tail side using : list_add_tail(list, 123);\tprinting list from tail side using: print_list_tail(list);\n");
	list = list_add_tail(list, 33);
	print_list_tail(list);


	printf("\n removing selected node by value 55 using  list = list_remove_node(list, find_node(list,55));  \tprinting list from tail side using: print_list_tail(list);\n");
	list = list_remove_node(list, find_node(list, 55));
	print_list_tail(list);


	printf("\n removing selected node by value 4 using  list = list_remove_node(list, find_node(list,55));  \tprinting list from tail side using: print_list_tail(list);\n");
	list = list_remove_node(list, find_node(list, 4));
	print_list_tail(list);

	printf("\n removing selected node by value 58 using  list = list_remove_node(list, find_node(list,55));  \tprinting list from tail side using: print_list_tail(list);\n");
	list = list_remove_node(list, find_node(list, 58));
	print_list_tail(list);


	printf("\n ediintg selected node by value 11 to 22 using  ist_edit_node(find_node(list, 11), 22);  \tprinting list from tail side using: print_list_tail(list);\n");
	list_edit_node(find_node(list, 11), 22);
	print_list_tail(list);


	printf("\n ediintg selected node by value 33 to 456 using  ist_edit_node(find_node(list, 11), 22);  \tprinting list from tail side using: print_list_tail(list);\n");
	list_edit_node(find_node(list, 33), 456);
	print_list_tail(list);



	printf("\n\n\n\n\n\n\n");

}

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

void genrating_contacts_test()
{
	srand(time(0));
	contact_type contact;
	for (int i = 0; i < 200; i++)
	{
		contact = generate_rand_contact(rand());
		print_contact(contact);

	}



}