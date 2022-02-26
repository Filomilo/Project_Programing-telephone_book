#include "phone_book.h"


void print_contact(contact_type contact)
{
	printf("ID: %d\n", contact.id);
	printf("Name: %s\tSurname: %s\n", contact.name,contact.surname);
	printf("%s, st.%s %d     %s\n", contact.adress.city, contact.adress.street, contact.adress.number, contact.adress.postal_code);
	printf("pohone number: %s", contact.phone_number);
	printf("\n\n\n");
}