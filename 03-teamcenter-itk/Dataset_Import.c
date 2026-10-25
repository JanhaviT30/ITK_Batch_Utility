#include"Header.h"

int datasetImport(char* id)
{

	int ifail, count;

	char* msg, * type;

	tag_t item, rev, rel_type, * sec_obj_list;

	ITEM_find_item(id, &item);
	ITEM_find_revision(item, "A", &rev);
	GRM_find_relation_type("IMAN_specification", &rel_type);
	GRM_list_secondary_objects_only(rev, rel_type, &count, &sec_obj_list);
	for (int i = 0; i < count; i++)
	{
		WSOM_ask_object_type2(sec_obj_list[i], &type); // PDF
		if (tc_strcmp(type, "PDF") == 0)
		{
			AOM_refresh(sec_obj_list[i], 1); //check out
			ifail = AE_import_named_ref(sec_obj_list[i], "PDF_Reference", "C:\\Users\\Admin\\Desktop\\TC_Jframe.pdf", NULL, SS_BINARY);
			AE_save_myself(sec_obj_list[i]);
			AOM_refresh(sec_obj_list[i], 0); // check in
		}
	}
	if (sec_obj_list)
		MEM_free(sec_obj_list);
	if (ifail == ITK_ok)
	{
		printf("\n\t File Imported Sucessfully:");
	}
	else
	{
		EMH_ask_error_text(ifail, &msg);
		printf("\n\n\t Error=%s", msg);
	}
	//getch();
	return ITK_ok;
}



	
