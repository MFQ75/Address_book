#ifndef ADDRESS_BOOK_H
#define ADDRESS_BOOK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
typedef enum 
{
	success,
	failure
}Status;
typedef struct _Information
{
	FILE *fptr;
	FILE *fptr1;
	char *name;
	char *mobile;
	long size;

}Information;

/* file function prototypes*/
Status open_file(Information *info);
Status open_file_read(Information *info);
Status open_file_dup(Information *info);
Status check_file_empty(Information *info);
Status close_file(Information *info);
Status close_file_local(Information *info);

/* add_contact function prototype*/
Status add_element(Information *info);
Status check_email(char *email);
Status check_name(char *name,char *newname);
Status check_mobile_digit(char *mobile);
Status check_mobile(Information *info,char *m);

/*search_contact function prototype*/
Status search_element(Information *info);
Status search(char *search,int num,Information *info);

/*list_element function prototype*/
Status list_element(Information *info);

/*save_element function prototypes*/
Status save_element(Information *info);

/*delete_element function prottypes*/
Status delete_element(Information *info);

/*edit_element function prototype*/
Status edit_element(Information *info);
#endif
