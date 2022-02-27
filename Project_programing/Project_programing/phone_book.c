//funckcje odpowiedzlane za zarz¹dzanie ksi¹zk¹ telefoniczn¹

#include "phone_book.h"


// funckcja wyœwietlaj¹c podany jej konkat wraz z podpisamy

void print_contact(contact_type contact)
{
	printf("ID: %d\n", contact.id);
	printf("Name: %s\tSurname: %s\n", contact.name,contact.surname);
	printf("%s, st.%s %d     %s\n", contact.adress.city, contact.adress.street, contact.adress.number, contact.adress.postal_code);
	printf("pohone number: %s", contact.phone_number);
	printf("\n\n\n");
}