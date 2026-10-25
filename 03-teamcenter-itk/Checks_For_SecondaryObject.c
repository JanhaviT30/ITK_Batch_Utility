#include"Header.h"
# define PLM_error (EMH_USER_error_base + 5656)
int PLM_pre_cond2(METHOD_message_t* msg, va_list args)
{
	tag_t primary_object, secondary_object, relation_type, * sec_obj;
	int ifail;
	char* secondary_object_type;
	char* sec_obj_type;
	int i, count;
	int flag = ITK_ok;

#define ITK_notOK = 1;

	primary_object = va_arg(args, tag_t);
	secondary_object = va_arg(args, tag_t);
	relation_type = va_arg(args, tag_t);

	ifail = WSOM_ask_object_type2(secondary_object, &secondary_object_type);
	if (tc_strcmp(secondary_object_type, "Text") == 0)
	{
		ifail = GRM_list_secondary_objects_only(primary_object, relation_type, &count, &sec_obj);
		for (i = 0; i < count; i++)
		{
			ifail = WSOM_ask_object_type2(sec_obj[i], &sec_obj_type);
			if (tc_strcmp(sec_obj_type, "PDF") == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == ITK_ok)
		{
			EMH_store_error_s2(EMH_severity_error, PLM_error, "Hii", "PDF not Attached");
			return PLM_error;
		}
		
	}
	return 0;
}
