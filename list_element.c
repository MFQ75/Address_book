#include "address_book.h"

Status list_element(Information *info)
{
	close_file(info);
	if(open_file_read(info) != success)
		return 0;
	int c=0,num;
	printf("Enter the index no : ");
	scanf("%d",&num);
	char content[80];
	while(fgets(content,80,info->fptr))
	{
		c++;
		if(c == num)
			break;
	}
	close_file(info);
	open_file(info);
	if(c == num)
	{
		printf("%s",content);
		return c;
	}
	else
		return failure;
}
