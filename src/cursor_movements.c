
#include "../inc/termcode.h"



void move_cursor_up(te_t *editor)
{
	editor->posy = max(editor->posy-1 , 0);
	editor->posx = min(editor->posx , editor->line_len[editor->posy] - 1);
	editor->tgoto_str = tgoto(editor->cursor_motion_str , editor->posx , editor->posy);
	tputs(editor->tgoto_str , 1 , putchar);
	
	fflush(stdout);
}

void move_cursor_down(te_t *editor)
{
	editor->posy = min(editor->len_len-1 , editor->posy+1);
	editor->posx = min(editor->posx , editor->line_len[editor->posy] - 1);
	editor->tgoto_str = tgoto(editor->cursor_motion_str , editor->posx , editor->posy);
	tputs(editor->tgoto_str , 1 , putchar);

	fflush(stdout);
}

void move_cursor_left(te_t *editor)
{
	editor->posx = max(0 , editor->posx-1);
	editor->tgoto_str = tgoto(editor->cursor_motion_str , editor->posx , editor->posy);
	tputs(editor->tgoto_str , 1 , putchar);

	fflush(stdout);
}

void move_cursor_right(te_t *editor)
{
	editor->posx = min(editor->posx+1 , editor->line_len[editor->posy] - 1 );
	editor->tgoto_str = tgoto(editor->cursor_motion_str , editor->posx , editor->posy);
	tputs(editor->tgoto_str , 1 , putchar );
	
	fflush(stdout);
}
