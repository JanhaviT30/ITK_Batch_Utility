#include<fclasses/tc_string.h>
#include<tc\tc_startup.h>
#include<tc/emh.h>
#include<tccore/item.h>
#include<tcinit/tcinit.h>
#include<tc/folder.h>
#include<tccore/aom.h>
#include<tccore/tctype.h>
#include<tccore/aom_prop.h>
#include<sa/user.h>
#include<ae/datasettype.h>
#include<ae/dataset.h>
#include<tccore/grm.h>

#include<tccore/workspaceobject.h>
#include<sa/tcfile.h>

#include<fclasses/tc_string.h>
#include<qry/qry.h>

#include<bom/bom.h>

int check_error(int ifail);
int Itemcreate(char* u, char* id, char* name);


int BulkItem_create(char* u, char* name);


int TCTYPE_item_create(char* u, char*id);
int Attach_dataset(char* u);
int export_dataset(char* id);
int TCTYPE_item_search_based_on_criteria(char* u, char* g);
int  TCTYPE_item_search_based_on_query(char* u, char* g);
int TC_find_BOM_line(char* id);
int TC_TYPE_create_bulk_item(char* u, char* g, char* name);
int change_ownership();
