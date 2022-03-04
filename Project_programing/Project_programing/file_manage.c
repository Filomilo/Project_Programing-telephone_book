#include "phone_book.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dirent.h"
#include <filesystem>

void save(list_pointers list, char file_name[30])
{

	//tworzenie folderu jesli nie instje

	DIR *dirct;
	dirct = opendir("\phone_data");
	if (dirct == NULL)
	{
		mkdir("phone_data");

	}
	closedir(dirct);



	//otwieranie pliku

	FILE* file;
	char directory[60]="phone_data\\";
	strcat_s(directory, 60, file_name);
	strcat_s(directory, 60, ".pbd");
	printf("file: \n%s", directory);
	int a =fopen_s(&file , directory, "w");
	


	if (list.head == NULL)
	{
		printf("cant save empty phone book\n");
		return;
	}
	while (list.head != list.tail)
	{
		fwrite(&list.head->data, sizeof(list.head->data),1,file);
		list.head = list.head->prev;


	}
	fwrite(&list.head->data, sizeof(list.head->data), 1, file);




	fclose(file);
	getchar();
	getchar();

}



list_pointers load(char file_name[30])
{
	list_pointers list;
	list = list_init();


	//otwieranie pliku

	FILE* file;
	char directory[60] = "phone_data\\";
	strcat_s(directory, 60, file_name);
	strcat_s(directory, 60, ".pbd");
	printf("file: \n%s", directory);
	int a = fopen_s(&file, directory, "r");


	contact_type contact;
	while (!feof(file))
	{
		fread(&contact, sizeof(contact), 1, file);
		list=list_add_tail(list, contact);
	}

	


	fclose(file);



	return	list;

}