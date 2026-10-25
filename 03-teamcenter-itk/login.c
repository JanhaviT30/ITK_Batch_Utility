#include "Header.h"
int ITK_user_main(int argc, char* argv[])
{
	char* u = ITK_ask_cli_argument("-u=");
	char* p = ITK_ask_cli_argument("-p=");
	char* g = ITK_ask_cli_argument("-g=");
	char* id = ITK_ask_cli_argument("-id=");
	char* name = ITK_ask_cli_argument("-name=");

	int ifail;
	char* error;
	ifail = ITK_init_module(u, p, g);// attempt to login
	if (ifail == ITK_ok)
	{
		printf("\n\t Logging into the TEAMCENTER\n\t");
		 //TC_TYPE_create_bulk_item(u, g,  name);
		//BulkItem_create(u, name);
		//Itemcreate(u, id, name);
		//TCTYPE_item_create(u,id);
	//Attach_dataset(u);
	     
        //   TCTYPE_item_search_based_on_criteria(u,g);
	// TCTYPE_item_search_based_on_query(u, g);
	//TC_find_BOM_line(id);
	Attach_dataset(u);
		//change_ownership();


	//	export_dataset(id);
		
	}
	else
	{
		ifail = EMH_ask_error_text(ifail, &error);
		printf("\n\t %s", error);
	}




	return 0;
}


