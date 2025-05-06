

#include "../inc/termcode.h"

int max(int a , int b)
{
	return a>b ? a : b;
}

int min(int a , int b)
{
	return a>b ? b : a;
}



void clear_screen(char **envp)
{
	pid_t pid;

	char **args = malloc(2 * sizeof(char *));
	
	args[0] = "clear" ;
	args[1] = NULL;
	
	pid=  fork();
	
	if(pid==0)
		execve("/bin/clear" , args , envp);
	else 
		waitpid(pid , NULL , 0);
	
}

void redraw_line(te_t *editor , char *content , int len)
{
	char *clear_line_str = tgetstr("ce" , &((editor)->buff_ptr));
	tputs(clear_line_str , 1 , putchar);
	int i = 0;
	while(len--)
	{
		editor->tgoto_str = tgoto(editor->cursor_motion_str , i , editor->posy);
		tputs(editor->tgoto_str , 1 , putchar);
		putchar(content[i]);
		i++;
		fflush(stdout);
	}
}



void redraw_under(te_t *editor , text_t *text)
{
	char *clear_under_str = tgetstr("cd" , &((editor)->buff_ptr));
	tputs(clear_under_str , 1 , putchar);
	text_t *node = text;
	int y = editor->posy ;
	
	while(node)
	{
		editor->line_len[y] = ft_strlen(node->line.buffer);
		int i = 0 ;
		while(node->line.buffer[i]!='\0')
		{
			editor->tgoto_str = tgoto(editor->cursor_motion_str , i , y);
			tputs(editor->tgoto_str , 1 , putchar);
			putchar(node->line.buffer[i]);
			i++;
			fflush(stdout);
		}
		y++;
		node = node->next;
	}
	editor->tgoto_str = tgoto(editor->cursor_motion_str , 0 , ++editor->posy);
	tputs(editor->tgoto_str , 1 , putchar);
	fflush(stdout);	
	editor->posx = 0;
}
