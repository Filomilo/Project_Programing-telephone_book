/**
 * @file phone_book_list.c
 * @author Tomasz Bogdan, Maciej Cedzyński, Filip Borowiec
* @brief plik zawierające funkcje umożliwiające tworzenie i zarządzanie lista dynamiczną * @version 0.1
 * @date 2022-03-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "phone_book.h"
#include <stdio.h>
#include <stdlib.h>


 /**
  * @brief funkcja incjująca pusta liste dynamiczną
  *
  * funkcja ta tworzy listę dynamiczną w formie typu list pointers i następnie ustawia wszystkie jej elemnty na NULL jako oznaczenie żę jest pusta
  * a następnie przekazuje ja do zwrotu
  * @return list_pointers - zwraca typ lsit_pointers który jest określeniem pustej listy dynamicznej
  */

list_pointers list_init()
{
	list_pointers list;
	list.head = NULL;
	list.tail = NULL;
	return list;
}



/**
 * @brief funkcja dodaje do listy element od strony głowy
 *
 * na samym początku funkcja umieszcza w pamięci nowy element listy dynamicznej w przypadku jeśli się nie uda wyświetla komunikat "ERROR: Stack overflow"
 * następnie przypisuje do danych tego elementu dane podane jako argument wywołania funkcji, w kolejnym kroku wartość poprzedniego elementu dla nowo utworzonego
 * jest element head a następnym NULL czyli koniec listy. Następnie jeśli aktualny head nie jest psuty to ustawia wartość jego następnego elementu na ten utworzony
 * kolejno jeśli tail listy dynamicznej jest pusty zostaje on również ustawiony na nowy element.
 * na sam koniec ustawia wartość head na nowy element, tak zmieniona struktura zostaje zwrócona do programu
 *
 * @param list - struktura list_pointers określająca listę do której użytkownik chce dodać element
 * @param data - struktura contactt_type który ma zostać dodany do listy dynamicznej
 * @return list_pointers - zwraca zmieniona struktura lsit_pointers określająca listę z już dodanym elementem
 */

list_pointers list_add_head(list_pointers list, contact_type data)
{
	list_node* new_node = (list_node*)malloc(sizeof(list_node));
	if (new_node == NULL)
	{

		printf("ERROR: Stack oberflow");
		return list;

	}

	new_node->next = NULL;
	new_node->prev = list.head;
	new_node->data = data;
	if (list.head != NULL)
	{
		list.head->next = new_node;
	}

	if (list.tail == NULL)
		list.tail = new_node;

	list.head = new_node;



		return list;
}




/**
 * @brief funkcja dodaje do listy element od storny ogona
 *
 * na samym początku funkcja umieszcza w pamięci nowy element listy dynamicznej w przypadku jeśli się nie uda wyświetla komunikat "ERROR: Stack overflow"
 * następnie przypisuje do danych tego elementu dane podane jako argument wywołania funkcji, w kolejnym kroku wartość kolejnego elementu dla nowo utworzonego
 * jest element tail a poprzednim NULL czyli koniec listy. Następnie jeśli aktualny tail nie jest psuty to ustawia wartość jego poprzedniego lematu na ten utworzony
 * kolejno jeśli head listy dynamicznej jest pusty zostaje on również ustawiony na nowy element.
 * na sam koniec ustawia wartość tail na nowy element, tak zmieniona struktura zostaje zwrócona do programu
 *
 * @param list - struktura list_pointers określająca listę do której użytkownik chce dodać element
 * @param data - struktura contactt_type który ma zostać dodany do listy dynamicznej
 * @return list pointers - zwraca zmieniona struktura lsit_pointers określająca listę z już dodanym elementem
 */

list_pointers list_add_tail(list_pointers list, contact_type data)
{
	list_node* new_node = (list_node*)malloc(sizeof(list_node));
	if (new_node == NULL)
	{

		printf("ERROR: Stack oberflow");
		return list;

	}

	new_node->next = list.tail;
	new_node->prev = NULL;
	new_node->data = data;
	if (list.head == NULL)
	{
		list.head = new_node;
	}

	if (list.tail != NULL)
		list.tail->prev = new_node;

	list.tail = new_node;



	return list;
}




