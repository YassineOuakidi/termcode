#include "../inc/termcode.h"

void cp(char *tmp , char *dest)
{
	if(!tmp || !dest)
		return ;
	size_t i = 0;
	while(tmp[i])
	{
		dest[i] = tmp[i];
		i++;
	}
}

void remove_line(te_t *editor , text_t **text)
{
	int height = editor->posy ;

	text_t *node = *text;

	int temp = editor->line_len[editor->posy - 1] - 1;

	while(height--)
		node = node->next;
	

	if(node->line.cap - node->line.len <= node->next->line.len)
	{
		node->line.buffer = realloc(node->line.buffer , node->line.cap * 2 );
		node->line.cap *=2;
	}
	
	memmove(node->line.buffer + node->line.len - 1,
		node->next->line.buffer ,
		node->next->line.len + 1);
	
	memmove(editor->line_len + editor->posy ,
		editor->line_len + editor->posy + 1,
		editor->len_len - editor->posy - 1 );

	text_t *tmp = node->next;

	if(node->next->next)
		node->next = node->next->next;
	else
		node->next = NULL;

	editor->line_len[editor->posy - 1] += ft_strlen(tmp->line.buffer);
	node->line.len = ft_strlen(node->line.buffer) + 1;
	
	
	editor->posy--;

	editor->len_len--;
	
	redraw_under(editor , node);
	editor->posx = temp;
	editor->posy--;
	editor->tgoto_str = tgoto(editor->cursor_motion_str , editor->posx , editor->posy);
	tputs(editor->tgoto_str , 1 , putchar);
	fflush(stdout);
	
}

void erase_char(te_t *editor , text_t **text)
{
	fflush(stdout);
	if(editor->posx == 0)
	{
		remove_line(editor , text);
		return;
	}
	
	int height = editor->posy + 1;
	text_t *node = *text;
	
	while(height--)
		node = node->next;
	
	memmove( node->line.buffer + editor->posx - 1,
		node->line.buffer + editor->posx  ,
		node->line.len - editor->posx + 1);

	node->line.len--;
	
	editor->line_len[editor->posy]--;

	redraw_line(editor ,  node->line.buffer , node->line.len);
	
	editor->tgoto_str = tgoto(editor->cursor_motion_str , --editor->posx , editor->posy);
	tputs(editor->tgoto_str , 1 , putchar);
	fflush(stdout);
}
