#include"Header.h"
int check_error(int ifail)
{
	char* error;
	if(ifail == ITK_ok)
	{
		printf("\t\n All_OK\n");

	}
	else
	{
		ifail = EMH_ask_error_text(ifail, &error);
		printf("\n\t ERROR=%s\n", error);
	}
	return 0;
}