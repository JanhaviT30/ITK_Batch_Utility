#include"Header.h"
int TCTYPE_item_create(char* u,char* id)
{
	int ifail;
	tag_t type, create_input, BO, user, Home_folder;

	ifail = TCTYPE_find_type("Item", "item", &type);
	check_error(ifail);
	ifail = TCTYPE_construct_create_input(type, &create_input);
	check_error(ifail);
	ifail = AOM_set_value_string(create_input, "item_id", id);
	check_error(ifail);
	ifail = AOM_set_value_string(create_input, "object_name", "BMW");
	check_error(ifail);
	ifail = AOM_set_value_string(create_input, "object_desc", "this is custom BMW type document....");
	check_error(ifail);
	ifail = TCTYPE_create_object(create_input, &BO);
	check_error(ifail);
	ifail = AOM_save_without_extensions(BO);
	check_error(ifail);
	ifail = SA_find_user2(u, &user);
	check_error(ifail);
	ifail = SA_ask_user_home_folder(user, &Home_folder);
	check_error(ifail);
	ifail = FL_insert(Home_folder, BO, 999);
	check_error(ifail);;
	ifail = AOM_save_with_extensions(Home_folder);
	check_error(ifail);

	return 0;
}
