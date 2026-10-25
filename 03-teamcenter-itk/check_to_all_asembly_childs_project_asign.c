
EPM_register_rule_handler("PS_assembly_components", "Check the BOM line sub comp project assign or not befoer tiating a workflow",
	(EPM_rule_handler_t)PS_assembly_components);






#include "Header.h"
EPM_decision_t decision = EPM_nogo;
int check_assmbly_comp_project(int count, tag_t* childs);
EPM_decision_t PS_assembly_components(EPM_rule_message_t msg)
{
	
	int ifail, count, found, j, i;
	char* class_name;
	tag_t root_task,* childs, top_line, item, window,*attachments, class_id;
	char* obj_type;

	ifail = EPM_ask_root_task(msg.task, &root_task);
	ifail = EPM_ask_attachments(root_task, EPM_target_attachment, &count, &attachments);
	for (i = 0; i < count; i++)
	{
		ifail = POM_class_of_instance(attachments[i], &class_id);
		ifail = POM_name_of_class(class_id, &class_name);
		//ifail = WSOM_ask_object_type2(attachments[i], &obj_type);
		if (tc_strcmp(class_name, "ItemRevision") == 0)
		{
			ifail=BOM_create_window(&window);
			ifail = ITEM_ask_item_of_rev(attachments[i], &item);
			ifail = BOM_set_window_top_line(window, item, attachments[i], NULLTAG, &top_line);
			ifail = BOM_line_ask_all_child_lines(top_line, &count, &childs);
			if (count > 0)
			{
				check_assmbly_comp_project(count, childs);
			}

		}
	}
	return decision;
}
int check_assmbly_comp_project(int count,tag_t * childs)
{
	char* proj_id;
	tag_t* sub_childs;
	int child_count;
	for (int i = 0; i < count; i++)
	{
		AOM_ask_value_string(childs[i], "bl_project_id", &proj_id);
		if (tc_strcmp(proj_id, "TCproject1") != 0)
		{
			decision = EPM_nogo;
			break;
		}
		else
		{
			decision = EPM_go;
			ifail = BOM_line_ask_all_child_lines(childs[i], &child_count, &sub_childs);
			if (child_count > 0)
			{
				check_assmbly_comp_project(child_count, sub_childs);
			}
		}
	}


	return 0;
}