/**
 * @brief funkcja znajduje element o podanym id
 *
 * funkcja ta przechodzi przez kolejne elementy listy dynamicznej tak długo aż nie osiągnie lub nie znajdzie elementu o id równym podanego w searched_value
 * jeśli znajdzie takowy element to zwraca wskaźnik na ten właśnie element a jeżeli zwraca pusty wskaźnik
 *
 * @param list - struktura list_pointers na listę dynamiczną której element należy znaleźć
 * @param searched value - wartość int określająca id elementu który ma zostać odnaleziony
 * @return list_node* - zwraca wskaźnik na znaleziony element listy dynamicznej lub jeżeli taki nie został odnaleziony w pusty wskaźnik
 */

list_node* find_node(list_pointers list, int searched_value)
{
	while (list.tail != NULL || list.head == NULL)
	{
		if (list.tail->data.id == searched_value)
			return list.tail;
		list.tail = list.tail->next;

	}
	printf("no value found\n");
	return NULL;
}






/**
 * @brief funkcja usuwa końcowy element (tail) z listy dynamicznej
 *
 * na samym początku funkcja sprawdza czy lista nie jest już pusta jeżeli jest to wyświetla "ERROR: Nothing to remove\n"
 * następnie pyszpiuje tymczasowemu wskaźnikowi następny element od zaczynając od tail, następnie usuwa tail za pomocą funkcji free()
 * następnei jezeli tymczasowy elemnt jest równy nULL to oznacza żę lista jest pusta i zwraca listę z list_init()
 * jeżeli nie to ustawia  poprzedni element tymczasowego element jako NULL czyli koniec listy a potem ustawia tail listy jako właśnie ten tymczasowy element.
 * tak zmieniona lista zostaje zwrócona do programu
 *
 * @param list - struktura list_pointers określająca listę dynamiczną z której ma usunąć ogon
 * @return list_pointers - zwraca strukturę list_pointers opisująca listę z już usuniętymi ogonem
 */

list_pointers list_remove_tail(list_pointers list)
{
	if (list.tail == NULL)
	{

		printf("ERROR: Nothing to remove\n");
		return list;

	}
	list_node* tmp;
	tmp = list.tail->next;
	free(list.tail);
	if (tmp == NULL)
	{
		list = list_init();
		return list;
	}
	tmp->prev = NULL;
	list.tail = tmp;

	return list;
}



/**
 * @brief funkcja usuwa początkowy element (head) z listy dynamicznej
 *
 * na samym początku funkcja sprawdza czy lista nie jest już pusta jeżeli jest to wyświetla "ERROR: Nothing to remove\n"
 * następnie pyszpiuje tymczasowemu wskaźnikowi poprzedni element od zaczynając od head, następnie usuwa head za pomocą funkcji free()
 * następnei jezeli tymczasowy elemnt jest równy nULL to oznacza żę lista jest pusta i zwraca listę z list_init()
 * jeżeli nie to ustawia  następny element tymczasowy element jako NULL czyli koniec listy a potem ustawia head listy jako właśnie ten tymczasowy element.
 * tak zmieniona lista zostaje zwrócona do programu
 *
 * @param list - struktura list_pointers określająca listę dynamiczną z której ma usunąć head
 * @return list_pointers - zwraca strukturę list_pointers opisująca listę z już usuniętymi head
 */

list_pointers list_remove_head(list_pointers list)
{
	if (list.tail == NULL || list.head == NULL)
	{

		printf("ERROR: Nothing to remove\n");
		return list;

	}
	if (list.head->prev == NULL)
	{
		free(list.head);
		list.head = NULL;
		list.tail = NULL;
		return list;
	}

	list_node* tmp;
	
	tmp = list.head->prev;
	tmp->next = NULL;
	free(list.head);
	list.head = tmp;

	return list;
}



/**
 * @brief funkcja usuwa wybrany element z listy dynamicznej
 *
 * funckja na samym początku sprawdza czy wartość elementu do usunięcia jest różna od NULL jeśli nie to wypisuje "ERROR: no node to remove selected\n".
 * Następnie  jeżeli element do usunięcia jest równy elementowi head to wywołuje funkcje list_remove_head a jeżli jest równe tail funkcje list_remove_tail.
 * jeżeli nie jest równy żadnego z tych elementów to ustawia wartości następnego elementu poprzedniego elementu listy na następny element list ,
 *  z kolei wartość poprzedniego elementu kolejnego elementu listy jest ustawiana na poprzedni element listy, po czym usuwa się wybrany element za pomocą funkcji free()
 *  następnie zmieniona listę zwraca się do głównego programu
 *
 * @param list - struktura list_pointers określająca listę dynamiczną z której ma usunąć element
 * @param node_to_remove - wskaźnik na element który ma zostać usunięty, wskaźnik taki można uzyskać np poprzez funkcje find_node()
 * @return list_pointers  - zwraca strukturę list_pointers opisująca listę z już usuniętymi elementem
 */

