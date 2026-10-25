#include"Header.h"

int updateProperty(METHOD_message_t msg, va_list args) {

	tag_t itemRevision = va_arg(args, tag_t); // previous - on which item revision i have performed Revise opetation
	// new -> After performing Revise operation newly created Revision

	int ifail = ITK_ok;

	ifail = AOM_refresh(itemRevision, 1); // item revision cheked
	ifail = AOM_set_value_string(itemRevision, "object_desc", "This Item Revision is Revised");// property filled
	ifail = AOM_save_with_extensions(itemRevision); // save As

	ifail = AOM_refresh(itemRevision, 0);
	
	return 0;
}