#include "phone_book.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


list_pointers add_new_element(list_pointers list)
{
	system("cls");
	contact_type contact;
	contact = generate_rand_contact(1);
	list = list_add_head(list, contact);


	return list;
}


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
		case 1: printf("\nsearching by house number\n"); ; break;
		case 2: printf("\nserach by postal code\n"); break;
		case 3: printf("\nsearch by street\n"); break;
		case 4: printf("\nsearch by city\n"); break;
		case 5: printf("\nsearch by phone number\n"); break;
		case 6: printf("\nsearch by surname\n"); break;
		case 7: printf("\nsearch by name\n"); break;
		default: printf("\n ERROR: provided wrong value\n\n"); break;
		}


	} while (choice != 0);


	}



list_pointers sort_phone_book(list_pointers list)
{
	int choice;
	do
	{
		system("cls");
		printf("Depending on what parameter, would you like to sort: \n\n");
		printf("8- id\n7- name\n6- surname\n5- phone number\n4- city \n3- street\n2- postal code\n1- house number\n0-fisnish searching phone book\n\n ");
		scanf_s("%d", &choice, 1);
		switch (choice)
		{
		case 0:  break;
		case 1: printf("\sort by house number\n"); ; break;
		case 2: printf("\sort by postal code\n"); break;
		case 3: printf("\sort by street\n"); break;
		case 4: printf("\sort by city\n"); break;
		case 5: printf("\nsort by phone number\n"); break;
		case 6: printf("\nsort by surname\n"); break;
		case 7: printf("\nsort by name\n"); break;
		case 8: printf("\nsort by id\n"); break;
		default: printf("\n ERROR: provided wrong value\n\n"); break;
		}


	} while (choice != 0);
	return list;

}




list_pointers delete_element(list_pointers list)
{
	int choice;
	int id;
	do
	{
		system("cls");
		printf("what is the id of an element  you'd like to remove: \n\n");
		scanf_s("%d", &id, 1);

		printf("\n\n would you like to add another element: \n 1- yes \n 0- no \n\n");
		scanf_s("%d", &choice, 1);
		if (choice == 0)
			break;
		if (choice == 1)
			continue;
		printf("\n ERROR: provided wrong value\n\n");
	} while (1);

	return list;
}


void save_phone_book(list_pointers list)
{
	char file_name[30];
	int choice;
	do
	{
		system("cls");
		printf("how would you like to name your phone_book: \n\n");
		scanf_s("%s", file_name, 30);

		printf("\n\n would you like to save  another copy of your phone book: \n 1- yes \n 0- no \n\n");
		scanf_s("%d", &choice, 1);
		if (choice == 0)
			break;
		if (choice == 1)
			continue;
		printf("\n ERROR: provided wrong value\n\n");
	} while (1);

}



list_pointers edit_element(list_pointers list)
{
	int choice;
	int id;
	do
	{
		system("cls");
		printf("what is the id of an element  you'd like to edit: \n\n");
		scanf_s("%d", &id, 1);

		printf("\n\n would you like to add another element: \n 1- yes \n 0- no \n\n");
		scanf_s("%d", &choice, 1);
		if (choice == 0)
			break;
		if (choice == 1)
			continue;
		printf("\n ERROR: provided wrong value\n\n");
	} while (1);

	return list;
}


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
			case 4 : list = edit_element(list); break;
			case 5 : list = delete_element(list); break;
			case 6 : list=add_new_element(list); break;
		default: printf("\n ERROR: provided wrong value\n\n"); break;
		}


	} while (choice != 0);

	free_list(list);
}




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

void load_phone_book()
{
	char file_name[30];
	int choice;
	list_pointers list = list_init();
	do {
		printf("what phone book would you likr to openn: \n\n");
		scanf_s("%s", file_name, 30);
		printf("\n\n would you like to open other element: \n 1- yes \n 0- no \n\n");
		scanf_s("%d", &choice, 1);
		if (choice == 0)
			break;
		if (choice == 1)
			continue;
		printf("\n ERROR: provided wrong value\n\n");
	} while (1);



	phone_book_manage(list);

}

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
		case 2: load_phone_book(); break;
		default: printf("Wrong value provided"); break;
		}

		
	} while (choice != 0);
	printf("\n\n\nThank you for using software, see you again next time\n\n\n");
	return;
}
