#include"Header.h"

int  TCTYPE_item_search_based_on_query(char* u, char* g)
{
	int ifail;
	tag_t user, group, query, * list;
	int i, count;
	char* id;
	char* name;


	char** entries;
	char** values;

	entries = (char**)MEM_alloc(4 * sizeof(char*));
	values= (char**)MEM_alloc(4 * sizeof(char*));
	for (i = 0; i < 4; i++)
	{
		entries[i]= (char*)MEM_alloc(sizeof(char*));
		values[i]= (char*)MEM_alloc(sizeof(char*));
	}

	tc_strcpy(entries[0], "Name");
	tc_strcpy(entries[1], "Type");
	tc_strcpy(entries[2], "Owning User");
	tc_strcpy(entries[3], "Owning Group");


	tc_strcpy(values[0], "*");
	tc_strcpy(values[1], "Item");
	tc_strcpy(values[2], u);
	tc_strcpy(values[3], g);


	ifail = QRY_find2("General...", &query);//search query
	//check_error(ifail);
	ifail = QRY_execute(query, 4, entries, values, &count, &list);
	//check_error(ifail);

	for (i = 0; i < count; i++)
	{
		ifail = ITEM_ask_id2(list[i], &id);
		printf("\n\n\t id=%s", id);

		ifail = ITEM_ask_name2(list[i], &name);
		printf("\n\t name=%s",name);
	}
	if (list)
		MEM_free(list);
	return 0;
}