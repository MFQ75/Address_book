#include "address_book.h"

Status save_element(Information *info)
{
	close_file(info);
	if(open_file_read(info) != success)
		return 0;
	info->fptr1 = fopen("save.csv","w");
	if(info->fptr1 == NULL)
		perror("file");
	char ch;
	while(fread(&ch,1,1,info->fptr) > 0)
		fwrite(&ch,1,1,info->fptr1);

	fclose(info->fptr1);
	close_file(info);
	open_file(info);
}
