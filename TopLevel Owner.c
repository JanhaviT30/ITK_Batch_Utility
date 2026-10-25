#include"Header.h"

int PLM_add_top_owner(EPM_action_message_t msg)  //handler definition
{
	int ifail, i, j, k, signoff_count, sec_obj_count, count, sign_of_count;

	tag_t* signoff, sub_task, root_task, memberTag, * attachments, user, * sec_obj;


	//EPM_decision_t decision=EPM_nogo;
	char* attachments_type, * sec_obj_type;
	char* login_user_name, * propvalue;
	int* levels, no_of_members;
	int no_of_parents;

	tag_t* parents, owner, group, * members, * sign_off;
	EPM_signoff_decision_t decision;
	date_t decision_date;
	char* comments;

	//get the root task
	ifail = EPM_ask_root_task(msg.task, &root_task);
	//get the target attachments

	ifail = EPM_ask_attachments(root_task, EPM_target_attachment, &count, &attachments);
	for (i = 0; i < count; i++)
	{

		//get the object type
		ifail = WSOM_ask_object_type2(attachments[i], &attachments_type);

		if (tc_strcmp(attachments_type, "ItemRevision") == 0)
		{
			//get the total parnets objtes

			ifail = PS_where_used_all(attachments[i], -1, &no_of_parents, &levels, &parents);
			for (j = 0; j < no_of_parents; j++)
			{
				//get the owner
				POM_ask_owner(parents[j], &owner, &group);

				//members tag from user and group
				ifail = SA_find_groupmembers(owner, group, &no_of_members, &members);
				for (k = 0; k < no_of_members; k++)
				{
					//add sign off user
					ifail =	EPM_create_adhoc_signoff(msg.task, members[k], &sign_of_count, &sign_off);


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