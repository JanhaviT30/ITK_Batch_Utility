#include"Header.h"
#//Program for Action Handler
int PLM_attach_dataset(EPM_action_message_t msg)
{
	tag_t root_task, * attachments, dataset_type, dataset, rel_type, rel;
	int i, count, j;
	char* arg_name, * arg_value;
	char* obj_type;
	char* type = NULL, * name = NULL, *rel_types = NULL;// = NULL;
	int ifail;

	// find the root task
	EPM_ask_root_task(msg.task, &root_task);

	int k = TC_number_of_arguments(msg.arguments);
	for (j = 0; j < k; j++)
	{
		ITK_ask_argument_named_value(TC_next_argument(msg.arguments), &arg_name, &arg_value);
		if (tc_strcmp(arg_name, "type") == 0)
		{
			type = (char*)MEM_alloc(100);
			tc_strcpy(type, "");
			tc_strcpy(type, arg_value);
		}
		if (tc_strcmp(arg_name, "name") == 0)
		{
			name = (char*)MEM_alloc(100);
			tc_strcpy(name, "");
			tc_strcpy(name, arg_value);
		}
		
	}

	//find the target objects
	EPM_ask_attachments(root_task, EPM_target_attachment, &count, &attachments);
	for (i = 0; i < count; i++)
	{
		WSOM_ask_object_type2(attachments[i], &obj_type);
		if (tc_strcmp(obj_type, "ItemRevision") == 0)
		{
			ifail = AE_find_datasettype2(type, &dataset_type);//find datasettype
			ifail = AE_create_dataset_with_id(dataset_type,name, "", "0", "0", &dataset);//create dataset
			ifail = AE_save_myself(dataset);//save
			ifail = GRM_find_relation_type("IMAN_specification", &rel_type);//find rel
			ifail = GRM_create_relation(attachments[i], dataset, rel_type, NULLTAG, &rel);//create rel
			ifail = GRM_save_relation(rel);//save rel
		}
	}
	if (attachments)
		MEM_free(attachments);
	return 0;
}