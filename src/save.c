
#include "../inc/termcode.h"


void save(te_t *editor , text_t *text , char *filename)
{
	int fd;
	if(filename==NULL)
		fd = open("test" , O_WRONLY | O_TRUNC | O_CREAT);
	else
		fd = open(filename , O_WRONLY | O_TRUNC);
	text_t *node = text;
	char endl = '\n';
	while(text)
	{
		if(text->line.buffer)
		{
			//write(fd , tmp , ft_strlen(tmp));
			write(fd , text->line.buffer , ft_strlen(text->line.buffer));
			if(text->line.buffer[text->line.len]!='\n')
				write(fd , &endl , 1);
		}
		text = text->next;
	}
}
