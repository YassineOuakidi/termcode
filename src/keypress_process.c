
#include "../inc/termcode.h"

void process_movements(te_t *editor)
{
	char c;
	read(STDIN_FILENO , &c , 1);
	switch(c)
	{
		case 'A':
			move_cursor_up(editor);
			break;
		case 'B':
			move_cursor_down(editor);
			break;
		case 'C':
			move_cursor_right(editor);
			break;
		case 'D':
			move_cursor_left(editor);
			break;
		fflush(stdout);
	}
}

int process_esc(te_t *editor)
{
	char c;
	read(STDIN_FILENO , &c , 1);
	if(c=='[')
		process_movements(editor);
	else if(c=='q')
		return 2;
	else if(c=='s')
		return 1;
}



void termcode_readKey(te_t *editor , char **envp , text_t *text , char *filename)
{
	char c;
	while(read(STDIN_FILENO , &c , 1))
	{
		if(c=='\x1b')
		{
			int status = process_esc(editor);
			if(status==1)
				save(editor , text , filename);
			if(status == 2 )
			{
				tcsetattr(STDIN_FILENO , TCSAFLUSH , &(editor->old_termios));
				return;
			}
		}
		else if(c==editor->old_termios.c_cc[VERASE])
			erase_char(editor , text);
		else 
			my_putchar(c , editor , text);	
	}
	fflush(stdout);
}
