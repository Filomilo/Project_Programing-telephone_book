//funkcje odopwiadajace za wyszukiwanie w liscie
/**
 * @file search_fuctions.c
 * @author
* @brief funkcję odpowiedzialne za przeszukiwanie elementów książki telefonicznej
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
  * @brief funkcja zamienia wszystkie duże litery w podanym ciągu znaków na małe litery.
  *
  * funckja dla podanego ciagu znaków int wchodzi w pętle przechodząca przez każdy znak w danym ciągu.
  * Dla każdego znaku w pętli wywołuje funkcje tolower() z biblioteki ctype.h która zamienia duża litere na jej mały odpowiednik
  *
  * @param string - 30 elemnotwy ciąg znaków który ma zostać zamieniony na małe litery
  */

void string_to_low(char string[30])
{
	for (int i=0; i< strlen(string); i++)
	{
		string[i] = tolower(string[i]);

	}

}


/**
 * @brief funkcja sprawdza czy imię danego wpisu w książce telefonicznej spełnia warunek wyszukiwania
 *
 * funkcja zamienia najpierw zarówno imię jak i warunek wyszukiwania na małe litery za pomocą funkcji string_to_low
 * następnie porównuje oba ciągi za pomocą funkcji strcmp i jeżeli ciągi są takie same zwraca wartość 1 a jeżeli nie to 0
 * @param string - 30 elemnotwy ciąg znaków który określa wyszukiwany element
 * @param node - wpis w książce telefonicznej który jest sprawdzany z tekstem string
 * @return int - liczba zwracana przez funkcje określająca czy dany element spełnia warunek wyszukiwania
 * 0- jeżeli nie spełnia warunku
 * 1- jeżeli spełnia warunek
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
 * @brief funkcja sprawdza czy nazwisko danego wpisu w książce telefonicznej spełnia warunek wyszukiwania
 *
 * funkcja zamienia najpierw zarówno nazwisko jak i warunek wyszukiwania na małe litery za pomocą funkcji string_to_low
 * następnie porównuje oba ciągi za pomocą funkcji strcmp i jeżeli ciągi są takie same zwraca wartość 1 a jeżeli nie to 0
 * @param string - 30 elemnotwy ciąg znaków który określa wyszukiwany element
 * @param node - wpis w książce telefonicznej który jest sprawdzany z tekstem string
 * @return int - liczba zwracana przez funkcje określająca czy dany element spełnia warunek wyszukiwania
 * 0- jeżeli nie spełnia warunku
 * 1- jeżeli spełnia warunek
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
 * @brief funkcja sprawdza czy numer telefonu danego wpisu w książce telefonicznej spełnia warunek wyszukiwania
 *
 *
 * funkcja porównuje parametr wyszukiwania oraz numer telefonu za pomocą funkcji strcmp() i jeżeli ciągi są takie same zwraca wartość 1 a jeżeli nie to 0
 * @param string - 30 elemnotwy ciąg znaków który określa wyszukiwany element
 * @param name - wpis w książce telefonicznej który jest sprawdzany z tekstem string
 * @return int - liczba zwracana przez funkcje określająca czy dany element spełnia warunek wyszukiwania
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
 * @brief funkcja sprawdza czy miasto w adresie zamieszkania danego wpisu w książce telefonicznej spełnia warunek wyszukiwania
 *
 * funkcja zamienia najpierw zarówno miasto jak i warunek wyszukiwania na małe litery za pomocą funkcji string_to_low
 * następnie porównuje oba ciągi za pomocą funkcji strcmp i jeżeli ciągi są takie same zwraca wartość 1 a jeżeli nie to 0
 * @param string - 30 elemnotwy ciąg znaków który określa wyszukiwany element
 * @param node - wpis w książce telefonicznej który jest sprawdzany z tekstem string
 * @return int - liczba zwracana przez funkcje określająca czy dany element spełnia warunek wyszukiwania
 * 0- jeżeli nie spełnia warunku
 * 1- jeżeli spełnia warunek
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
 * @brief funkcja sprawdza czy ulica w adresie zamieszkania danego wpisu w książce telefonicznej spełnia warunek wyszukiwania
 *
 * funkcja zamienia najpierw zarówno ulica  jak i warunek wyszukiwania na małe litery za pomocą funkcji string_to_low
 * następnie porównuje oba ciągi za pomocą funkcji strncmp i jeżeli ciągi są takie same zwraca wartość 1 a jeżeli nie to 0
 * @param string - 30 elemnotwy ciąg znaków który określa wyszukiwany element
 * @param node - wpis w książce telefonicznej który jest sprawdzany z tekstem string
 * @return int - liczba zwracana przez funkcje określająca czy dany element spełnia warunek wyszukiwania
 * 0- jeżeli nie spełnia warunku
 * 1- jeżeli spełnia warunek
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
 * @brief funkcja sprawdza czy kod pocztowy danego wpisu w książce telefonicznej spełnia warunek wyszukiwania
 *
 *
 * funkcja porównuje parametr wyszukiwania oraz kod pocztowym za pomocą funkcji strncmp() i jeżeli ciągi są takie same zwraca wartość 1 a jeżeli nie to 0
 * @param string - 30 elemnotwy ciąg znaków który określa wyszukiwany element
 * @param node - wpis w książce telefonicznej który jest sprawdzany z tekstem string
 * @return int - liczba zwracana przez funkcje określająca czy dany element spełnia warunek wyszukiwania
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
 * @brief funkcja sprawdza czy numer domu spełnia warunek wyszukiwania
 *
 *
 * funkcja najpierw zamienia ciąg znaków podany jako warunek wyszukiwania na wartość int z pomocą funkcji atoi()
 * a następnie porównuje tą wartość z wartością numeru adresu w danym wpisie i zwraca 0 jeżeli nie są równe i 1 kiedy są równe
 * @param string - 30 elemnotwy ciąg znaków który określa wyszukiwany element
 * @param node - wpis w książce telefonicznej który jest sprawdzany z tekstem string
 * @return int - liczba zwracana przez funkcje określająca czy dany element spełnia warunek wyszukiwania
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
 * @brief funkcja wyszukuje elementy w podanej tablicy według podanego tekstu i kategorii wyszukiwanego elementu.
 * następnie zwraca listę wypełniona wyszukiwanymi elementami
 *
 * funkcja na samym początku tworzy nową listę do której będą zapisywane wyniki wyszukiwania następnie dla każdego elementu listy oryginalnej wywołuje wskaźnik na funkcję
 * w zależności od tego która kategorie danych się wyszukuje,  funkcja sprawdzająca zwraca wartość 1 wtedy, dany element jest dodawany do nowej listy z wynikami wyszukiwania,
 * po stworzeniu listy z wynikami wyszukiwania jest ona wyświetlona na ekranie a także i zwrócona jako wynik funkcji
 *
 * @param list - list_pointers określająca listę która ma zostać przeszukana
 * @param is_selected - wskaźnik na funkcje sprawdzająca czy dany element spełnia warunki wyszukiwania można podać:
 * is_search_city, is_search_name, is_search_number, is_search_phone_number, is_search_postal_code,  is_search_street, is_search_surname
 * @param text - 30 elementowy ciąg znaków określajacy wyszukiwany element
 * @return list_pointers - struktura list pointers określający listę z elementami spełniającymi podane warunki
 */


list_pointers search_results(list_pointers list, int(*is_selected)(char[30], contact_type), char text[30])
{
	list_pointers new_list = list_init();


	if (list.head == NULL)
	{
		
		return new_list;
	}
	while (list.tail != NULL)
	{
		
		if(is_selected(text,list.tail->data))
			new_list=list_add_head(new_list,list.tail->data);


		list.tail = list.tail->next;


	}
	
	printf("\n");

		//print_list_tail(new_list);


		return new_list;
}
