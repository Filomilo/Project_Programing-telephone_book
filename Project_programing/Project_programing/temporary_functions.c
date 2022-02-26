#include "phone_book.h"
#include <stdio.h>
#include <stdlib.h>



void list_test()
{
	printf("\n\n\n\n\n thisi s the test of list data structure: \n\n");
	list_pointers list = list_init();
	printf("\ninitiation list using: list_pointers list= list_init();\n");
	print_list_head(list);

	printf("\nadding vale of 5 to list from head side using : list=list_add_head(list, 5);\t printing list from head side using: print_list_head(list);\n");
	list = list_add_head(list, 5);
	print_list_head(list);


	printf("\nadding vale of 82 to list from head side using : list=list_add_head(list, 82);\t printing list from head side using: print_list_head(list);\n");
	list = list_add_head(list, 82);
	print_list_head(list);

	printf("\nadding vale of 22 to list from head side using :	list = list_add_head(list, 22);;\tprinting list from tail side using:print_list_tail(list);;\n");
	list = list_add_head(list, 22);
	print_list_tail(list);

	printf("\nadding vale of 123 to list from tail side using : list_add_tail(list, 123);\tprinting list from tail side using: print_list_tail(list);\n");
	list = list_add_tail(list, 123);
	print_list_tail(list);

	printf("\nremoving tail of list using : list = list_remove_tail(list);\tprinting list from tail side using: print_list_tail(list);\n");
	list = list_remove_tail(list);
	print_list_tail(list);

	printf("\nremoving tail of list using : list = list_remove_tail(list);\tprinting list from tail side using: print_list_tail(list);\n");
	list = list_remove_tail(list);
	print_list_tail(list);

	printf("\nremoving head of list using : list = list_remove_head(list);;\tprinting list from tail side using: print_list_tail(list);\n");
	list = list_remove_head(list);
	print_list_tail(list);

	printf("\nremoving head of list using : list = list_remove_head(list);;\tprinting list from tail side using: print_list_tail(list);\n");
	list = list_remove_head(list);
	print_list_tail(list);

	printf("\nremoving head of list using : list = list_remove_head(list);;\tprinting list from tail side using: print_list_tail(list);\n");
	list = list_remove_head(list);
	print_list_tail(list);

	printf("\nremoving tail of list using : list = list_remove_tail(list);\tprinting list from tail side using: print_list_tail(list);\n");
	list = list_remove_tail(list);
	print_list_tail(list);

	printf("\nadding vale of 55 to list from head side using : list=list_add_head(list, 5);\t printing list from head side using: print_list_head(list);\n");
	list = list_add_head(list, 55);
	print_list_head(list);


	printf("\nadding vale of 78 to list from head side using : list=list_add_head(list, 82);\t printing list from head side using: print_list_head(list);\n");
	list = list_add_head(list, 78);
	print_list_head(list);

	printf("\nadding vale of 4 to list from head side using :	list = list_add_head(list, 22);;\tprinting list from tail side using:print_list_tail(list);;\n");
	list = list_add_head(list, 4);
	print_list_tail(list);

	printf("\nadding vale of 33 to list from tail side using : list_add_tail(list, 123);\tprinting list from tail side using: print_list_tail(list);\n");
	list = list_add_tail(list, 33);
	print_list_tail(list);


	printf("\n removing selected node by value 55 using  list = list_remove_node(list, find_node(list,55));  \tprinting list from tail side using: print_list_tail(list);\n");
	list = list_remove_node(list, find_node(list, 55));
	print_list_tail(list);


	printf("\n removing selected node by value 4 using  list = list_remove_node(list, find_node(list,55));  \tprinting list from tail side using: print_list_tail(list);\n");
	list = list_remove_node(list, find_node(list, 4));
	print_list_tail(list);

	printf("\n removing selected node by value 58 using  list = list_remove_node(list, find_node(list,55));  \tprinting list from tail side using: print_list_tail(list);\n");
	list = list_remove_node(list, find_node(list, 58));
	print_list_tail(list);


	printf("\n ediintg selected node by value 11 to 22 using  ist_edit_node(find_node(list, 11), 22);  \tprinting list from tail side using: print_list_tail(list);\n");
	list_edit_node(find_node(list, 11), 22);
	print_list_tail(list);


	printf("\n ediintg selected node by value 33 to 456 using  ist_edit_node(find_node(list, 11), 22);  \tprinting list from tail side using: print_list_tail(list);\n");
	list_edit_node(find_node(list, 33), 456);
	print_list_tail(list);



	printf("\n\n\n\n\n\n\n");

}