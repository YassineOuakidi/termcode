

#include "../inc/termcode.h"



void print_line(te_t **editor , char *line)
{
	size_t 	i = 0;
	while(line[i] && line[i]!=EOF)
	{
		(*editor)->tgoto_str = tgoto((*editor)->cursor_motion_str ,(*editor)->posx , (*editor)->posy);
		tputs((*editor)->tgoto_str , 1 , putchar);
		putchar(line[i]);
		(*editor)->posx++;
		i++;
	}
	(*editor)->posy++;
	(*editor)->posx = 0;
	(*editor)->tgoto_str = tgoto((*editor)->cursor_motion_str, (*editor)->posx ,(*editor)->posy);
	tputs((*editor)->tgoto_str , 1 , putchar);
	fflush(stdout);
}

void append_line_to_text(char *line , text_t **text)
{
	text_t *new_text = malloc(sizeof(text_t));
 	new_text->line.buffer = ft_strdup(line);
    	new_text->line.len = ft_strlen(line) ;
    	new_text->line.cap = new_text->line.len;
    	new_text->next = NULL;

    	if (*text == NULL)
    	{
        	*text = new_text;
    	}
    	else
    	{
        	text_t *tmp = *text;
        	while (tmp->next)
        		tmp = tmp->next;
        	tmp->next = new_text;
    	}
}

void output_content(int fd , te_t *editor , text_t *text)
{
	int line_count = 0;
	char *line ;
	while((line = get_next_line(fd)))
	{
		if(line[0]=='\n')
			editor->line_len[line_count] = 1;
		else
			editor->line_len[line_count] = ft_strlen(line) ;

		print_line(&editor , line);

		append_line_to_text(line , &text);
		
		free(line);

		line_count++;
	}
	if(line_count==0)
	{
		append_line_to_text("\n" , &text);
		editor->line_len[0] = 1;
		line_count = 1;
	}
	
	text = text->next;
	editor->len_len = line_count;
	fflush(stdout);
	return ;
}