list_pointers list_remove_node(list_pointers list, list_node* node_to_remove)
{
	if (node_to_remove == NULL)
	{
		printf("ERROR: no node to remove selected\n");
		return list;
	}
	else
	if (node_to_remove==list.tail)
	{
		list = list_remove_tail(list);
		return list;
	}
	else
	if (node_to_remove == list.head)
	{

		list = list_remove_head(list);
		getchar();
		return list;
	}
	else {
		node_to_remove->prev->next = node_to_remove->next;
		node_to_remove->next->prev = node_to_remove->prev;
		free(node_to_remove);
		return list;
	}


}




/**
 * @brief funkcja podmienia wartośc wybranego elementu na wartość podaną w argumencie
 *
 * funkcja ta najpierw sprawdza czy wybrany element do podmiany nie jest psuty jeżeli jest pusty to wyświetla "ERROR: no node to edit selected"
 * jeżeli nie jest pusty podmienia wartość jego data na wartość podana w agumencies
 *
 * @param node_to_edit - wskaźnik na element którego dane ma funkcja podmienić, może zostać uzyskany np poprzez funkcje findnode()
 * @param data - struktura contact_type który zawiera dane na które ma zostać podmieniony podany element
 */

void list_edit_node(list_node* node_to_edit, contact_type data)
{
	if (node_to_edit == NULL)
	{
		printf("ERROR: no node to edit selected\n");
		return ;
	}
	node_to_edit->data = data;

}




/**
 * @brief funkcja wyświetla wszystkie elementy listy dynamicznej od strony głowy
 *
 * funkcja ta najpierw sprawdza czy lista nie jest pusta, jeżeli jest jest to wyświetla komunikat "your list is empty"
 * jezeli nie jest pusta to dla danych każdego elementu listu od głowy zaczynając na ogonie kończąc wykonuje funkcje print_contact()
 * który wyświetla na dane elementu listy w odpowiednim formacie
 *
 * @param list - funkcja przyjmuje list_pointers określającą listę do wyświetlenia
 */

void print_list_head(list_pointers list)
{
	if (list.head == NULL)
	{
		printf("your list is empty\n");
		return;
	}
	while (list.head != list.tail)
	{
		print_contact( list.head->data);
		list.head = list.head->prev;


	}
	print_contact(list.head->data);
	printf("\n");
}



/**
 * @brief funkcja wyświetla wszystkie elementy listy dynamicznej od strony głowy
 *
 * funkcja ta najpierw sprawdza czy lista nie jest pusta, jeżeli jest jest to wyświetla komunikat "your list is empty"
 * jezeli nie jest pusta to dla danych każdego elementu listu od głowy zaczynając na ogonie kończąc wykonuje funkcje print_contact()
 * który wyświetla na dane elementu listy w odpowiednim formacie
 *
 * @param list - funkcja przyjmuje list_pointers określającą listę do wyświetlenia
 */

void print_list_tail(list_pointers list)
{
	if (list.head == NULL)
	{
		printf("your list is empty\n");
		return;
	}
	while (list.tail != list.head)
	{
		print_contact(list.tail ->data);
		list.tail = list.tail->next;


	}
	print_contact(list.tail->data);
	printf("\n");
}




/**
 * @brief funkcja ta znajduje i zwraca środkowy element listy
 *
 * funkcja ta najpierw sprawdza czy lista nie jest pusta, jeżeli jest jest to wyświetla komunikat "your list is empty".
 * następnie jeżeli lista jednoelementowa to zwraca ten jeden element.
 * następnie jeżeli nie jest jednoelementowa to tworzy dwa wskaźniki first i sec oba przyjmujące wartość tail
 * następnie do czasu aż wskaźnik sec nie osiągnie końca listy to wskaźnik first przemiesza się z każdą iteracja o jeden elemnt listy
 * do przodu natomiast sec o dwa elementy do przodu
 * po zakończeniu listy wartość first jest wskaźnikiem na na środkowy element listy i taki też idzie do zwrotu
 *
 * @param list - funkcja przyjmuje list_pointers określającą listę której środkowy element ma zostać znaleziony
 * @return list_node* - funkcja zwraca wskaźnik na środkowy element listy
 */

