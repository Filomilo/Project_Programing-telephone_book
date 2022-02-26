#ifndef PHONE_BOOK
#define PHONE_BOOK

//structure of adrees for later use in contact sturcture

struct adress_struct
{
	char street[30];
	short int number;
	char postal_code[8];
	char city[30];
};
typedef struct adress_struct adress_type;

//strcuture of single contact to use in phone book

struct contact_struct
{
	unsigned int id;
	char name[30];
	char surname[30];
	adress_type adress;
	char phone_number[11];

};
typedef struct contact_struct contact_type;


//data type of int with change name to use as data type in list and make it easier for later change to sturcture

typedef int list_data;


//strcuture type of a single element of list
struct list_node_struct
{
	list_data data;
	struct list_node_struct* next;
	struct list_node_struct* prev;
};
typedef struct list_node_struct list_node;


//strcuture contating first and last element of list
struct list_pointers_strucrt
{
	list_node* head;
	list_node* tail;

};
typedef struct list_pointers_strucrt list_pointers;


//functions for managing list, located in file phone_book_list.c

extern list_pointers list_init();
extern list_pointers list_add_head(list_pointers list, list_data data);
extern list_pointers list_add_tail(list_pointers list, list_data data);
extern list_node* find_node(list_pointers list, list_data searched_value);
extern list_pointers list_remove_tail(list_pointers list);
extern list_pointers list_remove_head(list_pointers list);
extern list_pointers list_remove_node(list_pointers list, list_node* node_to_remove);
void list_edit_node(list_node* node_to_edit, list_data data);
void print_list_head(list_pointers list);
void print_list_tail(list_pointers list);
extern list_node* find_middle_node(list_pointers list);
extern list_pointers merge_sort(list_pointers list, int (*cmp)(list_data, list_data));

extern void print_contact(contact_type contact);





// temporary function for testing if list data structure works properly, located in temporary_functions.c

extern void list_test(); 
extern void genrating_contacts_test();
int int_cmp(list_data a, list_data b);
void list_test_sort();










#endif 