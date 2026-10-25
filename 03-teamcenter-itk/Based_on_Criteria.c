#include"Header.h"

int TCTYPE_item_search_based_on_criteria(char* u, char* g)
{
	int ifail;
	int i, count;
	char* id;
	char* name;
	tag_t user, group,*list;

	WSO_search_criteria_t criteria;

	ifail = SA_find_user2(u, &user);//find user
	//check_error(ifail);
	ifail = SA_find_group(g, &group);//find group
	//check_error(ifail);

	ifail = WSOM_clear_search_criteria(&criteria);//initializes a search criteria structure
	//check_error(ifail);
	tc_strcpy(criteria.class_name, "Item");
	tc_strcpy(criteria.name,"*");
	criteria.owner = user;
	criteria.group = group;

	ifail = WSOM_search(criteria, &count, &list);
	printf("\n\t count=%d", count);
	
	for (i = 0; i < count; i++)
	{
		ITEM_ask_id2(list[i], &id);
		printf("\n\t ID=%s", id);

		ITEM_ask_name2(list[i], &name);
		printf("\n\t Name = %s",name);
		//export_dataset(id);//  export dastaset function call 
	}
	if (list)
		MEM_free(list);

	return 0;
}