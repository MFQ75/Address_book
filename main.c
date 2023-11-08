#include "address_book.h"
int main()
{
	int num;
	Information info;
	if(open_file(&info) == failure)
		return 0;
	else
	{
		check_file_empty(&info);
		while(1)
		{
			printf("1.Add contact\n2.Edit contact\n3.delete\n4.search\n5.list\n6.save\n7.exit\nEnter your choice : ");
			scanf("%d",&num);
			switch(num)
			{
				case 1 : add_element(&info);
					break; 
				case 2 : if(edit_element(&info) == success)
					         printf("Edit successfull\n");
					 else
						printf("Not found\n");
					break; 
				case 3 : if(delete_element(&info) == success)
						 printf("Deleted Index successfully\n");
					 else
						 printf("Index no not found\n");
					 break;
				case 4 : search_element(&info);
					 break;
				case 5 : if(list_element(&info) == failure)
						 printf("Index no not found\n");
					 break;
				case 6 : save_element(&info);
					 break;
				case 7 : close_file(&info);
					 exit(0);
					 break;
				default: printf("Invalid choice\n");
			}
		}
	}
	return 0;
}
