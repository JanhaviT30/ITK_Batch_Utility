#include "Header.h"
//Load the lib
extern  DLLAPI int libtata_register_callbacks()
{
	//register the lib
	CUSTOM_register_exit("libtata", "USER_init_module", (CUSTOM_EXIT_ftn_t)tc_function1);
	//CUSTOM_register_exit("libtata", "USER_exit_module", (CUSTOM_EXIT_ftn_t)tc_function2);
	return 0;
}


//execute dll 1
extern DLLAPI int tc_function1(int* decision, va_list args)
{
	METHOD_id_t method_id;
	*decision = ALL_CUSTOMIZATIONS;

	TC_write_syslog("\n\t libtata user reg successfully");


	/*METHOD_find_method("ItemRevision", "ITEM_copy_rev", &method_id);


	METHOD_add_pre_condition(method_id, (METHOD_function_t)PLM_pre_cond, NULL);*/









	//METHOD_find_method("IMAN_specification", "GRM_create", &method_id);
	//METHOD_add_pre_condition(method_id, (METHOD_function_t)PLM_pre_cond2, NULL);

	//METHOD_find_method("ItemRevision", "IMAN_save", &method_id);
	//METHOD_add_action(method_id, METHOD_post_action_type, 
	//	(METHOD_function_t)PLM_Post_action1, NULL);



	/*EPM_register_rule_handler("PLM_check_owner", "PLM_check_owner", (EPM_rule_handler_t) 
		PLM_check_owner);*/

	//METHOD_id_t mehtod_id;
	//METHOD_find_method("ItemRevision", "ITEM_copy_rev", &mehtod_id);
	//METHOD_add_action(mehtod_id, METHOD_post_action_type, (METHOD_function_t)updateProperty, NULL);





	//EPM_register_action_handler("PLM_attach_dataset", "PLM_attach_dataset_desc",
		//(EPM_action_handler_t)PLM_attach_dataset);

	EPM_register_action_handler("PLM_add_top_owner", "PLM_add_top_owner_desc",
		(EPM_action_handler_t)PLM_add_top_owner);

	//EPM_register_action_handler("PLM_select_signoff", "PLM_select_signoff", 
	//	(EPM_action_handler_t)PLM_add_top_level_owner_to_signoff);



	return 0;
}

//execute the dll 2
extern DLLAPI int tc_function2(int* decision, va_list args)
{
	*decision = ALL_CUSTOMIZATIONS;
	TC_write_syslog("\n\t libtata reg successfully");
	return 0;
}