list_node* find_middle_node(list_pointers list)
{
	if (list.head==NULL )
	{
		printf("ERROR: list is empty");
		return NULL;
	}
	if (list.head == list.tail)
	{
		return list.head;
	}
	list_node* first = list.tail;
	list_node* sec = list.tail;
	while (sec->next != list.head && sec->next->next != list.head)
	{
		first = first->next;
		sec=sec->next->next;
	}
	return first;

}


/**
 * @brief funkcja usuwa całą listę z pamięci
 *
 * funkcja ta wykonuje operacja list_remove_head dla listy aż head i tail nie są sobie równe po osiągnięciu wychodzi z listy
 * i usuwa ostatni pozostały element listy  i zwraca pustą lite
 *
 * @param list - funkcja przyjmuje list_pointers określającą listę która chcemy usunąc
 * @return list_pointers - funkcja zwraca pustą listę
 */

list_pointers free_list(list_pointers list)
{

	while (list.head != list.tail)
		list = list_remove_head(list);
	list = list_remove_head(list);
	return list;
}



/**
 * @brief funkcja wykorzystywana przez funkcje merge_sort do scalenia dwóch posortowanych list
 *
 * funckja ta tworzy nową liste następnie przepisuje obie listy do niej w odpowniej kolejnoći po wykorzystainiu 
 * wyszystkiich elemntow z jednej listy przepisuje pozostałę elementy z pozostałej listy towrząc tym samym jedna liste z posortowanymi
 * elemntami
 *
 * @param left - list_pointers opisujące lewą część listy
 * @param right - list_pointers opisujące prawą część listy
 * @param cmp - wskaźnik na funkjcje określającą według którego elemenru ma być posortowana lista
 * @return list_pointers
 */

list_pointers merge(list_pointers left, list_pointers right, int (*cmp)(contact_type, contact_type))
{
	list_pointers list = list_init();
	
	list_node* lpointer = left.tail;
	list_node* rpointer = right.tail;
	list_node* delpointer = NULL;


	while (lpointer != left.head->next && rpointer != right.head->next)
	{
		if (cmp(lpointer->data, rpointer->data) >= 0)
		{
			list = list_add_head(list, lpointer->data);
			delpointer = lpointer;
			lpointer = lpointer->next;
		}
		else
		{
			list = list_add_head(list, rpointer->data);
			delpointer = rpointer;
			rpointer = rpointer->next;
		}
	}

	while (lpointer!= left.head->next)
	{
		list = list_add_head(list, lpointer->data);
		lpointer = lpointer->next;
	}

	while (rpointer != right.head->next)
	{
		list = list_add_head(list, rpointer->data);
		rpointer = rpointer->next;
	}

	left = free_list(left);
	right = free_list(right);

	return list;
}



/**
 * @brief funkcja sortuje listę dynamiczna według elementu podanego jako wskaźnik funkcji
 *
 * funkcja ta jest rekurencyjna którym warunkiem końcowym jest podanie listy jednoelementowej czyli head===tail
 * na sam początek funkcja znajduje środkowy element i według niego dzieli ta liste rna lewa i prawa
 * na następnie dla każdej z pozostałych również wykonuje funkcje merge sort tak dlugo az bedzie listę jedno elemento
 * w momencie kiedy masz już listę jednoelementowa zscaler je dwie za pomocą funkcji merge czyli w odpowiedniej kolejności
 * następnie scalasz tak tablice rodzica i w ten sposób zostajesz z posortowana tablica
 *
 * @param list - struktura list pointers określająca listę do posortowania
 * @param cmp - wskaźnik na funkcję porównując dwa elementy listy określające według którego elementu ma zostać posortowane
 * mozna podac: id_cmp, name_cmp, number_cmp, phone_cmp, postal_code_cmp, street_cmp
 * @return list_pointers - zwraca strukture list_pointer okreslajaca posortowana lsite
 */

list_pointers merge_sort(list_pointers list, int (*cmp)(contact_type, contact_type))
{
	if (list.head == list.tail)
		return list;
	list_node* mid = find_middle_node(list);
	list_pointers left_list;
	left_list.head = list.head;
	left_list.tail = mid->next;

	list_pointers right_list;
	right_list.head = mid;
	right_list.tail = list.tail;



	left_list = merge_sort(left_list, cmp);
	right_list = merge_sort(right_list, cmp);
	return merge(left_list,right_list, cmp);
}


