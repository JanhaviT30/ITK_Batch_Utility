#include "Header.h"

int bl_ask_all_childs_lines(int count, tag_t* childs);

int TC_find_BOM_line(char* id)
{
	tag_t item, rev, window, top_line, * childs;
	int ifail;
	int i, count, count2;


	ifail = ITEM_find_item(id, &item);//find item
	//check_error(ifail);
	ifail = ITEM_find_revision(item, "A", &rev);//find the revision
	//check_error(ifail);
	ifail = BOM_create_window(&window);//create new bom window
	//check_error(ifail);
	ifail = BOM_set_window_top_line(window, item, rev, NULLTAG, &top_line);//find the top bom line
	//check_error(ifail);
	ifail = BOM_line_ask_all_child_lines(top_line, &count, &childs);//find childs
	//check_error(ifail);


	if (count > 0)
	{
		bl_ask_all_childs_lines(count, childs);
	}
	if (childs)
		MEM_free(childs);
	return 0;
}

int bl_ask_all_childs_lines(int count, tag_t* childs)
{
	int ifail;
	int i;
	int count2;
	tag_t* sub_childs;
	char* name;

	for (i = 0; i < count; i++)
	{
		ifail = AOM_ask_value_string(childs[i], "bl_line_name", &name);
		printf("\n\t name=%s\n", name);
		ifail = BOM_line_ask_all_child_lines(childs[i], &count2, &sub_childs);
		if (count2 > 0)
		{
			bl_ask_all_childs_lines(count2, sub_childs);
		}
		if (sub_childs)
			MEM_free(sub_childs);
	}
	return 0;
}