//funckcje odpowiedzlane za zarz¹dzanie ksi¹zk¹ telefoniczn¹

#include "phone_book.h"
#include <stdlib.h>

// funckcja wyœwietlaj¹c podany jej konkat wraz z podpisamy

void print_contact(contact_type contact)
{
	printf("ID: %d\n", contact.id);
	printf("Name: %s\tSurname: %s\n", contact.name,contact.surname);
	printf("%s, st.%s %d     %s\n", contact.adress.city, contact.adress.street, contact.adress.number, contact.adress.postal_code);
	printf("pohone number: %s", contact.phone_number);
	printf("\n\n\n");
}

int id = 0;

int generate_id(list_pointers list)
{
	//print_list_tail(list);
	int i = 0;
	if (list.head == NULL)
	{
		return i;
	}
	//list = merge_sort(list, id_cmp);
	//print_list_head(list);
	while (list.head != list.tail)
	{
		//printf("id: %d, ",list.tail->data.id);
		list.tail = list.tail->next;
		//printf("contact :"); 
		//print_contact(list.tail->data);
		i++;

	}

	return ++id;
}