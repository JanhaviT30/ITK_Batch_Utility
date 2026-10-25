#include"Header.h"
int tc_item_bulk_create(char *path)
{
FILE* f1;
int ifail;
char buffer[100];
int k = 0;
char* ID, * Name, * Type;
tag_t type_tag, create_input, bo;
fopen_s(&f1, path, "rt");
if (f1)
{
printf("\n\t File found");
while (fgets(buffer, sizeof(buffer), f1))
{
if (k > 0)
{
printf("\n\t line=%s", buffer);
ID = strtok(buffer, ",");
Name = strtok(NULL, ",");
Type = strtok(NULL, ",");

printf("\n\t ID = % s", ID);
printf("\n\t Name = % s", Name);
printf("\n\t Type = % s", Type);
ifail = TCTYPE_find_type(Type, Type, &type_tag);
ifail = TCTYPE_construct_create_input(type_tag,
&create_input);
ifail = AOM_set_value_string(create_input, "object_name",
Name);
ifail = AOM_set_value_string(create_input, "item_id", ID);
ifail = TCTYPE_create_object(create_input,&bo);
check_error(ifail);
ifail = AOM_save_without_extensions(bo);
check_error(ifail);
tc_insert_objs(bo);
}
k++;
}
}
return 0;
}
