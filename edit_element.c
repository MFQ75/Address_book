#include "address_book.h"

Status edit_element(Information *info)
{
	int c;
	if(c=list_element(info) != failure)
	{
		int num;
		printf("1.Name\n2.Mobile no\n3.Email\n4.State\nEnter your choice : ");
		scanf("%d",&num);
		char content[80];
		int i=0;
		close_file(info);
	        if(open_file_read(info) != success)
		return 0;
		info->fptr1 = fopen("dup.csv","w");
		while(i++<c)
		{
			fscanf(info->fptr,"%s",content);
			fprintf(info->fptr1,"%s\n",content);
		}
		char mobile[11],email[30],state[20];
		fscanf(info->fptr,"%s",content);
		sscanf(content,"%[^,],%[^,],%[^,],%[^,]",info->name,mobile,email,state);

		switch(num)
		{
			case 1 :  {
					  char name[20];
					  printf("Enter the new name\n");
					  scanf("%s",name);
					  fprintf(info->fptr1,"%s,%s,%s,%s\n",name,mobile,email,state);
				  }
				  break;
			case 2 :  { 
					  char mobile[10];
					  printf("Enter the new name\n");
					  scanf("%s",mobile);
					  fprintf(info->fptr1,"%s,%s,%s,%s\n",info->name,mobile,email,state);
				  }
				  break;
			case 3 :  {
					  char email[30];
					  printf("Enter the new name\n");
					  scanf("%s",email);
					  fprintf(info->fptr1,"%s,%s,%s,%s\n",info->name,mobile,email,state);
				  }
				  break;
			case 4 :  {
					  char state[20];
					  printf("Enter the new name\n");
					  scanf("%s",state);
					  fprintf(info->fptr1,"%s,%s,%s,%s\n",info->name,mobile,email,state);
				  } 
				  break;
			default:
		}
		while(fscanf(info->fptr,"%s",content) != EOF)
			fprintf(info->fptr1,"%s\n",content);
		close_file(info);
		fclose(info->fptr1);

		info->fptr = fopen("general.csv", "w");
		info->fptr1 = fopen("dup.csv","r");
		while(fscanf(info->fptr1,"%s",content) != EOF)
			fprintf(info->fptr,"%s\n",content);
		close_file(info);
		fclose(info->fptr1);
		open_file(info);
		return success;

	}
	else
		return failure;
}
