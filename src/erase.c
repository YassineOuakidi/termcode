#include "../inc/termcode.h"


void remove_line(te_t *editor , text_t *text)
{
	int height = editor->posy ;

	text_t *node = text;

	while(height--)
		node = node->next;
	
	if(node->line.cap - node->line.len < node->next->line.len)
	{
		node->line.buffer = realloc(node->line.buffer , node->line.cap * 2 );
		node->line.cap *=2;
	}
	memmove(node->line.buffer + node->line.len - 1,
		node->next->line.buffer ,
		node->next->line.len );
	
	text_t *tmp = node->next;

	if(node->next->next)
		node->next = node->next->next;
	else
		node->next = NULL;

	editor->line_len[editor->posy - 1] += ft_strlen(tmp->line.buffer);
	
	free(tmp->line.buffer);
	free(tmp);
	
	editor->posy--;
	
	redraw_under(editor , node);
	
}

void erase_char(te_t *editor , text_t *text)
{
	if(editor->posx == 0)
	{
		remove_line(editor , text);
		return;
	}	
	text_t *node = text;
	int pos = editor->posy + 1;
	while(pos--)
		node = node->next;
	if(node->line.buffer[0] == '\n')
	{
		remove_line(editor , text);
		return;
	}
	memmove(node->line.buffer + editor->posx-1 ,
		node->line.buffer + editor->posx,
		node->line.len - pos - 1);

	node->line.len -- ;
	editor->line_len[editor->posx]--;
	redraw_line(editor , node->line.buffer , node->line.len);
	editor->tgoto_str = tgoto(editor->cursor_motion_str , --editor->posx , editor->posy);
	tputs(editor->tgoto_str , 1 , putchar);
	fflush(stdout);
}
