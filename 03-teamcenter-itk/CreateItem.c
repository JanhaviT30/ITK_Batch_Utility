#include"Header.h"

int Itemcreate(char* u,char* id, char* name)
{
	int ifail;
	tag_t item, rev,user, home_folder;


	ifail = ITEM_create_item(id, name, "Item", "A", &item, &rev);
	check_error(ifail);


	ifail = ITEM_save_item(item);
	check_error(ifail);

	ifail = ITEM_save_rev(rev);
	check_error(ifail);

	ifail = SA_find_user2(u, &user);
	check_error(ifail);

	ifail = SA_ask_user_home_folder(user, &home_folder);
	check_error(ifail);

	ifail = FL_insert(home_folder, item, 999);
	check_error(ifail);

	ifail = AOM_save_with_extensions(home_folder);
	check_error(ifail);

	return 0;
}