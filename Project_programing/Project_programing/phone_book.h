/**
 * @file phone_book.h
 * @author Tomasz Bogdan, Maciej Cedzyński, Filip Borowiec
 * @brief plik nagłowkowki bibliteki łączacej wszystkie pliki programu
 * @version 0.1
 * @date 2022-03-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
 
 
#ifndef PHONE_BOOK
#define PHONE_BOOK

//struktura adresu wykorzystywana we strukturze wpisu w ksi�zce telefoniczej

/**
 * @brief struktura zawierająća dane o adresie danej osoby
 * 
 */
struct adress_struct
{
	/**
	 * @brief 30 elemnotowy ciąg znaków przeznaczony do zapisania nazwy ulicy zamieszkania
	 * 
	 */
	char street[30];
	/**
	 * @brief wartosć liczbowa służąca określninu mueru domu lib budynku adresu danej osoby
	 * 
	 */
	short int number;
	/**
	 * @brief 8 elemntowy ciąg znaków służący do pszechowywania kodu pocztowego danej osoby w książce
	 * 
	 */
	char postal_code[8];
	/**
	 * @brief 30 elemntowy ciąg znakó służacy do pszechowywania maista zamieszkania danej osoby w książce teleofoniczej
	 * 
	 */
	char city[30];
}; 
/**
 * @brief typ struktury adresu utworzony aby skrócić nazwe typu do krótzej przystępniejszej formy
 * 
 */
typedef struct adress_struct adress_type;


//struktura pojedy�czego wpisu w ksi�zce telefoniczej
/**
 * @brief struktura pojedyńczego wpisusu w książće telefoniczej
 * 
 */
struct contact_struct
{
	/**
	 * @brief wartość liczbowa int bez znaku określająca id danego konkaktu w ksiżce telefonicznej
	 * 
	 */
	unsigned int id;


	/**
	 * @brief 30 elemtowy ciąg znaków pozwakjacy na zapisanie imienia danego kontaktu w książce telefonicznej
	 * 
	 */
	char name[30];


	/**
	 * @brief 30 elemtowy ciąg znaków pozwakjacy na zapisanie nazwiska danego kontaktu w książce telefonicznej
	 * 
	 */
	char surname[30];


	/**
	 * @brief typ danych struktury adresu gdzie maja byc zapisywane wszelkie dane odnośnie adrsu zamieskzania danego adresu
	 * 
	 */
	adress_type adress;


	/**
	 * @brief 11 elemtowy ciąg znaków przeznaczony do zapisania numeru telfonu danego wpisu w książce telefonicznej
	 * 
	 */
	char phone_number[11];

};

/**
 * @brief typ danych struktury wpisu w konakcie aby ułatwić poźnijesze odnoszenie sie do tego typu
 * 
 */
typedef struct contact_struct contact_type;


//typ danych struktry pojedy�czego elemntu list, zawiera dane oraz onaczenie poprzeniego i koljengo elemenmtu


/**
 * @brief typ struktury opisujące pojedyńczy elemnt listy dynamicznej ksiązki telefonicznej
 * 
 */
struct list_node_struct
{
	/**
	 * @brief dane zapisane w pojedyńczym elemncie listy, dane są jednym wpisem w książće o typue contact_type
	 * 
	 */
	contact_type data;

	/**
	 * @brief wskaźnik na nastęny elemnt w liście dynamicznje
	 * 
	 */
	struct list_node_struct* next;

	/**
	 * @brief wksaźnik na poprzedni elemnt listy dynamicznej
	 * 
	 */
	struct list_node_struct* prev;
};

/**
 * @brief typ danych struktury pojedyńczego lemntu listy dynamicznje utworzony w celu późniejszego łatwiejszego przywoływania tego typu w kodzie
 * 
 */
typedef struct list_node_struct list_node;


// typ danych struktury list_pointers do oznaczenia listy dynamicznej
/**
 * @brief struktura wykorzystana jako określnnie listy dynamicznej
 * 
 */
struct list_pointers_strucrt
{
	/**
	 * @brief wskaźnik na początkowy elemnt listy dynamicznej
	 * 
	 */
	list_node* head;

	/**
	 * @brief wskaźńk na końcowy element listy dynamicznej
	 * 
	 */
	list_node* tail;

};

/**
 * @brief typ danych struktualny dla opisu listy dynamicznej  w celu późnijeszego ułatwienia odniesienia się w dalszej części programu
 * 
 */
typedef struct list_pointers_strucrt list_pointers;


//funckcje zjaduje sie w pliku phone_book_list.c do osbsu�ugi listy dynamicznej

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


//funkcje znajduj�ce sie w pliku phone_book.c do obs�ugi ksi�zki telefonicznej

extern void print_contact(contact_type contact);



//funkcje por�uja�e ze sob� dwa elemnty listy w zale�no�ci od parametru opisanegro w nazwie funkcjiu, znajudj� si� w pliku list_cmp.c
// zwracaj� -1 gdy a<b, 0 gdy a=b, 1 gdy a>b 1

extern int id_cmp(list_node* a, list_node* b);
extern int name_cmp(list_node* a, list_node* b);
extern int phone_cmp(list_node* a, list_node* b);
extern int city_cmp(list_node* a, list_node* b);
extern int street_cmp(list_node* a, list_node* b);
extern int postal_code_cmp(list_node* a, list_node* b);
extern number_cmp(list_node* a, list_node* b);




// funkcje wyszukiwujce

extern list_pointers search_results(list_pointers list, int(*is_selected)(char[30], int));
extern int is_search_name(char string[30], contact_type node);
extern int is_search_surname(char string[30], contact_type node);
extern int is_search_phone_number(char string[30], contact_type node);
extern int is_search_city(char string[30], contact_type node);
extern int is_search_street(char string[30], contact_type node);
extern int is_search_postal_code(char string[30], contact_type node);
extern int is_search_number(char string[30], contact_type node);



//user interface functions 
extern void start_ui();
extern list_pointers add_new_element(list_pointers list);





// tymczasowe funkcje znajduj�ce sie w pliku temporary_functions.c u�ywane do tesowtaia poprawno��i dzia�ania prgramu

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