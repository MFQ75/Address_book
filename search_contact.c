#include "address_book.h"
Status search_element(Information *info)
{

	if(info->size != 0)
	{
		close_file(info);
		if(open_file_read(info) != success)
			return 0;
		int choice;
		printf("Select the menu which you have to edit\n1.name\n2.mobile no\n3.Email id\n4.state\nEnter Your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : {
					 char name[20];
					 printf("Enter the name : ");
					 scanf("%s",name);
					 if(search(name,1,info) != success)
						 printf("Not Found\n");

				 }
				 break;
			case 2 : {
					 char mobile[10];
					 printf("Enter mobile no : ");
					 scanf("%s",mobile);
					 if(search(mobile,2,info) != success)
						 printf("Not Found\n");
				 }
				 break;
			case 3 : {
					 char email[30];
					 printf("Enter the Email id : ");
					 scanf("%s",email);
					 if(search(email,3,info) != success)
						 printf("Not Found\n");
				 }
				 break;
			case 4 : {
					 char state[20];
					 printf("Enter the state : ");
					 scanf("%s",state);
					 if(search(state,4,info) != success)
						 printf("Not Found\n");
				 }

		}
		close_file(info);
		open_file(info);
	}
	else
		printf("File is empty\n");
}

Status search(char *search,int num,Information *info)
{
	char content[80];
	while(fscanf(info->fptr,"%s",content) != EOF)
	{
		char mobile[11],email[30],state[20];
		sscanf(content, "%[^,],%[^,],%[^,],%[^,]", info->name,mobile,email,state);

		switch(num)
		{
			case 1 :
				if(strcmp(info->name,search) == 0)
				{
		                        printf("content is %s\n", content);
					return success;
				}
				break;
			case 2 :
				if(strcmp(mobile,search) == 0)
				{
		                        printf("content is %s\n", content);
					return success;
				}
				break;
			case 3 :
				if(strcmp(email,search) == 0)
				{
		                        printf("content is %s\n", content);
					return success;
				}
				break;
			case 4 :
				if(strcmp(state,search) == 0)
				{
		                        printf("content is %s\n", content);
					return success;
				}
		}
	}
	return failure;
}		
