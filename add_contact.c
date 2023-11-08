#include "address_book.h"

Status add_element(Information *info)
{
	char name[20];
	printf("Enter the name : ");
	scanf(" %[^\n]",name);

	if(info->size != 0)
	{
		close_file(info);

		info->fptr = fopen("general.csv", "r");
		char content[80];
		while(fgets(content,80,info->fptr))
		{
			char ch[20];
			sscanf(content, "%[^,]", ch);
			if(strcmp(strtok(ch," "),name) == 0)
			{
				printf("Name already exist\n");
				break;
			}
		}
		close_file(info);
		open_file(info);


	}

	fprintf(info->fptr, "%s,", name);
	char mobile[12];
	printf("Enter the mobile no : ");
	scanf(" %[0-9]",mobile);
	while(check_mobile_digit(mobile)!=success)
		scanf(" %[0-9]",mobile);
	info->mobile = mobile;

	if(info->size != 0)
	{
		close_file(info);
		info->fptr = fopen("general.csv", "r");
		while(check_mobile(info,mobile) != success)
		{
			printf("Enter the mobile no\n");
			scanf(" %[0-9]",mobile);
			if(check_mobile_digit(mobile)!=success)
				scanf(" %[0-9]",mobile);
			info->mobile = mobile;
		}
		close_file(info);
		open_file(info);
	}
		char email[30];
	printf("Enter email id : ");
	scanf("%s", email);
	while(check_email(email) != success)
	{
		printf("Error : please use @ or .com is missing\n");
		printf("Enter email id : ");
		scanf(" %s", email);
	}	
	char state[20];
	printf("Enter the state name : ");
	scanf("%s", state);

	fprintf(info->fptr, "%s,%s,%s\n",info->mobile,email,state);
}

Status check_mobile_digit(char *mobile)
{
	while(strlen(mobile) != 10)
	{
		printf("please pass 10 digit no\n");
		printf("Enter the mobile no : ");
		return failure;
	}
	return success;
}

Status check_mobile(Information *info,char *m)
{

	char content[80];
	while(fgets(content,80,info->fptr))
	{
		char ch[20],mobile[10];
		sscanf(content, "%[^,],%[^,]", ch,mobile);
		if(strcmp(mobile,m) == 0)
		{
			printf("Mobile no already exist\n");
			return failure;
		}
	}
	return success;
}
Status check_email(char *email)
{
	if(strstr(email,"@"))
	{
		if(strcmp(strstr(email,"."),".com") == 0)
			return success;
	}
	return failure;
}
