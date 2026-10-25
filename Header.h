#include<conio.h>
#include<stdio.h>
#include<tccore/custom.h>
#include<tccore/method.h>
#include<tc/tc_startup.h>
#include<tccore/aom.h>
#include<tccore/aom_prop.h>
#include<fclasses/tc_string.h>
#include<tc/emh.h>
#include<tccore/grm.h>
#include<tccore/project.h>
#include<ae/dataset.h>
#include<ae/datasettype.h>
#include<epm/epm.h>
#include<tc/preferences.h>
#include<epm/epm_task_template_itk.h>//post action wf

#include<ps/ps.h> // add_top_level_owner_to_signoff
#include<sa/groupmember.h>
#include<epm/signoff.h>




#define DLLAPI __declspec(dllexport)


extern  DLLAPI int libtata_register_callbacks();
extern DLLAPI int tc_function1(int* decision, va_list args);
extern DLLAPI int tc_function2(int* decision, va_list args);


int PLM_add_top_owner(EPM_action_message_t msg);
int PLM_pre_cond(METHOD_message_t* msg, va_list args);
int updateProperty(METHOD_message_t* msg, va_list args);







int PLM_pre_cond(METHOD_message_t* msg, va_list args);
int PLM_pre_cond2(METHOD_message_t* msg, va_list args);
int PLM_Post_action1(METHOD_message_t* msg, va_list args);

EPM_decision_t PLM_check_owner(EPM_rule_message_t msg);
int PLM_attach_dataset(EPM_action_message_t msg);
int PLM_add_top_level_owner_to_signoff(EPM_action_message_t msg);







