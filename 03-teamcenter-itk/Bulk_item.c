#include"Header.h"
int TC_TYPE_create_bulk_item(char* u,char* g, char* name)
{
	tag_t type, type1, create_ip, create_ip1, home, user, *bo;
	int ifail;
	int i, * qty, count;
	tag_t* create_inputs;
	char* error;
	char* id;

	qty = (int*)MEM_alloc(sizeof(int));
	create_inputs = (tag_t*)MEM_alloc(2 * sizeof(tag_t));

	ifail = TCTYPE_find_type("Item", "item", &type);
	check_error(ifail);
	ifail = TCTYPE_construct_create_input(type, &create_ip);
	check_error(ifail);
	ifail = AOM_set_value_string(create_ip, "item_id", NULL);
	check_error(ifail);
	ifail = AOM_set_value_string(create_ip, "object_name", name);
	check_error(ifail);


	ifail = TCTYPE_find_type("Document", "Document", &type1);
	check_error(ifail);
	ifail = TCTYPE_construct_create_input(type1, &create_ip1);
	check_error(ifail);
	ifail = AOM_set_value_string(create_ip1, "item_id", NULL);
	check_error(ifail);
	ifail = AOM_set_value_string(create_ip1, "object_name", name);
	check_error(ifail);


	create_inputs[0] = create_ip;
	create_inputs[1] = create_ip1;

	qty[0] = 5;
	qty[1] = 5;

	ifail = TCTYPE_create_objects(2, qty, create_inputs, &count, &bo);
	//check_error(ifail);
	for (i = 0; i < count; i++)
	{
		ifail = AOM_save_without_extensions(bo[i]);
		if (ifail == ITK_ok)
		{
			printf("\n\t  ITEMS created successfully");
		}
		else
		{
			ifail = EMH_ask_error_text(ifail, &error);
			printf("\n\t%s", error);
		}

		ifail = ITEM_ask_id2(bo[i], &id);
		check_error(ifail);
		printf("\n\t id=%s\n", id);


		ifail = SA_find_user2(u, &user);
		check_error(ifail);
		ifail = SA_ask_user_home_folder(user, &home);
		check_error(ifail);
		ifail = FL_insert(home, bo, 999);
		check_error(ifail);

		ifail = AOM_save_with_extensions(home);
		check_error(ifail);

	}
	if (bo)
		MEM_free(bo);

	return 0;
}