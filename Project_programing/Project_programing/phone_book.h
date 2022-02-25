#ifndef PHONE_BOOK
#define PHONE_BOOK





struct adress_struct
{
	char street[30];
	short int number;
	char postal_code[8];
	char city[30];
};
typedef struct adress_struct adress_type;


struct contact_struct
{
	unsigned int id;
	char name[30];
	char surname[30];
	adress_type adress;
	char phone_number[11];

};
typedef struct contact_struct contact_type;




extern void print_test();


#endif 