#include "Header.h"
int Auto_assignUser(char* id)
{

	int ifail = 0, i, count;
	char* user_id;
	char* name;
	char* parent_item_id, * group_name;
	char* level;
	int no_of_parent, * levels;
	tag_t item, rev, user, group, * table_rows, * parents, * table_row;

	char* str;
	char* s;

	ifail = ITEM_find_item(id, &item);

	ifail = ITEM_find_revision(item, "A", &rev);


	ifail = PS_where_used_all(rev, -1, &no_of_parent, &levels, &parents);
	printf("\n\t no_of_parent=%d", no_of_parent);
	for (i = 0; i < no_of_parent; i++)
	{
		ifail = AOM_ask_value_string(parents[i], "item_id", &parent_item_id);

		printf("\n\t parent_item_id=%s", parent_item_id);
		ifail = POM_ask_owner(parents[i], &user, &group);
		ifail = SA_ask_group_name2(group, &group_name);
		ifail = SA_ask_user_identifier2(user, &user_id);

		ifail = AOM_ask_table_rows(rev, "j9Honda_table", &count, &table_row);
		if (ifail == ITK_ok)
		{
			printf("\n\t AOM_insert_table_rows successfully");
		}
		{
			EMH_ask_error_text(ifail, &s);
			printf("\n\t\t Error=%s", s);
		}
		printf("\n\t row count=%d", count);
		ifail = AOM_refresh(rev, 1);
		ifail = AOM_insert_table_rows(rev, "j9Honda_table", 0, 1, &table_rows);
		if (ifail == ITK_ok)
		{
			printf("\n\t AOM_insert_table_rows successfully");
		}
		else
		{
			EMH_ask_error_text(ifail, &s);
			printf("\n\t\t Error=%s", s);
		}
		ifail = AOM_ask_name(parents[i], &name);


		//level = atoi(levels[0]);
		str = (char*)MEM_alloc(sizeof(char*));
		snprintf(str, sizeof(str), "%d", levels[i]);
		printf("\n\t level=%s", str);
		printf("\n\t parent_item_id=%s", parent_item_id);
		printf("\n\t group_name=%s", group_name);
		printf("\n\t user_id=%s", user_id);
		printf("\n\t parents name=%s", name);


		ifail = AOM_set_value_string(table_rows[0], "j9Group", group_name);
		if (ifail == ITK_ok)
		{
			printf("\n\t AOM_set_value_string successfully");
		}
		else
		{
			EMH_ask_error_text(ifail, &s);
			printf("\n\t\t Error=%s", s);
		}
		ifail = AOM_set_value_string(table_rows[0], "j9Parent_id", parent_item_id);
		if (ifail == ITK_ok)
		{
			printf("\n\t AOM_set_value_string successfully");
		}
		else
		{
			EMH_ask_error_text(ifail, &s);
			printf("\n\t\t Error=%s", s);
		}
		ifail = AOM_set_value_string(table_rows[0], "j9level", str);
		if (ifail == ITK_ok)
		{
			printf("\n\t AOM_set_value_string successfully");
		}
		else
		{
			EMH_ask_error_text(ifail, &s);
			printf("\n\t\t Error=%s", s);
		}
		ifail = AOM_set_value_string(table_rows[0], "j9Name", name);
		if (ifail == ITK_ok)
		{
			printf("\n\t AOM_set_value_string successfully");
		}
		else
		{
			EMH_ask_error_text(ifail, &s);
			printf("\n\t\t Error=%s", s);
		}

		ifail = AOM_save_without_extensions(table_rows[0]);
		if (ifail == ITK_ok)
		{
			printf("\n\t Table property Updated");
		}
		else
		{
			EMH_ask_error_text(ifail, &s);
			printf("\n\t\t Error=%s", s);
		}

		printf("\n\n\t Number of rows=%d", count);
		ifail = AOM_refresh(rev, 0);
		//if (table_rows)
		//MEM_free(table_rows);
	}
	ifail = AOM_refresh(rev, 1);
	if (parents)
		MEM_free(parents);

	return ITK_ok;
}
