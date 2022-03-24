//funkcje odopwiadaj�ce za wyszukiwanie we liscie
/**
 * @file search_fuctions.c
 * @author
 * @brief funckje odpowidzialne za pszeszukiwanie elemntów ksiązki telefonicznej
 * @version 0.1
 * @date 2022-03-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "phone_book.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>






/**
 * @brief funkja zamienia wszystkie duże litery w podanym ciągu znaków na małe litery.
 *
 * funckja dla podanego ciagu znaków int wchodzi w pętle przechodząca przez każdy znak w danym ciągu. 
 * Dla każdego znaku w pętli wyowłuje funkcje tolower() z biblioteki ctype.h która zamienia duża litere na jej mały odpowiednik
 * 
 * @param string - 30 elemnotwy ciag znakow ktory ma zostac zamieniony na male litery
 */
void string_to_low(char string[30])
{
	for (int i=0; i< strlen(string); i++)
	{
		string[i] = tolower(string[i]);

	}

}


/**
 * @brief funckja sprawdza czy imie danego wpisu w książce telfoniczej spełnia warunek wyszukiwania
 * 
 * funckja zamienia najpierw zarówno imie jak i warunek wyszukiwania na male litery za pomoca funkcji string_to_low 
 * następnie porónuje oba ciągi za pomoca funkcji strncmp i jeżeli ciagi są takie same zwraca wartosć 1 a jezeli nie to 0
 * @param string - 30 elemnotwy ciag znakow ktory określający wyszukiany element
 * @param node - sprawdzany wpis w ksiąće telefoniszej który jest sprawdzany z tekstem string
 * @return int - liczba zwracana przez funkcje określająca czy dany elemnt spełnia warunek wyszukiwania
 * 0- jeżeli nie spełnia warunku
 * 1- jeżęli spełnia warunek 
 */
int is_search_name(char string[30], contact_type node)
{
	string_to_low(node.name);
	char temp[30];
	strncpy_s(temp, 30, string, 30);
	string_to_low(temp);
	if (strncmp(node.name, temp, strlen(temp)) != 0)
		return 0;
	else
		return 1;
}


/**
 * @brief funckja sprawdza czy nazwisko danego wpisu w książce telfoniczej spełnia warunek wyszukiwania
 * 
 * funckja zamienia najpierw zarówno nazwisko jak i warunek wyszukiwania na male litery za pomoca funkcji string_to_low 
 * następnie porónuje oba ciągi za pomoca funkcji strncmp i jeżeli ciagi są takie same zwraca wartosć 1 a jezeli nie to 0
 * @param string - 30 elemnotwy ciag znakow ktory określający wyszukiany element
 * @param node - sprawdzany wpis w ksiąće telefoniszej który jest sprawdzany z tekstem string
 * @return int - liczba zwracana przez funkcje określająca czy dany elemnt spełnia warunek wyszukiwania
 * 0- jeżeli nie spełnia warunku
 * 1- jeżęli spełnia warunek 
 */
int is_search_surname(char string[30], contact_type node)
{
	string_to_low(node.surname);
	char temp[30];
	strncpy_s(temp, 30, string, 30);
	string_to_low(temp);
	if (strncmp(node.surname, temp, strlen(temp)) != 0)
		return 0;
	else
		return 1;
}

/**
 * @brief funckja sprawdza czy numer telefonu danego wpisu w książce telfoniczej spełnia warunek wyszukiwania
 * 
 * 
 * funcja porónuje paraemtr wyszukiwnaia oraz numer telefonu za pomocą funkcji strncmp() i jeżeli ciagi są takie same zwraca wartosć 1 a jezeli nie to 0
 * @param string - 30 elemnotwy ciag znakow ktory określający wyszukiany element
 * @param node - sprawdzany wpis w ksiąće telefoniszej który jest sprawdzany z tekstem string
 * @return int - liczba zwracana przez funkcje określająca czy dany elemnt spełnia warunek wyszukiwania
 * 0- jeżeli nie spełnia warunku
 * 1 - jeżeli spełnia warunek
 */
int is_search_phone_number(char string[30], contact_type node)
{
	if (strncmp(node.phone_number, string, strlen(string)) != 0)
		return 0;
	else
		return 1;
}

/**
 * @brief funckja sprawdza czy miasto w adresie zamieszkania danego wpisu w książce telfoniczej spełnia warunek wyszukiwania
 * 
 * funckja zamienia najpierw zarówno miasto jak i warunek wyszukiwania na male litery za pomoca funkcji string_to_low 
 * następnie porónuje oba ciągi za pomoca funkcji strncmp i jeżeli ciagi są takie same zwraca wartosć 1 a jezeli nie to 0
 * @param string - 30 elemnotwy ciag znakow ktory określający wyszukiany element
 * @param node - sprawdzany wpis w ksiąće telefoniszej który jest sprawdzany z tekstem string
 * @return int - liczba zwracana przez funkcje określająca czy dany elemnt spełnia warunek wyszukiwania
 * 0- jeżeli nie spełnia warunku
 * 1- jeżęli spełnia warunek 
 */
