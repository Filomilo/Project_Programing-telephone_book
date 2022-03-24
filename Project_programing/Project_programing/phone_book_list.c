/**
 * @file phone_book_list.c
 * @author your name (you@domain.com)
 * @brief plik zawierajace funkjce umożliwajaće twrzenie i zarzadzanie lsita dynamiczną
 * @version 0.1
 * @date 2022-03-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "phone_book.h"
#include <stdio.h>
#include <stdlib.h>



//funkcja incjuj�c� pust� liste czyli nadaje .head i .tail wartos�i NULL,


/**
 * @brief funkcja incjująca pusta liste dynamiczną
 * 
 * funckja ta tworzy liste dynamiczną w formie typu list pointers i następnie ustawia wszystkie jej elemnty na NULL jako oznaczenie żę jest pusta
 * a nastęnie przekazuje ja do zwrotu
 * @return list_pointers - zwraca typ lsit_pointers któy jest okreśłeneim pustej listy dynamicznej
 */
list_pointers list_init()
{
	list_pointers list;
	list.head = NULL;
	list.tail = NULL;
	return list;
}



//funcja dodaj�ca elemnt na pocz�tku listy (za head),
/**
 * @brief funkja doaje do listy elemnt od storny głowy
 *	
 * na samym poczatku funkcja umieszczaw w pamieci nowy elemnt listy dynamicznej w przypadku jeśli się nie uda wyświetla komunikat "ERROR: Stack oberflow" 
 * następnie przypisuje do danych tego elemntu dane podane jaako argumet wywołanaia funkjci, w kolejnym koroku wartosć poprzedniego elemntu dla nowo utworzonego
 * jest elemnt head a następnym NULL czyli koniec listy. Następnie jeżli aktualny head nie jest psuty to ustawia wartość jego nastepnego lemntu na ten utworzony
 * kolejno jezli tail lsity dynamicznej jest pusty zostaje on również ustawiony na nowy element.
 * na sam koniec ustwaia wartość head na nowy elemnt, tak zmieniiona struktura zostaje zwrócona do programu 
 * 
 * @param list - struktura list_pointers określająca liste do któej użytkownik che dodaćelemnt
 * @param data - struktura contactt_type który ma zostać dodany do lsity dynamicznej
 * @return list_pointers - zwraca zmieniona struktura lsit_pointers określajaca liste z już dodanym elemntem
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



//funcja dodaj�ca elemnt na ko�cu listy(przed tail)
/**
 * @brief funkja doaje do listy elemnt od storny ogona
 *	
 * na samym poczatku funkcja umieszczaw w pamieci nowy elemnt listy dynamicznej w przypadku jeśli się nie uda wyświetla komunikat "ERROR: Stack oberflow" 
 * następnie przypisuje do danych tego elemntu dane podane jaako argumet wywołanaia funkjci, w kolejnym koroku wartosć kolejnego elemntu dla nowo utworzonego
 * jest elemnt tail a poprzednim NULL czyli koniec listy. Następnie jeżli aktualny tail nie jest psuty to ustawia wartość jego poprzediniego lemntu na ten utworzony
 * kolejno jezli head lsity dynamicznej jest pusty zostaje on również ustawiony na nowy element.
 * na sam koniec ustwaia wartość tail na nowy elemnt, tak zmieniiona struktura zostaje zwrócona do programu 
 * 
 * @param list - struktura list_pointers określająca liste do któej użytkownik che dodaćelemnt
 * @param data - struktura contactt_type który ma zostać dodany do lsity dynamicznej
 * @return list_pointers - zwraca zmieniona struktura lsit_pointers określajaca liste z już dodanym elemntem
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



//funkcja znajduj�ca elemnt o danym id we wprowadzonej lis�ie
/**
 * @brief funkcja znajduje elemnt o podanym id
 * 
 * funckja ta przechodzi przez kolejne elemnty listy dynamicznej tak długo aż nie osiagnie lub nie znajdzie elemntu o id równym podanego w searched_value
 * jezei znajdzie takowy elemnt to zwraca wskaźnik na ten właśnie element a jeżeli zwraca pusty wskaźnik
 * 
 * @param list - struktura list_pointers na liste dynamiczną któej elemnt należy znaleźć 
 * @param searched_value - wartość int określająca id elemntu który ma zostać odnaleziony
 * @return list_node* - zwraca wskaźńik na odnaleziony elemnt listy dynamicznej lub jeżeli taki nie został odnaleziony w pusty wskaźńk
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



//funcja usuwaj�ca ostatni elemnt listy(tail), 



/**
 * @brief funkcja usuwa końcowy elemnt (tail) z listy dynamicznje
 * 
 * na samym początku funkcja sprawdza czy lista nie jest juz pusta jezeli jest to wyswietla "ERROR: Nothing to remove\n" 
 * następnie pyszpiuje tymczasowemy wskaźnikowi następny elemnt od zaczynajac od tail, nastepnie usuwa tail za pomoca funkcji free()
 * następnei jezeli tymczasowy elemnt jest równy nULL to oznacza żę lista jest pusta i zwraca liste z list_init() 
 * jeżeli nie to ustwaia  poprzedni element tymczasowgo elemnt jako NULL czyli koniec listy a potem ustawia tail listy jako właśnie ten tymczaswowey element. 
 * tak zmieniona lista zostaje zwrócona do programu 
 * 
 * @param list - struktura list_pointers określajaca liste dynamiczną z której ma usunać ogon
 * @return list_pointers - zwraca strukture list_pointers opisujaca liste z już usuniętymi ogonem
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



//funcja usuwaj�ca pierwszy elemnt listy(head)

/**
 * @brief funkcja usuwa początkowy elemnt (head) z listy dynamicznje
 * 
 * na samym początku funkcja sprawdza czy lista nie jest juz pusta jezeli jest to wyswietla "ERROR: Nothing to remove\n" 
 * następnie pyszpiuje tymczasowemy wskaźnikowi poprzedni elemnt od zaczynajac od head, nastepnie usuwa head za pomoca funkcji free()
 * następnei jezeli tymczasowy elemnt jest równy nULL to oznacza żę lista jest pusta i zwraca liste z list_init() 
 * jeżeli nie to ustwaia  następny element tymczasowgo elemnt jako NULL czyli koniec listy a potem ustawia head listy jako właśnie ten tymczaswowey element. 
 * tak zmieniona lista zostaje zwrócona do programu 
 * 
 * @param list - struktura list_pointers określajaca liste dynamiczną z której ma usunać head
 * @return list_pointers - zwraca strukture list_pointers opisujaca liste z już usuniętymi head
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



//funkcja usuwajaca wybrany element listy
/**
 * @brief funkcja usuwa wybrany elemnt z listy dynamicznej
 * 
 * funckja na samym poczatku sprawdza czy wartośc elemntu do usunięcia jest różna od NULL jeżli nie to wypisuje "ERROR: no node to remove selected\n".
 * Następnie  jezeli elemnt do usnięcia jest równy elemntowi head to wywuuje funkcje list_remove_head a jeżli jest równe tail funkcje list_remove_tail.
 * jezeli nie jest równy żadnego z tych elemntów to ustawua wartości następnego elemntu poprzedneigo elemtu listy na nastoeny elemnt list , 
 *  z kolei wartosć porzedniego elemntu kolejengo elemntu listy jest ustawiana na poprzendi elemnt listy, po czym usuwa się wy brany eleemnt za pomoca funkjci free()
 *  nastepnie zmieniiona liste zwraca sie do głónego programu
 * 
 * @param list - struktura list_pointers określajaca liste dynamiczną z której ma usunać element
 * @param node_to_remove - wskaźnik na elemnt ktory ma zostać usuniety, wskaźńik taki mozńa uzyskać np poprzez funckje find_node()
 * @return list_pointers  - zwraca strukture list_pointers opisujaca liste z już usuniętymi elemntem
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
		printf("\nremoving tail\n");
		list = list_remove_tail(list);
		return list;
	}
	else
	if (node_to_remove == list.head)
	{
		printf("\nremoving head\n");

		list = list_remove_head(list);
		//print_list_head(list);
		print_contact(list.head->data);
		printf("\n\n finsihed test");
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



//funkcja zminiaj�ca dane wybranego na dane wprowadzone jako argumeny



/**
 * @brief funckcja podmienia wartośc wybranego elemntu na wartosć podaną w argumencie
 * 
 * funkcja ta najpierw sprwadza czy wybrany elemnt do podmiany nie jest psuty jezeli jest pusty to wysiwetla "ERROR: no node to edit selected"
 * jeżeli nie jest pusty podmienia wartosć jego data na wartosć podana w agumencies
 * 
 * @param node_to_edit - wskaźnik na elment ktorgo dane ma funkcja podmienic, może zostać uzyskany np poprez funckje find_node()
 * @param data - struktura contact_type który zawiera dane na któe ma zostać podminiony podany element
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



//funckja wy�wietlj�ca liste pocz�wszy od head id�� do tail
/**
 * @brief funckjca wsyświetla wszystkie elemnty lsity dynamicznej od strony głowy
 *
 * funkcja ta najpierw sprawdza czy lista nie jest psuta, jezeli jest jest to wyswietla komunikat "your list is empty"
 * jezeli nie jest pusta to dla danych każdego elemntu listu od głowy zaczynajac na ogonie kończąc wykonuje funkcje print_contact() 
 * który wysiwtla na dane elemntu listy w odpowiednim formacie 
 * 
 * @param list - funckja przyjmuje list_pointers określającą liste do wyświetlenia
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



//funckja wy�wietlj�ca liste pocz�wszy od tail id�c do head

/**
 * @brief funckjca wsyświetla wszystkie elemnty lsity dynamicznej od strony ogona
 *
 * funkcja ta najpierw sprawdza czy lista nie jest psuta, jezeli jest jest to wyswietla komunikat "your list is empty"
 * jezeli nie jest pusta to dla danych każdego elemntu listu od ogona zaczynajac na głowie kończąc wykonuje funkcje print_contact() 
 * który wysiwtla na dane elemntu listy w odpowiednim formacie 
 * 
 * @param list - funckja przyjmuje list_pointers określającą liste do wyświetlenia
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



//funkcja znajudj�ca �rodek listy wykorzystywana przy sortowaniu

/**
 * @brief funckcja ta znajduje i zwraca środkowy elemnt listy 
 * 
 * funkcja ta najpierw sprawdza czy lista nie jest psuta, jezeli jest jest to wyswietla komunikat "your list is empty".
 * nastepnie jezeli lista jedno elemtowa to zwraca ten jeden elemnt.
 * następnie jezeli nie jest jedno elmntowa to tworzy dwa wskażńiki first i sec oba przyjmujące wartosc tail
 * następnie do czasu aż wskaźnik sec nie osiągnie końca listy to wskaźńik first przemiesza się z każdą iteracja o jeden elemnt listy
 * do przodu natomiast sec o dwa elemnty do przodu
 * po zakończeniu listy wartosć first jest wskaźnikime na na środkowy elemnt listy i taki też i dzie do zwortu
 * 
 * @param list - funckja przyjmuje list_pointers określającą liste której środkowy elemnt ma zostać znaleziony
 * @return list_node* - funckja zwraca wskaźńik na środkowy elemnt listy
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


//funkcja usuwajaca liste z pami�ci
/**
 * @brief funckja usuwa calą lsite z pamięci
 * 
 * funckja ta wykonuje operacja list_remove_head dla lsity aż head i tail nie sa sobie równe po osiągnięciu wychodzi z listy
 * i usuwa ostani pozostaly elemnt listy  i zwraca pustą lite 
 *
 * @param list - funckja przyjmuje list_pointers określającą liste która chemy usunąc 
 * @return list_pointers - funkcja zwraca pustą liste
 */
