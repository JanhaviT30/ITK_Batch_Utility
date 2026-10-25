#include"Header.h"


#define PLM_error (EMH_USER_error_base +1234)


int PLM_pre_cond(METHOD_message_t* msg, va_list args)
{
	tag_t source_rev;
	const char* rev_id;


	char* value;

	source_rev = va_arg(args, tag_t);
	rev_id = va_arg(args, char*);

	AOM_UIF_ask_value(source_rev, "release_status_list", &value);
	if (tc_strcmp(value, "TCM Released") == 0)
	{

	}
	else
	{
		EMH_store_error_s2(EMH_severity_error, PLM_error, "Hi", "itemRevision is not released...");
		return PLM_error;
	}

	return 0;
}
