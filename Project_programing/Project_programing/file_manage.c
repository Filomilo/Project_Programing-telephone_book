#include "phone_book.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dirent.h"
#include <filesystem>


int phone_book_list()
{
	printf("your phone books:\n\n");
	DIR* dirct;
	dirct = opendir("\phone_data");
	struct dirent* dir;
	dir = readdir(dirct);
	dir = readdir(dirct);
	if (!(dir = readdir(dirct)))
	{
		printf("there are no phonebooks saved\n");
		return 0;
	}
	int i = 0;
	char* tok;
	do
	{
		tok = strtok_s(dir->d_name, ".", &tok);
		printf("%d: %s\n", i++,tok);
	} while (dir = readdir(dirct));
	
	return 1;
}


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



int get_file_name(char file_name[30], int choice)
{
	DIR* dirct;
	dirct = opendir("\phone_data");
	struct dirent* dir;
	dir = readdir(dirct);
	dir = readdir(dirct);
	dir = readdir(dirct);
	int i = 0;
	char* tok;
	do
	{
		tok = strtok_s(dir->d_name, ".", &tok);
		
		if (i == choice)
		{
			strncpy_s(file_name, 30, tok, 30);
			return 1;
		}
		i++;
	} while (dir = readdir(dirct));

	return 0;
}