#include"Header.h"

int Attach_dataset(char* u)
{
	int ifail;
	tag_t type, create_input, BO, user, Home_folder, datasettype, new_dataset, rel_type, rev, rel;
	
	ifail = TCTYPE_find_type("Item", "item", &type);
	check_error(ifail);
	ifail = TCTYPE_construct_create_input(type, &create_input);
	check_error(ifail);
	ifail = AOM_set_value_string(create_input, "item_id", "003007");
	check_error(ifail);
	ifail = AOM_set_value_string(create_input, "object_name", "MERCEDES");
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
	check_error(ifail);
	ifail = AOM_save_with_extensions(Home_folder);
	check_error(ifail);


	ifail = AE_find_datasettype2("PDF", &datasettype);
	check_error(ifail);
	ifail = AE_create_dataset_with_id(datasettype, "TCPLM", "PLM_1", NULLTAG, "A", &new_dataset);
	check_error(ifail);
	ifail = AE_save_myself(new_dataset);
	check_error(ifail);


	ifail = GRM_find_relation_type("IMAN_specification", &rel_type);
	check_error(ifail);
	ifail = ITEM_find_revision(BO, "A", &rev);
	check_error(ifail);
	ifail = GRM_create_relation(rev, new_dataset, rel_type, NULLTAG, &rel);
	check_error(ifail);
	ifail = GRM_save_relation(rel);
	check_error(ifail);

	return 0;
}