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

list_pointers duplicate_book( list_pointers list)
{
	list_pointers new = list_init();
	

	if (list.head == NULL)
	{
		return new;
	}
	while (list.tail != list.head)
	{
		new=list_add_tail(new, list.tail->data);
		list.tail = list.tail->next;


	}
	new = list_add_tail(new, list.tail->data);





	return new;

}



int generate_id(list_pointers list)
{
	int i=0;
	list_pointers tmp = duplicate_book(list);
	tmp = merge_sort(tmp, id_cmp);
	
	list_node* active = tmp.head;

	if (tmp.head == NULL)
	{
		printf("your list is empty\n");
		return i;
	}
	while (tmp.tail != active)
	{
		i++;
		
		active = active->prev;
		if (active->data.id != i)
		{
			free_list(tmp);
			return i;
		}
			

	}
	i++;
	free_list(tmp);
	
	return i;
}