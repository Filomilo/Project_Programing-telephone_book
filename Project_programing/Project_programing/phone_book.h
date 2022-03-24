#ifndef PHONE_BOOK
#define PHONE_BOOK

//struktura adresu wykorzystywana we strukturze wpisu w ksi¹zce telefoniczej

struct adress_struct
{
	char street[30];
	short int number;
	char postal_code[8];
	char city[30];
};
typedef struct adress_struct adress_type;


//struktura pojedyñczego wpisu w ksi¹zce telefoniczej

struct contact_struct
{
	unsigned int id;
	char name[30];
	char surname[30];
	adress_type adress;
	char phone_number[11];

};
typedef struct contact_struct contact_type;


//typ danych struktry pojedyñczego elemntu list, zawiera dane oraz onaczenie poprzeniego i koljengo elemenmtu

struct list_node_struct
{
	contact_type data;
	struct list_node_struct* next;
	struct list_node_struct* prev;
};
typedef struct list_node_struct list_node;


// typ danych struktury list_pointers do oznaczenia listy dynamicznej

struct list_pointers_strucrt
{
	list_node* head;
	list_node* tail;

};
typedef struct list_pointers_strucrt list_pointers;


//funckcje zjaduje sie w pliku phone_book_list.c do osbsu³ugi listy dynamicznej

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
extern int count_elements(list_pointers list);

//funkcje znajduj¹ce sie w pliku phone_book.c do obs³ugi ksi¹zki telefonicznej

extern void print_contact(contact_type contact);



//funkcje poróujaæe ze sob¹ dwa elemnty listy w zale¿noœci od parametru opisanegro w nazwie funkcjiu, znajudj¹ siê w pliku list_cmp.c
// zwracaj¹ -1 gdy a<b, 0 gdy a=b, 1 gdy a>b 1

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





// tymczasowe funkcje znajduj¹ce sie w pliku temporary_functions.c u¿ywane do tesowtaia poprawnoœæi dzia³ania prgramu

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









//gui

extern void start_gui();

#endif 