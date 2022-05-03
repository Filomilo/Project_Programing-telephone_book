/**
 * @file phone_book.h
 * @author Tomasz Bogdan, Maciej Cedzyński, Filip Borowiec
 * @brief plik nagłowkowy bibliteki łączacej wszystkie pliki programu
 * @version 0.1
 * @date 2022-03-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
 
 
#ifndef PHONE_BOOK
#define PHONE_BOOK

//struktura adresu wykorzystywana w strukturze wpisu w ksiazce telefoniczej

/**
 * @brief struktura zawierająca dane o adresie danej osoby
 * 
 */
struct adress_struct
{
	/**
	 * @brief 30 elementowy ciąg znaków przeznaczony do zapisania nazwy ulicy zamieszkania
	 * 
	 */
	char street[30];
	/**
	 * @brief wartosć liczbowa służąca określeniu mumeru domu lub budynku danej osoby
	 * 
	 */
	short int number;
	/**
	 * @brief 8 elementowy ciąg znaków służący do przechowywania kodu pocztowego danej osoby w książce
	 * 
	 */
	char postal_code[8];
	/**
	 * @brief 30 elementowy ciąg znaków służacy do przechowywania nazwy miasta zamieszkania danej osoby
	 * 
	 */
	char city[30];
}; 
/**
 * @brief typ struktury adresu utworzony aby skrócić nazwe typu do krótszej przystępniejszej formy
 * 
 */
typedef struct adress_struct adress_type;


//struktura pojedynczego wpisu w ksiazce telefoniczej
/**
 * @brief struktura pojedynczego wpisus w książce telefoniczej
 * 
 */
struct contact_struct
{
	/**
	 * @brief wartość liczbowa int bez znaku określająca id danego kontaktu w ksiażce telefonicznej
	 * 
	 */
	unsigned int id;


	/**
	 * @brief 30 elementowy ciąg znaków pozwalajacy na zapisanie imienia danego kontaktu w książce telefonicznej
	 * 
	 */
	char name[30];


	/**
	 * @brief 30 elementowy ciąg znaków pozwalajacy na zapisanie nazwiska danego kontaktu w książce telefonicznej
	 * 
	 */
	char surname[30];


	/**
	 * @brief typ danych struktury adresu gdzie maja byc zapisywane wszelkie dane odnośnie adresu zamieszkania 
	 * 
	 */
	adress_type adress;


	/**
	 * @brief 11 elementowy ciąg znaków przeznaczony do zapisania numeru telefonu danego wpisu w książce telefonicznej
	 * 
	 */
	char phone_number[11];

};

/**
 * @brief typ danych struktury wpisu w kontakcie aby ułatwić poźniejsze odnoszenie sie do tego typu
 * 
 */
typedef struct contact_struct contact_type;


//typ danych struktry pojedynczego elementu list, zawiera dane oraz oznaczenie poprzedniego i kolejnego elementu


/**
 * @brief typ struktury opisujący pojedynczy element listy dynamicznej ksiązki telefonicznej
 * 
 */
struct list_node_struct
{
	/**
	 * @brief dane zapisane w pojedynczym elemencie listy, dane są jednym wpisem w książce o typie contact_type
	 * 
	 */
	contact_type data;

	/**
	 * @brief wskaźnik na następny element w liście dynamicznej
	 * 
	 */
	struct list_node_struct* next;

	/**
	 * @brief wksaźnik na poprzedni element listy dynamicznej
	 * 
	 */
	struct list_node_struct* prev;
};

/**
 * @brief typ danych struktury pojedynczego elementu listy dynamicznej utworzony w celu późniejszego łatwiejszego przywoływania tego typu w kodzie
 * 
 */
typedef struct list_node_struct list_node;


// typ danych struktury list_pointers do oznaczenia listy dynamicznej
/**
 * @brief struktura wykorzystana jako określenie listy dynamicznej
 * 
 */
struct list_pointers_strucrt
{
	/**
	 * @brief wskaźnik na początkowy element listy dynamicznej
	 * 
	 */
	list_node* head;

	/**
	 * @brief wskaźnik na końcowy element listy dynamicznej
	 * 
	 */
	list_node* tail;

};

/**
 * @brief typ danych struktualny dla opisu listy dynamicznej w celu późnijeszego ułatwienia odniesienia się w dalszej części programu
 * 
 */
typedef struct list_pointers_strucrt list_pointers;


//funkcje znajdujace sie w pliku phone_book_list.c do obslugi listy dynamicznej

extern list_pointers list_init();
extern list_pointers list_add_head(list_pointers list, contact_type data);
extern list_pointers list_add_tail(list_pointers list, contact_type data);
extern list_node* find_node(list_pointers list, int searched_value);
extern list_pointers list_remove_tail(list_pointers list);
extern list_pointers list_remove_head(list_pointers list);
extern list_pointers list_remove_node(list_pointers list, list_node* node_to_remove);
void list_edit_node(list_node* node_to_edit, contact_type data);
void print_list_head(list_pointers list);
void print_list_tail(list_pointers list);
extern list_node* find_middle_node(list_pointers list);
extern list_pointers merge_sort(list_pointers list, int (*cmp)(contact_type, contact_type));
extern list_pointers free_list(list_pointers list);


//funkcje znajdujace sie w pliku phone_book.c do obslugi ksiazki telefonicznej

extern void print_contact(contact_type contact);



//funkcje porownujace ze soba dwa elementy listy w zależności od parametru opisanego w nazwie funkcji znajdującej sie w pliku list_cmp.c
// zwracającej -1 gdy a<b, 0 gdy a=b, 1 gdy a>b 1

extern int id_cmp(list_node* a, list_node* b);
extern int name_cmp(list_node* a, list_node* b);
extern int phone_cmp(list_node* a, list_node* b);
extern int city_cmp(list_node* a, list_node* b);
extern int street_cmp(list_node* a, list_node* b);
extern int postal_code_cmp(list_node* a, list_node* b);
extern number_cmp(list_node* a, list_node* b);




// funkcje wyszukujace

extern list_pointers search_results(list_pointers list, int(*is_selected)(char[30], int));
extern int is_search_name(char string[30], contact_type node);
extern int is_search_surname(char string[30], contact_type node);
extern int is_search_phone_number(char string[30], contact_type node);
extern int is_search_city(char string[30], contact_type node);
extern int is_search_street(char string[30], contact_type node);
extern int is_search_postal_code(char string[30], contact_type node);
extern int is_search_number(char string[30], contact_type node);



//interfejs 
extern void start_ui();
extern list_pointers add_new_element(list_pointers list);





//tymczasowe funkcje znajdujące sie w pliku temporary_functions.c używane do testowania poprawnosci działania programu

extern void genrating_contacts_test();
extern void list_test_sort();
void list_contact_test_search();
extern contact_type generate_rand_contact(int seed);
extern void list_file_test();
extern void open_file_test();
extern void list_id_test();


extern int generate_id(list_pointers list);



extern void save(list_pointers list, char file_name[30]);
extern list_pointers load(char file_name[30]);
extern int phone_book_list();
extern void opening_book();
extern get_file_name(char file_name[60], int choice);
#endif 
