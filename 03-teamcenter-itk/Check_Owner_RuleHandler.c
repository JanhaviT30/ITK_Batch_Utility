#include"Header.h"

//Program for Rule Handler(Honda01 WF)
EPM_decision_t PLM_check_owner(EPM_rule_message_t msg)
{
    EPM_decision_t decision = EPM_nogo;
    tag_t root_task, * attachments, login_user, owner;
    int i, count;
    char* login_user_name;

    //find the root task
    EPM_ask_root_task(msg.task, &root_task);


    //find the target objects
    EPM_ask_attachments(root_task, EPM_target_attachment, &count, &attachments);

    for (i = 0; i < count; i++)
    {
        //find the login user name
        POM_get_user(&login_user_name, &login_user);

        //find the target owner
        AOM_ask_owner(attachments[i], &owner);

        if (login_user == owner)
            decision = EPM_go;

    }
    if (attachments)
        MEM_free(attachments);

    return decision;
}
