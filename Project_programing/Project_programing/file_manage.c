/**
 * @file file_manage.c
 * @author your name (you@domain.com)
 * @brief plik ten zawiera funkcje odpowiedzilne za zarzadzenie plikami ksiazki telefonicznej
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
 * @brief funckja te generuje liste plików dostenych w folderze przeznaczonym na zapis ksiązek telefonicznych
 * 
 * na samy na poczatku funckacja wyswietal your phone books:
 * nastepnie z pomoca bibliotekei dirent.h otwiera lokalizacje przeznaczona na zapisywanie ksiązek telefonciznych
 * nastepnie rónwiez z pomoca bilbioteki dirent.h wypisuje liste nazw plikow bez roszezrzenia wraz przypiasniem
 * do nich wartosci numerecznej umozliwajacyh późniejszy wybór ksiazki do wybrania
 * 
 * @return int funckja zwraca wartosc 0 jezeli nie masz zadnych dostepnych ksiazek telfonicnzych
 * i 1- jezeli masz dostepne ksiązki telefonczne
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
 * @brief funckjaja zapisuje liste dynamiczną do pliku o podanej nazwie
 *
 * na samym poczatku funkjca sprawdza czy istnieje folder przeznaczony na zapisywanie ksiazek telefoncznych 
 * jezeli nie tworzy taki folder
 * natepnie tworzy caig znakow okreslajacy lokalziacje nazwe i rozszerzenie pliku do zapisania
 * nastpnie wchodzi w petle ktora przechodzdi przez wszystkie lemnty listy i zapisuje je do pliku binarnego 
 * o podnaej nazwie i rozszerzeniu .pbd
 * 
 * @param list - struktura list_pointer okreslajaca liste do zapisania
 * @param file_name - 30 elemntowy ciag znakwy okreslajacy nazwe pod ktora ma zostac zapisana lista
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
	getchar();

}


/**
 * @brief funkcja wczytuje liste z pliku o podanej nazwie
 *
 * na samym początku funkjcja towrzy nowa liste nastepenie genruje lokaliazacje nazwe i roserzenie pliku o  podanej naziwe
 * nastepnie otwiera ten plik o podanej nazwie
 * i wczytuje elementy listy elemnt po elemencie i dodaje je do nowo utworzonej listy az do osiagniecia konca pliku
 * po wczytaniu wszystkich elemntow moze zostac zwrocona lista wypelniona
 * 
 * 
 * @param file_name - 30 elemtowy ciag znakow okreslajacy nazwe pliku do otworzenia
 * @return list_pointers - struktura list_pointers okreslajaca wczytana z pliku
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
 * @brief funckja pozwala na zodbycie nazwy pliku w zaleznodci od wybranego numeru pliku
 * 
 * funckja bierze wartosc int okreslajaca numer pliku przypisany według schematu co w funckji phone_book_list
 * a nastepnie wydobywa nazwe tego pliku i zwrraca go do talbicy znakow podanych jako pierwszy argument funkcji
 * 
 * @param file_name - tablica znakow do ktorej zostanie zapisana wybrana nazwa pliku
 * @param choice - wartosc liczbowa wybranego pliku przypisanej na tej same zasadzie co w funkcji phone_book_list
 * @return int zwraca 0 gdy funkcja wykonala sie poprawnie
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