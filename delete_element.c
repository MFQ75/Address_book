#include "address_book.h"

Status delete_element(Information *info)
{
	close_file(info);
	info->fptr = fopen("general.csv", "r");
	info->fptr1 = fopen("dup.csv","w");
	int c=0,num;
	printf("Enter the index no : ");
	scanf("%d",&num);
	char content[80];

	while(fscanf(info->fptr,"%s",content) != EOF)
	{
		c++;
		if(c == num)
			continue;
		fprintf(info->fptr1,"%s\n",content);
	}
        fclose(info->fptr1);
	close_file(info);

	if(c<num)
		return failure;
	info->fptr = fopen("general.csv", "w");
	info->fptr1 = fopen("dup.csv","r");

	while(fscanf(info->fptr1,"%s",content) != EOF)
		fprintf(info->fptr,"%s\n",content);
	fclose(info->fptr1);
	close_file(info);
	open_file(info);
//	rm dup.csv;
	return success;
}
