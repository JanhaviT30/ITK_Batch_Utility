//Write the Action Handler which will add all top level owner of Assembly in the
//Select Sign - off Team Automatically.

#include "Header.h"

int PLM_add_top_level_owner_to_signoff(EPM_action_message_t msg)
{
	tag_t root_task, * attachments, * parents, owner, group, * members, * sign_off;
	int i, * count, j, k;
	int ifail;
	char* attachments_type;
	int num_of_parents, * levels, num_of_members, num_of_signoff;

	ifail = EPM_ask_root_task(msg.task, &root_task);
	//find the root task

	ifail = EPM_ask_attachments(root_task, EPM_target_attachment, &count, &attachments);
	//find the target objects
	for (i = 0; i < count; i++)
	{

		ifail = WSOM_ask_object_type2(attachments[i], &attachments_type);
		//find obj type

		if (tc_strcmp(attachments_type, "ItemRevision") == 0)
		{
			ifail = PS_where_used_all(attachments[i], -1, &num_of_parents, &levels, &parents);//get total parent obj
			for (j = 0; j < num_of_parents; j++)
			{
				POM_ask_owner(parents[j], &owner, &group);//get owner

				ifail = SA_find_groupmembers(owner, group, &num_of_members, &members);//find all groupmembers
				for (k = 0; k < num_of_members; k++)
				{
					ifail = EPM_create_adhoc_signoff(msg.task, members[k], &num_of_signoff, &sign_off);
				}
				if (members)
					MEM_free(members);
			}
			if (parents)
				MEM_free(parents);
		}

	}
	if (attachments)
		MEM_free(attachments);
	return 0;
}
