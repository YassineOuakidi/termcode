#include "../inc/termcode.h"


void save(te_t *editor , text_t *text , char *filename)
{
	int fd;
	
	fflush(stdout);

	if(filename==NULL)
		fd = open("test" , O_WRONLY | O_TRUNC | O_CREAT);
	else
		fd = open(filename , O_WRONLY | O_TRUNC , 0644);
	text_t *node = text->next;
	while(node)
	{
		if(node->line.buffer!=NULL)
			write(fd , node->line.buffer , ft_strlen(node->line.buffer));

		node = node->next;
	}
	close(fd);
}