list_pointers free_list(list_pointers list)
{

	while (list.head != list.tail)
		list = list_remove_head(list);
	list = list_remove_head(list);
	return list;
}



//funkcja �acz�ca ze sob� dwie listy sortuj�c je
/**
 * @brief funckja wykorzystwana przez funckje merge_sort do scalenia dwóch posortowanych lisr 
 * 
 * funkcja ta towrzy nową liste pustą liste dynamiczna, następnie tworzy nowe wskaźniki na lpointer i rpointer wskazujące koljno
 * na ogon lwejj lsity i ogon prawej lsity....(do dokonczenia)
 * 
 * @param left 
 * @param right 
 * @param cmp 
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



// funkcja wykorzstyj�ca spos�b merge sort do posortownaia listy
/**
 * @brief funckja sortuje liste dynamiczna według elemntu podanago jako wskaźńik funkcji
 *
 * funkcja ta jest rekurencyjna którym warunkiem koncowym jest podanie listy jedno elemnotwej czyli head===tail
 * na sam pocztek funkcja znajduje śrdodkowy elemnt i według niegod dzieli ta liste rna lewa i prawa
 * na nastepnie dla kazdej z postalych rowniez wykonuje funkcje merge sort tak dlugo az bedzie liste jedno elemnto
 * w momecnei kiedy masz juz liste jedno elemtowa zscalarz je dwie za pomoca funkcji merge czyli w odpoweinej koljenosci
 * nastepnie scalasz tak tablice rodzica i w tedn spsob zostajesz z posortowana talibca
 * 
 * @param list - struktura list pointers okreslajaca liste do posrotwoania
 * @param cmp - wskaxnik na funkcje porowujaca dwa elemnty listy okreslajace wedlug ktoreg elemntu ma zostac posortowane
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


