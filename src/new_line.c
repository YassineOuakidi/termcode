
#include "../inc/termcode.h"


void modify_line_len(te_t **editor , int len)
{
	if((*editor)->len_len+1 == (*editor)->len_cap)
	{
		void *tmp = realloc((*editor)->line_len , (*editor)->len_cap * 2 * sizeof(int));
		(*editor)->line_len = tmp;
		(*editor)->len_cap *=2;	
	}
	
	(*editor)->len_len++;

	(*editor)->line_len[(*editor)->posy - 1] = len;
	
}

void make_newline(char c , te_t *editor , text_t *text )
{
	
	int height = editor->posy + 1;

	text_t *node = text;

	while(height--)
		node = node->next;
	
	text_t *new_node = malloc(sizeof(text_t));

	new_node->line.buffer = malloc(1024 * sizeof(char));
	
	memmove( new_node->line.buffer ,
		node->line.buffer + editor->posx,
		node->line.len - editor->posx + 1);
	
	node->line.buffer[editor->posx] = '\n';
	
	memset ( node->line.buffer + editor->posx + 1 ,
		'\0',
		node->line.len - editor->posx -1 );

	node->line.len -=editor->posx;

	new_node->line.len = ft_strlen(new_node->line.buffer);

	modify_line_len(&editor , new_node->line.len );
	
	new_node->next = node->next;
	node->next = new_node;
	redraw_under(editor , node);
	
	save(editor , text , NULL);
}
