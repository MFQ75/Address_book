#include "address_book.h"

Status open_file_read(Information *info)
{
	info->fptr=fopen("general.csv","r");
	if(info->fptr == NULL)
	{
		perror("file");
		return failure;
	}
	return success;
}
Status open_file_save(Information *info)
{
	info->fptr1=fopen("save.csv","w");
	if(info->fptr1 == NULL)
	{
		perror("file");
		return failure;
	}
	return success;
}
Status open_file(Information *info)
{
	info->fptr=fopen("general.csv","a");
	if(info->fptr == NULL)
	{
		perror("file");
		return failure;
	}
	return success;
}

Status check_file_empty(Information *info)
{
	info->size=ftell(info->fptr);
}

Status close_file(Information *info)
{
	fclose(info->fptr);
	return success;
}
Status close_file_local(Information *info)
{
	fclose(info->fptr1);
	return success;
}
