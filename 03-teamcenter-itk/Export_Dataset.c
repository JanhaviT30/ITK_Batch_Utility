#include"Header.h"

int export_dataset(char* id)
{
	int i, j, count, count1;
	char* error;
	int ifail;
	tag_t item, rev, rel_type,* sec_objects, * ref;
	char* sec_object_type;
	char* ref_name;
	
	char path[100];
	//char* path;


	ifail = ITEM_find_item(id, &item);//find item
	check_error(ifail);
	ifail = ITEM_find_revision(item, "A", &rev);//find revision
	check_error(ifail);

	ifail = GRM_find_relation_type("IMAN_specification", &rel_type);
	check_error(ifail);

	ifail = GRM_list_secondary_objects_only(rev, rel_type, &count, &sec_objects);//find secondary object
	check_error(ifail);
	printf("\n\t count=%d\n", count);

	for (i = 0; i < count; i++)
	{
		ifail = WSOM_ask_object_type2(sec_objects[i], &sec_object_type);//find the sec object type
		check_error(ifail);
		printf("\n\t sec_object_type=%s\n", sec_object_type);

		if (tc_strcmp(sec_object_type,"PDF") == 0)
		{
			ifail = AE_ask_all_dataset_named_refs2(sec_objects[i], "PDF_Reference", &count1, &ref);//fimd the named ref count
			check_error(ifail);

			for (j = 0; j < count1; j++)
			{
				ifail = IMF_ask_original_file_name2(ref[j], &ref_name);//find named ref name
				check_error(ifail);

				printf("\n\t ref_name=%s", ref_name);//c.pdf
				
				
				tc_strcpy(path, "");
				tc_strcpy(path, "C:\\ITK_export\\");  // C:\\ITK_Export\\c.pdf
				tc_strcat(path, ref_name);  //   c:\\export\\c.pdf
				printf("\n\t  Ref_name with path=%s", path);

				ifail = AOM_refresh(sec_objects[i], 1);//check-out
				check_error(ifail);
				ifail = AE_export_named_ref(sec_objects[i], "PDF_Reference", path);//export dataset named ref
				check_error(ifail);
				ifail = AOM_refresh(sec_objects[i], 0);//check-in
				check_error(ifail);
			
			}
			if (ref)
				MEM_free(ref);
			

		}
		
		
	}if (sec_objects)
		MEM_free(sec_objects);

	return 0;
}