int is_search_city(char string[30], contact_type node)
{
	string_to_low(node.adress.city);
	char temp[30];
	strncpy_s(temp,30, string, 30);
	string_to_low(temp);
	if (strncmp(node.adress.city, temp, strlen(temp)) != 0)
		return 0;
	else
		return 1;
}

/**
 * @brief funckja sprawdza czy ulica w adresie zamieszkania danego wpisu w książce telfoniczej spełnia warunek wyszukiwania
 * 
 * funckja zamienia najpierw zarówno ulica  jak i warunek wyszukiwania na male litery za pomoca funkcji string_to_low 
 * następnie porónuje oba ciągi za pomoca funkcji strncmp i jeżeli ciagi są takie same zwraca wartosć 1 a jezeli nie to 0
 * @param string - 30 elemnotwy ciag znakow ktory określający wyszukiany element
 * @param node - sprawdzany wpis w ksiąće telefoniszej który jest sprawdzany z tekstem string
 * @return int - liczba zwracana przez funkcje określająca czy dany elemnt spełnia warunek wyszukiwania
 * 0- jeżeli nie spełnia warunku
 * 1- jeżęli spełnia warunek 
 */
int is_search_street(char string[30], contact_type node)
{
	string_to_low(node.adress.street);
	char temp[30];
	strncpy_s(temp, 30, string, 30);
	string_to_low(temp);
	if (strncmp(node.adress.street, temp, strlen(temp)) != 0)
		return 0;
	else
		return 1;
}


/**
 * @brief funckja sprawdza czy kod pocztowy danego wpisu w książce telfoniczej spełnia warunek wyszukiwania
 * 
 * 
 * funcja porónuje paraemtr wyszukiwnaia oraz kod pocztowys za pomocą funkcji strncmp() i jeżeli ciagi są takie same zwraca wartosć 1 a jezeli nie to 0
 * @param string - 30 elemnotwy ciag znakow ktory określający wyszukiany element
 * @param node - sprawdzany wpis w ksiąće telefoniszej który jest sprawdzany z tekstem string
 * @return int - liczba zwracana przez funkcje określająca czy dany elemnt spełnia warunek wyszukiwania
 * 0- jeżeli nie spełnia warunku
 * 1 - jeżeli spełnia warunek
 */
int is_search_postal_code(char string[30], contact_type node)
{

	if (strncmp(node.adress.postal_code, string, strlen(string)) != 0)
		return 0;
	else
		return 1;
}

/**
 * @brief funckja sprawdza czy numer domu spełnia warunek wyszukiwania
 * 
 * 
 * funkcja najpierw zaminia ciąg znaków podany jako warunek wyszukiwania na wartość int z pomoćą funkcji atoi()
 * a nastęnie porónuje tą wartość z wartośćia numveru adresu w danym wpisie i zwraca 0 jeżeli nie są równe i 1 kiedy są równe
 * @param string - 30 elemnotwy ciag znakow ktory określający wyszukiany element
 * @param node - sprawdzany wpis w ksiąće telefoniszej który jest sprawdzany z tekstem string
 * @return int - liczba zwracana przez funkcje określająca czy dany elemnt spełnia warunek wyszukiwania
 * 0- jeżeli nie spełnia warunku
 * 1 - jeżeli spełnia warunek
 */
int is_search_number(char string[30], contact_type node)
{
	int number = atoi(string);
	if (node.adress.number!= number)
		return 0;
	else
		return 1;
}

/**
 * @brief funkcja wyszukuje elemnty w podanej talibcy według podanego tekstu i kategori wyszukiwanego elemntu.
 * następnie zwraca liste wypełniona wyszukiwanymi elementami
 * 
 * funckja na samym poczatku tworzy nową lsite do której benda zapiyswane wyniki wyszukiwania następnie dla każdego elemtnu listy orginalnej wywołuje wskaźnik na funckje
 * w zależnosci od tego która kateogire danych sie wszykuje,  funkja sprawdzająca zwraca wartosć 1 wtedy dany element jest dodawny do nowej listy z wynikami wyszukiwania
 * po stworzeniu listy z wynikami wyszukiami jest ona wysiwirtlona na ekranie a także i zwrócona jako wynik funkcji
 *
 * @param list - list_pointers określająca liste która ma zostać pszeszukana
 * @param is_selected - wskaźnik na funkcje sprawdzająca czy dany elemnt spełnia warunki wyszukiwania można podać: 
 * is_search_city, is_search_name, is_search_number, is_search_phone_number, is_search_postal_code,  is_search_street, is_search_surname	
 * @param text - 30 elemtowy ciąg znaków określająca wyszukiwany elemnt
 * @return list_pointers - struktura list pointers określająca liste z elementami spełniającaymi podane warunki
 */

list_pointers search_results(list_pointers list, int(*is_selected)(char[30], contact_type), char text[30])
{
	list_pointers new_list = list_init();


	if (list.head == NULL)
	{
		return new_list;
	}
	while (list.tail != list.head)
	{
		
		if(is_selected(text,list.tail->data))
			new_list=list_add_head(new_list,list.tail->data);


		list.tail = list.tail->next;


	}
	
	printf("\n");

		print_list_tail(new_list);


		return new_list;
}