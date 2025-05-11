

#include "../inc/termcode.h"

void free_editor(te_t *editor)
{
	free(editor->line_len);
}

void free_text(text_t *text)
{
	text_t *node = text;
	while(node!=NULL)
	{
		text_t *tmp = node;
		node = node->next;
		if(node->line.buffer) free(node->line.buffer);
		free(node);
	}
}

void free_all(te_t *editor , text_t *text)
{
	free_editor(editor);
	free_text(text);
}
