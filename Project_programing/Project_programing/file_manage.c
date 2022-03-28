/**
 * @file file_manage.c
 * @author Tomasz Bogdan, Maciej Cedzyński, Filip Borowiec
 * @brief plik ten zawiera funkcje odpowiedzialne za zarządzanie plikami książki telefonicznej
 * @version 0.1
 * @date 2022-03-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "phone_book.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dirent.h"
#include <filesystem>

 /**
  * @brief funkcje te generuje listę plików dostępnych w folderze przeznaczonym na zapis książek telefonicznych
  *
  * na samy na początku funkcja wyświetla your phone books:
  * następnie z pomocą biblioteki dirent.h otwiera lokalizacje przeznaczona na zapisywanie książek telefonicznych
  * następnie również z pomocą biblioteki dirent.h wypisuje listę nazw plików bez rozszerzenia wraz przypisaniem
  * do nich wartości numerycznej umożliwiających późniejszy wybór książki do wybrania
  *
  * @return int funkcja zwraca wartość 0 jeżeli nie masz żadnych dostępnych książek telefonicznych
  * i 1- jeśli masz dostępne książki telefoniczne
  */

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

/**
 * @brief funkcja zapisuje listę dynamiczną do pliku o podanej nazwie
 *
 * na samym początku funkcja sprawdza czy istnieje folder przeznaczony na zapisywanie książek telefonicznych
 * jeżeli nie tworzy taki folder
 * następnie tworzy ciąg znaków określający lokalizacja nazwę i rozszerzenie pliku do zapisania
 * następnie wchodzi w pętlę która przechodzi przez wszystkie elementy listy i zapisuje je do pliku binarnego
 * o podanej nazwie i rozszerzeniu .pbd
 *
 * @param list - struktura list_pointer określająca listę do zapisania
 * @param file_name - 30 elementowy ciąg znaków określający nazwę pod którą ma zostać zapisana lista
 */

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

}


/**
 * @brief funkcja wczytuje listę z pliku o podanej nazwie
 *
 * na samym początku funkcja towrzy nowa liste nastepenie generuje lokalizację nazwę i rozszerzenie pliku o  podanej nazwie
 * następnie otwiera ten plik o podanej nazwie
 * i wczytuje elementy listy element po elemencie i dodaje je do nowo utworzonej listy aż do osiągnięcia końca pliku
 * po wczytaniu wszystkich elementów może zostać zwrócona lista wypełniona
 *
 *
 * @param file_name - 30 elementowy ciąg znaków określający nazwę pliku do odtworzenia
 * @return list_pointers - struktura list_pointers określająca wczytana z pliku
 */

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


/**
 * @brief funkcja pozwala na zdobycie nazwy pliku w zależności od wybranego numeru pliku
 *
 * funkcja bierze wartosc int określająca numer pliku przypisany według schematu co w funkcji phone book list
 * a następnie wydobywa nazwę tego pliku i zwraca go do tablicy znaków podanych jako pierwszy argument funkcji
 *
 * @param file_name - tablica znaków do której zostanie zapisana wybrana nazwa pliku
 * @param choice - wartość liczbowa wybranego pliku przypisanej na tej samej zasadzie co w funkcji phone_book_list
 * @return int zwraca 0 gdy funkcja wykona się poprawnie
 */

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