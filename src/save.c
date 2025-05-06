

#include "../inc/termcode.h"





void save(te_t *editor , text_t *text , char *filename)
{
	int fd;
	if(filename==NULL)
		fd = open("test" , O_WRONLY | O_TRUNC | O_CREAT);
	else
		fd = open(filename , O_WRONLY | O_TRUNC);
	text_t *node = text;

	while(text)
	{
		write(fd , text->line.buffer , ft_strlen(text->line.buffer));
		text = text->next;
	}
}
