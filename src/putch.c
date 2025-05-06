


#include "../inc/termcode.h"

void add_char_to_line(text_t **line , char c , int pos)
{
	if((*line)->line.len+1==(*line)->line.cap)
	{
		void *t = realloc((*line)->line.buffer , (*line)->line.cap * 2 * sizeof(char));
		(*line)->line.cap *=2;
	}
	memmove((*line)->line.buffer + pos + 1,
		(*line)->line.buffer + pos , 
		(*line)->line.len - pos);
	(*line)->line.buffer[pos] = c;
}


void my_putchar(char c , te_t *editor , text_t *text)
{
	if(c=='\r' || c=='\n')
	{
		make_newline(c , editor , text);
		return ;
	}

	int line_num = editor->posy;
	text_t *node = text;
	while(line_num!=-1)
	{
		node = node->next;
		line_num--;
	}
	
	add_char_to_line(&node , c , editor->posx );
	editor->line_len[editor->posy]++;
	node->line.len++;
	redraw_line(editor , node->line.buffer , node->line.len);
	editor->tgoto_str = tgoto(editor->cursor_motion_str , ++editor->posx , editor->posy);
	tputs(editor->tgoto_str , 1 , putchar);
	fflush(stdout);
}
