

#include "../inc/termcode.h"


void setRawMode(te_t **editor)
{
	tcgetattr(STDIN_FILENO , &((*editor)->configured_terminal));

	(*editor)->old_termios = (*editor)->configured_terminal;

	(*editor)->configured_terminal.c_lflag &= ~(ICANON | ECHO | IEXTEN | ISIG);
	(*editor)->configured_terminal.c_iflag &= ~(IXON | ICRNL | BRKINT | INPCK | ISTRIP);
	(*editor)->configured_terminal.c_oflag &= ~(OPOST);
	(*editor)->configured_terminal.c_cflag &= ~CSIZE;
	(*editor)->configured_terminal.c_cflag |= CS8;


	tcsetattr(STDIN_FILENO , TCSAFLUSH , &((*editor)->configured_terminal));

}

void init_text_utils(te_t **editor)
{
	(*editor)->line_len = malloc(1024 * sizeof(int));
	(*editor)->len_cap = 1024;
	(*editor)->len_len = 0;
}

void init_editor(te_t **editor)
{
	(*editor)->posx = 0;
	(*editor)->posy = 0;
	(*editor)->term_buffer = malloc(2048 * sizeof(char));
	(*editor)->cursor_motion_str = tgetstr("cm" , &(*editor)->term_buffer);
}


void init_env(te_t *editor , char **envp )
{
	setRawMode(&editor);
	clear_screen(envp);
	init_text_utils(&editor);
	init_editor(&editor);
}
