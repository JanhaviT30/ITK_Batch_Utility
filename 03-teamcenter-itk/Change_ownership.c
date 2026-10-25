#include "Header.h"
int change_ownership()
{
	int ifail, count, i, count1, j;
	char* error, * ID;
	tag_t* revs, new_user, new_group, * item_list;


	WSO_search_criteria_t criteria;


	ifail = WSOM_clear_search_criteria(&criteria);//search criteria structure
	check_error(ifail);

	
	tc_strcpy(criteria.class_name, "Item");
	tc_strcpy(criteria.name, "*");


	ifail = WSOM_search(criteria, &count1, &item_list);
	check_error(ifail);


	for (j = 0; j < count1; j++)
	{
		ifail = ITEM_ask_id2(item_list[j], &ID);//find item id
		check_error(ifail);
		printf("\n\t Item_id is : %s ", ID);

		ifail = ITEM_list_all_revs(item_list[j], &count, &revs);//find all rev
		check_error(ifail);

		ifail = SA_find_user2("ram", &new_user);//find user
		check_error(ifail);
		ifail = SA_find_group("Honda", &new_group);//find group
		check_error(ifail);
		ifail = AOM_set_ownership(item_list[j], new_user, new_group);
		check_error(ifail);

		if (ifail == ITK_ok)
		{
			printf("\n\t -----OWNERSHIP changed successfully-----");
		}
		else
		{
			EMH_ask_error_text(ifail, &error);
			printf("\n\t %s", error);
		}

		for (i = 0; i < count; i++)
		{
			ifail = AOM_set_ownership(revs[i], new_user, new_group);
			check_error(ifail);

			if (ifail == ITK_ok)
			{
				printf("\n\t ****ownership changed successfully for %d item revision ***", i);
			}
			else
			{
				EMH_ask_error_text(ifail, &error);
				printf("\n\t %s", error);
			}
		}
		if (revs)
			MEM_free(revs);

	}
	if (item_list)
		MEM_free(item_list);
	return 0;
}