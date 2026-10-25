#include"Header.h"
int PLM_Post_action1(METHOD_message_t* msg, va_list args)
{
	tag_t object, dataset_type, dataset, rel_type, relation;

	char* error;
	object = va_arg(args, tag_t);
	int ifail;
	ifail = AE_find_datasettype2("PDF", &dataset_type);
	if (ifail == ITK_ok)
	{
		printf("ALL_OK\n");

	}
	else
	{
		EMH_ask_error_text(ifail, &error);
		printf("%s\n", error);
	}


	ifail = AE_create_dataset_with_id(dataset_type, "TC", "", "0", "0", &dataset);
	if (ifail == ITK_ok)
	{
		printf("ALL_OK\n");

	}
	else
	{
		EMH_ask_error_text(ifail, &error);
		printf("%s\n", error);
	}


	ifail = AE_save_myself(dataset);
	if (ifail == ITK_ok)
	{
		printf("ALL_OK\n");

	}
	else
	{
		EMH_ask_error_text(ifail, &error);
		printf("%s\n", error);
	}


	ifail = GRM_find_relation_type("IMAN_specification", &rel_type);
	if (ifail == ITK_ok)
	{
		printf("ALL_OK\n");

	}
	else
	{
		EMH_ask_error_text(ifail, &error);
		printf("%s\n", error);
	}


	ifail = GRM_create_relation(object, dataset, rel_type, NULLTAG, &relation);
	if (ifail == ITK_ok)
	{
		printf("ALL_OK\n");

	}
	else
	{
		EMH_ask_error_text(ifail, &error);
		printf("%s\n", error);
	}

	ifail = GRM_save_relation(relation);
	if (ifail == ITK_ok)
	{
		printf("ALL_OK\n");

	}
	else
	{
		EMH_ask_error_text(ifail, &error);
		printf("%s\n", error);
	}

	return 0;
}
